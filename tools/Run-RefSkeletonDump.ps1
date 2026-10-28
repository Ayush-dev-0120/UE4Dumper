param(
    [Parameter(Mandatory = $true)][string]$GName,
    [Parameter(Mandatory = $true)][string]$GUObject,
    [string]$GWorld = "",
    [string]$Package = "com.pubg.imobile",
    [string]$Dumper = "",
    [string]$NdkBuild = "",
    [string]$GNameAdjust = "0x0",
    [switch]$NewUE,
    [switch]$DerefGName,
    [switch]$DerefGUObject
)

$ErrorActionPreference = "Stop"
$repoRoot = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
if ([string]::IsNullOrWhiteSpace($Dumper)) {
    $Dumper = Join-Path $repoRoot "libs\arm64-v8a\ue4dumper64"
}
if (-not [IO.Path]::IsPathRooted($Dumper)) {
    $Dumper = Join-Path $repoRoot $Dumper
}
if (-not (Test-Path -LiteralPath $Dumper -PathType Leaf)) {
    throw "Dumper binary not found: $Dumper"
}
foreach ($value in @($GName, $GUObject, $GNameAdjust, $GWorld)) {
    if ([string]::IsNullOrWhiteSpace($value)) { continue }
    if ($value -notmatch '^0x[0-9a-fA-F]+$|^[0-9a-fA-F]+$') {
        throw "Invalid hex address/offset: $value"
    }
}

# Always rebuild so the pushed executable contains the RefSkeleton exporter.
if ([string]::IsNullOrWhiteSpace($NdkBuild)) {
    $ndkCommand = Get-Command ndk-build.cmd, ndk-build -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($ndkCommand) {
        $NdkBuild = $ndkCommand.Source
    } else {
        $ndkRoots = @($env:ANDROID_NDK_HOME, $env:ANDROID_NDK_ROOT, $env:ANDROID_HOME,
            (Join-Path $env:LOCALAPPDATA "Android\Sdk\ndk")) | Where-Object { $_ }
        foreach ($root in $ndkRoots) {
            if (Test-Path -LiteralPath $root -PathType Leaf) {
                $NdkBuild = (Resolve-Path -LiteralPath $root).Path
                break
            }
            if (Test-Path -LiteralPath $root -PathType Container) {
                $directCandidate = Join-Path $root "ndk-build.cmd"
                if (Test-Path -LiteralPath $directCandidate -PathType Leaf) {
                    $NdkBuild = $directCandidate
                    break
                }
                $nestedNdkRoot = Join-Path $root "ndk"
                if (Test-Path -LiteralPath $nestedNdkRoot -PathType Container) { $root = $nestedNdkRoot }
                $candidate = Get-ChildItem -LiteralPath $root -Directory -ErrorAction SilentlyContinue |
                    Sort-Object Name -Descending |
                    ForEach-Object { Join-Path $_.FullName "ndk-build.cmd" } |
                    Where-Object { Test-Path -LiteralPath $_ -PathType Leaf } |
                    Select-Object -First 1
                if ($candidate) { $NdkBuild = $candidate; break }
            }
        }
    }
}
if (-not $NdkBuild -or -not (Test-Path -LiteralPath $NdkBuild -PathType Leaf)) {
    throw "Android NDK ndk-build.cmd was not found. Install the NDK or pass -NdkBuild <path>, then rerun this script."
}

Write-Host "Building updated ARM64 dumper..."
Push-Location $repoRoot
try {
    $ndkArgs = @("NDK_PROJECT_PATH=$repoRoot",
        "APP_BUILD_SCRIPT=$(Join-Path $repoRoot 'jni\Android.mk')",
        "NDK_APPLICATION_MK=$(Join-Path $repoRoot 'jni\Application.mk')")
    & $NdkBuild clean @ndkArgs
    if ($LASTEXITCODE -ne 0) { throw "ndk-build clean failed; the device was not run." }
    & $NdkBuild @ndkArgs
    if ($LASTEXITCODE -ne 0) { throw "ndk-build failed; the device was not run." }
} finally {
    Pop-Location
}
if (-not (Test-Path -LiteralPath $Dumper -PathType Leaf)) {
    throw "Build succeeded but the expected ARM64 binary is missing: $Dumper"
}

$remoteBinary = "/data/local/tmp/ue4dumper64"
$remoteOutput = "/data/local/tmp/ue4dumper-output-$([DateTime]::Now.ToString('yyyyMMdd-HHmmss'))"
$localOutput = Join-Path $repoRoot "RefSkeleton.txt"
$localBoneAddresses = Join-Path $repoRoot "BoneTransformAddresses.txt"

$devices = @(& adb devices 2>&1)
if ($LASTEXITCODE -ne 0 -or -not ($devices | Where-Object { $_ -match '\sdevice$' })) {
    throw "No ADB device is connected. Check 'adb devices'."
}

& adb push $Dumper $remoteBinary
if ($LASTEXITCODE -ne 0) { throw "Could not push dumper to the device." }

& adb shell su -c "chmod 755 $remoteBinary"
if ($LASTEXITCODE -ne 0) { throw "Could not mark the dumper executable on the device (root required)." }
& adb shell su -c "mkdir -p $remoteOutput"
if ($LASTEXITCODE -ne 0) { throw "Could not create the temporary device output folder (root required)." }

$modeArgument = if ([string]::IsNullOrWhiteSpace($GWorld)) { "--sdku" } else { "--sdkw" }
$arguments = @("$remoteBinary", $modeArgument, "--gname", $GName, "--guobj", $GUObject,
    "--gname-adjust", $GNameAdjust, "--package", $Package, "--output", $remoteOutput)
if (-not [string]::IsNullOrWhiteSpace($GWorld)) { $arguments += @("--gworld", $GWorld) }
if ($NewUE) { $arguments += "--newue" }
if ($DerefGName) { $arguments += @("--derefgname", "true") }
if ($DerefGUObject) { $arguments += @("--derefguobj", "true") }
$remoteCommand = ($arguments -join " ")
& adb shell su -c $remoteCommand
if ($LASTEXITCODE -ne 0) { throw "The dumper failed on the device." }

& adb pull "$remoteOutput/RefSkeleton.txt" $repoRoot
if ($LASTEXITCODE -ne 0) { throw "Could not export RefSkeleton.txt to the repository folder." }
Write-Host "Exported: $localOutput"
if (-not [string]::IsNullOrWhiteSpace($GWorld)) {
    & adb pull "$remoteOutput/BoneTransformAddresses.txt" $repoRoot
    if ($LASTEXITCODE -ne 0) { throw "Could not export BoneTransformAddresses.txt to the repository folder." }
    Write-Host "Exported: $localBoneAddresses"
}

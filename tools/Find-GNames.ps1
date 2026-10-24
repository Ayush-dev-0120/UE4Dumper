param(
    [string]$Package = "com.pubg.imobile",
    [string]$Module = "libUE4.so",
    [UInt64]$GNameAdjust = 0x110
)

$ErrorActionPreference = "Stop"

function Invoke-RootAdb([string]$Command) {
    $result = @(& adb shell su -c $Command 2>&1)
    if ($LASTEXITCODE -ne 0) {
        throw "ADB/root command failed: $($result -join [Environment]::NewLine)"
    }
    return $result
}

function Read-UInt64([UInt64]$Address, [int]$Pid) {
    $addressText = "0x{0:x}" -f $Address
    $result = Invoke-RootAdb "od -An -tx8 -j $addressText -N 8 /proc/$Pid/mem"
    $hex = ($result -join " ").Trim() -replace "\s", ""
    if ($hex -notmatch "^[0-9a-fA-F]{1,16}$") {
        throw "Could not read a QWORD at ${addressText}: $($result -join ' ')"
    }
    return [Convert]::ToUInt64($hex, 16)
}

function Format-Address([UInt64]$Address) {
    return "0x{0:x}" -f $Address
}

$deviceList = @(& adb devices 2>&1)
if ($LASTEXITCODE -ne 0 -or -not ($deviceList | Where-Object { $_ -match "\sdevice$" })) {
    throw "No ADB device is connected. Check 'adb devices' first."
}

$pidOutput = @(& adb shell pidof $Package 2>&1)
if ($LASTEXITCODE -ne 0 -or -not $pidOutput) {
    throw "Process '$Package' is not running. Open the app and try again."
}
$pidText = ($pidOutput -join " ").Trim().Split(' ')[0]
$processId = [int]$pidText

$mapLines = Invoke-RootAdb "cat /proc/$processId/maps"
$base = $null
$scanRanges = @()
foreach ($line in $mapLines) {
    if ($line -match "^([0-9a-fA-F]+)-[0-9a-fA-F]+\s+\S+\s+00000000\s+\S+\s+\d+\s+.*$([regex]::Escape($Module))$") {
        $base = [Convert]::ToUInt64($Matches[1], 16)
    }
    if ($line -match "^([0-9a-fA-F]+)-([0-9a-fA-F]+)\s+rw-p\s+[0-9a-fA-F]+\s+\S+\s+\d+\s+.*$([regex]::Escape($Module))$") {
        $scanRanges += [pscustomobject]@{
            Start = [Convert]::ToUInt64($Matches[1], 16)
            End   = [Convert]::ToUInt64($Matches[2], 16)
        }
    }
    if ($line -match "^([0-9a-fA-F]+)-([0-9a-fA-F]+)\s+\S+\s+[0-9a-fA-F]+\s+\S+\s+\d+\s+\[anon:\.bss\]") {
        $scanRanges += [pscustomobject]@{
            Start = [Convert]::ToUInt64($Matches[1], 16)
            End   = [Convert]::ToUInt64($Matches[2], 16)
        }
    }
}
if ($null -eq $base) {
    throw "Could not find the base mapping for $Module in PID $processId."
}
if (-not $scanRanges) {
    throw "No writable $Module or [anon:.bss] ranges found for PID $processId."
}

# The main DWORD changes between versions. Match the four 1.0f DWORDs and the
# three stable trailing DWORDs visible in the saved sample: 118, 4, 4.
$oneFloat = "3f800000"
$requiredFloatCount = 4
$afterMain = @("00000076", "00000004", "00000004")
$candidates = @()
$seenAddresses = @{}

Write-Host "PID: $processId"
Write-Host "$Module base: $(Format-Address $base)"
Write-Host "Scanning $($scanRanges.Count) writable library/BSS range(s) for four 1.0f DWORDs + trailing DWORDs 118, 4, 4..."

foreach ($range in $scanRanges) {
    $length = $range.End - $range.Start
    $startText = Format-Address $range.Start
    $scanLines = Invoke-RootAdb "od -A x -tx4 -w64 -v -j $startText -N $length /proc/$processId/mem"
    $carryWords = @()
    $carryAddress = [UInt64]0

    foreach ($line in $scanLines) {
        $fields = @($line.Trim() -split "\s+")
        if ($fields.Count -lt 4 -or $fields[0] -notmatch "^[0-9a-fA-F]+$") { continue }
        $rowAddress = [Convert]::ToUInt64($fields[0], 16)
        $words = @($fields | Select-Object -Skip 1)
        if ($carryWords.Count -gt 0) {
            $scanWords = @($carryWords) + @($words)
            $scanAddress = $carryAddress
        } else {
            $scanWords = $words
            $scanAddress = $rowAddress
        }

        for ($i = 0; $i -lt ($scanWords.Count - 2); $i++) {
            if ($scanWords[$i] -ne $oneFloat -or $scanWords[$i + 1] -ne $oneFloat) { continue }
            if ($i -gt 0 -and $scanWords[$i - 1] -eq $oneFloat) { continue }

            # The following DWORD is version-specific; the surrounding words
            # are the stable markers from the screenshot.
            $mainIndex = $i
            while ($mainIndex -lt $scanWords.Count -and $scanWords[$mainIndex] -eq $oneFloat) { $mainIndex++ }
            if (($mainIndex - $i) -ne $requiredFloatCount -or ($mainIndex + $afterMain.Count) -ge $scanWords.Count) { continue }
            $tailMatches = $true
            for ($tailIndex = 0; $tailIndex -lt $afterMain.Count; $tailIndex++) {
                if ($scanWords[$mainIndex + 1 + $tailIndex] -ne $afterMain[$tailIndex]) {
                    $tailMatches = $false
                    break
                }
            }
            if (-not $tailMatches) { continue }

            $mainAddress = [UInt64]($scanAddress + (4 * $mainIndex))
            $candidateKey = Format-Address $mainAddress
            if ($seenAddresses.ContainsKey($candidateKey)) { continue }
            $seenAddresses[$candidateKey] = $true
            $rva = [UInt64]($mainAddress - $base)
            $candidates += [pscustomobject]@{
                Address = $mainAddress
                RVA = $rva
                MainDWORD = $scanWords[$mainIndex]
                FloatCount = $mainIndex - $i
            }
        }

        $carryCount = [Math]::Min(7, $words.Count)
        $carryWords = @($words | Select-Object -Last $carryCount)
        $carryAddress = [UInt64]($rowAddress + (4 * ($words.Count - $carryCount)))
    }
}

if (-not $candidates) {
    Write-Warning "No matches found. Check that the saved neighborhood has four 1.0f DWORDs before the main DWORD, then 118, 4, 4 immediately after it."
    exit 1
}

$candidate = $candidates | Sort-Object Address | Select-Object -First 1
Write-Host ("GName : {0})+ {1})" -f `
    (Format-Address $candidate.RVA), (Format-Address $GNameAdjust))

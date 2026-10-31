param(
    [string]$SdkPath = ""
)

$ErrorActionPreference = "Stop"
$repoRoot = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
if ([string]::IsNullOrWhiteSpace($SdkPath)) {
    $SdkPath = Join-Path $repoRoot "SDK.txt"
} elseif (-not [IO.Path]::IsPathRooted($SdkPath)) {
    $SdkPath = Join-Path $repoRoot $SdkPath
}
if (-not (Test-Path -LiteralPath $SdkPath -PathType Leaf)) {
    throw "SDK dump not found: $SdkPath"
}

$className = "(unknown)"
$results = @()
$sceneComponentFound = $false
$updatedFlag = $null
foreach ($line in Get-Content -LiteralPath $SdkPath) {
    if ($line -match '^Class:\s*(.+)$') {
        $className = $Matches[1].Trim()
        if ($className -match '^(SceneComponent|[^.]+\.SceneComponent)\.') {
            $sceneComponentFound = $true
        }
        continue
    }

    if ($className -match '(^|\.)SceneComponent\.' -and
        $line -match '^\s*(?:FTransform|Transform)\s+ComponentToWorld\s*;.*\[Offset:\s*(0x[0-9a-fA-F]+),\s*Size:\s*(0x[0-9a-fA-F]+)\]') {
        $fieldOffset = $Matches[1]
        $fieldSize = $Matches[2]
        $results += [pscustomobject]@{
            Class = $className
            Field = 'ComponentToWorld'
            Offset = $fieldOffset
            Size = $fieldSize
        }
    }

    if ($className -match '(^|\.)SceneComponent\.' -and
        $line -match '^\s*bool\s+bComponentToWorldUpdated\s*;.*\[Offset:\s*(0x[0-9a-fA-F]+)') {
        $updatedFlag = $Matches[1]
    }
}

if ($results.Count -gt 0) {
    Write-Host "ComponentToWorld field found in: $SdkPath"
    $results | Format-Table -AutoSize
    exit 0
}

if (-not $sceneComponentFound) {
    Write-Host "No SceneComponent class found in $SdkPath"
    exit 1
}

Write-Host "ComponentToWorld field is not listed in: $SdkPath"
if ($updatedFlag) {
    Write-Host "SceneComponent::bComponentToWorldUpdated is at $updatedFlag, but that is a separate bool and is not the transform offset."
}
Write-Host "This SDK dump does not expose the ComponentToWorld field, so its offset cannot be read from this file. Use a runtime memory/structure scan or a matching engine layout to determine it."
exit 1

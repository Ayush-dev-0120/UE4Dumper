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
$links = @()
$sdkText = Get-Content -LiteralPath $SdkPath
foreach ($line in $sdkText) {
    if ($line -match '^Class:\s*(.+)$') {
        $className = $Matches[1].Trim()
        continue
    }
    if (($className -match '^Actor\.' -and $line -match '^\s*Actor\* Owner;.*\[Offset:\s*(0x[0-9a-fA-F]+)') -or
        ($className -match '^Pawn\.' -and $line -match '^\s*PlayerState\* PlayerState;.*\[Offset:\s*(0x[0-9a-fA-F]+)')) {
        $fieldOffset = $Matches[1]
        $fieldName = if ($line -match 'Owner;') { 'Owner' } else { 'PlayerState' }
        $links += [pscustomobject]@{
            Class = $className
            Field = $fieldName
            Offset = $fieldOffset
        }
    }
}

$className = "(unknown)"
foreach ($line in $sdkText) {
    if ($line -match '^Class:\s*(.+)$') {
        $className = $Matches[1].Trim()
        continue
    }
    if ($line -match '^\s*bool\s+(bIsABot|bIsAI|IsAIPlayer|IsBot|IsAI)\s*;.*\[Offset:\s*(0x[0-9a-fA-F]+),\s*Size:\s*(0x[0-9a-fA-F]+)\]') {
        $field = $Matches[1]
        $offset = $Matches[2]
        $size = $Matches[3]
        $mask = "(not listed)"
        if ($line -match 'ByteMask:\s*(\d+)') {
            $mask = "0x{0:X2}" -f [int]$Matches[1]
        }
        $confidence = if ($field -eq "bIsABot" -and $className -match 'PlayerState') {
            "Strong bot flag"
        } elseif ($field -eq "bIsAI" -and $className -match 'UAECharacter') {
            "Useful character-level cross-check"
        } else {
            "Candidate; verify for this game/build"
        }
        $results += [pscustomobject]@{
            Class = $className
            Field = $field
            Offset = $offset
            Size = $size
            ByteMask = $mask
            Meaning = $confidence
        }
    }
}

if ($results.Count -eq 0) {
    Write-Host "No bot/AI boolean fields found in $SdkPath"
    exit 1
}

Write-Host "Bot/player flag candidates from: $SdkPath"
$results | Format-Table -AutoSize
Write-Host ""
Write-Host "SDK relationship fields:"
$links | Format-Table -AutoSize
if ($sdkText -match '(?i)ModelTarget|ModelTaget') {
    Write-Host "ModelTarget references exist in this SDK dump; inspect those class fields for an actor/pawn link."
} else {
    Write-Host "No ModelTarget class or field appears in this SDK dump, so it does not define a direct ModelTarget-to-player link."
}
Write-Host "For the PlayerState bIsABot row: read one byte at PlayerState + Offset, then test (value & ByteMask) != 0."
Write-Host "Follow Actor.Owner or Pawn.PlayerState only after validating the pointed-to UObject class with GName. Offsets are class-relative and build-specific."

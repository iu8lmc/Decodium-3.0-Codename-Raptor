$SIGNTOOL = "C:\Program Files (x86)\Windows Kits\10\bin\10.0.22621.0\x64\signtool.exe"
$PFX      = "C:\Users\IU8LMC\decodium_codesign.pfx"
$PASS     = "Dec2026sign"
$SRC      = "C:\Users\IU8LMC\Downloads\WSJTX_3.0_Source"

$installers = @(
    "$SRC\Decodium_3.0_2603040154_FT2_x64_Setup.exe",
    "$SRC\Decodium_3.0_2603040154_FT2_x86_Setup.exe"
)

foreach ($inst in $installers) {
    $name = Split-Path $inst -Leaf
    Write-Host "Signing $name..." -NoNewline
    & $SIGNTOOL sign /f $PFX /p $PASS /fd SHA256 /d "Decodium 3.0 FT2 Raptor Installer" $inst 2>&1 | Out-Null
    if ($LASTEXITCODE -eq 0) { Write-Host " OK" -ForegroundColor Green }
    else { Write-Host " FAIL (exit $LASTEXITCODE)" -ForegroundColor Red }
}

$SIGNTOOL = "C:\Program Files (x86)\Windows Kits\10\bin\10.0.22621.0\x64\signtool.exe"
$PFX      = "C:\Users\IU8LMC\decodium_codesign.pfx"
$PASS     = "Dec2026sign"
$SRC      = "C:\Users\IU8LMC\Downloads\WSJTX_3.0_Source"

$exeNames = @(
    "decodium.exe","jt9.exe","message_aggregator.exe","wsprd.exe",
    "rigctl-decodium.exe","rigctld-decodium.exe","rigctlcom-decodium.exe",
    "udp_daemon.exe","ChronoGPS.exe"
)

$ok = 0; $skip = 0; $fail = 0

foreach ($arch in @("dist_64bit","dist_32bit")) {
    Write-Host "`n=== $arch ===" -ForegroundColor Cyan
    foreach ($exe in $exeNames) {
        $path = "$SRC\$arch\$exe"
        if (-not (Test-Path $path)) { Write-Host "  SKIP: $exe"; $skip++; continue }
        Write-Host "  Signing $exe..." -NoNewline
        & $SIGNTOOL sign /f $PFX /p $PASS /fd SHA256 /d "Decodium 3.0 FT2 Raptor" $path 2>&1 | Out-Null
        if ($LASTEXITCODE -eq 0) { Write-Host " OK" -ForegroundColor Green; $ok++ }
        else { Write-Host " FAIL" -ForegroundColor Red; $fail++ }
    }
}

Write-Host "`nSigned: $ok  Skipped: $skip  Failed: $fail"
exit $fail

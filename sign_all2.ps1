$dirs = @("C:\Users\IU8LMC\Downloads\WSJTX_3.0_Source\dist_64bit", "C:\Users\IU8LMC\Downloads\WSJTX_3.0_Source\dist_32bit")
$ok = 0; $fail = 0
foreach ($dir in $dirs) {
    $exes = Get-ChildItem "$dir\*.exe"
    foreach ($exe in $exes) {
        Write-Host "Signing $($exe.Name) in $(Split-Path $dir -Leaf)..." -NoNewline
        & 'C:\Program Files (x86)\Windows Kits\10\bin\10.0.22621.0\x64\signtool.exe' sign /f 'C:\Users\IU8LMC\decodium_codesign_new.pfx' /p 'Decodium2026!' /fd SHA256 /tr http://timestamp.digicert.com /td SHA256 $exe.FullName 2>&1 | Out-Null
        if ($LASTEXITCODE -eq 0) { Write-Host " OK" -ForegroundColor Green; $ok++ }
        else { Write-Host " FAIL" -ForegroundColor Red; $fail++ }
    }
}
Write-Host "`nSigned: $ok  Failed: $fail"

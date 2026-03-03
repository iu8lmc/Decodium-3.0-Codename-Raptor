$signtool = "C:\Program Files (x86)\Windows Kits\10\bin\10.0.22621.0\x64\signtool.exe"
$pfx = "C:\Users\IU8LMC\decodium_codesign_new.pfx"
$pw = "Decodium2026!"

$dirs = @("C:\Users\IU8LMC\Downloads\WSJTX_3.0_Source\dist_64bit", "C:\Users\IU8LMC\Downloads\WSJTX_3.0_Source\dist_32bit")
foreach ($dir in $dirs) {
    $exes = Get-ChildItem "$dir\*.exe"
    foreach ($exe in $exes) {
        Write-Host "Signing $($exe.FullName)..."
        & $signtool sign /f $pfx /p $pw /fd SHA256 /tr http://timestamp.digicert.com /td SHA256 $exe.FullName
        if ($LASTEXITCODE -ne 0) { Write-Host "  FAILED!" -ForegroundColor Red }
        else { Write-Host "  OK" -ForegroundColor Green }
    }
}
Write-Host "`nDone signing all executables."

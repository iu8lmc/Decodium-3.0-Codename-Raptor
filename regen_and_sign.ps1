$ErrorActionPreference = "Continue"

# Remove old PFX
Remove-Item "C:\Users\IU8LMC\decodium_codesign2.pfx" -ErrorAction SilentlyContinue

# Create fresh self-signed code signing certificate
$cert = New-SelfSignedCertificate -Type CodeSigningCert `
    -Subject "CN=IU8LMC Decodium, O=IU8LMC, C=IT" `
    -FriendlyName "Decodium Code Signing 2026" `
    -CertStoreLocation "Cert:\CurrentUser\My" `
    -NotAfter (Get-Date).AddYears(5) `
    -KeyAlgorithm RSA -KeyLength 2048 -HashAlgorithm SHA256

Write-Host "Certificate created: $($cert.Thumbprint)"

# Export to PFX with simple password
$pwd = ConvertTo-SecureString -String "Dec2026sign" -Force -AsPlainText
Export-PfxCertificate -Cert $cert -FilePath "C:\Users\IU8LMC\decodium_codesign2.pfx" -Password $pwd | Out-Null
Write-Host "PFX exported"

# Sign all executables
$signtool = "C:\Program Files (x86)\Windows Kits\10\bin\10.0.22621.0\x64\signtool.exe"
$pfx = "C:\Users\IU8LMC\decodium_codesign2.pfx"

$dirs = @("C:\Users\IU8LMC\Downloads\WSJTX_3.0_Source\dist_64bit", "C:\Users\IU8LMC\Downloads\WSJTX_3.0_Source\dist_32bit")
$ok = 0
$fail = 0
foreach ($dir in $dirs) {
    $exes = Get-ChildItem "$dir\*.exe"
    foreach ($exe in $exes) {
        Write-Host "Signing $($exe.Name) in $(Split-Path $dir -Leaf)..." -NoNewline
        & $signtool sign /f $pfx /p "Dec2026sign" /fd SHA256 /tr http://timestamp.digicert.com /td SHA256 $exe.FullName 2>&1 | Out-Null
        if ($LASTEXITCODE -eq 0) { Write-Host " OK" -ForegroundColor Green; $ok++ }
        else { Write-Host " FAIL" -ForegroundColor Red; $fail++ }
    }
}
Write-Host "`nSigned: $ok  Failed: $fail"

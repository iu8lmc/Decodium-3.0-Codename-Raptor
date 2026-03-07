Remove-Item "C:\Users\IU8LMC\decodium_codesign.pfx" -ErrorAction SilentlyContinue
$cert = New-SelfSignedCertificate -Type CodeSigningCert `
    -Subject "CN=IU8LMC Decodium, O=IU8LMC, C=IT" `
    -FriendlyName "Decodium Code Signing 2026" `
    -CertStoreLocation "Cert:\CurrentUser\My" `
    -NotAfter (Get-Date).AddYears(5) `
    -KeyAlgorithm RSA -KeyLength 2048 -HashAlgorithm SHA256
Write-Host ("Cert created: " + $cert.Thumbprint)
$pwd = ConvertTo-SecureString -String "Dec2026sign" -Force -AsPlainText
Export-PfxCertificate -Cert $cert -FilePath "C:\Users\IU8LMC\decodium_codesign.pfx" -Password $pwd | Out-Null
Write-Host "PFX exported OK - password: Dec2026sign"

#!/bin/bash
# Genera certificato self-signed per code signing con OpenSSL
set -e

PFX="/c/Users/IU8LMC/decodium_codesign.pfx"
PASS="Dec2026sign"
SUBJECT="/C=IT/O=IU8LMC/CN=IU8LMC Decodium"

cd /tmp

# Genera chiave privata RSA 2048
openssl genrsa -out codesign_key.pem 2048 2>/dev/null

# Crea certificato auto-firmato con estensione CodeSigning
cat > codesign_ext.cnf << 'EXTEOF'
[ v3_codesign ]
keyUsage = critical, digitalSignature
extendedKeyUsage = critical, codeSigning
subjectKeyIdentifier = hash
authorityKeyIdentifier = keyid:always
basicConstraints = critical, CA:false
EXTEOF

openssl req -new -x509 -key codesign_key.pem \
    -out codesign_cert.pem \
    -days 1825 \
    -subj "$SUBJECT" \
    -extensions v3_codesign \
    -config <(cat /c/msys64/mingw64/etc/ssl/openssl.cnf; cat codesign_ext.cnf) 2>/dev/null

# Esporta in PFX
openssl pkcs12 -export \
    -out "$PFX" \
    -inkey codesign_key.pem \
    -in codesign_cert.pem \
    -passout "pass:$PASS" \
    -name "Decodium Code Signing 2026" 2>/dev/null

rm -f codesign_key.pem codesign_cert.pem codesign_ext.cnf

echo "PFX generato: $PFX"
echo "Password: $PASS"
ls -la "$PFX"

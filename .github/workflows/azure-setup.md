# Setup Azure Trusted Signing — Istruzioni una-tantum

## 1. Crea account Azure (gratuito)

Vai su https://azure.microsoft.com/free/ e registrati.
Il piano gratuito include $200 di credito — Azure Trusted Signing
costa ~$0.005 per firma, quindi $200 = ~40.000 firme.

## 2. Crea risorsa Trusted Signing

```bash
# Installa Azure CLI se non ce l'hai
# https://aka.ms/installazurecliwindows

az login

# Crea resource group
az group create --name decodium-signing --location westeurope

# Registra provider (prima volta)
az provider register --namespace Microsoft.CodeSigning

# Crea account Trusted Signing
az trustedsigning account create \
  --name decodium-codesign \
  --resource-group decodium-signing \
  --location westeurope \
  --sku Basic

# Crea certificate profile (PublicTrust = riconosciuto da Windows/AV)
az trustedsigning certificate-profile create \
  --account-name decodium-codesign \
  --resource-group decodium-signing \
  --profile-name decodium-profile \
  --profile-type PublicTrust \
  --include-street false
```

> **Nota**: `PublicTrust` richiede verifica identità (1-3 giorni).
> Per test usa `PrivateTrust` (subito attivo, non trusted da Windows di default).

## 3. Crea Service Principal per GitHub Actions

```bash
# Crea service principal con ruolo Trusted Signing Certificate Profile Signer
SP=$(az ad sp create-for-rbac \
  --name "decodium-github-signing" \
  --role "Trusted Signing Certificate Profile Signer" \
  --scopes "/subscriptions/$(az account show --query id -o tsv)/resourceGroups/decodium-signing" \
  --sdk-auth)

echo $SP
# Copia l'output JSON — servirà come AZURE_CREDENTIALS secret
```

L'output è simile a:
```json
{
  "clientId": "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx",
  "clientSecret": "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
  "subscriptionId": "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx",
  "tenantId": "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx"
}
```

## 4. Aggiungi secrets al repo GitHub

Vai su: https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor/settings/secrets/actions

Aggiungi questi secrets:

| Secret | Valore |
|--------|--------|
| `AZURE_CREDENTIALS` | JSON completo dal passo 3 |
| `AZURE_TRUSTED_SIGNING_ENDPOINT` | `https://weu.codesigning.azure.net` (westeurope) |
| `AZURE_CODE_SIGNING_ACCOUNT` | `decodium-codesign` |
| `AZURE_CERT_PROFILE_NAME` | `decodium-profile` |

## 5. Triggera build

### Automatica (tag push):
```bash
git tag v3.0.2603070002
git push mine v3.0.2603070002
```

### Manuale (GitHub UI):
Actions → Build & Release Decodium → Run workflow → inserisci build tag

## 6. Verifica firma

Dopo la release, scarica l'installer e verifica:
```powershell
Get-AuthenticodeSignature "Decodium_3.0_..._x64_Setup.exe" | Select-Object *
# Status dovrebbe essere "Valid"
# SignerCertificate.Subject: "CN=IU8LMC, ..."
```

## Costo stimato

- ~10 firme per build (9 exe + 1 installer) × $0.005 = **$0.05 per release**
- 20 release/anno = **$1/anno**

# Setup SignPath — Code Signing gratuito per Open Source

## 1. Registrati su SignPath

1. Vai su https://app.signpath.io/Web/SignUp
2. Crea account con la tua email GitHub
3. Nome organizzazione: `IU8LMC` (o come preferisci)

## 2. Richiedi piano Open Source (gratuito)

Settings → Subscription → "Apply for Open Source"

Fornisci:
- Repository: https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor
- Licenza: GPL-3.0
- Breve descrizione del progetto

Approvazione: 1-3 giorni lavorativi.

## 3. Configura il progetto in SignPath

Una volta approvato, nel portale SignPath:

### Crea progetto
Projects → + Add → slug: `Decodium`

### Crea Artifact Configuration: `exe-collection`
Per firmare i file .exe nella cartella dist:
```xml
<artifact-configuration xmlns="http://signpath.io/artifact-configuration/v1">
  <zip-file>
    <pe-binary path="*.exe" />
    <pe-binary path="**/*.dll" />
  </zip-file>
</artifact-configuration>
```

### Crea Artifact Configuration: `installer`
Per firmare l'installer Inno Setup:
```xml
<artifact-configuration xmlns="http://signpath.io/artifact-configuration/v1">
  <zip-file>
    <pe-binary path="*.exe" />
  </zip-file>
</artifact-configuration>
```

### Crea Signing Policy: `release-signing`
Policies → + Add:
- Slug: `release-signing`
- Certificate: usa il certificato fornito da SignPath (open source)
- Approvers: nessuno (auto-approve per open source)

## 4. Ottieni API Token

Settings → API Tokens → + Add → copia il token

## 5. Trova Organization ID

Settings → Organization → copia Organization ID (GUID)

## 6. Aggiungi GitHub Secrets

Vai su: https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor/settings/secrets/actions

| Secret | Valore |
|--------|--------|
| `SIGNPATH_API_TOKEN` | Token dal passo 4 |
| `SIGNPATH_ORGANIZATION_ID` | GUID dal passo 5 |

## 7. Triggera build

### Automatica (tag push):
```bash
git tag v3.0.2603070002
git push mine v3.0.2603070002
```

### Manuale (GitHub UI):
Actions → Build & Release Decodium → Run workflow → inserisci build tag

## 8. Verifica firma

```powershell
Get-AuthenticodeSignature "Decodium_3.0_..._x64_Setup.exe" | Select-Object *
# Status: Valid
# SignerCertificate.Subject: "CN=IU8LMC, ..."
```

## Costo

- Piano Open Source: **gratuito** (richiede approvazione)
- Nessun limite di firme per progetti open source

# Decodium Shannon v3.0 — Vademecum Completo
## Tutte le innovazioni dal 16 Febbraio 2026 ad oggi (23 Marzo 2026)

**73 de IU8LMC**

---

## Indice

1. [FT2 Mode — Il cuore di Decodium](#1-ft2-mode)
2. [Shannon Decoder — Decodifica di nuova generazione](#2-shannon-decoder)
3. [DXpedition Mode a 2 slot](#3-dxpedition-mode)
4. [Auto CQ con Caller Queue](#4-auto-cq-caller-queue)
5. [Quick QSO — QSO in 2 messaggi](#5-quick-qso)
6. [Sistema Certificati Decodium](#6-sistema-certificati)
7. [Lista DXpedition Verificate (Ed25519)](#7-lista-dxpedition-verificate)
8. [Dual Carrier FT2](#8-dual-carrier)
9. [Async TX — Trasmissione senza sincronizzazione](#9-async-tx)
10. [Async FT2 Decoder — Sliding Window](#10-async-decoder)
11. [S-Meter e Visualizzatore Async](#11-s-meter)
12. [Sistema Temi (Dark Mode)](#12-sistema-temi)
13. [Interfaccia Dock e Layout](#13-interfaccia-dock)
14. [Toolbar e Barra di Stato](#14-toolbar)
15. [Ghost Filter](#15-ghost-filter)
16. [Contatore QSO di Sessione](#16-contatore-qso)
17. [Download Hamlib 4.7 da GitHub](#17-hamlib-download)
18. [DX Cluster Spot Automatico](#18-dx-cluster)
19. [Auto-Update e Installer](#19-auto-update)
20. [Compatibilità e Porting](#20-compatibilita)
21. [Cronologia Build](#21-cronologia)

---

## 1. FT2 Mode — Il cuore di Decodium {#1-ft2-mode}

**Data introduzione:** Febbraio 2026 (build iniziale)

FT2 è il modo digitale proprietario di Decodium, derivato da FT8 ma ottimizzato per velocità:

| Parametro | FT8 | FT2 |
|-----------|-----|-----|
| Periodo | 15 s | 3.75 s |
| Simboli (NN) | 79 | 103 |
| NSPS (samples/symbol) | 1920 | 288 |
| Durata segnale | ~12.6 s | ~2.47 s |
| Modulazione | 8-GFSK | 8-GFSK |
| Finestra DT | -0.5…+1.5 s | -0.52…+1.52 s |
| Frequenza campionamento | 12000 Hz | 12000 Hz |
| NMAX (campioni) | 180000 | 45000 |

**Caratteristiche tecniche:**
- Sincronizzazione Costas tone a 7 toni (come FT8)
- Codifica LDPC identica a FT8 (174,91)
- Packing a 77 bit standard (compatibile con tutti i tipi di messaggio FT8)
- Modulazione GFSK con pulse shaping gaussiano
- QSO completo in ~15 secondi (4 periodi × 3.75 s) contro ~60 s di FT8

**File sorgente principali:**
- `lib/ft2/ft2_decode.f90` — decoder FT2
- `lib/ft2/ft2_params.f90` — parametri (NSPS, NN, NMAX)
- `lib/ft2/genft2.f90` — generatore forma d'onda TX
- `lib/ft2/get_ft2_bitmetrics.f90` — estrazione metriche soft-bit

---

## 2. Shannon Decoder — Decodifica di nuova generazione {#2-shannon-decoder}

**Data introduzione:** Build 2603200134 (20 Marzo 2026)
**Aggiornamento major:** Build 2603221328 (22 Marzo 2026)

Il decoder Shannon è l'evoluzione del decoder FT2/FT8, con tre innovazioni chiave:

### 2.1 Best-of-N Costas Synchronization
Invece di una singola correlazione Costas, il decoder esegue **N tentativi** con parametri variati e seleziona il migliore:
- **Best-of-3** iniziale (build 2603221255)
- **Best-of-4** nella versione finale (build 2603221328)
- Migliora la decodifica in condizioni di basso SNR e QRM

### 2.2 MMSE Channel Estimation
**Minimum Mean Square Error** equalizzazione del canale:
- Stima adattiva del canale basata sui toni Costas pilota
- Equalizzazione delle metriche soft-bit in `get_ft2_bitmetrics`
- Guadagno: ~1-2 dB in condizioni di fading selettivo
- Introdotto: build 2603172124

### 2.3 Normalized Min-Sum LDPC
Sostituzione del decoder BP (Belief Propagation) standard con **Min-Sum normalizzato**:
- Riduce la complessità computazionale
- Migliora la convergenza su canali rumorosi
- Applicato a tutti i decoder BP (non solo FT2): build 2603182239
- Inizialmente isolato a FT2 (build 2603181634), poi esteso

### 2.4 Adaptive Sync
Algoritmo di sincronizzazione adattiva:
- `syncmin` e `smaxthresh` regolati dinamicamente
- `MAXCAND` aumentato per più candidati simultanei
- Sub-sample DT interpolation per precisione temporale

### 2.5 RR73 Loop Break
Ottimizzazione che interrompe il ciclo di retry RR73 dopo un massimo di tentativi:
- Previene loop infiniti durante il QSO
- Max 2-3 ripetizioni poi stop automatico

---

## 3. DXpedition Mode a 2 Slot {#3-dxpedition-mode}

**Data introduzione:** Build 2603040154 (4 Marzo 2026)
**Maturazione:** Build 2603050304 — Build 2603111500

Modalità DXpedition ispirata a MSHV, indipendente dal Fox mode di WSJT-X:

### Architettura
- `m_bDXpedMode`: flag indipendente da `SpecOp::FOX`
- **2 slot** simultanei con `DXpedSlot` struct per ogni slot
- Coda caller ordinata per **SNR decrescente**
- Sequenza QSO accelerata: **2 periodi TX** (RST → RR73+log) invece di 3

### Flusso operativo
1. CQ automatico quando la coda è vuota (`dxpedCQmode`)
2. Caller decodificato → `dxpedAutoSequence()` lo instrada
3. Se caller è in slot attivo → `dxpedRxProcess()` avanza la FSM
4. Se caller è nuovo → `enqueueCaller()` (ordinato per SNR)
5. Filtro B4 prima dell'enqueue (se `cbNoBefore` attivo)
6. Log automatico ADIF al completamento (`dxpedLogQSO()`)

### Features avanzate
- **Piggyback CQ** ogni 4 periodi TX (`m_dxpedCQcounter`)
- **MSHV-style sync** per sincronizzazione temporale
- **Freq-diversity**: slot con frequenze TX ≥150 Hz di distanza
- **Dual Carrier** in DXped: stessi dati su 2 sub-portanti (500 Hz spacing)
- **Missed periods**: timeout dopo 2 periodi mancati (era 4)
- **Auto-fill slot vuoti**: `dxpedFillEmptySlots()` con soft penalty -20dB SNR per freq vicine

### Evoluzione temporale
| Build | Feature |
|-------|---------|
| 2603040154 | Auto CQ MSHV-style + 2-slot base |
| 2603050304 | FSM fix, caller skip, JTAlert compat |
| 2603070004 | DT-aware caller queue, 3-carrier multistream |
| 2603100026 | DXped auto-sequence fix, Spot toggle |
| 2603111500 | DXped cert required, timing bar, queue input |

---

## 4. Auto CQ con Caller Queue {#4-auto-cq-caller-queue}

**Data introduzione:** Build 2602281659 (28 Febbraio 2026)
**Fix critico:** Build 2603222105 (22 Marzo 2026)

### Funzionalità
- Pulsante **Auto CQ** dedicato nella toolbar
- **Coda caller** visuale con gestione priorità
- Double-click per accodare manualmente una stazione
- Filtro **No B4** per escludere stazioni già lavorate
- Pannello AutoCQ con gestione coda (build 2603221027)

### Il bug critico (risolto 22 Marzo)
**Problema:** Auto CQ ignorava silenziosamente tutte le stazioni che rispondevano al nostro CQ. Il doppio-click manuale funzionava, ma Auto CQ no.

**Causa root:** Il flag `m_bAutoReply` veniva resettato a `false` dalla logica del pulsante Auto TX (`on_autoButton_clicked()`, riga 4604), impedendo a `auto_sequence()` di processare le risposte. La condizione critica era `m_bCallingCQ && m_bAutoReply` alla riga 8797.

**Fix (3 punti):**
```cpp
// Riga 1146 e 4604: guard con m_autoCQ
if (!m_autoCQ) m_bAutoReply = false;

// Riga 18451-18463: m_bAutoReply = true DOPO on_autoButton_clicked()
m_bCallingCQ = true;
ui->cbAutoSeq->setChecked(true);
if (!m_auto) {
  ui->autoButton->setChecked(true);
  on_autoButton_clicked(true);
}
m_bAutoReply = true;  // DOPO — altrimenti riga 4604 la resetta
```

---

## 5. Quick QSO — QSO in 2 messaggi {#5-quick-qso}

**Data introduzione:** Build 2603190215 (19 Marzo 2026)

Modalità per QSO ultra-rapidi in soli 2 messaggi:

### Flusso
1. **TX2** invia beacon con report (es. `IU8LMC IK0YUJ -05 TU`)
2. L'altra stazione risponde con 73
3. Log automatico

### Implementazione
- Encoding custom "Report + TU" in un singolo messaggio TX2
- Auto-detect della modalità dell'altra stazione
- `blockSignals` + deferred state restore per evitare glitch UI
- TX3 ritorna al messaggio standard (non più usato per TU)
- **Indipendente dal certificato** dalla build 2603191319

### Evoluzione
| Build | Cambiamento |
|-------|-------------|
| 2603190215 | Implementazione iniziale Quick QSO |
| 2603190018 | Fix flusso 2/3 messaggi, encoding custom |
| 2603191027 | Quick QSO beacon solo via TX2, TX3 standard |
| 2603191208 | Beacon TX2 + fix install path |
| 2603191319 | TU indipendente da certificato |
| 2603191419 | TU spostato in TX3 + serial unificato |

---

## 6. Sistema Certificati Decodium {#6-sistema-certificati}

**Data introduzione:** Build 2603191319 (19 Marzo 2026)

### Formato certificato
File `.dxcert` con formato testo:
```
DECODIUM-CERT-V1
CALL=IU8LMC
TIER=PRO
EXPIRES=2027-03-19
SIG=<HMAC-SHA256 hex>
```

### Livelli (Tier)
| Tier | Funzionalità |
|------|-------------|
| **NONE** | Funzionalità base |
| **FREE** | Decodium ID in TX2, Quick QSO, Badge verificato |
| **PRO** | Tutte le feature premium |

### Verifica crittografica
- **HMAC-SHA256** con chiave segreta offuscata nel binario
- Payload firmato: `CALL|TIER|EXPIRES`
- Verifica: confronto hex della firma

### Feature gates
```cpp
bool canSendDecodiumId()     // TU in TX2
bool canQuickQSO()           // Quick QSO mode
bool canShowVerifiedBadge()  // Badge D ✓
bool canUsePremiumFeatures() // Solo PRO
```

### File sorgente
- `DecodiumCertificate.hpp` — classe con enum Tier e feature gates
- `DecodiumCertificate.cpp` — load, verify (HMAC-SHA256), clear

---

## 7. Lista DXpedition Verificate (Ed25519) {#7-lista-dxpedition-verificate}

**Data introduzione:** Build 2603110027 (11 Marzo 2026)

Sistema di lista DXpedition verificata con firma crittografica Ed25519, più sicuro dell'HMAC usato per i certificati personali.

### Architettura

**Server-side:**
- Lista JSON firmata su `https://ft2.it/verified_dxpeds.json`
- Chiave privata Ed25519 in `tools/dxped_private.pem` (segreta)
- Tool di gestione: `tools/DXpedCertManager.py`, `tools/dxped_manage.py`

**Client-side:**
- Chiave pubblica Ed25519 (32 byte) hardcoded in `VerifiedDxpedList.hpp`
- Download + cache locale in `verified_dxpeds.json` nella data dir
- Verifica firma con OpenSSL `EVP_DigestVerify`

### Formato JSON firmato
```json
{
  "version": 2,
  "expires": "2026-06-11T00:00:00Z",
  "callsigns": ["3Y0K", "VU7W", "FT5XO", ...],
  "signature": "<base64 Ed25519 64-byte sig>"
}
```

### Processo di verifica
1. Parse JSON
2. Verifica `version >= 2`
3. Decodifica firma Base64 (64 byte Ed25519)
4. Ricostruisce payload canonico (JSON compatto senza campo `signature`)
5. Verifica Ed25519 con chiave pubblica hardcoded
6. Controlla scadenza (con grace period di 7 giorni per utenti offline)
7. Estrae callsign set

### Manager runtime
`VerifiedDxpedListManager` (QObject):
- `loadCached()` al costruttore (sincrono)
- `refresh()` scarica da ft2.it (asincrono)
- `addLocal()` per callsign da certificati locali
- Signal `callsignsUpdated` quando la lista cambia

### Certificate Manager GUI
Build 2603110027: interfaccia grafica per gestire certificati e lista verificata.

---

## 8. Dual Carrier FT2 {#8-dual-carrier}

**Data introduzione:** Build 2603070005 (7 Marzo 2026)

### Concetto
Trasmissione dello stesso messaggio su **2 sub-portanti** simultanee, distanziate di 500 Hz:
- Diversità di frequenza → migliore robustezza al fading selettivo
- Costo: **-3 dB** per portante (potenza totale invariata, divisa su 2)

### Implementazione
- `cbDualCarrier` checkbox nell'UI
- Copia messaggio in `foxcom_.cmsg[0]` e `foxcom_.cmsg[1]`, `nslots=2`
- Chiama `foxgenft2_()` per generare forma d'onda multi-portante
- `foxcom_.fstep = 500 Hz` (era 200 Hz nelle prime versioni)
- Label rosso "TX -3dB" visibile quando attivo

### Uso in DXped
In modalità DXpedition, il dual carrier permette di servire 2 stazioni diverse su 2 frequenze simultanee con `fstep = 500 Hz` di separazione.

---

## 9. Async TX — Trasmissione senza sincronizzazione {#9-async-tx}

**Data introduzione:** Build 2603080006 (8 Marzo 2026)

### Concetto
In FT2, il periodo di 3.75 s è già molto breve. L'Async TX elimina la necessità di aspettare l'inizio del periodo:

### Flusso
1. Decode ricevuto
2. Guard timer 300 ms (`m_asyncTxGuardTimer`)
3. TX immediato bypassando periodo 3.75 s
4. Modulator::start con `synchronize=false`
5. TX dura 1.28 s (2.47 s segnale compresso)
6. Ritorno in RX

**QSO completo in ~6 secondi** (decode → 300ms → TX → RX → decode)

### Flag e meccanismo
- `m_bAsyncTxArmed` forza `m_bTxTime=true` in `guiUpdate()`
- `asyncBypass` evita il kill del TX a fine periodo
- Trigger da `auto_tx_mode()` e `process_autoButton()`
- Checkbox "Async L2" nell'UI + label verde "L2"

---

## 10. Async FT2 Decoder — Sliding Window {#10-async-decoder}

**Data introduzione:** Build 2603070006 / 2603080001 (7-8 Marzo 2026)

### Architettura
Decoder continuo a finestra scorrevole, senza aspettare la fine del periodo:

- **Ring buffer**: `m_asyncAudio[90000]` (7.5 s @ 12 kHz)
- **Timer**: `m_asyncDecodeTimer` ogni 1.5 s
- Ogni tick estrae gli ultimi 45000 campioni (= 1 finestra FT2)
- Decodifica via `ft2_async_decode_()` in `QtConcurrent::run`
- Risultati in `m_asyncMsg[100][80]`

### Deduplicazione
- `m_asyncDedupeSet` (QSet<QString>) per evitare duplicati
- Clear automatico ogni 10 s
- Chiave = testo messaggio dopo il campo frequenza

### Fortran module
- `lib/ft2/ft2_async_decode.f90`: modulo `ft2_async_mod`
- Callback stores risultati in array `async_results(100)`
- Nessun file I/O (tutto in memoria)

---

## 11. S-Meter e Visualizzatore Async {#11-s-meter}

**Data introduzione:** Build 2603171317 (17 Marzo 2026)

### S-Meter
- SNR letto dal path di decodifica standard di jt9
- Parsing che preserva gli spazi iniziali Fortran (`i4`)
- Sempre visibile nella UI
- Toggle wave/meter con right-click

### Visualizzatore Async
- Onda sinusoidale animata per stato RX/TX
- Display dB dal S-meter
- Posizionato accanto ai pulsanti TX
- Dimensioni compatte: 90×50 px

---

## 12. Sistema Temi (Dark Mode) {#12-sistema-temi}

**Data introduzione:** Build 2603220022 (22 Marzo 2026)

### Temi disponibili
| Tema | Descrizione |
|------|-------------|
| **Shannon Light** | Tema chiaro predefinito |
| **Shannon Dark** | Tema scuro |
| **Midnight** | Tema molto scuro (OLED-friendly) |
| **Classic** | Stile WSJT-X originale |

### Implementazione
- Palette e stylesheet caricate da `Palettes/` directory
- Installate con l'installer (sia x64 che x86)
- Selezionabili dal menu

---

## 13. Interfaccia Dock e Layout {#13-interfaccia-dock}

**Data introduzione:** Build 2603211439 (21 Marzo 2026)

### Innovazioni
- **Tutti i controlli sono QDockWidget** agganciabili
- **Dock nesting** abilitato (dock dentro dock)
- **Layout presets** salvabili e richiamabili
- **Reset Layout** per tornare alla configurazione predefinita
- **Waterfall come dock** all'interno della finestra principale (build 2603201952)

### Evoluzione
| Build | Feature |
|-------|---------|
| 2603201952 | Waterfall docked nella finestra principale |
| 2603210030 | Full dock layout + icona FT2 bianca + Reset Layout |
| 2603211439 | Layout presets + dock nesting completo |
| 2603211523 | Fix ridimensionamento dock + ADIF in app dir |

---

## 14. Toolbar e Barra di Stato {#14-toolbar}

**Data introduzione:** Build 2603220209 (22 Marzo 2026)

### Toolbar
- Pulsanti rapidi per le funzioni più usate
- Icone Shannon-style

### Barra di stato
- **Indicatore progresso QSO**: stato corrente della sequenza
- **Righe alternate** nelle tabelle Band Activity / Rx Frequency
- **Preset FT2** rapido
- **Contatore QSO di sessione** (vedi §16)

---

## 15. Ghost Filter {#15-ghost-filter}

**Data introduzione:** Build 2603200141 (20 Marzo 2026)
**Fix critico:** Build 2603221027 (22 Marzo 2026)

### Problema
Stazioni "fantasma" (decodifiche vecchie o spurie) rimanevano nel filtro interno, bloccando nuove decodifiche legittime dalla stessa frequenza.

### Soluzione
- Pulizia automatica delle entry obsolete nel filtro
- Timeout configurabile per entry nel filtro
- Build 2603221027: fix che impediva alle decodifiche di essere bloccate da filtri ghost

### Evoluzione
| Build | Feature |
|-------|---------|
| 2603160728 | Callsign filter anti-ghost (ITU regex) |
| 2603160916 | Relaxed — ITU regex troppo restrittivo |
| 2603160948 | Rimosso filtro callsign del tutto |
| 2603200141 | Ghost filter magnetico su waterfall |
| 2603221027 | Fix ghost filter che bloccava decode |

---

## 16. Contatore QSO di Sessione {#16-contatore-qso}

**Data introduzione:** Build 2603221145 (22 Marzo 2026)

### Differenza dal contatore WSJT-X
| | WSJT-X | Decodium Shannon |
|---|--------|-----------------|
| Reset | Mezzanotte UTC | Apertura programma |
| Tipo | Giornaliero | Sessione |
| Display | "Today:N" | "QSO:N" |

### Implementazione
- `m_qsoSessionCount` inizializzato a 0 al costruttore
- Incremento su ogni `logIncremental()`
- Nessuna scansione ADIF all'avvio
- Display: `"QSO:%1 | Up:%2"` nella status bar
- Tooltip: "QSOs this session / total to upload"

---

## 17. Download Hamlib 4.7 da GitHub {#17-hamlib-download}

**Data introduzione:** Build 2603221145 (22 Marzo 2026)
**Fix URL:** Build 2603221428 (22 Marzo 2026)

### Problema originale
- URL SourceForge (`n0nb.users.sourceforge.net`) restituiva pagina HTML invece della DLL
- Il file HTML veniva salvato come `libhamlib-4.dll` → crash all'avvio

### Soluzione
- **URL** cambiati a GitHub Releases ufficiali Hamlib 4.7:
  - x64: `https://github.com/Hamlib/Hamlib/releases/download/4.7/hamlib-w64-4.7.zip`
  - x32: `https://github.com/Hamlib/Hamlib/releases/download/4.7/hamlib-w32-4.7.zip`
- Download ZIP → estrazione DLL → validazione dimensione (>1 MB)
- Verifica content-type (rifiuta `text/html`)

### Fix Windows 10 (build 2603221428)
- Rimosso `NoLessSafeRedirectPolicy` che bloccava i redirect HTTPS→HTTP su Windows 10
- I download ora funzionano sia su Windows 10 che Windows 11

---

## 18. DX Cluster Spot Automatico {#18-dx-cluster}

**Data introduzione:** Build 2603090018 (9 Marzo 2026)

### Funzionalità
- Spot automatico al DX cluster su QSO loggato
- Connessione Telnet a cluster (es. W3LPL, iq8do.aricaserta.it)
- Protocollo AR-Cluster con auto-detect prompt

### Evoluzione
| Build | Fix |
|-------|-----|
| 2603090018 | Implementazione base |
| 2603090019 | Fix freq kHz, robust Telnet read |
| 2603090020 | QTcpSocket su main thread |
| 2603090021 | QPointer guard per timer async |
| 2603100024 | Fix AR-Cluster prompt detection |
| 2603100026 | Spot toggle button |
| 2603111500 | DX Cluster integrato |
| 2603170141 | Guard checkbox + rate limit 20/h anti-abuse |

---

## 19. Auto-Update e Installer {#19-auto-update}

### Auto-Update
- `UpdateChecker` controlla nuove versioni su GitHub
- Regex: `QRegExp rx("v3\\.0\\.(\\d{10})")` per parsing tag
- Skip version + stop nagging dopo N dismissals
- Build tag a 10 cifre (formato: AAMMDDHHMM)

### Installer (Inno Setup 6)
- **x64**: `Decodium_FT2_{BUILD}_x64_Setup.exe`
- **x86**: `Decodium_FT2_{BUILD}_x86_Setup.exe`
- Code signing PFX con SHA256 + timestamp DigiCert
- Firewall rule UDP automatica all'installazione
- Directory app scrivibile per log ADIF
- Auto-launch dopo installazione

### Pipeline build
```
build_installers.bat:
  1. Copia exe da build-w2 a dist_64bit
  2. Firma exe x64 (signtool SHA256)
  3. Firma exe x86
  4. Compila installer x64 (ISCC)
  5. Compila installer x86 (ISCC)
  6. Firma installer
```

---

## 20. Compatibilità e Porting {#20-compatibilita}

### UDP Protocol
- ID UDP: "WSJTX" per compatibilità JTAlert/Gridtracker
- Porta effimera (rimossa porta fissa 2238)
- Mode FT2 inviato come FT8 per compatibilità JTAlert

### Branding
| Data | Nome |
|------|------|
| Feb 2026 | Decodium v3.0 FT2 Raptor |
| 8 Mar | Decodium 3.0 ASYMX Official |
| 9 Mar | Rimosso ChronoGPS, nuova icona ASYMX |
| 15 Mar | Decodium Fast Track 2 |
| 20 Mar | **Decodium Shannon** (nome finale) |

### Ottimizzazioni
- SIMD SSE4.2 (downgrade da AVX2 per compatibilità Win7)
- Fix FT2 TX buffer overflow (build 2603151750)
- Fix FT2 TX timing (ramp-up/down, latency) per TCI e soundcard

### Internazionalizzazione
- Menu Language per cambio lingua a runtime
- Lingue: EN, IT, ES, DE, TR
- `UILanguage` da `MultiSettings`

---

## 21. Cronologia Build Completa {#21-cronologia}

| Build | Data | Milestone principali |
|-------|------|---------------------|
| 2602260045 | 26 Feb | Prima release FT2 Raptor, DT feedback, ChronoGPS |
| 2602270204 | 27 Feb | Rimosso DT feedback, rename wsjtx→decodium |
| 2602281659 | 28 Feb | B4 strikethrough, Auto CQ caller queue, TX bracket waterfall |
| 2603010555 | 1 Mar | Multi-period averaging +4dB, Auto CQ display |
| 2603040154 | 4 Mar | Auto CQ MSHV-style, DXped 2-slot |
| 2603050304 | 5 Mar | DXped FSM fix, JTAlert compat, x64+x86 |
| 2603070005 | 7 Mar | Dual Carrier FT2, freq-diversity, fstep 500Hz |
| 2603080001 | 8 Mar | Async FT2 decoder sliding window |
| 2603080005 | 8 Mar | Eliminati DT/NTP time sync |
| 2603080006 | 8 Mar | Async TX senza sincronizzazione periodo |
| 2603090018 | 9 Mar | DX cluster spot automatico |
| 2603100026 | 10 Mar | DXped auto-sequence fix, Spot toggle |
| 2603110027 | 11 Mar | Ed25519 verified DXped list, Certificate Manager |
| 2603111500 | 11 Mar | DXped cert required, ASYMX badge, timing bar |
| 2603152359 | 15 Mar | Rebrand Decodium Fast Track 2 |
| 2603160728 | 16 Mar | SIMD SSE4.2, callsign filter |
| 2603162146 | 16 Mar | Colors fix, async visualizer, language menu |
| 2603170141 | 17 Mar | i18n, DX spot guard, async latency |
| 2603171317 | 17 Mar | S-meter, wave/meter toggle |
| 2603172124 | 17 Mar | MMSE channel estimation, message count 2/3/5 |
| 2603181634 | 18 Mar | Min-Sum LDPC (FT2), auto-sequence fix |
| 2603182239 | 18 Mar | Min-Sum LDPC per tutti i decoder BP |
| 2603190215 | 19 Mar | Quick QSO, 2-msg beacon |
| 2603191319 | 19 Mar | Decodium certificate system |
| 2603191419 | 19 Mar | TU in TX3, serial unificato |
| 2603200134 | 20 Mar | FT2 decoder v2 — push Shannon limit |
| 2603200201 | 20 Mar | Rebrand **Decodium Shannon** |
| 2603201741 | 20 Mar | Ghost filter, magnetic waterfall dock, logo Shannon |
| 2603201952 | 20 Mar | Waterfall docked |
| 2603210030 | 21 Mar | Full dock layout, Reset Layout |
| 2603211439 | 21 Mar | Layout presets, dock nesting |
| 2603220022 | 22 Mar | Theme system, AutoCQ/DXped bugfix |
| 2603220209 | 22 Mar | Toolbar, QSO progress, status bar |
| 2603221027 | 22 Mar | Ghost filter fix, AutoCQ panel, dark mode, QSO counter |
| 2603221145 | 22 Mar | Hamlib GitHub download, session QSO counter |
| 2603221328 | 22 Mar | Shannon decoder: best-of-N Costas, adaptive sync |
| 2603221428 | 22 Mar | Fix download Windows 10 |
| **2603222105** | **22 Mar** | **Fix Auto CQ ignoring callers, remove RF Analyzer** |

---

## Riepilogo Numerico

| Metrica | Valore |
|---------|--------|
| Periodo di sviluppo | 16 Feb — 23 Mar 2026 (35 giorni) |
| Build rilasciate | ~70+ |
| Commit totali | ~150+ |
| Feature principali | 20+ |
| Decoder innovations | 4 (Costas N-best, MMSE, Min-Sum LDPC, Async sliding) |
| Sistemi crittografici | 2 (HMAC-SHA256 certificati, Ed25519 DXped list) |
| Modi operativi | FT2, DXped 2-slot, Quick QSO, Async TX, Dual Carrier |
| Piattaforme | Windows x64, Windows x86 |
| Temi UI | 4 (Shannon Light/Dark, Midnight, Classic) |

---

**Decodium Shannon v3.0 — Pushing the Shannon Limit**

*73 de IU8LMC*

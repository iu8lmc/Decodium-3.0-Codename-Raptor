# Decodium 3.0 ASYMX

**Asynchronous weak-signal digital communication client — FT2 mode (3.75s, 4-GFSK)**
Based on WSJT-X 3.0.0 RC1 — async TX, enhanced decoder, built-in alert engine.

**Build:** 2603141352 | **Codename:** ASYMX | **Author:** IU8LMC | **License:** GPL v3

[![Download Latest](https://img.shields.io/github/v/release/iu8lmc/Decodium-3.0-Codename-Raptor?label=Download&style=for-the-badge)](https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor/releases/latest)

---

> **[Italiano](#italiano)** | **[English](#english)** | **[Español](#español)**

---

<a name="english"></a>
## 🇬🇧 English

### Downloads

| Installer | Platform |
|-----------|----------|
| [**x64 Setup**](https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor/releases/latest) | Windows 10/11 64-bit (recommended) |
| [**x86 Setup**](https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor/releases/latest) | Windows 10/11 32-bit |
| [**x64 Win7 Setup**](https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor/releases/latest) | Windows 7/8 64-bit |
| [**x86 Win7 Setup**](https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor/releases/latest) | Windows 7/8 32-bit |

All installers are digitally signed (SHA256 + RFC3161 timestamp).

---

### Key Features

#### Async FT2 TX (No Period Sync Required)
- TX fires immediately after decode — no waiting for even/odd period alignment
- Full QSO cycle in ~6 seconds (decode → 300ms guard → 1.28s TX → RX)
- Ideal for portable, QRP, and rapid contest operation

#### Smart Frequency Finder (NEW — Build 2603141145+)
- **Auto Offset TX** — When responding to a CQ, TX is automatically placed on a clear frequency away from RX. Eliminates QRM from other callers on the same frequency
- **Find Clear button** — One-click scan to find the least-crowded frequency in the 200–2500 Hz audio passband
- **FT2 TX≠RX enforced** — In FT2 mode, TX frequency is ALWAYS different from RX (mandatory, not optional)
- **Real-time frequency tracking** — All decoded signals are tracked (30s window) to build a live occupancy map

#### Intelligent Auto-Sequence (NEW — Build 2603141145+)
- **Auto TX frequency change** — After 3 failed call attempts, TX automatically shifts to a new clear frequency
- **Extended retry tolerance** — MAX_TX_RETRIES=6, MAX_MISSED_PERIODS=8 (optimized for async FT2 timing)
- **Async decode tolerance** — Period-miss counter adapts to FT2 async timing instead of rigid FT8 periods
- **Reset on valid response** — Retry counter resets when the other station responds, preventing premature timeout

#### DXpedition 2-Slot Mode
- Dual-carrier TX on two independent frequencies (500 Hz spacing)
- FSM auto-sequencer: CQ → RST → RR73+log → next caller
- SNR-sorted caller queue with frequency distance penalty
- 2-period QSO cycle (RST → RR73+log), piggyback CQ every 4 TX periods

#### Built-in Alert Engine (replaces JTAlert)
- **12 Audio Alerts:** CQ, MyCall, DXCC, DXCCOnBand, Grid, GridOnBand, Continent, ContinentOnBand, CQZone, CQZoneOnBand, ITUZone, ITUZoneOnBand
- **B4 Tracking:** strikethrough + color highlight per type (call, country, grid, continent, zone)
- **DXCC / Country / Zone lookup:** integrated cty.dat with auto-update (30-day check)
- **Customizable Color Highlights:** CQ, MyCall, DXCC, Grid, Continent, Zone, LoTW
- **LoTW User Highlighting:** stations on LoTW shown with distinct color
- **DX Call Alert:** audio + visual alert on specific callsigns
- **No B4 Filter:** hide stations already worked on band

#### Auto CQ with Caller Queue
- Dedicated Tab 2 with FIFO queue (max 20 stations)
- Double-click enqueues callers during active QSO
- SNR-sorted, auto-process on QSO completion

#### FT2 Decoder Enhancements

| Parameter | Value | Effect |
|-----------|-------|--------|
| syncmin | 0.90 | Balanced sync threshold |
| MAXCAND | 300 | More candidates evaluated |
| nsp | 4 | 4th subtraction pass |
| OSD depth | 3 | Aggressive LDPC decoding |
| SNR floor | -21 dB | Weak signal reporting |
| Freq range | 200–4910 Hz | Extended bandwidth |
| Freq grid | 2 Hz | Finer sync search |

#### Async Sliding Window Decoder
- Continuous 1.5s decode ticks on a 7.5s ring buffer (45000 samples)
- Deduplication with 10s window (QSet-based)
- Background decoding via QtConcurrent — no UI freeze

#### Logging & Integration
- **N1MM Logger+** — real-time UDP broadcast
- **Cloudlog** — direct API logging
- **LoTW** — upload/download QSO
- **PSKReporter** — automatic spot reporting
- **OmniRig** — auto-launch with COM wait loop
- **Cabrillo** — contest logging support

#### Ed25519 Signed DXpedition List
- Verified DXpedition list with Ed25519 cryptographic signatures
- Certificate Manager GUI for managing DXpedition certificates

---

### Building from Source

#### Requirements
- MSYS2 MinGW-w64 (GCC 15.x, gfortran)
- Qt 5.15.x + Boost
- CMake 3.x

#### Build
```bash
cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=C:/msys64/mingw64/bin/mingw32-make.exe
mingw32-make -j4 decodium
```

#### Create Installers
Requires [Inno Setup 6](https://jrsoftware.org/isinfo.php):
```
build_installers.bat
```

---

### Changelog (Recent)

#### Build 2603141352 (2026-03-14) — Latest
- Smart Frequency Finder: Auto Offset TX + Find Clear button
- FT2 TX≠RX enforced: TX always on a different frequency from RX
- Intelligent auto-sequence: auto TX freq change after 3 failed retries
- Extended retry tolerance for async FT2 (MAX_TX_RETRIES=6, MAX_MISSED_PERIODS=8)
- Async decode period-miss tolerance + reset on valid response

#### Build 2603140700 (2026-03-14)
- Fix async FT2 decoder crash on startup (Fortran FCL overflow)
- Fix null-terminator bug in async decode results

#### Build 2603132108 (2026-03-13)
- DXpedition 2-slot mode with dual-carrier TX
- SNR-sorted caller queue with frequency distance penalty
- 2-period QSO cycle, piggyback CQ

#### Build 2603110028 (2026-03-11)
- Ed25519 signed verified DXpedition list
- Certificate Manager GUI

#### Build 2603080006 (2026-03-08)
- Async TX: bypass period synchronization in FT2
- Guard timer 300ms between decode and TX
- Full QSO in ~6 seconds

#### Build 2603080005 (2026-03-08)
- Remove NTP/DT timing system (simplified)
- Caller queue scoring = SNR only

#### Build 2603070006 (2026-03-07)
- Async sliding window decoder (1.5s ticks, 7.5s buffer)
- QtConcurrent background decoding
- 10s deduplication window

---

<a name="italiano"></a>
## 🇮🇹 Italiano

### Caratteristiche Principali

#### TX Asincrono FT2 (Senza Sincronizzazione di Periodo)
- Il TX parte immediatamente dopo la decodifica — nessuna attesa per l'allineamento pari/dispari
- Ciclo QSO completo in ~6 secondi (decodifica → 300ms pausa → 1.28s TX → RX)
- Ideale per operazioni portatili, QRP e contest veloci

#### Ricerca Frequenza Intelligente (NOVITÀ — Build 2603141145+)
- **Auto Offset TX** — Rispondendo a un CQ, il TX viene posizionato automaticamente su una frequenza libera lontana dall'RX. Elimina il QRM da altri chiamanti sulla stessa frequenza
- **Pulsante Find Clear** — Scansione con un click per trovare la frequenza meno affollata nel range 200–2500 Hz
- **TX≠RX obbligatorio in FT2** — La frequenza TX è SEMPRE diversa dall'RX (obbligatorio, non opzionale)
- **Tracciamento frequenze in tempo reale** — Tutti i segnali decodificati vengono tracciati (finestra 30s) per costruire una mappa di occupazione

#### Auto-Sequenza Intelligente (NOVITÀ — Build 2603141145+)
- **Cambio automatico frequenza TX** — Dopo 3 tentativi di chiamata falliti, il TX si sposta automaticamente su una nuova frequenza libera
- **Tolleranza retry estesa** — MAX_TX_RETRIES=6, MAX_MISSED_PERIODS=8 (ottimizzato per il timing asincrono FT2)
- **Tolleranza decodifica asincrona** — Il contatore periodi mancati si adatta al timing FT2 invece dei periodi rigidi FT8
- **Reset su risposta valida** — Il contatore retry si azzera quando l'altra stazione risponde

#### Modalità DXpedition 2-Slot
- TX dual-carrier su due frequenze indipendenti (spaziatura 500 Hz)
- Auto-sequencer FSM: CQ → RST → RR73+log → prossimo chiamante
- Coda chiamanti ordinata per SNR con penalità distanza in frequenza
- Ciclo QSO a 2 periodi (RST → RR73+log), CQ piggyback ogni 4 periodi TX

#### Motore Alert Integrato (sostituisce JTAlert)
- **12 Avvisi Audio:** CQ, MyCall, DXCC, DXCCOnBand, Grid, GridOnBand, Continente, ContinenteOnBand, CQZone, CQZoneOnBand, ITUZone, ITUZoneOnBand
- **Tracciamento B4:** barrato + colore evidenziato per tipo (call, paese, grid, continente, zona)
- **Lookup DXCC / Paese / Zona:** cty.dat integrato con aggiornamento automatico
- **Colori Personalizzabili:** CQ, MyCall, DXCC, Grid, Continente, Zona, LoTW
- **Evidenziazione Utenti LoTW:** stazioni su LoTW con colore distinto
- **Avviso DX Call:** alert audio + visivo su callsign specifici
- **Filtro No B4:** nasconde stazioni già lavorate sulla banda

#### Auto CQ con Coda Chiamanti
- Tab 2 dedicato con coda FIFO (max 20 stazioni)
- Doppio-click accoda i chiamanti durante QSO attivo
- Ordinamento SNR, elaborazione automatica al completamento QSO

#### Decoder FT2 Asincrono a Finestra Scorrevole
- Tick di decodifica continui ogni 1.5s su buffer circolare 7.5s (45000 campioni)
- Deduplicazione con finestra 10s
- Decodifica in background via QtConcurrent — nessun blocco UI

#### Lista DXpedition con Firma Ed25519
- Lista DXpedition verificata con firme crittografiche Ed25519
- GUI Certificate Manager per la gestione dei certificati

#### Logging & Integrazioni
- N1MM Logger+, Cloudlog, LoTW, PSKReporter, OmniRig, Cabrillo

---

### Cronologia Modifiche (Recenti)

#### Build 2603141352 (14-03-2026) — Ultima
- Ricerca Frequenza Intelligente: Auto Offset TX + pulsante Find Clear
- TX≠RX obbligatorio in FT2: TX sempre su frequenza diversa da RX
- Auto-sequenza intelligente: cambio automatico freq TX dopo 3 tentativi falliti
- Tolleranza retry estesa per FT2 asincrono
- Tolleranza periodi mancati + reset su risposta valida

#### Build 2603140700 (14-03-2026)
- Fix crash decoder FT2 asincrono all'avvio (overflow FCL Fortran)
- Fix bug null-terminator nei risultati di decodifica asincrona

#### Build 2603132108 (13-03-2026)
- Modalità DXpedition 2-slot con TX dual-carrier
- Coda chiamanti ordinata per SNR

#### Build 2603080006 (08-03-2026)
- TX Asincrono: bypass sincronizzazione periodo in FT2
- QSO completo in ~6 secondi

#### Build 2603070006 (07-03-2026)
- Decoder asincrono a finestra scorrevole (tick 1.5s, buffer 7.5s)

---

<a name="español"></a>
## 🇪🇸 Español

### Características Principales

#### TX Asíncrono FT2 (Sin Sincronización de Período)
- El TX se activa inmediatamente después de la decodificación — sin esperar alineación de períodos par/impar
- Ciclo QSO completo en ~6 segundos (decodificación → 300ms pausa → 1.28s TX → RX)
- Ideal para operaciones portátiles, QRP y concursos rápidos

#### Buscador Inteligente de Frecuencia (NUEVO — Build 2603141145+)
- **Auto Offset TX** — Al responder un CQ, el TX se coloca automáticamente en una frecuencia libre alejada del RX. Elimina el QRM de otros llamantes en la misma frecuencia
- **Botón Find Clear** — Escaneo con un click para encontrar la frecuencia menos congestionada en el rango 200–2500 Hz
- **TX≠RX obligatorio en FT2** — La frecuencia TX es SIEMPRE diferente de RX (obligatorio, no opcional)
- **Seguimiento de frecuencias en tiempo real** — Todas las señales decodificadas se rastrean (ventana 30s) para construir un mapa de ocupación en vivo

#### Auto-Secuencia Inteligente (NUEVO — Build 2603141145+)
- **Cambio automático de frecuencia TX** — Después de 3 intentos de llamada fallidos, el TX se desplaza automáticamente a una nueva frecuencia libre
- **Tolerancia de reintento extendida** — MAX_TX_RETRIES=6, MAX_MISSED_PERIODS=8 (optimizado para temporización asíncrona FT2)
- **Tolerancia de decodificación asíncrona** — El contador de períodos perdidos se adapta a la temporización FT2 en lugar de los períodos rígidos de FT8
- **Reset con respuesta válida** — El contador de reintentos se reinicia cuando la otra estación responde

#### Modo DXpedición 2-Slot
- TX dual-carrier en dos frecuencias independientes (espaciado 500 Hz)
- Auto-secuenciador FSM: CQ → RST → RR73+log → siguiente llamante
- Cola de llamantes ordenada por SNR con penalización por distancia en frecuencia
- Ciclo QSO de 2 períodos (RST → RR73+log), CQ piggyback cada 4 períodos TX

#### Motor de Alertas Integrado (reemplaza JTAlert)
- **12 Alertas de Audio:** CQ, MyCall, DXCC, DXCCOnBand, Grid, GridOnBand, Continente, ContinenteOnBand, CQZone, CQZoneOnBand, ITUZone, ITUZoneOnBand
- **Seguimiento B4:** tachado + resaltado de color por tipo (indicativo, país, grid, continente, zona)
- **Búsqueda DXCC / País / Zona:** cty.dat integrado con actualización automática
- **Colores Personalizables:** CQ, MyCall, DXCC, Grid, Continente, Zona, LoTW
- **Resaltado Usuarios LoTW:** estaciones en LoTW con color distintivo
- **Alerta DX Call:** alerta audio + visual en indicativos específicos
- **Filtro No B4:** oculta estaciones ya trabajadas en la banda

#### Auto CQ con Cola de Llamantes
- Pestaña 2 dedicada con cola FIFO (máx 20 estaciones)
- Doble-click encola llamantes durante QSO activo
- Ordenamiento por SNR, procesamiento automático al completar QSO

#### Decodificador FT2 Asíncrono de Ventana Deslizante
- Ticks de decodificación continuos cada 1.5s en buffer circular de 7.5s (45000 muestras)
- Deduplicación con ventana de 10s
- Decodificación en segundo plano via QtConcurrent — sin congelamiento de UI

#### Lista DXpedición con Firma Ed25519
- Lista de DXpediciones verificada con firmas criptográficas Ed25519
- GUI Certificate Manager para gestión de certificados

#### Registro e Integraciones
- N1MM Logger+, Cloudlog, LoTW, PSKReporter, OmniRig, Cabrillo

---

### Historial de Cambios (Recientes)

#### Build 2603141352 (14-03-2026) — Última
- Buscador Inteligente de Frecuencia: Auto Offset TX + botón Find Clear
- TX≠RX obligatorio en FT2: TX siempre en frecuencia diferente de RX
- Auto-secuencia inteligente: cambio automático de freq TX después de 3 intentos fallidos
- Tolerancia de reintento extendida para FT2 asíncrono
- Tolerancia de períodos perdidos + reset con respuesta válida

#### Build 2603140700 (14-03-2026)
- Fix crash del decodificador FT2 asíncrono al inicio (overflow FCL Fortran)
- Fix bug null-terminator en resultados de decodificación asíncrona

#### Build 2603132108 (13-03-2026)
- Modo DXpedición 2-slot con TX dual-carrier
- Cola de llamantes ordenada por SNR

#### Build 2603080006 (08-03-2026)
- TX Asíncrono: bypass de sincronización de período en FT2
- QSO completo en ~6 segundos

#### Build 2603070006 (07-03-2026)
- Decodificador asíncrono de ventana deslizante (tick 1.5s, buffer 7.5s)

---

## Key Differences from Stock WSJT-X

| Feature | Decodium ASYMX | Stock WSJT-X |
|---------|---------------|--------------|
| Async TX | Yes (no period sync) | No |
| Smart Freq Finder | Auto Offset + Find Clear | No |
| TX≠RX in FT2 | Enforced | Same freq |
| Auto TX Freq Change | After 3 failed retries | No |
| DXped 2-Slot | Dual-carrier, FSM auto-seq | Fox/Hound |
| Built-in Alerts | 12 types + B4 + LoTW | No (needs JTAlert) |
| Caller Queue | FIFO max 20, SNR-sorted | Fox only |
| Async Decoder | Sliding window 1.5s/7.5s | Period-based |
| DXped Certificates | Ed25519 signed | No |
| No B4 Filter | Yes | No |
| Auto CTY.DAT | Yes (30-day) | Manual |
| B4 Strikethrough | Yes | No |
| TX Bracket Waterfall | Yes | No |

---

## Credits
- **WSJT-X** by Joe Taylor K1JT and the WSJT Development Group
- **WSJT-X 3.0.0** fork by WM8Q (avantol)
- **Decodium 3.0 ASYMX** by IU8LMC

73 de IU8LMC

[![Buy Me a Coffee](https://img.shields.io/badge/Buy%20Me%20a%20Coffee-FFDD00?style=for-the-badge&logo=buy-me-a-coffee&logoColor=black)](https://buymeacoffee.com/iu8lmc)

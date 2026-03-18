# Decodium Fast Track 2

**The fastest and most sensitive FT2 client in the world.**
*El cliente FT2 más rápido y sensible del mundo.*
*Il client FT2 più veloce e sensibile al mondo.*
*Der schnellste und empfindlichste FT2-Client der Welt.*
*Dünyanın en hızlı ve en hassas FT2 istemcisi.*

Fork of WSJT-X 3.0 focused on asynchronous FT2 — real-time decoding, instant TX, sensitivity close to FT8.

**Build:** 2603182218 | **Author:** IU8LMC | **License:** GPL v3

---

## Downloads

| Architecture | Link |
|---|---|
| **Windows x64** (recommended) | [Decodium_FT2_x64_Setup.exe](https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor/releases/latest) |
| **Windows x86** (32-bit) | [Decodium_FT2_x86_Setup.exe](https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor/releases/latest) |

Digitally signed installers (SHA256 + DigiCert RFC3161 timestamp).

---

## What's New — Build 2603182218

### [EN] English

#### Normalized Min-Sum LDPC Decoder
The LDPC(174,91) decoder now uses **Normalized Min-Sum** algorithm instead of Sum-Product (tanh/atanh). Replaces the expensive `tanh()` / `product()` / `atanh()` chain with `sign() * min(|msg|) * alpha` (alpha=0.75). Benefits:
- **+0.2-0.4 dB** sensitivity improvement on weak signals
- **Faster computation** — `min()` is cheaper than `tanh()/atanh()`
- Isolated in FT2-specific decoder (`decode174_91_ft2.f90`) — does NOT touch the shared FT8/FT4/Q65 backend

#### QSO Message Count Auto-Sequence Fix
Fixed inconsistency between 2/3/5-msg modes and auto-sequencing:
- **`m_sentFirst73` protection**: now set in the re-route path (2/3-msg skip TX5) to block late messages from the old QSO partner — prevents phantom QSOs
- **`qsoCooldown` injection**: manually inserted when TX3 is skipped (m_QSOProgress never reaches ROGER_REPORT), preventing the same station from being re-processed

#### Band Activity Colors Fix
Non-CQ messages (QSO in progress, reports, 73) were always displayed in grey. Now DXCC/B4/Grid/Continent highlighting is applied to ALL messages when "Show DXCC entity and worked before status" is enabled:
- **New DXCC** → magenta
- **New on band** → colored by priority
- **Worked before on band** → grey + strikethrough
- **MyCall** → red (highest priority)
- **CQ** → green (unchanged)

#### Async Mode Visualizer
New animated widget replacing the static green "FT2" badge:
- **Animated sine wave** — green during RX, red during TX
- **S-meter bar** — shows dB SNR of the last decoded station with color gradient (red→yellow→green)
- **"ASINCRONO" header** — switches to "TX" when transmitting
- Located in the control panel near Hold Tx Freq / Dual Carrier

#### Language Menu
Full multilingual support with 10 languages selectable from the menu bar:
- English, Italiano, Español, Català, Dansk, 日本語, Русский, 中文(简体), 中文(繁體), English (UK)
- Language preference saved persistently — survives restarts
- Select Language menu → choose language → restart to apply

---

### [ES] Español

#### Decodificador LDPC Min-Sum Normalizado
El decodificador LDPC(174,91) ahora usa el algoritmo **Min-Sum Normalizado** en lugar de Sum-Product (tanh/atanh). Reemplaza la cadena costosa `tanh()` / `product()` / `atanh()` con `sign() * min(|msg|) * alpha` (alpha=0.75):
- **+0.2-0.4 dB** de mejora en sensibilidad
- **Cálculo más rápido** — `min()` es más barato que `tanh()/atanh()`
- Aislado en decoder FT2-específico (`decode174_91_ft2.f90`) — NO toca el backend compartido FT8/FT4/Q65

#### Corrección de Auto-Secuencia con Conteo de Mensajes QSO
Corregida inconsistencia entre los modos 2/3/5 mensajes y la auto-secuencia:
- **Protección `m_sentFirst73`**: ahora se establece en la ruta de re-enrutamiento para bloquear mensajes tardíos del antiguo compañero de QSO
- **Inyección de `qsoCooldown`**: insertado manualmente cuando se omite TX3

#### Corrección de Colores en Actividad de Banda
Los mensajes que no son CQ (QSO en curso, reportes, 73) siempre se mostraban en gris. Ahora el resaltado DXCC/B4/Grid/Continente se aplica a TODOS los mensajes cuando "Mostrar entidad DXCC y estado trabajado antes" está habilitado:
- **Nuevo DXCC** → magenta
- **Nuevo en banda** → coloreado por prioridad
- **Trabajado antes en banda** → gris + tachado
- **Mi indicativo** → rojo (máxima prioridad)
- **CQ** → verde (sin cambios)

#### Visualizador de Modo Asíncrono
Nuevo widget animado que reemplaza la insignia estática verde "FT2":
- **Onda sinusoidal animada** — verde durante RX, roja durante TX
- **Barra S-meter** — muestra dB SNR de la última estación decodificada con gradiente de color (rojo→amarillo→verde)
- **Encabezado "ASINCRONO"** — cambia a "TX" al transmitir
- Ubicado en el panel de control cerca de Bloquear Freq TX / Portadora Dual

#### Menú de Idioma
Soporte multilingüe completo con 10 idiomas seleccionables desde la barra de menú:
- English, Italiano, Español, Català, Dansk, 日本語, Русский, 中文(简体), 中文(繁體), English (UK)
- La preferencia de idioma se guarda de forma persistente
- Seleccione menú Language → elija idioma → reinicie para aplicar

---

### [IT] Italiano

#### Decoder LDPC Min-Sum Normalizzato
Il decoder LDPC(174,91) ora usa l'algoritmo **Min-Sum Normalizzato** al posto del Sum-Product (tanh/atanh). Sostituisce la catena costosa `tanh()` / `product()` / `atanh()` con `sign() * min(|msg|) * alpha` (alpha=0.75):
- **+0.2-0.4 dB** di miglioramento sensibilità sui segnali deboli
- **Calcolo più veloce** — `min()` è più economico di `tanh()/atanh()`
- Isolato nel decoder FT2-specifico (`decode174_91_ft2.f90`) — NON tocca il backend condiviso FT8/FT4/Q65

#### Fix Auto-Sequenza con Conteggio Messaggi QSO
Corretta incongruenza tra le modalità 2/3/5 messaggi e l'auto-sequenza:
- **Protezione `m_sentFirst73`**: ora settato nel percorso re-route (2/3-msg salta TX5) per bloccare messaggi tardivi dal vecchio partner QSO — previene QSO fantasma
- **Iniezione `qsoCooldown`**: inserito manualmente quando TX3 viene saltato (m_QSOProgress non raggiunge mai ROGER_REPORT)

#### Fix Colori nella Band Activity
I messaggi non-CQ (QSO in corso, report, 73) venivano sempre mostrati in grigio. Ora l'evidenziazione DXCC/B4/Grid/Continente viene applicata a TUTTI i messaggi quando "Mostra entità DXCC e stato lavorato prima" è abilitato:
- **Nuovo DXCC** → magenta
- **Nuovo sulla banda** → colorato per priorità
- **Lavorato prima sulla banda** → grigio + barrato
- **Il mio nominativo** → rosso (priorità massima)
- **CQ** → verde (invariato)

#### Visualizzatore Modo Asincrono
Nuovo widget animato che sostituisce il badge verde statico "FT2":
- **Sinusoide animata** — verde durante RX, rossa durante TX
- **Barra S-meter** — mostra i dB SNR dell'ultima stazione decodificata con gradiente colore (rosso→giallo→verde)
- **Intestazione "ASINCRONO"** — cambia in "TX" durante la trasmissione
- Posizionato nel pannello di controllo vicino a Blocca Freq TX / Dual Carrier

#### Menu Lingua
Supporto multilingua completo con 10 lingue selezionabili dalla barra menu:
- English, Italiano, Español, Català, Dansk, 日本語, Русский, 中文(简体), 中文(繁體), English (UK)
- La preferenza lingua viene salvata in modo persistente
- Seleziona menu Language → scegli lingua → riavvia per applicare

---

### [DE] Deutsch

#### Normalisierter Min-Sum LDPC Decoder
Der LDPC(174,91)-Decoder verwendet jetzt den **Normalisierten Min-Sum**-Algorithmus anstelle von Sum-Product (tanh/atanh). Ersetzt die teure `tanh()` / `product()` / `atanh()`-Kette durch `sign() * min(|msg|) * alpha` (alpha=0.75):
- **+0,2-0,4 dB** Empfindlichkeitsverbesserung bei schwachen Signalen
- **Schnellere Berechnung** — `min()` ist günstiger als `tanh()/atanh()`
- Isoliert im FT2-spezifischen Decoder (`decode174_91_ft2.f90`) — berührt NICHT das gemeinsame FT8/FT4/Q65-Backend

#### QSO-Nachrichtenzählung Auto-Sequenz-Fix
Inkonsistenz zwischen 2/3/5-Nachrichtenmodi und Auto-Sequenzierung behoben:
- **`m_sentFirst73`-Schutz**: jetzt im Re-Route-Pfad gesetzt, um verspätete Nachrichten vom alten QSO-Partner zu blockieren
- **`qsoCooldown`-Einspeisung**: manuell eingefügt, wenn TX3 übersprungen wird

#### Korrektur der Farben in der Bandaktivität
Nicht-CQ-Nachrichten (laufende QSOs, Rapporte, 73) wurden immer grau angezeigt. Jetzt wird die DXCC/B4/Grid/Kontinent-Hervorhebung auf ALLE Nachrichten angewendet, wenn "DXCC-Entität und Vorher-gearbeitet-Status anzeigen" aktiviert ist:
- **Neues DXCC** → Magenta
- **Neu auf dem Band** → nach Priorität eingefärbt
- **Vorher auf dem Band gearbeitet** → grau + durchgestrichen
- **Mein Rufzeichen** → rot (höchste Priorität)
- **CQ** → grün (unverändert)

#### Asynchron-Modus-Visualisierer
Neues animiertes Widget ersetzt das statische grüne "FT2"-Abzeichen:
- **Animierte Sinuswelle** — grün während RX, rot während TX
- **S-Meter-Balken** — zeigt dB SNR der zuletzt dekodierten Station mit Farbverlauf (rot→gelb→grün)
- **"ASINCRONO"-Überschrift** — wechselt zu "TX" beim Senden
- Im Bedienfeld in der Nähe von TX-Frequenz halten / Dual Carrier

#### Sprachmenü
Vollständige Mehrsprachunterstützung mit 10 Sprachen, auswählbar über die Menüleiste:
- English, Italiano, Español, Català, Dansk, 日本語, Русский, 中文(简体), 中文(繁體), English (UK)
- Spracheinstellung wird dauerhaft gespeichert
- Menü Language wählen → Sprache auswählen → Neustart zum Anwenden

---

### [TR] Türkçe

#### Normalleştirilmiş Min-Sum LDPC Kod Çözücü
LDPC(174,91) kod çözücü artık Sum-Product (tanh/atanh) yerine **Normalleştirilmiş Min-Sum** algoritmasını kullanıyor. Pahalı `tanh()` / `product()` / `atanh()` zincirini `sign() * min(|msg|) * alpha` (alpha=0.75) ile değiştirir:
- **+0,2-0,4 dB** zayıf sinyallerde hassasiyet iyileştirmesi
- **Daha hızlı hesaplama** — `min()`, `tanh()/atanh()`'den daha ucuzdur
- FT2'ye özel kod çözücüde izole edildi (`decode174_91_ft2.f90`) — paylaşılan FT8/FT4/Q65 arka ucuna dokunmaz

#### QSO Mesaj Sayısı Otomatik Sıralama Düzeltmesi
2/3/5 mesaj modları ile otomatik sıralama arasındaki tutarsızlık düzeltildi:
- **`m_sentFirst73` koruması**: artık yeniden yönlendirme yolunda ayarlanarak eski QSO ortağından gelen geç mesajları engeller
- **`qsoCooldown` enjeksiyonu**: TX3 atlandığında manuel olarak eklenir

#### Bant Aktivitesi Renk Düzeltmesi
CQ olmayan mesajlar (devam eden QSO, raporlar, 73) her zaman gri renkte görüntüleniyordu. Şimdi "DXCC varlığını ve önceden çalışılma durumunu göster" etkinleştirildiğinde DXCC/B4/Grid/Kıta vurgulama TÜM mesajlara uygulanır:
- **Yeni DXCC** → macenta
- **Bantta yeni** → önceliğe göre renklendirilmiş
- **Bantta daha önce çalışılmış** → gri + üstü çizili
- **Benim çağrı işaretim** → kırmızı (en yüksek öncelik)
- **CQ** → yeşil (değişmedi)

#### Asenkron Mod Görselleştirici
Statik yeşil "FT2" rozetinin yerini alan yeni animasyonlu widget:
- **Animasyonlu sinüs dalgası** — RX sırasında yeşil, TX sırasında kırmızı
- **S-metre çubuğu** — son çözülen istasyonun dB SNR'sini renk gradyanıyla gösterir (kırmızı→sarı→yeşil)
- **"ASINCRONO" başlığı** — iletim sırasında "TX" olarak değişir
- TX Frekansını Kilitle / Çift Taşıyıcı yakınında kontrol panelinde bulunur

#### Dil Menüsü
Menü çubuğundan seçilebilen 10 dil ile tam çok dilli destek:
- English, Italiano, Español, Català, Dansk, 日本語, Русский, 中文(简体), 中文(繁體), English (UK)
- Dil tercihi kalıcı olarak kaydedilir
- Language menüsünü seçin → dil seçin → uygulamak için yeniden başlatın

---

## Raptor Engine — Enhanced FT2 Decoder

The heart of Decodium Fast Track 2 is the **Raptor Engine**, an asynchronous FT2 decoder completely redesigned to approach FT8 performance.

### Decoder Innovations

| Innovation | Detail | Gain |
|---|---|---|
| **Scale Factor 3.2** | LLR scaling aligned with FT8 for better LDPC separation | +0.5 dB |
| **RMS Normalization** | `normalizebmet()` on all LLR channels (llra, llrb, llrc) — subtract mean, divide by sigma | +1.0 dB |
| **Turbo Timer 187ms** | 20 decode attempts per period (was 5 at 750ms) | 4x reactivity |
| **5 Metric Passes** | llra + llrb + llrc + best-of + weighted average | +0.5 dB |
| **TX Frequency Hopping** | +/-25 Hz random after CQ to avoid async collisions | -30% collisions |
| **Predictive DT Hints** | Memorizes known station timing for 60s, reduces DT search | +15% decode speed |
| **Sync-Triggered Decode** | 2 phases: fast Costas scan + targeted decode on hits only | -40% CPU |
| **MAXCAND 300** | More weak candidates evaluated (default 200) | +10-15% weak decodes |
| **OSD Depth 4** | More aggressive LDPC (default 3) | +0.3 dB |
| **syncmin 0.82** | Lower sync threshold for weak signals | +5% candidates |
| **Freq range 200-5500 Hz** | +600 Hz useful bandwidth | +12% space |
| **4 subtraction passes** | Extra pass to recover hidden signals | +5-10% decodes |
| **Adaptive Channel Estimation** | MMSE equalization from Costas pilots, SNR-weighted LLR | +0.5-1.5 dB on HF |
| **Normalized Min-Sum LDPC** | sign()*min(|msg|)*alpha replaces tanh/product/atanh | +0.2-0.4 dB |

**Estimated overall gain: +2.5 to +5.0 dB over standard FT2 decoder**

### Adaptive Channel Estimation (MMSE)

New in Build 2603172124 — real-time channel equalization for HF fading channels:

- **`lib/ft2/ft2_channel_est.f90`** — Estimates complex channel gain H(k) from the 16 Costas sync symbols, linearly interpolates across all 103 symbols, applies MMSE equalization, and computes per-symbol SNR
- **`lib/ft2/get_ft2_bitmetrics.f90`** — Integrates equalized metrics: detects fading (>3 dB SNR variation), blends original and equalized bit metrics proportionally to fading depth
- **AWGN static channel** → no modification (fading <3 dB, bypass) — zero cost on clean signals
- **HF selective fading** → MMSE equalization + SNR-weighted LLR → +0.5 to +1.5 dB improvement

### Async FT2 — Real-Time Decoding

- 7.5s ring buffer (90000 samples at 12 kHz)
- 3.75s decode window (45000 samples) — continuous sliding window
- Automatic deduplication (QSet, reset every 10s)
- No "period" concept — continuous decoding like an SDR

### Async TX — Instant Transmission

- **TX bypasses the 3.75s period** — transmits when message is ready
- 300ms guard timer between decode and TX (avoids collisions)
- `m_bAsyncTxArmed` flag forces `m_bTxTime=true` in GUI cycle
- Flow: decode → 300ms → TX 1.28s → RX → decode (~6s per complete QSO)

---

## Speedy Contest + Digital Morse (D-CW)

### Speedy Contest Mode
- Double-click on decode → TX starts in ~20ms (bypass guard timer)
- "Speedy" checkbox visible only in FT2
- Ideal for contests: click = transmit

### Digital Morse (D-CW) Mode
- **Spacebar = TX NOW** — transmit the pre-loaded message when you want
- Double-click prepares the message (LDPC encoding + GFSK) but does NOT transmit
- Operator chooses the right moment → Spacebar → TX in ~20ms
- Combines FT2 coding gain (-21 dB SNR) with operator reflexes
- A new discipline: digital CW at 1.28 seconds

---

## DXpedition 2-Slot Mode

- Automatic management of 2 simultaneous TX slots (independent from Fox/Hound)
- Dedicated auto-sequencer: `dxpedAutoSequence()` routes each decode
- Caller queue sorted by SNR (strongest first)
- QSO in 2 TX periods: RST → RR73+log (like MSHV)
- Piggyback CQ every 4 TX periods
- Automatic B4 filter before enqueue
- Automatic ADIF logging at QSO end

---

## Multi-Mode Support

FT2 as primary mode, but all standard modes available:
FT8, FT4, JT65, JT9, JT4, Q65, MSK144, WSPR, FST4, FST4W, Echo, FreqCal

---

## Other Features

### Auto CQ Caller Queue
- Automatic FIFO queue (max 20 stations) during Auto CQ
- Live display in the right panel with numbered list
- Double-click queues stations in any QSO state
- Automatic processing at the end of current QSO

### Advanced Decoder Sensitivity

| Parameter | Value | Effect |
|---|---|---|
| syncmin | 0.82 | Reduced sync threshold |
| MAXCAND | 300 | +50% candidates |
| nsp | 4 | 4th subtraction pass |
| OSD depth | 4 | Aggressive LDPC |
| SNR floor | -24 dB | Weaker signals |
| Freq range | 200-5500 Hz | +600 Hz bandwidth |
| Freq grid | 2 Hz | Finer sync |

### FT2 Multi-Period Averaging (+4 dB)
- EMA soft averaging of bitmetrics over 2-4 consecutive periods
- Automatic averaged decode when single period fails
- +3-5 dB on weak signals with stable DT

### Optimized Waterfall
- Gain normalized for TR period (compensates 3.75s vs 15s)
- Line reset at 17 pixels for short FT2 period
- Orange multi-slot markers for Fox mode

### Network & Integration
- **PSKReporter:** automatic spotting
- **OmniRig:** auto-launch with 5s COM wait
- **LOTW:** upload/download QSO
- **Cabrillo:** contest logging
- **Auto CTY.DAT:** automatic download if missing or >30 days

### Audio
- Underrun recovery (resume instead of fatal error)
- Notify interval 20ms, buffer 16384 frames
- Predictive soundcard drift compensation

### UI & Display
- "Fast Track 2" logo and branding
- B4 Strikethrough — worked stations shown with strikethrough
- TX Bracket on waterfall — red brackets `[ ]` at TX position
- No B4 Filter — hides worked stations on the band
- Raptor palette (military green theme)
- **Band Activity colors** — DXCC/B4 highlighting on all messages
- **Async Mode Visualizer** — animated sine wave + S-meter

### Auto-Update
- Automatic new version check via GitHub API
- One-click download and install
- Digitally signed installer

---

## Comparison with Standard WSJT-X

| Feature | Decodium FT2 | WSJT-X |
|---|---|---|
| FT2 Decoder | Raptor Engine (+3 dB) | Standard |
| FT2 Async | Sliding window 187ms | Not available |
| Async TX | Instant (bypass period) | Synchronized |
| Speedy Contest | Yes | No |
| Digital Morse (D-CW) | Yes (Spacebar TX) | No |
| DXped 2-Slot | Yes | Fox/Hound |
| Scale Factor | 3.2 (optimized) | 2.83 |
| LLR Normalization | RMS (normalizebmet) | None |
| Decode Timer | 187ms (20/period) | ~750ms (5/period) |
| TX Freq Hopping | +/-25 Hz auto | No |
| DT Hints | Predictive (60s cache) | No |
| MAXCAND | 300 | 200 |
| OSD Depth | 4 | 3 |
| Freq Range | 200-5500 Hz | ~4910 Hz |
| Caller Queue | FIFO 20 stations | Fox only |
| B4 Strikethrough | Yes | No |
| TX Bracket Waterfall | Yes | No |
| Multi-Period Avg | EMA +4 dB | No |
| Auto CTY.DAT | Yes | No |
| Code Signing | SHA256 + timestamp | No |
| **Language Menu** | **10 languages** | **No** |
| **Band Activity Colors** | **All messages** | **CQ only** |
| **Async Visualizer** | **Sine wave + S-meter** | **No** |
| **Channel Estimation** | **MMSE adaptive (Costas pilots)** | **No** |
| **LDPC Algorithm** | **Normalized Min-Sum (alpha=0.75)** | **Sum-Product (tanh/atanh)** |

---

## Building from Source

### Requirements
- MSYS2 MinGW-w64 (GCC 15.x, gfortran)
- Qt 5.15.x / Qt 6.x
- Boost (dynamic linking)
- CMake 3.x

### Build x64
```bash
cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=C:/msys64/mingw64/bin/mingw32-make.exe
cmake --build . --target decodium -- -j4
```

### Build x86
```bash
cd build32
PATH="/c/msys64/mingw32/bin:$PATH"
cmake .. -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=C:/msys64/mingw32/bin/mingw32-make.exe
cmake --build . --target decodium -- -j4
```

### Create Installers
Requires [Inno Setup 6](https://jrsoftware.org/isinfo.php) and Windows SDK (signtool):
```
build_installers.bat
```

---

## Changelog

### Build 2603182218 (2026-03-18)
- **Normalized Min-Sum LDPC**: FT2-specific decoder (`decode174_91_ft2.f90`) replaces Sum-Product with sign()*min(|msg|)*alpha (alpha=0.75) — +0.2-0.4 dB, faster, does NOT touch shared FT8/FT4/Q65 backend
- **QSO message count auto-sequence fix**: m_sentFirst73 protection + qsoCooldown injection in 2/3-msg re-route path — prevents phantom QSOs from late messages

### Build 2603180019 (2026-03-18)
- **Configurable QSO message count** (2/3/5 msg) for FT2
- **MMSE channel estimation** from Costas pilots, SNR-weighted LLR
- **S-meter SNR fix**: feed from jt9 standard decode path

### Build 2603162146 (2026-03-16)
- **Band Activity Colors**: DXCC/B4/Grid/Continent highlighting on non-CQ messages
- **Async Mode Visualizer**: animated sine wave (RX green/TX red) + S-meter dB bar
- **Language Menu**: 10 languages selectable from menu bar, persistent setting
- **Fix**: QSettings language persistence via MultiSettings

### Build 2603161508 (2026-03-16)
- **Fix**: 73 repetition (max 2) + remove callsign filter
- **Fix**: RR73 infinite loop — stop after 3 retries
- **Fix**: UpdateChecker regex

### Build 2603151508 (2026-03-15) — Decodium Fast Track 2
- **Full rebrand**: Decodium 3.0 ASYMX → Decodium Fast Track 2
- **Raptor Engine**: scale factor 3.2, normalizebmet RMS, 5 metric passes
- **Turbo Timer 187ms**: 20 decode/period (4x faster)
- **TX Frequency Hopping**: +/-25 Hz anti-collision async
- **Predictive DT Hints**: 60s station timing cache
- **Sync-Triggered Decode**: 2 phases (Costas scan + targeted decode)
- **Speedy Contest + Digital Morse (D-CW)**: instant and manual TX
- **New SVG logo**: Fast Track 2 branding

### Build 2603080006 (2026-03-08)
- Async TX: bypass 3.75s period, 300ms guard timer
- DT/NTP elimination from TX timing

### Build 2603070006 (2026-03-07)
- Async FT2 decoder (sliding window, ft2_triggered_decode)
- 90000 sample ring buffer, 1.5s timer (later optimized to 187ms)

### Build 2603031040 (2026-03-03)
- Caller Queue in dedicated Tab 2
- Fix FT2 wrong-period nutc
- DXped 2-slot mode

---

## Credits
- **WSJT-X** by Joe Taylor K1JT and the WSJT Development Group
- **WSJT-X 3.0.0** fork by WM8Q (avantol)
- **Decodium Fast Track 2** by IU8LMC

73 de IU8LMC Martino & IZ8XXE Mimmo

# Decodium v3.0 FT2 "Raptor"

Optimized weak-signal FT2 client with enhanced sensitivity, extended frequency range, and real-time NTP/DT feedback.
Based on WSJT-X 3.0.0 RC1 — focused exclusively on FT2 mode.

**Build:** Vers.2603010555 | **Codename:** Raptor | **Author:** IU8LMC | **License:** GPL v3

---

## Downloads

- [**x64 Installer**](https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor/releases/latest) (recommended)
- [**x86 Installer**](https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor/releases/latest) (32-bit systems)

Both installers are digitally signed (SHA256 + DigiCert RFC3161 timestamp).

---

## Features

### Multi-Mode Support
- FT2 as primary mode, forced at startup
- All standard modes available via Mode menu (FT8, FT4, JT65, JT9, JT4, Q65, MSK144, WSPR, FST4, FST4W, Echo, FreqCal)
- Mode-specific quick buttons for FT8, FT4, FT2

### FT2 Multi-Period Averaging (+4dB)
- EMA soft averaging of bitmetrics over 2-4 consecutive periods
- When single-period decode fails, averaged decode is attempted automatically
- Expected gain: **+3-5 dB** on weak signals with stable DT
- Averaging state cleared on frequency change or band switch

### Decoder Sensitivity Boost

| Parameter | Value | Effect |
|-----------|-------|--------|
| syncmin | 0.82 | Lower sync correlation threshold — more weak-signal candidates |
| MAXCAND | 300 | More candidates evaluated (default 200) |
| nsp | 4 | 4th subtraction pass recovers hidden signals (default 3) |
| OSD depth | 4 | More aggressive LDPC decoding (default 3) |
| SNR floor | -24 dB | Reports weaker signals (default -21 dB) |
| Freq range | 200–5500 Hz | +600 Hz useful bandwidth (default ~4910 Hz) |
| Freq grid | 2 Hz | Finer sync search in 1st pass (default 3 Hz) |

- Candidates sorted by sync power (strongest first) for optimal subtraction order
- 4-pass decoding architecture with progressive LDPC/soft-decision + OSD with a priori info
- Expected impact: **+10–25% weak-signal decodes**

### Advanced Time Synchronization

#### TimeSyncPanel (Logger32-style)
- Live UTC clock with sub-millisecond precision (100ms update)
- NTP offset with color coding (Green <20ms, Yellow <100ms, Red >=100ms)
- Soundcard drift monitoring in PPM and ms/period
- DT convergence indicator (LOCKED / Converging / Adjusting)
- Decode latency tracking with color thresholds
- EMA factor display (warm-up / tracking / stable)
- NTP/DT divergence warning system

#### NTP Client (25+ servers)
- NTP Pool Project, NIST, Google, Cloudflare, INRIM Italy (Stratum 1 cesium), PTB Germany, Apple, Microsoft, Meta
- Custom NTP server field (user-configurable, persisted)
- RTT filtering: 50ms for FT2 (configurable, default 100ms)
- IQR outlier removal + median + EMA smoothing
- FT2 mode: **30s refresh** (normal: 60s)
- HTTP fallback when NTP fails

#### DT Feedback Loop
- NTP offset + soundcard drift correction injected into Detector
- High-resolution timer (~1us on Windows vs ~15ms QDateTime)
- FT2-optimized clamp: +/-30ms step, +/-300ms total
- Fast EMA warm-up: convergence in **~2-3 FT2 periods (7-11 seconds)**
- Predictive drift compensation based on measured PPM

### Waterfall Optimized for FT2
- Gain normalized by TR period (compensates FT2 3.75s vs FT8 15s energy difference)
- Line reset at 17 pixels for FT2 short period
- Averaging forced to 1 for maximum responsiveness
- Multi-slot orange dashed markers for Fox mode (200 Hz spacing)

### Fox and Hound
- Multi-slot TX: up to 5 (SuperFox) or 3 (standard Fox)
- SuperFox mode integration with dedicated UI
- Wait & Call for Hound mode
- Multi-slot TX disabled outside Fox mode (safety)

### Decoder Watchdog
- Prevents UI freeze from hung decoders
- Timeout: max(5s, 2x TR period)
- Automatic termination and restart

### Network & Integration
- **PSKReporter:** automatic spot reporting (user-agent: Decodium3FT2-Raptor)
- **OmniRig:** auto-launch with 5s COM wait loop
- **LOTW:** upload/download QSO integration
- **Cabrillo:** contest logging support

### Audio Improvements
- Underrun recovery (resume instead of fatal error)
- Notify interval: 20ms (was 1000ms)
- Default buffer: 16384 frames for Windows
- Predictive soundcard drift compensation

### UI & Display
- Raptor palette (green military theme)
- Customizable color highlighting (CQ, MyCall, DX entity, 73/RR73, Pounce)
- Diagnostic mode for rig control troubleshooting
- About dialog with ft2logo, codename, version, decoder parameters
- **B4 Strikethrough** — stations already worked on band shown with strikethrough text in Band Activity, in addition to background color
- **TX Bracket on Waterfall** — red `[ ]` brackets drawn on waterfall overlay at TX slot position (FT2/FT8/FT4)

### Auto CQ Caller Queue
- Automatic FIFO queue for callers in Auto CQ mode (max 20 stations)
- **Live queue display** in right panel with "Caller Queue (N)" title and numbered station list
- Double-click enqueues stations in **any** Auto CQ state (CALLING, in QSO, SIGNOFF)
- First click during CQ auto-processes immediately; subsequent clicks queue for later
- When in QSO and responses arrive from other stations, they are auto-queued
- On current QSO completion, the next caller in queue is automatically processed
- Callsign, RX frequency and standard messages generated automatically
- Panel restores to "Rx Frequency" when Auto CQ is deactivated

### No B4 Filter
- Checkbox to filter out stations already worked on current band
- Applies to both double-click selection and auto caller queue interception

### Auto-update CTY.DAT
- At startup, if `cty.dat` is missing or older than 30 days, it is automatically downloaded in background
- Download from country-files.com with automatic logbook rescan

---

## Building from Source

### Requirements
- MSYS2 MinGW-w64 (GCC 15.x, gfortran)
- Qt 5.15.x
- Boost (dynamic linking)
- CMake 3.x

### Build x64
```bash
cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=C:/msys64/mingw64/bin/mingw32-make.exe
cmake --build . --target wsjtx -- -j4
```

### Build x86
```bash
cd build32
PATH="/c/msys64/mingw32/bin:$PATH"
cmake .. -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=C:/msys64/mingw32/bin/mingw32-make.exe
cmake --build . --target wsjtx -- -j4
```

### Create Installers
Requires [Inno Setup 6](https://jrsoftware.org/isinfo.php) and Windows SDK (signtool):
```
build_installers.bat
```

---

## Key Differences from Stock WSJT-X

| Feature | Decodium Raptor | Stock WSJT-X |
|---------|----------------|--------------|
| Primary Mode | FT2 default, multi-mode | Multi-mode |
| syncmin | 0.82 | Standard |
| OSD Depth | 4 | Mode-dependent |
| MAXCAND | 300 | Lower |
| Freq Range | 200–5500 Hz | Mode-dependent |
| TimeSyncPanel | Logger32-style | Basic status bar |
| NTP Servers | 25+ with Stratum 1 | Default pool |
| RTT Filtering | Yes (50ms FT2) | No |
| IQR Outlier Removal | Yes | No |
| Soundcard Drift PPM | Real-time | Not available |
| DT Feedback Loop | NTP + drift | Not implemented |
| Decoder Watchdog | Yes | No |
| OmniRig Auto-Launch | Yes | Manual |
| B4 Strikethrough | Yes | No |
| TX Bracket Waterfall | Yes | No |
| Auto CQ Caller Queue | Yes (FIFO, max 20, live display) | Fox/Hound only |
| No B4 Filter | Yes | No |
| FT2 Multi-Period Avg | Yes (+4dB EMA) | No |
| Auto-update CTY.DAT | Yes (30-day check) | Manual only |

---

## Changelog

### Build 2603010555 (2026-03-01) — Latest
- Add Auto CQ Caller Queue live display in right panel with numbered station list
- Fix double-click enqueue: now works during CALLING state (was blocked by `> CALLING` condition)
- Auto-process first queued station immediately when in CALLING state
- Panel restores to "Rx Frequency" when Auto CQ is deactivated
- Update About dialog and program title to build 2603010555

### Build 2603010503 (2026-03-01)
- FT2 multi-period soft averaging (EMA): +3-5 dB gain over 2-4 periods
- Module-level bitmetrics accumulation buffer in ft2_decode.f90
- Averaged decode attempt when single-period fails (navg >= 2)
- Add SignPath Foundation code signing workflow (GitHub Actions)

### Build 2602281900 (2026-02-28)
- Double-click on callsign during active Auto CQ QSO enqueues instead of interrupting
- New "No B4" checkbox filters out stations already worked on current band
- Restore all mode actions (FT8, FT4, JT65, JT9, Q65, MSK144, etc.) in Mode menu
- Translate README feature descriptions to English

### Build 2602281659 (2026-02-28)
- B4 Strikethrough: stations already worked on band shown with strikethrough text
- Auto CQ Caller Queue: FIFO queue (max 20) for callers during active QSO
- TX Bracket Waterfall: red `[ ]` brackets drawn at TX slot position
- Auto CTY.DAT: auto-download cty.dat at startup if missing or older than 30 days

### Build 2602270848 (2026-02-27)
- Restore DT display (Decode Timing panel), keep soundcard drift removed
- Bump build tag for x64/x86 installers

### Build 2602270204 (2026-02-27)
- Remove DT feedback loop (display-only, never applied to Detector)
- Rename wsjtx → decodium across entire project (CMake, config, log, UI, desktop, icons)

### Build 2602261706 (2026-02-26)
- Add ChronoGPS to installer and menu with dedicated icon
- Integrate ChronoGPS panel into TimeSyncPanel as two-column layout (720x580)
- Auto-launch ChronoGPS at startup (persisted setting)

### Build 2602261018 (2026-02-26)
- Re-enable DT feedback for TimeSyncPanel convergence display
- Disable DT feedback correction (display only, no Detector injection)
- Tune FT2 decoder: syncmin 0.90, ndeep/maxosd=3, SNR floor -21 dB
- Replace wsjtx.ico with decodium.ico for proper branding

### Build 2602260045 (2026-02-26)
- Revert aggressive decoder params causing high decode latency
- Restore Detector to exact working build (stock behavior)
- Remove all timing corrections from Detector (NTP/DT/drift = display only)
- Fix DT feedback oscillation: remove predictive correction, reduce EMA factors
- Relax NTP RTT filter (50→100ms) and refresh interval (30→60s)
- FT2-exclusive mode with Raptor branding, ft2logo, Raptor.pal palette
- Build scripts: sign_and_pack, sign_installers, build_installers

### Build 2402261000 (2024-02-26) — Initial Release
- Rebrand WSJT-X to Decodium v3.0 FT2 (IU8LMC)
- Add FT2 digital mode with new Fortran decoder sources
- Add NTP precision client (25+ servers, RTT filtering, IQR outlier removal, EMA)
- Soundcard clock drift detection (PPM + ms/period)
- Audio output underrun recovery, optimized buffer settings
- OmniRig auto-launch with COM server wait loop
- Multi-slot waterfall markers (FT2=200Hz spacing)
- Time Synchronization panel (Logger32-style)
- Custom NTP server field, decoder watchdog timer, PSKReporter fix
- Windows manifest, Inno Setup scripts, CI workflows (Linux, macOS, Windows)

---

## Credits
- **WSJT-X** by Joe Taylor K1JT and the WSJT Development Group
- **WSJT-X 3.0.0** fork by WM8Q (avantol)
- **Decodium v3.0 FT2 Raptor** by IU8LMC

73 de IU8LMC Martino   IZ8XXE Mimmo

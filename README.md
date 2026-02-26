# Decodium v3.0 FT2 "Raptor"

Optimized weak-signal FT2 client with enhanced sensitivity, extended frequency range, and real-time NTP/DT feedback.
Based on WSJT-X 3.0.0 RC1 — focused exclusively on FT2 mode.

**Build:** Vers.2602260045 | **Codename:** Raptor | **Author:** IU8LMC | **License:** GPL v3

---

## Downloads

- [**x64 Installer**](https://github.com/iu8lmc/decodium3-build/releases/latest) (recommended)
- [**x86 Installer**](https://github.com/iu8lmc/decodium3-build/releases/latest) (32-bit systems)

Both installers are digitally signed (SHA256 + DigiCert RFC3161 timestamp).

---

## Features

### FT2-Exclusive Mode
- All non-FT2 modes disabled (FT8, FT4, JT65, JT9, JT4, WSPR, Echo, MSK144, Q65, FST4, FST4W, FreqCal)
- FT2 forced at startup regardless of saved settings
- Clean, simplified interface for FT2 operations

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
| Primary Mode | FT2 exclusive | Multi-mode |
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

---

## Credits
- **WSJT-X** by Joe Taylor K1JT and the WSJT Development Group
- **WSJT-X 3.0.0** fork by WM8Q (avantol)
- **Decodium v3.0 FT2 Raptor** by IU8LMC

73 de IU8LMC Martino   IZ8XXE Mimmo

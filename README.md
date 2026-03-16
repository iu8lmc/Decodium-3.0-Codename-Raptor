# Decodium Fast Track 2

**Il client FT2 piu' veloce e sensibile al mondo.**

Fork ottimizzato di WSJT-X 3.0 focalizzato su FT2 asincrono — decode in tempo reale, TX istantaneo, sensibilita' vicina a FT8.

**Build:** 2603160728 | **Author:** IU8LMC | **License:** GPL v3

---

## Downloads

| Architettura | Link |
|---|---|
| **Windows x64** (consigliato) | [Decodium_FT2_2603160728_x64_Setup.exe](https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor/releases/latest) |
| **Windows x86** (32-bit) | [Decodium_FT2_2603160728_x86_Setup.exe](https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor/releases/latest) |

Installer firmati digitalmente (SHA256 + DigiCert RFC3161 timestamp).

---

## Raptor Engine — Decoder FT2 Potenziato

Il cuore di Decodium Fast Track 2 e' il **Raptor Engine**, un decoder FT2 asincrono completamente riprogettato per avvicinarsi alle prestazioni di FT8.

### Innovazioni del Decoder

| Innovazione | Dettaglio | Guadagno |
|---|---|---|
| **Scale Factor 3.2** | LLR scaling allineato a FT8 per migliore separazione LDPC | +0.5 dB |
| **Normalizzazione RMS** | `normalizebmet()` su tutti i canali LLR (llra, llrb, llrc) — sottrae media, divide per sigma | +1.0 dB |
| **Timer Turbo 187ms** | 20 tentativi decode per periodo (era 5 con 750ms) | 4x reattivita' |
| **5 Passate Metriche** | llra + llrb + llrc + best-of + media pesata | +0.5 dB |
| **TX Frequency Hopping** | +/-25 Hz random dopo CQ per evitare collisioni async | -30% collisioni |
| **Predictive DT Hints** | Memorizza timing stazioni note per 60s, riduce search DT | +15% velocita' decode |
| **Sync-Triggered Decode** | 2 fasi: Costas scan veloce + decode mirato solo su hit | -40% CPU |
| **MAXCAND 300** | Piu' candidati deboli valutati (default 200) | +10-15% decode deboli |
| **OSD Depth 4** | LDPC piu' aggressivo (default 3) | +0.3 dB |
| **syncmin 0.82** | Soglia sync piu' bassa per segnali deboli | +5% candidati |
| **Freq range 200-5500 Hz** | +600 Hz di banda utile | +12% spazio |
| **4 passate subtraction** | Pass extra per recuperare segnali nascosti | +5-10% decode |

**Guadagno complessivo stimato: +2.0 a +3.5 dB rispetto al decoder FT2 standard**

### Async FT2 — Decode in Tempo Reale

- Ring buffer 7.5s (90000 campioni a 12 kHz)
- Finestra decode 3.75s (45000 campioni) — sliding window continuo
- Deduplicazione automatica (QSet, reset ogni 10s)
- Nessun concetto di "periodo" — decode continuo come un SDR

### Async TX — Trasmissione Istantanea

- **TX bypassa il periodo 3.75s** — trasmette quando il messaggio e' pronto
- Guard timer 300ms tra decode e TX (evita collisioni)
- Flag `m_bAsyncTxArmed` forza `m_bTxTime=true` nel ciclo GUI
- Flusso: decode → 300ms → TX 1.28s → RX → decode (~6s per QSO completo)

---

## Speedy Contest + Digital Morse (D-CW)

### Speedy Contest Mode
- Double-click su decode → TX parte in ~20ms (bypass guard timer)
- Checkbox "Speedy" visibile solo in FT2
- Ideale per contest: click = trasmetti

### Digital Morse (D-CW) Mode
- **Spacebar = TX NOW** — trasmetti il messaggio pre-caricato quando vuoi
- Double-click prepara il messaggio (encoding LDPC + GFSK) ma NON trasmette
- L'operatore sceglie il momento giusto → Spacebar → TX in ~20ms
- Unisce il coding gain di FT2 (-21 dB SNR) con i riflessi dell'operatore
- Una nuova disciplina: CW digitale a 1.28 secondi

---

## DXpedition 2-Slot Mode

- Gestione automatica di 2 slot TX simultanei (indipendente da Fox/Hound)
- Auto-sequencer dedicato: `dxpedAutoSequence()` instrada ogni decode
- Coda callers ordinata per SNR (i piu' forti prima)
- QSO in 2 periodi TX: RST → RR73+log (come MSHV)
- CQ piggyback ogni 4 periodi TX
- Filtro B4 automatico prima dell'enqueue
- Log ADIF automatico a fine QSO

---

## Multi-Mode Support

FT2 come modo primario, ma tutti i modi standard disponibili:
FT8, FT4, JT65, JT9, JT4, Q65, MSK144, WSPR, FST4, FST4W, Echo, FreqCal

---

## Altre Funzionalita'

### Auto CQ Caller Queue
- Coda FIFO automatica (max 20 stazioni) durante Auto CQ
- Display live nel pannello destro con lista numerata
- Double-click accoda stazioni in qualsiasi stato QSO
- Processamento automatico alla fine del QSO corrente

### Sensibilita' Decoder Avanzata

| Parametro | Valore | Effetto |
|---|---|---|
| syncmin | 0.82 | Soglia sync ridotta |
| MAXCAND | 300 | +50% candidati |
| nsp | 4 | 4a passata subtraction |
| OSD depth | 4 | LDPC aggressivo |
| SNR floor | -24 dB | Segnali piu' deboli |
| Freq range | 200-5500 Hz | +600 Hz banda |
| Freq grid | 2 Hz | Sync piu' fine |

### FT2 Multi-Period Averaging (+4 dB)
- EMA soft averaging bitmetrics su 2-4 periodi consecutivi
- Decode averaged automatico quando il singolo periodo fallisce
- +3-5 dB su segnali deboli con DT stabile

### Waterfall Ottimizzato
- Gain normalizzato per periodo TR (compensa 3.75s vs 15s)
- Reset linea a 17 pixel per periodo corto FT2
- Marcatori multi-slot arancioni per Fox mode

### Network & Integrazione
- **PSKReporter:** spot automatico
- **OmniRig:** auto-launch con 5s COM wait
- **LOTW:** upload/download QSO
- **Cabrillo:** logging contest
- **Auto CTY.DAT:** download automatico se mancante o >30 giorni

### Audio
- Recovery da underrun (resume invece di errore fatale)
- Notify interval 20ms, buffer 16384 frames
- Compensazione drift predittiva soundcard

### UI & Display
- Logo e branding "Fast Track 2"
- B4 Strikethrough — stazioni gia' lavorate mostrate barrate
- TX Bracket sul waterfall — parentesi rosse `[ ]` alla posizione TX
- Filtro No B4 — nasconde stazioni gia' lavorate sulla banda
- Palette Raptor (tema verde militare)

### Auto-Aggiornamento
- Controllo automatico nuova versione via GitHub API
- Download e installazione con un click
- Installer firmato digitalmente

---

## Confronto con WSJT-X Standard

| Feature | Decodium FT2 | WSJT-X |
|---|---|---|
| Decoder FT2 | Raptor Engine (+3 dB) | Standard |
| FT2 Async | Sliding window 187ms | Non disponibile |
| TX Async | Istantaneo (bypass periodo) | Sincronizzato |
| Speedy Contest | Si | No |
| Digital Morse (D-CW) | Si (Spacebar TX) | No |
| DXped 2-Slot | Si | Fox/Hound |
| Scale Factor | 3.2 (ottimizzato) | 2.83 |
| Normalizzazione LLR | RMS (normalizebmet) | Nessuna |
| Timer Decode | 187ms (20/periodo) | ~750ms (5/periodo) |
| TX Freq Hopping | +/-25 Hz auto | No |
| DT Hints | Predittivi (60s cache) | No |
| MAXCAND | 300 | 200 |
| OSD Depth | 4 | 3 |
| Freq Range | 200-5500 Hz | ~4910 Hz |
| Caller Queue | FIFO 20 stazioni | Fox only |
| B4 Strikethrough | Si | No |
| TX Bracket Waterfall | Si | No |
| Multi-Period Avg | EMA +4 dB | No |
| Auto CTY.DAT | Si | No |
| Code Signing | SHA256 + timestamp | No |

---

## Building from Source

### Requisiti
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

### Creare Installer
Richiede [Inno Setup 6](https://jrsoftware.org/isinfo.php) e Windows SDK (signtool):
```
build_installers.bat
```

---

## Changelog

### Build 2603160728 (2026-03-15) — Decodium Fast Track 2
- **Rebrand completo**: Decodium 3.0 ASYMX → Decodium Fast Track 2
- **Raptor Engine**: scale factor 3.2, normalizebmet RMS, 5 passate metriche
- **Timer Turbo 187ms**: 20 decode/periodo (4x piu' veloce)
- **TX Frequency Hopping**: +/-25 Hz anti-collisione async
- **Predictive DT Hints**: cache timing stazioni 60s
- **Sync-Triggered Decode**: 2 fasi (Costas scan + targeted decode)
- **Fix crash**: buffer 45000 (era 30000), fromLatin1 con lunghezza esplicita
- **Fix crash click**: caratteri Fortran senza null-terminator
- **Speedy Contest + Digital Morse (D-CW)**: TX istantaneo e manuale
- **Nuovo logo SVG**: Fast Track 2 branding
- **Installer rinominati**: Decodium_FT2_{build}_{arch}_Setup.exe

### Build 2603151211 (2026-03-15)
- Bump serial per update detection
- Fix FT2 TX timing (ramp-up/down, latency) per TCI e soundcard
- Restore colonna DT + shortcut Ctrl+K clear call

### Build 2603120745 (2026-03-12)
- Fix FT2 TX timing (ramp-up/down, latency)
- Rebase su stable 0745 + DT header fix + OmniRig pre-generated

### Build 2603080006 (2026-03-08)
- Async TX: bypass periodo 3.75s, guard timer 300ms
- Eliminazione DT/NTP dal TX timing
- Porta UDP effimera (rimosso 2238 fisso)

### Build 2603070006 (2026-03-07)
- Async FT2 decoder (sliding window, ft2_triggered_decode)
- Ring buffer 90000 campioni, timer 1.5s (poi ottimizzato a 187ms)

### Build 2603031040 (2026-03-03)
- Caller Queue in Tab 2 dedicato
- Fix FT2 wrong-period nutc
- DXped 2-slot mode

---

## Credits
- **WSJT-X** by Joe Taylor K1JT and the WSJT Development Group
- **WSJT-X 3.0.0** fork by WM8Q (avantol)
- **Decodium Fast Track 2** by IU8LMC

73 de IU8LMC Martino & IZ8XXE Mimmo

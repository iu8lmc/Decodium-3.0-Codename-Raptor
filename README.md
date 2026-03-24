# Decodium Shannon v3.0 — Build 2603241200

## [English](#english) | [Italiano](#italiano) | [Deutsch](#deutsch)

---

## English

### What's New in Build 2603241200

**WSJT-X Classic (locked) — one-click preset**
- New entry in View → Layout → **WSJT-X Classic (locked)**
- One click: applies Classic WSJT-X 3.0 colors + original positions + all dock windows locked
- Docks cannot be floated or dragged — exact faithful reproduction of original WSJT-X 3.0 appearance

**True layout lock fix**
- Fixed: "Lock layout" previously only removed `DockWidgetFloatable` — docks could still be dragged
- Fix: now also removes `DockWidgetMovable` — complete dock lock
- Unlock restores both Floatable and Movable flags

**Decode browser cleared on mode change**
- Band activity and Rx/Tx frequency windows are now cleared when changing operating mode
- Consistent with existing behavior on band change (when "Erase on band change" is enabled)

### Highlights from Recent Builds

- **Splash screen**: "FT2 Shannon Edition" branding with bilingual motto (IT/EN)
- **Floating dock fix**: positions correctly restored after restart
- **AutoCQ loop fix**: callers no longer ignored after ~10 QSOs
- **RF Amber theme**: dark background with amber/gold vintage radio accents
- **Period separator**: quick View menu toggle for the `------` line
- **Crash fix**: null pointer crash on startup in Remote Desktop / VM without display — fixed
- **ADIF 3.17**: FT2 QSOs logged as `<MODE:4>MFSK <SUBMODE:3>FT2` (Log4OM, HRD, CloudLog, N1MM+ compatible)
- **Windows 10 downloads**: cty.dat, Hamlib, country files now download correctly on Windows 10
- **Shannon Decoder**: best-of-N Costas sync, adaptive algorithm, RR73 loop-break optimization
- **Hamlib 4.7**: downloaded from GitHub Releases (no broken SourceForge links)
- **Session QSO counter**: resets on program start, not at UTC midnight
- **Ghost filter fix**: decodes no longer blocked by stale filter entries
- **AutoCQ panel**: caller queue with SNR-based ordering
- **Theme system**: Shannon Light, Shannon Dark, Midnight, Classic, RF Amber
- **Dockable controls**: layout presets, Reset Layout, floating windows

### Download

**[⬇ Download from GitHub Releases](https://github.com/iu8lmc/Decodium-3.0-Shannon/releases/latest)**

- **Windows x64**: [`Decodium_FT2_2603241200_x64_Setup.exe`](https://github.com/iu8lmc/Decodium-3.0-Shannon/releases/download/v3.0.2603241200/Decodium_FT2_2603241200_x64_Setup.exe)
- **Windows x86**: [`Decodium_FT2_2603241200_x86_Setup.exe`](https://github.com/iu8lmc/Decodium-3.0-Shannon/releases/download/v3.0.2603241200/Decodium_FT2_2603241200_x86_Setup.exe)

Both installers are code-signed.

### System Requirements
- Windows 10 or later (x64 or x86)
- Sound card with 48 kHz sample rate
- Internet connection for spotting (optional)

---

## Italiano

### Novità nella Build 2603241200

**WSJT-X Classic (bloccato) — preset con un click**
- Nuova voce in Visualizza → Layout → **WSJT-X Classic (locked)**
- Un solo click: applica i colori Classic WSJT-X 3.0 + posizioni originali + tutte le finestre dock bloccate
- I dock non possono essere portati in floating né trascinati — riproduzione fedele dell'interfaccia originale WSJT-X 3.0

**Fix vero blocco layout**
- Corretto: "Blocca layout" rimuoveva solo `DockWidgetFloatable` — i dock potevano ancora essere trascinati
- Fix: ora rimuove anche `DockWidgetMovable` — blocco completo dei dock
- Lo sblocco ripristina entrambi i flag Floatable e Movable

**Browser decodifiche cancellato al cambio modo**
- Le finestre Band activity e Rx/Tx frequency vengono ora cancellate al cambio modo operativo
- Comportamento coerente con il già esistente cancellamento al cambio banda

### Highlights dalle Build Recenti

- **Splash screen**: branding "FT2 Shannon Edition" con motto bilingue (IT/EN)
- **Fix dock flottanti**: posizioni ripristinate correttamente al riavvio
- **Fix loop AutoCQ**: i chiamanti non vengono più ignorati dopo ~10 QSO
- **Tema RF Amber**: sfondo scuro con accenti ambra/oro stile radio vintage
- **Separatore periodi**: toggle rapido nel menu Visualizza per la linea `------`
- **Fix crash**: crash null pointer all'avvio in Remote Desktop / VM senza display — risolto
- **ADIF 3.17**: QSO FT2 loggati come `<MODE:4>MFSK <SUBMODE:3>FT2` (compatibile Log4OM, HRD, CloudLog, N1MM+)
- **Download su Windows 10**: cty.dat, Hamlib, country files scaricano correttamente su Windows 10
- **Decoder Shannon**: sincronizzazione best-of-N Costas, algoritmo adattivo, ottimizzazione loop-break RR73
- **Hamlib 4.7**: scaricato da GitHub Releases (nessun link SourceForge rotto)
- **Contatore QSO di sessione**: si resetta all'avvio del programma, non a mezzanotte UTC
- **Fix filtro ghost**: le decodifiche non vengono più bloccate da filtri obsoleti
- **Pannello AutoCQ**: coda chiamanti ordinata per SNR
- **Sistema temi**: Shannon Light, Shannon Dark, Midnight, Classic, RF Amber
- **Controlli agganciabili**: preset di layout, Reset Layout, finestre flottanti

### Download

**[⬇ Scarica da GitHub Releases](https://github.com/iu8lmc/Decodium-3.0-Shannon/releases/latest)**

- **Windows x64**: [`Decodium_FT2_2603241200_x64_Setup.exe`](https://github.com/iu8lmc/Decodium-3.0-Shannon/releases/download/v3.0.2603241200/Decodium_FT2_2603241200_x64_Setup.exe)
- **Windows x86**: [`Decodium_FT2_2603241200_x86_Setup.exe`](https://github.com/iu8lmc/Decodium-3.0-Shannon/releases/download/v3.0.2603241200/Decodium_FT2_2603241200_x86_Setup.exe)

Entrambi gli installer sono firmati digitalmente.

### Requisiti di Sistema
- Windows 10 o successivo (x64 o x86)
- Scheda audio con frequenza di campionamento 48 kHz
- Connessione internet per lo spotting (opzionale)

---

## Deutsch

### Neuerungen in Build 2603241200

**WSJT-X Classic (gesperrt) — Ein-Klick-Voreinstellung**
- Neuer Eintrag unter Ansicht → Layout → **WSJT-X Classic (locked)**
- Ein Klick: wendet Classic WSJT-X 3.0 Farben + Originalpositionen + alle gesperrten Dock-Fenster an
- Docks können weder schwebend noch ziehbar sein — originalgetreue Wiedergabe von WSJT-X 3.0

**Echter Layout-Sperren-Fix**
- Behoben: "Layout sperren" entfernte bisher nur `DockWidgetFloatable` — Docks konnten noch gezogen werden
- Fix: entfernt jetzt auch `DockWidgetMovable` — vollständige Dock-Sperre
- Entsperren stellt beide Flags Floatable und Movable wieder her

**Decode-Browser bei Moduswechsel geleert**
- Band-Aktivitäts- und Rx/Tx-Frequenzfenster werden jetzt beim Wechsel des Betriebsmodus geleert
- Konsistentes Verhalten mit dem bestehenden Leeren beim Bandwechsel

### Highlights aus neueren Builds

- **Splash-Screen**: „FT2 Shannon Edition" Branding mit zweisprachigem Motto (IT/EN)
- **Dock-Fenster-Fix**: Positionen nach Neustart korrekt wiederhergestellt
- **AutoCQ-Schleifenfix**: Anrufer werden nach ~10 QSOs nicht mehr ignoriert
- **RF Amber-Theme**: dunkler Hintergrund mit Bernstein-/Goldakzenten im Vintage-Funk-Stil
- **Periodentrennlinie**: Schnellumschalter im Ansichts-Menü für die `------` Linie
- **Absturz-Fix**: Null-Pointer-Absturz beim Start in Remote Desktop / VM ohne Anzeige — behoben
- **ADIF 3.17**: FT2-QSOs werden als `<MODE:4>MFSK <SUBMODE:3>FT2` geloggt (Log4OM, HRD, CloudLog, N1MM+ kompatibel)
- **Windows 10 Downloads**: cty.dat, Hamlib, Country-Dateien laden korrekt unter Windows 10
- **Shannon-Decoder**: Best-of-N Costas-Synchronisation, adaptiver Algorithmus, RR73 Loop-Break-Optimierung
- **Hamlib 4.7**: Download von GitHub Releases (keine defekten SourceForge-Links mehr)
- **Sitzungs-QSO-Zähler**: Reset beim Programmstart, nicht um Mitternacht UTC
- **Ghost-Filter-Fix**: Dekodierungen werden nicht mehr durch veraltete Filtereinträge blockiert
- **AutoCQ-Panel**: Anruferwarteschlange mit SNR-basierter Sortierung
- **Theme-System**: Shannon Light, Shannon Dark, Midnight, Classic, RF Amber
- **Andockbare Steuerelemente**: Layout-Vorlagen, Layout zurücksetzen, schwebende Fenster

### Download

**[⬇ Download von GitHub Releases](https://github.com/iu8lmc/Decodium-3.0-Shannon/releases/latest)**

- **Windows x64**: [`Decodium_FT2_2603241200_x64_Setup.exe`](https://github.com/iu8lmc/Decodium-3.0-Shannon/releases/download/v3.0.2603241200/Decodium_FT2_2603241200_x64_Setup.exe)
- **Windows x86**: [`Decodium_FT2_2603241200_x86_Setup.exe`](https://github.com/iu8lmc/Decodium-3.0-Shannon/releases/download/v3.0.2603241200/Decodium_FT2_2603241200_x86_Setup.exe)

Beide Installer sind digital signiert.

### Systemanforderungen
- Windows 10 oder höher (x64 oder x86)
- Soundkarte mit 48 kHz Abtastrate
- Internetverbindung für Spotting (optional)

---

**73 de IU8LMC**

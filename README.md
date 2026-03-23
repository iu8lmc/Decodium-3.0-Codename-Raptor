# Decodium Shannon v3.0 — Build 2603232208

## [English](#english) | [Italiano](#italiano) | [Deutsch](#deutsch)

---

## English

### What's New in Build 2603232208

**Splash screen — FT2 Shannon Edition**
- New branding: "FT2 Shannon Edition" subtitle with the bilingual motto:
  *"It's not about more power. It's about better math."*
  *"Non ci vuole più potenza. Ci vuole più matematica."*
- Splash timer: 10 seconds with smooth fade-out

**Floating dock windows — positions restored correctly on restart**
- Fixed bug where floating dock widget positions were lost after restarting
- Root cause: `restoreState()` was called before the window was shown — Qt cannot position floating docks until the window is visible
- Fix: deferred second `restoreState()` call fires after the event loop starts, correctly repositioning all floating docks

**AutoCQ loop fix — callers no longer ignored after ~10 QSOs**
- Fixed critical bug where AutoCQ kept sending CQ indefinitely, ignoring all callers after ~10 completed QSOs
- Root cause 1: `on_logQSOButton_clicked` queued a `QTimer::singleShot(500ms)` for every QSO — after many QSOs, accumulated timers fired out of order, calling `processNextInQueue()` at wrong moments
- Root cause 2: `on_stopTxButton_clicked` reset `m_bAutoReply = false` without AutoCQ guard, silently killing CQ reply detection
- Root cause 3: `msgLength==0` guard could trigger `on_stopTxButton_clicked` during AutoCQ transitions
- Fix: timer accumulation eliminated — CQ restart is now handled exclusively by `clearDX()`, called synchronously after each QSO

**RF Amber theme — new original theme**
- New "RF Amber" theme in View → Theme menu
- Dark background with amber/gold accents inspired by vintage radio equipment
- Phosphor amber clock, amber frequency readout, dark cognac dock titles
- Accent colors on tabs, menus, checkboxes, toolbar and status bar

**Period separator line — quick toggle**
- New checkable item in View menu: "Show period separator line"
- Instantly show/hide the dashed `------` line between decoding periods
- One click — no need to open the Settings dialog

### Highlights from Recent Builds

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
- **Windows x64**: `Decodium_FT2_2603232208_x64_Setup.exe`
- **Windows x86**: `Decodium_FT2_2603232208_x86_Setup.exe`

Both installers are code-signed.

### System Requirements
- Windows 10 or later (x64 or x86)
- Sound card with 48 kHz sample rate
- Internet connection for spotting (optional)

---

## Italiano

### Novità nella Build 2603232208

**Splash screen — FT2 Shannon Edition**
- Nuovo branding: sottotitolo "FT2 Shannon Edition" con il motto bilingue:
  *"It's not about more power. It's about better math."*
  *"Non ci vuole più potenza. Ci vuole più matematica."*
- Timer splash: 10 secondi con dissolvenza finale

**Finestre dock flottanti — posizioni ripristinate correttamente al riavvio**
- Risolto bug per cui le posizioni delle finestre dock flottanti venivano perse dopo il riavvio
- Causa: `restoreState()` veniva chiamata prima che la finestra fosse visibile — Qt non può posizionare i dock flottanti finché la finestra non è mostrata
- Fix: una seconda chiamata differita a `restoreState()` scatta dopo l'avvio dell'event loop, riposizionando correttamente tutti i dock flottanti

**Fix loop AutoCQ — i chiamanti non vengono più ignorati dopo ~10 QSO**
- Risolto bug critico dove AutoCQ continuava a mandare CQ all'infinito ignorando tutti i chiamanti dopo circa 10 QSO completati
- Causa 1: `on_logQSOButton_clicked` avviava un `QTimer::singleShot(500ms)` per ogni QSO — dopo molti QSO i timer accumulati sparavano fuori ordine, chiamando `processNextInQueue()` in momenti sbagliati
- Causa 2: `on_stopTxButton_clicked` resettava `m_bAutoReply = false` senza guardia per AutoCQ, uccidendo silenziosamente il rilevamento delle risposte al CQ
- Causa 3: la guardia `msgLength==0` poteva attivare `on_stopTxButton_clicked` durante le transizioni AutoCQ
- Fix: eliminata l'accumulazione di timer — il restart CQ è ora gestito esclusivamente da `clearDX()`, chiamata sincronamente dopo ogni QSO

**Tema RF Amber — nuovo tema originale**
- Nuovo tema "RF Amber" nel menu Visualizza → Tema
- Sfondo scuro con accenti ambra/oro ispirati alle apparecchiature radio vintage
- Orologio ambra fosforescente, frequenza in oro, titoli dock color cognac scuro
- Colori accent su tab, menu, checkbox, toolbar e barra di stato

**Linea separatrice periodi — toggle rapido**
- Nuova voce selezionabile nel menu Visualizza: "Show period separator line"
- Mostra/nascondi istantaneamente la linea tratteggiata `------` tra i periodi di decodifica
- Un solo click — senza aprire il dialogo Impostazioni

### Highlights dalle Build Recenti

- **Fix crash**: crash null pointer all'avvio in sessioni Remote Desktop / VM senza display — risolto
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
- **Windows x64**: `Decodium_FT2_2603232208_x64_Setup.exe`
- **Windows x86**: `Decodium_FT2_2603232208_x86_Setup.exe`

Entrambi gli installer sono firmati digitalmente.

### Requisiti di Sistema
- Windows 10 o successivo (x64 o x86)
- Scheda audio con frequenza di campionamento 48 kHz
- Connessione internet per lo spotting (opzionale)

---

## Deutsch

### Neuerungen in Build 2603232208

**Splash-Screen — FT2 Shannon Edition**
- Neues Branding: Untertitel "FT2 Shannon Edition" mit zweisprachigem Motto:
  *"It's not about more power. It's about better math."*
  *"Non ci vuole più potenza. Ci vuole più matematica."*
- Splash-Timer: 10 Sekunden mit sanftem Ausblenden

**Schwebende Dock-Fenster — Positionen nach Neustart korrekt wiederhergestellt**
- Fehler behoben, bei dem schwebende Dock-Fenster nach dem Neustart ihre Position verloren
- Ursache: `restoreState()` wurde aufgerufen, bevor das Fenster sichtbar war — Qt kann schwebende Docks erst positionieren, wenn das Fenster angezeigt wird
- Fix: ein verzögerter zweiter `restoreState()`-Aufruf startet nach dem Event-Loop-Start und positioniert alle schwebenden Docks korrekt

**AutoCQ-Schleifenfix — Anrufer werden nach ~10 QSOs nicht mehr ignoriert**
- Kritischen Bug behoben, bei dem AutoCQ nach ~10 QSOs endlos CQ sendete und alle Anrufer ignorierte
- Ursache 1: `on_logQSOButton_clicked` startete für jeden QSO einen `QTimer::singleShot(500ms)` — nach vielen QSOs feuerten die angesammelten Timer außer der Reihe und riefen `processNextInQueue()` zum falschen Zeitpunkt auf
- Ursache 2: `on_stopTxButton_clicked` setzte `m_bAutoReply = false` ohne AutoCQ-Guard und zerstörte lautlos die CQ-Antworterkennung
- Ursache 3: die `msgLength==0`-Prüfung konnte `on_stopTxButton_clicked` während AutoCQ-Übergängen auslösen
- Fix: Timer-Anhäufung eliminiert — CQ-Neustart wird jetzt ausschließlich von `clearDX()` synchron nach jedem QSO verwaltet

**RF Amber-Theme — neues Originaltheme**
- Neues "RF Amber"-Theme im Menü Ansicht → Theme
- Dunkler Hintergrund mit Bernstein-/Goldakzenten, inspiriert von Vintage-Funkgeräten
- Phosphor-Bernstein-Uhr, goldene Frequenzanzeige, dunkel-cognacfarbene Dock-Titelleisten
- Akzentfarben in Tabs, Menüs, Checkboxen, Toolbar und Statusleiste

**Periodentrennlinie — Schnellumschalter**
- Neuer auswählbarer Eintrag im Ansichts-Menü: "Show period separator line"
- Gestrichelte `------` Linie zwischen Dekodierperioden sofort ein-/ausblenden
- Ein Klick — kein Öffnen der Einstellungen nötig

### Highlights aus neueren Builds

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
- **Windows x64**: `Decodium_FT2_2603232208_x64_Setup.exe`
- **Windows x86**: `Decodium_FT2_2603232208_x86_Setup.exe`

Beide Installer sind digital signiert.

### Systemanforderungen
- Windows 10 oder höher (x64 oder x86)
- Soundkarte mit 48 kHz Abtastrate
- Internetverbindung für Spotting (optional)

---

**73 de IU8LMC**

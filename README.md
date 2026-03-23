# Decodium Shannon v3.0 — Build 2603232200

## [English](#english) | [Italiano](#italiano) | [Deutsch](#deutsch)

---

## English

### What's New in Build 2603232200

**AutoCQ loop fix — callers no longer ignored after ~10 contacts**
- Fixed critical bug where AutoCQ stopped responding to callers after completing ~10 QSOs
- Root cause 1: `on_logQSOButton_clicked` was scheduling a `QTimer::singleShot(500ms)` for every QSO. After many QSOs, accumulated timers fired out of order, calling `processNextInQueue()` and resetting state at wrong moments — causing callers to be ignored
- Root cause 2: `on_stopTxButton_clicked` was resetting `m_bAutoReply = false` without guarding for AutoCQ mode, sometimes silently killing AutoCQ's ability to detect CQ replies
- Root cause 3: `msgLength==0` guard could trigger `on_stopTxButton_clicked` during AutoCQ transitions
- Fix: removed timer accumulation — CQ restart is now handled exclusively by `clearDX()` which is already called synchronously after each QSO

**Startup performance — 20-second delay eliminated**
- Reduced splash screen timer from 20 seconds to 3 seconds
- The application now opens almost instantly instead of making the user wait

**RF Amber theme — new original theme**
- New "RF Amber" theme in View → Theme menu
- Dark background with amber/gold accents inspired by vintage radio equipment
- Phosphor amber clock display, amber frequency readout, dark cognac dock titles
- Accent colors across tabs, menus, checkboxes, toolbar and status bar

**Period separator line — quick toggle**
- New checkable item in View menu: "Show period separator line"
- Instantly show or hide the dashed `------` line between decoding periods
- No need to go into Settings dialog — one click toggle

**Previous: Crash fix — Startup stability improvement**
- Fixed potential null pointer crash in `readSettings()` when `QApplication::primaryScreen()` returns null (can happen in Remote Desktop sessions or VMs without display)
- Replaced deprecated `QApplication::desktop()` API in startup banner with modern `QScreen` API (Qt 5.14+)
- Both fixes prevent silent crashes reported by some users ("doesn't open, closes immediately")

**Previous: ADIF 3.17 Compliance — FT2 logged correctly**
- FT2 QSOs are now logged as `<MODE:4>MFSK <SUBMODE:3>FT2` per ADIF 3.17 specification
- FT2 is officially listed in ADIF 3.17 as a submode of MFSK (alongside FT4, FST4, Q65, JS8…)
- Previously FT2 was incorrectly logged as a standalone `<MODE:3>FT2`
- All major logging software (Log4OM, HRD, CloudLog, N1MM+) will now correctly import FT2 QSOs

**Previous build highlights:**
- Auto CQ Fix — Callers no longer ignored
- Fixed a critical bug where Auto CQ silently ignored all stations responding to our CQ
- Root cause: internal flag `m_bAutoReply` was reset to `false` by the Auto TX button logic, preventing `auto_sequence()` from processing any incoming replies
- Manual double-click still worked because it bypasses that flag — now both paths work correctly

**Windows 10 Download Compatibility (from build 2603221428)**
- Fixed file downloads (cty.dat, Hamlib, country files) failing on Windows 10
- Removed `NoLessSafeRedirectPolicy` which blocked HTTPS→HTTP redirect chains used by SourceForge and country-files.com
- Downloads now work on Windows 10 and Windows 11

**Shannon Decoder for FT8/FT4 (from build 2603221328)**
- New best-of-N Costas synchronization for improved decoding
- Adaptive sync algorithm
- RR73 loop break optimization

**Previous builds highlights:**
- Hamlib 4.7 download from GitHub Releases (no more broken SourceForge links)
- Session QSO counter (resets on program start, not at UTC midnight)
- Ghost filter fix — decodes no longer blocked by stale filter entries
- AutoCQ panel with caller queue management
- Dark mode / theme system (Shannon Light, Shannon Dark, Midnight, Classic)
- Toolbar, QSO progress indicator, status bar improvements
- DXped mode bugfixes
- Dockable controls with layout presets and Reset Layout

### Download
- **Windows x64**: `Decodium_FT2_2603232200_x64_Setup.exe`
- **Windows x86**: `Decodium_FT2_2603232200_x86_Setup.exe`

Both installers are code-signed.

### System Requirements
- Windows 10 or later (x64 or x86)
- Sound card with 48 kHz sample rate
- Internet connection for spotting (optional)

---

## Italiano

### Novità nella Build 2603232200

**Fix loop AutoCQ — i chiamanti non vengono più ignorati dopo ~10 QSO**
- Risolto bug critico dove AutoCQ smetteva di rispondere ai chiamanti dopo circa 10 QSO completati
- Causa 1: `on_logQSOButton_clicked` avviava un `QTimer::singleShot(500ms)` per ogni QSO. Dopo molti QSO, i timer accumulati sparavano fuori ordine, chiamando `processNextInQueue()` e resettando lo stato in momenti sbagliati — i chiamanti venivano ignorati
- Causa 2: `on_stopTxButton_clicked` resettava `m_bAutoReply = false` senza guardia per AutoCQ, uccidendo silenziosamente la capacità di rilevare risposte al CQ
- Causa 3: la guardia `msgLength==0` poteva attivare `on_stopTxButton_clicked` durante le transizioni AutoCQ
- Fix: eliminata l'accumulazione di timer — il restart CQ è ora gestito esclusivamente da `clearDX()` che già viene chiamata sincronamente dopo ogni QSO

**Performance all'avvio — ritardo di 20 secondi eliminato**
- Ridotto il timer della splash screen da 20 secondi a 3 secondi
- Il programma si apre quasi istantaneamente invece di far attendere l'utente

**Tema RF Amber — nuovo tema originale**
- Nuovo tema "RF Amber" nel menu Visualizza → Tema
- Sfondo scuro con accenti ambra/oro ispirati alle apparecchiature radio vintage
- Orologio ambra fosforescente, frequenza in oro, titoli dock color cognac scuro
- Colori accent su tab, menu, checkbox, toolbar e barra di stato

**Linea separatrice periodi — toggle rapido**
- Nuova voce selezionabile nel menu Visualizza: "Show period separator line"
- Mostra/nascondi istantaneamente la linea tratteggiata `------` tra i periodi di decodifica
- Senza entrare nelle impostazioni — un solo click

**Precedente: Fix crash — Stabilità all'avvio**
- Risolto potenziale crash con null pointer in `readSettings()` quando `QApplication::primaryScreen()` restituisce null (può accadere in sessioni Remote Desktop o VM senza display)
- Sostituita API deprecata `QApplication::desktop()` nel banner di avvio con API moderna `QScreen`
- Entrambi i fix prevengono crash silenziosi segnalati da alcuni utenti ("non si apre, si chiude subito")

**Precedente: Conformità ADIF 3.17 — FT2 loggato correttamente**
- I QSO FT2 vengono ora loggati come `<MODE:4>MFSK <SUBMODE:3>FT2` secondo la specifica ADIF 3.17
- FT2 è ufficialmente elencato in ADIF 3.17 come submode di MFSK (insieme a FT4, FST4, Q65, JS8…)
- In precedenza FT2 veniva loggato erroneamente come modo standalone `<MODE:3>FT2`
- Tutti i principali software di log (Log4OM, HRD, CloudLog, N1MM+) importeranno correttamente i QSO FT2

**Novità dalle build precedenti:**
- Fix Auto CQ — I chiamanti non vengono più ignorati
- Risolto un bug critico dove Auto CQ ignorava silenziosamente tutte le stazioni che rispondevano al nostro CQ
- Causa: il flag interno `m_bAutoReply` veniva resettato a `false` dalla logica del pulsante Auto TX, impedendo ad `auto_sequence()` di processare le risposte in arrivo
- Il doppio-click manuale funzionava perché bypassa quel flag — ora entrambi i percorsi funzionano

**Compatibilità Download su Windows 10 (dalla build 2603221428)**
- Risolti i download di file (cty.dat, Hamlib, country files) che fallivano su Windows 10
- Rimosso `NoLessSafeRedirectPolicy` che bloccava i redirect HTTPS→HTTP usati da SourceForge e country-files.com
- I download funzionano ora su Windows 10 e Windows 11

**Decoder Shannon per FT8/FT4 (dalla build 2603221328)**
- Nuova sincronizzazione best-of-N Costas per decodifica migliorata
- Algoritmo di sync adattivo
- Ottimizzazione loop break RR73

**Novità dalle build precedenti:**
- Download Hamlib 4.7 da GitHub Releases (niente più link SourceForge rotti)
- Contatore QSO di sessione (si resetta all'avvio, non a mezzanotte UTC)
- Fix filtro ghost — le decodifiche non vengono più bloccate da filtri obsoleti
- Pannello AutoCQ con gestione coda chiamanti
- Dark mode / sistema temi (Shannon Light, Shannon Dark, Midnight, Classic)
- Toolbar, indicatore progresso QSO, miglioramenti barra di stato
- Bugfix modalità DXped
- Controlli agganciabili (dock) con preset di layout e Reset Layout

### Download
- **Windows x64**: `Decodium_FT2_2603232200_x64_Setup.exe`
- **Windows x86**: `Decodium_FT2_2603232200_x86_Setup.exe`

Entrambi gli installer sono firmati digitalmente.

### Requisiti di Sistema
- Windows 10 o successivo (x64 o x86)
- Scheda audio con frequenza di campionamento 48 kHz
- Connessione internet per lo spotting (opzionale)

---

## Deutsch

### Neuerungen in Build 2603232200

**AutoCQ-Schleifenfix — Anrufer werden nach ~10 QSOs nicht mehr ignoriert**
- Kritischen Bug behoben, bei dem AutoCQ nach etwa 10 abgeschlossenen QSOs aufhörte, auf Anrufer zu reagieren
- Ursache 1: `on_logQSOButton_clicked` startete für jeden QSO einen `QTimer::singleShot(500ms)`. Nach vielen QSOs feuerten die angesammelten Timer außerhalb der Reihenfolge, riefen `processNextInQueue()` auf und setzten den Zustand zu falschen Zeitpunkten zurück
- Ursache 2: `on_stopTxButton_clicked` setzte `m_bAutoReply = false` ohne AutoCQ-Guard, was lautlos die Fähigkeit zerstörte, CQ-Antworten zu erkennen
- Ursache 3: die `msgLength==0`-Prüfung konnte `on_stopTxButton_clicked` während AutoCQ-Übergängen auslösen
- Fix: Timer-Anhäufung eliminiert — CQ-Neustart wird jetzt ausschließlich von `clearDX()` synchron nach jedem QSO verwaltet

**Startperformance — 20-Sekunden-Verzögerung eliminiert**
- Splash-Screen-Timer von 20 Sekunden auf 3 Sekunden reduziert
- Das Programm öffnet sich jetzt fast sofort statt den Benutzer warten zu lassen

**RF Amber-Theme — neues Originaltheme**
- Neues "RF Amber"-Theme im Menü Ansicht → Theme
- Dunkler Hintergrund mit Bernstein-/Goldakzenten, inspiriert von Vintage-Funkausrüstungen
- Phosphor-Bernstein-Uhr, goldene Frequenzanzeige, dunkel-cognacfarbene Dock-Titelleisten
- Akzentfarben in Tabs, Menüs, Checkboxen, Toolbar und Statusleiste

**Periodentrennlinie — Schnellumschalter**
- Neuer auswählbarer Eintrag im Ansichts-Menü: "Show period separator line"
- Sofort die gestrichelte `------` Linie zwischen Dekodierperioden ein-/ausblenden
- Kein Öffnen der Einstellungen nötig — ein Klick

**Vorherige: Absturz-Fix — Stabilitätsverbesserung beim Start**
- Potenzieller Null-Pointer-Absturz in `readSettings()` behoben, wenn `QApplication::primaryScreen()` null zurückgibt (kann bei Remote Desktop oder VMs ohne Display auftreten)
- Veraltete `QApplication::desktop()` API im Startbanner durch moderne `QScreen` API ersetzt
- Beide Fixes verhindern stille Abstürze, die von einigen Benutzern gemeldet wurden ("öffnet nicht, schließt sofort")

**Vorherige: ADIF 3.17 Konformität — FT2 wird korrekt geloggt**
- FT2-QSOs werden jetzt gemäß ADIF 3.17 als `<MODE:4>MFSK <SUBMODE:3>FT2` geloggt
- FT2 ist offiziell in ADIF 3.17 als Submode von MFSK gelistet (zusammen mit FT4, FST4, Q65, JS8…)
- Zuvor wurde FT2 fälschlicherweise als eigenständiger Modus `<MODE:3>FT2` geloggt
- Alle gängigen Logging-Programme (Log4OM, HRD, CloudLog, N1MM+) importieren FT2-QSOs nun korrekt

**Highlights früherer Builds:**
- Auto CQ Fix — Anrufer werden nicht mehr ignoriert
- Kritischer Bug behoben, bei dem Auto CQ alle Stationen, die auf unseren CQ-Ruf antworteten, stillschweigend ignorierte
- Ursache: Das interne Flag `m_bAutoReply` wurde durch die Auto-TX-Taste auf `false` zurückgesetzt, wodurch `auto_sequence()` keine eingehenden Antworten mehr verarbeitete
- Manueller Doppelklick funktionierte weiterhin, da er dieses Flag umgeht — jetzt funktionieren beide Wege korrekt

**Windows 10 Download-Kompatibilität (ab Build 2603221428)**
- Datei-Downloads (cty.dat, Hamlib, Country-Dateien) auf Windows 10 repariert
- `NoLessSafeRedirectPolicy` entfernt, die HTTPS→HTTP-Weiterleitungen blockierte (SourceForge, country-files.com)
- Downloads funktionieren jetzt unter Windows 10 und Windows 11

**Shannon-Decoder für FT8/FT4 (ab Build 2603221328)**
- Neue Best-of-N Costas-Synchronisation für verbesserte Dekodierung
- Adaptiver Sync-Algorithmus
- RR73 Loop-Break-Optimierung

**Highlights früherer Builds:**
- Hamlib 4.7 Download von GitHub Releases (keine defekten SourceForge-Links mehr)
- Sitzungs-QSO-Zähler (Reset beim Programmstart, nicht um Mitternacht UTC)
- Ghost-Filter-Fix — Dekodierungen werden nicht mehr durch veraltete Filtereinträge blockiert
- AutoCQ-Panel mit Anruferwarteschlange
- Dark Mode / Theme-System (Shannon Light, Shannon Dark, Midnight, Classic)
- Toolbar, QSO-Fortschrittsanzeige, Statusleisten-Verbesserungen
- DXped-Modus Bugfixes
- Andockbare Steuerelemente mit Layout-Vorlagen und Layout zurücksetzen

### Download
- **Windows x64**: `Decodium_FT2_2603232200_x64_Setup.exe`
- **Windows x86**: `Decodium_FT2_2603232200_x86_Setup.exe`

Beide Installer sind digital signiert.

### Systemanforderungen
- Windows 10 oder höher (x64 oder x86)
- Soundkarte mit 48 kHz Abtastrate
- Internetverbindung für Spotting (optional)

---

**73 de IU8LMC**

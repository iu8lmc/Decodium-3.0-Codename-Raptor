# Decodium Shannon v3.0 — Build 2603230232

## [English](#english) | [Italiano](#italiano) | [Deutsch](#deutsch)

---

## English

### What's New in Build 2603230232

**ADIF 3.17 Compliance — FT2 logged correctly**
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
- **Windows x64**: `Decodium_FT2_2603230232_x64_Setup.exe`
- **Windows x86**: `Decodium_FT2_2603230232_x86_Setup.exe`

Both installers are code-signed.

### System Requirements
- Windows 10 or later (x64 or x86)
- Sound card with 48 kHz sample rate
- Internet connection for spotting (optional)

---

## Italiano

### Novità nella Build 2603230232

**Conformità ADIF 3.17 — FT2 loggato correttamente**
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
- **Windows x64**: `Decodium_FT2_2603230232_x64_Setup.exe`
- **Windows x86**: `Decodium_FT2_2603230232_x86_Setup.exe`

Entrambi gli installer sono firmati digitalmente.

### Requisiti di Sistema
- Windows 10 o successivo (x64 o x86)
- Scheda audio con frequenza di campionamento 48 kHz
- Connessione internet per lo spotting (opzionale)

---

## Deutsch

### Neuerungen in Build 2603230232

**ADIF 3.17 Konformität — FT2 wird korrekt geloggt**
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
- **Windows x64**: `Decodium_FT2_2603230232_x64_Setup.exe`
- **Windows x86**: `Decodium_FT2_2603230232_x86_Setup.exe`

Beide Installer sind digital signiert.

### Systemanforderungen
- Windows 10 oder höher (x64 oder x86)
- Soundkarte mit 48 kHz Abtastrate
- Internetverbindung für Spotting (optional)

---

**73 de IU8LMC**

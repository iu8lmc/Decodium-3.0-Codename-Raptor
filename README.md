# Decodium Shannon v3.0 — Build 2603260100

## [Italiano](#italiano) | [English](#english)

---

<a name="italiano"></a>
# 🇮🇹 Italiano

**Decodium Shannon** è un fork di WSJT-X 3.0 con interfaccia completamente modulare, sistema di temi avanzato, colori personalizzabili e supporto multilingua.

---

## Funzionalità principali

### 🔧 Layout completamente modulare
Ogni pannello — Waterfall, Band Activity, Rx Frequency, Bande, Controlli, QSO — si può spostare, affiancare, raggruppare in tab o staccare come finestra indipendente. Nessuna gerarchia fissa, libertà totale.

**View → Layout** offre 8 preset pronti:

| Preset | Descrizione |
|--------|-------------|
| Classic — WSJT-X style | Waterfall in alto, decode al centro, controlli in basso |
| Wide — decodes side by side | Decode affiancati orizzontalmente |
| Stacked — all vertical | Tutti i pannelli in colonna verticale |
| Operator — waterfall + controls top | Waterfall e controlli in alto, decode in basso |
| Compact — minimal footprint | Tutto in tab, footprint minimo |
| DXpedition — dual monitor | Band Activity grande, resto a destra |
| FT2 Operator — all visible | Tutti i pannelli contemporaneamente visibili |
| **WSJT-X Classic (locked)** | Look Windows nativo, colori originali WSJT-X 3.0, tutto bloccato |

### 💾 Salva, carica e blocca i layout
- **View → Save Layout…** — salva il layout corrente con un nome
- **View → Load Saved Layout** — ricarica in un click
- **View → Lock layout** — blocca tutti i pannelli, nessuno si sposta per errore

### 🎨 Sistema temi — 6 temi + colori personalizzabili
**View → Theme** per scegliere tra:
- Shannon Light / Shannon Dark / Midnight / Classic (WSJT-X) / RF Amber / **Custom**

**View → Theme → Customize Colors…** apre il personalizzatore con 2 tab:

**Tab "Interface" — 28 slot colore:**
Sfondo finestra, dock title bar, pannelli decode, orologio UTC, frequenza dial, pulsanti (normale/hover/attivo), menu, status bar, schede, input, separatori dock.

**Tab "Decode Text" — 16 tipi di highlight:**
CQ, MyCall, Tx, DXCC, DXCCBand, Grid, GridBand, Call, CallBand, Continent, ContinentBand, CQZone, CQZoneBand, ITUZone, ITUZoneBand, LoTW.
Per ogni tipo: sfondo + testo, reset singolo, anteprima live.

### 📤 Esporta layout (.dlay) — condivisione community
**View → Export Layout (.dlay)…**
Crea un file JSON portabile con: layout completo + colori personalizzati + callsign autore + descrizione + data.

### 📥 Importa layout da altri radioamatori
**View → Import Layout (.dlay)…**
Anteprima con nome, autore, data e descrizione prima di applicare. Scelta separata se applicare i colori inclusi.

### 🌍 Interfaccia in 12 lingue
Italiano · English · Deutsch · Español · Català · Dansk · Magyar · 日本語 · Русский · 中文(简体) · 中文(繁體) · English (GB)

### 📊 Contatore QSO di sessione
Status bar: `QSO:n | Up:m` — conta dall'avvio del programma, nessun reset a mezzanotte UTC.

### 🚀 Avvio con layout default
Se `decodium_original.dlay` è presente nella cartella dell'applicazione, al primo avvio viene caricato automaticamente (layout + tema + colori).

---

## Fix recenti (build 2603252200 → 2603260100)

| Build | Fix |
|-------|-----|
| 2603252200 | Tab "Testo Decode" nel personalizzatore colori — 16 tipi di highlight modificabili |
| 2603252330 | Export: colori nel `.dlay` solo se tema Custom · Import: tema base applicato prima dei colori · Dialog colori: parte da valori chiari se tema chiaro attivo |
| 2603252359 | i18n completo: tutti i testi estratti da `.ui` + `.cpp`, EN e IT a 0 stringhe non tradotte, 12 lingue aggiornate |
| 2603260100 | i18n UI: incluse 1002 stringhe da `mainwindow.ui` / `Configuration.ui` · carica `.dlay` default al primo avvio · fix coerenza colori al cambio tema |

---

## Download

| Architettura | File |
|-------------|------|
| Windows x64 | `Decodium_FT2_2603260100_x64_Setup.exe` |
| Windows x86 | `Decodium_FT2_2603260100_x86_Setup.exe` |

📖 Guida completa: [`LAYOUT_GUIDE.md`](LAYOUT_GUIDE.md)

---

73 de IU8LMC

---
---

<a name="english"></a>
# 🇬🇧 English

**Decodium Shannon** is a fork of WSJT-X 3.0 with a fully modular interface, advanced theme system, customizable colors and multilingual support.

---

## Main Features

### 🔧 Fully modular layout
Every panel — Waterfall, Band Activity, Rx Frequency, Bands, Controls, QSO — can be moved, split, grouped into tabs, or detached as an independent floating window. No fixed hierarchy, total freedom.

**View → Layout** offers 8 ready-made presets:

| Preset | Description |
|--------|-------------|
| Classic — WSJT-X style | Waterfall top, decodes center, controls bottom |
| Wide — decodes side by side | Decodes arranged horizontally side by side |
| Stacked — all vertical | All panels in a vertical column |
| Operator — waterfall + controls top | Waterfall and controls on top, decodes below |
| Compact — minimal footprint | Everything in tabs, minimal screen use |
| DXpedition — dual monitor | Large Band Activity left, rest on the right |
| FT2 Operator — all visible | All panels visible simultaneously |
| **WSJT-X Classic (locked)** | Native Windows look, original WSJT-X 3.0 colors, all panels locked |

### 💾 Save, load and lock layouts
- **View → Save Layout…** — save the current layout with a name
- **View → Load Saved Layout** — restore with one click
- **View → Lock layout** — locks all panels so nothing moves accidentally

### 🎨 Theme system — 6 themes + customizable colors
**View → Theme** to choose from:
- Shannon Light / Shannon Dark / Midnight / Classic (WSJT-X) / RF Amber / **Custom**

**View → Theme → Customize Colors…** opens the customizer with 2 tabs:

**"Interface" tab — 28 color slots:**
Window background, dock title bar, decode panels, UTC clock, dial frequency, buttons (normal/hover/active), menus, status bar, tabs, input fields, dock separators.

**"Decode Text" tab — 16 highlight types:**
CQ, MyCall, Tx, DXCC, DXCCBand, Grid, GridBand, Call, CallBand, Continent, ContinentBand, CQZone, CQZoneBand, ITUZone, ITUZoneBand, LoTW.
Per type: background + foreground, individual reset, live preview.

### 📤 Export layout (.dlay) — community sharing
**View → Export Layout (.dlay)…**
Creates a portable JSON file with: full layout + custom colors + author callsign + description + creation date.

### 📥 Import layouts from other operators
**View → Import Layout (.dlay)…**
Preview showing name, author, date and description before applying. Separate choice to apply included colors.

### 🌍 Interface in 12 languages
Italiano · English · Deutsch · Español · Català · Dansk · Magyar · 日本語 · Русский · 中文(简体) · 中文(繁體) · English (GB)

### 📊 Session QSO counter
Status bar: `QSO:n | Up:m` — counts from program start, no reset at UTC midnight.

### 🚀 Default layout on first run
If `decodium_original.dlay` is present in the application folder, it is loaded automatically on first run (layout + theme + colors).

---

## Recent fixes (builds 2603252200 → 2603260100)

| Build | Fix |
|-------|-----|
| 2603252200 | "Decode Text" tab in color customizer — 16 highlight types editable |
| 2603252330 | Export: colors in `.dlay` only when Custom theme active · Import: base theme applied before asking about colors · Color dialog: starts with light defaults when light theme is active |
| 2603252359 | Full i18n: all texts extracted from `.ui` + `.cpp`, EN and IT at 0 untranslated strings, 12 languages updated |
| 2603260100 | i18n UI: 1002 strings from `mainwindow.ui` / `Configuration.ui` included · auto-load default `.dlay` on first run · fix color coherence when switching themes |

---

## Download

| Architecture | File |
|-------------|------|
| Windows x64 | `Decodium_FT2_2603260100_x64_Setup.exe` |
| Windows x86 | `Decodium_FT2_2603260100_x86_Setup.exe` |

📖 Full guide: [`LAYOUT_GUIDE.md`](LAYOUT_GUIDE.md)

---

73 de IU8LMC

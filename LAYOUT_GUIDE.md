# Decodium Shannon — Guida Layout e Temi Personalizzati

> Versione applicabile: build **2603242300** e successive

---

## Indice

1. [Layout modulare — panoramica](#1-layout-modulare--panoramica)
2. [Spostare i pannelli](#2-spostare-i-pannelli)
3. [Preset di layout](#3-preset-di-layout)
4. [Salvare un layout](#4-salvare-un-layout)
5. [Esportare un layout (.dlay)](#5-esportare-un-layout-dlay)
6. [Importare un layout da altri operatori](#6-importare-un-layout-da-altri-operatori)
7. [Personalizzare i colori](#7-personalizzare-i-colori)
8. [Formato file .dlay](#8-formato-file-dlay)
9. [Condividere layout in community](#9-condividere-layout-in-community)
10. [Tema WSJT-X Classic](#10-tema-wsjt-x-classic)

---

## 1. Layout modulare — panoramica

Decodium Shannon ha un'interfaccia **completamente modulare**: ogni pannello è un dock window indipendente che può essere:

- **Trascinato** in qualsiasi posizione della finestra (in alto, in basso, a sinistra, a destra)
- **Affiancato** ad altri pannelli con split orizzontale o verticale
- **Raggruppato in tab** con altri pannelli (trascina un pannello sopra un altro)
- **Staccato** in finestra flottante indipendente
- **Riagganciato** in qualsiasi momento

### Pannelli disponibili

| Pannello | Contenuto |
|----------|-----------|
| **Band Activity** | Decode del periodo corrente (pannello sinistro) |
| **Rx Frequency** | Decode sulla frequenza RX selezionata (pannello destro) |
| **Waterfall** | Spettrogramma / waterfall |
| **Bands** | 26 pulsanti selezione banda (HF + VHF/UHF) |
| **Controls** | Monitor, Decode, AutoCQ, Tx Enable, Log QSO, Tune… |
| **QSO** | Freq TX/RX, DX Call/Grid, messaggi TX 1-6, signal meter |
| **Cluster** | DX Cluster spots |
| **Active Stations** | Stazioni attive |

Tutti i pannelli sono sullo stesso livello — non ci sono gerarchie o container fissi. Un pannello **Bands** può stare accanto al Waterfall tanto quanto accanto ai decode.

---

## 2. Spostare i pannelli

### Trascinamento
Clicca e tieni premuto sulla **barra del titolo** del pannello, poi trascinalo:
- **Verso il bordo** della finestra → ancora nel dock area (top/bottom/left/right)
- **Sopra un altro pannello** → crea un gruppo a tab
- **Nel centro della finestra** → pannello flottante indipendente

### Affiancamento con split
Trascina un pannello sul **bordo** di un pannello esistente (non al centro):
- Bordo sinistro/destro → split orizzontale
- Bordo superiore/inferiore → split verticale

### Ritorno al dock
Fai doppio clic sulla barra del titolo di un pannello flottante per riancorarlo nell'ultima posizione.

### Lock layout
**Visualizza → Lock layout** blocca tutti i pannelli: nessuno può essere mosso o staccato. Utile durante la sessione operativa per evitare spostamenti accidentali.

---

## 3. Preset di layout

**Visualizza → Layout** offre preset predefiniti:

| Preset | Descrizione |
|--------|-------------|
| Classic — WSJT-X style | Waterfall in alto, decode sinistra/destra, controlli in basso |
| Wide — decodes side by side | Decode affiancati orizzontalmente, waterfall in basso |
| Stacked — all vertical | Tutti i pannelli in colonna verticale |
| Operator — waterfall + controls top | Waterfall e controlli in alto, decode in basso |
| Compact — minimal footprint | Waterfall in alto, tutto il resto in tab in basso |
| DXpedition — dual monitor | Band Activity grande a sinistra, resto a destra |
| FT2 Operator — all visible | Tutti i pannelli visibili contemporaneamente |
| **WSJT-X Classic (locked)** | Layout + colori originali WSJT-X 3.0, tutto bloccato |
| Reset to Default | Ripristina il layout Classic |

---

## 4. Salvare un layout

**Visualizza → Save Layout…**

1. Appare un dialogo con il campo nome
2. Inserisci un nome descrittivo (es. `FT2 DXpedition 2 monitor`)
3. Clicca OK

Il layout viene salvato localmente e compare nel menu **Visualizza → Carica Layout Salvato**.

### Caricare un layout salvato
**Visualizza → Carica Layout Salvato → [nome]**

Il layout viene ripristinato immediatamente, incluse le dimensioni e posizioni di tutti i pannelli.

### Eliminare un layout salvato
**Visualizza → Carica Layout Salvato → Elimina… → [nome]**

---

## 5. Esportare un layout (.dlay)

Il formato `.dlay` permette di esportare il tuo layout — inclusi colori personalizzati — come file da condividere con altri operatori.

**Visualizza → Esporta Layout (.dlay)…**

1. Inserisci il **nome del layout** (es. `FT2 Wide Screen Amber`)
2. Inserisci una **descrizione** opzionale (es. `Ottimizzato per schermo 27" in DXpedition`)
3. Scegli dove salvare il file `.dlay`
4. Il file viene salvato con tutti i dati necessari

### Cosa viene esportato

```
Layout .dlay
├── Metadati
│   ├── Nome del layout
│   ├── Callsign autore (dal campo "My Call" della configurazione)
│   ├── Descrizione
│   └── Data/ora di creazione (UTC)
├── Posizione e dimensioni di tutti i pannelli
├── Dimensioni della finestra principale
├── Tema (numero tema Shannon/Classic/ecc.)
└── Colori personalizzati (se tema "Personalizzato" attivo)
    ├── Sfondo, testo di ogni elemento
    ├── Orologio, frequenza, decode panel
    ├── Pulsanti, menu, status bar, schede, input
    └── Separatori dock
```

---

## 6. Importare un layout da altri operatori

**Visualizza → Importa Layout (.dlay)…**

1. Seleziona il file `.dlay` ricevuto
2. Decodium mostra un'**anteprima** con:
   - Nome del layout
   - Callsign dell'autore
   - Data di creazione
   - Descrizione
3. Clicca **Sì** per applicare il layout
4. Se il file contiene colori personalizzati, un secondo dialogo chiede:
   > *"Il layout include anche colori personalizzati. Applicarli?"*
5. Il layout viene applicato immediatamente e salvato nei layout locali

Il layout importato è disponibile in **Visualizza → Carica Layout Salvato** per riutilizzarlo in futuro.

---

## 7. Personalizzare i colori

**Visualizza → Theme → Personalizza Colori…**

Si apre un pannello con **28 slot colore** organizzati per sezione dell'interfaccia.

### Sezioni personalizzabili

| Sezione | Slot colore |
|---------|-------------|
| Finestra principale | Sfondo, Testo |
| Dock — barra titolo | Sfondo, Testo |
| Pannelli Decode | Sfondo, Testo |
| Orologio UTC | Sfondo, Testo |
| Frequenza Dial | Sfondo, Testo |
| Pulsanti normali | Sfondo, Testo, Hover |
| Pulsanti attivi | Sfondo, Testo |
| Menu | Sfondo, Testo, Selezionato (sfondo+testo) |
| Status bar | Sfondo, Testo |
| Schede Tab | Normale (sfondo+testo), Attiva (sfondo+testo) |
| Campi input | Sfondo, Testo |
| Separatori dock | Colore hover |

### Come modificare un colore

1. Clicca sul **rettangolo colorato** (swatch) accanto all'elemento
2. Si apre il selezionatore colore nativo di Windows
3. Scegli il nuovo colore → OK
4. Clicca **Apply** per vedere l'anteprima live senza chiudere il dialogo
5. Clicca **OK** per salvare

### Reset di un singolo colore
Clicca il pulsante **↺** accanto allo swatch per ripristinare il valore di default.

### Salvataggio
I colori vengono salvati automaticamente in memoria e ripristinati ad ogni avvio. Non è necessario esportare per mantenerli — l'export serve solo per la condivisione.

### Tema attivo
Quando si personalizzano i colori, il tema passa automaticamente a **"Personalizzato"** (Visualizza → Theme → Personalizzato).

---

## 8. Formato file .dlay

Il file `.dlay` è un file **JSON in chiaro**, leggibile con qualsiasi editor di testo.

### Struttura completa

```json
{
  "format": "DecodiumLayout",
  "version": 1,
  "name": "FT2 DXpedition Wide Screen",
  "author": "IU8LMC",
  "description": "Waterfall in alto, decode affiancati, QSO a destra. Ottimizzato per 27\".",
  "created": "2026-03-24T22:00:00Z",
  "app_version": "3.0",
  "theme": 5,
  "state": "AAAA...base64...",
  "geometry": "AAAA...base64...",
  "colors": {
    "win_bg": "#1a1a2e",
    "win_fg": "#e0e0e0",
    "dock_title_bg": "#16213e",
    "dock_title_fg": "#00d4ff",
    "decode_bg": "#0d0d1a",
    "decode_fg": "#ffffff",
    "clock_bg": "#000000",
    "clock_fg": "#00ff88",
    "freq_bg": "#000000",
    "freq_fg": "#00d4ff",
    "btn_bg": "#1e2a3a",
    "btn_fg": "#c0d8f0",
    "btn_hover_bg": "#2a3f55",
    "btn_on_bg": "#0056a0",
    "btn_on_fg": "#ffffff",
    "menu_bg": "#12192a",
    "menu_fg": "#c0d0e0",
    "menu_sel_bg": "#0078d4",
    "menu_sel_fg": "#ffffff",
    "status_bg": "#0d1520",
    "status_fg": "#80a0c0",
    "tab_bg": "#1a2535",
    "tab_fg": "#8090a0",
    "tab_sel_bg": "#1e3050",
    "tab_sel_fg": "#e0f0ff",
    "input_bg": "#1a2535",
    "input_fg": "#c0d8f0",
    "separator": "#2a4060"
  }
}
```

### Campi principali

| Campo | Tipo | Descrizione |
|-------|------|-------------|
| `format` | string | Sempre `"DecodiumLayout"` — identifica il tipo di file |
| `version` | int | Versione formato (attuale: `1`) |
| `name` | string | Nome del layout |
| `author` | string | Callsign dell'autore |
| `description` | string | Descrizione opzionale |
| `created` | string | Data/ora UTC ISO 8601 |
| `theme` | int | Tema numerico (0=Shannon Light, 1=Dark, 2=Midnight, 3=Classic, 4=Amber, 5=Custom) |
| `state` | string | Posizione pannelli (base64, opaco Qt) |
| `geometry` | string | Dimensioni finestra (base64, opaco Qt) |
| `colors` | object | Colori personalizzati (presente solo se tema Custom o se l'utente li ha definiti) |

### Chiavi dei colori

| Chiave | Elemento |
|--------|----------|
| `win_bg` / `win_fg` | Sfondo e testo finestra principale |
| `dock_title_bg` / `dock_title_fg` | Barra titolo dei dock |
| `decode_bg` / `decode_fg` | Pannelli Band Activity e Rx Frequency |
| `clock_bg` / `clock_fg` | Display orologio UTC |
| `freq_bg` / `freq_fg` | Display frequenza dial |
| `btn_bg` / `btn_fg` | Pulsanti stato normale |
| `btn_hover_bg` | Pulsanti in hover |
| `btn_on_bg` / `btn_on_fg` | Pulsanti attivi (checked) |
| `menu_bg` / `menu_fg` | Barra e voci menu |
| `menu_sel_bg` / `menu_sel_fg` | Voce menu selezionata |
| `status_bg` / `status_fg` | Barra di stato |
| `tab_bg` / `tab_fg` | Schede tab (non selezionate) |
| `tab_sel_bg` / `tab_sel_fg` | Scheda tab attiva |
| `input_bg` / `input_fg` | Campi di testo, spinbox, combo |
| `separator` | Colore hover dei separatori dock |

---

## 9. Condividere layout in community

Il sistema `.dlay` è pensato per la condivisione tra radioamatori. Ecco come contribuire e raccogliere layout dalla community.

### Come condividere il tuo layout

1. Configura il layout che preferisci (posizioni + colori)
2. **Visualizza → Esporta Layout (.dlay)…**
3. Inserisci un nome descrittivo e la descrizione (menzione il tipo di schermo, DXpedition, contest, ecc.)
4. Pubblica il file `.dlay` su:
   - Forum radioamatoriali (QRZ.com, eHam, contestUniversity, Reparto DX)
   - Gruppi Facebook / Telegram
   - GitHub (issues o discussions del progetto Decodium)
   - Email a operatori amici

### Come usare un layout ricevuto

1. Ricevi o scarica il file `.dlay`
2. **Visualizza → Importa Layout (.dlay)…**
3. Controlla nome, autore e descrizione nell'anteprima
4. Clicca Sì — il layout si applica immediatamente

### Suggerimenti per un buon layout da condividere

- **Nome descrittivo**: es. `Contest 80m Single Band`, `DXpedition FT2 Dual Monitor`, `QRP Portable Small Screen`
- **Descrizione completa**: indica la risoluzione schermo ottimale, modalità operativa, eventuali note
- **Includi i colori**: se hai un tema personalizzato interessante, esportalo con il layout
- **Callsign corretto**: il tuo nominativo appare come autore nel dialogo di importazione

### Esempio di file da condividere su forum

```
Allego il mio layout per FT2 DXpedition su schermo 1920x1080.
Waterfall in alto, decode affiancati, QSO a destra, Bands in basso.
Tema scuro personalizzato con testo cyan sull'orologio.

[allegato: FT2_DXped_IU8LMC.dlay]
```

---

## 10. Tema WSJT-X Classic

Per chi vuole l'esperienza fedele a WSJT-X 3.0 originale:

**Visualizza → Layout → WSJT-X Classic (locked)**

Questo preset in un solo clic:

1. **Applica il tema Classic** — stile Qt di sistema Windows nativo, zero CSS custom:
   - Pulsanti e menu con l'aspetto predefinito Windows
   - Orologio: sfondo nero, testo giallo, font MS Shell Dlg 2 16pt (identico WSJT-X)
   - Frequenza: identica all'orologio
   - Nessun colore personalizzato

2. **Dispone i pannelli** come WSJT-X originale:
   - Waterfall in alto
   - Band Activity (sinistra) e Rx Frequency (destra) al centro
   - Bands + Controls in basso affiancati
   - QSO Controls sotto Controls

3. **Blocca tutti i dock**:
   - Nessun pannello può essere mosso o staccato
   - L'interfaccia è statica come in WSJT-X originale

Per sbloccare i dock dopo aver applicato il preset: **Visualizza → Lock layout** (deseleziona).

---

## Riferimenti rapidi

| Azione | Menu |
|--------|------|
| Spostare pannelli | Trascina dalla barra titolo |
| Raggruppare pannelli | Trascina un pannello sopra un altro |
| Bloccare tutto | Visualizza → Lock layout |
| Preset layout | Visualizza → Layout → [nome preset] |
| Salvare layout | Visualizza → Save Layout… |
| Caricare layout salvato | Visualizza → Carica Layout Salvato |
| Esportare per community | Visualizza → Esporta Layout (.dlay)… |
| Importare da altri | Visualizza → Importa Layout (.dlay)… |
| Personalizzare colori | Visualizza → Theme → Personalizza Colori… |
| WSJT-X originale | Visualizza → Layout → WSJT-X Classic (locked) |

---

*Decodium Shannon v3.0 — IU8LMC*

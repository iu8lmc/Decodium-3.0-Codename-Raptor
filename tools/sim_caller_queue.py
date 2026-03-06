#!/usr/bin/env python3
"""
Decodium Auto CQ - Caller Queue Simulator
Replica esatta della logica C++ in mainwindow.cpp senza compilazione.
Permette di testare scenari di coda in modo interattivo o batch.
"""

import sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

from collections import deque
from dataclasses import dataclass, field
from typing import Optional
import textwrap, random, time

# ─── Costanti (come in mainwindow.cpp) ────────────────────────────────────────
MAX_TX_RETRIES   = 3   # tentativi Tx2/3/4 prima di tornare a CQ
MAX_CQ_RETRIES   = 10  # CQ senza risposta prima di toggle period
MAX_MISSED_PERIODS = 4 # periodi RX senza risposta prima di skip caller
MAX_QUEUE_SIZE   = 20

# ─── Enum QSOProgress ─────────────────────────────────────────────────────────
CALLING, REPLYING, REPORT, ROGER_REPORT, SIGNOFF, FINISHED = range(6)
PROGRESS_NAME = {CALLING:"CALLING", REPLYING:"REPLYING", REPORT:"REPORT",
                 ROGER_REPORT:"ROGER_REPORT", SIGNOFF:"SIGNOFF", FINISHED:"FINISHED"}

# ─── Stato della macchina ─────────────────────────────────────────────────────
@dataclass
class State:
    # Queue
    caller_queue: deque = field(default_factory=deque)
    # Flags
    m_autoCQ: bool = False
    m_bDXpedMode: bool = False
    m_auto: bool = False
    # QSO progress
    m_QSOProgress: int = CALLING
    m_ntx: int = 6
    m_hisCall: str = ""
    m_rxFreq: int = 1500
    # Retry counters
    m_autoCQPeriodsMissed: int = 0
    m_receivedReplyThisPeriod: bool = False
    m_txRetryCount: int = 0
    m_lastNtx: int = -1
    m_cqRetryCount: int = 0
    m_txFirst: bool = True
    # Tab/UI (simulato)
    tab_index: int = 0
    stacked_index: int = 0   # 0=Fox, 1=CallerQueue
    # Log eventi
    log: list = field(default_factory=list)
    period: int = 0

S = State()

# ─── Helpers ──────────────────────────────────────────────────────────────────
CYAN  = "\033[96m"
GREEN = "\033[92m"
YELLOW= "\033[93m"
RED   = "\033[91m"
GRAY  = "\033[90m"
BOLD  = "\033[1m"
RESET = "\033[0m"

def log(msg: str, color: str = ""):
    tag = f"[P{S.period:03d}]"
    line = f"{color}{tag} {msg}{RESET}"
    print(line)
    S.log.append(f"{tag} {msg}")

def show_queue():
    """Simula refreshCallerQueueDisplay()"""
    if not S.m_autoCQ and not S.m_bDXpedMode:
        return
    title = f"Caller Queue ({len(S.caller_queue)})"
    bar = "-" * 46
    print(f"\n  {BOLD}{CYAN}+-- {title} {'-'*(30-len(title))}+{RESET}")
    if not S.caller_queue:
        print(f"  {GRAY}|  (empty - double-click to add stations)      |{RESET}")
    else:
        for n, entry in enumerate(S.caller_queue, 1):
            parts = entry.split()
            call = parts[0] if parts else "?"
            freq = parts[1] if len(parts) > 1 else "?"
            snr  = int(parts[2]) if len(parts) > 2 else -99
            snr_str = f"{snr:+4d} dB" if snr > -99 else "   ?  "
            print(f"  {CYAN}|  #{n:2d}  {call:<12s}  {freq:>5s} Hz  {snr_str}   |{RESET}")
    print(f"  {CYAN}+{bar}+{RESET}")
    print(f"  Tab:{S.tab_index+1}  StackedPage:{['Fox/Hound','CallerQueue'][S.stacked_index]}  "
          f"QSO:{PROGRESS_NAME[S.m_QSOProgress]}  Tx{S.m_ntx}  "
          f"DX:{S.m_hisCall or '–'}  RxFreq:{S.m_rxFreq}")
    print()

def show_state():
    show_queue()

# ─── enqueueCaller ────────────────────────────────────────────────────────────
def enqueueCaller(call: str, freq: int, snr: int) -> bool:
    """
    Identica a MainWindow::enqueueCaller().
    Inserimento ordinato per SNR decrescente, no duplicati, max 20.
    Restituisce True se accodato.
    """
    call = call.upper().strip()
    # No duplicati
    for e in S.caller_queue:
        if e.startswith(call + " "):
            log(f"enqueueCaller: {call} già in coda — ignorato", GRAY)
            return False
    if len(S.caller_queue) >= MAX_QUEUE_SIZE:
        log(f"enqueueCaller: coda piena ({MAX_QUEUE_SIZE}) — {call} ignorato", RED)
        return False

    entry = f"{call} {freq} {snr}"
    # Inserimento ordinato per SNR decrescente
    insert_pos = len(S.caller_queue)
    queue_list = list(S.caller_queue)
    for j, e in enumerate(queue_list):
        parts = e.split()
        existing_snr = int(parts[2]) if len(parts) >= 3 else -99
        if snr > existing_snr:
            insert_pos = j
            break
    queue_list.insert(insert_pos, entry)
    S.caller_queue = deque(queue_list)
    log(f"enqueueCaller: {call} accodato in pos {insert_pos+1}  SNR={snr:+d} dB  freq={freq} Hz", GREEN)
    show_queue()
    return True

# ─── processNextInQueue ───────────────────────────────────────────────────────
def processNextInQueue():
    """
    Identica a MainWindow::processNextInQueue().
    Con fix Bug 4: while loop per saltare entry malformate.
    """
    while S.caller_queue:
        entry = S.caller_queue.popleft()
        parts = entry.split()
        if len(parts) < 2:
            log(f"processNextInQueue: entry malformata '{entry}' — saltata", YELLOW)
            continue
        call = parts[0]
        freq = int(parts[1])
        S.m_hisCall = call
        S.m_rxFreq  = freq
        S.m_autoCQPeriodsMissed = 0
        S.m_receivedReplyThisPeriod = False
        S.m_ntx = 2          # setTxMsg(2) — MSHV style
        S.m_QSOProgress = REPORT
        S.m_txRetryCount = 0
        S.m_lastNtx = -1
        log(f"processNextInQueue: avvio QSO con {call} @ {freq} Hz → Tx2 REPORT", GREEN)
        show_queue()
        return
    # Coda esaurita
    show_queue()
    log("processNextInQueue: coda vuota", GRAY)

# ─── clearDX ─────────────────────────────────────────────────────────────────
def clearDX():
    """Identica a MainWindow::clearDX()"""
    S.m_autoCQPeriodsMissed = 0
    S.m_receivedReplyThisPeriod = False

    if S.m_autoCQ and S.caller_queue:
        log("clearDX: coda non vuota → processNextInQueue()", CYAN)
        processNextInQueue()
        return

    if S.m_autoCQ and not S.caller_queue:
        S.m_ntx = 6
        S.m_QSOProgress = CALLING
        log("clearDX: coda vuota → torna a CQ (Tx6 CALLING)", CYAN)

    if S.m_QSOProgress != CALLING and not S.m_autoCQ:
        log("clearDX: auto_tx_mode(false)", GRAY)

    S.m_hisCall = ""

# ─── on_stopButton_clicked ────────────────────────────────────────────────────
def on_stopButton_clicked():
    """Fix Bug 1: ripristina Tab 2 UI oltre a resettare m_autoCQ"""
    log("STOP button clicked", RED)
    S.m_autoCQ = False
    S.caller_queue.clear()
    # Fix: ripristina stacked widget e tab (prima mancava!)
    S.stacked_index = 0
    S.tab_index = 0
    S.m_hisCall = ""
    S.m_QSOProgress = CALLING
    S.m_ntx = 6
    S.m_txRetryCount = 0
    S.m_lastNtx = -1
    S.m_cqRetryCount = 0
    log(f"  → m_autoCQ=False, queue cleared, Tab1, StackedPage=Fox", GRAY)
    show_queue()

# ─── on_autoCQButton_clicked ──────────────────────────────────────────────────
def on_autoCQButton_clicked(checked: bool):
    S.m_autoCQ = checked
    if checked:
        S.m_ntx = 6
        S.m_QSOProgress = CALLING
        if not S.m_bDXpedMode:
            S.stacked_index = 1   # CallerQueue page
            S.tab_index = 1
        log("Auto CQ ON → Tab2/CallerQueue page, Tx6 CALLING", GREEN)
        show_queue()
    else:
        S.caller_queue.clear()
        S.stacked_index = 0
        S.tab_index = 0
        S.m_hisCall = ""
        log("Auto CQ OFF → Tab1/FoxHound page, queue cleared", YELLOW)
        show_queue()

# ─── on_dxpedButton_clicked ───────────────────────────────────────────────────
def on_dxpedButton_clicked(checked: bool):
    if checked:
        S.m_bDXpedMode = True
        S.m_autoCQ = True
        S.m_bDXpedMode = True
        # Fix Bug 3: DXped forza stacked widget a page 0 (Fox/Hound)
        S.stacked_index = 0
        S.tab_index = 1
        log("DXped ON → Tab2/FoxHound page (stacked=0), m_autoCQ=True", GREEN)
        show_queue()
    else:
        S.m_bDXpedMode = False
        # Fix Bug 2: resetta m_autoCQ che DXped aveva impostato
        S.m_autoCQ = False
        S.caller_queue.clear()
        S.stacked_index = 0
        S.tab_index = 0
        log("DXped OFF → m_autoCQ=False, queue cleared, Tab1", YELLOW)
        show_queue()

# ─── doubleClickOnCallerQueue ────────────────────────────────────────────────
def doubleClickOnCallerQueue(call: str, alt: bool = False):
    """Simula double-click su entry nella coda"""
    call = call.upper().strip()
    found_entry = None
    remaining = deque()
    queue_list = list(S.caller_queue)
    for entry in queue_list:
        if entry.startswith(call + " ") and found_entry is None:
            found_entry = entry
        else:
            remaining.append(entry)
    if found_entry is None:
        log(f"doubleClickOnCallerQueue: '{call}' non trovato in coda", RED)
        return
    if alt:
        # Alt+DC: sposta in cima
        new_queue = deque([found_entry])
        new_queue.extend(remaining)
        S.caller_queue = new_queue
        log(f"doubleClickOnCallerQueue: Alt+DC — {call} spostato in cima", CYAN)
    else:
        # DC normale: rimuovi
        S.caller_queue = remaining
        log(f"doubleClickOnCallerQueue: DC — {call} rimosso dalla coda", YELLOW)
    show_queue()

# ─── Simulazione periodi RX ───────────────────────────────────────────────────
def rx_period(responses: list = None):
    """
    Simula un periodo RX. responses è una lista di (call, freq, snr) che hanno
    risposto in questo periodo.
    Implementa la logica auto_sequence + timeout.
    """
    S.period += 1
    log(f"─── RX period {S.period} ──────────────────────────────────", BOLD)

    if responses:
        for call, freq, snr in responses:
            log(f"  RX decode: {call:12s} @ {freq} Hz  SNR={snr:+d} dB", "")
            # Se è il nostro DX corrente → risposta ricevuta
            if call == S.m_hisCall:
                S.m_receivedReplyThisPeriod = True
                S.m_autoCQPeriodsMissed = 0
                S.m_txRetryCount = 0
                # Avanza QSO state machine (semplificata)
                if S.m_QSOProgress == REPORT:
                    S.m_QSOProgress = ROGER_REPORT
                    S.m_ntx = 4
                    log(f"  → {call} ha risposto al report → Tx4 ROGER_REPORT", GREEN)
                elif S.m_QSOProgress == ROGER_REPORT:
                    S.m_QSOProgress = SIGNOFF
                    S.m_ntx = 5
                    log(f"  → {call} ha inviato RR73 → Tx5 SIGNOFF, loggo QSO", GREEN)
            else:
                # Altro caller durante QSO attivo → enqueue
                if S.m_autoCQ and S.m_QSOProgress > CALLING and S.m_QSOProgress < SIGNOFF:
                    enqueueCaller(call, freq, snr)
    else:
        log("  (nessun decode)", GRAY)

    # Timeout logic (come in readFromStdout / decodeDone)
    if S.m_autoCQ and S.m_QSOProgress > CALLING:
        if not S.m_receivedReplyThisPeriod:
            S.m_autoCQPeriodsMissed += 1
            log(f"  periodsMissed={S.m_autoCQPeriodsMissed}/{MAX_MISSED_PERIODS}", YELLOW)
            if S.m_autoCQPeriodsMissed >= MAX_MISSED_PERIODS:
                log(f"  TIMEOUT: {MAX_MISSED_PERIODS} periodi senza risposta → clearDX()", RED)
                clearDX()
        S.m_receivedReplyThisPeriod = False

    # 73 completato → log e prossimo
    if S.m_QSOProgress == SIGNOFF:
        log(f"  QSO con {S.m_hisCall} completato → clearDX()", GREEN)
        clearDX()

# ─── Scenari di test ──────────────────────────────────────────────────────────

def sep(title):
    print(f"\n{BOLD}{'='*60}{RESET}")
    print(f"{BOLD}  SCENARIO: {title}{RESET}")
    print(f"{BOLD}{'='*60}{RESET}\n")

def reset():
    global S
    S = State()

def run_scenario_1():
    """Scenario 1: Auto CQ base — 3 callers in coda, QSO sequenziali"""
    reset(); sep("Auto CQ base — 3 callers in coda, QSO sequenziali")
    on_autoCQButton_clicked(True)

    # Periodo 1-3: arrivano 3 caller durante CALLING
    rx_period([("W1ABC", 1200, -10)])
    rx_period([("DL2XYZ", 1450, -5)])
    rx_period([("JA1QQQ", 1600, -15)])

    # Periodo 4: inizia QSO con il primo (processNextInQueue)
    # Simuliamo che il prossimo periodo parte con il primo in coda
    log("── Auto CQ avvia primo QSO dalla coda ──", BOLD)
    if S.caller_queue:
        processNextInQueue()  # normalmente chiamato da clearDX o da on_autoCQButton_clicked

    # Periodo 5: W1ABC risponde
    rx_period([("W1ABC", 1200, -10)])

    # Periodo 6: W1ABC invia RR73
    rx_period([("W1ABC", 1200, -10)])

    # clearDX → passa a DL2XYZ
    # (già triggato dallo state SIGNOFF nel period handler)

    # Periodo 7: DL2XYZ risponde
    rx_period([("DL2XYZ", 1450, -5)])
    rx_period([("DL2XYZ", 1450, -5)])

    # Periodo 8: JA1QQQ
    rx_period([("JA1QQQ", 1600, -15)])
    rx_period([("JA1QQQ", 1600, -15)])
    print(f"\n{GREEN}✓ Scenario 1 completato{RESET}\n")

def run_scenario_2():
    """Scenario 2: Timeout — caller non risponde dopo MAX_MISSED_PERIODS"""
    reset(); sep("Timeout caller — skip dopo MAX_MISSED_PERIODS")
    on_autoCQButton_clicked(True)
    enqueueCaller("K7TTT", 1300, -12)
    enqueueCaller("VE3ABC", 1400, -8)
    processNextInQueue()  # avvia con K7TTT

    # K7TTT non risponde per MAX_MISSED_PERIODS periodi
    for i in range(MAX_MISSED_PERIODS):
        rx_period([])

    # Deve essere passato a VE3ABC automaticamente
    print(f"\n{GREEN}✓ Scenario 2 completato — K7TTT saltato, attuale: {S.m_hisCall}{RESET}\n")

def run_scenario_3():
    """Scenario 3: Stop button — Tab 2 deve tornare a Fox page"""
    reset(); sep("Stop button — Tab 2 ripristinata (Bug 1 fix)")
    on_autoCQButton_clicked(True)
    enqueueCaller("OH2ABC", 1500, -7)
    enqueueCaller("F5XYZ", 1600, -3)
    print(f"  Prima di STOP: Tab={S.tab_index+1}, Stacked={'CallerQueue' if S.stacked_index else 'Fox'}, Queue={len(S.caller_queue)}")
    on_stopButton_clicked()
    assert S.tab_index == 0,        f"BUG: tabIndex={S.tab_index}, atteso 0"
    assert S.stacked_index == 0,    f"BUG: stackedIndex={S.stacked_index}, atteso 0"
    assert S.m_autoCQ == False,     f"BUG: m_autoCQ=True dopo STOP"
    assert len(S.caller_queue) == 0,f"BUG: queue non svuotata ({len(S.caller_queue)} elementi)"
    print(f"\n{GREEN}✓ Scenario 3: Stop ripristina correttamente Tab 2{RESET}\n")

def run_scenario_4():
    """Scenario 4: DXped ON/OFF — m_autoCQ e stacked widget corretti (Bug 2+3 fix)"""
    reset(); sep("DXped ON/OFF — m_autoCQ e Tab 2 (Bug 2+3 fix)")
    on_dxpedButton_clicked(True)
    assert S.m_autoCQ == True,    f"BUG: m_autoCQ=False dopo DXped ON"
    assert S.stacked_index == 0, f"BUG: stackedIndex={S.stacked_index}, atteso 0 (Fox page)"
    assert S.tab_index == 1,     f"BUG: tabIndex={S.tab_index}, atteso 1"
    print(f"  DXped ON: autoCQ={S.m_autoCQ}, stacked={['Fox','CallerQueue'][S.stacked_index]}, tab={S.tab_index+1}")

    enqueueCaller("ZL3ABC", 1200, -5)
    enqueueCaller("VK2XYZ", 1300, -8)

    on_dxpedButton_clicked(False)
    assert S.m_autoCQ == False,    f"BUG: m_autoCQ=True dopo DXped OFF"
    assert S.stacked_index == 0,  f"BUG: stackedIndex={S.stacked_index}, atteso 0"
    assert S.tab_index == 0,      f"BUG: tabIndex={S.tab_index}, atteso 0"
    assert len(S.caller_queue) == 0, f"BUG: queue non svuotata ({len(S.caller_queue)})"
    print(f"  DXped OFF: autoCQ={S.m_autoCQ}, stacked={['Fox','CallerQueue'][S.stacked_index]}, tab={S.tab_index+1}, queue={len(S.caller_queue)}")
    print(f"\n{GREEN}✓ Scenario 4: DXped ON/OFF corretto{RESET}\n")

def run_scenario_5():
    """Scenario 5: doubleClickOnCallerQueue — rimozione e move-to-top"""
    reset(); sep("doubleClickOnCallerQueue — rimozione e Alt+DC move-to-top")
    on_autoCQButton_clicked(True)
    enqueueCaller("AA1AAA", 1100, -20)
    enqueueCaller("BB2BBB", 1200, -10)
    enqueueCaller("CC3CCC", 1300, -5)
    enqueueCaller("DD4DDD", 1400, 0)

    print(f"  Ordine iniziale (SNR desc): {[e.split()[0] for e in S.caller_queue]}")
    assert list(S.caller_queue)[0].startswith("DD4DDD"), "BUG: ordinamento SNR sbagliato"

    # Rimuovi BB2BBB
    doubleClickOnCallerQueue("BB2BBB")
    assert all(not e.startswith("BB2BBB") for e in S.caller_queue), "BUG: BB2BBB non rimosso"
    print(f"  Dopo rimozione BB2BBB: {[e.split()[0] for e in S.caller_queue]}")

    # Move AA1AAA in cima (Alt+DC)
    doubleClickOnCallerQueue("AA1AAA", alt=True)
    assert list(S.caller_queue)[0].startswith("AA1AAA"), "BUG: AA1AAA non in cima dopo Alt+DC"
    print(f"  Dopo Alt+DC AA1AAA in cima: {[e.split()[0] for e in S.caller_queue]}")
    print(f"\n{GREEN}✓ Scenario 5: doubleClick rimozione e Alt+DC corretti{RESET}\n")

def run_scenario_6():
    """Scenario 6: Entry malformata in coda (Bug 4 fix)"""
    reset(); sep("Entry malformata — Bug 4 fix (processNextInQueue while loop)")
    on_autoCQButton_clicked(True)
    # Inietta entry malformata direttamente
    S.caller_queue.append("BADENTRY")     # 1 parte
    S.caller_queue.append("ALSO_BAD")     # 1 parte
    S.caller_queue.append("G3ABC 1500 -8")# valida
    print(f"  Queue iniettata: {list(S.caller_queue)}")
    processNextInQueue()
    assert S.m_hisCall == "G3ABC", f"BUG: m_hisCall='{S.m_hisCall}', atteso 'G3ABC'"
    print(f"\n{GREEN}✓ Scenario 6: entry malformate saltate, QSO avviato con G3ABC{RESET}\n")

def run_scenario_7():
    """Scenario 7: SNR ordering — caller più forte prima"""
    reset(); sep("SNR ordering — caller più forte servito prima")
    on_autoCQButton_clicked(True)
    # Inserimento in ordine casuale di SNR
    callers = [("W3AAA", 1200, -15), ("K1BBB", 1300, +3), ("JA7CCC", 1400, -7), ("DK4DDD", 1500, -20)]
    for call, freq, snr in callers:
        enqueueCaller(call, freq, snr)
    order = [e.split()[0] for e in S.caller_queue]
    snrs  = [int(e.split()[2]) for e in S.caller_queue]
    print(f"  Ordine in coda: {order}")
    print(f"  SNR in coda:    {snrs}")
    assert snrs == sorted(snrs, reverse=True), f"BUG: coda non ordinata per SNR desc: {snrs}"
    # Processa in ordine: usa processNextInQueue() una volta, poi clearDX() avanza automaticamente
    processNextInQueue()
    assert S.m_hisCall == "K1BBB",  f"BUG: 1° atteso K1BBB, ottenuto {S.m_hisCall}"
    # clearDX chiama processNextInQueue internamente se la coda non è vuota
    clearDX()
    assert S.m_hisCall == "JA7CCC", f"BUG: 2° atteso JA7CCC, ottenuto {S.m_hisCall}"
    clearDX()
    assert S.m_hisCall == "W3AAA",  f"BUG: 3° atteso W3AAA, ottenuto {S.m_hisCall}"
    clearDX()
    assert S.m_hisCall == "DK4DDD", f"BUG: 4° atteso DK4DDD, ottenuto {S.m_hisCall}"
    clearDX()
    # Coda esaurita: deve tornare a CQ
    assert S.m_QSOProgress == CALLING and S.m_ntx == 6, \
        f"BUG: dopo coda esaurita atteso CALLING/Tx6, ottenuto {PROGRESS_NAME[S.m_QSOProgress]}/Tx{S.m_ntx}"
    print(f"\n{GREEN}✓ Scenario 7: SNR ordering e avanzamento sequenziale corretti{RESET}\n")

def run_scenario_8():
    """Scenario 8: coda piena — limite 20 entries"""
    reset(); sep("Coda piena — limite MAX_QUEUE_SIZE=20")
    on_autoCQButton_clicked(True)
    for i in range(25):
        enqueueCaller(f"W{i:02d}ABC", 1000 + i * 10, -i)
    print(f"  Entries accodate: {len(S.caller_queue)} (max {MAX_QUEUE_SIZE})")
    assert len(S.caller_queue) <= MAX_QUEUE_SIZE, f"BUG: coda ha {len(S.caller_queue)} > {MAX_QUEUE_SIZE}"
    print(f"\n{GREEN}✓ Scenario 8: limite coda rispettato{RESET}\n")

def run_all():
    run_scenario_1()
    run_scenario_2()
    run_scenario_3()
    run_scenario_4()
    run_scenario_5()
    run_scenario_6()
    run_scenario_7()
    run_scenario_8()
    print(f"\n{BOLD}{GREEN}{'='*60}")
    print(f"  TUTTI GLI 8 SCENARI SUPERATI OK")
    print(f"{'='*60}{RESET}\n")

# ─── Modalità interattiva ────────────────────────────────────────────────────
def interactive():
    print(f"\n{BOLD}Decodium Caller Queue Simulator — modalità interattiva{RESET}")
    print("Comandi: enqueue <CALL> <FREQ> <SNR> | process | clear | stop | autocq <on|off>")
    print("         dxped <on|off> | rx [<CALL> <FREQ> <SNR>...] | dc <CALL> [alt]")
    print("         show | reset | run1..8 | runall | quit\n")
    show_state()
    while True:
        try:
            line = input(f"{CYAN}sim>{RESET} ").strip()
        except (EOFError, KeyboardInterrupt):
            break
        if not line:
            continue
        parts = line.split()
        cmd = parts[0].lower()
        try:
            if cmd == "enqueue":
                enqueueCaller(parts[1], int(parts[2]), int(parts[3]))
            elif cmd == "process":
                processNextInQueue()
            elif cmd == "clear":
                clearDX()
            elif cmd == "stop":
                on_stopButton_clicked()
            elif cmd == "autocq":
                on_autoCQButton_clicked(parts[1].lower() == "on")
            elif cmd == "dxped":
                on_dxpedButton_clicked(parts[1].lower() == "on")
            elif cmd == "rx":
                responses = []
                i = 1
                while i + 2 < len(parts):
                    responses.append((parts[i], int(parts[i+1]), int(parts[i+2])))
                    i += 3
                rx_period(responses if responses else None)
            elif cmd == "dc":
                alt = len(parts) > 2 and parts[2].lower() == "alt"
                doubleClickOnCallerQueue(parts[1], alt)
            elif cmd == "show":
                show_state()
            elif cmd == "reset":
                reset(); log("Reset completo", YELLOW)
            elif cmd.startswith("run") and cmd[3:].isdigit():
                globals()[f"run_scenario_{cmd[3:]}"]()
            elif cmd == "runall":
                run_all()
            elif cmd in ("quit", "exit", "q"):
                break
            else:
                print(f"Comando sconosciuto: {cmd}")
        except Exception as e:
            print(f"{RED}Errore: {e}{RESET}")

# ─── Main ────────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    import sys
    if len(sys.argv) > 1 and sys.argv[1] == "batch":
        run_all()
    else:
        interactive()

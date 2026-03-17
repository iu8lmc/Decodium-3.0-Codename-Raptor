#include "TxController.hpp"
#include <QDebug>
#include <QRegularExpression>

TxController::TxController(QObject *parent)
    : QObject(parent)
{
}

bool TxController::transmitting() const
{
    return m_transmitting;
}

void TxController::setTransmitting(bool on)
{
    if (m_transmitting != on) {
        m_transmitting = on;
        emit transmittingChanged();
    }
}

bool TxController::autoCQ() const
{
    return m_autoCQ;
}

void TxController::setAutoCQ(bool on)
{
    if (m_autoCQ != on) {
        m_autoCQ = on;
        emit autoCQChanged();
        if (on) {
            setTxState(QStringLiteral("Auto CQ"));
        } else if (!m_transmitting) {
            setTxState(QStringLiteral("Idle"));
        }
    }
}

bool TxController::autoSequence() const
{
    return m_autoSequence;
}

void TxController::setAutoSequence(bool on)
{
    if (m_autoSequence != on) {
        m_autoSequence = on;
        emit autoSequenceChanged();
    }
}

int TxController::activeTxMessage() const
{
    return m_activeTxMessage;
}

void TxController::setActiveTxMessage(int num)
{
    if (num >= 1 && num <= 6 && m_activeTxMessage != num) {
        m_activeTxMessage = num;
        emit activeTxMessageChanged();
    }
}

QString TxController::hisCall() const
{
    return m_hisCall;
}

void TxController::setHisCall(const QString &call)
{
    QString upper = call.toUpper().trimmed();
    if (m_hisCall != upper) {
        m_hisCall = upper;
        emit hisCallChanged();
    }
}

QString TxController::hisGrid() const
{
    return m_hisGrid;
}

void TxController::setHisGrid(const QString &grid)
{
    QString upper = grid.toUpper().trimmed();
    if (m_hisGrid != upper) {
        m_hisGrid = upper;
        emit hisGridChanged();
    }
}

QString TxController::txReport() const
{
    return m_txReport;
}

void TxController::setTxReport(const QString &report)
{
    if (m_txReport != report) {
        m_txReport = report;
        emit txReportChanged();
    }
}

QString TxController::tx1() const { return m_tx1; }
void TxController::setTx1(const QString &msg)
{
    if (m_tx1 != msg) { m_tx1 = msg; emit tx1Changed(); }
}

QString TxController::tx2() const { return m_tx2; }
void TxController::setTx2(const QString &msg)
{
    if (m_tx2 != msg) { m_tx2 = msg; emit tx2Changed(); }
}

QString TxController::tx3() const { return m_tx3; }
void TxController::setTx3(const QString &msg)
{
    if (m_tx3 != msg) { m_tx3 = msg; emit tx3Changed(); }
}

QString TxController::tx4() const { return m_tx4; }
void TxController::setTx4(const QString &msg)
{
    if (m_tx4 != msg) { m_tx4 = msg; emit tx4Changed(); }
}

QString TxController::tx5() const { return m_tx5; }
void TxController::setTx5(const QString &msg)
{
    if (m_tx5 != msg) { m_tx5 = msg; emit tx5Changed(); }
}

QString TxController::tx6() const { return m_tx6; }
void TxController::setTx6(const QString &msg)
{
    if (m_tx6 != msg) { m_tx6 = msg; emit tx6Changed(); }
}

QString TxController::txState() const
{
    return m_txState;
}

void TxController::setTxState(const QString &state)
{
    if (m_txState != state) {
        m_txState = state;
        emit txStateChanged();
    }
}

int TxController::txPeriod() const
{
    return m_txPeriod;
}

void TxController::setTxPeriod(int period)
{
    if (m_txPeriod != period && (period == 0 || period == 1)) {
        m_txPeriod = period;
        emit txPeriodChanged();
    }
}

void TxController::setQsoProgress(int p)
{
    if (m_qsoProgress != p) {
        m_qsoProgress = p;
        emit qsoProgressChanged();
    }
}

void TxController::setTxEnabled(bool v)
{
    if (m_txEnabled != v) {
        m_txEnabled = v;
        emit txEnabledChanged();
    }
}

void TxController::startCQ()
{
    if (m_tx6.isEmpty())
        return;

    setActiveTxMessage(6);
    setQsoProgress(CALLING);
    setTxState(QStringLiteral("Sending CQ"));
    setTransmitting(true);
    resetWatchdog();
    emit txRequested(m_tx6);
}

void TxController::halt()
{
    setTransmitting(false);
    setTxEnabled(false);
    m_autoCQ = false;
    emit autoCQChanged();
    setQsoProgress(IDLE_QSO);
    setTxState(QStringLiteral("Idle"));
    resetWatchdog();
    emit haltRequested();
}

void TxController::enableTx()
{
    setTxEnabled(true);
    if (!m_transmitting) {
        setTxState(QStringLiteral("Waiting"));
    }
}

void TxController::sendMessage(int num)
{
    if (num < 1 || num > 6)
        return;

    QString msg;
    switch (num) {
    case 1: msg = m_tx1; break;
    case 2: msg = m_tx2; break;
    case 3: msg = m_tx3; break;
    case 4: msg = m_tx4; break;
    case 5: msg = m_tx5; break;
    case 6: msg = m_tx6; break;
    }

    if (msg.isEmpty())
        return;

    setActiveTxMessage(num);
    setTransmitting(true);
    resetWatchdog();

    switch (num) {
    case 1: setTxState(QStringLiteral("Sending Grid")); break;
    case 2: setTxState(QStringLiteral("Sending Report")); break;
    case 3: setTxState(QStringLiteral("Sending R+Report")); break;
    case 4: setTxState(QStringLiteral("Sending RR73")); break;
    case 5: setTxState(QStringLiteral("Sending 73")); break;
    case 6: setTxState(QStringLiteral("Sending CQ")); break;
    }

    emit txRequested(msg);
}

void TxController::genStdMsgs(const QString &myCall, const QString &myGrid,
                               const QString &hisCall, const QString &hisGrid,
                               const QString &rptSent, const QString &rptRcvd)
{
    Q_UNUSED(rptRcvd)

    if (myCall.isEmpty())
        return;

    setHisCall(hisCall);
    setHisGrid(hisGrid);
    setTxReport(rptSent);

    QString gridPart = myGrid.left(4);

    // TX6: CQ myCall myGrid
    setTx6(QStringLiteral("CQ %1 %2").arg(myCall, gridPart));

    if (hisCall.isEmpty()) {
        setTx1(QString());
        setTx2(QString());
        setTx3(QString());
        setTx4(QString());
        setTx5(QString());
        return;
    }

    // TX1: hisCall myCall myGrid (reply to CQ)
    setTx1(QStringLiteral("%1 %2 %3").arg(hisCall, myCall, gridPart));

    // TX2: hisCall myCall rptSent (send report)
    QString report = rptSent;
    if (report.isEmpty())
        report = QStringLiteral("-10");
    setTx2(QStringLiteral("%1 %2 %3").arg(hisCall, myCall, report));

    // TX3: hisCall myCall R+rptSent (send R+report)
    setTx3(QStringLiteral("%1 %2 R%3").arg(hisCall, myCall, report));

    // TX4: hisCall myCall RR73 (final acknowledgment)
    setTx4(QStringLiteral("%1 %2 RR73").arg(hisCall, myCall));

    // TX5: hisCall myCall 73 (alternate final)
    setTx5(QStringLiteral("%1 %2 73").arg(hisCall, myCall));
}

// ── FASE 4: Process decoded messages for auto-sequence ──
void TxController::processDecodedMessage(const QString &utc, int snr, double dt,
                                          int freq, const QString &message,
                                          const QString &myCall, const QString &myGrid)
{
    Q_UNUSED(utc)
    Q_UNUSED(dt)

    if (!m_autoSequence || myCall.isEmpty())
        return;

    // Check if this message is directed to us
    bool isDirected = message.contains(myCall);
    if (!isDirected)
        return;

    // Parse the message to determine what was received
    QStringList parts = message.trimmed().split(QRegularExpression("\\s+"));
    if (parts.size() < 2)
        return;

    // Expected formats:
    // "myCall hisCall grid"   -> they reply to our CQ with grid
    // "myCall hisCall report" -> they send us a report (e.g. -10)
    // "myCall hisCall Rreport"-> they send R+report (e.g. R-10)
    // "myCall hisCall RR73"   -> they acknowledge
    // "myCall hisCall RRR"    -> they acknowledge
    // "myCall hisCall 73"     -> they sign off
    // "CQ hisCall grid"      -> CQ from hisCall (not directed)

    QString lastPart = parts.last();
    QString senderCall;

    // Find the sender: first part that isn't our call
    for (const auto &part : parts) {
        if (part != myCall && part != QStringLiteral("CQ") && part != QStringLiteral("DX")
            && !part.startsWith('-') && !part.startsWith('+') && !part.startsWith('R')
            && part != QStringLiteral("RR73") && part != QStringLiteral("RRR")
            && part != QStringLiteral("73")) {
            // Looks like a callsign if it has a digit
            if (part.contains(QRegularExpression("[0-9]"))) {
                senderCall = part;
                break;
            }
        }
    }

    // If sender doesn't match our current DX call, and we already have one, skip
    if (!m_hisCall.isEmpty() && !senderCall.isEmpty() && senderCall != m_hisCall)
        return;

    // If we don't have a DX call set yet, set it from this message
    if (m_hisCall.isEmpty() && !senderCall.isEmpty()) {
        setHisCall(senderCall);
    }

    // Store received report for later
    QString rptSent = m_txReport.isEmpty() ? QStringLiteral("-10") : m_txReport;
    QString rptRcvd = QString::number(snr);

    // Determine QSO state transition based on received message content
    if (lastPart == QStringLiteral("73")) {
        // Received 73 → QSO complete, halt TX
        qDebug() << "Auto-seq: received 73 from" << senderCall;
        emit qsoComplete(m_hisCall, m_hisGrid, rptSent, rptRcvd);
        halt();
        return;
    }

    if (lastPart == QStringLiteral("RR73") || lastPart == QStringLiteral("RRR")) {
        // Received RR73/RRR → send 73 (TX5), QSO essentially complete
        qDebug() << "Auto-seq: received RR73 from" << senderCall << "→ send 73";
        m_rptRcvd = rptRcvd;
        genStdMsgs(myCall, myGrid, m_hisCall, m_hisGrid, rptSent, rptRcvd);
        advanceQsoState(5);
        emit qsoComplete(m_hisCall, m_hisGrid, rptSent, m_rptRcvd);
        return;
    }

    if (lastPart.startsWith('R') && lastPart.length() >= 2
        && (lastPart[1] == '-' || lastPart[1] == '+' || lastPart[1].isDigit())) {
        // Received R+report → send RR73 (TX4)
        m_rptRcvd = lastPart.mid(1);  // strip the 'R'
        qDebug() << "Auto-seq: received R+report" << lastPart << "from" << senderCall << "→ send RR73";
        genStdMsgs(myCall, myGrid, m_hisCall, m_hisGrid, rptSent, m_rptRcvd);
        advanceQsoState(4);
        return;
    }

    if ((lastPart.startsWith('-') || lastPart.startsWith('+')) && lastPart.length() >= 2) {
        // Received report → send R+report (TX3)
        m_rptRcvd = lastPart;
        qDebug() << "Auto-seq: received report" << lastPart << "from" << senderCall << "→ send R+report";
        genStdMsgs(myCall, myGrid, m_hisCall, m_hisGrid, rptSent, m_rptRcvd);
        advanceQsoState(3);
        return;
    }

    // Check if last part is a grid square (4-6 chars, letter-letter-digit-digit pattern)
    if (lastPart.length() >= 4 && lastPart[0].isLetter() && lastPart[1].isLetter()
        && lastPart[2].isDigit() && lastPart[3].isDigit()) {
        // Received grid → they're replying to our CQ → send report (TX2)
        setHisGrid(lastPart);
        m_rptRcvd = rptRcvd;
        qDebug() << "Auto-seq: received grid" << lastPart << "from" << senderCall << "→ send report";
        genStdMsgs(myCall, myGrid, senderCall.isEmpty() ? m_hisCall : senderCall,
                   lastPart, rptSent, rptRcvd);
        advanceQsoState(2);
        emit rxFreqRequested(freq);
        return;
    }
}

void TxController::advanceQsoState(int nextTxNum)
{
    setActiveTxMessage(nextTxNum);
    setTxEnabled(true);
    resetWatchdog();

    switch (nextTxNum) {
    case 1: setQsoProgress(CALLING); break;
    case 2: setQsoProgress(REPORT); break;
    case 3: setQsoProgress(ROGER_REPORT); break;
    case 4: setQsoProgress(ROGERS); break;
    case 5: setQsoProgress(SIGNOFF); break;
    case 6: setQsoProgress(CALLING); break;
    }
}

// ── FASE 5: Handle double-click on decode line ──
void TxController::handleDoubleClick(const QString &message, int freq,
                                      const QString &myCall, const QString &myGrid)
{
    if (message.isEmpty() || myCall.isEmpty())
        return;

    QStringList parts = message.trimmed().split(QRegularExpression("\\s+"));
    if (parts.isEmpty())
        return;

    QString callsign;
    QString grid;

    if (parts[0] == QStringLiteral("CQ")) {
        // CQ [DX] CALL GRID
        int callIdx = 1;
        if (parts.size() > 2 && (parts[1] == QStringLiteral("DX")
            || parts[1] == QStringLiteral("POTA") || parts[1] == QStringLiteral("SOTA")
            || parts[1] == QStringLiteral("QRP") || parts[1].length() <= 3)) {
            callIdx = 2;
        }
        if (callIdx < parts.size())
            callsign = parts[callIdx];
        if (callIdx + 1 < parts.size())
            grid = parts[callIdx + 1];

        // Reply to CQ → start with TX1 (grid)
        setHisCall(callsign);
        setHisGrid(grid);
        genStdMsgs(myCall, myGrid, callsign, grid, QStringLiteral("-10"), QString());
        advanceQsoState(1);
        emit rxFreqRequested(freq);
    } else {
        // Non-CQ message: extract callsign
        // First word is target, second is sender
        if (parts.size() >= 2) {
            // If first part is our call, sender is second
            if (parts[0] == myCall) {
                callsign = parts[1];
            } else {
                callsign = parts[0];
            }
        }
        if (parts.size() >= 3) {
            QString last = parts.last();
            if (last.length() >= 4 && last[0].isLetter() && last[1].isLetter()
                && last[2].isDigit() && last[3].isDigit()) {
                grid = last;
            }
        }

        setHisCall(callsign);
        if (!grid.isEmpty()) setHisGrid(grid);
        genStdMsgs(myCall, myGrid, callsign, grid, QStringLiteral("-10"), QString());
        advanceQsoState(2);
        emit rxFreqRequested(freq);
    }
}

// ── Watchdog ──
void TxController::tickWatchdog()
{
    if (m_transmitting) {
        m_txWatchdog++;
        emit txWatchdogChanged();
        if (m_txWatchdog >= TX_WATCHDOG_MAX) {
            qDebug() << "TX Watchdog: timeout reached, halting TX";
            halt();
        }
    }
}

void TxController::resetWatchdog()
{
    if (m_txWatchdog != 0) {
        m_txWatchdog = 0;
        emit txWatchdogChanged();
    }
}

QString TxController::currentTxMessage() const
{
    switch (m_activeTxMessage) {
    case 1: return m_tx1;
    case 2: return m_tx2;
    case 3: return m_tx3;
    case 4: return m_tx4;
    case 5: return m_tx5;
    case 6: return m_tx6;
    default: return QString();
    }
}

// ── Fox/Hound Mode ──

void TxController::setFoxMode(bool v)
{
    if (m_foxMode != v) {
        m_foxMode = v;
        if (v) {
            m_houndMode = false;
            emit houndModeChanged();
        }
        emit foxModeChanged();
    }
}

void TxController::setHoundMode(bool v)
{
    if (m_houndMode != v) {
        m_houndMode = v;
        if (v) {
            m_foxMode = false;
            m_superFoxMode = false;
            emit foxModeChanged();
            emit superFoxModeChanged();
        }
        emit houndModeChanged();
    }
}

void TxController::setSuperFoxMode(bool v)
{
    if (m_superFoxMode != v) {
        m_superFoxMode = v;
        if (v && !m_foxMode) {
            m_foxMode = true;
            emit foxModeChanged();
        }
        emit superFoxModeChanged();
    }
}

void TxController::setNoB4Filter(bool v)
{
    if (m_noB4Filter != v) {
        m_noB4Filter = v;
        emit noB4FilterChanged();
    }
}

void TxController::enqueueStation(const QString &call)
{
    QString upper = call.toUpper().trimmed();
    if (upper.isEmpty() || m_callerQueue.contains(upper))
        return;

    if (m_callerQueue.size() >= MAX_CALLER_QUEUE) {
        qDebug() << "TxController: caller queue full, ignoring" << upper;
        return;
    }

    m_callerQueue.append(upper);
    emit callerQueueChanged();
    qDebug() << "TxController: enqueued" << upper << "queue size:" << m_callerQueue.size();
}

void TxController::dequeueStation(const QString &call)
{
    QString upper = call.toUpper().trimmed();
    if (m_callerQueue.removeOne(upper)) {
        emit callerQueueChanged();
        qDebug() << "TxController: dequeued" << upper;
    }
}

void TxController::clearCallerQueue()
{
    if (!m_callerQueue.isEmpty()) {
        m_callerQueue.clear();
        emit callerQueueChanged();
    }
}

QString TxController::dequeueNextStation()
{
    if (m_callerQueue.isEmpty())
        return QString();

    QString next = m_callerQueue.takeFirst();
    emit callerQueueChanged();
    qDebug() << "TxController: processing next in queue:" << next;
    return next;
}

#include "LogController.hpp"
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QRegularExpression>

LogController::LogController(QObject *parent)
    : QObject(parent)
{
    m_nam = new QNetworkAccessManager(this);
    loadAdifLog();
}

int LogController::qsoCount() const
{
    return m_qsoCount;
}

QString LogController::lastLoggedCall() const
{
    return m_lastLoggedCall;
}

QString LogController::lastLoggedGrid() const
{
    return m_lastLoggedGrid;
}

QString LogController::lastLoggedTime() const
{
    return m_lastLoggedTime;
}

void LogController::logQSO(const QString &call, const QString &grid,
                            const QString &mode, const QString &rstSent,
                            const QString &rstRcvd, double freq)
{
    logQSOFull(call, grid, mode, rstSent, rstRcvd, freq, QString(), QString());
}

void LogController::logQSOFull(const QString &call, const QString &grid,
                                const QString &mode, const QString &rstSent,
                                const QString &rstRcvd, double freq,
                                const QString &comment, const QString &name)
{
    if (call.isEmpty())
        return;

    QSORecord qso;
    qso.dateTimeOn = QDateTime::currentDateTimeUtc();
    qso.dateTimeOff = qso.dateTimeOn;
    qso.call = call.toUpper().trimmed();
    qso.grid = grid.toUpper().trimmed();
    qso.mode = mode.toUpper().trimmed();
    qso.rstSent = rstSent;
    qso.rstRcvd = rstRcvd;
    qso.frequency = freq;
    qso.comment = comment;
    qso.name = name;

    // Write to ADIF file
    writeAdifRecord(qso);

    // Upload to Cloudlog if enabled
    if (m_cloudlogEnabled && !m_cloudlogUrl.isEmpty() && !m_cloudlogApiKey.isEmpty()) {
        uploadToCloudlog(qso);
    }

    // Update in-memory tracking
    QString band = bandFromFrequency(freq);
    m_workedCallsByBand.insert(band, qso.call);
    if (!qso.grid.isEmpty()) {
        m_workedGridsByBand.insert(band, qso.grid);
    }

    // Update properties
    m_qsoCount++;
    emit qsoCountChanged();

    m_lastLoggedCall = qso.call;
    emit lastLoggedCallChanged();

    m_lastLoggedGrid = qso.grid;
    emit lastLoggedGridChanged();

    m_lastLoggedTime = qso.dateTimeOn.toString(QStringLiteral("yyyy-MM-dd hh:mm:ss"));
    emit lastLoggedTimeChanged();

    emit qsoLogged(qso.call, qso.grid, qso.mode, freq);
}

bool LogController::isCallWorked(const QString &call, const QString &band) const
{
    return m_workedCallsByBand.contains(band, call.toUpper().trimmed());
}

bool LogController::isGridWorked(const QString &grid, const QString &band) const
{
    return m_workedGridsByBand.contains(band, grid.toUpper().trimmed());
}

void LogController::loadAdifLog()
{
    QString logDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QString logPath = logDir + QStringLiteral("/decodium3_log.adi");

    QFile file(logPath);
    if (!file.exists() || !file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    // Skip ADIF header (everything before <eoh>)
    int eohPos = content.indexOf(QStringLiteral("<eoh>"), 0, Qt::CaseInsensitive);
    if (eohPos >= 0)
        content = content.mid(eohPos + 5);

    // Parse ADIF records
    static QRegularExpression fieldRe(QStringLiteral("<(\\w+):(\\d+)>([^<]*)"),
                                       QRegularExpression::CaseInsensitiveOption);
    static QRegularExpression eorRe(QStringLiteral("<eor>"),
                                     QRegularExpression::CaseInsensitiveOption);

    int pos = 0;
    while (pos < content.size()) {
        int eorIdx = content.indexOf(eorRe, pos);
        if (eorIdx < 0)
            break;

        QString record = content.mid(pos, eorIdx - pos);
        pos = eorIdx + 5;

        QString call, band;
        QString grid;

        auto it = fieldRe.globalMatch(record);
        while (it.hasNext()) {
            auto match = it.next();
            QString fieldName = match.captured(1).toLower();
            int fieldLen = match.captured(2).toInt();
            QString fieldValue = match.captured(3).left(fieldLen);

            if (fieldName == QStringLiteral("call"))
                call = fieldValue.toUpper().trimmed();
            else if (fieldName == QStringLiteral("band"))
                band = fieldValue.trimmed();
            else if (fieldName == QStringLiteral("gridsquare"))
                grid = fieldValue.toUpper().trimmed();
        }

        if (!call.isEmpty() && !band.isEmpty()) {
            m_workedCallsByBand.insert(band, call);
            if (!grid.isEmpty())
                m_workedGridsByBand.insert(band, grid);
            m_qsoCount++;
        }
    }

    if (m_qsoCount > 0) {
        emit qsoCountChanged();
    }
}

void LogController::writeAdifRecord(const QSORecord &qso)
{
    QString logDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(logDir);
    if (!dir.exists()) {
        dir.mkpath(logDir);
    }

    QString logPath = logDir + QStringLiteral("/decodium3_log.adi");
    QFile file(logPath);

    bool isNewFile = !file.exists();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);

    if (isNewFile) {
        out << QStringLiteral("ADIF Export from Decodium3\n");
        out << QStringLiteral("<adif_ver:5>3.1.4\n");
        out << QStringLiteral("<programid:9>Decodium3\n");
        out << QStringLiteral("<programversion:5>3.0.0\n");
        out << QStringLiteral("<eoh>\n\n");
    }

    auto writeField = [&out](const QString &fieldName, const QString &value) {
        if (!value.isEmpty()) {
            out << QStringLiteral("<%1:%2>%3 ")
                       .arg(fieldName)
                       .arg(value.length())
                       .arg(value);
        }
    };

    writeField(QStringLiteral("call"), qso.call);
    writeField(QStringLiteral("gridsquare"), qso.grid);
    writeField(QStringLiteral("mode"), qso.mode);
    writeField(QStringLiteral("rst_sent"), qso.rstSent);
    writeField(QStringLiteral("rst_rcvd"), qso.rstRcvd);

    double freqMHz = qso.frequency / 1000000.0;
    writeField(QStringLiteral("freq"), QString::number(freqMHz, 'f', 6));

    QString band = bandFromFrequency(qso.frequency);
    writeField(QStringLiteral("band"), band);

    writeField(QStringLiteral("qso_date"),
               qso.dateTimeOn.toString(QStringLiteral("yyyyMMdd")));
    writeField(QStringLiteral("time_on"),
               qso.dateTimeOn.toString(QStringLiteral("hhmmss")));
    writeField(QStringLiteral("qso_date_off"),
               qso.dateTimeOff.toString(QStringLiteral("yyyyMMdd")));
    writeField(QStringLiteral("time_off"),
               qso.dateTimeOff.toString(QStringLiteral("hhmmss")));

    writeField(QStringLiteral("comment"), qso.comment);
    writeField(QStringLiteral("name"), qso.name);

    out << QStringLiteral("<eor>\n");

    file.close();
}

void LogController::uploadToCloudlog(const QSORecord &qso)
{
    QJsonObject json;
    json[QStringLiteral("key")] = m_cloudlogApiKey;
    json[QStringLiteral("type")] = QStringLiteral("adif");

    // Build ADIF string for the single QSO
    QString adif;
    auto addField = [&adif](const QString &name, const QString &value) {
        if (!value.isEmpty())
            adif += QStringLiteral("<%1:%2>%3").arg(name).arg(value.length()).arg(value);
    };

    addField(QStringLiteral("call"), qso.call);
    addField(QStringLiteral("gridsquare"), qso.grid);
    addField(QStringLiteral("mode"), qso.mode);
    addField(QStringLiteral("rst_sent"), qso.rstSent);
    addField(QStringLiteral("rst_rcvd"), qso.rstRcvd);
    addField(QStringLiteral("freq"), QString::number(qso.frequency / 1000000.0, 'f', 6));
    addField(QStringLiteral("band"), bandFromFrequency(qso.frequency));
    addField(QStringLiteral("qso_date"), qso.dateTimeOn.toString(QStringLiteral("yyyyMMdd")));
    addField(QStringLiteral("time_on"), qso.dateTimeOn.toString(QStringLiteral("hhmmss")));
    adif += QStringLiteral("<eor>");

    json[QStringLiteral("string")] = adif;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson(QJsonDocument::Compact);

    QNetworkRequest req(QUrl(m_cloudlogUrl + QStringLiteral("/index.php/api/qso")));
    req.setHeader(QNetworkRequest::ContentTypeHeader, QStringLiteral("application/json"));

    QNetworkReply *reply = m_nam->post(req, data);
    connect(reply, &QNetworkReply::finished, reply, [reply]() {
        if (reply->error() != QNetworkReply::NoError) {
            qWarning() << "Cloudlog upload failed:" << reply->errorString();
        } else {
            qDebug() << "Cloudlog: QSO uploaded successfully";
        }
        reply->deleteLater();
    });
}

// ── LOTW Integration ──

void LogController::setLotwEnabled(bool v)
{
    if (m_lotwEnabled != v) {
        m_lotwEnabled = v;
        emit lotwEnabledChanged();
    }
}

void LogController::updateLotwUsers()
{
    qDebug() << "LogController: downloading LOTW user list";
    QUrl url(QStringLiteral("https://lotw.arrl.org/lotw-user-activity.csv"));
    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::UserAgentHeader, QStringLiteral("Decodium3/3.0"));

    QNetworkReply *reply = m_nam->get(req);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qWarning() << "LogController: LOTW user list download failed:" << reply->errorString();
            return;
        }

        m_lotwUsers.clear();
        QTextStream in(reply);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (line.isEmpty() || line.startsWith('#'))
                continue;
            // Format: CALL,DATE
            int comma = line.indexOf(',');
            if (comma > 0) {
                m_lotwUsers.insert(line.left(comma).toUpper().trimmed());
            }
        }
        qDebug() << "LogController: loaded" << m_lotwUsers.size() << "LOTW users";
    });
}

bool LogController::isLotwUser(const QString &call) const
{
    return m_lotwUsers.contains(call.toUpper().trimmed());
}

// ── Contest / Cabrillo ──

void LogController::setContestMode(bool v)
{
    if (m_contestMode != v) {
        m_contestMode = v;
        emit contestModeChanged();
    }
}

void LogController::setContestName(const QString &n)
{
    if (m_contestName != n) {
        m_contestName = n;
        emit contestNameChanged();
    }
}

void LogController::exportCabrillo(const QString &filename)
{
    if (filename.isEmpty()) return;

    // Read existing ADIF log and convert to Cabrillo format
    QString logDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QString adifPath = logDir + QStringLiteral("/decodium3_log.adi");

    QFile adifFile(adifPath);
    if (!adifFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "LogController: cannot read ADIF for Cabrillo export";
        return;
    }

    QFile cabFile(filename);
    if (!cabFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "LogController: cannot create Cabrillo file:" << filename;
        return;
    }

    QTextStream out(&cabFile);
    out << "START-OF-LOG: 3.0\n";
    out << "CONTEST: " << (m_contestName.isEmpty() ? "GENERAL" : m_contestName) << "\n";
    out << "CREATED-BY: Decodium3 v3.0\n";
    out << "CALLSIGN: \n";  // User should fill in
    out << "CATEGORY-OPERATOR: SINGLE-OP\n";
    out << "CATEGORY-BAND: ALL\n";
    out << "CATEGORY-MODE: DIGI\n";

    // Parse ADIF and write QSO lines
    QTextStream in(&adifFile);
    QString content = in.readAll();
    adifFile.close();

    int eohPos = content.indexOf(QStringLiteral("<eoh>"), 0, Qt::CaseInsensitive);
    if (eohPos >= 0) content = content.mid(eohPos + 5);

    static QRegularExpression fieldRe(QStringLiteral("<(\\w+):(\\d+)>([^<]*)"),
                                       QRegularExpression::CaseInsensitiveOption);
    static QRegularExpression eorRe(QStringLiteral("<eor>"),
                                     QRegularExpression::CaseInsensitiveOption);

    int pos = 0;
    while (pos < content.size()) {
        int eorIdx = content.indexOf(eorRe, pos);
        if (eorIdx < 0) break;

        QString record = content.mid(pos, eorIdx - pos);
        pos = eorIdx + 5;

        QString call, freq, mode, date, time, rstSent, rstRcvd;

        auto it = fieldRe.globalMatch(record);
        while (it.hasNext()) {
            auto match = it.next();
            QString fn = match.captured(1).toLower();
            int fl = match.captured(2).toInt();
            QString fv = match.captured(3).left(fl);

            if (fn == "call") call = fv;
            else if (fn == "freq") freq = fv;
            else if (fn == "mode") mode = fv;
            else if (fn == "qso_date") date = fv;
            else if (fn == "time_on") time = fv;
            else if (fn == "rst_sent") rstSent = fv;
            else if (fn == "rst_rcvd") rstRcvd = fv;
        }

        if (!call.isEmpty()) {
            // Cabrillo QSO format: QSO: freq mode date time call rst exch
            int freqKhz = static_cast<int>(freq.toDouble() * 1000);
            out << QString("QSO: %1 DG %2 %3 %4 %5 %6\n")
                       .arg(freqKhz, 5)
                       .arg(date)
                       .arg(time.left(4))
                       .arg(call, -13)
                       .arg(rstSent.isEmpty() ? "599" : rstSent)
                       .arg(rstRcvd.isEmpty() ? "599" : rstRcvd);
        }
    }

    out << "END-OF-LOG:\n";
    cabFile.close();
    qDebug() << "LogController: Cabrillo exported to" << filename;
}

void LogController::reloadCtyDat()
{
    qDebug() << "LogController: reloading country data from cty.dat";
    // Country data reload - the AD1CCty class handles this in the desktop version
    // For now, just log that it was called; full DXCC lookup can be added later
}

QString LogController::bandFromFrequency(double freqHz) const
{
    if (freqHz >= 1800000 && freqHz <= 2000000)
        return QStringLiteral("160m");
    if (freqHz >= 3500000 && freqHz <= 4000000)
        return QStringLiteral("80m");
    if (freqHz >= 5330500 && freqHz <= 5406400)
        return QStringLiteral("60m");
    if (freqHz >= 7000000 && freqHz <= 7300000)
        return QStringLiteral("40m");
    if (freqHz >= 10100000 && freqHz <= 10150000)
        return QStringLiteral("30m");
    if (freqHz >= 14000000 && freqHz <= 14350000)
        return QStringLiteral("20m");
    if (freqHz >= 18068000 && freqHz <= 18168000)
        return QStringLiteral("17m");
    if (freqHz >= 21000000 && freqHz <= 21450000)
        return QStringLiteral("15m");
    if (freqHz >= 24890000 && freqHz <= 24990000)
        return QStringLiteral("12m");
    if (freqHz >= 28000000 && freqHz <= 29700000)
        return QStringLiteral("10m");
    if (freqHz >= 50000000 && freqHz <= 54000000)
        return QStringLiteral("6m");
    if (freqHz >= 144000000 && freqHz <= 148000000)
        return QStringLiteral("2m");
    if (freqHz >= 420000000 && freqHz <= 450000000)
        return QStringLiteral("70cm");

    return QStringLiteral("OOB");
}

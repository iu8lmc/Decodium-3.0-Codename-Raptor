#include "AppController.hpp"
#include <QSettings>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QUrl>
#include <QDebug>

AppController::AppController(QObject *parent)
    : QObject(parent)
    , m_nam(new QNetworkAccessManager(this))
{
    loadSettings();

    // Auto-check cty.dat on startup
    QMetaObject::invokeMethod(this, "checkCtyDatUpdate", Qt::QueuedConnection);
}

QString AppController::callsign() const
{
    return m_callsign;
}

void AppController::setCallsign(const QString &call)
{
    QString upper = call.toUpper().trimmed();
    if (m_callsign != upper) {
        m_callsign = upper;
        emit callsignChanged();
        saveSettings();
    }
}

QString AppController::grid() const
{
    return m_grid;
}

void AppController::setGrid(const QString &grid)
{
    QString formatted = grid.toUpper().trimmed();
    if (m_grid != formatted) {
        m_grid = formatted;
        emit gridChanged();
        saveSettings();
    }
}

bool AppController::darkMode() const
{
    return m_darkMode;
}

void AppController::setDarkMode(bool dark)
{
    if (m_darkMode != dark) {
        m_darkMode = dark;
        emit darkModeChanged();
        saveSettings();
    }
}

// Decoder tuning setters
void AppController::setFt8Sensitivity(int v)
{
    v = qBound(0, v, 2);
    if (m_ft8Sensitivity != v) { m_ft8Sensitivity = v; emit decoderSettingsChanged(); saveSettings(); }
}

void AppController::setFt8Cycles(int v)
{
    v = qBound(1, v, 3);
    if (m_ft8Cycles != v) { m_ft8Cycles = v; emit decoderSettingsChanged(); saveSettings(); }
}

void AppController::setFt8Threads(int v)
{
    v = qBound(0, v, 12);
    if (m_ft8Threads != v) { m_ft8Threads = v; emit decoderSettingsChanged(); saveSettings(); }
}

void AppController::setFt8DecoderStart(int v)
{
    v = qBound(1, v, 5);
    if (m_ft8DecoderStart != v) { m_ft8DecoderStart = v; emit decoderSettingsChanged(); saveSettings(); }
}

void AppController::setFt4Depth(int v)
{
    v = qBound(1, v, 3);
    if (m_ft4Depth != v) { m_ft4Depth = v; emit decoderSettingsChanged(); saveSettings(); }
}

void AppController::setNtrials10(int v)
{
    if (m_ntrials10 != v) { m_ntrials10 = v; emit decoderSettingsChanged(); saveSettings(); }
}

void AppController::setMultithreadFT8(bool v)
{
    if (m_multithreadFT8 != v) { m_multithreadFT8 = v; emit decoderSettingsChanged(); saveSettings(); }
}

void AppController::setHideFT8Dupes(bool v)
{
    if (m_hideFT8Dupes != v) { m_hideFT8Dupes = v; emit decoderSettingsChanged(); saveSettings(); }
}

void AppController::setWideDxCallSearch(bool v)
{
    if (m_wideDxCallSearch != v) { m_wideDxCallSearch = v; emit decoderSettingsChanged(); saveSettings(); }
}

// NTP
void AppController::setNtpEnabled(bool v)
{
    if (m_ntpEnabled != v) { m_ntpEnabled = v; emit ntpEnabledChanged(); saveSettings(); }
}

void AppController::setNtpSynced(bool v)
{
    if (m_ntpSynced != v) { m_ntpSynced = v; emit ntpSyncedChanged(); }
}

void AppController::setNtpOffsetMs(double v)
{
    if (!qFuzzyCompare(m_ntpOffsetMs, v)) { m_ntpOffsetMs = v; emit ntpOffsetMsChanged(); }
}

// PSK Reporter
void AppController::setPskReporterEnabled(bool v)
{
    if (m_pskReporterEnabled != v) { m_pskReporterEnabled = v; emit pskReporterEnabledChanged(); saveSettings(); }
}

// Cloudlog
void AppController::setCloudlogEnabled(bool v)
{
    if (m_cloudlogEnabled != v) { m_cloudlogEnabled = v; emit cloudlogEnabledChanged(); saveSettings(); }
}

void AppController::setCloudlogUrl(const QString &v)
{
    if (m_cloudlogUrl != v) { m_cloudlogUrl = v; emit cloudlogUrlChanged(); saveSettings(); }
}

void AppController::setCloudlogApiKey(const QString &v)
{
    if (m_cloudlogApiKey != v) { m_cloudlogApiKey = v; emit cloudlogApiKeyChanged(); saveSettings(); }
}

void AppController::saveSettings()
{
    QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
    settings.beginGroup(QStringLiteral("Station"));
    settings.setValue(QStringLiteral("Callsign"), m_callsign);
    settings.setValue(QStringLiteral("Grid"), m_grid);
    settings.endGroup();

    settings.beginGroup(QStringLiteral("Appearance"));
    settings.setValue(QStringLiteral("DarkMode"), m_darkMode);
    settings.endGroup();

    settings.beginGroup(QStringLiteral("Decoder"));
    settings.setValue(QStringLiteral("FT8Sensitivity"), m_ft8Sensitivity);
    settings.setValue(QStringLiteral("FT8Cycles"), m_ft8Cycles);
    settings.setValue(QStringLiteral("FT8Threads"), m_ft8Threads);
    settings.setValue(QStringLiteral("FT8DecoderStart"), m_ft8DecoderStart);
    settings.setValue(QStringLiteral("FT4Depth"), m_ft4Depth);
    settings.setValue(QStringLiteral("Ntrials10"), m_ntrials10);
    settings.setValue(QStringLiteral("MultithreadFT8"), m_multithreadFT8);
    settings.setValue(QStringLiteral("HideFT8Dupes"), m_hideFT8Dupes);
    settings.setValue(QStringLiteral("WideDxCallSearch"), m_wideDxCallSearch);
    settings.endGroup();

    settings.beginGroup(QStringLiteral("NTP"));
    settings.setValue(QStringLiteral("Enabled"), m_ntpEnabled);
    settings.endGroup();

    settings.beginGroup(QStringLiteral("PSKReporter"));
    settings.setValue(QStringLiteral("Enabled"), m_pskReporterEnabled);
    settings.endGroup();

    settings.beginGroup(QStringLiteral("Cloudlog"));
    settings.setValue(QStringLiteral("Enabled"), m_cloudlogEnabled);
    settings.setValue(QStringLiteral("Url"), m_cloudlogUrl);
    settings.setValue(QStringLiteral("ApiKey"), m_cloudlogApiKey);
    settings.endGroup();

    settings.beginGroup(QStringLiteral("Highlighting"));
    settings.setValue(QStringLiteral("ColorCQ"), m_colorCQ.name());
    settings.setValue(QStringLiteral("ColorMyCall"), m_colorMyCall.name());
    settings.setValue(QStringLiteral("ColorDXEntity"), m_colorDXEntity.name());
    settings.setValue(QStringLiteral("Color73"), m_color73.name());
    settings.setValue(QStringLiteral("ColorB4"), m_colorB4.name());
    settings.setValue(QStringLiteral("B4Strikethrough"), m_b4Strikethrough);
    settings.endGroup();

    settings.beginGroup(QStringLiteral("Alerts"));
    settings.setValue(QStringLiteral("Enabled"), m_alertSoundsEnabled);
    settings.endGroup();

    settings.sync();
}

void AppController::loadSettings()
{
    QSettings settings(QStringLiteral("Decodium3"), QStringLiteral("Decodium3"));
    settings.beginGroup(QStringLiteral("Station"));
    m_callsign = settings.value(QStringLiteral("Callsign"), QString()).toString();
    m_grid = settings.value(QStringLiteral("Grid"), QString()).toString();
    settings.endGroup();

    settings.beginGroup(QStringLiteral("Appearance"));
    m_darkMode = settings.value(QStringLiteral("DarkMode"), false).toBool();
    settings.endGroup();

    settings.beginGroup(QStringLiteral("Decoder"));
    m_ft8Sensitivity = settings.value(QStringLiteral("FT8Sensitivity"), 1).toInt();
    m_ft8Cycles = settings.value(QStringLiteral("FT8Cycles"), 3).toInt();
    m_ft8Threads = settings.value(QStringLiteral("FT8Threads"), 0).toInt();
    m_ft8DecoderStart = settings.value(QStringLiteral("FT8DecoderStart"), 3).toInt();
    m_ft4Depth = settings.value(QStringLiteral("FT4Depth"), 3).toInt();
    m_ntrials10 = settings.value(QStringLiteral("Ntrials10"), 3).toInt();
    m_multithreadFT8 = settings.value(QStringLiteral("MultithreadFT8"), false).toBool();
    m_hideFT8Dupes = settings.value(QStringLiteral("HideFT8Dupes"), false).toBool();
    m_wideDxCallSearch = settings.value(QStringLiteral("WideDxCallSearch"), false).toBool();
    settings.endGroup();

    settings.beginGroup(QStringLiteral("NTP"));
    m_ntpEnabled = settings.value(QStringLiteral("Enabled"), true).toBool();
    settings.endGroup();

    settings.beginGroup(QStringLiteral("PSKReporter"));
    m_pskReporterEnabled = settings.value(QStringLiteral("Enabled"), false).toBool();
    settings.endGroup();

    settings.beginGroup(QStringLiteral("Cloudlog"));
    m_cloudlogEnabled = settings.value(QStringLiteral("Enabled"), false).toBool();
    m_cloudlogUrl = settings.value(QStringLiteral("Url"), QString()).toString();
    m_cloudlogApiKey = settings.value(QStringLiteral("ApiKey"), QString()).toString();
    settings.endGroup();

    settings.beginGroup(QStringLiteral("Highlighting"));
    m_colorCQ = QColor(settings.value(QStringLiteral("ColorCQ"), m_colorCQ.name()).toString());
    m_colorMyCall = QColor(settings.value(QStringLiteral("ColorMyCall"), m_colorMyCall.name()).toString());
    m_colorDXEntity = QColor(settings.value(QStringLiteral("ColorDXEntity"), m_colorDXEntity.name()).toString());
    m_color73 = QColor(settings.value(QStringLiteral("Color73"), m_color73.name()).toString());
    m_colorB4 = QColor(settings.value(QStringLiteral("ColorB4"), m_colorB4.name()).toString());
    m_b4Strikethrough = settings.value(QStringLiteral("B4Strikethrough"), true).toBool();
    settings.endGroup();

    settings.beginGroup(QStringLiteral("Alerts"));
    m_alertSoundsEnabled = settings.value(QStringLiteral("Enabled"), false).toBool();
    settings.endGroup();
}

// ── cty.dat auto-update ──

void AppController::checkCtyDatUpdate()
{
    QString dataDir = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir().mkpath(dataDir);
    QString ctyPath = dataDir + QStringLiteral("/cty.dat");

    QFileInfo fi(ctyPath);
    if (fi.exists()) {
        // Check age: only update if older than 30 days
        qint64 ageDays = fi.lastModified().daysTo(QDateTime::currentDateTime());
        if (ageDays < 30) {
            qDebug() << "AppController: cty.dat is" << ageDays << "days old, no update needed";
            return;
        }
    }

    qDebug() << "AppController: downloading cty.dat update";
    m_ctyDatUpdating = true;
    emit ctyDatUpdatingChanged();

    QUrl url(QStringLiteral("https://www.country-files.com/bigcty/cty.dat"));
    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::UserAgentHeader, QStringLiteral("Decodium3/3.0"));

    QNetworkReply *reply = m_nam->get(req);
    connect(reply, &QNetworkReply::finished, this, [this, reply, ctyPath]() {
        reply->deleteLater();
        m_ctyDatUpdating = false;
        emit ctyDatUpdatingChanged();

        if (reply->error() != QNetworkReply::NoError) {
            qWarning() << "AppController: cty.dat download failed:" << reply->errorString();
            return;
        }

        QByteArray data = reply->readAll();
        if (data.size() < 1000) {
            qWarning() << "AppController: cty.dat too small, ignoring";
            return;
        }

        QFile file(ctyPath);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(data);
            file.close();
            qDebug() << "AppController: cty.dat updated," << data.size() << "bytes";
            emit ctyDatUpdated();
        }
    });
}

// ── Color highlighting setters ──

void AppController::setColorCQ(const QColor &c)
{
    if (m_colorCQ != c) { m_colorCQ = c; emit highlightColorsChanged(); saveSettings(); }
}
void AppController::setColorMyCall(const QColor &c)
{
    if (m_colorMyCall != c) { m_colorMyCall = c; emit highlightColorsChanged(); saveSettings(); }
}
void AppController::setColorDXEntity(const QColor &c)
{
    if (m_colorDXEntity != c) { m_colorDXEntity = c; emit highlightColorsChanged(); saveSettings(); }
}
void AppController::setColor73(const QColor &c)
{
    if (m_color73 != c) { m_color73 = c; emit highlightColorsChanged(); saveSettings(); }
}
void AppController::setColorB4(const QColor &c)
{
    if (m_colorB4 != c) { m_colorB4 = c; emit highlightColorsChanged(); saveSettings(); }
}
void AppController::setB4Strikethrough(bool v)
{
    if (m_b4Strikethrough != v) { m_b4Strikethrough = v; emit highlightColorsChanged(); saveSettings(); }
}

// ── Alert sounds ──

void AppController::setAlertSoundsEnabled(bool v)
{
    if (m_alertSoundsEnabled != v) { m_alertSoundsEnabled = v; emit alertSoundsEnabledChanged(); saveSettings(); }
}

void AppController::playAlert(const QString &alertType)
{
    if (!m_alertSoundsEnabled) return;

    // Lazy-init sound sources on first use
    if (m_alertCQ.source().isEmpty()) {
        m_alertCQ.setSource(QUrl(QStringLiteral("qrc:/sounds/CQ.wav")));
        m_alertCQ.setVolume(0.7f);
        m_alertMyCall.setSource(QUrl(QStringLiteral("qrc:/sounds/MyCall.wav")));
        m_alertMyCall.setVolume(1.0f);
    }

    if (alertType == QLatin1String("MyCall")) {
        m_alertMyCall.play();
    } else if (alertType == QLatin1String("CQ")) {
        m_alertCQ.play();
    }

    qDebug() << "AppController: alert sound:" << alertType;
}

// ── Update checker ──

void AppController::checkForUpdates()
{
    QUrl url(QStringLiteral("https://api.github.com/repos/iu8lmc/Decodium-3.0-Shannon/releases/latest"));
    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::UserAgentHeader, QStringLiteral("Decodium3/3.0"));
    req.setRawHeader("Accept", "application/vnd.github.v3+json");

    QNetworkReply *reply = m_nam->get(req);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qWarning() << "AppController: update check failed:" << reply->errorString();
            return;
        }

        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject obj = doc.object();
        QString tagName = obj.value(QStringLiteral("tag_name")).toString();

        if (!tagName.isEmpty() && tagName != QStringLiteral("v") + version()) {
            m_latestVersion = tagName;
            m_updateAvailable = true;
            emit latestVersionChanged();
            emit updateAvailableChanged();
            qDebug() << "AppController: update available:" << tagName;
        }
    });
}

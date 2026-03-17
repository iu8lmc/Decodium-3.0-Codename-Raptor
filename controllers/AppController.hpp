#ifndef APPCONTROLLER_HPP
#define APPCONTROLLER_HPP

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QColor>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSoundEffect>

class AppController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString version READ version CONSTANT)
    Q_PROPERTY(QString callsign READ callsign WRITE setCallsign NOTIFY callsignChanged)
    Q_PROPERTY(QString grid READ grid WRITE setGrid NOTIFY gridChanged)
    Q_PROPERTY(bool darkMode READ darkMode WRITE setDarkMode NOTIFY darkModeChanged)

    // Decoder tuning parameters
    Q_PROPERTY(int ft8Sensitivity READ ft8Sensitivity WRITE setFt8Sensitivity NOTIFY decoderSettingsChanged)
    Q_PROPERTY(int ft8Cycles READ ft8Cycles WRITE setFt8Cycles NOTIFY decoderSettingsChanged)
    Q_PROPERTY(int ft8Threads READ ft8Threads WRITE setFt8Threads NOTIFY decoderSettingsChanged)
    Q_PROPERTY(int ft8DecoderStart READ ft8DecoderStart WRITE setFt8DecoderStart NOTIFY decoderSettingsChanged)
    Q_PROPERTY(int ft4Depth READ ft4Depth WRITE setFt4Depth NOTIFY decoderSettingsChanged)
    Q_PROPERTY(int ntrials10 READ ntrials10 WRITE setNtrials10 NOTIFY decoderSettingsChanged)
    Q_PROPERTY(bool multithreadFT8 READ multithreadFT8 WRITE setMultithreadFT8 NOTIFY decoderSettingsChanged)
    Q_PROPERTY(bool hideFT8Dupes READ hideFT8Dupes WRITE setHideFT8Dupes NOTIFY decoderSettingsChanged)
    Q_PROPERTY(bool wideDxCallSearch READ wideDxCallSearch WRITE setWideDxCallSearch NOTIFY decoderSettingsChanged)

    // NTP
    Q_PROPERTY(bool ntpEnabled READ ntpEnabled WRITE setNtpEnabled NOTIFY ntpEnabledChanged)
    Q_PROPERTY(bool ntpSynced READ ntpSynced NOTIFY ntpSyncedChanged)
    Q_PROPERTY(double ntpOffsetMs READ ntpOffsetMs NOTIFY ntpOffsetMsChanged)

    // PSK Reporter
    Q_PROPERTY(bool pskReporterEnabled READ pskReporterEnabled WRITE setPskReporterEnabled NOTIFY pskReporterEnabledChanged)

    // Cloudlog
    Q_PROPERTY(bool cloudlogEnabled READ cloudlogEnabled WRITE setCloudlogEnabled NOTIFY cloudlogEnabledChanged)
    Q_PROPERTY(QString cloudlogUrl READ cloudlogUrl WRITE setCloudlogUrl NOTIFY cloudlogUrlChanged)
    Q_PROPERTY(QString cloudlogApiKey READ cloudlogApiKey WRITE setCloudlogApiKey NOTIFY cloudlogApiKeyChanged)

    // cty.dat auto-update
    Q_PROPERTY(bool ctyDatUpdating READ ctyDatUpdating NOTIFY ctyDatUpdatingChanged)

    // Color highlighting
    Q_PROPERTY(QColor colorCQ READ colorCQ WRITE setColorCQ NOTIFY highlightColorsChanged)
    Q_PROPERTY(QColor colorMyCall READ colorMyCall WRITE setColorMyCall NOTIFY highlightColorsChanged)
    Q_PROPERTY(QColor colorDXEntity READ colorDXEntity WRITE setColorDXEntity NOTIFY highlightColorsChanged)
    Q_PROPERTY(QColor color73 READ color73 WRITE setColor73 NOTIFY highlightColorsChanged)
    Q_PROPERTY(QColor colorB4 READ colorB4 WRITE setColorB4 NOTIFY highlightColorsChanged)
    Q_PROPERTY(bool b4Strikethrough READ b4Strikethrough WRITE setB4Strikethrough NOTIFY highlightColorsChanged)

    // Alert sounds
    Q_PROPERTY(bool alertSoundsEnabled READ alertSoundsEnabled WRITE setAlertSoundsEnabled NOTIFY alertSoundsEnabledChanged)

    // Update checker
    Q_PROPERTY(bool updateAvailable READ updateAvailable NOTIFY updateAvailableChanged)
    Q_PROPERTY(QString latestVersion READ latestVersion NOTIFY latestVersionChanged)

public:
    explicit AppController(QObject *parent = nullptr);
    ~AppController() override = default;

    QString version() const { return QStringLiteral("3.0.0"); }

    QString callsign() const;
    void setCallsign(const QString &call);

    QString grid() const;
    void setGrid(const QString &grid);

    bool darkMode() const;
    void setDarkMode(bool dark);

    // Decoder tuning
    int ft8Sensitivity() const { return m_ft8Sensitivity; }
    void setFt8Sensitivity(int v);
    int ft8Cycles() const { return m_ft8Cycles; }
    void setFt8Cycles(int v);
    int ft8Threads() const { return m_ft8Threads; }
    void setFt8Threads(int v);
    int ft8DecoderStart() const { return m_ft8DecoderStart; }
    void setFt8DecoderStart(int v);
    int ft4Depth() const { return m_ft4Depth; }
    void setFt4Depth(int v);
    int ntrials10() const { return m_ntrials10; }
    void setNtrials10(int v);
    bool multithreadFT8() const { return m_multithreadFT8; }
    void setMultithreadFT8(bool v);
    bool hideFT8Dupes() const { return m_hideFT8Dupes; }
    void setHideFT8Dupes(bool v);
    bool wideDxCallSearch() const { return m_wideDxCallSearch; }
    void setWideDxCallSearch(bool v);

    // NTP
    bool ntpEnabled() const { return m_ntpEnabled; }
    void setNtpEnabled(bool v);
    bool ntpSynced() const { return m_ntpSynced; }
    void setNtpSynced(bool v);
    double ntpOffsetMs() const { return m_ntpOffsetMs; }
    void setNtpOffsetMs(double v);

    // PSK Reporter
    bool pskReporterEnabled() const { return m_pskReporterEnabled; }
    void setPskReporterEnabled(bool v);

    // Cloudlog
    bool cloudlogEnabled() const { return m_cloudlogEnabled; }
    void setCloudlogEnabled(bool v);
    QString cloudlogUrl() const { return m_cloudlogUrl; }
    void setCloudlogUrl(const QString &v);
    QString cloudlogApiKey() const { return m_cloudlogApiKey; }
    void setCloudlogApiKey(const QString &v);

    // cty.dat auto-update
    bool ctyDatUpdating() const { return m_ctyDatUpdating; }
    Q_INVOKABLE void checkCtyDatUpdate();

    // Color highlighting
    QColor colorCQ() const { return m_colorCQ; }
    void setColorCQ(const QColor &c);
    QColor colorMyCall() const { return m_colorMyCall; }
    void setColorMyCall(const QColor &c);
    QColor colorDXEntity() const { return m_colorDXEntity; }
    void setColorDXEntity(const QColor &c);
    QColor color73() const { return m_color73; }
    void setColor73(const QColor &c);
    QColor colorB4() const { return m_colorB4; }
    void setColorB4(const QColor &c);
    bool b4Strikethrough() const { return m_b4Strikethrough; }
    void setB4Strikethrough(bool v);

    // Alert sounds
    bool alertSoundsEnabled() const { return m_alertSoundsEnabled; }
    void setAlertSoundsEnabled(bool v);
    Q_INVOKABLE void playAlert(const QString &alertType);

    // Update checker
    bool updateAvailable() const { return m_updateAvailable; }
    QString latestVersion() const { return m_latestVersion; }
    Q_INVOKABLE void checkForUpdates();

    Q_INVOKABLE void saveSettings();
    Q_INVOKABLE void loadSettings();

signals:
    void callsignChanged();
    void gridChanged();
    void darkModeChanged();
    void decoderSettingsChanged();
    void ntpEnabledChanged();
    void ntpSyncedChanged();
    void ntpOffsetMsChanged();
    void pskReporterEnabledChanged();
    void cloudlogEnabledChanged();
    void cloudlogUrlChanged();
    void cloudlogApiKeyChanged();
    void ctyDatUpdatingChanged();
    void ctyDatUpdated();
    void highlightColorsChanged();
    void alertSoundsEnabledChanged();
    void updateAvailableChanged();
    void latestVersionChanged();

private:
    QString m_callsign;
    QString m_grid;
    bool m_darkMode = false;

    // Decoder tuning
    int m_ft8Sensitivity = 1;    // 0=low, 1=normal, 2=high
    int m_ft8Cycles = 3;         // 1-3
    int m_ft8Threads = 0;        // 0=auto, 1-12
    int m_ft8DecoderStart = 3;   // 1-5 seconds before period end
    int m_ft4Depth = 3;          // 1-3
    int m_ntrials10 = 3;
    bool m_multithreadFT8 = false;
    bool m_hideFT8Dupes = false;
    bool m_wideDxCallSearch = false;

    // NTP
    bool m_ntpEnabled = true;
    bool m_ntpSynced = false;
    double m_ntpOffsetMs = 0.0;

    // PSK Reporter
    bool m_pskReporterEnabled = false;

    // Cloudlog
    bool m_cloudlogEnabled = false;
    QString m_cloudlogUrl;
    QString m_cloudlogApiKey;

    // cty.dat
    QNetworkAccessManager *m_nam = nullptr;
    bool m_ctyDatUpdating = false;

    // Color highlighting
    QColor m_colorCQ = QColor(0, 128, 0);          // green
    QColor m_colorMyCall = QColor(255, 0, 0);       // red
    QColor m_colorDXEntity = QColor(255, 140, 0);   // dark orange
    QColor m_color73 = QColor(0, 100, 200);          // blue
    QColor m_colorB4 = QColor(160, 160, 160);        // grey
    bool m_b4Strikethrough = true;

    // Alert sounds
    bool m_alertSoundsEnabled = false;
    QSoundEffect m_alertCQ;
    QSoundEffect m_alertMyCall;

    // Update checker
    bool m_updateAvailable = false;
    QString m_latestVersion;
};

#endif // APPCONTROLLER_HPP

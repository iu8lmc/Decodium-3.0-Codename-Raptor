#ifndef LOGCONTROLLER_HPP
#define LOGCONTROLLER_HPP

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSet>

class LogController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int qsoCount READ qsoCount NOTIFY qsoCountChanged)
    Q_PROPERTY(QString lastLoggedCall READ lastLoggedCall NOTIFY lastLoggedCallChanged)
    Q_PROPERTY(QString lastLoggedGrid READ lastLoggedGrid NOTIFY lastLoggedGridChanged)
    Q_PROPERTY(QString lastLoggedTime READ lastLoggedTime NOTIFY lastLoggedTimeChanged)

    // LOTW integration
    Q_PROPERTY(bool lotwEnabled READ lotwEnabled WRITE setLotwEnabled NOTIFY lotwEnabledChanged)

    // Contest mode
    Q_PROPERTY(bool contestMode READ contestMode WRITE setContestMode NOTIFY contestModeChanged)
    Q_PROPERTY(QString contestName READ contestName WRITE setContestName NOTIFY contestNameChanged)

public:
    explicit LogController(QObject *parent = nullptr);
    ~LogController() override = default;

    int qsoCount() const;
    QString lastLoggedCall() const;
    QString lastLoggedGrid() const;
    QString lastLoggedTime() const;

    Q_INVOKABLE void logQSO(const QString &call, const QString &grid,
                             const QString &mode, const QString &rstSent,
                             const QString &rstRcvd, double freq);

    Q_INVOKABLE void logQSOFull(const QString &call, const QString &grid,
                                const QString &mode, const QString &rstSent,
                                const QString &rstRcvd, double freq,
                                const QString &comment, const QString &name);

    Q_INVOKABLE bool isCallWorked(const QString &call, const QString &band) const;
    Q_INVOKABLE bool isGridWorked(const QString &grid, const QString &band) const;

    // Cloudlog integration
    void setCloudlogEnabled(bool v) { m_cloudlogEnabled = v; }
    void setCloudlogUrl(const QString &v) { m_cloudlogUrl = v; }
    void setCloudlogApiKey(const QString &v) { m_cloudlogApiKey = v; }

    // LOTW integration
    bool lotwEnabled() const { return m_lotwEnabled; }
    void setLotwEnabled(bool v);
    Q_INVOKABLE void updateLotwUsers();
    Q_INVOKABLE bool isLotwUser(const QString &call) const;

    // Contest mode
    bool contestMode() const { return m_contestMode; }
    void setContestMode(bool v);
    QString contestName() const { return m_contestName; }
    void setContestName(const QString &n);
    Q_INVOKABLE void exportCabrillo(const QString &filename);

    // Reload country data after cty.dat update
    Q_INVOKABLE void reloadCtyDat();

    // Load existing ADIF for B4 tracking
    void loadAdifLog();

signals:
    void qsoCountChanged();
    void lastLoggedCallChanged();
    void lastLoggedGridChanged();
    void lastLoggedTimeChanged();
    void qsoLogged(const QString &call, const QString &grid, const QString &mode, double freq);
    void lotwEnabledChanged();
    void contestModeChanged();
    void contestNameChanged();

private:
    struct QSORecord {
        QDateTime dateTimeOn;
        QDateTime dateTimeOff;
        QString call;
        QString grid;
        QString mode;
        QString rstSent;
        QString rstRcvd;
        double frequency = 0.0;
        QString comment;
        QString name;
    };

    void writeAdifRecord(const QSORecord &qso);
    void uploadToCloudlog(const QSORecord &qso);

public:
    QString bandFromFrequency(double freqHz) const;

private:

    int m_qsoCount = 0;
    QString m_lastLoggedCall;
    QString m_lastLoggedGrid;
    QString m_lastLoggedTime;

    // In-memory log of worked calls/grids per band for quick lookups
    QMultiHash<QString, QString> m_workedCallsByBand;  // band -> call
    QMultiHash<QString, QString> m_workedGridsByBand;  // band -> grid

    // Cloudlog
    bool m_cloudlogEnabled = false;
    QString m_cloudlogUrl;
    QString m_cloudlogApiKey;
    QNetworkAccessManager *m_nam = nullptr;

    // LOTW
    bool m_lotwEnabled = false;
    QSet<QString> m_lotwUsers;

    // Contest
    bool m_contestMode = false;
    QString m_contestName;
};

#endif // LOGCONTROLLER_HPP

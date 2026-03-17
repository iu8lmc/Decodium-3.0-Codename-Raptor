#ifndef RADIOCONTROLLER_HPP
#define RADIOCONTROLLER_HPP

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QHash>
#include <QMap>

class RadioController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(double dialFrequency READ dialFrequency WRITE setDialFrequency NOTIFY dialFrequencyChanged)
    Q_PROPERTY(QString mode READ mode WRITE setMode NOTIFY modeChanged)
    Q_PROPERTY(QString band READ band WRITE setBand NOTIFY bandChanged)
    Q_PROPERTY(QString submode READ submode WRITE setSubmode NOTIFY submodeChanged)
    Q_PROPERTY(bool split READ split WRITE setSplit NOTIFY splitChanged)
    Q_PROPERTY(bool tuning READ tuning NOTIFY tuningChanged)
    Q_PROPERTY(QString frequencyDisplay READ frequencyDisplay NOTIFY dialFrequencyChanged)

public:
    explicit RadioController(QObject *parent = nullptr);
    ~RadioController() override = default;

    double dialFrequency() const;
    void setDialFrequency(double freq);

    QString mode() const;
    void setMode(const QString &mode);

    QString band() const;
    void setBand(const QString &band);

    QString submode() const;
    void setSubmode(const QString &sub);

    bool split() const;
    void setSplit(bool on);

    bool tuning() const;

    QString frequencyDisplay() const;

    Q_INVOKABLE void tune(bool on);
    Q_INVOKABLE QStringList availableBands() const;
    Q_INVOKABLE QStringList availableModes() const;
    Q_INVOKABLE double defaultFrequencyForBand(const QString &band, const QString &mode) const;
    Q_INVOKABLE double trPeriod() const;

signals:
    void dialFrequencyChanged();
    void modeChanged();
    void bandChanged();
    void submodeChanged();
    void splitChanged();
    void tuningChanged();

private:
    void initFrequencyMaps();
    QString bandFromFrequency(double freq) const;

    double m_dialFrequency = 14074000.0;
    QString m_mode = QStringLiteral("FT8");
    QString m_band = QStringLiteral("20m");
    QString m_submode;
    bool m_split = false;
    bool m_tuning = false;

    // Band -> Frequency maps per mode
    QMap<QString, double> m_ft8Freqs;
    QMap<QString, double> m_ft4Freqs;
    QMap<QString, double> m_ft2Freqs;
    QMap<QString, double> m_jt65Freqs;
    QMap<QString, double> m_jt9Freqs;
    QMap<QString, double> m_wsprFreqs;

    // Band boundaries for lookup
    struct BandLimits {
        double lower;
        double upper;
        QString name;
    };
    QList<BandLimits> m_bandLimits;
};

#endif // RADIOCONTROLLER_HPP

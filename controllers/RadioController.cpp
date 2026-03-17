#include "RadioController.hpp"
#include <QLocale>
#include <QtMath>

RadioController::RadioController(QObject *parent)
    : QObject(parent)
{
    initFrequencyMaps();
}

void RadioController::initFrequencyMaps()
{
    // FT8 standard dial frequencies
    m_ft8Freqs[QStringLiteral("160m")] = 1840000;
    m_ft8Freqs[QStringLiteral("80m")]  = 3573000;
    m_ft8Freqs[QStringLiteral("60m")]  = 5357000;
    m_ft8Freqs[QStringLiteral("40m")]  = 7074000;
    m_ft8Freqs[QStringLiteral("30m")]  = 10136000;
    m_ft8Freqs[QStringLiteral("20m")]  = 14074000;
    m_ft8Freqs[QStringLiteral("17m")]  = 18100000;
    m_ft8Freqs[QStringLiteral("15m")]  = 21074000;
    m_ft8Freqs[QStringLiteral("12m")]  = 24915000;
    m_ft8Freqs[QStringLiteral("10m")]  = 28074000;
    m_ft8Freqs[QStringLiteral("6m")]   = 50313000;
    m_ft8Freqs[QStringLiteral("2m")]   = 144174000;
    m_ft8Freqs[QStringLiteral("70cm")] = 432174000;

    // FT4 standard dial frequencies
    m_ft4Freqs[QStringLiteral("160m")] = 1840000;
    m_ft4Freqs[QStringLiteral("80m")]  = 3575000;
    m_ft4Freqs[QStringLiteral("60m")]  = 5357000;
    m_ft4Freqs[QStringLiteral("40m")]  = 7047500;
    m_ft4Freqs[QStringLiteral("30m")]  = 10140000;
    m_ft4Freqs[QStringLiteral("20m")]  = 14080000;
    m_ft4Freqs[QStringLiteral("17m")]  = 18104000;
    m_ft4Freqs[QStringLiteral("15m")]  = 21140000;
    m_ft4Freqs[QStringLiteral("12m")]  = 24919000;
    m_ft4Freqs[QStringLiteral("10m")]  = 28180000;
    m_ft4Freqs[QStringLiteral("6m")]   = 50318000;
    m_ft4Freqs[QStringLiteral("2m")]   = 144170000;
    m_ft4Freqs[QStringLiteral("70cm")] = 432170000;

    // FT2 dial frequencies
    m_ft2Freqs[QStringLiteral("160m")] = 1842000;
    m_ft2Freqs[QStringLiteral("80m")]  = 3574500;
    m_ft2Freqs[QStringLiteral("60m")]  = 5358000;
    m_ft2Freqs[QStringLiteral("40m")]  = 7075500;
    m_ft2Freqs[QStringLiteral("30m")]  = 10134500;
    m_ft2Freqs[QStringLiteral("20m")]  = 14075500;
    m_ft2Freqs[QStringLiteral("17m")]  = 18105500;
    m_ft2Freqs[QStringLiteral("15m")]  = 21075500;
    m_ft2Freqs[QStringLiteral("12m")]  = 24917500;
    m_ft2Freqs[QStringLiteral("10m")]  = 28075500;
    m_ft2Freqs[QStringLiteral("6m")]   = 50314500;
    m_ft2Freqs[QStringLiteral("2m")]   = 144175500;
    m_ft2Freqs[QStringLiteral("70cm")] = 432176500;

    // JT65 standard dial frequencies
    m_jt65Freqs[QStringLiteral("160m")] = 1838000;
    m_jt65Freqs[QStringLiteral("80m")]  = 3570000;
    m_jt65Freqs[QStringLiteral("40m")]  = 7076000;
    m_jt65Freqs[QStringLiteral("30m")]  = 10138000;
    m_jt65Freqs[QStringLiteral("20m")]  = 14076000;
    m_jt65Freqs[QStringLiteral("17m")]  = 18102000;
    m_jt65Freqs[QStringLiteral("15m")]  = 21076000;
    m_jt65Freqs[QStringLiteral("12m")]  = 24917000;
    m_jt65Freqs[QStringLiteral("10m")]  = 28076000;
    m_jt65Freqs[QStringLiteral("6m")]   = 50276000;
    m_jt65Freqs[QStringLiteral("2m")]   = 144116000;

    // JT9 standard dial frequencies
    m_jt9Freqs[QStringLiteral("160m")] = 1839000;
    m_jt9Freqs[QStringLiteral("80m")]  = 3572000;
    m_jt9Freqs[QStringLiteral("40m")]  = 7078000;
    m_jt9Freqs[QStringLiteral("30m")]  = 10138000;
    m_jt9Freqs[QStringLiteral("20m")]  = 14078000;
    m_jt9Freqs[QStringLiteral("17m")]  = 18104000;
    m_jt9Freqs[QStringLiteral("15m")]  = 21078000;
    m_jt9Freqs[QStringLiteral("12m")]  = 24919000;
    m_jt9Freqs[QStringLiteral("10m")]  = 28078000;
    m_jt9Freqs[QStringLiteral("6m")]   = 50312000;

    // WSPR standard dial frequencies
    m_wsprFreqs[QStringLiteral("160m")] = 1836600;
    m_wsprFreqs[QStringLiteral("80m")]  = 3568600;
    m_wsprFreqs[QStringLiteral("60m")]  = 5287200;
    m_wsprFreqs[QStringLiteral("40m")]  = 7038600;
    m_wsprFreqs[QStringLiteral("30m")]  = 10138700;
    m_wsprFreqs[QStringLiteral("20m")]  = 14095600;
    m_wsprFreqs[QStringLiteral("17m")]  = 18104600;
    m_wsprFreqs[QStringLiteral("15m")]  = 21094600;
    m_wsprFreqs[QStringLiteral("12m")]  = 24924600;
    m_wsprFreqs[QStringLiteral("10m")]  = 28124600;
    m_wsprFreqs[QStringLiteral("6m")]   = 50293000;
    m_wsprFreqs[QStringLiteral("2m")]   = 144489000;

    // Band boundaries
    m_bandLimits = {
        {1800000,    2000000,    QStringLiteral("160m")},
        {3500000,    4000000,    QStringLiteral("80m")},
        {5330500,    5406400,    QStringLiteral("60m")},
        {7000000,    7300000,    QStringLiteral("40m")},
        {10100000,   10150000,   QStringLiteral("30m")},
        {14000000,   14350000,   QStringLiteral("20m")},
        {18068000,   18168000,   QStringLiteral("17m")},
        {21000000,   21450000,   QStringLiteral("15m")},
        {24890000,   24990000,   QStringLiteral("12m")},
        {28000000,   29700000,   QStringLiteral("10m")},
        {50000000,   54000000,   QStringLiteral("6m")},
        {144000000,  148000000,  QStringLiteral("2m")},
        {420000000,  450000000,  QStringLiteral("70cm")},
    };
}

double RadioController::dialFrequency() const
{
    return m_dialFrequency;
}

void RadioController::setDialFrequency(double freq)
{
    if (!qFuzzyCompare(m_dialFrequency, freq)) {
        m_dialFrequency = freq;
        emit dialFrequencyChanged();

        // Update band based on new frequency
        QString newBand = bandFromFrequency(freq);
        if (!newBand.isEmpty() && newBand != m_band) {
            m_band = newBand;
            emit bandChanged();
        }
    }
}

QString RadioController::mode() const
{
    return m_mode;
}

void RadioController::setMode(const QString &mode)
{
    QString upper = mode.toUpper().trimmed();
    if (m_mode != upper) {
        m_mode = upper;
        emit modeChanged();

        // When mode changes, update the dial frequency for the current band
        double newFreq = defaultFrequencyForBand(m_band, m_mode);
        if (newFreq > 0 && !qFuzzyCompare(newFreq, m_dialFrequency)) {
            m_dialFrequency = newFreq;
            emit dialFrequencyChanged();
        }
    }
}

QString RadioController::band() const
{
    return m_band;
}

void RadioController::setBand(const QString &band)
{
    if (m_band != band) {
        m_band = band;
        emit bandChanged();

        // Update dial frequency for the new band in the current mode
        double newFreq = defaultFrequencyForBand(band, m_mode);
        if (newFreq > 0) {
            m_dialFrequency = newFreq;
            emit dialFrequencyChanged();
        }
    }
}

QString RadioController::submode() const
{
    return m_submode;
}

void RadioController::setSubmode(const QString &sub)
{
    if (m_submode != sub) {
        m_submode = sub;
        emit submodeChanged();
    }
}

bool RadioController::split() const
{
    return m_split;
}

void RadioController::setSplit(bool on)
{
    if (m_split != on) {
        m_split = on;
        emit splitChanged();
    }
}

bool RadioController::tuning() const
{
    return m_tuning;
}

QString RadioController::frequencyDisplay() const
{
    // Format as MHz with decimals, e.g. "14.074 000"
    double mhz = m_dialFrequency / 1000000.0;
    int wholeMhz = static_cast<int>(mhz);
    int khzPart = static_cast<int>(m_dialFrequency) % 1000000;

    // Format: XX.XXX XXX
    QString khzStr = QStringLiteral("%1").arg(khzPart, 6, 10, QLatin1Char('0'));
    return QStringLiteral("%1.%2 %3")
        .arg(wholeMhz)
        .arg(khzStr.left(3))
        .arg(khzStr.mid(3));
}

void RadioController::tune(bool on)
{
    if (m_tuning != on) {
        m_tuning = on;
        emit tuningChanged();
    }
}

QStringList RadioController::availableBands() const
{
    return {
        QStringLiteral("160m"), QStringLiteral("80m"), QStringLiteral("60m"),
        QStringLiteral("40m"), QStringLiteral("30m"), QStringLiteral("20m"),
        QStringLiteral("17m"), QStringLiteral("15m"), QStringLiteral("12m"),
        QStringLiteral("10m"), QStringLiteral("6m"), QStringLiteral("2m"),
        QStringLiteral("70cm")
    };
}

QStringList RadioController::availableModes() const
{
    return {
        QStringLiteral("FT8"), QStringLiteral("FT4"), QStringLiteral("FT2"),
        QStringLiteral("JT65"), QStringLiteral("JT9"), QStringLiteral("WSPR")
    };
}

double RadioController::defaultFrequencyForBand(const QString &band, const QString &mode) const
{
    const QMap<QString, double> *freqMap = nullptr;

    if (mode == QLatin1String("FT8"))
        freqMap = &m_ft8Freqs;
    else if (mode == QLatin1String("FT4"))
        freqMap = &m_ft4Freqs;
    else if (mode == QLatin1String("FT2"))
        freqMap = &m_ft2Freqs;
    else if (mode == QLatin1String("JT65"))
        freqMap = &m_jt65Freqs;
    else if (mode == QLatin1String("JT9"))
        freqMap = &m_jt9Freqs;
    else if (mode == QLatin1String("WSPR"))
        freqMap = &m_wsprFreqs;

    if (freqMap && freqMap->contains(band)) {
        return freqMap->value(band);
    }

    // Fallback: try FT8 frequencies
    if (m_ft8Freqs.contains(band)) {
        return m_ft8Freqs.value(band);
    }

    return 0.0;
}

double RadioController::trPeriod() const
{
    if (m_mode == QLatin1String("FT8"))  return 15.0;
    if (m_mode == QLatin1String("FT4"))  return 7.5;
    if (m_mode == QLatin1String("FT2"))  return 3.75;
    if (m_mode == QLatin1String("JT65")) return 60.0;
    if (m_mode == QLatin1String("JT9"))  return 60.0;
    if (m_mode == QLatin1String("WSPR")) return 120.0;
    return 15.0;
}

QString RadioController::bandFromFrequency(double freq) const
{
    for (const auto &bl : m_bandLimits) {
        if (freq >= bl.lower && freq <= bl.upper) {
            return bl.name;
        }
    }
    return QString();
}

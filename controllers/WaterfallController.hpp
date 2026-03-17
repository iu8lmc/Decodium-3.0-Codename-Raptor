#ifndef WATERFALLCONTROLLER_HPP
#define WATERFALLCONTROLLER_HPP

#include <QObject>
#include <QQmlEngine>
#include <QVariantList>

class WaterfallController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int rxFreq READ rxFreq WRITE setRxFreq NOTIFY rxFreqChanged)
    Q_PROPERTY(int txFreq READ txFreq WRITE setTxFreq NOTIFY txFreqChanged)
    Q_PROPERTY(int startFreq READ startFreq WRITE setStartFreq NOTIFY startFreqChanged)
    Q_PROPERTY(int bandwidth READ bandwidth WRITE setBandwidth NOTIFY bandwidthChanged)
    Q_PROPERTY(int gain READ gain WRITE setGain NOTIFY gainChanged)
    Q_PROPERTY(int zero READ zero WRITE setZero NOTIFY zeroChanged)
    Q_PROPERTY(bool splitEnabled READ splitEnabled WRITE setSplitEnabled NOTIFY splitEnabledChanged)
    Q_PROPERTY(int nBins READ nBins NOTIFY nBinsChanged)

    // Fox mode markers & TX brackets
    Q_PROPERTY(QVariantList foxSlotMarkers READ foxSlotMarkers NOTIFY foxSlotMarkersChanged)
    Q_PROPERTY(bool showTxBrackets READ showTxBrackets WRITE setShowTxBrackets NOTIFY showTxBracketsChanged)

public:
    explicit WaterfallController(QObject *parent = nullptr);
    ~WaterfallController() override = default;

    int rxFreq() const;
    void setRxFreq(int freq);

    int txFreq() const;
    void setTxFreq(int freq);

    int startFreq() const;
    void setStartFreq(int freq);

    int bandwidth() const;
    void setBandwidth(int bw);

    int gain() const;
    void setGain(int g);

    int zero() const;
    void setZero(int z);

    bool splitEnabled() const;
    void setSplitEnabled(bool on);

    int nBins() const;

    Q_INVOKABLE void setFrequenciesLocked(bool locked);
    Q_INVOKABLE void centerOnRxFreq();

    QVariantList foxSlotMarkers() const { return m_foxSlotMarkers; }
    void setFoxSlotMarkers(const QVariantList &markers);
    bool showTxBrackets() const { return m_showTxBrackets; }
    void setShowTxBrackets(bool v);

    // Update Fox slot markers based on Fox mode TX frequency and slot count
    Q_INVOKABLE void updateFoxMarkers(int baseFreq, int nSlots, int spacing = 200);

signals:
    void rxFreqChanged();
    void txFreqChanged();
    void startFreqChanged();
    void bandwidthChanged();
    void gainChanged();
    void zeroChanged();
    void splitEnabledChanged();
    void nBinsChanged();
    void spectrumDataReady(const QList<float> &data);
    void foxSlotMarkersChanged();
    void showTxBracketsChanged();

public slots:
    void onSpectrumData(const QList<float> &bins);

private:
    int clampFreq(int freq) const;

    int m_rxFreq = 1500;
    int m_txFreq = 1500;
    int m_startFreq = 200;
    int m_bandwidth = 5000;
    int m_gain = 50;
    int m_zero = 50;
    bool m_splitEnabled = false;
    bool m_freqsLocked = true;
    int m_nBins = 0;

    // Fox mode
    QVariantList m_foxSlotMarkers;
    bool m_showTxBrackets = true;
};

#endif // WATERFALLCONTROLLER_HPP

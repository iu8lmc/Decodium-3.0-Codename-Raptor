#ifndef RFANALYZERWIDGET_H
#define RFANALYZERWIDGET_H

#include <QWidget>
#include <QVariantList>
#include <QVector>

class QSettings;
class QQuickWidget;

// ── C++ backend exposed to QML ──────────────────────────────
class RFAnalyzerBackend : public QObject
{
  Q_OBJECT

  // Spectrum data (float arrays as QVariantList for QML)
  Q_PROPERTY (QVariantList spectrumData READ spectrumData NOTIFY dataChanged)
  Q_PROPERTY (int    spectrumSize READ spectrumSize NOTIFY dataChanged)
  Q_PROPERTY (float  df           READ df           NOTIFY dataChanged)
  Q_PROPERTY (float  maxDB        READ maxDB        NOTIFY dataChanged)
  Q_PROPERTY (float  noiseFloor   READ noiseFloor   NOTIFY dataChanged)
  Q_PROPERTY (float  peakDB       READ peakDB       NOTIFY dataChanged)
  Q_PROPERTY (float  snr          READ snr          NOTIFY dataChanged)
  Q_PROPERTY (float  rmsDB        READ rmsDB        NOTIFY dataChanged)
  Q_PROPERTY (int    zeroCrossRate READ zeroCrossRate NOTIFY dataChanged)
  Q_PROPERTY (float  peakFreq     READ peakFreq     NOTIFY dataChanged)
  Q_PROPERTY (float  peakLevel    READ peakLevel    NOTIFY dataChanged)

  // Waveform data
  Q_PROPERTY (QVariantList waveformData READ waveformData NOTIFY dataChanged)
  Q_PROPERTY (float  waveRms      READ waveRms      NOTIFY dataChanged)

  // Timing
  Q_PROPERTY (float  trPeriod     READ trPeriod     NOTIFY dataChanged)
  Q_PROPERTY (float  elapsed      READ elapsed      NOTIFY dataChanged)

  // Settings
  Q_PROPERTY (float  refDB        READ refDB   WRITE setRefDB   NOTIFY settingsChanged)
  Q_PROPERTY (float  rangeDB      READ rangeDB WRITE setRangeDB NOTIFY settingsChanged)
  Q_PROPERTY (QString mode        READ mode    WRITE setMode    NOTIFY settingsChanged)

public:
  explicit RFAnalyzerBackend (QObject *p = nullptr);

  void feedData (float const *spectrum, int nBins, float df3,
                 short const *timeSamples, int nSamples,
                 float trPeriod, float elapsed);

  // Property getters
  QVariantList spectrumData () const { return m_specData; }
  int    spectrumSize () const { return m_nBins; }
  float  df ()          const { return m_df; }
  float  maxDB ()       const { return m_maxDB; }
  float  noiseFloor ()  const { return m_noiseFloor; }
  float  peakDB ()      const { return m_peakDB; }
  float  snr ()         const { return m_snr; }
  float  rmsDB ()       const { return m_rmsDB; }
  int    zeroCrossRate () const { return m_zcRate; }
  float  peakFreq ()    const { return m_peakFreq; }
  float  peakLevel ()   const { return m_peakLevel; }
  QVariantList waveformData () const { return m_waveData; }
  float  waveRms ()     const { return m_waveRms; }
  float  trPeriod ()    const { return m_trPeriod; }
  float  elapsed ()     const { return m_elapsed; }
  float  refDB ()       const { return m_refDB; }
  float  rangeDB ()     const { return m_rangeDB; }
  QString mode ()       const { return m_mode; }

  void setRefDB (float v)   { m_refDB = v; emit settingsChanged (); }
  void setRangeDB (float v) { m_rangeDB = v; emit settingsChanged (); }
  void setMode (QString v)  { m_mode = v; emit settingsChanged (); }

  Q_INVOKABLE void resetPeak () { m_peakDB = -200; }

  // Waterfall: returns color for bin at normalized position
  Q_INVOKABLE QVariantList getWaterfallRow () const { return m_wfRow; }

signals:
  void dataChanged ();
  void settingsChanged ();

private:
  QVariantList m_specData;
  QVariantList m_waveData;
  QVariantList m_wfRow;      // latest waterfall row (RGB values)
  int   m_nBins {0};
  float m_df {0};
  float m_maxDB {-200}, m_noiseFloor {-120}, m_peakDB {-200};
  float m_snr {0}, m_rmsDB {-200};
  int   m_zcRate {0};
  float m_peakFreq {0}, m_peakLevel {-200};
  float m_waveRms {0};
  float m_trPeriod {0}, m_elapsed {0};
  float m_refDB {-30}, m_rangeDB {80};
  QString m_mode {"FT8"};

  int m_frameSkip {0};  // throttle updates
};

// ── Main widget wrapping QQuickWidget ───────────────────────
class RFAnalyzerWidget : public QWidget
{
  Q_OBJECT
public:
  explicit RFAnalyzerWidget (QSettings *settings, QWidget *parent = nullptr);
  ~RFAnalyzerWidget () override;

  void updateData (float const *spectrum, float df3, int ihsym, float pdB,
                   short const *timeSamples, int nSamples,
                   float trPeriod, float elapsed);

  void saveSettings ();
  void restoreSettings ();

private:
  QSettings          *m_settings;
  QQuickWidget       *m_quickWidget;
  RFAnalyzerBackend  *m_backend;
};

#endif // RFANALYZERWIDGET_H

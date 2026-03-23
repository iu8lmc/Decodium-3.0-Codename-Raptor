#include "RFAnalyzerWidget.h"

#include <QVBoxLayout>
#include <QQuickWidget>
#include <QQmlContext>
#include <QSettings>
#include <QUrl>
#include <QQmlError>
#include <QtMath>
#include <algorithm>
#include <QDebug>

// ═════════════════════════════════════════════════════════════
//  RFAnalyzerBackend
// ═════════════════════════════════════════════════════════════
RFAnalyzerBackend::RFAnalyzerBackend (QObject *p) : QObject (p) {}

void RFAnalyzerBackend::feedData (float const *spectrum, int nBins, float df3,
                                   short const *timeSamples, int nSamples,
                                   float trPeriod, float elapsed)
{
  // Throttle to ~12 FPS
  if (++m_frameSkip < 3) return;
  m_frameSkip = 0;

  m_nBins = nBins;
  m_df = df3;
  m_trPeriod = trPeriod;
  m_elapsed = elapsed;

  // ── Spectrum: subsample to max 500 bins for QML ───────────
  int step = qMax (1, nBins / 500);
  int outN = nBins / step;
  m_specData.clear ();
  m_specData.reserve (outN);

  float maxDB = -200;
  int maxIdx = 0;
  QVector<float> sorted;
  sorted.reserve (outN);

  for (int i = 0; i < nBins; i += step) {
    float db = spectrum[i];
    m_specData.append (db);
    if (db > -10) continue;
    if (db > maxDB) { maxDB = db; maxIdx = i; }
    if (db > -200) sorted.append (db);
  }

  std::sort (sorted.begin (), sorted.end ());
  m_noiseFloor = sorted.isEmpty () ? -120 : sorted[sorted.size () / 4];
  m_maxDB = maxDB;
  m_snr = maxDB - m_noiseFloor;
  if (maxDB > m_peakDB) m_peakDB = maxDB;
  m_peakFreq = maxIdx * df3;
  m_peakLevel = maxDB;

  // ── Waterfall row: pre-compute RGB for QML ────────────────
  m_wfRow.clear ();
  m_wfRow.reserve (outN * 3);
  float ref = m_refDB, range = m_rangeDB;
  for (int i = 0; i < nBins; i += step) {
    float t = qBound (0.0f, (spectrum[i] - (ref - range)) / range, 1.0f);
    int r, g, b;
    if (t < 0.25f)      { r=0; g=(int)(t/0.25f*80); b=g; }
    else if (t < 0.5f)  { float u=(t-0.25f)/0.25f; r=0; g=(int)(80+u*111); b=(int)(80+u*96); }
    else if (t < 0.75f) { float u=(t-0.5f)/0.25f; r=(int)(u*201); g=(int)(191-u*23); b=(int)(176-u*100); }
    else                 { float u=(t-0.75f)/0.25f; r=(int)(201+u*54); g=(int)(168+u*87); b=(int)(76+u*179); }
    m_wfRow.append (qBound (0, r, 255));
    m_wfRow.append (qBound (0, g, 255));
    m_wfRow.append (qBound (0, b, 255));
  }

  // ── Waveform: subsample to max 400 points ─────────────────
  int wStep = qMax (1, nSamples / 400);
  m_waveData.clear ();
  m_waveData.reserve (nSamples / wStep);
  double rmsSum = 0;
  int zc = 0;
  for (int i = 0; i < nSamples; i += wStep) {
    float v = timeSamples[i] / 32768.0f;
    m_waveData.append (v);
    rmsSum += v * v;
  }
  for (int i = 1; i < nSamples; ++i) {
    if ((timeSamples[i-1] < 0 && timeSamples[i] >= 0) || (timeSamples[i-1] >= 0 && timeSamples[i] < 0))
      zc++;
  }
  float rms = nSamples > 0 ? std::sqrt (rmsSum / (nSamples / wStep)) : 0;
  m_waveRms = rms;
  m_rmsDB = rms > 0 ? 20.0f * std::log10 (rms) : -200;
  m_zcRate = nSamples > 0 ? (int)(zc * 12000.0f / (2.0f * nSamples)) : 0;

  emit dataChanged ();
}

// ═════════════════════════════════════════════════════════════
//  RFAnalyzerWidget
// ═════════════════════════════════════════════════════════════
RFAnalyzerWidget::RFAnalyzerWidget (QSettings *settings, QWidget *parent)
  : QWidget (parent), m_settings (settings)
{
  m_backend = new RFAnalyzerBackend (this);

  auto *layout = new QVBoxLayout (this);
  layout->setContentsMargins (0, 0, 0, 0);

  m_quickWidget = new QQuickWidget (this);
  m_quickWidget->setResizeMode (QQuickWidget::SizeRootObjectToView);
  m_quickWidget->setClearColor (QColor (0x06, 0x0A, 0x16));

  // Expose backend to QML
  m_quickWidget->rootContext ()->setContextProperty ("analyzer", m_backend);

  // Load QML from resources
  m_quickWidget->setSource (QUrl ("qrc:/qml/RFAnalyzer.qml"));

  if (m_quickWidget->status () == QQuickWidget::Error) {
    for (auto const &e : m_quickWidget->errors ())
      qWarning () << "RFAnalyzer QML error:" << e.toString ();
  }

  layout->addWidget (m_quickWidget);
  restoreSettings ();
}

RFAnalyzerWidget::~RFAnalyzerWidget () { saveSettings (); }

void RFAnalyzerWidget::updateData (float const *spectrum, float df3, int /*ihsym*/, float /*pdB*/,
                                    short const *timeSamples, int nSamples,
                                    float trPeriod, float elapsed)
{
  if (!isVisible ()) return;
  int nBins = qMin ((int)(4000.0f / df3), 5000);
  if (nBins < 2) return;
  m_backend->feedData (spectrum, nBins, df3, timeSamples, nSamples, trPeriod, elapsed);
}

void RFAnalyzerWidget::saveSettings ()
{
  if (!m_settings) return;
  m_settings->beginGroup ("RFAnalyzer");
  m_settings->setValue ("refDB", m_backend->refDB ());
  m_settings->setValue ("rangeDB", m_backend->rangeDB ());
  m_settings->setValue ("mode", m_backend->mode ());
  m_settings->endGroup ();
}

void RFAnalyzerWidget::restoreSettings ()
{
  if (!m_settings) return;
  m_settings->beginGroup ("RFAnalyzer");
  m_backend->setRefDB (m_settings->value ("refDB", -30).toFloat ());
  m_backend->setRangeDB (m_settings->value ("rangeDB", 80).toFloat ());
  m_backend->setMode (m_settings->value ("mode", "FT8").toString ());
  m_settings->endGroup ();
}

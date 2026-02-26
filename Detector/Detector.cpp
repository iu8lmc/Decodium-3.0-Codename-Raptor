#include "Detector.hpp"
#include <QDateTime>
#include <QtAlgorithms>
#include <QDebug>
#include <math.h>
#include "commons.h"
#include "PrecisionTime.hpp"

#include "moc_Detector.cpp"

extern "C" {
  void   fil4_(qint16*, qint32*, qint16*, qint32*);
}

extern dec_data_t dec_data;

Detector::Detector (unsigned frameRate, double periodLengthInSeconds,
                    unsigned downSampleFactor, QObject * parent)
  : AudioDevice (parent)
  , m_frameRate (frameRate)
  , m_period (periodLengthInSeconds)
  , m_downSampleFactor (downSampleFactor)
  , m_samplesPerFFT {max_buffer_size}
  , m_buffer ((downSampleFactor > 1) ?
              new short [max_buffer_size * downSampleFactor] : nullptr)
  , m_bufferPos (0)
{
  clear ();
}

void Detector::setBlockSize (unsigned n)
{
  m_samplesPerFFT = n;
}

bool Detector::reset ()
{
  clear ();
  // don't call base class reset because it calls seek(0) which causes
  // a warning
  return isOpen ();
}

void Detector::clear ()
{
  // set index to roughly where we are in time (1ms resolution)
  // qint64 now (QDateTime::currentMSecsSinceEpoch ());
  // unsigned msInPeriod ((now % 86400000LL) % (m_period * 1000));
  // dec_data.params.kin = qMin ((msInPeriod * m_frameRate) / 1000, static_cast<unsigned> (sizeof (dec_data.d2) / sizeof (dec_data.d2[0])));
  dec_data.params.kin = 0;
  m_bufferPos = 0;

  // fill buffer with zeros (G4WJS commented out because it might cause decoder hangs)
  // qFill (dec_data.d2, dec_data.d2 + sizeof (dec_data.d2) / sizeof (dec_data.d2[0]), 0);
}

qint64 Detector::writeData (char const * data, qint64 maxSize)
{
  static unsigned mstr0=999999;

  // Use high-resolution timer (~1us on Windows) instead of QDateTime (~15ms)
  qint64 ms0 = preciseCurrentMSecsSinceEpoch() % 86400000;

  // No timing corrections applied to period boundary — stock WSJT-X behavior.
  // NTP offset and DT feedback are displayed in TimeSyncPanel for monitoring
  // but NOT injected here, because shifting the period boundary corrupts
  // the audio window and degrades decoder performance.
  unsigned mstr = ms0 % int(1000.0*m_period);

  if(mstr < mstr0) {
    // Flush any partial data in the intermediate downsample buffer before reset
    // This prevents losing up to 300ms of audio at period boundaries
    if (m_downSampleFactor > 1 && m_bufferPos > 0) {
      qint32 fullBlock = m_samplesPerFFT * m_downSampleFactor;
      for (unsigned i = m_bufferPos; i < static_cast<unsigned>(fullBlock); ++i) {
        m_buffer[i] = 0;
      }
      qint32 framesToProcess = fullBlock;
      qint32 framesAfterDownSample = m_samplesPerFFT;
      if (dec_data.params.kin >= 0 &&
          dec_data.params.kin < (NTMAX*12000 - framesAfterDownSample)) {
        fil4_(&m_buffer[0], &framesToProcess, &dec_data.d2[dec_data.params.kin],
            &framesAfterDownSample);
        dec_data.params.kin += framesAfterDownSample;
        Q_EMIT framesWritten(dec_data.params.kin);
      }
    }
    dec_data.params.kin = 0;
    m_bufferPos = 0;
  }
  mstr0=mstr;

  // no torn frames
  Q_ASSERT (!(maxSize % static_cast<qint64> (bytesPerFrame ())));
  // these are in terms of input frames (not down sampled)
  size_t framesAcceptable ((sizeof (dec_data.d2) /
                            sizeof (dec_data.d2[0]) - dec_data.params.kin) * m_downSampleFactor);
  size_t framesAccepted (qMin (static_cast<size_t> (maxSize /
                                                    bytesPerFrame ()), framesAcceptable));

  // Soundcard clock drift measurement — informational only, displayed in TimeSyncPanel.
  // NOT used to modify period boundary detection.
  size_t framesDelivered = static_cast<size_t>(maxSize / bytesPerFrame());
  m_totalInputFrames += framesDelivered;
  qint64 ms0_raw = preciseCurrentMSecsSinceEpoch();
  if (m_driftStartMs == 0) {
    m_driftStartMs = ms0_raw;
    m_driftLastEmitMs = ms0_raw;
    m_totalInputFrames = framesDelivered;  // reset to just this batch
  } else {
    qint64 elapsedMs = ms0_raw - m_driftStartMs;
    if (elapsedMs >= 10000 && (ms0_raw - m_driftLastEmitMs) >= DRIFT_EMIT_INTERVAL_MS) {
      double elapsedSec = elapsedMs / 1000.0;
      double nominalInputRate = static_cast<double>(m_frameRate) * m_downSampleFactor;
      double actualRate = static_cast<double>(m_totalInputFrames) / elapsedSec;
      double ppm = (actualRate / nominalInputRate - 1.0) * 1e6;
      // Sanity gate: ignore wildly implausible values (startup transient, etc.)
      if (qAbs(ppm) < 500.0) {
        m_measuredDriftPpm = ppm;
        double driftMsPerPeriod = m_measuredDriftPpm * m_period / 1000.0;
        m_driftLastEmitMs = ms0_raw;
        Q_EMIT soundcardDriftUpdated(driftMsPerPeriod, m_measuredDriftPpm);
      }
    }
  }

  if (framesAccepted < static_cast<size_t> (maxSize / bytesPerFrame ())) {
    m_droppedFrames += (maxSize / bytesPerFrame () - framesAccepted);
    qDebug () << "dropped " << maxSize / bytesPerFrame () - framesAccepted
                << " frames of data on the floor!"
                << dec_data.params.kin << mstr;
    }

    for (unsigned remaining = framesAccepted; remaining; ) {
      size_t numFramesProcessed (qMin (m_samplesPerFFT *
                                       m_downSampleFactor - m_bufferPos, remaining));

      if(m_downSampleFactor > 1) {
        store (&data[(framesAccepted - remaining) * bytesPerFrame ()],
               numFramesProcessed, &m_buffer[m_bufferPos]);
        m_bufferPos += numFramesProcessed;

        if(m_bufferPos==m_samplesPerFFT*m_downSampleFactor) {
          qint32 framesToProcess (m_samplesPerFFT * m_downSampleFactor);
          qint32 framesAfterDownSample (m_samplesPerFFT);
          if(m_downSampleFactor > 1 && dec_data.params.kin>=0 &&
             dec_data.params.kin < (NTMAX*12000 - framesAfterDownSample)) {
            fil4_(&m_buffer[0], &framesToProcess, &dec_data.d2[dec_data.params.kin],
                &framesAfterDownSample);
            dec_data.params.kin += framesAfterDownSample;
          } else {
            // qDebug() << "framesToProcess     = " << framesToProcess;
            // qDebug() << "dec_data.params.kin = " << dec_data.params.kin;
            // qDebug() << "secondInPeriod      = " << secondInPeriod();
            // qDebug() << "framesAfterDownSample" << framesAfterDownSample;
          }
          Q_EMIT framesWritten (dec_data.params.kin);
          m_bufferPos = 0;
        }

      } else {
        store (&data[(framesAccepted - remaining) * bytesPerFrame ()],
               numFramesProcessed, &dec_data.d2[dec_data.params.kin]);
        m_bufferPos += numFramesProcessed;
        dec_data.params.kin += numFramesProcessed;
        if (m_bufferPos == static_cast<unsigned> (m_samplesPerFFT)) {
          Q_EMIT framesWritten (dec_data.params.kin);
          m_bufferPos = 0;
        }
      }
      remaining -= numFramesProcessed;
    }

    // we drop any data past the end of the buffer on the floor until
    // the next period starts
    return maxSize;
}

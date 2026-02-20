// -*- Mode: C++ -*-
#include "NtpClient.hpp"

#include <QDateTime>
#include <QNetworkDatagram>
#include <QNetworkRequest>
#include <QtEndian>
#include <algorithm>
#include <cmath>
#include <random>
#include <QLocale>

NtpClient::NtpClient(QObject *parent)
  : QObject(parent)
  , m_servers({
      // NTP Pool Project - global
      "0.pool.ntp.org",
      "1.pool.ntp.org",
      "2.pool.ntp.org",
      "3.pool.ntp.org",
      // NTP Pool - Europe
      "0.europe.pool.ntp.org",
      "1.europe.pool.ntp.org",
      "2.europe.pool.ntp.org",
      "3.europe.pool.ntp.org",
      // NIST (USA) - stratum 1
      "time.nist.gov",
      // Google Public NTP - stratum 1, smeared leap seconds
      "time.google.com",
      "time1.google.com",
      "time2.google.com",
      "time3.google.com",
      "time4.google.com",
      // Cloudflare NTP - anycast, low latency
      "time.cloudflare.com",
      // Apple NTP
      "time.apple.com",
      // Microsoft NTP
      "time.windows.com",
      // Facebook/Meta NTP - stratum 1
      "time.facebook.com",
      // European national institutes
      "ntp1.inrim.it",        // INRIM Italy - stratum 1 cesium
      "ntp2.inrim.it",        // INRIM Italy - stratum 1 cesium
      "ptbtime1.ptb.de",      // PTB Germany - stratum 1
      "ptbtime2.ptb.de",      // PTB Germany - stratum 1
      "ptbtime3.ptb.de",      // PTB Germany - stratum 1
      "ntp.ubuntu.com",       // Ubuntu/Canonical
    })
{
  m_refreshTimer.setInterval(REFRESH_INTERVAL_MS);
  connect(&m_refreshTimer, &QTimer::timeout, this, &NtpClient::onRefreshTimeout);

  m_queryTimeoutTimer.setInterval(QUERY_TIMEOUT_MS);
  m_queryTimeoutTimer.setSingleShot(true);
  connect(&m_queryTimeoutTimer, &QTimer::timeout, this, &NtpClient::onQueryTimeout);

  connect(&m_socket, &QUdpSocket::readyRead, this, &NtpClient::onReadyRead);

  // HTTP fallback network manager
  m_nam = new QNetworkAccessManager(this);
  connect(m_nam, &QNetworkAccessManager::finished, this, &NtpClient::onHttpReply);
}

NtpClient::~NtpClient()
{
  m_refreshTimer.stop();
  m_queryTimeoutTimer.stop();
  m_socket.close();
}

void NtpClient::setEnabled(bool enabled)
{
  m_enabled = enabled;
  if (enabled) {
    if (m_socket.state() == QAbstractSocket::UnconnectedState) {
      m_socket.bind();  // bind to any available port
    }
    syncNow();
    m_refreshTimer.start();
  } else {
    m_refreshTimer.stop();
    m_queryTimeoutTimer.stop();
    m_socket.close();
  }
}

void NtpClient::setInitialOffset(double offsetMs)
{
  m_offsetMs = offsetMs;
}

void NtpClient::syncNow()
{
  if (!m_enabled) return;

  m_pendingQueries.clear();
  m_collectedOffsets.clear();
  m_pendingDnsLookups = 0;

  // Select a random subset of servers (max 8) to avoid overloading
  QStringList selected = m_servers;
  std::random_device rd;
  std::mt19937 rng(rd());
  std::shuffle(selected.begin(), selected.end(), rng);
  int queryCount = qMin(selected.size(), SERVERS_PER_QUERY);

  // Start async DNS lookup for selected servers
  for (int i = 0; i < queryCount; ++i) {
    ++m_pendingDnsLookups;
    QHostInfo::lookupHost(selected[i], this, SLOT(onDnsLookupResult(QHostInfo)));
  }
}

void NtpClient::onDnsLookupResult(QHostInfo hostInfo)
{
  --m_pendingDnsLookups;

  if (hostInfo.error() != QHostInfo::NoError) {
    Q_EMIT errorOccurred(QString("DNS lookup failed for %1: %2")
                         .arg(hostInfo.hostName(), hostInfo.errorString()));
    return;
  }

  auto const addresses = hostInfo.addresses();
  if (!addresses.isEmpty()) {
    sendQuery(addresses.first());
    // Start timeout timer when first query is sent
    if (!m_queryTimeoutTimer.isActive()) {
      m_queryTimeoutTimer.start();
    }
  }
}

void NtpClient::sendQuery(QHostAddress const& address)
{
  QByteArray packet(NTP_PACKET_SIZE, '\0');
  packet[0] = 0x1B;  // LI=0, VN=3, Mode=3 (client)

  // Record T1 (client send time)
  qint64 t1Ms = QDateTime::currentDateTimeUtc().toMSecsSinceEpoch();

  // Write T1 into Originate Timestamp (bytes 24-31) for server echo
  quint32 t1Sec, t1Frac;
  msToNtpTimestamp(t1Ms, t1Sec, t1Frac);
  qToBigEndian(t1Sec, reinterpret_cast<uchar*>(packet.data() + 24));
  qToBigEndian(t1Frac, reinterpret_cast<uchar*>(packet.data() + 28));

  PendingQuery pq;
  pq.t1Ms = t1Ms;
  m_pendingQueries.insert(address.toString(), pq);

  m_socket.writeDatagram(packet, address, NTP_PORT);
}

void NtpClient::onReadyRead()
{
  while (m_socket.hasPendingDatagrams()) {
    QNetworkDatagram datagram = m_socket.receiveDatagram();
    QByteArray data = datagram.data();

    // Validate packet size
    if (data.size() < NTP_PACKET_SIZE) continue;

    // Record T4 (client receive time)
    qint64 t4Ms = QDateTime::currentDateTimeUtc().toMSecsSinceEpoch();

    QString senderKey = datagram.senderAddress().toString();
    if (!m_pendingQueries.contains(senderKey)) continue;

    qint64 t1Ms = m_pendingQueries.value(senderKey).t1Ms;
    m_pendingQueries.remove(senderKey);

    // Validate stratum (byte 1): must be 1-15
    quint8 stratum = static_cast<quint8>(data[1]);
    if (stratum == 0 || stratum > 15) continue;

    // Extract T2 (server receive timestamp, bytes 32-39)
    quint32 t2Sec = qFromBigEndian<quint32>(reinterpret_cast<const uchar*>(data.constData() + 32));
    quint32 t2Frac = qFromBigEndian<quint32>(reinterpret_cast<const uchar*>(data.constData() + 36));

    // Extract T3 (server transmit timestamp, bytes 40-47)
    quint32 t3Sec = qFromBigEndian<quint32>(reinterpret_cast<const uchar*>(data.constData() + 40));
    quint32 t3Frac = qFromBigEndian<quint32>(reinterpret_cast<const uchar*>(data.constData() + 44));

    double t2Ms = ntpTimestampToMs(t2Sec, t2Frac);
    double t3Ms = ntpTimestampToMs(t3Sec, t3Frac);

    // Calculate offset: ((T2-T1) + (T3-T4)) / 2
    double offset = ((t2Ms - t1Ms) + (t3Ms - t4Ms)) / 2.0;

    // Sanity gate: discard offsets > 1 hour
    if (std::abs(offset) > MAX_OFFSET_MS) continue;

    m_collectedOffsets.append(offset);

    // If all responses received, compute result immediately
    if (m_pendingQueries.isEmpty()) {
      m_queryTimeoutTimer.stop();
      onQueryTimeout();  // reuse the same finalization logic
    }
  }
}

void NtpClient::onRefreshTimeout()
{
  syncNow();
}

void NtpClient::onQueryTimeout()
{
  m_queryTimeoutTimer.stop();
  m_pendingQueries.clear();

  if (m_collectedOffsets.isEmpty()) {
    // NTP failed — track consecutive failures
    ++m_ntpConsecutiveFailures;

    if (!m_synced) {
      Q_EMIT syncStatusChanged(false, "NTP: no response from servers");
    }

    // Try HTTP time fallback when NTP fails
    httpTimeFallback();

    // Use faster retry interval when not synced
    m_refreshTimer.setInterval(REFRESH_RETRY_MS);
    return;
  }

  // NTP succeeded — reset failure counter
  m_ntpConsecutiveFailures = 0;

  // Compute median of collected offsets
  std::sort(m_collectedOffsets.begin(), m_collectedOffsets.end());
  int n = m_collectedOffsets.size();
  double median;
  if (n % 2 == 0) {
    median = (m_collectedOffsets[n/2 - 1] + m_collectedOffsets[n/2]) / 2.0;
  } else {
    median = m_collectedOffsets[n/2];
  }

  m_offsetMs = median;
  m_synced = true;

  // Restore normal refresh interval after successful sync
  m_refreshTimer.setInterval(REFRESH_INTERVAL_MS);

  Q_EMIT offsetUpdated(m_offsetMs);
  Q_EMIT syncStatusChanged(true, QString("NTP synced: %1 servers, offset %2 ms")
                           .arg(n).arg(median, 0, 'f', 1));
}

// ---- HTTP Time Fallback ----
// When UDP NTP (port 123) is blocked by firewall, use HTTP HEAD requests
// to get approximate time from the Date header. Accuracy ~200-500ms.
void NtpClient::httpTimeFallback()
{
  if (!m_enabled) return;

  // HTTP time sources — port 80/443 almost never blocked
  static const QStringList httpServers = {
    "https://www.google.com",
    "https://www.cloudflare.com",
    "https://www.microsoft.com",
    "https://www.apple.com",
  };

  m_httpOffsets.clear();
  m_httpPendingCount = httpServers.size();

  for (const auto &url : httpServers) {
    QNetworkRequest req{QUrl{url}};
    req.setAttribute(QNetworkRequest::RedirectPolicyAttribute,
                     QNetworkRequest::NoLessSafeRedirectPolicy);
    // Record send time
    QNetworkReply *reply = m_nam->head(req);
    m_httpSendTimes.insert(reply, QDateTime::currentDateTimeUtc().toMSecsSinceEpoch());
    // Timeout individual requests after 5s
    QTimer::singleShot(5000, reply, [reply]() {
      if (reply->isRunning()) reply->abort();
    });
  }
}

void NtpClient::onHttpReply(QNetworkReply *reply)
{
  reply->deleteLater();
  --m_httpPendingCount;

  qint64 t4Ms = QDateTime::currentDateTimeUtc().toMSecsSinceEpoch();

  if (reply->error() == QNetworkReply::NoError && m_httpSendTimes.contains(reply)) {
    qint64 t1Ms = m_httpSendTimes.value(reply);
    m_httpSendTimes.remove(reply);

    // Parse Date header: "Mon, 17 Feb 2026 14:30:00 GMT"
    QByteArray dateHeader = reply->rawHeader("Date");
    if (!dateHeader.isEmpty()) {
      // Try RFC 2822 format
      QDateTime serverTime = QLocale::c().toDateTime(
        QString::fromLatin1(dateHeader).trimmed(),
        "ddd, dd MMM yyyy HH:mm:ss 'GMT'");
      serverTime.setTimeSpec(Qt::UTC);

      if (serverTime.isValid()) {
        qint64 serverMs = serverTime.toMSecsSinceEpoch();
        qint64 rtt = t4Ms - t1Ms;
        // Estimate: server time corresponds to midpoint of round-trip
        double offset = static_cast<double>(serverMs) - static_cast<double>(t1Ms + rtt / 2);
        // HTTP Date has 1-second resolution, so only trust offsets within 1 hour
        if (std::abs(offset) < MAX_OFFSET_MS) {
          m_httpOffsets.append(offset);
        }
      }
    }
  } else {
    m_httpSendTimes.remove(reply);
  }

  // All HTTP replies received — compute result
  if (m_httpPendingCount <= 0) {
    if (!m_httpOffsets.isEmpty()) {
      std::sort(m_httpOffsets.begin(), m_httpOffsets.end());
      int n = m_httpOffsets.size();
      double median;
      if (n % 2 == 0) {
        median = (m_httpOffsets[n/2 - 1] + m_httpOffsets[n/2]) / 2.0;
      } else {
        median = m_httpOffsets[n/2];
      }

      m_offsetMs = median;
      m_synced = true;

      Q_EMIT offsetUpdated(m_offsetMs);
      Q_EMIT syncStatusChanged(true, QString("HTTP time sync: %1 servers, offset %2 ms")
                               .arg(n).arg(median, 0, 'f', 0));
    }
    m_httpSendTimes.clear();
  }
}

double NtpClient::ntpTimestampToMs(quint32 seconds, quint32 fraction)
{
  // Convert NTP timestamp (epoch 1900) to milliseconds since Unix epoch (1970)
  qint64 unixSeconds = static_cast<qint64>(seconds) - static_cast<qint64>(NTP_EPOCH_OFFSET);
  double fracMs = static_cast<double>(fraction) * 1000.0 / 4294967296.0;  // 2^32
  return static_cast<double>(unixSeconds) * 1000.0 + fracMs;
}

void NtpClient::msToNtpTimestamp(qint64 msEpoch, quint32 &seconds, quint32 &fraction)
{
  // Convert milliseconds since Unix epoch to NTP timestamp (epoch 1900)
  qint64 sec = msEpoch / 1000;
  qint64 ms = msEpoch % 1000;
  seconds = static_cast<quint32>(sec + static_cast<qint64>(NTP_EPOCH_OFFSET));
  fraction = static_cast<quint32>(static_cast<double>(ms) / 1000.0 * 4294967296.0);  // 2^32
}

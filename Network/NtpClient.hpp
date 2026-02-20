// -*- Mode: C++ -*-
#ifndef NTP_CLIENT_HPP__
#define NTP_CLIENT_HPP__

#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QHostInfo>
#include <QVector>
#include <QString>
#include <QElapsedTimer>
#include <QHash>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class NtpClient : public QObject
{
  Q_OBJECT

public:
  explicit NtpClient(QObject *parent = nullptr);
  ~NtpClient() override;

  void setEnabled(bool enabled);
  void syncNow();
  double offsetMs() const { return m_offsetMs; }
  bool isSynced() const { return m_synced; }
  void setInitialOffset(double offsetMs);

Q_SIGNALS:
  void offsetUpdated(double offsetMs);
  void syncStatusChanged(bool synced, QString const& statusText);
  void errorOccurred(QString const& errorMsg);

private Q_SLOTS:
  void onRefreshTimeout();
  void onQueryTimeout();
  void onReadyRead();
  void onDnsLookupResult(QHostInfo hostInfo);
  void onHttpReply(QNetworkReply *reply);

private:
  static constexpr quint64 NTP_EPOCH_OFFSET = 2208988800ULL;
  static constexpr int NTP_PACKET_SIZE = 48;
  static constexpr int NTP_PORT = 123;
  static constexpr int REFRESH_INTERVAL_MS = 300000;  // 5 minutes
  static constexpr int REFRESH_RETRY_MS = 30000;      // 30 seconds when not synced
  static constexpr int QUERY_TIMEOUT_MS = 5000;       // 5 seconds
  static constexpr double MAX_OFFSET_MS = 3600000.0;  // 1 hour sanity gate
  static constexpr int SERVERS_PER_QUERY = 8;          // max servers per sync cycle

  struct PendingQuery {
    qint64 t1Ms;  // client send time (ms since Unix epoch)
  };

  void sendQuery(QHostAddress const& address);
  void httpTimeFallback();
  static double ntpTimestampToMs(quint32 seconds, quint32 fraction);
  static void msToNtpTimestamp(qint64 msEpoch, quint32 &seconds, quint32 &fraction);

  QUdpSocket m_socket;
  QTimer m_refreshTimer;
  QTimer m_queryTimeoutTimer;

  QStringList m_servers;
  QHash<QString, PendingQuery> m_pendingQueries;  // key = address.toString()
  QVector<double> m_collectedOffsets;

  // HTTP time fallback
  QNetworkAccessManager *m_nam {nullptr};
  QVector<double> m_httpOffsets;
  QHash<QNetworkReply*, qint64> m_httpSendTimes;  // reply → send time
  int m_httpPendingCount {0};
  int m_ntpConsecutiveFailures {0};

  double m_offsetMs {0.0};
  bool m_synced {false};
  bool m_enabled {false};
  int m_pendingDnsLookups {0};
};

#endif // NTP_CLIENT_HPP__

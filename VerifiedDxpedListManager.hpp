#ifndef VERIFIED_DXPED_LIST_MANAGER_HPP
#define VERIFIED_DXPED_LIST_MANAGER_HPP

#include <QObject>
#include <QDir>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QSet>
#include <QString>
#include <QUrl>
#include <QDebug>

#include "VerifiedDxpedList.hpp"

// Downloads and caches the signed verified DXpedition callsign list.
// On construction, loads cached copy synchronously.
// Call refresh() to fetch fresh data from the server.
class VerifiedDxpedListManager : public QObject
{
  Q_OBJECT

public:
  explicit VerifiedDxpedListManager (QDir const& data_dir,
                                     QString const& url = "https://ft2.it/verified_dxpeds.json",
                                     QObject * parent = nullptr)
    : QObject {parent}
    , m_cachePath {data_dir.absoluteFilePath ("verified_dxpeds.json")}
    , m_url {url}
  {
    // Load cached copy immediately
    loadCached ();
  }

  QSet<QString> const& callsigns () const { return m_callsigns; }

  void refresh ()
  {
    if (m_url.isEmpty ()) return;
    auto * reply = m_nam.get (QNetworkRequest {QUrl {m_url}});
    connect (reply, &QNetworkReply::finished, this, [this, reply] () {
      reply->deleteLater ();
      if (reply->error () != QNetworkReply::NoError) {
        qDebug () << "VerifiedDxpedListManager: download error:" << reply->errorString ();
        return;
      }
      auto data = reply->readAll ();
      auto calls = VerifiedDxpedList::parseAndVerify (data);
      if (calls.isEmpty ()) {
        qDebug () << "VerifiedDxpedListManager: downloaded list invalid or empty";
        return;
      }
      // Save to cache
      QFile f (m_cachePath);
      if (f.open (QIODevice::WriteOnly)) {
        f.write (data);
        f.close ();
      }
      // Merge with any locally-loaded calls (from .dxcert)
      m_callsigns = calls;
      Q_EMIT callsignsUpdated (m_callsigns);
    });
  }

  // Add a callsign from local certificate loading
  void addLocal (QString const& call)
  {
    m_callsigns.insert (call.toUpper ());
    Q_EMIT callsignsUpdated (m_callsigns);
  }

Q_SIGNALS:
  void callsignsUpdated (QSet<QString> const& calls);

private:
  void loadCached ()
  {
    QFile f (m_cachePath);
    if (!f.open (QIODevice::ReadOnly)) return;
    auto data = f.readAll ();
    f.close ();
    auto calls = VerifiedDxpedList::parseAndVerify (data);
    if (!calls.isEmpty ()) {
      m_callsigns = calls;
      qDebug () << "VerifiedDxpedListManager: loaded" << calls.size () << "calls from cache";
    }
  }

  QNetworkAccessManager m_nam;
  QSet<QString>         m_callsigns;
  QString               m_cachePath;
  QString               m_url;
};

#endif // VERIFIED_DXPED_LIST_MANAGER_HPP

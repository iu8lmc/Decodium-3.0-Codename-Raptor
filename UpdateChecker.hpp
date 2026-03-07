#ifndef UPDATECHECKER_HPP
#define UPDATECHECKER_HPP

#include <QObject>
#include <QString>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

// Controlla GitHub Releases per nuove versioni e offre download automatico.
// Uso: UpdateChecker::checkForUpdates(parent);  — chiamata unica, si auto-gestisce.

class UpdateChecker : public QObject
{
  Q_OBJECT

public:
  static void checkForUpdates (QWidget * parent, bool silent = true);

  explicit UpdateChecker (QWidget * parent, bool silent);

private Q_SLOTS:
  void onReleaseFetched (QNetworkReply * reply);
  void onDownloadProgress (qint64 received, qint64 total);
  void onDownloadFinished ();

private:
  void startDownload (QString const& url, QString const& filename);
  void launchInstaller (QString const& path);
  bool isNewerVersion (QString const& remoteTag) const;

  QNetworkAccessManager  m_nam;
  QNetworkReply        * m_downloadReply {nullptr};
  QWidget              * m_parent        {nullptr};
  bool                   m_silent        {true};
  QString                m_assetUrl;
  QString                m_remoteVersion;
  QFile                * m_outFile       {nullptr};

  // Progress dialog (owned by this, shown during download)
  class QProgressDialog * m_progress {nullptr};
};

#endif // UPDATECHECKER_HPP

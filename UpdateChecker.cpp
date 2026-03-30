#include "UpdateChecker.hpp"

#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QPushButton>
#include <QProgressDialog>
#include <QFile>
#include <QDir>
#include <QStandardPaths>
#include <QProcess>
#include <QSysInfo>
#include <QNetworkRequest>
#include <QSettings>
#include <QTextStream>
#include <QDebug>

#include "revision_utils.hpp"

#include <QRegularExpression>

// GitHub repo
static constexpr char GITHUB_API_URL[] =
    "https://api.github.com/repos/iu8lmc/Decodium-3.0-Shannon/releases/latest";

// ──────────────────────────────────────────────────────────────────────────────
void UpdateChecker::checkForUpdates (QWidget * parent, bool silent)
{
  auto * checker = new UpdateChecker {parent, silent};
  Q_UNUSED (checker);
}

// ──────────────────────────────────────────────────────────────────────────────
UpdateChecker::UpdateChecker (QWidget * parent, bool silent)
  : QObject {parent}
  , m_parent {parent}
  , m_silent {silent}
{
  connect (&m_nam, &QNetworkAccessManager::finished,
           this,   &UpdateChecker::onReleaseFetched);

  QNetworkRequest req {QUrl {GITHUB_API_URL}};
  req.setHeader (QNetworkRequest::UserAgentHeader,
                 QStringLiteral ("Decodium/") + program_title ());
  req.setRawHeader ("Accept", "application/vnd.github+json");
  m_nam.get (req);
}

// ──────────────────────────────────────────────────────────────────────────────
static qint64 extractBuildNumber (QString const& tag)
{
  static QRegularExpression rxDigits {R"((\d{10}))"};
  auto m = rxDigits.match (tag);
  return m.hasMatch () ? m.captured (1).toLongLong () : -1;
}

bool UpdateChecker::isVersionDifferent (QString const& remoteTag) const
{
  qint64 remote = extractBuildNumber (remoteTag);
  qint64 local  = extractBuildNumber (program_title ());
  if (remote < 0 || local < 0) return false;

  qDebug () << "UpdateChecker: remote=" << remote << "local=" << local
             << "tag=" << remoteTag << "title=" << program_title ();

  return remote != local;
}

bool UpdateChecker::isDowngrade (QString const& remoteTag) const
{
  qint64 remote = extractBuildNumber (remoteTag);
  qint64 local  = extractBuildNumber (program_title ());
  return (remote >= 0 && local >= 0 && remote < local);
}

// ──────────────────────────────────────────────────────────────────────────────
void UpdateChecker::onReleaseFetched (QNetworkReply * reply)
{
  reply->deleteLater ();
  disconnect (&m_nam, &QNetworkAccessManager::finished,
              this,   &UpdateChecker::onReleaseFetched);

  if (reply->error () != QNetworkReply::NoError) {
    if (!m_silent)
      QMessageBox::warning (m_parent, tr ("Update"),
                            tr ("Unable to contact the server:\n%1")
                            .arg (reply->errorString ()));
    deleteLater ();
    return;
  }

  QJsonDocument doc = QJsonDocument::fromJson (reply->readAll ());
  if (doc.isNull () || !doc.isObject ()) {
    deleteLater ();
    return;
  }

  QJsonObject root = doc.object ();
  m_remoteVersion  = root["tag_name"].toString ();

  if (!isVersionDifferent (m_remoteVersion)) {
    if (!m_silent)
      QMessageBox::information (m_parent, tr ("Update"),
                                tr ("Decodium is up to date.\n\n"
                                    "Remote version: %1\n"
                                    "Local version: %2")
                                .arg (m_remoteVersion)
                                .arg (program_title ()));
    deleteLater ();
    return;
  }

  // Skip if user already dismissed this version (silent/auto mode only)
  if (m_silent) {
    QSettings settings;
    QString skipped = settings.value ("UpdateChecker/SkippedVersion").toString ();
    if (skipped == m_remoteVersion) {
      deleteLater ();
      return;
    }
  }

  // Find the right asset for this architecture
  QString arch = (QSysInfo::currentCpuArchitecture () == "x86_64") ? "x64" : "x86";
  QJsonArray assets = root["assets"].toArray ();
  for (auto const& a : assets) {
    QString name = a.toObject ()["name"].toString ();
    if (name.contains (arch, Qt::CaseInsensitive) && name.endsWith (".exe")) {
      m_assetUrl = a.toObject ()["browser_download_url"].toString ();
      break;
    }
  }

  bool downgrade = isDowngrade (m_remoteVersion);
  QString notes = root["body"].toString ().left (400);
  QString msg   = downgrade
    ? tr ("A <b>downgrade</b> is available: <b>%1</b><br>"
          "<i>(your current version %2 is newer than the official release)</i><br><br>"
          "%3<br><br>"
          "Would you like to download and install the official version now?")
        .arg (m_remoteVersion)
        .arg (program_title ())
        .arg (notes.toHtmlEscaped ().replace ("\n", "<br>"))
    : tr ("New version available: <b>%1</b><br><br>"
          "%2<br><br>"
          "Would you like to download and install the update now?")
        .arg (m_remoteVersion)
        .arg (notes.toHtmlEscaped ().replace ("\n", "<br>"));

  QMessageBox box {m_parent};
  box.setWindowTitle (tr ("Decodium Update"));
  box.setTextFormat  (Qt::RichText);
  box.setText        (msg);
  QPushButton *btnYes  = box.addButton (downgrade ? tr ("Yes, downgrade") : tr ("Yes, update"), QMessageBox::AcceptRole);
  QPushButton *btnSkip = box.addButton (tr ("Not now (don't ask again for this version)"), QMessageBox::RejectRole);
  box.addButton (tr ("Later"), QMessageBox::DestructiveRole);
  box.setDefaultButton (btnYes);
  box.setIcon (QMessageBox::Information);
  box.exec ();

  if (box.clickedButton () == btnSkip) {
    QSettings settings;
    settings.setValue ("UpdateChecker/SkippedVersion", m_remoteVersion);
    deleteLater ();
    return;
  }

  if (box.clickedButton () != btnYes || m_assetUrl.isEmpty ()) {
    deleteLater ();
    return;
  }

  QString filename = QStringLiteral ("Decodium_%1_Setup.exe").arg (m_remoteVersion);
  startDownload (m_assetUrl, filename);
}

// ──────────────────────────────────────────────────────────────────────────────
void UpdateChecker::startDownload (QString const& url, QString const& filename)
{
  QString tempDir  = QStandardPaths::writableLocation (QStandardPaths::TempLocation);
  QString destPath = tempDir + QDir::separator () + filename;

  m_outFile = new QFile {destPath, this};
  if (!m_outFile->open (QIODevice::WriteOnly)) {
    QMessageBox::critical (m_parent, tr ("Update"),
                           tr ("Unable to write to temporary folder:\n%1").arg (destPath));
    deleteLater ();
    return;
  }

  m_progress = new QProgressDialog {tr ("Downloading update…"), tr ("Cancel"),
                                    0, 100, m_parent};
  m_progress->setWindowModality (Qt::WindowModal);
  m_progress->setMinimumDuration (0);
  m_progress->setValue (0);

  connect (m_progress, &QProgressDialog::canceled, this, [this] () {
    if (m_downloadReply) m_downloadReply->abort ();
  });

  QNetworkRequest req {QUrl {url}};
  req.setAttribute (QNetworkRequest::RedirectPolicyAttribute,
                    QNetworkRequest::NoLessSafeRedirectPolicy);
  req.setHeader (QNetworkRequest::UserAgentHeader,
                 QStringLiteral ("Decodium/") + program_title ());

  m_downloadReply = m_nam.get (req);
  connect (m_downloadReply, &QNetworkReply::downloadProgress,
           this,             &UpdateChecker::onDownloadProgress);
  connect (m_downloadReply, &QNetworkReply::finished,
           this,             &UpdateChecker::onDownloadFinished);
  connect (m_downloadReply, &QNetworkReply::readyRead, this, [this] () {
    if (m_outFile) m_outFile->write (m_downloadReply->readAll ());
  });
}

// ──────────────────────────────────────────────────────────────────────────────
void UpdateChecker::onDownloadProgress (qint64 received, qint64 total)
{
  if (m_progress && total > 0)
    m_progress->setValue (static_cast<int> (received * 100 / total));
}

// ──────────────────────────────────────────────────────────────────────────────
void UpdateChecker::onDownloadFinished ()
{
  m_downloadReply->deleteLater ();

  if (m_progress) { m_progress->close (); m_progress->deleteLater (); m_progress = nullptr; }
  if (m_outFile)  { m_outFile->close ();  }

  if (m_downloadReply->error () != QNetworkReply::NoError) {
    QMessageBox::critical (m_parent, tr ("Update"),
                           tr ("Download failed:\n%1").arg (m_downloadReply->errorString ()));
    deleteLater ();
    return;
  }

  QString path = m_outFile->fileName ();
  QMessageBox::information (m_parent, tr ("Update"),
                             tr ("Download complete.\n"
                                 "The installer will now launch.\n"
                                 "Decodium will close automatically."));
  launchInstaller (path);
}

// ──────────────────────────────────────────────────────────────────────────────
void UpdateChecker::launchInstaller (QString const& path)
{
  QString installerPath = path;
  QString batPath = QStandardPaths::writableLocation (QStandardPaths::TempLocation)
                    + QDir::separator () + "decodium_update.bat";
  QFile bat {batPath};
  if (bat.open (QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream ts {&bat};
    ts << "@echo off\r\n"
       << "timeout /t 2 /nobreak >nul\r\n"
       << "\"" << QDir::toNativeSeparators (installerPath) << "\""
       << " /VERYSILENT /CLOSEAPPLICATIONS /FORCECLOSEAPPLICATIONS"
       << " /SUPPRESSMSGBOXES /NORESTART /MERGETASKS=\"desktopicon\"\r\n";
    bat.close ();
    QProcess::startDetached ("cmd.exe", {"/C", batPath});
  } else {
    QProcess::startDetached (installerPath,
      {"/VERYSILENT", "/CLOSEAPPLICATIONS", "/FORCECLOSEAPPLICATIONS",
       "/SUPPRESSMSGBOXES", "/NORESTART", "/MERGETASKS=desktopicon"});
  }
  QApplication::quit ();
  deleteLater ();
}

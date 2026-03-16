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
#include <QDebug>

#include "revision_utils.hpp"

#include <QRegularExpression>

// GitHub repo — cambia se il repo cambia nome
static constexpr char GITHUB_API_URL[] =
    "https://api.github.com/repos/iu8lmc/Decodium-3.0-Codename-Raptor/releases/latest";

// ──────────────────────────────────────────────────────────────────────────────
void UpdateChecker::checkForUpdates (QWidget * parent, bool silent)
{
  // L'oggetto si auto-distrugge quando ha finito
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
// Confronta tag remoto (es. "v3.0.2603060002") con build locale (es. "2603160843")
// Estrae la parte numerica finale e la confronta come intero.
bool UpdateChecker::isNewerVersion (QString const& remoteTag) const
{
  // Rimuove prefissi tipo "v3.0."
  QString cleaned = remoteTag;
  cleaned.remove (QRegularExpression ("^v?[0-9]+\\.[0-9]+\\.?"));
  bool ok = false;
  qint64 remote = cleaned.toLongLong (&ok);
  if (!ok) return false;

  QString localTag = program_title ();
  // program_title() restituisce "Decodium Fast Track 2 v3.0.XXXXXXXXXX ..."
  // Cerca il build number dopo "v3.0."
  QRegularExpression rx ("v3\\.0\\.(\\d{10})");
  auto match = rx.match (localTag);
  if (!match.hasMatch ()) return false;
  qint64 local = match.captured (1).toLongLong ();
  return remote > local;
}

// ──────────────────────────────────────────────────────────────────────────────
void UpdateChecker::onReleaseFetched (QNetworkReply * reply)
{
  reply->deleteLater ();
  disconnect (&m_nam, &QNetworkAccessManager::finished,
              this,   &UpdateChecker::onReleaseFetched);

  if (reply->error () != QNetworkReply::NoError) {
    if (!m_silent)
      QMessageBox::warning (m_parent, tr ("Aggiornamento"),
                            tr ("Impossibile contattare il server:\n%1")
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

  if (!isNewerVersion (m_remoteVersion)) {
    if (!m_silent)
      QMessageBox::information (m_parent, tr ("Aggiornamento"),
                                tr ("Decodium è aggiornato all'ultima versione."));
    deleteLater ();
    return;
  }

  // Skip se l'utente ha già rifiutato questa versione (solo in modalità silent/auto)
  if (m_silent) {
    QSettings settings;
    QString skipped = settings.value ("UpdateChecker/SkippedVersion").toString ();
    if (skipped == m_remoteVersion) {
      deleteLater ();
      return;  // utente ha scelto "Non ora" per questa versione
    }
  }

  // Cerca l'asset giusto per questa architettura
  QString arch = (QSysInfo::currentCpuArchitecture () == "x86_64") ? "x64" : "x86";
  QJsonArray assets = root["assets"].toArray ();
  for (auto const& a : assets) {
    QString name = a.toObject ()["name"].toString ();
    if (name.contains (arch, Qt::CaseInsensitive) && name.endsWith (".exe")) {
      m_assetUrl = a.toObject ()["browser_download_url"].toString ();
      break;
    }
  }

  QString notes = root["body"].toString ().left (400);
  QString msg   = tr ("Nuova versione disponibile: <b>%1</b><br><br>"
                      "%2<br><br>"
                      "Vuoi scaricare e installare l'aggiornamento adesso?")
                  .arg (m_remoteVersion)
                  .arg (notes.toHtmlEscaped ().replace ("\n", "<br>"));

  QMessageBox box {m_parent};
  box.setWindowTitle (tr ("Aggiornamento Decodium"));
  box.setTextFormat  (Qt::RichText);
  box.setText        (msg);
  QPushButton *btnYes  = box.addButton (tr ("Sì, aggiorna"), QMessageBox::AcceptRole);
  QPushButton *btnSkip = box.addButton (tr ("Non ora (non chiedere più per questa versione)"), QMessageBox::RejectRole);
  box.addButton (tr ("Più tardi"), QMessageBox::DestructiveRole);
  box.setDefaultButton (btnYes);
  box.setIcon (QMessageBox::Information);
  box.exec ();

  if (box.clickedButton () == btnSkip) {
    // Ricorda: non chiedere più per questa versione
    QSettings settings;
    settings.setValue ("UpdateChecker/SkippedVersion", m_remoteVersion);
    deleteLater ();
    return;
  }

  if (box.clickedButton () != btnYes || m_assetUrl.isEmpty ()) {
    deleteLater ();
    return;
  }

  // Avvia il download
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
    QMessageBox::critical (m_parent, tr ("Aggiornamento"),
                           tr ("Impossibile scrivere nella cartella temporanea:\n%1").arg (destPath));
    deleteLater ();
    return;
  }

  m_progress = new QProgressDialog {tr ("Download aggiornamento…"), tr ("Annulla"),
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
    QMessageBox::critical (m_parent, tr ("Aggiornamento"),
                           tr ("Download fallito:\n%1").arg (m_downloadReply->errorString ()));
    deleteLater ();
    return;
  }

  QString path = m_outFile->fileName ();
  QMessageBox::information (m_parent, tr ("Aggiornamento"),
                             tr ("Download completato.\n"
                                 "L'installer verrà avviato.\n"
                                 "Decodium si chiuderà automaticamente."));
  launchInstaller (path);
}

// ──────────────────────────────────────────────────────────────────────────────
void UpdateChecker::launchInstaller (QString const& path)
{
  // Avvia l'installer in modo indipendente e chiudi l'app
  QProcess::startDetached (path, {"/SILENT"});
  QApplication::quit ();
  deleteLater ();
}

//
// DXpedition Certificate Generator — Decodium Shannon
// Tool riservato all'authority (IU8LMC) — NON distribuire
//
// Usage:
//   dxcert_generator.exe                          (modalità interattiva)
//   dxcert_generator.exe VP8PJ 199 "South Shetland" "IU8LMC,W1AW" 2026-04-01 2026-04-15 4
//

#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QCryptographicHash>
#include <QMessageAuthenticationCode>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <iostream>

static QByteArray HMAC_KEY ("D3c0d1uM-ASYMX-DXp3d-2026-IU8LMC");

static QString readLine (QString const& prompt)
{
  std::cout << prompt.toStdString () << ": " << std::flush;
  char buf[256];
  if (!std::cin.getline (buf, sizeof (buf))) return {};
  return QString::fromLocal8Bit (buf).trimmed ();
}

static bool generateCert (QString const& callsign, int dxcc, QString const& dxccName,
                           QStringList const& operators, QString const& startDate,
                           QString const& endDate, int maxSlots, QString const& outFile)
{
  QJsonObject obj;
  obj["version"] = 1;
  obj["callsign"] = callsign.toUpper ();
  obj["dxcc_entity"] = dxcc;
  obj["dxcc_name"] = dxccName;
  QJsonArray ops;
  for (auto const& op : operators) ops.append (op.trimmed ().toUpper ());
  obj["operators"] = ops;
  obj["activation_start"] = startDate + "T00:00:00Z";
  obj["activation_end"] = endDate + "T23:59:59Z";
  obj["max_slots"] = qBound (1, maxSlots, 4);
  obj["issued_by"] = QString ("Decodium Authority");
  obj["issued_at"] = QDateTime::currentDateTimeUtc ().toString (Qt::ISODate);

  // Sign with HMAC-SHA256
  auto payload = QJsonDocument (obj).toJson (QJsonDocument::Compact);
  auto sig = QMessageAuthenticationCode::hash (payload, HMAC_KEY, QCryptographicHash::Sha256).toHex ();
  obj["signature"] = QString::fromLatin1 (sig);

  // Cert hash
  auto certHash = QString::fromLatin1 (
    QCryptographicHash::hash (payload, QCryptographicHash::Sha256).toHex ().left (8));

  // Write file
  QFile f (outFile);
  if (!f.open (QIODevice::WriteOnly)) {
    std::cerr << "ERROR: Cannot write " << outFile.toStdString () << std::endl;
    return false;
  }
  f.write (QJsonDocument (obj).toJson (QJsonDocument::Indented));
  f.close ();

  std::cout << "\n========================================\n";
  std::cout << "  Certificate Generated!\n";
  std::cout << "========================================\n";
  std::cout << "  File:       " << outFile.toStdString () << "\n";
  std::cout << "  Callsign:   " << callsign.toUpper ().toStdString () << "\n";
  std::cout << "  DXCC:       " << dxccName.toStdString () << " (" << dxcc << ")\n";
  std::cout << "  Operators:  " << operators.join (", ").toUpper ().toStdString () << "\n";
  std::cout << "  Max Slots:  " << maxSlots << "\n";
  std::cout << "  Valid:      " << startDate.toStdString () << " to " << endDate.toStdString () << "\n";
  std::cout << "  Hash:       " << certHash.toStdString () << "\n";
  std::cout << "  Signature:  " << sig.left (32).constData () << "...\n";
  std::cout << "========================================\n";
  return true;
}

int main (int argc, char *argv[])
{
  QCoreApplication app (argc, argv);

  if (argc >= 7) {
    // Command-line mode
    QString call = argv[1];
    int dxcc = QString (argv[2]).toInt ();
    QString name = argv[3];
    QStringList ops = QString (argv[4]).split (',');
    QString start = argv[5];
    QString end = argv[6];
    int nSlots = argc > 7 ? QString (argv[7]).toInt () : 2;
    QString outFile = call.toUpper () + ".dxcert";

    return generateCert (call, dxcc, name, ops, start, end, nSlots, outFile) ? 0 : 1;
  }

  // Interactive mode
  std::cout << "========================================\n";
  std::cout << "  Decodium Shannon — DXped Certificate Generator\n";
  std::cout << "  RESERVED — Do not distribute\n";
  std::cout << "========================================\n\n";

  QString call = readLine ("DXpedition Callsign (e.g. VP8PJ)");
  if (call.isEmpty ()) { std::cerr << "Callsign required.\n"; return 1; }

  int dxcc = readLine ("DXCC Entity Number (e.g. 199)").toInt ();
  QString dxccName = readLine ("DXCC Name (e.g. South Shetland)");
  QStringList ops = readLine ("Operators comma-separated (e.g. IU8LMC,W1AW,K3LR)").split (',');
  QString start = readLine ("Activation Start (YYYY-MM-DD)");
  QString end = readLine ("Activation End (YYYY-MM-DD)");
  int nSlots = readLine ("Max TX Slots (1-4, default 2)").toInt ();
  if (nSlots < 1 || nSlots > 4) nSlots = 2;

  QString outFile = call.toUpper () + ".dxcert";
  return generateCert (call, dxcc, dxccName, ops, start, end, nSlots, outFile) ? 0 : 1;
}

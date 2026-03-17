#ifndef DXPED_CERTIFICATE_HPP__
#define DXPED_CERTIFICATE_HPP__

#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QCryptographicHash>
#include <QMessageAuthenticationCode>

// DXpedition Certificate (.dxcert) — JSON file with HMAC-SHA256 signature
// Used to verify legitimate DXpedition stations in Decodium
class DXpedCertificate
{
public:
  DXpedCertificate () = default;

  bool loadFromFile (QString const& path)
  {
    QFile f (path);
    if (!f.open (QIODevice::ReadOnly)) return false;
    auto data = f.readAll ();
    f.close ();

    QJsonParseError err;
    auto doc = QJsonDocument::fromJson (data, &err);
    if (err.error != QJsonParseError::NoError || !doc.isObject ()) return false;

    auto obj = doc.object ();
    version_       = obj["version"].toInt (0);
    callsign_      = obj["callsign"].toString ().toUpper ();
    dxcc_entity_   = obj["dxcc_entity"].toInt (0);
    dxcc_name_     = obj["dxcc_name"].toString ();
    start_         = QDateTime::fromString (obj["activation_start"].toString (), Qt::ISODate);
    end_           = QDateTime::fromString (obj["activation_end"].toString (), Qt::ISODate);
    max_slots_     = qBound (1, obj["max_slots"].toInt (2), 4);
    issued_by_     = obj["issued_by"].toString ();
    signature_     = obj["signature"].toString ();

    operators_.clear ();
    for (auto const& v : obj["operators"].toArray ()) {
      operators_ << v.toString ().toUpper ();
    }

    // Verify HMAC-SHA256 signature
    QJsonObject check = obj;
    check.remove ("signature");
    auto payload = QJsonDocument (check).toJson (QJsonDocument::Compact);
    auto expected = QMessageAuthenticationCode::hash (
      payload, hmacKey (), QCryptographicHash::Sha256).toHex ();

    valid_ = (signature_ == QString::fromLatin1 (expected));

    // Compute verification hash (first 8 hex chars of SHA-256 of certificate)
    cert_hash_ = QString::fromLatin1 (
      QCryptographicHash::hash (payload, QCryptographicHash::Sha256).toHex ().left (8));

    return valid_;
  }

  bool isValid () const
  {
    if (!valid_) return false;
    auto now = QDateTime::currentDateTimeUtc ();
    return now >= start_ && now <= end_;
  }

  bool isOperator (QString const& call) const
  {
    return operators_.contains (call.toUpper ());
  }

  QString callsign () const { return callsign_; }
  int dxccEntity () const { return dxcc_entity_; }
  QString dxccName () const { return dxcc_name_; }
  QStringList operators () const { return operators_; }
  int maxSlots () const { return max_slots_; }
  QDateTime activationStart () const { return start_; }
  QDateTime activationEnd () const { return end_; }
  QString issuedBy () const { return issued_by_; }
  QString certHash () const { return cert_hash_; }
  bool signatureValid () const { return valid_; }

  // Generate a certificate file (for authority use)
  static bool generateCertFile (QString const& path,
                                QString const& callsign,
                                int dxcc_entity,
                                QString const& dxcc_name,
                                QStringList const& operators,
                                QDateTime const& start,
                                QDateTime const& end,
                                int max_slots = 2)
  {
    QJsonObject obj;
    obj["version"] = 1;
    obj["callsign"] = callsign.toUpper ();
    obj["dxcc_entity"] = dxcc_entity;
    obj["dxcc_name"] = dxcc_name;
    QJsonArray ops;
    for (auto const& op : operators) ops.append (op.toUpper ());
    obj["operators"] = ops;
    obj["activation_start"] = start.toString (Qt::ISODate);
    obj["activation_end"] = end.toString (Qt::ISODate);
    obj["max_slots"] = qBound (1, max_slots, 4);
    obj["issued_by"] = QString ("Decodium Authority");
    obj["issued_at"] = QDateTime::currentDateTimeUtc ().toString (Qt::ISODate);

    auto payload = QJsonDocument (obj).toJson (QJsonDocument::Compact);
    auto sig = QMessageAuthenticationCode::hash (
      payload, hmacKey (), QCryptographicHash::Sha256).toHex ();
    obj["signature"] = QString::fromLatin1 (sig);

    QFile f (path);
    if (!f.open (QIODevice::WriteOnly)) return false;
    f.write (QJsonDocument (obj).toJson (QJsonDocument::Indented));
    f.close ();
    return true;
  }

private:
  // Embedded HMAC key (shared between authority and client)
  static QByteArray hmacKey () { return QByteArray ("D3c0d1uM-ASYMX-DXp3d-2026-IU8LMC"); }

  int         version_     {0};
  QString     callsign_;
  int         dxcc_entity_ {0};
  QString     dxcc_name_;
  QDateTime   start_;
  QDateTime   end_;
  QStringList operators_;
  int         max_slots_   {2};
  QString     issued_by_;
  QString     signature_;
  QString     cert_hash_;
  bool        valid_       {false};
};

#endif // DXPED_CERTIFICATE_HPP__

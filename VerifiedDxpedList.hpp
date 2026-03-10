#ifndef VERIFIED_DXPED_LIST_HPP
#define VERIFIED_DXPED_LIST_HPP

#include <QByteArray>
#include <QDateTime>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSet>
#include <QString>

#include <openssl/evp.h>

class VerifiedDxpedList
{
public:
  // Ed25519 public key (32 bytes) — generated 2026-03-11
  // Matching private key: tools/dxped_private.pem (KEEP SECRET)
  static constexpr unsigned char ed25519_pubkey[32] = {
    0x2e, 0x01, 0xfa, 0x42, 0x92, 0x44, 0xd4, 0x35,
    0xd5, 0x2f, 0x8b, 0xf8, 0x68, 0x1e, 0x15, 0xb5,
    0xc9, 0x7d, 0x67, 0x90, 0xc8, 0x0f, 0x34, 0x3b,
    0x6c, 0x64, 0x7b, 0x8f, 0x37, 0x06, 0xfe, 0x13
  };

  // Parse and verify a signed JSON list. Returns callsign set (empty on failure).
  static QSet<QString> parseAndVerify (QByteArray const& json)
  {
    QSet<QString> result;

    QJsonParseError err;
    auto doc = QJsonDocument::fromJson (json, &err);
    if (err.error != QJsonParseError::NoError || !doc.isObject ()) {
      qDebug () << "VerifiedDxpedList: JSON parse error" << err.errorString ();
      return result;
    }

    auto obj = doc.object ();
    int version = obj["version"].toInt (0);
    if (version < 2) {
      qDebug () << "VerifiedDxpedList: unsupported version" << version;
      return result;
    }

    // Extract and decode signature
    auto sigB64 = obj["signature"].toString ().toLatin1 ();
    auto sigBytes = QByteArray::fromBase64 (sigB64);
    if (sigBytes.size () != 64) {
      qDebug () << "VerifiedDxpedList: invalid signature length" << sigBytes.size ();
      return result;
    }

    // Reconstruct canonical payload (without signature)
    QJsonObject check = obj;
    check.remove ("signature");
    auto payload = QJsonDocument (check).toJson (QJsonDocument::Compact);

    // Verify Ed25519 signature
    if (!verifyEd25519 (payload, sigBytes)) {
      qDebug () << "VerifiedDxpedList: SIGNATURE VERIFICATION FAILED";
      return result;
    }

    // Check expiry (with 7-day grace period for offline users)
    auto expiresStr = obj["expires"].toString ();
    auto expires = QDateTime::fromString (expiresStr, Qt::ISODate);
    if (expires.isValid () && QDateTime::currentDateTimeUtc () > expires.addDays (7)) {
      qDebug () << "VerifiedDxpedList: list expired" << expiresStr;
      return result;
    }

    // Extract callsigns
    auto arr = obj["callsigns"].toArray ();
    for (auto const& v : arr) {
      auto call = v.toString ().trimmed ().toUpper ();
      if (!call.isEmpty ()) result.insert (call);
    }

    qDebug () << "VerifiedDxpedList: loaded" << result.size () << "verified callsigns";
    return result;
  }

private:
  static bool verifyEd25519 (QByteArray const& payload, QByteArray const& signature)
  {
    EVP_PKEY * pkey = EVP_PKEY_new_raw_public_key (
      EVP_PKEY_ED25519, nullptr, ed25519_pubkey, 32);
    if (!pkey) {
      qDebug () << "VerifiedDxpedList: EVP_PKEY_new_raw_public_key failed";
      return false;
    }

    EVP_MD_CTX * ctx = EVP_MD_CTX_new ();
    if (!ctx) {
      EVP_PKEY_free (pkey);
      return false;
    }

    bool ok = false;
    if (EVP_DigestVerifyInit (ctx, nullptr, nullptr, nullptr, pkey) == 1) {
      ok = EVP_DigestVerify (ctx,
        reinterpret_cast<unsigned char const*> (signature.constData ()),
        static_cast<size_t> (signature.size ()),
        reinterpret_cast<unsigned char const*> (payload.constData ()),
        static_cast<size_t> (payload.size ())) == 1;
    }

    EVP_MD_CTX_free (ctx);
    EVP_PKEY_free (pkey);
    return ok;
  }
};

#endif // VERIFIED_DXPED_LIST_HPP

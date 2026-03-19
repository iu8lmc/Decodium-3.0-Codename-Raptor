#ifndef DECODIUM_CERTIFICATE_HPP
#define DECODIUM_CERTIFICATE_HPP

#include <QString>
#include <QDate>

class DecodiumCertificate
{
public:
  enum Tier { NONE = 0, FREE = 1, PRO = 2 };

  DecodiumCertificate ();

  // Load certificate from file, returns true if valid
  bool load (QString const& filePath);

  // Verification
  bool isValid () const { return m_valid; }
  bool isExpired () const { return m_valid && m_expires < QDate::currentDate (); }
  bool isActive () const { return m_valid && !isExpired (); }

  // Certificate fields
  QString callsign () const { return m_callsign; }
  Tier tier () const { return m_tier; }
  QDate expires () const { return m_expires; }
  QString tierName () const;

  // Feature gates
  bool canSendDecodiumId () const { return isActive (); }             // TU in TX2
  bool canQuickQSO () const { return isActive (); }                   // Quick QSO mode
  bool canShowVerifiedBadge () const { return isActive (); }          // D ✓ badge
  bool canUsePremiumFeatures () const { return isActive () && m_tier >= PRO; }

  // Clear loaded certificate
  void clear ();

private:
  bool verify (QString const& call, QString const& tierStr,
               QString const& expiresStr, QString const& signature) const;

  bool m_valid;
  QString m_callsign;
  Tier m_tier;
  QDate m_expires;
};

#endif // DECODIUM_CERTIFICATE_HPP

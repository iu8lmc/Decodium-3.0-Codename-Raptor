#include "Radio.hpp"

#include <cmath>
#include <limits>

#include <QString>
#include <QChar>
#include <QSet>
#include <QRegularExpression>

namespace Radio
{
  namespace
  {
    double constexpr MHz_factor {1.e6};
    int constexpr frequency_precsion {6};

    // valid callsign alphabet
    QRegularExpression callsign_alphabet_re {R"(^[A-Z0-9/]{3,11}$)"};

    // very loose validation - callsign must contain a letter next to
    // a number
    QRegularExpression valid_callsign_regexp {R"(\d[[:alpha:]]|[[:alpha:]]\d)"};

    // standard callsign
    QRegularExpression strict_standard_callsign_re {R"(^([A-Z][0-9]?|[0-9A-Z][A-Z])[0-9][A-Z]{0,3}$)"};

    // ITU-compliant callsign format (strict structural validation)
    // Prefix: 1-3 chars (letter(s) + digit, or digit + letter + digit, etc.)
    // Suffix: 1-4 letters
    // Optional /P /M /MM /AM /QRP /R /0-9 portable suffix
    // Covers: W1AW, VK2ABC, 3DA0XYZ, VP8/G4XYZ, G4XYZ/P, etc.
    QRegularExpression itu_callsign_re {
      R"(^(?:[A-Z]{1,2}[0-9]|[0-9][A-Z][0-9]|[A-Z][0-9][A-Z])[0-9]?[A-Z]{1,4}$)",
      QRegularExpression::CaseInsensitiveOption};

    // suffixes that are often used and should not be interpreted as a
    // DXCC Entity prefix used as a suffix
    QRegularExpression non_prefix_suffix {R"(\A([0-9AMPQR]|QRP|F[DF]|[AM]M|L[HT]|LGT)\z)"};

    // Known non-callsign tokens that appear in FT8/FT2 messages
    QSet<QString> message_tokens {"CQ", "DE", "QRZ", "RR73", "RRR", "73",
      "TNX", "TU", "GL", "HNY", "PSE", "QSY", "AGN", "TEST", "BCN"};
  }


  Frequency frequency (QVariant const& v, int scale, bool * ok, QLocale const& locale)
  {
    double value {0.};
    if (QVariant::String == v.type ())
      {
        value = locale.toDouble (v.value<QString> (), ok);
      }
    else
      {
        value = v.toDouble ();
        if (ok) *ok = true;
      }
    if (ok && !*ok)
      {
        return value;
      }
    return frequency (value, scale, ok);
  }

  Frequency frequency (double value, int scale, bool * ok)
  {
    value *= std::pow (10., scale);
    if (ok)
      {
        if (value < 0. || value > static_cast<double>(std::numeric_limits<Frequency>::max ()))
          {
            value = 0.;
            *ok = false;
          }
        else
          {
            *ok = true;
          }
      }
    return std::llround (value);
  }

  FrequencyDelta frequency_delta (QVariant const& v, int scale, bool * ok, QLocale const& locale)
  {
    double value {0.};
    if (QVariant::String == v.type ())
      {
        value = locale.toDouble (v.value<QString> (), ok);
      }
    else
      {
        value = v.toDouble ();
        if (ok) *ok = true;
      }
    if (ok && !*ok)
      {
        return value;
      }
    return frequency_delta (value, scale, ok);
  }

  FrequencyDelta frequency_delta (double value, int scale, bool * ok)
  {
    value *= std::pow (10., scale);
    if (ok)
      {
        if (value < static_cast<double>(std::numeric_limits<Frequency>::min ())
            || value > static_cast<double>(std::numeric_limits<Frequency>::max ()))
          {
            value = 0.;
            *ok = false;
          }
        else
          {
            *ok = true;
          }
      }
    return std::llround (value);
  }


  QString frequency_MHz_string (Frequency f, int precision, QLocale const& locale)
  {
    return locale.toString (f / MHz_factor, 'f', precision);
  }

  QString frequency_MHz_string (FrequencyDelta d, int precision, QLocale const& locale)
  {
    return locale.toString (d / MHz_factor, 'f', precision);
  }

  QString pretty_frequency_MHz_string (Frequency f, QLocale const& locale)
  {
    auto f_string = locale.toString (f / MHz_factor, 'f', frequency_precsion);
    return f_string.insert (f_string.size () - 3, QChar::Nbsp);
  }

  QString pretty_frequency_MHz_string (double f, int scale, QLocale const& locale)
  {
    auto f_string = locale.toString (f / std::pow (10., scale - 6), 'f', frequency_precsion);
    return f_string.insert (f_string.size () - 3, QChar::Nbsp);
  }

  QString pretty_frequency_MHz_string (FrequencyDelta d, QLocale const& locale)
  {
    auto d_string = locale.toString (d / MHz_factor, 'f', frequency_precsion);
    return d_string.insert (d_string.size () - 3, QChar::Nbsp);
  }

  bool is_callsign (QString const& callsign)
  {
    return callsign.contains (valid_callsign_regexp);
  }

  // Strict ITU-format callsign validation
  // Returns true only if the callsign (or its base part for compound calls)
  // matches a real amateur radio callsign structure.
  // Filters out: "1A", "X5", "NOISE3Z", hash fragments, free-text tokens
  bool is_valid_callsign (QString const& callsign)
  {
    if (callsign.isEmpty () || callsign.size () < 3) return false;

    // Skip known message tokens
    auto upper = callsign.toUpper ().trimmed ();
    if (message_tokens.contains (upper)) return false;

    // For compound calls (VP8/G4XYZ, G4XYZ/P), validate the base part
    QString base = upper;
    if (upper.contains ('/'))
      {
        // Split and validate the longer part (the actual callsign)
        auto parts = upper.split ('/');
        base = parts[0];
        for (auto const& p : parts)
          {
            if (p.size () > base.size ()) base = p;
          }
        // Short suffixes like /P /M /R /MM /AM /QRP are OK — just validate base
      }

    // Must be 3-10 chars, only A-Z and 0-9
    if (base.size () < 3 || base.size () > 10) return false;
    static QRegularExpression alpha_num_only {R"(^[A-Z0-9]+$)"};
    if (!alpha_num_only.match (base).hasMatch ()) return false;

    // Must contain at least one digit AND at least one letter
    bool has_digit = false, has_letter = false;
    for (auto const& c : base)
      {
        if (c.isDigit ()) has_digit = true;
        if (c.isLetter ()) has_letter = true;
      }
    if (!has_digit || !has_letter) return false;

    // ITU structural check on base callsign:
    // Valid prefix patterns followed by 1-4 letter suffix
    // Pattern: (1-2 letters + digit) OR (digit + letter + digit) OR (letter + digit + letter)
    //          followed by optional extra digit, then 1-4 suffix letters
    if (!itu_callsign_re.match (base).hasMatch ()) return false;

    return true;
  }

  bool is_compound_callsign (QString const& callsign)
  {
    return callsign.contains ('/');
  }

  bool is_77bit_nonstandard_callsign (QString const& callsign)
  {
    return callsign.contains (callsign_alphabet_re)
      && !callsign.contains (strict_standard_callsign_re);
  }

  // split on first '/' and return the larger portion or the whole if
  // there is no '/'
  QString base_callsign (QString callsign)
  {
    auto slash_pos = callsign.indexOf ('/');
    if (slash_pos >= 0)
      {
        auto right_size = callsign.size () - slash_pos - 1;
        if (right_size>= slash_pos)
          {
            callsign = callsign.mid (slash_pos + 1);
          }
        else
          {
            callsign = callsign.left (slash_pos);
          }
      }
    return callsign.toUpper ();
  }

  // analyze the callsign and determine the effective prefix, returns
  // the full call if no valid prefix (or prefix as a suffix) is specified
  QString effective_prefix (QString callsign)
  {
    auto prefix = callsign;
    auto slash_pos = callsign.indexOf ('/');
    if (slash_pos >= 0)
      {
        auto right_size = callsign.size () - slash_pos - 1;
        if (right_size >= slash_pos) // native call is longer than
                                     // prefix/suffix algorithm
          {
            prefix = callsign.left (slash_pos);
          }
        else
          {
            prefix = callsign.mid (slash_pos + 1);
            if (prefix.contains (non_prefix_suffix))
              {
                prefix = callsign.left (slash_pos); // ignore
                                                    // non-prefix
                                                    // suffixes
              }
          }
      }
    return prefix.toUpper ();
  }
}

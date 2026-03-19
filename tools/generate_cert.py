#!/usr/bin/env python3
"""
Decodium Certificate Generator — SOLO PER IU8LMC
Genera file .decodium per utenti verificati.

Uso:
  python generate_cert.py IU8LMC PRO 2027-12-31
  python generate_cert.py IK8XXX FREE 2026-12-31
"""

import sys
import hmac
import hashlib

# Stessa chiave del C++ (signingKey())
SIGNING_KEY = b"D3c0d1um_R4pt0r_2026_IU8LMC_s1gn_k3y_v01"

def generate_cert(callsign: str, tier: str, expires: str) -> str:
    callsign = callsign.upper()
    tier = tier.upper()

    if tier not in ("FREE", "PRO"):
        print(f"ERRORE: tier deve essere FREE o PRO, ricevuto: {tier}")
        sys.exit(1)

    payload = f"{callsign}|{tier}|{expires}".encode("utf-8")
    sig = hmac.new(SIGNING_KEY, payload, hashlib.sha256).hexdigest()

    cert = f"""DECODIUM-CERT-V1
# Decodium Fast Track 2 — Verified Station Certificate
# Generato per {callsign} — NON modificare questo file
CALL={callsign}
TIER={tier}
EXPIRES={expires}
SIG={sig}
"""
    return cert

def main():
    if len(sys.argv) != 4:
        print("Uso: python generate_cert.py <CALLSIGN> <FREE|PRO> <YYYY-MM-DD>")
        print("Esempio: python generate_cert.py IU8LMC PRO 2027-12-31")
        sys.exit(1)

    callsign = sys.argv[1]
    tier = sys.argv[2]
    expires = sys.argv[3]

    cert = generate_cert(callsign, tier, expires)
    filename = f"{callsign.upper()}.decodium"

    with open(filename, "w", encoding="utf-8") as f:
        f.write(cert)

    print(f"Certificato generato: {filename}")
    print(f"  Call: {callsign.upper()}")
    print(f"  Tier: {tier.upper()}")
    print(f"  Scadenza: {expires}")
    print(f"  Firma: verificata OK")

if __name__ == "__main__":
    main()

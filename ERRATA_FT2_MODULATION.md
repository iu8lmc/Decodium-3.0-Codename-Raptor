# Errata Corrige — FT2 Modulation Parameters

**Date:** February 27, 2026
**From:** IU8LMC — Decodium Project
**To:** Decodium community

---

## Summary

Previous documentation and website descriptions of the FT2 mode contained an error regarding the modulation type. This notice corrects the record.

## What was stated (incorrect)

- Modulation: **8-GFSK**
- Tones: **8**
- Tone spacing: **~17 Hz**
- Bandwidth: **~150 Hz**

## What the code actually implements (correct)

- Modulation: **4-GFSK**
- Tones: **4** (values 0, 1, 2, 3)
- Tone spacing: **~33.3 Hz** (hmod × baud = 0.8 × 41.67)
- Bandwidth: **~167 Hz**
- Encoding: LDPC(174,91) — identical to FT4 and FT8
- Sync: Four 4×4 Costas arrays — identical to FT4
- Frame: 103 symbols + 2 ramp = 105 total — identical to FT4

## What FT2 actually is

FT2 is FT4 with the symbol rate doubled. The only protocol-level change from FT4 is a single parameter:

| Parameter | FT4 | FT2 |
|-----------|-----|-----|
| NSPS (samples per symbol) | 576 | **288** |
| Symbol rate | 20.83 baud | **41.67 baud** |
| TX duration | 5.04 s | **2.52 s** |
| T/R period | 7.5 s | **3.75 s** |

Everything else — LDPC code, Costas arrays, Grayscale mapping, scrambling vector, frame structure — is identical to FT4.

This is confirmed by the source code:
- `lib/ft2/genft2.f90` is identical to `lib/ft4/genft4.f90`
- `lib/ft2/ft2_params.f90` differs from `lib/ft4/ft4_params.f90` only in NSPS and its derived constants
- `lib/ft2/foxgenft2.f90` line 7 (written by the original WSJT-X authors): *"FT2 signals are ~167 Hz wide (4-GFSK, baud=41.667 Hz)"*

## Impact on users

**None.** The software has always transmitted and decoded correctly using 4-GFSK. The error was limited to the documentation and website descriptions. No software update is needed. All QSOs made with FT2 are valid.

## How this happened

The modulation parameters of FT8 (which does use 8-GFSK with 8 tones) were mistakenly attributed to FT2 during the preparation of the technical documentation. The error was not caught before publication because FT2 was described as a "new mode" rather than what it actually is: an accelerated FT4.

## Corrective actions

1. Website and GitHub documentation updated to reflect the correct parameters
2. This errata notice published for transparency
3. README and release notes corrected

We apologize for the confusion and thank the community members who brought this to our attention.

---

*Decodium 3.0 — FT2 Raptor*
*https://github.com/iu8lmc/Decodium-3.0-Codename-Raptor*

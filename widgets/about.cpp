#include "about.h"

#include <QCoreApplication>
#include <QDateTime>
#include <QString>

#include "revision_utils.hpp"

#include "ui_about.h"

CAboutDlg::CAboutDlg(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::CAboutDlg)
{
  ui->setupUi(this);

  ui->labelTxt->setText(
    // Decodium FT2 logo on top
    "<p align=\"center\"><img src=\":/ft2logo.png\" width=\"180\" height=\"180\" /></p>"
    "<h2 align=\"center\">Decodium v3.0 FT2</h2>"
    "<h3 align=\"center\">Codename: <i>Raptor</i></h3>"
    "<p align=\"center\" style=\"font-size:14px;\"><b>Build 2603080003</b></p>"
    "<p align=\"center\">"
    "<a href=\"https://buymeacoffee.com/iu8lmc\" style=\""
    "background-color:#FFDD00;color:#000000;font-family:Arial,sans-serif;"
    "font-size:14px;font-weight:bold;padding:8px 18px;border-radius:6px;"
    "border:2px solid #000000;text-decoration:none;display:inline-block;\">"
    "&#9749; Buy me a coffee</a></p>"
    "<hr>"
    "<p align=\"center\"><b>Mod by IU8LMC</b> — <a href=\"https://www.qrz.com/db/IU8LMC\">qrz.com/db/IU8LMC</a></p>"
    "<p>Decodium v3.0 FT2 <i>\"Raptor\"</i> is an optimized weak-signal digital "
    "communication client focused exclusively on the FT2 mode (3.75s period, 4-GFSK). "
    "Enhanced decoder sensitivity, extended frequency range, and real-time "
    "NTP/DT feedback for maximum decoding performance.</p>"
    "<hr>"
    "<h3 align=\"center\">Built-in Alert Engine (replaces JTAlert)</h3>"
    "<p><b>12 Audio Alerts:</b> CQ, MyCall, DXCC, DXCCOnBand, Grid, GridOnBand, "
    "Continent, ContinentOnBand, CQZone, CQZoneOnBand, ITUZone, ITUZoneOnBand</p>"
    "<p><b>B4 Tracking:</b> strikethrough + color highlight per type "
    "(call, country, grid, continent, zone)</p>"
    "<p><b>DXCC / Country / Zone lookup:</b> integrated cty.dat with auto-update</p>"
    "<p><b>Customizable Color Highlights:</b> CQ, MyCall, DXCC, Grid, "
    "Continent, Zone, LoTW</p>"
    "<p><b>LoTW User Highlighting:</b> stations on LoTW shown with distinct color</p>"
    "<p><b>Auto CQ with Caller Queue:</b> dedicated Tab 2, FIFO queue (max 20)</p>"
    "<p><b>Logging:</b> N1MM Logger+, Cloudlog, LoTW</p>"
    "<p><b>No B4 Filter:</b> hide stations already worked on band</p>"
    "<p><b>Multiplier Tracking:</b> per-contest mult counting</p>"
    "<p><b>DX Call Alert:</b> audio + visual alert on specific callsigns</p>"
    "<hr>"
    "<p><b>FT2 Decoder:</b> syncmin 0.90, OSD depth 3, 4-pass subtraction, "
    "MAXCAND 300, freq range 200-4910 Hz, 2 Hz grid, SNR floor -21 dB</p>"
    "<hr>"
    "<p>&copy; 2001-2026 by Joe Taylor, K1JT, Bill Somerville, G4WJS, "
    "Steve Franke, K9AN, Nico Palermo, IV3NWV, "
    "Uwe Risse, DG2YCB, Brian Moran, N9ADG, "
    "and Roger Rehr, W3SZ.</p>"
    "<p>We gratefully acknowledge contributions from AC6SL, AE4JY, "
    "DF2ET, DJ0OT, DL3WDG, EA4AC, G4KLA, IW3RAB, JA7UDE, "
    "K3WYC, KA1GT, KA6MAL, KA9Q, KB1ZMX, KD6EKQ, KG4IYS, KI7MT, "
    "KK1D, ND0B, PY1ZRJ, PY2SDR, VE1SKY, VK3ACF, VK4BDJ, "
    "VK7MO, VR2UPU, W3DJS, W4TI, W4TV, and W9MDB.</p>"
    "<hr>"
    "<p><b>Bundled Tools:</b></p>"
    "<p><b>ChronoGPS v2.4.6</b> — GPS/NTP time synchronization<br>"
    "by Yoshiharu Tsukuura, <b>JP1LRT</b> — "
    "<a href=\"https://github.com/jp1lrt/ChronoGPS\">github.com/jp1lrt/ChronoGPS</a><br>"
    "MIT License &copy; 2026 JP1LRT</p>"
    "<p align=\"center\"><img src=\":/icon_128x128.png\" /></p>"
    "<p>Decodium v3.0 FT2 is licensed under the terms of Version 3 "
    "of the <a href=\"https://www.gnu.org/licenses/gpl-3.0.txt\">GNU General Public License (GPL)</a></p>");
}

CAboutDlg::~CAboutDlg()
{
}

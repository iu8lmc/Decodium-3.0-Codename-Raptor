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
    "<p align=\"center\"><img src=\":/ft2logo.png\" width=\"180\" height=\"180\" /></p>"
    "<h2 align=\"center\">Decodium Fast Track 2</h2>"
    "<h3 align=\"center\"><i>" + tr("Official Release") + "</i></h3>"
    "<p align=\"center\" style=\"font-size:14px;\"><b>Build 2603171536</b></p>"
    "<p align=\"center\">"
    "<a href=\"https://buymeacoffee.com/iu8lmc\" style=\""
    "background-color:#FFDD00;color:#000000;font-family:Arial,sans-serif;"
    "font-size:14px;font-weight:bold;padding:8px 18px;border-radius:6px;"
    "border:2px solid #000000;text-decoration:none;display:inline-block;\">"
    "&#9749; Buy me a coffee</a></p>"
    "<hr>"
    "<p align=\"center\"><b>Mod by IU8LMC</b> — <a href=\"https://www.qrz.com/db/IU8LMC\">qrz.com/db/IU8LMC</a></p>"
    "<p>" + tr("Decodium Fast Track 2 is an asynchronous weak-signal digital "
    "communication client focused on the FT2 mode (3.75s period, 4-GFSK). "
    "Async TX without period synchronization, enhanced decoder sensitivity, "
    "extended frequency range for maximum decoding performance.") + "</p>"
    "<hr>"
    "<h3 align=\"center\">" + tr("Built-in Alert Engine (replaces JTAlert)") + "</h3>"
    "<p><b>" + tr("12 Audio Alerts:") + "</b> CQ, MyCall, DXCC, DXCCOnBand, Grid, GridOnBand, "
    "Continent, ContinentOnBand, CQZone, CQZoneOnBand, ITUZone, ITUZoneOnBand</p>"
    "<p><b>" + tr("B4 Tracking:") + "</b> " +
    tr("strikethrough + color highlight per type (call, country, grid, continent, zone)") + "</p>"
    "<p><b>" + tr("DXCC / Country / Zone lookup:") + "</b> " +
    tr("integrated cty.dat with auto-update") + "</p>"
    "<p><b>" + tr("Customizable Color Highlights:") + "</b> CQ, MyCall, DXCC, Grid, "
    "Continent, Zone, LoTW</p>"
    "<p><b>" + tr("LoTW User Highlighting:") + "</b> " +
    tr("stations on LoTW shown with distinct color") + "</p>"
    "<p><b>" + tr("Auto CQ with Caller Queue:") + "</b> " +
    tr("dedicated Tab 2, FIFO queue (max 20)") + "</p>"
    "<p><b>" + tr("Logging:") + "</b> N1MM Logger+, Cloudlog, LoTW</p>"
    "<p><b>" + tr("No B4 Filter:") + "</b> " +
    tr("hide stations already worked on band") + "</p>"
    "<p><b>" + tr("DX Call Alert:") + "</b> " +
    tr("audio + visual alert on specific callsigns") + "</p>"
    "<hr>"
    "<p><b>" + tr("FT2 Decoder:") + "</b> syncmin 0.90, OSD depth 3, 4-pass subtraction, "
    "MAXCAND 300, freq range 200-4910 Hz, 2 Hz grid, SNR floor -21 dB</p>"
    "<hr>"
    "<p>&copy; 2001-2026 by Joe Taylor, K1JT, Bill Somerville, G4WJS, "
    "Steve Franke, K9AN, Nico Palermo, IV3NWV, "
    "Uwe Risse, DG2YCB, Brian Moran, N9ADG, "
    "and Roger Rehr, W3SZ.</p>"
    "<p>" + tr("We gratefully acknowledge contributions from") + " AC6SL, AE4JY, "
    "DF2ET, DJ0OT, DL3WDG, EA4AC, G4KLA, IW3RAB, JA7UDE, "
    "K3WYC, KA1GT, KA6MAL, KA9Q, KB1ZMX, KD6EKQ, KG4IYS, KI7MT, "
    "KK1D, ND0B, PY1ZRJ, PY2SDR, VE1SKY, VK3ACF, VK4BDJ, "
    "VK7MO, VR2UPU, W3DJS, W4TI, W4TV, " + tr("and") + " W9MDB.</p>"
    "<p align=\"center\"><img src=\":/icon_128x128.png\" /></p>"
    "<p>" + tr("Decodium Fast Track 2 is licensed under the terms of Version 3 "
    "of the GNU General Public License (GPL).") + "</p>");
}

CAboutDlg::~CAboutDlg()
{
}

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
    "<p align=\"center\" style=\"font-size:14px;\"><b>Vers.2602260045</b></p>"
    "<hr>"
    "<p align=\"center\"><b>Mod by IU8LMC</b> - <a href=\"https://www.qrz.com/db/IU8LMC\">qrz.com/db/IU8LMC</a></p>"
    "<p>Decodium v3.0 FT2 <i>\"Raptor\"</i> is an optimized weak-signal digital "
    "communication client focused exclusively on the FT2 mode (3.75s period, 4-GFSK). "
    "Enhanced decoder sensitivity, extended frequency range, and real-time "
    "NTP/DT feedback for maximum decoding performance.</p>"
    "<p><b>FT2 Enhancements:</b> syncmin 0.82, OSD depth 4, 4-pass subtraction, "
    "MAXCAND 300, freq range 200-5500 Hz, 2 Hz grid, SNR floor -24 dB</p>"
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
    "<p align=\"center\"><img src=\":/icon_128x128.png\" /></p>"
    "<p>Decodium v3.0 FT2 is licensed under the terms of Version 3 "
    "of the <a href=\"https://www.gnu.org/licenses/gpl-3.0.txt\">GNU General Public License (GPL)</a></p>");
}

CAboutDlg::~CAboutDlg()
{
}

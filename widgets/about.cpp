#include "about.h"

#include <QCoreApplication>
#include <QString>

#include "revision_utils.hpp"

#include "ui_about.h"

CAboutDlg::CAboutDlg(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::CAboutDlg)
{
  ui->setupUi(this);

  QString versionStr = QString{"Decodium 3 FT2 v"
                                + QCoreApplication::applicationVersion()
                                + " " + revision()}.simplified();

  ui->labelTxt->setText(
    "<h2>" + versionStr + "</h2>"
    "<p><b>Mod by IU8LMC</b> - <a href=\"https://www.qrz.com/db/IU8LMC\">qrz.com/db/IU8LMC</a></p>"
    "<p>Decodium 3 FT2 implements a number of digital modes designed for "
    "weak-signal Amateur Radio communication.</p>"
    "<p>&copy; 2001-2025 by Joe Taylor, K1JT, Bill Somerville, G4WJS, "
    "Steve Franke, K9AN, Nico Palermo, IV3NWV, "
    "Uwe Risse, DG2YCB, Brian Moran, N9ADG, "
    "and Roger Rehr, W3SZ.</p>"
    "<p>We gratefully acknowledge contributions from AC6SL, AE4JY, "
    "DF2ET, DJ0OT, DL3WDG, EA4AC, G4KLA, IW3RAB, JA7UDE, "
    "K3WYC, KA1GT, KA6MAL, KA9Q, KB1ZMX, KD6EKQ, KG4IYS, KI7MT, "
    "KK1D, ND0B, PY1ZRJ, PY2SDR, VE1SKY, VK3ACF, VK4BDJ, "
    "VK7MO, VR2UPU, W3DJS, W4TI, W4TV, and W9MDB.</p>"
    "<p><img src=\":/icon_128x128.png\" /></p>"
    "<p>Decodium 3 FT2 is licensed under the terms of Version 3 "
    "of the <a href=\"https://www.gnu.org/licenses/gpl-3.0.txt\">GNU General Public License (GPL)</a></p>");
}

CAboutDlg::~CAboutDlg()
{
}

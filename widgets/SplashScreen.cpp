#include "SplashScreen.hpp"

#include <QPixmap>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QCoreApplication>
#include <QDesktopServices>
#include <QUrl>
#include <QTimer>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QFont>
#include <QApplication>
#include <QDesktopWidget>

#include "revision_utils.hpp"
#include "pimpl_impl.hpp"

#include "moc_SplashScreen.cpp"

class SplashScreen::impl
{
public:
  impl ()
    : checkbox_ {"Do not show this again"}
  {
    main_layout_.addStretch ();
    main_layout_.addWidget (&checkbox_, 0, Qt::AlignRight);
  }

  QVBoxLayout main_layout_;
  QCheckBox checkbox_;
};

SplashScreen::SplashScreen ()
  : QSplashScreen {QPixmap {1, 1}, Qt::WindowStaysOnTopHint}
{
  // Hide the default QSplashScreen pixmap — we use a custom dialog instead
  setPixmap (QPixmap (1, 1));

  // Create the banner dialog
  auto *banner = new QWidget (nullptr, Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
  banner->setAttribute (Qt::WA_DeleteOnClose);
  banner->setFixedSize (520, 580);
  banner->setStyleSheet (
    "QWidget#bannerBg {"
    "  background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
    "    stop:0 #0a0e27, stop:0.5 #1a1e3a, stop:1 #0a0e27);"
    "  border: 2px solid #3a7bd5;"
    "  border-radius: 16px;"
    "}"
  );
  banner->setObjectName ("bannerBg");

  auto *layout = new QVBoxLayout (banner);
  layout->setContentsMargins (30, 25, 30, 25);
  layout->setSpacing (12);

  // Logo
  auto *logoLabel = new QLabel;
  QPixmap logo (":/ft2logo.png");
  if (!logo.isNull ()) {
    logoLabel->setPixmap (logo.scaled (140, 140, Qt::KeepAspectRatio, Qt::SmoothTransformation));
  }
  logoLabel->setAlignment (Qt::AlignCenter);
  layout->addWidget (logoLabel);

  // Title
  auto *title = new QLabel ("DECODIUM SHANNON");
  title->setAlignment (Qt::AlignCenter);
  title->setStyleSheet (
    "color: #ffffff; font-size: 26px; font-weight: bold;"
    "font-family: 'Segoe UI', Arial, sans-serif; letter-spacing: 3px;"
  );
  layout->addWidget (title);

  // Subtitle — edition name
  auto *subtitle = new QLabel ("FT2 Shannon Edition");
  subtitle->setAlignment (Qt::AlignCenter);
  subtitle->setStyleSheet (
    "color: #ffcc44; font-size: 15px; font-weight: bold; letter-spacing: 1px;"
    "font-family: 'Segoe UI', Arial, sans-serif;"
  );
  layout->addWidget (subtitle);

  // Separator
  auto *sep = new QLabel;
  sep->setFixedHeight (2);
  sep->setStyleSheet ("background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
    "stop:0 transparent, stop:0.2 #3a7bd5, stop:0.8 #3a7bd5, stop:1 transparent);");
  layout->addWidget (sep);

  // Slogan — bilingual quote
  auto *slogan = new QLabel (
    "<p style='text-align:center; color:#e0e0e0; font-size:14px; line-height:1.6;'>"
    "<span style='color:#7eb8ff; font-style:italic;'>"
    "&ldquo;It&apos;s not about more power. It&apos;s about better math.&rdquo;</span><br>"
    "<span style='color:#aaccff; font-style:italic;'>"
    "&ldquo;Non ci vuole pi&ugrave; potenza. Ci vuole pi&ugrave; matematica.&rdquo;</span><br><br>"
    "<span style='color:#8888aa; font-size:12px;'>"
    "Dedicato a Claude Shannon (1916&ndash;2001)<br>"
    "padre della teoria dell&apos;informazione</span></p>"
  );
  slogan->setAlignment (Qt::AlignCenter);
  slogan->setTextFormat (Qt::RichText);
  layout->addWidget (slogan);

  layout->addSpacing (8);

  // Coffee section
  auto *helpTitle = new QLabel ("Aiutaci a migliorare Decodium!");
  helpTitle->setAlignment (Qt::AlignCenter);
  helpTitle->setStyleSheet (
    "color: #ffffff; font-size: 16px; font-weight: bold;"
    "font-family: 'Segoe UI', Arial, sans-serif;"
  );
  layout->addWidget (helpTitle);

  auto *coffeeBtn = new QPushButton (QString::fromUtf8 ("  \u2615 Help us grow  "));
  coffeeBtn->setCursor (Qt::PointingHandCursor);
  coffeeBtn->setFixedSize (240, 44);
  coffeeBtn->setStyleSheet (
    "QPushButton {"
    "  background-color: #FFDD00; color: #000000;"
    "  font-family: 'Segoe UI', Arial, sans-serif;"
    "  font-size: 16px; font-weight: bold;"
    "  padding: 8px 18px; border-radius: 8px;"
    "  border: 2px solid #000000;"
    "}"
    "QPushButton:hover {"
    "  background-color: #FFE84D;"
    "  border-color: #333333;"
    "}"
  );
  auto *coffeeLay = new QHBoxLayout;
  coffeeLay->addStretch ();
  coffeeLay->addWidget (coffeeBtn);
  coffeeLay->addStretch ();
  layout->addLayout (coffeeLay);

  connect (coffeeBtn, &QPushButton::clicked, [] () {
    QDesktopServices::openUrl (QUrl ("https://pay.sumup.com/b2c/QFI3ZQYH"));
  });

  layout->addSpacing (8);

  // OK button
  auto *okBtn = new QPushButton ("OK");
  okBtn->setFixedSize (100, 36);
  okBtn->setCursor (Qt::PointingHandCursor);
  okBtn->setStyleSheet (
    "QPushButton {"
    "  background-color: #3a7bd5; color: #ffffff;"
    "  font-size: 14px; font-weight: bold;"
    "  border-radius: 6px; border: none;"
    "}"
    "QPushButton:hover {"
    "  background-color: #5a9bf5;"
    "}"
  );
  auto *okLay = new QHBoxLayout;
  okLay->addStretch ();
  okLay->addWidget (okBtn);
  okLay->addStretch ();
  layout->addLayout (okLay);

  connect (okBtn, &QPushButton::clicked, banner, &QWidget::close);

  // Version footer
  auto *ver = new QLabel (program_title (revision ()));
  ver->setAlignment (Qt::AlignCenter);
  ver->setStyleSheet ("color: #666688; font-size: 11px;");
  layout->addWidget (ver);

  // Author
  auto *author = new QLabel ("by IU8LMC - qrz.com/db/IU8LMC");
  author->setAlignment (Qt::AlignCenter);
  author->setStyleSheet ("color: #555577; font-size: 11px;");
  layout->addWidget (author);

  // Auto-fade after 10 seconds
  QTimer::singleShot (10000, banner, [banner] () {
    if (!banner->isVisible ()) return;
    auto *effect = new QGraphicsOpacityEffect (banner);
    banner->setGraphicsEffect (effect);
    auto *anim = new QPropertyAnimation (effect, "opacity", banner);
    anim->setDuration (1500);
    anim->setStartValue (1.0);
    anim->setEndValue (0.0);
    connect (anim, &QPropertyAnimation::finished, banner, &QWidget::close);
    anim->start (QAbstractAnimation::DeleteWhenStopped);
  });

  // Center on screen and show
  banner->show ();
  auto geo = QApplication::desktop ()->availableGeometry (banner);
  banner->move (geo.center () - banner->rect ().center ());

  setLayout (&m_->main_layout_);
  connect (&m_->checkbox_, &QCheckBox::stateChanged, [this] (int s) {
      if (Qt::Checked == s) Q_EMIT disabled ();
    });
}

SplashScreen::~SplashScreen ()
{
}

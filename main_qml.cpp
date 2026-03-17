#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QFont>
#include <QIcon>
#include <QDir>
#include <QCoreApplication>
#include <QTimer>
#include <QDateTime>
#include <QRegularExpression>
#include <cstring>
#include <cmath>

#include "commons.h"
#include "widgets/itoneAndicw.h"

// Global variables shared with Fortran and C++ backend
int volatile itone[MAX_NUM_SYMBOLS];
int volatile icw[NUM_CW_SYMBOLS];
dec_data_t dec_data;

// Fortran TX encoding functions (extern "C")
// fortran_charlen_t is the hidden string-length argument appended by gfortran
typedef int fortran_charlen_t;
extern "C" {
    void genft8_(char* msg, int* i3, int* n3, char* msgsent,
                 char ft8msgbits[], int itone[],
                 fortran_charlen_t msg_len, fortran_charlen_t msgsent_len);
    void genft2_(char* msg, int* ichk, char* msgsent,
                 char ft2msgbits[], int itone[],
                 fortran_charlen_t msg_len, fortran_charlen_t msgsent_len);
    void genft4_(char* msg, int* ichk, char* msgsent,
                 char ft4msgbits[], int itone[],
                 fortran_charlen_t msg_len, fortran_charlen_t msgsent_len);
    void genfst4_(char* msg, int* ichk, char* msgsent, int itone[],
                  int* iwspr, int* nwave, int* nfst4w,
                  fortran_charlen_t msg_len, fortran_charlen_t msgsent_len);
    void genq65_(char* msg, int* ichk, char* msgsent, int itone[],
                 int* i3, int* n3,
                 fortran_charlen_t msg_len, fortran_charlen_t msgsent_len);
    // Note: MSK144 TX encoding not available in desktop build (requires crc13 from Boost)
    // void genmsk_128_90_(char* msg, int* ichk, char* msgsent, int itone[],
    //                     int* itype,
    //                     fortran_charlen_t msg_len, fortran_charlen_t msgsent_len);
}

// Avoid macro clash with AudioController::RX_SAMPLE_RATE
#undef RX_SAMPLE_RATE

#include "controllers/AppController.hpp"
#include "controllers/RadioController.hpp"
#include "controllers/DecoderController.hpp"
#include "controllers/AudioController.hpp"
#include "controllers/TxController.hpp"
#include "controllers/LogController.hpp"
#include "controllers/WaterfallController.hpp"
#include "controllers/DecodeListModel.hpp"
#include "controllers/PSKReporterLite.hpp"
#include "controllers/ActiveStationsModel.hpp"
#include "qmlitems/WaterfallItem.hpp"
#include "Audio/NetworkAudioInput.hpp"
#include "Audio/soundout.h"
#include "Network/NtpClient.hpp"
#include "Network/FoxVerifier.hpp"
#include "otpgenerator.h"

// ── Helper: sync decoder settings from AppController ──
static void syncDecoderSettings(AppController &app, DecoderController &dec)
{
    dec.setFt8Sensitivity(app.ft8Sensitivity());
    dec.setFt8Cycles(app.ft8Cycles());
    dec.setFt8Threads(app.ft8Threads());
    dec.setFt8DecoderStart(app.ft8DecoderStart());
    dec.setFt4Depth(app.ft4Depth());
    dec.setNtrials10(app.ntrials10());
    dec.setMultithreadFT8(app.multithreadFT8());
    dec.setHideFT8Dupes(app.hideFT8Dupes());
    dec.setWideDxCallSearch(app.wideDxCallSearch());
}

int main(int argc, char *argv[])
{
    fprintf(stderr, "Decodium3 starting...\n"); fflush(stderr);
    QGuiApplication app(argc, argv);
    fprintf(stderr, "QGuiApplication created\n"); fflush(stderr);
    app.setOrganizationName("Decodium");
    app.setOrganizationDomain("decodium.radio");
    app.setApplicationName("Decodium 3 FT2");
    app.setApplicationVersion("3.0.0");

    // Set default font
    QFont defaultFont("Segoe UI", 10);
    app.setFont(defaultFont);

    // Use Qt Quick Controls Material style as base
    QQuickStyle::setStyle("Basic");

    // Create controllers
    AppController appController;
    RadioController radioController;
    DecoderController decoderController;
    AudioController audioController;
    TxController txController;
    LogController logController;
    WaterfallController waterfallController;
    DecodeListModel decodeListModel;
    DecodeListModel decodeModelP1;
    DecodeListModel decodeModelP2;
    DecodeListModel decodeModelRx;
    ActiveStationsModel activeStationsModel;

    // Create NTP client
    NtpClient ntpClient;

    // Create PSK Reporter
    PSKReporterLite pskReporter;

    // ── FASE 1: Sync decoder settings on startup and changes ──
    syncDecoderSettings(appController, decoderController);
    QObject::connect(&appController, &AppController::decoderSettingsChanged,
                     [&appController, &decoderController]() {
        syncDecoderSettings(appController, decoderController);
    });

    // ── Sync Cloudlog settings ──
    logController.setCloudlogEnabled(appController.cloudlogEnabled());
    logController.setCloudlogUrl(appController.cloudlogUrl());
    logController.setCloudlogApiKey(appController.cloudlogApiKey());
    QObject::connect(&appController, &AppController::cloudlogEnabledChanged,
                     [&appController, &logController]() {
        logController.setCloudlogEnabled(appController.cloudlogEnabled());
    });
    QObject::connect(&appController, &AppController::cloudlogUrlChanged,
                     [&appController, &logController]() {
        logController.setCloudlogUrl(appController.cloudlogUrl());
    });
    QObject::connect(&appController, &AppController::cloudlogApiKeyChanged,
                     [&appController, &logController]() {
        logController.setCloudlogApiKey(appController.cloudlogApiKey());
    });

    // ── FASE 7: NTP wiring ──
    QObject::connect(&ntpClient, &NtpClient::offsetUpdated,
                     [&appController](double offsetMs) {
        appController.setNtpOffsetMs(offsetMs);
    });
    QObject::connect(&ntpClient, &NtpClient::syncStatusChanged,
                     [&appController](bool synced, const QString &) {
        appController.setNtpSynced(synced);
    });
    QObject::connect(&appController, &AppController::ntpEnabledChanged,
                     [&appController, &ntpClient]() {
        ntpClient.setEnabled(appController.ntpEnabled());
    });
    // Start NTP if enabled
    ntpClient.setEnabled(appController.ntpEnabled());

    // ── PSK Reporter wiring ──
    pskReporter.setLocalStation(appController.callsign(), appController.grid(),
                                 QString(), QStringLiteral("Decodium3 3.0.0"));
    pskReporter.setEnabled(appController.pskReporterEnabled());
    QObject::connect(&appController, &AppController::pskReporterEnabledChanged,
                     [&appController, &pskReporter]() {
        pskReporter.setEnabled(appController.pskReporterEnabled());
    });
    QObject::connect(&appController, &AppController::callsignChanged,
                     [&appController, &pskReporter]() {
        pskReporter.setLocalStation(appController.callsign(), appController.grid(),
                                     QString(), QStringLiteral("Decodium3 3.0.0"));
    });

    // Connect controllers: radio mode → audio/decoder
    QObject::connect(&radioController, &RadioController::modeChanged,
                     [&audioController, &radioController]() {
        audioController.onModeChanged(radioController.mode());
    });
    QObject::connect(&radioController, &RadioController::modeChanged,
                     [&decoderController, &radioController]() {
        decoderController.setCurrentMode(radioController.mode());
    });

    // Connect audio → decoder: frames written triggers decode timing + spectrum
    QObject::connect(&audioController, &AudioController::framesWritten,
                     &decoderController, &DecoderController::onFramesWritten);

    // Connect decoder spectrum → waterfall display
    QObject::connect(&decoderController, &DecoderController::spectrumData,
                     &waterfallController, &WaterfallController::onSpectrumData);

    // WiFi CAT: forward radio changes to bridge when in WiFi mode
    QObject::connect(&radioController, &RadioController::dialFrequencyChanged,
                     [&audioController, &radioController]() {
        audioController.sendCatFreqToBridge(
            static_cast<quint64>(radioController.dialFrequency()));
    });
    QObject::connect(&radioController, &RadioController::modeChanged,
                     [&audioController, &radioController]() {
        audioController.sendCatModeToBridge(radioController.mode());
    });

    // ─── TX Encoding: txRequested → genXX_ → Modulator::start ───
    QObject::connect(&txController, &TxController::txRequested,
                     [&radioController, &audioController, &waterfallController,
                      &txController, &decoderController](const QString &message) {
        QString mode = radioController.mode();
        int txFreq = waterfallController.txFreq();

        // Prepare Fortran message buffers (37 chars, space-padded)
        char msg[37], msgsent[37], msgbits[77];
        std::memset(msg, ' ', 37);
        std::memset(msgsent, ' ', 37);
        std::memset(msgbits, 0, 77);
        QByteArray msgBytes = message.toLatin1();
        std::memcpy(msg, msgBytes.constData(), qMin(msgBytes.size(), 37));

        unsigned nsym = 79;
        double framesPerSymbol = 1920.0;
        double toneSpacing = 6.25;
        double trPeriod = 15.0;

        if (mode == QLatin1String("FT8")) {
            int i3 = 0, n3 = 0;
            genft8_(msg, &i3, &n3, msgsent, msgbits,
                    const_cast<int*>(itone), 37, 37);
            nsym = 79;
            framesPerSymbol = 1920.0;
            toneSpacing = 6.25;
            trPeriod = 15.0;
        } else if (mode == QLatin1String("FT2")) {
            int ichk = 0;
            genft2_(msg, &ichk, msgsent, msgbits,
                    const_cast<int*>(itone), 37, 37);
            nsym = 103;
            framesPerSymbol = 288.0;
            toneSpacing = 0.0;
            trPeriod = 3.75;
        } else if (mode == QLatin1String("FT4")) {
            int ichk = 0;
            genft4_(msg, &ichk, msgsent, msgbits,
                    const_cast<int*>(itone), 37, 37);
            nsym = 103;
            framesPerSymbol = 576.0;
            toneSpacing = 0.0;
            trPeriod = 7.5;
        } else if (mode == QLatin1String("FST4")) {
            int ichk = 0, iwspr = 0, nwave = 0, nfst4w = 0;
            genfst4_(msg, &ichk, msgsent, const_cast<int*>(itone),
                     &iwspr, &nwave, &nfst4w, 37, 37);
            nsym = nwave > 0 ? nwave : 800;
            framesPerSymbol = 800.0;    // depends on T/R period
            toneSpacing = 1.464;
            trPeriod = decoderController.period();
        } else if (mode == QLatin1String("Q65")) {
            int ichk = 0, i3 = 0, n3 = 0;
            genq65_(msg, &ichk, msgsent, const_cast<int*>(itone),
                    &i3, &n3, 37, 37);
            nsym = 85;
            framesPerSymbol = static_cast<double>(decoderController.period() * 12000 / 85);
            toneSpacing = 0.0;
            trPeriod = decoderController.period();
        } else if (mode == QLatin1String("MSK144")) {
            // MSK144 TX encoding not yet available (decode-only mode)
            qWarning() << "TX: MSK144 encoding not available in this build";
            return;
        } else {
            qWarning() << "TX: unsupported mode" << mode;
            return;
        }

        qDebug() << "TX: encoded" << message << "for" << mode
                 << "nsym=" << nsym << "freq=" << txFreq;

        // Start Modulator (pulls from itone[] via readData)
        Modulator *mod = audioController.modulator();
        SoundOutput *sout = audioController.wifiMode()
                                ? nullptr : audioController.soundOutput();
        if (mod) {
            mod->start(mode, nsym, framesPerSymbol,
                       static_cast<double>(txFreq), toneSpacing,
                       sout, AudioDevice::Mono,
                       true, false, 99.0, trPeriod);
        }

        // In WiFi mode, also send PTT to bridge
        if (audioController.wifiMode()) {
            audioController.sendCatPttToBridge(true);
        }
    });

    // TX halt: stop Modulator
    QObject::connect(&txController, &TxController::haltRequested,
                     [&audioController]() {
        Modulator *mod = audioController.modulator();
        if (mod) mod->stop(true);
        if (audioController.wifiMode()) {
            audioController.sendCatPttToBridge(false);
        }
    });

    // ── FASE 4: Connect decoder → TxController auto-sequence ──
    QObject::connect(&decoderController, &DecoderController::newDecode,
                     [&txController, &appController](
                         const QString &utc, int snr, double dt,
                         int freq, const QString &message) {
        txController.processDecodedMessage(utc, snr, dt, freq, message,
                                            appController.callsign(),
                                            appController.grid());
    });

    // ── FASE 5: Connect TxController rxFreqRequested → waterfall ──
    QObject::connect(&txController, &TxController::rxFreqRequested,
                     &waterfallController, &WaterfallController::setRxFreq);

    // ── FASE 6: Connect QSO complete → log ──
    QObject::connect(&txController, &TxController::qsoComplete,
                     [&logController, &radioController, &decoderController](
                         const QString &call, const QString &grid,
                         const QString &rptSent, const QString &rptRcvd) {
        logController.logQSO(call, grid, decoderController.currentMode(),
                              rptSent, rptRcvd, radioController.dialFrequency());
    });

    // ── FASE 8: Color highlighting + B4 tracking + PSK Reporter in newDecode handler ──
    QObject::connect(&decoderController, &DecoderController::newDecode,
                     [&decodeListModel, &decodeModelP1, &decodeModelP2,
                      &decodeModelRx, &waterfallController, &appController,
                      &logController, &radioController, &pskReporter,
                      &activeStationsModel](
                         const QString &utc, int snr, double dt,
                         int freq, const QString &message) {
        QString myCall = appController.callsign();
        bool isCQ = message.startsWith(QStringLiteral("CQ "));
        bool isDirected = !myCall.isEmpty() && message.contains(myCall);

        // B4 check: extract callsign from message
        bool isB4 = false;
        QString senderCall;
        QStringList parts = message.trimmed().split(QRegularExpression("\\s+"));
        if (isCQ && parts.size() >= 2) {
            int callIdx = 1;
            if (parts.size() > 2 && parts[1].length() <= 3) callIdx = 2;
            if (callIdx < parts.size()) senderCall = parts[callIdx];
        } else if (parts.size() >= 2) {
            // Non-CQ: sender is typically second word for directed, or first word
            if (parts[0] == myCall && parts.size() >= 2) {
                senderCall = parts[1];
            } else {
                senderCall = parts[0];
            }
        }

        // Check B4 against log
        if (!senderCall.isEmpty()) {
            QString band = logController.bandFromFrequency(radioController.dialFrequency());
            isB4 = logController.isCallWorked(senderCall, band);
        }

        // ── Color logic (configurable via AppController highlight colors) ──
        QColor color;
        bool has73 = message.contains(QStringLiteral("73")) || message.contains(QStringLiteral("RR73"));
        if (isDirected) {
            color = appController.colorMyCall();
        } else if (has73) {
            color = appController.color73();
        } else if (isCQ && !isB4) {
            color = appController.colorCQ();
        } else if (isCQ && isB4) {
            color = appController.colorB4();
        } else {
            color = QColor(QStringLiteral("#B0BEC5"));    // grey — normal
        }

        // LOTW user check
        bool isLotw = false;
        if (logController.lotwEnabled() && !senderCall.isEmpty()) {
            isLotw = logController.isLotwUser(senderCall);
        }

        // Add to the combined model
        decodeListModel.addDecode(utc, snr, dt, freq, message, isCQ, isDirected,
                                   color, isB4, isDirected, isLotw);

        // Determine period from UTC seconds
        int secs = utc.right(2).toInt();
        bool isEven = (secs == 0 || secs == 30);
        if (isEven)
            decodeModelP1.addDecode(utc, snr, dt, freq, message, isCQ, isDirected,
                                     color, isB4, isDirected, isLotw);
        else
            decodeModelP2.addDecode(utc, snr, dt, freq, message, isCQ, isDirected,
                                     color, isB4, isDirected, isLotw);

        // Add to RX freq model if within ±100 Hz of current rxFreq
        int rxFreq = waterfallController.rxFreq();
        if (qAbs(freq - rxFreq) <= 100)
            decodeModelRx.addDecode(utc, snr, dt, freq, message, isCQ, isDirected,
                                     color, isB4, isDirected, isLotw);

        // ── FASE 6: PSK Reporter spot ──
        if (pskReporter.isEnabled() && !senderCall.isEmpty()) {
            QString senderGrid;
            // Try to extract grid from CQ messages
            if (isCQ) {
                int callIdx = 1;
                if (parts.size() > 2 && parts[1].length() <= 3) callIdx = 2;
                if (callIdx + 1 < parts.size()) {
                    QString possibleGrid = parts[callIdx + 1];
                    if (possibleGrid.length() >= 4
                        && possibleGrid[0].isLetter() && possibleGrid[1].isLetter()
                        && possibleGrid[2].isDigit() && possibleGrid[3].isDigit()) {
                        senderGrid = possibleGrid;
                    }
                }
            }
            quint64 absFreq = static_cast<quint64>(radioController.dialFrequency()) + freq;
            pskReporter.addSpot(senderCall, senderGrid, absFreq,
                                 radioController.mode(), snr);
        }

        // ── Active stations tracking ──
        if (!senderCall.isEmpty()) {
            QString senderGrid;
            if (isCQ) {
                int callIdx2 = 1;
                if (parts.size() > 2 && parts[1].length() <= 3) callIdx2 = 2;
                if (callIdx2 + 1 < parts.size()) {
                    QString pg = parts[callIdx2 + 1];
                    if (pg.length() >= 4 && pg[0].isLetter() && pg[1].isLetter()
                        && pg[2].isDigit() && pg[3].isDigit())
                        senderGrid = pg;
                }
            }
            activeStationsModel.addStation(senderCall, freq, snr, senderGrid, utc);
            // Mark LOTW user if enabled
            if (logController.lotwEnabled()) {
                activeStationsModel.markLotwUser(senderCall, logController.isLotwUser(senderCall));
            }
        }
    });

    // Clear all decode models at the start of each decoding period
    QObject::connect(&decoderController, &DecoderController::decodingStarted,
                     [&decodeListModel, &decodeModelP1, &decodeModelP2, &decodeModelRx,
                      &activeStationsModel]() {
        decodeListModel.clear();
        decodeModelP1.clear();
        decodeModelP2.clear();
        decodeModelRx.clear();
        activeStationsModel.ageAllStations();
    });

    // ── C17: SuperFox OTP verification ──
    // When SuperFox mode is active and a decode contains an OTP code, verify it
    QNetworkAccessManager *foxNam = new QNetworkAccessManager(&app);
    QObject::connect(&decoderController, &DecoderController::newDecode,
                     [&txController, foxNam](
                         const QString &utc, int snr, double dt,
                         int freq, const QString &message) {
        if (!txController.superFoxMode()) return;

        // SuperFox OTP pattern: message ends with a 6-digit code
        static QRegularExpression otpRe("\\b([A-Z0-9/]+)\\s+(\\d{6})\\s*$");
        auto match = otpRe.match(message);
        if (!match.hasMatch()) return;

        QString foxCall = match.captured(1);
        QString otpCode = match.captured(2);

        // Create verifier for this OTP
        QDateTime ts = QDateTime::currentDateTimeUtc();
        auto *verifier = new FoxVerifier(
            QStringLiteral("Decodium3/1.0"), foxNam,
            FoxVerifier::default_url(),
            foxCall, ts, otpCode, static_cast<unsigned int>(freq));

        QObject::connect(verifier, &FoxVerifier::verifyComplete,
                         [verifier](int status, QDateTime, QString callsign,
                                    QString, unsigned int hz, const QString &response) {
            qDebug() << "FoxVerifier: VERIFIED" << callsign << "at" << hz << "Hz -" << response;
            verifier->deleteLater();
        });
        QObject::connect(verifier, &FoxVerifier::verifyError,
                         [verifier](int status, QDateTime, QString callsign,
                                    QString, unsigned int, const QString &error) {
            qDebug() << "FoxVerifier: FAILED" << callsign << "-" << error;
            verifier->deleteLater();
        });
    });

    // Pass callsign/grid to decoder when they change
    QObject::connect(&appController, &AppController::callsignChanged,
                     [&decoderController, &appController]() {
        decoderController.setMyCall(appController.callsign());
    });
    QObject::connect(&appController, &AppController::gridChanged,
                     [&decoderController, &appController]() {
        decoderController.setMyGrid(appController.grid());
    });
    // Pass hisCall and TX state to decoder for hint/AP
    QObject::connect(&txController, &TxController::hisCallChanged,
                     [&decoderController, &txController]() {
        decoderController.setHisCall(txController.hisCall());
    });
    QObject::connect(&txController, &TxController::transmittingChanged,
                     [&decoderController, &txController]() {
        decoderController.setTxing(txController.transmitting());
    });
    QObject::connect(&txController, &TxController::txEnabledChanged,
                     [&decoderController, &txController]() {
        decoderController.setEnableTx(txController.txEnabled());
    });

    // Pass RX frequency to decoder
    QObject::connect(&waterfallController, &WaterfallController::rxFreqChanged,
                     [&decoderController, &waterfallController]() {
        decoderController.setNfqso(waterfallController.rxFreq());
    });

    // WiFi CAT: when bridge connects, wire CAT status feedback to RadioController
    QObject::connect(&audioController, &AudioController::bridgeConnectedChanged,
                     [&audioController, &radioController]() {
        auto *netInput = audioController.networkInput();
        if (netInput && audioController.bridgeConnected()) {
            QObject::disconnect(netInput, &NetworkAudioInput::catStatusReceived,
                                nullptr, nullptr);
            QObject::connect(netInput, &NetworkAudioInput::catStatusReceived,
                             [&radioController](quint64 freq, quint8 /*mode*/,
                                                bool /*ptt*/, qint16 /*sMeter*/) {
                radioController.setDialFrequency(static_cast<double>(freq));
            });
        }
    });

    // ── cty.dat update → reload country data in log controller ──
    QObject::connect(&appController, &AppController::ctyDatUpdated,
                     &logController, &LogController::reloadCtyDat);

    // ── Fox/Hound: pass mode to decoder params ──
    QObject::connect(&txController, &TxController::houndModeChanged,
                     [&decoderController, &txController]() {
        decoderController.setHoundMode(txController.houndMode());
    });
    QObject::connect(&txController, &TxController::superFoxModeChanged,
                     [&decoderController, &txController]() {
        decoderController.setSuperFoxMode(txController.superFoxMode());
    });

    // ── Decoder watchdog warning ──
    QObject::connect(&decoderController, &DecoderController::decoderWatchdogTriggered,
                     []() {
        qWarning() << "main: Decoder watchdog triggered — consider reducing decode depth";
    });

    // ── Fox mode → waterfall Fox slot markers ──
    QObject::connect(&txController, &TxController::foxModeChanged,
                     [&txController, &waterfallController]() {
        if (txController.foxMode()) {
            waterfallController.updateFoxMarkers(1000, 5, 200);  // base 1000 Hz, 5 slots, 200 Hz spacing
        } else {
            waterfallController.setFoxSlotMarkers(QVariantList());
        }
    });

    // ── Alert sounds on newDecode ──
    QObject::connect(&decoderController, &DecoderController::newDecode,
                     [&appController](
                         const QString &, int, double,
                         int, const QString &message) {
        if (!appController.alertSoundsEnabled()) return;
        QString myCall = appController.callsign();
        if (!myCall.isEmpty() && message.contains(myCall)) {
            appController.playAlert(QStringLiteral("MyCall"));
        } else if (message.startsWith(QStringLiteral("CQ "))) {
            appController.playAlert(QStringLiteral("CQ"));
        }
    });

    // ── FT2 soft avg reset on mode change ──
    QObject::connect(&decoderController, &DecoderController::currentModeChanged,
                     [&decoderController]() {
        decoderController.resetFt2SoftAvg();
    });

    // Initialize decoder with current settings
    decoderController.setMyCall(appController.callsign());
    decoderController.setMyGrid(appController.grid());
    decoderController.setNfqso(waterfallController.rxFreq());

    // Initialize audio subsystem
    audioController.initialize();

    // Register QML types
    qmlRegisterType<WaterfallItem>("Decodium", 1, 0, "WaterfallItem");

    // Create QML engine
    QQmlApplicationEngine engine;

    // Import path for Decodium QML module (qrc resources)
    engine.addImportPath("qrc:/");

    // Import path for Qt QML modules next to the executable
    QString appDir = QCoreApplication::applicationDirPath();
    engine.addImportPath(appDir + "/qml");

    // Expose controllers to QML
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("app", &appController);
    ctx->setContextProperty("radio", &radioController);
    ctx->setContextProperty("decoder", &decoderController);
    ctx->setContextProperty("audio", &audioController);
    ctx->setContextProperty("tx", &txController);
    ctx->setContextProperty("log", &logController);
    ctx->setContextProperty("waterfall", &waterfallController);
    ctx->setContextProperty("decodeModel", &decodeListModel);
    ctx->setContextProperty("decodeModelP1", &decodeModelP1);
    ctx->setContextProperty("decodeModelP2", &decodeModelP2);
    ctx->setContextProperty("decodeModelRx", &decodeModelRx);
    ctx->setContextProperty("activeStations", &activeStationsModel);
    ctx->setContextProperty("logController", &logController);

    // Load main QML
    qDebug() << "Loading QML from qrc:/qml/main.qml ...";
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) {
            fprintf(stderr, "FATAL: QML object creation failed for %s\n",
                    objUrl.toString().toUtf8().constData());
            fflush(stderr);
            QCoreApplication::exit(-1);
        }
    }, Qt::QueuedConnection);

    // Catch QML warnings
    qInstallMessageHandler([](QtMsgType type, const QMessageLogContext &ctx, const QString &msg) {
        fprintf(stderr, "[Qt] %s\n", msg.toUtf8().constData());
        fflush(stderr);
    });

    fprintf(stderr, "Loading QML...\n"); fflush(stderr);
    engine.load(url);
    fprintf(stderr, "QML loaded, root objects: %d\n", engine.rootObjects().size());
    fflush(stderr);

    // ── FASE 3: guiUpdate timer (100ms) ──
    // TX/RX timing, auto-CQ repeat, TX watchdog, period-based TX start
    QTimer guiUpdateTimer;
    guiUpdateTimer.setInterval(100);

    QObject::connect(&guiUpdateTimer, &QTimer::timeout,
                     [&decoderController, &txController, &audioController,
                      &appController, &radioController, &waterfallController,
                      &pskReporter]() {
        // Get current UTC time
        QDateTime utcNow = QDateTime::currentDateTimeUtc();
        double currentSec = utcNow.time().minute() * 60.0
                          + utcNow.time().second()
                          + utcNow.time().msec() / 1000.0;

        double period = decoderController.period();
        double secInPeriod = std::fmod(currentSec, period);
        int periodIndex = static_cast<int>(currentSec / period);
        bool isEvenPeriod = (periodIndex % 2 == 0);

        // Determine if this is our TX period
        int txPeriod = txController.txPeriod(); // 0=even, 1=odd
        bool isOurTxPeriod = (txPeriod == 0) ? isEvenPeriod : !isEvenPeriod;

        // ── TX Watchdog ──
        txController.tickWatchdog();

        // ── TX Timing: Start TX at the beginning of our TX period ──
        if (txController.txEnabled() && !txController.transmitting()
            && isOurTxPeriod && secInPeriod < 1.0) {
            // Start transmitting the currently selected message
            QString msg = txController.currentTxMessage();
            if (!msg.isEmpty()) {
                txController.sendMessage(txController.activeTxMessage());
            }
        }

        // ── Stop TX at end of TX period ──
        if (txController.transmitting() && !isOurTxPeriod && secInPeriod < 1.0) {
            // TX period is over, stop
            Modulator *mod = audioController.modulator();
            if (mod) mod->stop(true);
            if (audioController.wifiMode()) {
                audioController.sendCatPttToBridge(false);
            }
            // Don't call halt() — keep txEnabled for next cycle
        }

        // ── Auto-CQ repeat ──
        if (txController.autoCQ() && !txController.transmitting()
            && txController.qsoProgress() == TxController::CALLING
            && isOurTxPeriod && secInPeriod < 1.0) {
            txController.startCQ();
        }

        // ── PSK Reporter: flush periodically (handled by its own timer) ──
    });

    guiUpdateTimer.start();

    // Auto-start monitoring if QML loaded successfully
    if (!engine.rootObjects().isEmpty()) {
        qDebug() << "Auto-starting audio monitoring...";
        audioController.startMonitoring();
    }

    return app.exec();
}

/****************************************************************************
** Meta object code from reading C++ file 'MessageClient.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Network/MessageClient.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageClient.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MessageClient_t {
    QByteArrayData data[120];
    char stringdata0[1216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MessageClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MessageClient_t qt_meta_stringdata_MessageClient = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MessageClient"
QT_MOC_LITERAL(1, 14, 13), // "clear_decodes"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 6), // "window"
QT_MOC_LITERAL(4, 36, 5), // "reply"
QT_MOC_LITERAL(5, 42, 3), // "snr"
QT_MOC_LITERAL(6, 46, 10), // "delta_time"
QT_MOC_LITERAL(7, 57, 15), // "delta_frequency"
QT_MOC_LITERAL(8, 73, 4), // "mode"
QT_MOC_LITERAL(9, 78, 12), // "message_text"
QT_MOC_LITERAL(10, 91, 14), // "low_confidence"
QT_MOC_LITERAL(11, 106, 9), // "modifiers"
QT_MOC_LITERAL(12, 116, 5), // "close"
QT_MOC_LITERAL(13, 122, 6), // "replay"
QT_MOC_LITERAL(14, 129, 7), // "halt_tx"
QT_MOC_LITERAL(15, 137, 9), // "auto_only"
QT_MOC_LITERAL(16, 147, 9), // "free_text"
QT_MOC_LITERAL(17, 157, 4), // "send"
QT_MOC_LITERAL(18, 162, 18), // "highlight_callsign"
QT_MOC_LITERAL(19, 181, 8), // "callsign"
QT_MOC_LITERAL(20, 190, 2), // "bg"
QT_MOC_LITERAL(21, 193, 2), // "fg"
QT_MOC_LITERAL(22, 196, 9), // "last_only"
QT_MOC_LITERAL(23, 206, 20), // "switch_configuration"
QT_MOC_LITERAL(24, 227, 18), // "configuration_name"
QT_MOC_LITERAL(25, 246, 9), // "configure"
QT_MOC_LITERAL(26, 256, 19), // "frequency_tolerance"
QT_MOC_LITERAL(27, 276, 7), // "submode"
QT_MOC_LITERAL(28, 284, 9), // "fast_mode"
QT_MOC_LITERAL(29, 294, 9), // "tr_period"
QT_MOC_LITERAL(30, 304, 5), // "rx_df"
QT_MOC_LITERAL(31, 310, 7), // "dx_call"
QT_MOC_LITERAL(32, 318, 7), // "dx_grid"
QT_MOC_LITERAL(33, 326, 17), // "generate_messages"
QT_MOC_LITERAL(34, 344, 15), // "annotation_info"
QT_MOC_LITERAL(35, 360, 19), // "sort_order_provided"
QT_MOC_LITERAL(36, 380, 10), // "sort_order"
QT_MOC_LITERAL(37, 391, 5), // "error"
QT_MOC_LITERAL(38, 397, 8), // "location"
QT_MOC_LITERAL(39, 406, 8), // "setup_tx"
QT_MOC_LITERAL(40, 415, 11), // "newTxMsgIdx"
QT_MOC_LITERAL(41, 427, 3), // "msg"
QT_MOC_LITERAL(42, 431, 8), // "skipGrid"
QT_MOC_LITERAL(43, 440, 7), // "useRR73"
QT_MOC_LITERAL(44, 448, 5), // "check"
QT_MOC_LITERAL(45, 454, 6), // "offset"
QT_MOC_LITERAL(46, 461, 10), // "set_server"
QT_MOC_LITERAL(47, 472, 11), // "server_name"
QT_MOC_LITERAL(48, 484, 23), // "network_interface_names"
QT_MOC_LITERAL(49, 508, 15), // "set_server_port"
QT_MOC_LITERAL(50, 524, 9), // "port_type"
QT_MOC_LITERAL(51, 534, 11), // "server_port"
QT_MOC_LITERAL(52, 546, 7), // "set_TTL"
QT_MOC_LITERAL(53, 554, 3), // "TTL"
QT_MOC_LITERAL(54, 558, 6), // "enable"
QT_MOC_LITERAL(55, 565, 13), // "status_update"
QT_MOC_LITERAL(56, 579, 9), // "Frequency"
QT_MOC_LITERAL(57, 589, 6), // "report"
QT_MOC_LITERAL(58, 596, 7), // "tx_mode"
QT_MOC_LITERAL(59, 604, 10), // "tx_enabled"
QT_MOC_LITERAL(60, 615, 12), // "transmitting"
QT_MOC_LITERAL(61, 628, 8), // "decoding"
QT_MOC_LITERAL(62, 637, 5), // "tx_df"
QT_MOC_LITERAL(63, 643, 7), // "de_call"
QT_MOC_LITERAL(64, 651, 7), // "de_grid"
QT_MOC_LITERAL(65, 659, 16), // "watchdog_timeout"
QT_MOC_LITERAL(66, 676, 8), // "sub_mode"
QT_MOC_LITERAL(67, 685, 15), // "special_op_mode"
QT_MOC_LITERAL(68, 701, 9), // "lastTxMsg"
QT_MOC_LITERAL(69, 711, 11), // "qsoProgress"
QT_MOC_LITERAL(70, 723, 7), // "txFirst"
QT_MOC_LITERAL(71, 731, 6), // "cQOnly"
QT_MOC_LITERAL(72, 738, 6), // "genMsg"
QT_MOC_LITERAL(73, 745, 9), // "txHaltClk"
QT_MOC_LITERAL(74, 755, 13), // "txEnableState"
QT_MOC_LITERAL(75, 769, 11), // "txEnableClk"
QT_MOC_LITERAL(76, 781, 11), // "myContinent"
QT_MOC_LITERAL(77, 793, 11), // "metricUnits"
QT_MOC_LITERAL(78, 805, 6), // "decode"
QT_MOC_LITERAL(79, 812, 6), // "is_new"
QT_MOC_LITERAL(80, 819, 4), // "time"
QT_MOC_LITERAL(81, 824, 7), // "message"
QT_MOC_LITERAL(82, 832, 7), // "off_air"
QT_MOC_LITERAL(83, 840, 14), // "enqueue_decode"
QT_MOC_LITERAL(84, 855, 7), // "autoGen"
QT_MOC_LITERAL(85, 863, 4), // "isDx"
QT_MOC_LITERAL(86, 868, 8), // "modifier"
QT_MOC_LITERAL(87, 877, 15), // "isNewCallOnBand"
QT_MOC_LITERAL(88, 893, 9), // "isNewCall"
QT_MOC_LITERAL(89, 903, 18), // "isNewCountryOnBand"
QT_MOC_LITERAL(90, 922, 12), // "isNewCountry"
QT_MOC_LITERAL(91, 935, 7), // "country"
QT_MOC_LITERAL(92, 943, 9), // "continent"
QT_MOC_LITERAL(93, 953, 2), // "az"
QT_MOC_LITERAL(94, 956, 4), // "dist"
QT_MOC_LITERAL(95, 961, 11), // "WSPR_decode"
QT_MOC_LITERAL(96, 973, 5), // "drift"
QT_MOC_LITERAL(97, 979, 4), // "grid"
QT_MOC_LITERAL(98, 984, 5), // "power"
QT_MOC_LITERAL(99, 990, 15), // "decodes_cleared"
QT_MOC_LITERAL(100, 1006, 10), // "qso_logged"
QT_MOC_LITERAL(101, 1017, 8), // "time_off"
QT_MOC_LITERAL(102, 1026, 14), // "dial_frequency"
QT_MOC_LITERAL(103, 1041, 11), // "report_sent"
QT_MOC_LITERAL(104, 1053, 15), // "report_received"
QT_MOC_LITERAL(105, 1069, 8), // "tx_power"
QT_MOC_LITERAL(106, 1078, 8), // "comments"
QT_MOC_LITERAL(107, 1087, 4), // "name"
QT_MOC_LITERAL(108, 1092, 7), // "time_on"
QT_MOC_LITERAL(109, 1100, 13), // "operator_call"
QT_MOC_LITERAL(110, 1114, 7), // "my_call"
QT_MOC_LITERAL(111, 1122, 7), // "my_grid"
QT_MOC_LITERAL(112, 1130, 13), // "exchange_sent"
QT_MOC_LITERAL(113, 1144, 13), // "exchange_rcvd"
QT_MOC_LITERAL(114, 1158, 8), // "propmode"
QT_MOC_LITERAL(115, 1167, 9), // "satellite"
QT_MOC_LITERAL(116, 1177, 7), // "satmode"
QT_MOC_LITERAL(117, 1185, 6), // "freqRx"
QT_MOC_LITERAL(118, 1192, 11), // "logged_ADIF"
QT_MOC_LITERAL(119, 1204, 11) // "ADIF_record"

    },
    "MessageClient\0clear_decodes\0\0window\0"
    "reply\0snr\0delta_time\0delta_frequency\0"
    "mode\0message_text\0low_confidence\0"
    "modifiers\0close\0replay\0halt_tx\0auto_only\0"
    "free_text\0send\0highlight_callsign\0"
    "callsign\0bg\0fg\0last_only\0switch_configuration\0"
    "configuration_name\0configure\0"
    "frequency_tolerance\0submode\0fast_mode\0"
    "tr_period\0rx_df\0dx_call\0dx_grid\0"
    "generate_messages\0annotation_info\0"
    "sort_order_provided\0sort_order\0error\0"
    "location\0setup_tx\0newTxMsgIdx\0msg\0"
    "skipGrid\0useRR73\0check\0offset\0set_server\0"
    "server_name\0network_interface_names\0"
    "set_server_port\0port_type\0server_port\0"
    "set_TTL\0TTL\0enable\0status_update\0"
    "Frequency\0report\0tx_mode\0tx_enabled\0"
    "transmitting\0decoding\0tx_df\0de_call\0"
    "de_grid\0watchdog_timeout\0sub_mode\0"
    "special_op_mode\0lastTxMsg\0qsoProgress\0"
    "txFirst\0cQOnly\0genMsg\0txHaltClk\0"
    "txEnableState\0txEnableClk\0myContinent\0"
    "metricUnits\0decode\0is_new\0time\0message\0"
    "off_air\0enqueue_decode\0autoGen\0isDx\0"
    "modifier\0isNewCallOnBand\0isNewCall\0"
    "isNewCountryOnBand\0isNewCountry\0country\0"
    "continent\0az\0dist\0WSPR_decode\0drift\0"
    "grid\0power\0decodes_cleared\0qso_logged\0"
    "time_off\0dial_frequency\0report_sent\0"
    "report_received\0tx_power\0comments\0"
    "name\0time_on\0operator_call\0my_call\0"
    "my_grid\0exchange_sent\0exchange_rcvd\0"
    "propmode\0satellite\0satmode\0freqRx\0"
    "logged_ADIF\0ADIF_record"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  139,    2, 0x06 /* Public */,
       4,    8,  142,    2, 0x06 /* Public */,
      12,    0,  159,    2, 0x06 /* Public */,
      13,    0,  160,    2, 0x06 /* Public */,
      14,    1,  161,    2, 0x06 /* Public */,
      16,    2,  164,    2, 0x06 /* Public */,
      18,    4,  169,    2, 0x06 /* Public */,
      23,    1,  178,    2, 0x06 /* Public */,
      25,    9,  181,    2, 0x06 /* Public */,
      34,    3,  200,    2, 0x06 /* Public */,
      37,    1,  207,    2, 0x06 /* Public */,
      38,    1,  210,    2, 0x06 /* Public */,
      39,    6,  213,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      46,    2,  226,    2, 0x0a /* Public */,
      49,    1,  231,    2, 0x0a /* Public */,
      49,    0,  234,    2, 0x2a /* Public | MethodCloned */,
      52,    1,  235,    2, 0x0a /* Public */,
      54,    1,  238,    2, 0x0a /* Public */,
      55,   30,  241,    2, 0x0a /* Public */,
      78,    9,  302,    2, 0x0a /* Public */,
      83,   17,  321,    2, 0x0a /* Public */,
      95,   10,  356,    2, 0x0a /* Public */,
      99,    0,  377,    2, 0x0a /* Public */,
     100,   20,  378,    2, 0x0a /* Public */,
     118,    1,  419,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar,    3,
    QMetaType::Void, QMetaType::QTime, QMetaType::Int, QMetaType::Float, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::UChar,    2,    5,    6,    7,    8,    9,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor, QMetaType::QColor, QMetaType::Bool,   19,   20,   21,   22,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::QString, QMetaType::Bool, QMetaType::UInt, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    8,   26,   27,   28,   29,   30,   31,   32,   33,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::UInt,   31,   35,   36,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::QString, QMetaType::UInt,   40,   41,   42,   43,   44,   45,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,   47,   48,
    QMetaType::Void, 0x80000000 | 50,   51,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   53,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 56, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::UInt, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::UChar, QMetaType::UInt, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::UInt, QMetaType::Bool, QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::QString, QMetaType::Bool,    2,    8,   31,   57,   58,   59,   60,   61,   30,   62,   63,   64,   32,   65,   66,   28,   67,   26,   29,   24,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
    QMetaType::Void, QMetaType::Bool, QMetaType::QTime, QMetaType::Int, QMetaType::Float, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Bool,   79,   80,    5,    6,    7,    8,   81,   10,   82,
    QMetaType::Void, QMetaType::Bool, QMetaType::QTime, QMetaType::Int, QMetaType::Float, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,   84,   80,    5,    6,    7,    8,   81,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,
    QMetaType::Void, QMetaType::Bool, QMetaType::QTime, QMetaType::Int, QMetaType::Float, 0x80000000 | 56, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Bool,   79,   80,    5,    6,    2,   96,   19,   97,   98,   82,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, 0x80000000 | 56, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,  101,   31,   32,  102,    8,  103,  104,  105,  106,  107,  108,  109,  110,  111,  112,  113,  114,  115,  116,  117,
    QMetaType::Void, QMetaType::QByteArray,  119,

       0        // eod
};

void MessageClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MessageClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clear_decodes((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 1: _t->reply((*reinterpret_cast< QTime(*)>(_a[1])),(*reinterpret_cast< qint32(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7])),(*reinterpret_cast< quint8(*)>(_a[8]))); break;
        case 2: _t->close(); break;
        case 3: _t->replay(); break;
        case 4: _t->halt_tx((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->free_text((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->highlight_callsign((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2])),(*reinterpret_cast< const QColor(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 7: _t->switch_configuration((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->configure((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< quint32(*)>(_a[5])),(*reinterpret_cast< quint32(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9]))); break;
        case 9: _t->annotation_info((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 10: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->location((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->setup_tx((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< quint32(*)>(_a[6]))); break;
        case 13: _t->set_server((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2]))); break;
        case 14: _t->set_server_port((*reinterpret_cast< port_type(*)>(_a[1]))); break;
        case 15: _t->set_server_port(); break;
        case 16: _t->set_TTL((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->enable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->status_update((*reinterpret_cast< Frequency(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< quint32(*)>(_a[9])),(*reinterpret_cast< quint32(*)>(_a[10])),(*reinterpret_cast< const QString(*)>(_a[11])),(*reinterpret_cast< const QString(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13])),(*reinterpret_cast< bool(*)>(_a[14])),(*reinterpret_cast< const QString(*)>(_a[15])),(*reinterpret_cast< bool(*)>(_a[16])),(*reinterpret_cast< quint8(*)>(_a[17])),(*reinterpret_cast< quint32(*)>(_a[18])),(*reinterpret_cast< quint32(*)>(_a[19])),(*reinterpret_cast< const QString(*)>(_a[20])),(*reinterpret_cast< const QString(*)>(_a[21])),(*reinterpret_cast< quint32(*)>(_a[22])),(*reinterpret_cast< bool(*)>(_a[23])),(*reinterpret_cast< bool(*)>(_a[24])),(*reinterpret_cast< const QString(*)>(_a[25])),(*reinterpret_cast< bool(*)>(_a[26])),(*reinterpret_cast< bool(*)>(_a[27])),(*reinterpret_cast< bool(*)>(_a[28])),(*reinterpret_cast< const QString(*)>(_a[29])),(*reinterpret_cast< bool(*)>(_a[30]))); break;
        case 19: _t->decode((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QTime(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< quint32(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9]))); break;
        case 20: _t->enqueue_decode((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QTime(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< quint32(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< bool(*)>(_a[10])),(*reinterpret_cast< bool(*)>(_a[11])),(*reinterpret_cast< bool(*)>(_a[12])),(*reinterpret_cast< bool(*)>(_a[13])),(*reinterpret_cast< const QString(*)>(_a[14])),(*reinterpret_cast< const QString(*)>(_a[15])),(*reinterpret_cast< int(*)>(_a[16])),(*reinterpret_cast< int(*)>(_a[17]))); break;
        case 21: _t->WSPR_decode((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QTime(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< Frequency(*)>(_a[5])),(*reinterpret_cast< qint32(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< qint32(*)>(_a[9])),(*reinterpret_cast< bool(*)>(_a[10]))); break;
        case 22: _t->decodes_cleared(); break;
        case 23: _t->qso_logged((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< Frequency(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< const QString(*)>(_a[10])),(*reinterpret_cast< QDateTime(*)>(_a[11])),(*reinterpret_cast< const QString(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13])),(*reinterpret_cast< const QString(*)>(_a[14])),(*reinterpret_cast< const QString(*)>(_a[15])),(*reinterpret_cast< const QString(*)>(_a[16])),(*reinterpret_cast< const QString(*)>(_a[17])),(*reinterpret_cast< const QString(*)>(_a[18])),(*reinterpret_cast< const QString(*)>(_a[19])),(*reinterpret_cast< const QString(*)>(_a[20]))); break;
        case 24: _t->logged_ADIF((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MessageClient::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageClient::clear_decodes)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MessageClient::*)(QTime , qint32 , float , quint32 , QString const & , QString const & , bool , quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageClient::reply)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MessageClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageClient::close)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MessageClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageClient::replay)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MessageClient::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageClient::halt_tx)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MessageClient::*)(QString const & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageClient::free_text)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MessageClient::*)(QString const & , QColor const & , QColor const & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageClient::highlight_callsign)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MessageClient::*)(QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageClient::switch_configuration)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MessageClient::*)(QString const & , quint32 , QString const & , bool , quint32 , quint32 , QString const & , QString const & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageClient::configure)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MessageClient::*)(QString const & , bool , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageClient::annotation_info)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MessageClient::*)(QString const & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageClient::error)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MessageClient::*)(QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageClient::location)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MessageClient::*)(int , QString const & , bool , bool , QString const & , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageClient::setup_tx)) {
                *result = 12;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MessageClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MessageClient.data,
    qt_meta_data_MessageClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MessageClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MessageClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MessageClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void MessageClient::clear_decodes(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MessageClient::reply(QTime _t1, qint32 _t2, float _t3, quint32 _t4, QString const & _t5, QString const & _t6, bool _t7, quint8 _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MessageClient::close()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MessageClient::replay()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MessageClient::halt_tx(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MessageClient::free_text(QString const & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MessageClient::highlight_callsign(QString const & _t1, QColor const & _t2, QColor const & _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MessageClient::switch_configuration(QString const & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MessageClient::configure(QString const & _t1, quint32 _t2, QString const & _t3, bool _t4, quint32 _t5, quint32 _t6, QString const & _t7, QString const & _t8, bool _t9)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MessageClient::annotation_info(QString const & _t1, bool _t2, quint32 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MessageClient::error(QString const & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< MessageClient *>(this), &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MessageClient::location(QString const & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MessageClient::setup_tx(int _t1, QString const & _t2, bool _t3, bool _t4, QString const & _t5, quint32 _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

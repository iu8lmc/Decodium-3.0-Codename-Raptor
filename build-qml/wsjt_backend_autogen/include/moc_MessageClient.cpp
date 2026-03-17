/****************************************************************************
** Meta object code from reading C++ file 'MessageClient.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Network/MessageClient.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageClient.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13MessageClientE_t {};
} // unnamed namespace

template <> constexpr inline auto MessageClient::qt_create_metaobjectdata<qt_meta_tag_ZN13MessageClientE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MessageClient",
        "clear_decodes",
        "",
        "window",
        "reply",
        "snr",
        "delta_time",
        "delta_frequency",
        "mode",
        "message_text",
        "low_confidence",
        "modifiers",
        "close",
        "replay",
        "halt_tx",
        "auto_only",
        "free_text",
        "send",
        "highlight_callsign",
        "callsign",
        "QColor",
        "bg",
        "fg",
        "last_only",
        "switch_configuration",
        "configuration_name",
        "configure",
        "frequency_tolerance",
        "submode",
        "fast_mode",
        "tr_period",
        "rx_df",
        "dx_call",
        "dx_grid",
        "generate_messages",
        "annotation_info",
        "sort_order_provided",
        "sort_order",
        "error",
        "location",
        "setup_tx",
        "newTxMsgIdx",
        "msg",
        "skipGrid",
        "useRR73",
        "check",
        "offset",
        "set_server",
        "server_name",
        "network_interface_names",
        "set_server_port",
        "port_type",
        "server_port",
        "set_TTL",
        "TTL",
        "enable",
        "status_update",
        "Frequency",
        "report",
        "tx_mode",
        "tx_enabled",
        "transmitting",
        "decoding",
        "tx_df",
        "de_call",
        "de_grid",
        "watchdog_timeout",
        "sub_mode",
        "special_op_mode",
        "lastTxMsg",
        "qsoProgress",
        "txFirst",
        "cQOnly",
        "genMsg",
        "txHaltClk",
        "txEnableState",
        "txEnableClk",
        "myContinent",
        "metricUnits",
        "decode",
        "is_new",
        "time",
        "message",
        "off_air",
        "enqueue_decode",
        "autoGen",
        "isDx",
        "modifier",
        "isNewCallOnBand",
        "isNewCall",
        "isNewCountryOnBand",
        "isNewCountry",
        "country",
        "continent",
        "az",
        "dist",
        "WSPR_decode",
        "drift",
        "grid",
        "power",
        "decodes_cleared",
        "qso_logged",
        "time_off",
        "dial_frequency",
        "report_sent",
        "report_received",
        "tx_power",
        "comments",
        "name",
        "time_on",
        "operator_call",
        "my_call",
        "my_grid",
        "exchange_sent",
        "exchange_rcvd",
        "propmode",
        "satellite",
        "satmode",
        "freqRx",
        "logged_ADIF",
        "ADIF_record"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'clear_decodes'
        QtMocHelpers::SignalData<void(quint8)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UChar, 3 },
        }}),
        // Signal 'reply'
        QtMocHelpers::SignalData<void(QTime, qint32, float, quint32, QString const &, QString const &, bool, quint8)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QTime, 2 }, { QMetaType::Int, 5 }, { QMetaType::Float, 6 }, { QMetaType::UInt, 7 },
            { QMetaType::QString, 8 }, { QMetaType::QString, 9 }, { QMetaType::Bool, 10 }, { QMetaType::UChar, 11 },
        }}),
        // Signal 'close'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'replay'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'halt_tx'
        QtMocHelpers::SignalData<void(bool)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 15 },
        }}),
        // Signal 'free_text'
        QtMocHelpers::SignalData<void(QString const &, bool)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::Bool, 17 },
        }}),
        // Signal 'highlight_callsign'
        QtMocHelpers::SignalData<void(QString const &, QColor const &, QColor const &, bool)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 }, { 0x80000000 | 20, 21 }, { 0x80000000 | 20, 22 }, { QMetaType::Bool, 23 },
        }}),
        // Signal 'switch_configuration'
        QtMocHelpers::SignalData<void(QString const &)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 25 },
        }}),
        // Signal 'configure'
        QtMocHelpers::SignalData<void(QString const &, quint32, QString const &, bool, quint32, quint32, QString const &, QString const &, bool)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 }, { QMetaType::UInt, 27 }, { QMetaType::QString, 28 }, { QMetaType::Bool, 29 },
            { QMetaType::UInt, 30 }, { QMetaType::UInt, 31 }, { QMetaType::QString, 32 }, { QMetaType::QString, 33 },
            { QMetaType::Bool, 34 },
        }}),
        // Signal 'annotation_info'
        QtMocHelpers::SignalData<void(QString const &, bool, quint32)>(35, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 32 }, { QMetaType::Bool, 36 }, { QMetaType::UInt, 37 },
        }}),
        // Signal 'error'
        QtMocHelpers::SignalData<void(QString const &) const>(38, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'location'
        QtMocHelpers::SignalData<void(QString const &)>(39, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'setup_tx'
        QtMocHelpers::SignalData<void(int, QString const &, bool, bool, QString const &, quint32)>(40, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 41 }, { QMetaType::QString, 42 }, { QMetaType::Bool, 43 }, { QMetaType::Bool, 44 },
            { QMetaType::QString, 45 }, { QMetaType::UInt, 46 },
        }}),
        // Slot 'set_server'
        QtMocHelpers::SlotData<void(QString const &, QStringList const &)>(47, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 48 }, { QMetaType::QStringList, 49 },
        }}),
        // Slot 'set_server_port'
        QtMocHelpers::SlotData<void(port_type)>(50, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 51, 52 },
        }}),
        // Slot 'set_server_port'
        QtMocHelpers::SlotData<void()>(50, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'set_TTL'
        QtMocHelpers::SlotData<void(int)>(53, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 54 },
        }}),
        // Slot 'enable'
        QtMocHelpers::SlotData<void(bool)>(55, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Slot 'status_update'
        QtMocHelpers::SlotData<void(Frequency, QString const &, QString const &, QString const &, QString const &, bool, bool, bool, quint32, quint32, QString const &, QString const &, QString const &, bool, QString const &, bool, quint8, quint32, quint32, QString const &, QString const &, quint32, bool, bool, QString const &, bool, bool, bool, QString const &, bool)>(56, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 57, 2 }, { QMetaType::QString, 8 }, { QMetaType::QString, 32 }, { QMetaType::QString, 58 },
            { QMetaType::QString, 59 }, { QMetaType::Bool, 60 }, { QMetaType::Bool, 61 }, { QMetaType::Bool, 62 },
            { QMetaType::UInt, 31 }, { QMetaType::UInt, 63 }, { QMetaType::QString, 64 }, { QMetaType::QString, 65 },
            { QMetaType::QString, 33 }, { QMetaType::Bool, 66 }, { QMetaType::QString, 67 }, { QMetaType::Bool, 29 },
            { QMetaType::UChar, 68 }, { QMetaType::UInt, 27 }, { QMetaType::UInt, 30 }, { QMetaType::QString, 25 },
            { QMetaType::QString, 69 }, { QMetaType::UInt, 70 }, { QMetaType::Bool, 71 }, { QMetaType::Bool, 72 },
            { QMetaType::QString, 73 }, { QMetaType::Bool, 74 }, { QMetaType::Bool, 75 }, { QMetaType::Bool, 76 },
            { QMetaType::QString, 77 }, { QMetaType::Bool, 78 },
        }}),
        // Slot 'decode'
        QtMocHelpers::SlotData<void(bool, QTime, qint32, float, quint32, QString const &, QString const &, bool, bool)>(79, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 80 }, { QMetaType::QTime, 81 }, { QMetaType::Int, 5 }, { QMetaType::Float, 6 },
            { QMetaType::UInt, 7 }, { QMetaType::QString, 8 }, { QMetaType::QString, 82 }, { QMetaType::Bool, 10 },
            { QMetaType::Bool, 83 },
        }}),
        // Slot 'enqueue_decode'
        QtMocHelpers::SlotData<void(bool, QTime, qint32, float, quint32, QString const &, QString const &, bool, bool, bool, bool, bool, bool, QString const &, QString const &, int, int)>(84, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 85 }, { QMetaType::QTime, 81 }, { QMetaType::Int, 5 }, { QMetaType::Float, 6 },
            { QMetaType::UInt, 7 }, { QMetaType::QString, 8 }, { QMetaType::QString, 82 }, { QMetaType::Bool, 86 },
            { QMetaType::Bool, 87 }, { QMetaType::Bool, 88 }, { QMetaType::Bool, 89 }, { QMetaType::Bool, 90 },
            { QMetaType::Bool, 91 }, { QMetaType::QString, 92 }, { QMetaType::QString, 93 }, { QMetaType::Int, 94 },
            { QMetaType::Int, 95 },
        }}),
        // Slot 'WSPR_decode'
        QtMocHelpers::SlotData<void(bool, QTime, qint32, float, Frequency, qint32, QString const &, QString const &, qint32, bool)>(96, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 80 }, { QMetaType::QTime, 81 }, { QMetaType::Int, 5 }, { QMetaType::Float, 6 },
            { 0x80000000 | 57, 2 }, { QMetaType::Int, 97 }, { QMetaType::QString, 19 }, { QMetaType::QString, 98 },
            { QMetaType::Int, 99 }, { QMetaType::Bool, 83 },
        }}),
        // Slot 'decodes_cleared'
        QtMocHelpers::SlotData<void()>(100, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'qso_logged'
        QtMocHelpers::SlotData<void(QDateTime, QString const &, QString const &, Frequency, QString const &, QString const &, QString const &, QString const &, QString const &, QString const &, QDateTime, QString const &, QString const &, QString const &, QString const &, QString const &, QString const &, QString const &, QString const &, QString const &)>(101, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDateTime, 102 }, { QMetaType::QString, 32 }, { QMetaType::QString, 33 }, { 0x80000000 | 57, 103 },
            { QMetaType::QString, 8 }, { QMetaType::QString, 104 }, { QMetaType::QString, 105 }, { QMetaType::QString, 106 },
            { QMetaType::QString, 107 }, { QMetaType::QString, 108 }, { QMetaType::QDateTime, 109 }, { QMetaType::QString, 110 },
            { QMetaType::QString, 111 }, { QMetaType::QString, 112 }, { QMetaType::QString, 113 }, { QMetaType::QString, 114 },
            { QMetaType::QString, 115 }, { QMetaType::QString, 116 }, { QMetaType::QString, 117 }, { QMetaType::QString, 118 },
        }}),
        // Slot 'logged_ADIF'
        QtMocHelpers::SlotData<void(QByteArray const &)>(119, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 120 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MessageClient, qt_meta_tag_ZN13MessageClientE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MessageClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13MessageClientE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13MessageClientE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13MessageClientE_t>.metaTypes,
    nullptr
} };

void MessageClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MessageClient *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->clear_decodes((*reinterpret_cast<std::add_pointer_t<quint8>>(_a[1]))); break;
        case 1: _t->reply((*reinterpret_cast<std::add_pointer_t<QTime>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qint32>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<quint8>>(_a[8]))); break;
        case 2: _t->close(); break;
        case 3: _t->replay(); break;
        case 4: _t->halt_tx((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->free_text((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2]))); break;
        case 6: _t->highlight_callsign((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[4]))); break;
        case 7: _t->switch_configuration((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->configure((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[9]))); break;
        case 9: _t->annotation_info((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[3]))); break;
        case 10: _t->error((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->location((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->setup_tx((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[6]))); break;
        case 13: _t->set_server((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 14: _t->set_server_port((*reinterpret_cast<std::add_pointer_t<port_type>>(_a[1]))); break;
        case 15: _t->set_server_port(); break;
        case 16: _t->set_TTL((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->enable((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->status_update((*reinterpret_cast<std::add_pointer_t<Frequency>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[9])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[10])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[11])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[13])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[14])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[15])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[16])),(*reinterpret_cast<std::add_pointer_t<quint8>>(_a[17])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[18])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[19])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[20])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[21])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[22])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[23])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[24])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[25])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[26])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[27])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[28])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[29])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[30]))); break;
        case 19: _t->decode((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QTime>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qint32>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[9]))); break;
        case 20: _t->enqueue_decode((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QTime>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qint32>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[9])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[10])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[11])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[12])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[13])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[14])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[15])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[16])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[17]))); break;
        case 21: _t->WSPR_decode((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QTime>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qint32>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<Frequency>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<qint32>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<qint32>>(_a[9])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[10]))); break;
        case 22: _t->decodes_cleared(); break;
        case 23: _t->qso_logged((*reinterpret_cast<std::add_pointer_t<QDateTime>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<Frequency>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[9])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast<std::add_pointer_t<QDateTime>>(_a[11])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[13])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[14])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[15])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[16])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[17])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[18])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[19])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[20]))); break;
        case 24: _t->logged_ADIF((*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MessageClient::*)(quint8 )>(_a, &MessageClient::clear_decodes, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MessageClient::*)(QTime , qint32 , float , quint32 , QString const & , QString const & , bool , quint8 )>(_a, &MessageClient::reply, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MessageClient::*)()>(_a, &MessageClient::close, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MessageClient::*)()>(_a, &MessageClient::replay, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (MessageClient::*)(bool )>(_a, &MessageClient::halt_tx, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (MessageClient::*)(QString const & , bool )>(_a, &MessageClient::free_text, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (MessageClient::*)(QString const & , QColor const & , QColor const & , bool )>(_a, &MessageClient::highlight_callsign, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (MessageClient::*)(QString const & )>(_a, &MessageClient::switch_configuration, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (MessageClient::*)(QString const & , quint32 , QString const & , bool , quint32 , quint32 , QString const & , QString const & , bool )>(_a, &MessageClient::configure, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (MessageClient::*)(QString const & , bool , quint32 )>(_a, &MessageClient::annotation_info, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (MessageClient::*)(QString const & ) const>(_a, &MessageClient::error, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (MessageClient::*)(QString const & )>(_a, &MessageClient::location, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (MessageClient::*)(int , QString const & , bool , bool , QString const & , quint32 )>(_a, &MessageClient::setup_tx, 12))
            return;
    }
}

const QMetaObject *MessageClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13MessageClientE_t>.strings))
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
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void MessageClient::clear_decodes(quint8 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void MessageClient::reply(QTime _t1, qint32 _t2, float _t3, quint32 _t4, QString const & _t5, QString const & _t6, bool _t7, quint8 _t8)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8);
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
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void MessageClient::free_text(QString const & _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2);
}

// SIGNAL 6
void MessageClient::highlight_callsign(QString const & _t1, QColor const & _t2, QColor const & _t3, bool _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 7
void MessageClient::switch_configuration(QString const & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void MessageClient::configure(QString const & _t1, quint32 _t2, QString const & _t3, bool _t4, quint32 _t5, quint32 _t6, QString const & _t7, QString const & _t8, bool _t9)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9);
}

// SIGNAL 9
void MessageClient::annotation_info(QString const & _t1, bool _t2, quint32 _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1, _t2, _t3);
}

// SIGNAL 10
void MessageClient::error(QString const & _t1)const
{
    QMetaObject::activate<void>(const_cast< MessageClient *>(this), &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void MessageClient::location(QString const & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void MessageClient::setup_tx(int _t1, QString const & _t2, bool _t3, bool _t4, QString const & _t5, quint32 _t6)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1, _t2, _t3, _t4, _t5, _t6);
}
QT_WARNING_POP

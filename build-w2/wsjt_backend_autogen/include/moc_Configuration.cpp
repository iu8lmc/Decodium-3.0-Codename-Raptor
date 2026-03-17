/****************************************************************************
** Meta object code from reading C++ file 'Configuration.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Configuration.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Configuration.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13ConfigurationE_t {};
} // unnamed namespace

template <> constexpr inline auto Configuration::qt_create_metaobjectdata<qt_meta_tag_ZN13ConfigurationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Configuration",
        "text_font_changed",
        "",
        "QFont",
        "decoded_text_font_changed",
        "udp_server_changed",
        "QString&",
        "udp_server_name",
        "network_interfaces",
        "udp_server_port_changed",
        "port_type",
        "server_port",
        "udp_TTL_changed",
        "TTL",
        "accept_udp_requests_changed",
        "checked",
        "decode_highlighting_changed",
        "DecodeHighlightingModel",
        "transceiver_update",
        "Transceiver::TransceiverState",
        "transceiver_TCIframesWritten",
        "transceiver_TCImodActive",
        "leavingSettings",
        "transceiver_failure",
        "reason",
        "enumerating_audio_devices",
        "transceiver_frequency",
        "Frequency",
        "transceiver_tx_frequency",
        "transceiver_mode",
        "MODE",
        "transceiver_ptt",
        "transceiver_audio",
        "transceiver_tune",
        "transceiver_period",
        "transceiver_blocksize",
        "transceiver_modulator_start",
        "transceiver_modulator_stop",
        "transceiver_spread",
        "transceiver_nsym",
        "transceiver_trfrequency",
        "sync_transceiver",
        "force_signal",
        "enforce_mode_and_split",
        "invalidate_audio_input_device",
        "error",
        "invalidate_audio_output_device",
        "transceiver_volume",
        "transceiver_txvolume",
        "DataMode",
        "data_mode_none",
        "data_mode_USB",
        "data_mode_data",
        "Type2MsgGen",
        "type_2_msg_1_full",
        "type_2_msg_3_full",
        "type_2_msg_5_only"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'text_font_changed'
        QtMocHelpers::SignalData<void(QFont) const>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Signal 'decoded_text_font_changed'
        QtMocHelpers::SignalData<void(QFont) const>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Signal 'udp_server_changed'
        QtMocHelpers::SignalData<void(QString &, QStringList const &) const>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 }, { QMetaType::QStringList, 8 },
        }}),
        // Signal 'udp_server_port_changed'
        QtMocHelpers::SignalData<void(port_type) const>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Signal 'udp_TTL_changed'
        QtMocHelpers::SignalData<void(int) const>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 13 },
        }}),
        // Signal 'accept_udp_requests_changed'
        QtMocHelpers::SignalData<void(bool) const>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 15 },
        }}),
        // Signal 'decode_highlighting_changed'
        QtMocHelpers::SignalData<void(DecodeHighlightingModel const &) const>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 17, 2 },
        }}),
        // Signal 'transceiver_update'
        QtMocHelpers::SignalData<void(Transceiver::TransceiverState const &) const>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 19, 2 },
        }}),
        // Signal 'transceiver_TCIframesWritten'
        QtMocHelpers::SignalData<void(qint64) const>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 2 },
        }}),
        // Signal 'transceiver_TCImodActive'
        QtMocHelpers::SignalData<void(bool) const>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Signal 'leavingSettings'
        QtMocHelpers::SignalData<void(bool) const>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Signal 'transceiver_failure'
        QtMocHelpers::SignalData<void(QString const &) const>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 24 },
        }}),
        // Signal 'enumerating_audio_devices'
        QtMocHelpers::SignalData<void()>(25, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'transceiver_frequency'
        QtMocHelpers::SlotData<void(Frequency)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 27, 2 },
        }}),
        // Slot 'transceiver_tx_frequency'
        QtMocHelpers::SlotData<void(Frequency)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 27, 2 },
        }}),
        // Slot 'transceiver_tx_frequency'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'transceiver_mode'
        QtMocHelpers::SlotData<void(MODE)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 30, 2 },
        }}),
        // Slot 'transceiver_ptt'
        QtMocHelpers::SlotData<void(bool)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Slot 'transceiver_ptt'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'transceiver_audio'
        QtMocHelpers::SlotData<void(bool)>(32, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Slot 'transceiver_audio'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'transceiver_tune'
        QtMocHelpers::SlotData<void(bool)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Slot 'transceiver_tune'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'transceiver_period'
        QtMocHelpers::SlotData<void(double)>(34, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 2 },
        }}),
        // Slot 'transceiver_period'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'transceiver_blocksize'
        QtMocHelpers::SlotData<void(qint32)>(35, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Slot 'transceiver_blocksize'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'transceiver_modulator_start'
        QtMocHelpers::SlotData<void(QString, unsigned , double, double, double, bool, bool, double, double)>(36, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::UInt, 2 }, { QMetaType::Double, 2 }, { QMetaType::Double, 2 },
            { QMetaType::Double, 2 }, { QMetaType::Bool, 2 }, { QMetaType::Bool, 2 }, { QMetaType::Double, 2 },
            { QMetaType::Double, 2 },
        }}),
        // Slot 'transceiver_modulator_start'
        QtMocHelpers::SlotData<void(QString, unsigned , double, double, double, bool, bool, double)>(36, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::UInt, 2 }, { QMetaType::Double, 2 }, { QMetaType::Double, 2 },
            { QMetaType::Double, 2 }, { QMetaType::Bool, 2 }, { QMetaType::Bool, 2 }, { QMetaType::Double, 2 },
        }}),
        // Slot 'transceiver_modulator_start'
        QtMocHelpers::SlotData<void(QString, unsigned , double, double, double, bool, bool)>(36, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::UInt, 2 }, { QMetaType::Double, 2 }, { QMetaType::Double, 2 },
            { QMetaType::Double, 2 }, { QMetaType::Bool, 2 }, { QMetaType::Bool, 2 },
        }}),
        // Slot 'transceiver_modulator_start'
        QtMocHelpers::SlotData<void(QString, unsigned , double, double, double, bool)>(36, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::UInt, 2 }, { QMetaType::Double, 2 }, { QMetaType::Double, 2 },
            { QMetaType::Double, 2 }, { QMetaType::Bool, 2 },
        }}),
        // Slot 'transceiver_modulator_start'
        QtMocHelpers::SlotData<void(QString, unsigned , double, double, double)>(36, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::UInt, 2 }, { QMetaType::Double, 2 }, { QMetaType::Double, 2 },
            { QMetaType::Double, 2 },
        }}),
        // Slot 'transceiver_modulator_start'
        QtMocHelpers::SlotData<void(QString, unsigned , double, double)>(36, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::UInt, 2 }, { QMetaType::Double, 2 }, { QMetaType::Double, 2 },
        }}),
        // Slot 'transceiver_modulator_start'
        QtMocHelpers::SlotData<void(QString, unsigned , double)>(36, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::UInt, 2 }, { QMetaType::Double, 2 },
        }}),
        // Slot 'transceiver_modulator_start'
        QtMocHelpers::SlotData<void(QString, unsigned )>(36, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::UInt, 2 },
        }}),
        // Slot 'transceiver_modulator_start'
        QtMocHelpers::SlotData<void(QString)>(36, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Slot 'transceiver_modulator_start'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'transceiver_modulator_stop'
        QtMocHelpers::SlotData<void(bool)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Slot 'transceiver_modulator_stop'
        QtMocHelpers::SlotData<void()>(37, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'transceiver_spread'
        QtMocHelpers::SlotData<void(double)>(38, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 2 },
        }}),
        // Slot 'transceiver_spread'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'transceiver_nsym'
        QtMocHelpers::SlotData<void(int)>(39, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Slot 'transceiver_nsym'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'transceiver_trfrequency'
        QtMocHelpers::SlotData<void(double)>(40, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 2 },
        }}),
        // Slot 'transceiver_trfrequency'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'sync_transceiver'
        QtMocHelpers::SlotData<void(bool, bool)>(41, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 42 }, { QMetaType::Bool, 43 },
        }}),
        // Slot 'sync_transceiver'
        QtMocHelpers::SlotData<void(bool)>(41, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::Bool, 42 },
        }}),
        // Slot 'sync_transceiver'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'invalidate_audio_input_device'
        QtMocHelpers::SlotData<void(QString)>(44, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 45 },
        }}),
        // Slot 'invalidate_audio_output_device'
        QtMocHelpers::SlotData<void(QString)>(46, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 45 },
        }}),
        // Slot 'transceiver_volume'
        QtMocHelpers::SlotData<void(double)>(47, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 2 },
        }}),
        // Slot 'transceiver_volume'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'transceiver_txvolume'
        QtMocHelpers::SlotData<void(double)>(48, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 2 },
        }}),
        // Slot 'transceiver_txvolume'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'DataMode'
        QtMocHelpers::EnumData<enum DataMode>(49, 49, QMC::EnumFlags{}).add({
            {   50, DataMode::data_mode_none },
            {   51, DataMode::data_mode_USB },
            {   52, DataMode::data_mode_data },
        }),
        // enum 'Type2MsgGen'
        QtMocHelpers::EnumData<enum Type2MsgGen>(53, 53, QMC::EnumFlags{}).add({
            {   54, Type2MsgGen::type_2_msg_1_full },
            {   55, Type2MsgGen::type_2_msg_3_full },
            {   56, Type2MsgGen::type_2_msg_5_only },
        }),
    };
    return QtMocHelpers::metaObjectData<Configuration, qt_meta_tag_ZN13ConfigurationE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Configuration::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ConfigurationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ConfigurationE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13ConfigurationE_t>.metaTypes,
    nullptr
} };

void Configuration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Configuration *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->text_font_changed((*reinterpret_cast<std::add_pointer_t<QFont>>(_a[1]))); break;
        case 1: _t->decoded_text_font_changed((*reinterpret_cast<std::add_pointer_t<QFont>>(_a[1]))); break;
        case 2: _t->udp_server_changed((*reinterpret_cast<std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 3: _t->udp_server_port_changed((*reinterpret_cast<std::add_pointer_t<port_type>>(_a[1]))); break;
        case 4: _t->udp_TTL_changed((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->accept_udp_requests_changed((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->decode_highlighting_changed((*reinterpret_cast<std::add_pointer_t<DecodeHighlightingModel>>(_a[1]))); break;
        case 7: _t->transceiver_update((*reinterpret_cast<std::add_pointer_t<Transceiver::TransceiverState>>(_a[1]))); break;
        case 8: _t->transceiver_TCIframesWritten((*reinterpret_cast<std::add_pointer_t<qint64>>(_a[1]))); break;
        case 9: _t->transceiver_TCImodActive((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->leavingSettings((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->transceiver_failure((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->enumerating_audio_devices(); break;
        case 13: _t->transceiver_frequency((*reinterpret_cast<std::add_pointer_t<Frequency>>(_a[1]))); break;
        case 14: _t->transceiver_tx_frequency((*reinterpret_cast<std::add_pointer_t<Frequency>>(_a[1]))); break;
        case 15: _t->transceiver_tx_frequency(); break;
        case 16: _t->transceiver_mode((*reinterpret_cast<std::add_pointer_t<MODE>>(_a[1]))); break;
        case 17: _t->transceiver_ptt((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->transceiver_ptt(); break;
        case 19: _t->transceiver_audio((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->transceiver_audio(); break;
        case 21: _t->transceiver_tune((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 22: _t->transceiver_tune(); break;
        case 23: _t->transceiver_period((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 24: _t->transceiver_period(); break;
        case 25: _t->transceiver_blocksize((*reinterpret_cast<std::add_pointer_t<qint32>>(_a[1]))); break;
        case 26: _t->transceiver_blocksize(); break;
        case 27: _t->transceiver_modulator_start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[9]))); break;
        case 28: _t->transceiver_modulator_start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[8]))); break;
        case 29: _t->transceiver_modulator_start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[7]))); break;
        case 30: _t->transceiver_modulator_start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[6]))); break;
        case 31: _t->transceiver_modulator_start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[5]))); break;
        case 32: _t->transceiver_modulator_start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4]))); break;
        case 33: _t->transceiver_modulator_start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3]))); break;
        case 34: _t->transceiver_modulator_start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2]))); break;
        case 35: _t->transceiver_modulator_start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 36: _t->transceiver_modulator_start(); break;
        case 37: _t->transceiver_modulator_stop((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 38: _t->transceiver_modulator_stop(); break;
        case 39: _t->transceiver_spread((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 40: _t->transceiver_spread(); break;
        case 41: _t->transceiver_nsym((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 42: _t->transceiver_nsym(); break;
        case 43: _t->transceiver_trfrequency((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 44: _t->transceiver_trfrequency(); break;
        case 45: _t->sync_transceiver((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2]))); break;
        case 46: _t->sync_transceiver((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 47: _t->sync_transceiver(); break;
        case 48: _t->invalidate_audio_input_device((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 49: _t->invalidate_audio_output_device((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 50: _t->transceiver_volume((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 51: _t->transceiver_volume(); break;
        case 52: _t->transceiver_txvolume((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 53: _t->transceiver_txvolume(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Transceiver::TransceiverState >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Configuration::*)(QFont ) const>(_a, &Configuration::text_font_changed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Configuration::*)(QFont ) const>(_a, &Configuration::decoded_text_font_changed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Configuration::*)(QString & , QStringList const & ) const>(_a, &Configuration::udp_server_changed, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Configuration::*)(port_type ) const>(_a, &Configuration::udp_server_port_changed, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Configuration::*)(int ) const>(_a, &Configuration::udp_TTL_changed, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (Configuration::*)(bool ) const>(_a, &Configuration::accept_udp_requests_changed, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (Configuration::*)(DecodeHighlightingModel const & ) const>(_a, &Configuration::decode_highlighting_changed, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (Configuration::*)(Transceiver::TransceiverState const & ) const>(_a, &Configuration::transceiver_update, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (Configuration::*)(qint64 ) const>(_a, &Configuration::transceiver_TCIframesWritten, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (Configuration::*)(bool ) const>(_a, &Configuration::transceiver_TCImodActive, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (Configuration::*)(bool ) const>(_a, &Configuration::leavingSettings, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (Configuration::*)(QString const & ) const>(_a, &Configuration::transceiver_failure, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (Configuration::*)()>(_a, &Configuration::enumerating_audio_devices, 12))
            return;
    }
}

const QMetaObject *Configuration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Configuration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ConfigurationE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Configuration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    }
    return _id;
}

// SIGNAL 0
void Configuration::text_font_changed(QFont _t1)const
{
    QMetaObject::activate<void>(const_cast< Configuration *>(this), &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void Configuration::decoded_text_font_changed(QFont _t1)const
{
    QMetaObject::activate<void>(const_cast< Configuration *>(this), &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void Configuration::udp_server_changed(QString & _t1, QStringList const & _t2)const
{
    QMetaObject::activate<void>(const_cast< Configuration *>(this), &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void Configuration::udp_server_port_changed(port_type _t1)const
{
    QMetaObject::activate<void>(const_cast< Configuration *>(this), &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void Configuration::udp_TTL_changed(int _t1)const
{
    QMetaObject::activate<void>(const_cast< Configuration *>(this), &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void Configuration::accept_udp_requests_changed(bool _t1)const
{
    QMetaObject::activate<void>(const_cast< Configuration *>(this), &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void Configuration::decode_highlighting_changed(DecodeHighlightingModel const & _t1)const
{
    QMetaObject::activate<void>(const_cast< Configuration *>(this), &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void Configuration::transceiver_update(Transceiver::TransceiverState const & _t1)const
{
    QMetaObject::activate<void>(const_cast< Configuration *>(this), &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void Configuration::transceiver_TCIframesWritten(qint64 _t1)const
{
    QMetaObject::activate<void>(const_cast< Configuration *>(this), &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void Configuration::transceiver_TCImodActive(bool _t1)const
{
    QMetaObject::activate<void>(const_cast< Configuration *>(this), &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void Configuration::leavingSettings(bool _t1)const
{
    QMetaObject::activate<void>(const_cast< Configuration *>(this), &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void Configuration::transceiver_failure(QString const & _t1)const
{
    QMetaObject::activate<void>(const_cast< Configuration *>(this), &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void Configuration::enumerating_audio_devices()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}
QT_WARNING_POP

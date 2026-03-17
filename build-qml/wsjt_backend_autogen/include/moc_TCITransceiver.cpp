/****************************************************************************
** Meta object code from reading C++ file 'TCITransceiver.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Transceiver/TCITransceiver.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TCITransceiver.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14TCITransceiverE_t {};
} // unnamed namespace

template <> constexpr inline auto TCITransceiver::qt_create_metaobjectdata<qt_meta_tag_ZN14TCITransceiverE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "TCITransceiver",
        "sendIqData",
        "",
        "float*",
        "sendAudioData",
        "receiveIQ",
        "txAudioChrono",
        "tci_done1",
        "tci_done2",
        "tci_done3",
        "tci_done4",
        "tci_done5",
        "tci_done6",
        "tci_done7",
        "tci_done8",
        "sendTextMessage",
        "message",
        "txAudioData",
        "len",
        "data",
        "onBinaryReceived",
        "onMessageReceived",
        "str",
        "onError",
        "QAbstractSocket::SocketError",
        "err",
        "onConnected",
        "onDisconnected",
        "Tci_Cmd",
        "Cmd_Unknown",
        "Cmd_Device",
        "Cmd_ReceiveOnly",
        "Cmd_TrxCount",
        "Cmd_ChannelCount",
        "Cmd_VfoLimits",
        "Cmd_IfLimits",
        "Cmd_ModeList",
        "Cmd_Mode",
        "Cmd_Ready",
        "Cmd_Stop",
        "Cmd_Start",
        "Cmd_Preamp",
        "Cmd_Dds",
        "Cmd_If",
        "Cmd_Trx",
        "Cmd_RxEnable",
        "Cmd_TxEnable",
        "Cmd_RxChannelEnable",
        "Cmd_RitEnable",
        "Cmd_RitOffset",
        "Cmd_XitEnable",
        "Cmd_XitOffset",
        "Cmd_SplitEnable",
        "Cmd_IqSR",
        "Cmd_IqStart",
        "Cmd_IqStop",
        "Cmd_CWSpeed",
        "Cmd_CWDelay",
        "Cmd_Spot",
        "Cmd_SpotDelete",
        "Cmd_FilterBand",
        "Cmd_VFO",
        "Cmd_Version",
        "Cmd_Tune",
        "Cmd_RxMute",
        "Cmd_Smeter",
        "Cmd_Power",
        "Cmd_SWR",
        "Cmd_ECoderRX",
        "Cmd_ECoderVFO",
        "Cmd_AudioSR",
        "Cmd_AudioStart",
        "Cmd_AudioStop",
        "Cmd_AppFocus",
        "Cmd_Volume",
        "Cmd_SqlEnable",
        "Cmd_SqlLevel",
        "Cmd_Drive",
        "Cmd_TuneDrive",
        "Cmd_Mute",
        "Cmd_RxSensorsEnable",
        "Cmd_TxSensorsEnable",
        "Cmd_RxSensors",
        "Cmd_TxSensors",
        "Cmd_AgcMode",
        "Cmd_AgcGain",
        "Cmd_Lock"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'sendIqData'
        QtMocHelpers::SignalData<void(int, quint32, float *, bool)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 }, { QMetaType::UInt, 2 }, { 0x80000000 | 3, 2 }, { QMetaType::Bool, 2 },
        }}),
        // Signal 'sendAudioData'
        QtMocHelpers::SignalData<void(int, quint32, float *)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 }, { QMetaType::UInt, 2 }, { 0x80000000 | 3, 2 },
        }}),
        // Signal 'receiveIQ'
        QtMocHelpers::SignalData<void(bool, int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 }, { QMetaType::Int, 2 },
        }}),
        // Signal 'txAudioChrono'
        QtMocHelpers::SignalData<void(quint32)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 2 },
        }}),
        // Signal 'tci_done1'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tci_done2'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tci_done3'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tci_done4'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tci_done5'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tci_done6'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tci_done7'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tci_done8'
        QtMocHelpers::SignalData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'sendTextMessage'
        QtMocHelpers::SlotData<void(const QString &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 16 },
        }}),
        // Slot 'txAudioData'
        QtMocHelpers::SlotData<void(quint32, float *)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 18 }, { 0x80000000 | 3, 19 },
        }}),
        // Slot 'onBinaryReceived'
        QtMocHelpers::SlotData<void(const QByteArray &)>(20, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QByteArray, 19 },
        }}),
        // Slot 'onMessageReceived'
        QtMocHelpers::SlotData<void(const QString &)>(21, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 22 },
        }}),
        // Slot 'onError'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketError)>(23, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 24, 25 },
        }}),
        // Slot 'onConnected'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onDisconnected'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Tci_Cmd'
        QtMocHelpers::EnumData<enum Tci_Cmd>(28, 28, QMC::EnumFlags{}).add({
            {   29, Tci_Cmd::Cmd_Unknown },
            {   30, Tci_Cmd::Cmd_Device },
            {   31, Tci_Cmd::Cmd_ReceiveOnly },
            {   32, Tci_Cmd::Cmd_TrxCount },
            {   33, Tci_Cmd::Cmd_ChannelCount },
            {   34, Tci_Cmd::Cmd_VfoLimits },
            {   35, Tci_Cmd::Cmd_IfLimits },
            {   36, Tci_Cmd::Cmd_ModeList },
            {   37, Tci_Cmd::Cmd_Mode },
            {   38, Tci_Cmd::Cmd_Ready },
            {   39, Tci_Cmd::Cmd_Stop },
            {   40, Tci_Cmd::Cmd_Start },
            {   41, Tci_Cmd::Cmd_Preamp },
            {   42, Tci_Cmd::Cmd_Dds },
            {   43, Tci_Cmd::Cmd_If },
            {   44, Tci_Cmd::Cmd_Trx },
            {   45, Tci_Cmd::Cmd_RxEnable },
            {   46, Tci_Cmd::Cmd_TxEnable },
            {   47, Tci_Cmd::Cmd_RxChannelEnable },
            {   48, Tci_Cmd::Cmd_RitEnable },
            {   49, Tci_Cmd::Cmd_RitOffset },
            {   50, Tci_Cmd::Cmd_XitEnable },
            {   51, Tci_Cmd::Cmd_XitOffset },
            {   52, Tci_Cmd::Cmd_SplitEnable },
            {   53, Tci_Cmd::Cmd_IqSR },
            {   54, Tci_Cmd::Cmd_IqStart },
            {   55, Tci_Cmd::Cmd_IqStop },
            {   56, Tci_Cmd::Cmd_CWSpeed },
            {   57, Tci_Cmd::Cmd_CWDelay },
            {   58, Tci_Cmd::Cmd_Spot },
            {   59, Tci_Cmd::Cmd_SpotDelete },
            {   60, Tci_Cmd::Cmd_FilterBand },
            {   61, Tci_Cmd::Cmd_VFO },
            {   62, Tci_Cmd::Cmd_Version },
            {   63, Tci_Cmd::Cmd_Tune },
            {   64, Tci_Cmd::Cmd_RxMute },
            {   65, Tci_Cmd::Cmd_Smeter },
            {   66, Tci_Cmd::Cmd_Power },
            {   67, Tci_Cmd::Cmd_SWR },
            {   68, Tci_Cmd::Cmd_ECoderRX },
            {   69, Tci_Cmd::Cmd_ECoderVFO },
            {   70, Tci_Cmd::Cmd_AudioSR },
            {   71, Tci_Cmd::Cmd_AudioStart },
            {   72, Tci_Cmd::Cmd_AudioStop },
            {   73, Tci_Cmd::Cmd_AppFocus },
            {   74, Tci_Cmd::Cmd_Volume },
            {   75, Tci_Cmd::Cmd_SqlEnable },
            {   76, Tci_Cmd::Cmd_SqlLevel },
            {   77, Tci_Cmd::Cmd_Drive },
            {   78, Tci_Cmd::Cmd_TuneDrive },
            {   79, Tci_Cmd::Cmd_Mute },
            {   80, Tci_Cmd::Cmd_RxSensorsEnable },
            {   81, Tci_Cmd::Cmd_TxSensorsEnable },
            {   82, Tci_Cmd::Cmd_RxSensors },
            {   83, Tci_Cmd::Cmd_TxSensors },
            {   84, Tci_Cmd::Cmd_AgcMode },
            {   85, Tci_Cmd::Cmd_AgcGain },
            {   86, Tci_Cmd::Cmd_Lock },
        }),
    };
    return QtMocHelpers::metaObjectData<TCITransceiver, qt_meta_tag_ZN14TCITransceiverE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject TCITransceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<PollingTransceiver::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14TCITransceiverE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14TCITransceiverE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14TCITransceiverE_t>.metaTypes,
    nullptr
} };

void TCITransceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<TCITransceiver *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sendIqData((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<float*>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[4]))); break;
        case 1: _t->sendAudioData((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<float*>>(_a[3]))); break;
        case 2: _t->receiveIQ((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->txAudioChrono((*reinterpret_cast<std::add_pointer_t<quint32>>(_a[1]))); break;
        case 4: _t->tci_done1(); break;
        case 5: _t->tci_done2(); break;
        case 6: _t->tci_done3(); break;
        case 7: _t->tci_done4(); break;
        case 8: _t->tci_done5(); break;
        case 9: _t->tci_done6(); break;
        case 10: _t->tci_done7(); break;
        case 11: _t->tci_done8(); break;
        case 12: _t->sendTextMessage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->txAudioData((*reinterpret_cast<std::add_pointer_t<quint32>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<float*>>(_a[2]))); break;
        case 14: _t->onBinaryReceived((*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 15: _t->onMessageReceived((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->onError((*reinterpret_cast<std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 17: _t->onConnected(); break;
        case 18: _t->onDisconnected(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (TCITransceiver::*)(int , quint32 , float * , bool )>(_a, &TCITransceiver::sendIqData, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (TCITransceiver::*)(int , quint32 , float * )>(_a, &TCITransceiver::sendAudioData, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (TCITransceiver::*)(bool , int )>(_a, &TCITransceiver::receiveIQ, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (TCITransceiver::*)(quint32 )>(_a, &TCITransceiver::txAudioChrono, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (TCITransceiver::*)()>(_a, &TCITransceiver::tci_done1, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (TCITransceiver::*)()>(_a, &TCITransceiver::tci_done2, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (TCITransceiver::*)()>(_a, &TCITransceiver::tci_done3, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (TCITransceiver::*)()>(_a, &TCITransceiver::tci_done4, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (TCITransceiver::*)()>(_a, &TCITransceiver::tci_done5, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (TCITransceiver::*)()>(_a, &TCITransceiver::tci_done6, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (TCITransceiver::*)()>(_a, &TCITransceiver::tci_done7, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (TCITransceiver::*)()>(_a, &TCITransceiver::tci_done8, 11))
            return;
    }
}

const QMetaObject *TCITransceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCITransceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14TCITransceiverE_t>.strings))
        return static_cast<void*>(this);
    return PollingTransceiver::qt_metacast(_clname);
}

int TCITransceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PollingTransceiver::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void TCITransceiver::sendIqData(int _t1, quint32 _t2, float * _t3, bool _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 1
void TCITransceiver::sendAudioData(int _t1, quint32 _t2, float * _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2, _t3);
}

// SIGNAL 2
void TCITransceiver::receiveIQ(bool _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void TCITransceiver::txAudioChrono(quint32 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void TCITransceiver::tci_done1()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void TCITransceiver::tci_done2()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void TCITransceiver::tci_done3()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void TCITransceiver::tci_done4()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void TCITransceiver::tci_done5()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void TCITransceiver::tci_done6()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void TCITransceiver::tci_done7()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void TCITransceiver::tci_done8()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}
QT_WARNING_POP

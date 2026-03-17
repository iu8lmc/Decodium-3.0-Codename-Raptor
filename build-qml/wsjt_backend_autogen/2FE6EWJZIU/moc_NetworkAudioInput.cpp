/****************************************************************************
** Meta object code from reading C++ file 'NetworkAudioInput.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Audio/NetworkAudioInput.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NetworkAudioInput.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17NetworkAudioInputE_t {};
} // unnamed namespace

template <> constexpr inline auto NetworkAudioInput::qt_create_metaobjectdata<qt_meta_tag_ZN17NetworkAudioInputE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "NetworkAudioInput",
        "connected",
        "",
        "disconnected",
        "error",
        "message",
        "levelChanged",
        "peak",
        "catStatusReceived",
        "freq",
        "mode",
        "ptt",
        "sMeter",
        "spectrumReceived",
        "fftBins",
        "sendCatFreq",
        "freqHz",
        "sendCatMode",
        "sendCatPtt",
        "on",
        "sendAudioTx",
        "pcm48kHz",
        "onConnected",
        "onDisconnected",
        "onBinaryMessage",
        "onError",
        "QAbstractSocket::SocketError",
        "err",
        "onHeartbeat"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'connected'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'disconnected'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'error'
        QtMocHelpers::SignalData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Signal 'levelChanged'
        QtMocHelpers::SignalData<void(float)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 7 },
        }}),
        // Signal 'catStatusReceived'
        QtMocHelpers::SignalData<void(quint64, quint8, bool, qint16)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::ULongLong, 9 }, { QMetaType::UChar, 10 }, { QMetaType::Bool, 11 }, { QMetaType::Short, 12 },
        }}),
        // Signal 'spectrumReceived'
        QtMocHelpers::SignalData<void(const QByteArray &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 14 },
        }}),
        // Slot 'sendCatFreq'
        QtMocHelpers::SlotData<void(quint64)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::ULongLong, 16 },
        }}),
        // Slot 'sendCatMode'
        QtMocHelpers::SlotData<void(const QString &)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 },
        }}),
        // Slot 'sendCatPtt'
        QtMocHelpers::SlotData<void(bool)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 19 },
        }}),
        // Slot 'sendAudioTx'
        QtMocHelpers::SlotData<void(const QByteArray &)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 21 },
        }}),
        // Slot 'onConnected'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onDisconnected'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onBinaryMessage'
        QtMocHelpers::SlotData<void(const QByteArray &)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QByteArray, 5 },
        }}),
        // Slot 'onError'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketError)>(25, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 26, 27 },
        }}),
        // Slot 'onHeartbeat'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<NetworkAudioInput, qt_meta_tag_ZN17NetworkAudioInputE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject NetworkAudioInput::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17NetworkAudioInputE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17NetworkAudioInputE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17NetworkAudioInputE_t>.metaTypes,
    nullptr
} };

void NetworkAudioInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NetworkAudioInput *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->error((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->levelChanged((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 4: _t->catStatusReceived((*reinterpret_cast<std::add_pointer_t<quint64>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<quint8>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<qint16>>(_a[4]))); break;
        case 5: _t->spectrumReceived((*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 6: _t->sendCatFreq((*reinterpret_cast<std::add_pointer_t<quint64>>(_a[1]))); break;
        case 7: _t->sendCatMode((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->sendCatPtt((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->sendAudioTx((*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 10: _t->onConnected(); break;
        case 11: _t->onDisconnected(); break;
        case 12: _t->onBinaryMessage((*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 13: _t->onError((*reinterpret_cast<std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 14: _t->onHeartbeat(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (NetworkAudioInput::*)()>(_a, &NetworkAudioInput::connected, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (NetworkAudioInput::*)()>(_a, &NetworkAudioInput::disconnected, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (NetworkAudioInput::*)(const QString & )>(_a, &NetworkAudioInput::error, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (NetworkAudioInput::*)(float )>(_a, &NetworkAudioInput::levelChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (NetworkAudioInput::*)(quint64 , quint8 , bool , qint16 )>(_a, &NetworkAudioInput::catStatusReceived, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (NetworkAudioInput::*)(const QByteArray & )>(_a, &NetworkAudioInput::spectrumReceived, 5))
            return;
    }
}

const QMetaObject *NetworkAudioInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkAudioInput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17NetworkAudioInputE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NetworkAudioInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void NetworkAudioInput::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void NetworkAudioInput::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void NetworkAudioInput::error(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void NetworkAudioInput::levelChanged(float _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void NetworkAudioInput::catStatusReceived(quint64 _t1, quint8 _t2, bool _t3, qint16 _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 5
void NetworkAudioInput::spectrumReceived(const QByteArray & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP

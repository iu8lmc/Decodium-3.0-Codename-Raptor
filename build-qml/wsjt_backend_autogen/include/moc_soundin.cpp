/****************************************************************************
** Meta object code from reading C++ file 'soundin.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Audio/soundin.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundin.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10SoundInputE_t {};
} // unnamed namespace

template <> constexpr inline auto SoundInput::qt_create_metaobjectdata<qt_meta_tag_ZN10SoundInputE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SoundInput",
        "error",
        "",
        "message",
        "status",
        "start",
        "QAudioDeviceInfo",
        "framesPerBuffer",
        "AudioDevice*",
        "sink",
        "downSampleFactor",
        "AudioDevice::Channel",
        "suspend",
        "resume",
        "stop",
        "reset",
        "report_dropped_frames",
        "handleStateChanged",
        "QAudio::State"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'error'
        QtMocHelpers::SignalData<void(QString) const>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'status'
        QtMocHelpers::SignalData<void(QString) const>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void(QAudioDeviceInfo const &, int, AudioDevice *, unsigned , AudioDevice::Channel)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 2 }, { QMetaType::Int, 7 }, { 0x80000000 | 8, 9 }, { QMetaType::UInt, 10 },
            { 0x80000000 | 11, 2 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void(QAudioDeviceInfo const &, int, AudioDevice *, unsigned )>(5, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 6, 2 }, { QMetaType::Int, 7 }, { 0x80000000 | 8, 9 }, { QMetaType::UInt, 10 },
        }}),
        // Slot 'suspend'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resume'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stop'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'reset'
        QtMocHelpers::SlotData<void(bool)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 16 },
        }}),
        // Slot 'handleStateChanged'
        QtMocHelpers::SlotData<void(QAudio::State)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 18, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SoundInput, qt_meta_tag_ZN10SoundInputE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SoundInput::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10SoundInputE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10SoundInputE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10SoundInputE_t>.metaTypes,
    nullptr
} };

void SoundInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SoundInput *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->error((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->status((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->start((*reinterpret_cast<std::add_pointer_t<QAudioDeviceInfo>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<AudioDevice*>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<AudioDevice::Channel>>(_a[5]))); break;
        case 3: _t->start((*reinterpret_cast<std::add_pointer_t<QAudioDeviceInfo>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<AudioDevice*>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[4]))); break;
        case 4: _t->suspend(); break;
        case 5: _t->resume(); break;
        case 6: _t->stop(); break;
        case 7: _t->reset((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->handleStateChanged((*reinterpret_cast<std::add_pointer_t<QAudio::State>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 4:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< AudioDevice::Channel >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SoundInput::*)(QString ) const>(_a, &SoundInput::error, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SoundInput::*)(QString ) const>(_a, &SoundInput::status, 1))
            return;
    }
}

const QMetaObject *SoundInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoundInput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10SoundInputE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SoundInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SoundInput::error(QString _t1)const
{
    QMetaObject::activate<void>(const_cast< SoundInput *>(this), &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void SoundInput::status(QString _t1)const
{
    QMetaObject::activate<void>(const_cast< SoundInput *>(this), &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP

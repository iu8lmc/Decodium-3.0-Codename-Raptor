/****************************************************************************
** Meta object code from reading C++ file 'Modulator.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Modulator/Modulator.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Modulator.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9ModulatorE_t {};
} // unnamed namespace

template <> constexpr inline auto Modulator::qt_create_metaobjectdata<qt_meta_tag_ZN9ModulatorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Modulator",
        "stateChanged",
        "",
        "ModulatorState",
        "start",
        "mode",
        "symbolsLength",
        "framesPerSymbol",
        "frequency",
        "toneSpacing",
        "SoundOutput*",
        "Channel",
        "synchronize",
        "fastMode",
        "dBSNR",
        "TRperiod",
        "stop",
        "quick",
        "tune",
        "newState",
        "setFrequency",
        "newFrequency"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void(enum ModulatorState) const>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void(QString, unsigned , double, double, double, SoundOutput *, Channel, bool, bool, double, double)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::UInt, 6 }, { QMetaType::Double, 7 }, { QMetaType::Double, 8 },
            { QMetaType::Double, 9 }, { 0x80000000 | 10, 2 }, { 0x80000000 | 11, 2 }, { QMetaType::Bool, 12 },
            { QMetaType::Bool, 13 }, { QMetaType::Double, 14 }, { QMetaType::Double, 15 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void(QString, unsigned , double, double, double, SoundOutput *, Channel, bool, bool, double)>(4, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::UInt, 6 }, { QMetaType::Double, 7 }, { QMetaType::Double, 8 },
            { QMetaType::Double, 9 }, { 0x80000000 | 10, 2 }, { 0x80000000 | 11, 2 }, { QMetaType::Bool, 12 },
            { QMetaType::Bool, 13 }, { QMetaType::Double, 14 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void(QString, unsigned , double, double, double, SoundOutput *, Channel, bool, bool)>(4, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::UInt, 6 }, { QMetaType::Double, 7 }, { QMetaType::Double, 8 },
            { QMetaType::Double, 9 }, { 0x80000000 | 10, 2 }, { 0x80000000 | 11, 2 }, { QMetaType::Bool, 12 },
            { QMetaType::Bool, 13 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void(QString, unsigned , double, double, double, SoundOutput *, Channel, bool)>(4, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::UInt, 6 }, { QMetaType::Double, 7 }, { QMetaType::Double, 8 },
            { QMetaType::Double, 9 }, { 0x80000000 | 10, 2 }, { 0x80000000 | 11, 2 }, { QMetaType::Bool, 12 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void(QString, unsigned , double, double, double, SoundOutput *, Channel)>(4, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::UInt, 6 }, { QMetaType::Double, 7 }, { QMetaType::Double, 8 },
            { QMetaType::Double, 9 }, { 0x80000000 | 10, 2 }, { 0x80000000 | 11, 2 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void(QString, unsigned , double, double, double, SoundOutput *)>(4, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::UInt, 6 }, { QMetaType::Double, 7 }, { QMetaType::Double, 8 },
            { QMetaType::Double, 9 }, { 0x80000000 | 10, 2 },
        }}),
        // Slot 'stop'
        QtMocHelpers::SlotData<void(bool)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 17 },
        }}),
        // Slot 'stop'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'tune'
        QtMocHelpers::SlotData<void(bool)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 19 },
        }}),
        // Slot 'tune'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'setFrequency'
        QtMocHelpers::SlotData<void(double)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 21 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Modulator, qt_meta_tag_ZN9ModulatorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Modulator::staticMetaObject = { {
    QMetaObject::SuperData::link<AudioDevice::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9ModulatorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9ModulatorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9ModulatorE_t>.metaTypes,
    nullptr
} };

void Modulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Modulator *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast<std::add_pointer_t<enum ModulatorState>>(_a[1]))); break;
        case 1: _t->start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<SoundOutput*>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<Channel>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[9])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[10])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[11]))); break;
        case 2: _t->start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<SoundOutput*>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<Channel>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[9])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[10]))); break;
        case 3: _t->start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<SoundOutput*>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<Channel>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[9]))); break;
        case 4: _t->start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<SoundOutput*>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<Channel>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[8]))); break;
        case 5: _t->start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<SoundOutput*>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<Channel>>(_a[7]))); break;
        case 6: _t->start((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<SoundOutput*>>(_a[6]))); break;
        case 7: _t->stop((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->stop(); break;
        case 9: _t->tune((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->tune(); break;
        case 11: _t->setFrequency((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Modulator::*)(ModulatorState ) const>(_a, &Modulator::stateChanged, 0))
            return;
    }
}

const QMetaObject *Modulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Modulator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9ModulatorE_t>.strings))
        return static_cast<void*>(this);
    return AudioDevice::qt_metacast(_clname);
}

int Modulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AudioDevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Modulator::stateChanged(ModulatorState _t1)const
{
    QMetaObject::activate<void>(const_cast< Modulator *>(this), &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP

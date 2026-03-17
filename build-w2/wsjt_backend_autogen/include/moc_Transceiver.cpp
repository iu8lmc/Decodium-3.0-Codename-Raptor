/****************************************************************************
** Meta object code from reading C++ file 'Transceiver.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Transceiver/Transceiver.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Transceiver.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11TransceiverE_t {};
} // unnamed namespace

template <> constexpr inline auto Transceiver::qt_create_metaobjectdata<qt_meta_tag_ZN11TransceiverE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Transceiver",
        "resolution",
        "",
        "tciframeswritten",
        "tci_mod_active",
        "update",
        "Transceiver::TransceiverState",
        "sequence_number",
        "failure",
        "reason",
        "finished",
        "set",
        "start",
        "stop",
        "MODE",
        "UNK",
        "CW",
        "CW_R",
        "USB",
        "LSB",
        "FSK",
        "FSK_R",
        "DIG_U",
        "DIG_L",
        "AM",
        "FM",
        "DIG_FM"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'resolution'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Signal 'tciframeswritten'
        QtMocHelpers::SignalData<void(qint64)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 2 },
        }}),
        // Signal 'tci_mod_active'
        QtMocHelpers::SignalData<void(bool)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Signal 'update'
        QtMocHelpers::SignalData<void(Transceiver::TransceiverState const &, unsigned ) const>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 2 }, { QMetaType::UInt, 7 },
        }}),
        // Signal 'failure'
        QtMocHelpers::SignalData<void(QString const &) const>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Signal 'finished'
        QtMocHelpers::SignalData<void() const>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'set'
        QtMocHelpers::SlotData<void(Transceiver::TransceiverState const &, unsigned )>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 2 }, { QMetaType::UInt, 7 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void(unsigned )>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 7 },
        }}),
        // Slot 'stop'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'MODE'
        QtMocHelpers::EnumData<enum MODE>(14, 14, QMC::EnumFlags{}).add({
            {   15, MODE::UNK },
            {   16, MODE::CW },
            {   17, MODE::CW_R },
            {   18, MODE::USB },
            {   19, MODE::LSB },
            {   20, MODE::FSK },
            {   21, MODE::FSK_R },
            {   22, MODE::DIG_U },
            {   23, MODE::DIG_L },
            {   24, MODE::AM },
            {   25, MODE::FM },
            {   26, MODE::DIG_FM },
        }),
    };
    return QtMocHelpers::metaObjectData<Transceiver, qt_meta_tag_ZN11TransceiverE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Transceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11TransceiverE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11TransceiverE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11TransceiverE_t>.metaTypes,
    nullptr
} };

void Transceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Transceiver *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->resolution((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->tciframeswritten((*reinterpret_cast<std::add_pointer_t<qint64>>(_a[1]))); break;
        case 2: _t->tci_mod_active((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->update((*reinterpret_cast<std::add_pointer_t<Transceiver::TransceiverState>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2]))); break;
        case 4: _t->failure((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->finished(); break;
        case 6: _t->set((*reinterpret_cast<std::add_pointer_t<Transceiver::TransceiverState>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2]))); break;
        case 7: _t->start((*reinterpret_cast<std::add_pointer_t<uint>>(_a[1]))); break;
        case 8: _t->stop(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Transceiver::TransceiverState >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Transceiver::TransceiverState >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Transceiver::*)(int )>(_a, &Transceiver::resolution, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Transceiver::*)(qint64 )>(_a, &Transceiver::tciframeswritten, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Transceiver::*)(bool )>(_a, &Transceiver::tci_mod_active, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Transceiver::*)(Transceiver::TransceiverState const & , unsigned  ) const>(_a, &Transceiver::update, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Transceiver::*)(QString const & ) const>(_a, &Transceiver::failure, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (Transceiver::*)() const>(_a, &Transceiver::finished, 5))
            return;
    }
}

const QMetaObject *Transceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Transceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11TransceiverE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Transceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Transceiver::resolution(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void Transceiver::tciframeswritten(qint64 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void Transceiver::tci_mod_active(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void Transceiver::update(Transceiver::TransceiverState const & _t1, unsigned  _t2)const
{
    QMetaObject::activate<void>(const_cast< Transceiver *>(this), &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void Transceiver::failure(QString const & _t1)const
{
    QMetaObject::activate<void>(const_cast< Transceiver *>(this), &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void Transceiver::finished()const
{
    QMetaObject::activate(const_cast< Transceiver *>(this), &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'OmniRigTransceiver.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Transceiver/OmniRigTransceiver.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OmniRigTransceiver.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18OmniRigTransceiverE_t {};
} // unnamed namespace

template <> constexpr inline auto OmniRigTransceiver::qt_create_metaobjectdata<qt_meta_tag_ZN18OmniRigTransceiverE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "OmniRigTransceiver",
        "handle_COM_exception",
        "",
        "handle_visible_change",
        "handle_rig_type_change",
        "rig_number",
        "handle_status_change",
        "handle_params_change",
        "params",
        "handle_custom_reply",
        "QVariant",
        "command",
        "reply"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'handle_COM_exception'
        QtMocHelpers::SlotData<void(int, QString, QString, QString)>(1, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 2 }, { QMetaType::QString, 2 }, { QMetaType::QString, 2 }, { QMetaType::QString, 2 },
        }}),
        // Slot 'handle_visible_change'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'handle_rig_type_change'
        QtMocHelpers::SlotData<void(int)>(4, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Slot 'handle_status_change'
        QtMocHelpers::SlotData<void(int)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Slot 'handle_params_change'
        QtMocHelpers::SlotData<void(int, int)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 5 }, { QMetaType::Int, 8 },
        }}),
        // Slot 'handle_custom_reply'
        QtMocHelpers::SlotData<void(int, QVariant const &, QVariant const &)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 2 }, { 0x80000000 | 10, 11 }, { 0x80000000 | 10, 12 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<OmniRigTransceiver, qt_meta_tag_ZN18OmniRigTransceiverE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject OmniRigTransceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<TransceiverBase::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18OmniRigTransceiverE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18OmniRigTransceiverE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18OmniRigTransceiverE_t>.metaTypes,
    nullptr
} };

void OmniRigTransceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<OmniRigTransceiver *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->handle_COM_exception((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4]))); break;
        case 1: _t->handle_visible_change(); break;
        case 2: _t->handle_rig_type_change((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->handle_status_change((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->handle_params_change((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->handle_custom_reply((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QVariant>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QVariant>>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject *OmniRigTransceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OmniRigTransceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18OmniRigTransceiverE_t>.strings))
        return static_cast<void*>(this);
    return TransceiverBase::qt_metacast(_clname);
}

int OmniRigTransceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TransceiverBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP

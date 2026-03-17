/****************************************************************************
** Meta object code from reading C++ file 'OmniRigTransceiver.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Transceiver/OmniRigTransceiver.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OmniRigTransceiver.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OmniRigTransceiver_t {
    QByteArrayData data[12];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OmniRigTransceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OmniRigTransceiver_t qt_meta_stringdata_OmniRigTransceiver = {
    {
QT_MOC_LITERAL(0, 0, 18), // "OmniRigTransceiver"
QT_MOC_LITERAL(1, 19, 20), // "handle_COM_exception"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 21), // "handle_visible_change"
QT_MOC_LITERAL(4, 63, 22), // "handle_rig_type_change"
QT_MOC_LITERAL(5, 86, 10), // "rig_number"
QT_MOC_LITERAL(6, 97, 20), // "handle_status_change"
QT_MOC_LITERAL(7, 118, 20), // "handle_params_change"
QT_MOC_LITERAL(8, 139, 6), // "params"
QT_MOC_LITERAL(9, 146, 19), // "handle_custom_reply"
QT_MOC_LITERAL(10, 166, 7), // "command"
QT_MOC_LITERAL(11, 174, 5) // "reply"

    },
    "OmniRigTransceiver\0handle_COM_exception\0"
    "\0handle_visible_change\0handle_rig_type_change\0"
    "rig_number\0handle_status_change\0"
    "handle_params_change\0params\0"
    "handle_custom_reply\0command\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OmniRigTransceiver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   44,    2, 0x08 /* Private */,
       3,    0,   53,    2, 0x08 /* Private */,
       4,    1,   54,    2, 0x08 /* Private */,
       6,    1,   57,    2, 0x08 /* Private */,
       7,    2,   60,    2, 0x08 /* Private */,
       9,    3,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariant, QMetaType::QVariant,    2,   10,   11,

       0        // eod
};

void OmniRigTransceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OmniRigTransceiver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handle_COM_exception((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->handle_visible_change(); break;
        case 2: _t->handle_rig_type_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->handle_status_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->handle_params_change((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->handle_custom_reply((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OmniRigTransceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<TransceiverBase::staticMetaObject>(),
    qt_meta_stringdata_OmniRigTransceiver.data,
    qt_meta_data_OmniRigTransceiver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OmniRigTransceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OmniRigTransceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OmniRigTransceiver.stringdata0))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

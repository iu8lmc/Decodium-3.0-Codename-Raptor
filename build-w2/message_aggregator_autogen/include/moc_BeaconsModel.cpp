/****************************************************************************
** Meta object code from reading C++ file 'BeaconsModel.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../UDPExamples/BeaconsModel.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BeaconsModel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BeaconsModel_t {
    QByteArrayData data[16];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BeaconsModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BeaconsModel_t qt_meta_stringdata_BeaconsModel = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BeaconsModel"
QT_MOC_LITERAL(1, 13, 15), // "add_beacon_spot"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "is_new"
QT_MOC_LITERAL(4, 37, 9), // "ClientKey"
QT_MOC_LITERAL(5, 47, 4), // "time"
QT_MOC_LITERAL(6, 52, 3), // "snr"
QT_MOC_LITERAL(7, 56, 10), // "delta_time"
QT_MOC_LITERAL(8, 67, 9), // "Frequency"
QT_MOC_LITERAL(9, 77, 9), // "frequency"
QT_MOC_LITERAL(10, 87, 5), // "drift"
QT_MOC_LITERAL(11, 93, 8), // "callsign"
QT_MOC_LITERAL(12, 102, 4), // "grid"
QT_MOC_LITERAL(13, 107, 5), // "power"
QT_MOC_LITERAL(14, 113, 7), // "off_air"
QT_MOC_LITERAL(15, 121, 15) // "decodes_cleared"

    },
    "BeaconsModel\0add_beacon_spot\0\0is_new\0"
    "ClientKey\0time\0snr\0delta_time\0Frequency\0"
    "frequency\0drift\0callsign\0grid\0power\0"
    "off_air\0decodes_cleared"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BeaconsModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,   11,   24,    2, 0x0a /* Public */,
      15,    1,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4, QMetaType::QTime, QMetaType::Int, QMetaType::Float, 0x80000000 | 8, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Bool,    3,    2,    5,    6,    7,    9,   10,   11,   12,   13,   14,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void BeaconsModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BeaconsModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->add_beacon_spot((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const ClientKey(*)>(_a[2])),(*reinterpret_cast< QTime(*)>(_a[3])),(*reinterpret_cast< qint32(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< Frequency(*)>(_a[6])),(*reinterpret_cast< qint32(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< qint32(*)>(_a[10])),(*reinterpret_cast< bool(*)>(_a[11]))); break;
        case 1: _t->decodes_cleared((*reinterpret_cast< const ClientKey(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BeaconsModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QStandardItemModel::staticMetaObject>(),
    qt_meta_stringdata_BeaconsModel.data,
    qt_meta_data_BeaconsModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BeaconsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BeaconsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BeaconsModel.stringdata0))
        return static_cast<void*>(this);
    return QStandardItemModel::qt_metacast(_clname);
}

int BeaconsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

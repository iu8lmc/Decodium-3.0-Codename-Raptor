/****************************************************************************
** Meta object code from reading C++ file 'FrequencyList.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../models/FrequencyList.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrequencyList.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrequencyList_v2_101_t {
    QByteArrayData data[6];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrequencyList_v2_101_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrequencyList_v2_101_t qt_meta_stringdata_FrequencyList_v2_101 = {
    {
QT_MOC_LITERAL(0, 0, 20), // "FrequencyList_v2_101"
QT_MOC_LITERAL(1, 21, 6), // "filter"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 6), // "Region"
QT_MOC_LITERAL(4, 36, 4), // "Mode"
QT_MOC_LITERAL(5, 41, 17) // "reset_to_defaults"

    },
    "FrequencyList_v2_101\0filter\0\0Region\0"
    "Mode\0reset_to_defaults"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrequencyList_v2_101[] = {

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
       1,    3,   24,    2, 0x0a /* Public */,
       5,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void,

       0        // eod
};

void FrequencyList_v2_101::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrequencyList_v2_101 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->filter((*reinterpret_cast< Region(*)>(_a[1])),(*reinterpret_cast< Mode(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->reset_to_defaults(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrequencyList_v2_101::staticMetaObject = { {
    QMetaObject::SuperData::link<QSortFilterProxyModel::staticMetaObject>(),
    qt_meta_stringdata_FrequencyList_v2_101.data,
    qt_meta_data_FrequencyList_v2_101,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrequencyList_v2_101::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrequencyList_v2_101::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrequencyList_v2_101.stringdata0))
        return static_cast<void*>(this);
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int FrequencyList_v2_101::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
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

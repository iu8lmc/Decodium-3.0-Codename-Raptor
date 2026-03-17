/****************************************************************************
** Meta object code from reading C++ file 'IARURegions.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../models/IARURegions.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IARURegions.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IARURegions_t {
    QByteArrayData data[7];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IARURegions_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IARURegions_t qt_meta_stringdata_IARURegions = {
    {
QT_MOC_LITERAL(0, 0, 11), // "IARURegions"
QT_MOC_LITERAL(1, 12, 6), // "Region"
QT_MOC_LITERAL(2, 19, 3), // "ALL"
QT_MOC_LITERAL(3, 23, 2), // "R1"
QT_MOC_LITERAL(4, 26, 2), // "R2"
QT_MOC_LITERAL(5, 29, 2), // "R3"
QT_MOC_LITERAL(6, 32, 8) // "SENTINAL"

    },
    "IARURegions\0Region\0ALL\0R1\0R2\0R3\0"
    "SENTINAL"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IARURegions[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    5,   19,

 // enum data: key, value
       2, uint(IARURegions::ALL),
       3, uint(IARURegions::R1),
       4, uint(IARURegions::R2),
       5, uint(IARURegions::R3),
       6, uint(IARURegions::SENTINAL),

       0        // eod
};

void IARURegions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject IARURegions::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_IARURegions.data,
    qt_meta_data_IARURegions,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IARURegions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IARURegions::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IARURegions.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int IARURegions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'Modes.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../models/Modes.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Modes.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Modes_t {
    QByteArrayData data[17];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Modes_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Modes_t qt_meta_stringdata_Modes = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Modes"
QT_MOC_LITERAL(1, 6, 4), // "Mode"
QT_MOC_LITERAL(2, 11, 3), // "ALL"
QT_MOC_LITERAL(3, 15, 4), // "JT65"
QT_MOC_LITERAL(4, 20, 3), // "JT9"
QT_MOC_LITERAL(5, 24, 3), // "JT4"
QT_MOC_LITERAL(6, 28, 4), // "WSPR"
QT_MOC_LITERAL(7, 33, 4), // "Echo"
QT_MOC_LITERAL(8, 38, 6), // "MSK144"
QT_MOC_LITERAL(9, 45, 7), // "FreqCal"
QT_MOC_LITERAL(10, 53, 3), // "FT8"
QT_MOC_LITERAL(11, 57, 3), // "FT4"
QT_MOC_LITERAL(12, 61, 4), // "FST4"
QT_MOC_LITERAL(13, 66, 5), // "FST4W"
QT_MOC_LITERAL(14, 72, 3), // "Q65"
QT_MOC_LITERAL(15, 76, 3), // "FT2"
QT_MOC_LITERAL(16, 80, 28) // "MODES_END_SENTINAL_AND_COUNT"

    },
    "Modes\0Mode\0ALL\0JT65\0JT9\0JT4\0WSPR\0Echo\0"
    "MSK144\0FreqCal\0FT8\0FT4\0FST4\0FST4W\0Q65\0"
    "FT2\0MODES_END_SENTINAL_AND_COUNT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Modes[] = {

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
       1,    1, 0x0,   15,   19,

 // enum data: key, value
       2, uint(Modes::ALL),
       3, uint(Modes::JT65),
       4, uint(Modes::JT9),
       5, uint(Modes::JT4),
       6, uint(Modes::WSPR),
       7, uint(Modes::Echo),
       8, uint(Modes::MSK144),
       9, uint(Modes::FreqCal),
      10, uint(Modes::FT8),
      11, uint(Modes::FT4),
      12, uint(Modes::FST4),
      13, uint(Modes::FST4W),
      14, uint(Modes::Q65),
      15, uint(Modes::FT2),
      16, uint(Modes::MODES_END_SENTINAL_AND_COUNT),

       0        // eod
};

void Modes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject Modes::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_Modes.data,
    qt_meta_data_Modes,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Modes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Modes::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Modes.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int Modes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

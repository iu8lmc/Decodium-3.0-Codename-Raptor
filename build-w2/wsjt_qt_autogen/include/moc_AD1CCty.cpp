/****************************************************************************
** Meta object code from reading C++ file 'AD1CCty.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../logbook/AD1CCty.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AD1CCty.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AD1CCty_t {
    QByteArrayData data[13];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AD1CCty_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AD1CCty_t qt_meta_stringdata_AD1CCty = {
    {
QT_MOC_LITERAL(0, 0, 7), // "AD1CCty"
QT_MOC_LITERAL(1, 8, 10), // "cty_loaded"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "version"
QT_MOC_LITERAL(4, 28, 9), // "Continent"
QT_MOC_LITERAL(5, 38, 2), // "UN"
QT_MOC_LITERAL(6, 41, 2), // "AF"
QT_MOC_LITERAL(7, 44, 2), // "AN"
QT_MOC_LITERAL(8, 47, 2), // "AS"
QT_MOC_LITERAL(9, 50, 2), // "EU"
QT_MOC_LITERAL(10, 53, 2), // "NA"
QT_MOC_LITERAL(11, 56, 2), // "OC"
QT_MOC_LITERAL(12, 59, 2) // "SA"

    },
    "AD1CCty\0cty_loaded\0\0version\0Continent\0"
    "UN\0AF\0AN\0AS\0EU\0NA\0OC\0SA"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AD1CCty[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       1,   22, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // enums: name, alias, flags, count, data
       4,    4, 0x2,    8,   27,

 // enum data: key, value
       5, uint(AD1CCty::Continent::UN),
       6, uint(AD1CCty::Continent::AF),
       7, uint(AD1CCty::Continent::AN),
       8, uint(AD1CCty::Continent::AS),
       9, uint(AD1CCty::Continent::EU),
      10, uint(AD1CCty::Continent::NA),
      11, uint(AD1CCty::Continent::OC),
      12, uint(AD1CCty::Continent::SA),

       0        // eod
};

void AD1CCty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AD1CCty *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->cty_loaded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AD1CCty::*)(QString const & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AD1CCty::cty_loaded)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AD1CCty::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AD1CCty.data,
    qt_meta_data_AD1CCty,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AD1CCty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AD1CCty::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AD1CCty.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AD1CCty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void AD1CCty::cty_loaded(QString const & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< AD1CCty *>(this), &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

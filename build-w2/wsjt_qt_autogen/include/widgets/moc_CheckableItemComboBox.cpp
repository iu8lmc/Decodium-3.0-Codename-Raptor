/****************************************************************************
** Meta object code from reading C++ file 'CheckableItemComboBox.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../widgets/CheckableItemComboBox.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CheckableItemComboBox.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CheckableItemComboBox_t {
    QByteArrayData data[5];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CheckableItemComboBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CheckableItemComboBox_t qt_meta_stringdata_CheckableItemComboBox = {
    {
QT_MOC_LITERAL(0, 0, 21), // "CheckableItemComboBox"
QT_MOC_LITERAL(1, 22, 18), // "model_data_changed"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 12), // "item_pressed"
QT_MOC_LITERAL(4, 55, 11) // "QModelIndex"

    },
    "CheckableItemComboBox\0model_data_changed\0"
    "\0item_pressed\0QModelIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CheckableItemComboBox[] = {

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
       1,    0,   24,    2, 0x08 /* Private */,
       3,    1,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void CheckableItemComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CheckableItemComboBox *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->model_data_changed(); break;
        case 1: _t->item_pressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CheckableItemComboBox::staticMetaObject = { {
    QMetaObject::SuperData::link<LazyFillComboBox::staticMetaObject>(),
    qt_meta_stringdata_CheckableItemComboBox.data,
    qt_meta_data_CheckableItemComboBox,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CheckableItemComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CheckableItemComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CheckableItemComboBox.stringdata0))
        return static_cast<void*>(this);
    return LazyFillComboBox::qt_metacast(_clname);
}

int CheckableItemComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LazyFillComboBox::qt_metacall(_c, _id, _a);
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

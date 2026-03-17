/****************************************************************************
** Meta object code from reading C++ file 'echograph.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../widgets/echograph.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'echograph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EchoGraph_t {
    QByteArrayData data[11];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EchoGraph_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EchoGraph_t qt_meta_stringdata_EchoGraph = {
    {
QT_MOC_LITERAL(0, 0, 9), // "EchoGraph"
QT_MOC_LITERAL(1, 10, 29), // "on_smoothSpinBox_valueChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 1), // "n"
QT_MOC_LITERAL(4, 43, 26), // "on_gainSlider_valueChanged"
QT_MOC_LITERAL(5, 70, 5), // "value"
QT_MOC_LITERAL(6, 76, 26), // "on_zeroSlider_valueChanged"
QT_MOC_LITERAL(7, 103, 35), // "on_binsPerPixelSpinBox_valueC..."
QT_MOC_LITERAL(8, 139, 19), // "on_pbColors_clicked"
QT_MOC_LITERAL(9, 159, 21), // "on_cbBaseline_toggled"
QT_MOC_LITERAL(10, 181, 1) // "b"

    },
    "EchoGraph\0on_smoothSpinBox_valueChanged\0"
    "\0n\0on_gainSlider_valueChanged\0value\0"
    "on_zeroSlider_valueChanged\0"
    "on_binsPerPixelSpinBox_valueChanged\0"
    "on_pbColors_clicked\0on_cbBaseline_toggled\0"
    "b"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EchoGraph[] = {

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
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       6,    1,   50,    2, 0x08 /* Private */,
       7,    1,   53,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,

       0        // eod
};

void EchoGraph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EchoGraph *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_smoothSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_gainSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_zeroSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_binsPerPixelSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pbColors_clicked(); break;
        case 5: _t->on_cbBaseline_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EchoGraph::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_EchoGraph.data,
    qt_meta_data_EchoGraph,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EchoGraph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EchoGraph::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EchoGraph.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int EchoGraph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

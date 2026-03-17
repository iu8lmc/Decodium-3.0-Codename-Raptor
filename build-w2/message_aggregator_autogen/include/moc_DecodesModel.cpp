/****************************************************************************
** Meta object code from reading C++ file 'DecodesModel.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../UDPExamples/DecodesModel.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DecodesModel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DecodesModel_t {
    QByteArrayData data[19];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DecodesModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DecodesModel_t qt_meta_stringdata_DecodesModel = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DecodesModel"
QT_MOC_LITERAL(1, 13, 5), // "reply"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "ClientKey"
QT_MOC_LITERAL(4, 30, 3), // "snr"
QT_MOC_LITERAL(5, 34, 10), // "delta_time"
QT_MOC_LITERAL(6, 45, 15), // "delta_frequency"
QT_MOC_LITERAL(7, 61, 4), // "mode"
QT_MOC_LITERAL(8, 66, 7), // "message"
QT_MOC_LITERAL(9, 74, 14), // "low_confidence"
QT_MOC_LITERAL(10, 89, 9), // "modifiers"
QT_MOC_LITERAL(11, 99, 10), // "add_decode"
QT_MOC_LITERAL(12, 110, 6), // "is_new"
QT_MOC_LITERAL(13, 117, 7), // "off_air"
QT_MOC_LITERAL(14, 125, 7), // "is_fast"
QT_MOC_LITERAL(15, 133, 15), // "decodes_cleared"
QT_MOC_LITERAL(16, 149, 8), // "do_reply"
QT_MOC_LITERAL(17, 158, 11), // "QModelIndex"
QT_MOC_LITERAL(18, 170, 6) // "source"

    },
    "DecodesModel\0reply\0\0ClientKey\0snr\0"
    "delta_time\0delta_frequency\0mode\0message\0"
    "low_confidence\0modifiers\0add_decode\0"
    "is_new\0off_air\0is_fast\0decodes_cleared\0"
    "do_reply\0QModelIndex\0source"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DecodesModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    9,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,   11,   53,    2, 0x0a /* Public */,
      15,    1,   76,    2, 0x0a /* Public */,
      16,    2,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QTime, QMetaType::Int, QMetaType::Float, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::UChar,    2,    2,    4,    5,    6,    7,    8,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 3, QMetaType::QTime, QMetaType::Int, QMetaType::Float, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   12,    2,    2,    4,    5,    6,    7,    8,    9,   13,   14,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 17, QMetaType::UChar,   18,   10,

       0        // eod
};

void DecodesModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DecodesModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->reply((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< QTime(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< quint32(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< quint8(*)>(_a[9]))); break;
        case 1: _t->add_decode((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const ClientKey(*)>(_a[2])),(*reinterpret_cast< QTime(*)>(_a[3])),(*reinterpret_cast< qint32(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< quint32(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< bool(*)>(_a[10])),(*reinterpret_cast< bool(*)>(_a[11]))); break;
        case 2: _t->decodes_cleared((*reinterpret_cast< const ClientKey(*)>(_a[1]))); break;
        case 3: _t->do_reply((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DecodesModel::*)(ClientKey const & , QTime , qint32 , float , quint32 , QString const & , QString const & , bool , quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DecodesModel::reply)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DecodesModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QStandardItemModel::staticMetaObject>(),
    qt_meta_stringdata_DecodesModel.data,
    qt_meta_data_DecodesModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DecodesModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DecodesModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DecodesModel.stringdata0))
        return static_cast<void*>(this);
    return QStandardItemModel::qt_metacast(_clname);
}

int DecodesModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DecodesModel::reply(ClientKey const & _t1, QTime _t2, qint32 _t3, float _t4, quint32 _t5, QString const & _t6, QString const & _t7, bool _t8, quint8 _t9)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

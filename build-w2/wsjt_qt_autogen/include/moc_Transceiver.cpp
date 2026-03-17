/****************************************************************************
** Meta object code from reading C++ file 'Transceiver.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Transceiver/Transceiver.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Transceiver.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Transceiver_t {
    QByteArrayData data[27];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Transceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Transceiver_t qt_meta_stringdata_Transceiver = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Transceiver"
QT_MOC_LITERAL(1, 12, 10), // "resolution"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 16), // "tciframeswritten"
QT_MOC_LITERAL(4, 41, 14), // "tci_mod_active"
QT_MOC_LITERAL(5, 56, 6), // "update"
QT_MOC_LITERAL(6, 63, 29), // "Transceiver::TransceiverState"
QT_MOC_LITERAL(7, 93, 15), // "sequence_number"
QT_MOC_LITERAL(8, 109, 7), // "failure"
QT_MOC_LITERAL(9, 117, 6), // "reason"
QT_MOC_LITERAL(10, 124, 8), // "finished"
QT_MOC_LITERAL(11, 133, 3), // "set"
QT_MOC_LITERAL(12, 137, 5), // "start"
QT_MOC_LITERAL(13, 143, 4), // "stop"
QT_MOC_LITERAL(14, 148, 4), // "MODE"
QT_MOC_LITERAL(15, 153, 3), // "UNK"
QT_MOC_LITERAL(16, 157, 2), // "CW"
QT_MOC_LITERAL(17, 160, 4), // "CW_R"
QT_MOC_LITERAL(18, 165, 3), // "USB"
QT_MOC_LITERAL(19, 169, 3), // "LSB"
QT_MOC_LITERAL(20, 173, 3), // "FSK"
QT_MOC_LITERAL(21, 177, 5), // "FSK_R"
QT_MOC_LITERAL(22, 183, 5), // "DIG_U"
QT_MOC_LITERAL(23, 189, 5), // "DIG_L"
QT_MOC_LITERAL(24, 195, 2), // "AM"
QT_MOC_LITERAL(25, 198, 2), // "FM"
QT_MOC_LITERAL(26, 201, 6) // "DIG_FM"

    },
    "Transceiver\0resolution\0\0tciframeswritten\0"
    "tci_mod_active\0update\0"
    "Transceiver::TransceiverState\0"
    "sequence_number\0failure\0reason\0finished\0"
    "set\0start\0stop\0MODE\0UNK\0CW\0CW_R\0USB\0"
    "LSB\0FSK\0FSK_R\0DIG_U\0DIG_L\0AM\0FM\0DIG_FM"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Transceiver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       1,   86, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,
       5,    2,   68,    2, 0x06 /* Public */,
       8,    1,   73,    2, 0x06 /* Public */,
      10,    0,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    2,   77,    2, 0x0a /* Public */,
      12,    1,   82,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UInt,    2,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, QMetaType::UInt,    2,    7,
    QMetaType::Void, QMetaType::UInt,    7,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
      14,   14, 0x0,   12,   91,

 // enum data: key, value
      15, uint(Transceiver::UNK),
      16, uint(Transceiver::CW),
      17, uint(Transceiver::CW_R),
      18, uint(Transceiver::USB),
      19, uint(Transceiver::LSB),
      20, uint(Transceiver::FSK),
      21, uint(Transceiver::FSK_R),
      22, uint(Transceiver::DIG_U),
      23, uint(Transceiver::DIG_L),
      24, uint(Transceiver::AM),
      25, uint(Transceiver::FM),
      26, uint(Transceiver::DIG_FM),

       0        // eod
};

void Transceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Transceiver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resolution((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->tciframeswritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->tci_mod_active((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->update((*reinterpret_cast< const Transceiver::TransceiverState(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 4: _t->failure((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->finished(); break;
        case 6: _t->set((*reinterpret_cast< const Transceiver::TransceiverState(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 7: _t->start((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 8: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Transceiver::TransceiverState >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Transceiver::TransceiverState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Transceiver::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::resolution)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::tciframeswritten)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::tci_mod_active)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)(Transceiver::TransceiverState const & , unsigned  ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::update)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)(QString const & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::failure)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::finished)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Transceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Transceiver.data,
    qt_meta_data_Transceiver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Transceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Transceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Transceiver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Transceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Transceiver::resolution(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Transceiver::tciframeswritten(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Transceiver::tci_mod_active(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Transceiver::update(Transceiver::TransceiverState const & _t1, unsigned  _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(const_cast< Transceiver *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Transceiver::failure(QString const & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Transceiver *>(this), &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Transceiver::finished()const
{
    QMetaObject::activate(const_cast< Transceiver *>(this), &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

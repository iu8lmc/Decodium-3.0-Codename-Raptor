/****************************************************************************
** Meta object code from reading C++ file 'Modulator.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Modulator/Modulator.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Modulator.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Modulator_t {
    QByteArrayData data[22];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Modulator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Modulator_t qt_meta_stringdata_Modulator = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Modulator"
QT_MOC_LITERAL(1, 10, 12), // "stateChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "ModulatorState"
QT_MOC_LITERAL(4, 39, 5), // "start"
QT_MOC_LITERAL(5, 45, 4), // "mode"
QT_MOC_LITERAL(6, 50, 13), // "symbolsLength"
QT_MOC_LITERAL(7, 64, 15), // "framesPerSymbol"
QT_MOC_LITERAL(8, 80, 9), // "frequency"
QT_MOC_LITERAL(9, 90, 11), // "toneSpacing"
QT_MOC_LITERAL(10, 102, 12), // "SoundOutput*"
QT_MOC_LITERAL(11, 115, 7), // "Channel"
QT_MOC_LITERAL(12, 123, 11), // "synchronize"
QT_MOC_LITERAL(13, 135, 8), // "fastMode"
QT_MOC_LITERAL(14, 144, 5), // "dBSNR"
QT_MOC_LITERAL(15, 150, 8), // "TRperiod"
QT_MOC_LITERAL(16, 159, 4), // "stop"
QT_MOC_LITERAL(17, 164, 5), // "quick"
QT_MOC_LITERAL(18, 170, 4), // "tune"
QT_MOC_LITERAL(19, 175, 8), // "newState"
QT_MOC_LITERAL(20, 184, 12), // "setFrequency"
QT_MOC_LITERAL(21, 197, 12) // "newFrequency"

    },
    "Modulator\0stateChanged\0\0ModulatorState\0"
    "start\0mode\0symbolsLength\0framesPerSymbol\0"
    "frequency\0toneSpacing\0SoundOutput*\0"
    "Channel\0synchronize\0fastMode\0dBSNR\0"
    "TRperiod\0stop\0quick\0tune\0newState\0"
    "setFrequency\0newFrequency"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Modulator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,   11,   77,    2, 0x0a /* Public */,
       4,   10,  100,    2, 0x2a /* Public | MethodCloned */,
       4,    9,  121,    2, 0x2a /* Public | MethodCloned */,
       4,    8,  140,    2, 0x2a /* Public | MethodCloned */,
       4,    7,  157,    2, 0x2a /* Public | MethodCloned */,
       4,    6,  172,    2, 0x2a /* Public | MethodCloned */,
      16,    1,  185,    2, 0x0a /* Public */,
      16,    0,  188,    2, 0x2a /* Public | MethodCloned */,
      18,    1,  189,    2, 0x0a /* Public */,
      18,    0,  192,    2, 0x2a /* Public | MethodCloned */,
      20,    1,  193,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 10, 0x80000000 | 11, QMetaType::Bool, QMetaType::Bool, QMetaType::Double, QMetaType::Double,    5,    6,    7,    8,    9,    2,    2,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 10, 0x80000000 | 11, QMetaType::Bool, QMetaType::Bool, QMetaType::Double,    5,    6,    7,    8,    9,    2,    2,   12,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 10, 0x80000000 | 11, QMetaType::Bool, QMetaType::Bool,    5,    6,    7,    8,    9,    2,    2,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 10, 0x80000000 | 11, QMetaType::Bool,    5,    6,    7,    8,    9,    2,    2,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 10, 0x80000000 | 11,    5,    6,    7,    8,    9,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 10,    5,    6,    7,    8,    9,    2,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   21,

       0        // eod
};

void Modulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Modulator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< ModulatorState(*)>(_a[1]))); break;
        case 1: _t->start((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< SoundOutput*(*)>(_a[6])),(*reinterpret_cast< Channel(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10])),(*reinterpret_cast< double(*)>(_a[11]))); break;
        case 2: _t->start((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< SoundOutput*(*)>(_a[6])),(*reinterpret_cast< Channel(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10]))); break;
        case 3: _t->start((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< SoundOutput*(*)>(_a[6])),(*reinterpret_cast< Channel(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9]))); break;
        case 4: _t->start((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< SoundOutput*(*)>(_a[6])),(*reinterpret_cast< Channel(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8]))); break;
        case 5: _t->start((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< SoundOutput*(*)>(_a[6])),(*reinterpret_cast< Channel(*)>(_a[7]))); break;
        case 6: _t->start((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< SoundOutput*(*)>(_a[6]))); break;
        case 7: _t->stop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->stop(); break;
        case 9: _t->tune((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->tune(); break;
        case 11: _t->setFrequency((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Modulator::*)(ModulatorState ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modulator::stateChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Modulator::staticMetaObject = { {
    QMetaObject::SuperData::link<AudioDevice::staticMetaObject>(),
    qt_meta_stringdata_Modulator.data,
    qt_meta_data_Modulator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Modulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Modulator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Modulator.stringdata0))
        return static_cast<void*>(this);
    return AudioDevice::qt_metacast(_clname);
}

int Modulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AudioDevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Modulator::stateChanged(ModulatorState _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Modulator *>(this), &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

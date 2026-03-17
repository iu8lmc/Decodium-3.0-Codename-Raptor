/****************************************************************************
** Meta object code from reading C++ file 'soundout.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Audio/soundout.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SoundOutput_t {
    QByteArrayData data[20];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SoundOutput_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SoundOutput_t qt_meta_stringdata_SoundOutput = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SoundOutput"
QT_MOC_LITERAL(1, 12, 5), // "error"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "message"
QT_MOC_LITERAL(4, 27, 6), // "status"
QT_MOC_LITERAL(5, 34, 9), // "setFormat"
QT_MOC_LITERAL(6, 44, 16), // "QAudioDeviceInfo"
QT_MOC_LITERAL(7, 61, 6), // "device"
QT_MOC_LITERAL(8, 68, 8), // "channels"
QT_MOC_LITERAL(9, 77, 15), // "frames_buffered"
QT_MOC_LITERAL(10, 93, 7), // "restart"
QT_MOC_LITERAL(11, 101, 10), // "QIODevice*"
QT_MOC_LITERAL(12, 112, 7), // "suspend"
QT_MOC_LITERAL(13, 120, 6), // "resume"
QT_MOC_LITERAL(14, 127, 5), // "reset"
QT_MOC_LITERAL(15, 133, 4), // "stop"
QT_MOC_LITERAL(16, 138, 14), // "setAttenuation"
QT_MOC_LITERAL(17, 153, 16), // "resetAttenuation"
QT_MOC_LITERAL(18, 170, 18), // "handleStateChanged"
QT_MOC_LITERAL(19, 189, 13) // "QAudio::State"

    },
    "SoundOutput\0error\0\0message\0status\0"
    "setFormat\0QAudioDeviceInfo\0device\0"
    "channels\0frames_buffered\0restart\0"
    "QIODevice*\0suspend\0resume\0reset\0stop\0"
    "setAttenuation\0resetAttenuation\0"
    "handleStateChanged\0QAudio::State"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SoundOutput[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   80,    2, 0x0a /* Public */,
       5,    2,   87,    2, 0x2a /* Public | MethodCloned */,
      10,    1,   92,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x0a /* Public */,
      13,    0,   96,    2, 0x0a /* Public */,
      14,    0,   97,    2, 0x0a /* Public */,
      15,    0,   98,    2, 0x0a /* Public */,
      16,    1,   99,    2, 0x0a /* Public */,
      17,    0,  102,    2, 0x0a /* Public */,
      18,    1,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, QMetaType::UInt, QMetaType::Int,    7,    8,    9,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UInt,    7,    8,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,    2,

       0        // eod
};

void SoundOutput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SoundOutput *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->status((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setFormat((*reinterpret_cast< const QAudioDeviceInfo(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->setFormat((*reinterpret_cast< const QAudioDeviceInfo(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 4: _t->restart((*reinterpret_cast< QIODevice*(*)>(_a[1]))); break;
        case 5: _t->suspend(); break;
        case 6: _t->resume(); break;
        case 7: _t->reset(); break;
        case 8: _t->stop(); break;
        case 9: _t->setAttenuation((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 10: _t->resetAttenuation(); break;
        case 11: _t->handleStateChanged((*reinterpret_cast< QAudio::State(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudioDeviceInfo >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudioDeviceInfo >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QIODevice* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudio::State >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SoundOutput::*)(QString ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SoundOutput::error)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SoundOutput::*)(QString ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SoundOutput::status)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SoundOutput::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SoundOutput.data,
    qt_meta_data_SoundOutput,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SoundOutput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoundOutput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SoundOutput.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SoundOutput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void SoundOutput::error(QString _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< SoundOutput *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SoundOutput::status(QString _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< SoundOutput *>(this), &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'soundin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Audio/soundin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SoundInput_t {
    QByteArrayData data[19];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SoundInput_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SoundInput_t qt_meta_stringdata_SoundInput = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SoundInput"
QT_MOC_LITERAL(1, 11, 5), // "error"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 7), // "message"
QT_MOC_LITERAL(4, 26, 6), // "status"
QT_MOC_LITERAL(5, 33, 5), // "start"
QT_MOC_LITERAL(6, 39, 16), // "QAudioDeviceInfo"
QT_MOC_LITERAL(7, 56, 15), // "framesPerBuffer"
QT_MOC_LITERAL(8, 72, 12), // "AudioDevice*"
QT_MOC_LITERAL(9, 85, 4), // "sink"
QT_MOC_LITERAL(10, 90, 16), // "downSampleFactor"
QT_MOC_LITERAL(11, 107, 20), // "AudioDevice::Channel"
QT_MOC_LITERAL(12, 128, 7), // "suspend"
QT_MOC_LITERAL(13, 136, 6), // "resume"
QT_MOC_LITERAL(14, 143, 4), // "stop"
QT_MOC_LITERAL(15, 148, 5), // "reset"
QT_MOC_LITERAL(16, 154, 21), // "report_dropped_frames"
QT_MOC_LITERAL(17, 176, 18), // "handleStateChanged"
QT_MOC_LITERAL(18, 195, 13) // "QAudio::State"

    },
    "SoundInput\0error\0\0message\0status\0start\0"
    "QAudioDeviceInfo\0framesPerBuffer\0"
    "AudioDevice*\0sink\0downSampleFactor\0"
    "AudioDevice::Channel\0suspend\0resume\0"
    "stop\0reset\0report_dropped_frames\0"
    "handleStateChanged\0QAudio::State"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SoundInput[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    5,   65,    2, 0x0a /* Public */,
       5,    4,   76,    2, 0x2a /* Public | MethodCloned */,
      12,    0,   85,    2, 0x0a /* Public */,
      13,    0,   86,    2, 0x0a /* Public */,
      14,    0,   87,    2, 0x0a /* Public */,
      15,    1,   88,    2, 0x0a /* Public */,
      17,    1,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int, 0x80000000 | 8, QMetaType::UInt, 0x80000000 | 11,    2,    7,    9,   10,    2,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int, 0x80000000 | 8, QMetaType::UInt,    2,    7,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, 0x80000000 | 18,    2,

       0        // eod
};

void SoundInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SoundInput *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->status((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->start((*reinterpret_cast< const QAudioDeviceInfo(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< AudioDevice*(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< AudioDevice::Channel(*)>(_a[5]))); break;
        case 3: _t->start((*reinterpret_cast< const QAudioDeviceInfo(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< AudioDevice*(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 4: _t->suspend(); break;
        case 5: _t->resume(); break;
        case 6: _t->stop(); break;
        case 7: _t->reset((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->handleStateChanged((*reinterpret_cast< QAudio::State(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AudioDevice::Channel >(); break;
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
        case 8:
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
            using _t = void (SoundInput::*)(QString ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SoundInput::error)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SoundInput::*)(QString ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SoundInput::status)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SoundInput::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SoundInput.data,
    qt_meta_data_SoundInput,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SoundInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoundInput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SoundInput.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SoundInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SoundInput::error(QString _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< SoundInput *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SoundInput::status(QString _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< SoundInput *>(this), &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

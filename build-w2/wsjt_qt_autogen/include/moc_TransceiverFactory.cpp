/****************************************************************************
** Meta object code from reading C++ file 'TransceiverFactory.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Transceiver/TransceiverFactory.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TransceiverFactory.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TransceiverFactory_t {
    QByteArrayData data[26];
    char stringdata0[399];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TransceiverFactory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TransceiverFactory_t qt_meta_stringdata_TransceiverFactory = {
    {
QT_MOC_LITERAL(0, 0, 18), // "TransceiverFactory"
QT_MOC_LITERAL(1, 19, 8), // "DataBits"
QT_MOC_LITERAL(2, 28, 15), // "seven_data_bits"
QT_MOC_LITERAL(3, 44, 15), // "eight_data_bits"
QT_MOC_LITERAL(4, 60, 17), // "default_data_bits"
QT_MOC_LITERAL(5, 78, 8), // "StopBits"
QT_MOC_LITERAL(6, 87, 12), // "one_stop_bit"
QT_MOC_LITERAL(7, 100, 13), // "two_stop_bits"
QT_MOC_LITERAL(8, 114, 17), // "default_stop_bits"
QT_MOC_LITERAL(9, 132, 9), // "Handshake"
QT_MOC_LITERAL(10, 142, 17), // "handshake_default"
QT_MOC_LITERAL(11, 160, 14), // "handshake_none"
QT_MOC_LITERAL(12, 175, 17), // "handshake_XonXoff"
QT_MOC_LITERAL(13, 193, 18), // "handshake_hardware"
QT_MOC_LITERAL(14, 212, 9), // "PTTMethod"
QT_MOC_LITERAL(15, 222, 14), // "PTT_method_VOX"
QT_MOC_LITERAL(16, 237, 14), // "PTT_method_CAT"
QT_MOC_LITERAL(17, 252, 14), // "PTT_method_DTR"
QT_MOC_LITERAL(18, 267, 14), // "PTT_method_RTS"
QT_MOC_LITERAL(19, 282, 13), // "TXAudioSource"
QT_MOC_LITERAL(20, 296, 21), // "TX_audio_source_front"
QT_MOC_LITERAL(21, 318, 20), // "TX_audio_source_rear"
QT_MOC_LITERAL(22, 339, 9), // "SplitMode"
QT_MOC_LITERAL(23, 349, 15), // "split_mode_none"
QT_MOC_LITERAL(24, 365, 14), // "split_mode_rig"
QT_MOC_LITERAL(25, 380, 18) // "split_mode_emulate"

    },
    "TransceiverFactory\0DataBits\0seven_data_bits\0"
    "eight_data_bits\0default_data_bits\0"
    "StopBits\0one_stop_bit\0two_stop_bits\0"
    "default_stop_bits\0Handshake\0"
    "handshake_default\0handshake_none\0"
    "handshake_XonXoff\0handshake_hardware\0"
    "PTTMethod\0PTT_method_VOX\0PTT_method_CAT\0"
    "PTT_method_DTR\0PTT_method_RTS\0"
    "TXAudioSource\0TX_audio_source_front\0"
    "TX_audio_source_rear\0SplitMode\0"
    "split_mode_none\0split_mode_rig\0"
    "split_mode_emulate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TransceiverFactory[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       6,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    3,   44,
       5,    5, 0x0,    3,   50,
       9,    9, 0x0,    4,   56,
      14,   14, 0x0,    4,   64,
      19,   19, 0x0,    2,   72,
      22,   22, 0x0,    3,   76,

 // enum data: key, value
       2, uint(TransceiverFactory::seven_data_bits),
       3, uint(TransceiverFactory::eight_data_bits),
       4, uint(TransceiverFactory::default_data_bits),
       6, uint(TransceiverFactory::one_stop_bit),
       7, uint(TransceiverFactory::two_stop_bits),
       8, uint(TransceiverFactory::default_stop_bits),
      10, uint(TransceiverFactory::handshake_default),
      11, uint(TransceiverFactory::handshake_none),
      12, uint(TransceiverFactory::handshake_XonXoff),
      13, uint(TransceiverFactory::handshake_hardware),
      15, uint(TransceiverFactory::PTT_method_VOX),
      16, uint(TransceiverFactory::PTT_method_CAT),
      17, uint(TransceiverFactory::PTT_method_DTR),
      18, uint(TransceiverFactory::PTT_method_RTS),
      20, uint(TransceiverFactory::TX_audio_source_front),
      21, uint(TransceiverFactory::TX_audio_source_rear),
      23, uint(TransceiverFactory::split_mode_none),
      24, uint(TransceiverFactory::split_mode_rig),
      25, uint(TransceiverFactory::split_mode_emulate),

       0        // eod
};

void TransceiverFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject TransceiverFactory::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TransceiverFactory.data,
    qt_meta_data_TransceiverFactory,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TransceiverFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TransceiverFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TransceiverFactory.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TransceiverFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

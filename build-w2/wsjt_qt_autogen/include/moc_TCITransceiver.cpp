/****************************************************************************
** Meta object code from reading C++ file 'TCITransceiver.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Transceiver/TCITransceiver.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TCITransceiver.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TCITransceiver_t {
    QByteArrayData data[87];
    char stringdata0[1028];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TCITransceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TCITransceiver_t qt_meta_stringdata_TCITransceiver = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TCITransceiver"
QT_MOC_LITERAL(1, 15, 10), // "sendIqData"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "float*"
QT_MOC_LITERAL(4, 34, 13), // "sendAudioData"
QT_MOC_LITERAL(5, 48, 9), // "receiveIQ"
QT_MOC_LITERAL(6, 58, 13), // "txAudioChrono"
QT_MOC_LITERAL(7, 72, 9), // "tci_done1"
QT_MOC_LITERAL(8, 82, 9), // "tci_done2"
QT_MOC_LITERAL(9, 92, 9), // "tci_done3"
QT_MOC_LITERAL(10, 102, 9), // "tci_done4"
QT_MOC_LITERAL(11, 112, 9), // "tci_done5"
QT_MOC_LITERAL(12, 122, 9), // "tci_done6"
QT_MOC_LITERAL(13, 132, 9), // "tci_done7"
QT_MOC_LITERAL(14, 142, 9), // "tci_done8"
QT_MOC_LITERAL(15, 152, 15), // "sendTextMessage"
QT_MOC_LITERAL(16, 168, 7), // "message"
QT_MOC_LITERAL(17, 176, 11), // "txAudioData"
QT_MOC_LITERAL(18, 188, 3), // "len"
QT_MOC_LITERAL(19, 192, 4), // "data"
QT_MOC_LITERAL(20, 197, 16), // "onBinaryReceived"
QT_MOC_LITERAL(21, 214, 17), // "onMessageReceived"
QT_MOC_LITERAL(22, 232, 3), // "str"
QT_MOC_LITERAL(23, 236, 7), // "onError"
QT_MOC_LITERAL(24, 244, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(25, 273, 3), // "err"
QT_MOC_LITERAL(26, 277, 11), // "onConnected"
QT_MOC_LITERAL(27, 289, 14), // "onDisconnected"
QT_MOC_LITERAL(28, 304, 7), // "Tci_Cmd"
QT_MOC_LITERAL(29, 312, 11), // "Cmd_Unknown"
QT_MOC_LITERAL(30, 324, 10), // "Cmd_Device"
QT_MOC_LITERAL(31, 335, 15), // "Cmd_ReceiveOnly"
QT_MOC_LITERAL(32, 351, 12), // "Cmd_TrxCount"
QT_MOC_LITERAL(33, 364, 16), // "Cmd_ChannelCount"
QT_MOC_LITERAL(34, 381, 13), // "Cmd_VfoLimits"
QT_MOC_LITERAL(35, 395, 12), // "Cmd_IfLimits"
QT_MOC_LITERAL(36, 408, 12), // "Cmd_ModeList"
QT_MOC_LITERAL(37, 421, 8), // "Cmd_Mode"
QT_MOC_LITERAL(38, 430, 9), // "Cmd_Ready"
QT_MOC_LITERAL(39, 440, 8), // "Cmd_Stop"
QT_MOC_LITERAL(40, 449, 9), // "Cmd_Start"
QT_MOC_LITERAL(41, 459, 10), // "Cmd_Preamp"
QT_MOC_LITERAL(42, 470, 7), // "Cmd_Dds"
QT_MOC_LITERAL(43, 478, 6), // "Cmd_If"
QT_MOC_LITERAL(44, 485, 7), // "Cmd_Trx"
QT_MOC_LITERAL(45, 493, 12), // "Cmd_RxEnable"
QT_MOC_LITERAL(46, 506, 12), // "Cmd_TxEnable"
QT_MOC_LITERAL(47, 519, 19), // "Cmd_RxChannelEnable"
QT_MOC_LITERAL(48, 539, 13), // "Cmd_RitEnable"
QT_MOC_LITERAL(49, 553, 13), // "Cmd_RitOffset"
QT_MOC_LITERAL(50, 567, 13), // "Cmd_XitEnable"
QT_MOC_LITERAL(51, 581, 13), // "Cmd_XitOffset"
QT_MOC_LITERAL(52, 595, 15), // "Cmd_SplitEnable"
QT_MOC_LITERAL(53, 611, 8), // "Cmd_IqSR"
QT_MOC_LITERAL(54, 620, 11), // "Cmd_IqStart"
QT_MOC_LITERAL(55, 632, 10), // "Cmd_IqStop"
QT_MOC_LITERAL(56, 643, 11), // "Cmd_CWSpeed"
QT_MOC_LITERAL(57, 655, 11), // "Cmd_CWDelay"
QT_MOC_LITERAL(58, 667, 8), // "Cmd_Spot"
QT_MOC_LITERAL(59, 676, 14), // "Cmd_SpotDelete"
QT_MOC_LITERAL(60, 691, 14), // "Cmd_FilterBand"
QT_MOC_LITERAL(61, 706, 7), // "Cmd_VFO"
QT_MOC_LITERAL(62, 714, 11), // "Cmd_Version"
QT_MOC_LITERAL(63, 726, 8), // "Cmd_Tune"
QT_MOC_LITERAL(64, 735, 10), // "Cmd_RxMute"
QT_MOC_LITERAL(65, 746, 10), // "Cmd_Smeter"
QT_MOC_LITERAL(66, 757, 9), // "Cmd_Power"
QT_MOC_LITERAL(67, 767, 7), // "Cmd_SWR"
QT_MOC_LITERAL(68, 775, 12), // "Cmd_ECoderRX"
QT_MOC_LITERAL(69, 788, 13), // "Cmd_ECoderVFO"
QT_MOC_LITERAL(70, 802, 11), // "Cmd_AudioSR"
QT_MOC_LITERAL(71, 814, 14), // "Cmd_AudioStart"
QT_MOC_LITERAL(72, 829, 13), // "Cmd_AudioStop"
QT_MOC_LITERAL(73, 843, 12), // "Cmd_AppFocus"
QT_MOC_LITERAL(74, 856, 10), // "Cmd_Volume"
QT_MOC_LITERAL(75, 867, 13), // "Cmd_SqlEnable"
QT_MOC_LITERAL(76, 881, 12), // "Cmd_SqlLevel"
QT_MOC_LITERAL(77, 894, 9), // "Cmd_Drive"
QT_MOC_LITERAL(78, 904, 13), // "Cmd_TuneDrive"
QT_MOC_LITERAL(79, 918, 8), // "Cmd_Mute"
QT_MOC_LITERAL(80, 927, 19), // "Cmd_RxSensorsEnable"
QT_MOC_LITERAL(81, 947, 19), // "Cmd_TxSensorsEnable"
QT_MOC_LITERAL(82, 967, 13), // "Cmd_RxSensors"
QT_MOC_LITERAL(83, 981, 13), // "Cmd_TxSensors"
QT_MOC_LITERAL(84, 995, 11), // "Cmd_AgcMode"
QT_MOC_LITERAL(85, 1007, 11), // "Cmd_AgcGain"
QT_MOC_LITERAL(86, 1019, 8) // "Cmd_Lock"

    },
    "TCITransceiver\0sendIqData\0\0float*\0"
    "sendAudioData\0receiveIQ\0txAudioChrono\0"
    "tci_done1\0tci_done2\0tci_done3\0tci_done4\0"
    "tci_done5\0tci_done6\0tci_done7\0tci_done8\0"
    "sendTextMessage\0message\0txAudioData\0"
    "len\0data\0onBinaryReceived\0onMessageReceived\0"
    "str\0onError\0QAbstractSocket::SocketError\0"
    "err\0onConnected\0onDisconnected\0Tci_Cmd\0"
    "Cmd_Unknown\0Cmd_Device\0Cmd_ReceiveOnly\0"
    "Cmd_TrxCount\0Cmd_ChannelCount\0"
    "Cmd_VfoLimits\0Cmd_IfLimits\0Cmd_ModeList\0"
    "Cmd_Mode\0Cmd_Ready\0Cmd_Stop\0Cmd_Start\0"
    "Cmd_Preamp\0Cmd_Dds\0Cmd_If\0Cmd_Trx\0"
    "Cmd_RxEnable\0Cmd_TxEnable\0Cmd_RxChannelEnable\0"
    "Cmd_RitEnable\0Cmd_RitOffset\0Cmd_XitEnable\0"
    "Cmd_XitOffset\0Cmd_SplitEnable\0Cmd_IqSR\0"
    "Cmd_IqStart\0Cmd_IqStop\0Cmd_CWSpeed\0"
    "Cmd_CWDelay\0Cmd_Spot\0Cmd_SpotDelete\0"
    "Cmd_FilterBand\0Cmd_VFO\0Cmd_Version\0"
    "Cmd_Tune\0Cmd_RxMute\0Cmd_Smeter\0Cmd_Power\0"
    "Cmd_SWR\0Cmd_ECoderRX\0Cmd_ECoderVFO\0"
    "Cmd_AudioSR\0Cmd_AudioStart\0Cmd_AudioStop\0"
    "Cmd_AppFocus\0Cmd_Volume\0Cmd_SqlEnable\0"
    "Cmd_SqlLevel\0Cmd_Drive\0Cmd_TuneDrive\0"
    "Cmd_Mute\0Cmd_RxSensorsEnable\0"
    "Cmd_TxSensorsEnable\0Cmd_RxSensors\0"
    "Cmd_TxSensors\0Cmd_AgcMode\0Cmd_AgcGain\0"
    "Cmd_Lock"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCITransceiver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       1,  160, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  109,    2, 0x06 /* Public */,
       4,    3,  118,    2, 0x06 /* Public */,
       5,    2,  125,    2, 0x06 /* Public */,
       6,    1,  130,    2, 0x06 /* Public */,
       7,    0,  133,    2, 0x06 /* Public */,
       8,    0,  134,    2, 0x06 /* Public */,
       9,    0,  135,    2, 0x06 /* Public */,
      10,    0,  136,    2, 0x06 /* Public */,
      11,    0,  137,    2, 0x06 /* Public */,
      12,    0,  138,    2, 0x06 /* Public */,
      13,    0,  139,    2, 0x06 /* Public */,
      14,    0,  140,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  141,    2, 0x0a /* Public */,
      17,    2,  144,    2, 0x0a /* Public */,
      20,    1,  149,    2, 0x08 /* Private */,
      21,    1,  152,    2, 0x08 /* Private */,
      23,    1,  155,    2, 0x08 /* Private */,
      26,    0,  158,    2, 0x08 /* Private */,
      27,    0,  159,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::UInt, 0x80000000 | 3, QMetaType::Bool,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::UInt, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 3,   18,   19,
    QMetaType::Void, QMetaType::QByteArray,   19,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
      28,   28, 0x0,   58,  165,

 // enum data: key, value
      29, uint(TCITransceiver::Cmd_Unknown),
      30, uint(TCITransceiver::Cmd_Device),
      31, uint(TCITransceiver::Cmd_ReceiveOnly),
      32, uint(TCITransceiver::Cmd_TrxCount),
      33, uint(TCITransceiver::Cmd_ChannelCount),
      34, uint(TCITransceiver::Cmd_VfoLimits),
      35, uint(TCITransceiver::Cmd_IfLimits),
      36, uint(TCITransceiver::Cmd_ModeList),
      37, uint(TCITransceiver::Cmd_Mode),
      38, uint(TCITransceiver::Cmd_Ready),
      39, uint(TCITransceiver::Cmd_Stop),
      40, uint(TCITransceiver::Cmd_Start),
      41, uint(TCITransceiver::Cmd_Preamp),
      42, uint(TCITransceiver::Cmd_Dds),
      43, uint(TCITransceiver::Cmd_If),
      44, uint(TCITransceiver::Cmd_Trx),
      45, uint(TCITransceiver::Cmd_RxEnable),
      46, uint(TCITransceiver::Cmd_TxEnable),
      47, uint(TCITransceiver::Cmd_RxChannelEnable),
      48, uint(TCITransceiver::Cmd_RitEnable),
      49, uint(TCITransceiver::Cmd_RitOffset),
      50, uint(TCITransceiver::Cmd_XitEnable),
      51, uint(TCITransceiver::Cmd_XitOffset),
      52, uint(TCITransceiver::Cmd_SplitEnable),
      53, uint(TCITransceiver::Cmd_IqSR),
      54, uint(TCITransceiver::Cmd_IqStart),
      55, uint(TCITransceiver::Cmd_IqStop),
      56, uint(TCITransceiver::Cmd_CWSpeed),
      57, uint(TCITransceiver::Cmd_CWDelay),
      58, uint(TCITransceiver::Cmd_Spot),
      59, uint(TCITransceiver::Cmd_SpotDelete),
      60, uint(TCITransceiver::Cmd_FilterBand),
      61, uint(TCITransceiver::Cmd_VFO),
      62, uint(TCITransceiver::Cmd_Version),
      63, uint(TCITransceiver::Cmd_Tune),
      64, uint(TCITransceiver::Cmd_RxMute),
      65, uint(TCITransceiver::Cmd_Smeter),
      66, uint(TCITransceiver::Cmd_Power),
      67, uint(TCITransceiver::Cmd_SWR),
      68, uint(TCITransceiver::Cmd_ECoderRX),
      69, uint(TCITransceiver::Cmd_ECoderVFO),
      70, uint(TCITransceiver::Cmd_AudioSR),
      71, uint(TCITransceiver::Cmd_AudioStart),
      72, uint(TCITransceiver::Cmd_AudioStop),
      73, uint(TCITransceiver::Cmd_AppFocus),
      74, uint(TCITransceiver::Cmd_Volume),
      75, uint(TCITransceiver::Cmd_SqlEnable),
      76, uint(TCITransceiver::Cmd_SqlLevel),
      77, uint(TCITransceiver::Cmd_Drive),
      78, uint(TCITransceiver::Cmd_TuneDrive),
      79, uint(TCITransceiver::Cmd_Mute),
      80, uint(TCITransceiver::Cmd_RxSensorsEnable),
      81, uint(TCITransceiver::Cmd_TxSensorsEnable),
      82, uint(TCITransceiver::Cmd_RxSensors),
      83, uint(TCITransceiver::Cmd_TxSensors),
      84, uint(TCITransceiver::Cmd_AgcMode),
      85, uint(TCITransceiver::Cmd_AgcGain),
      86, uint(TCITransceiver::Cmd_Lock),

       0        // eod
};

void TCITransceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TCITransceiver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendIqData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< float*(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 1: _t->sendAudioData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< float*(*)>(_a[3]))); break;
        case 2: _t->receiveIQ((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->txAudioChrono((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 4: _t->tci_done1(); break;
        case 5: _t->tci_done2(); break;
        case 6: _t->tci_done3(); break;
        case 7: _t->tci_done4(); break;
        case 8: _t->tci_done5(); break;
        case 9: _t->tci_done6(); break;
        case 10: _t->tci_done7(); break;
        case 11: _t->tci_done8(); break;
        case 12: _t->sendTextMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->txAudioData((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< float*(*)>(_a[2]))); break;
        case 14: _t->onBinaryReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 15: _t->onMessageReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 17: _t->onConnected(); break;
        case 18: _t->onDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TCITransceiver::*)(int , quint32 , float * , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::sendIqData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)(int , quint32 , float * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::sendAudioData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)(bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::receiveIQ)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::txAudioChrono)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done1)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done2)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done3)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done4)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done5)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done6)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done7)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done8)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TCITransceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<PollingTransceiver::staticMetaObject>(),
    qt_meta_stringdata_TCITransceiver.data,
    qt_meta_data_TCITransceiver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TCITransceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCITransceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TCITransceiver.stringdata0))
        return static_cast<void*>(this);
    return PollingTransceiver::qt_metacast(_clname);
}

int TCITransceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PollingTransceiver::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void TCITransceiver::sendIqData(int _t1, quint32 _t2, float * _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TCITransceiver::sendAudioData(int _t1, quint32 _t2, float * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TCITransceiver::receiveIQ(bool _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TCITransceiver::txAudioChrono(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TCITransceiver::tci_done1()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void TCITransceiver::tci_done2()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void TCITransceiver::tci_done3()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void TCITransceiver::tci_done4()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void TCITransceiver::tci_done5()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void TCITransceiver::tci_done6()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void TCITransceiver::tci_done7()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void TCITransceiver::tci_done8()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

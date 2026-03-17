/****************************************************************************
** Meta object code from reading C++ file 'ClientWidget.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../UDPExamples/ClientWidget.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientWidget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientWidget_t {
    QByteArrayData data[61];
    char stringdata0[613];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientWidget_t qt_meta_stringdata_ClientWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ClientWidget"
QT_MOC_LITERAL(1, 13, 16), // "do_clear_decodes"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "ClientKey"
QT_MOC_LITERAL(4, 41, 3), // "key"
QT_MOC_LITERAL(5, 45, 6), // "window"
QT_MOC_LITERAL(6, 52, 8), // "do_close"
QT_MOC_LITERAL(7, 61, 8), // "do_reply"
QT_MOC_LITERAL(8, 70, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 82, 8), // "modifier"
QT_MOC_LITERAL(10, 91, 10), // "do_halt_tx"
QT_MOC_LITERAL(11, 102, 9), // "auto_only"
QT_MOC_LITERAL(12, 112, 12), // "do_free_text"
QT_MOC_LITERAL(13, 125, 4), // "text"
QT_MOC_LITERAL(14, 130, 8), // "location"
QT_MOC_LITERAL(15, 139, 18), // "highlight_callsign"
QT_MOC_LITERAL(16, 158, 4), // "call"
QT_MOC_LITERAL(17, 163, 2), // "bg"
QT_MOC_LITERAL(18, 166, 2), // "fg"
QT_MOC_LITERAL(19, 169, 9), // "last_only"
QT_MOC_LITERAL(20, 179, 20), // "switch_configuration"
QT_MOC_LITERAL(21, 200, 18), // "configuration_name"
QT_MOC_LITERAL(22, 219, 9), // "configure"
QT_MOC_LITERAL(23, 229, 4), // "mode"
QT_MOC_LITERAL(24, 234, 19), // "frequency_tolerance"
QT_MOC_LITERAL(25, 254, 7), // "submode"
QT_MOC_LITERAL(26, 262, 9), // "fast_mode"
QT_MOC_LITERAL(27, 272, 9), // "tr_period"
QT_MOC_LITERAL(28, 282, 5), // "rx_df"
QT_MOC_LITERAL(29, 288, 7), // "dx_call"
QT_MOC_LITERAL(30, 296, 7), // "dx_grid"
QT_MOC_LITERAL(31, 304, 17), // "generate_messages"
QT_MOC_LITERAL(32, 322, 13), // "update_status"
QT_MOC_LITERAL(33, 336, 9), // "Frequency"
QT_MOC_LITERAL(34, 346, 1), // "f"
QT_MOC_LITERAL(35, 348, 6), // "report"
QT_MOC_LITERAL(36, 355, 7), // "tx_mode"
QT_MOC_LITERAL(37, 363, 10), // "tx_enabled"
QT_MOC_LITERAL(38, 374, 12), // "transmitting"
QT_MOC_LITERAL(39, 387, 8), // "decoding"
QT_MOC_LITERAL(40, 396, 5), // "tx_df"
QT_MOC_LITERAL(41, 402, 7), // "de_call"
QT_MOC_LITERAL(42, 410, 7), // "de_grid"
QT_MOC_LITERAL(43, 418, 16), // "watchdog_timeout"
QT_MOC_LITERAL(44, 435, 8), // "sub_mode"
QT_MOC_LITERAL(45, 444, 15), // "special_op_mode"
QT_MOC_LITERAL(46, 460, 10), // "tx_message"
QT_MOC_LITERAL(47, 471, 12), // "decode_added"
QT_MOC_LITERAL(48, 484, 6), // "is_new"
QT_MOC_LITERAL(49, 491, 3), // "snr"
QT_MOC_LITERAL(50, 495, 10), // "delta_time"
QT_MOC_LITERAL(51, 506, 15), // "delta_frequency"
QT_MOC_LITERAL(52, 522, 7), // "message"
QT_MOC_LITERAL(53, 530, 14), // "low_confidence"
QT_MOC_LITERAL(54, 545, 7), // "off_air"
QT_MOC_LITERAL(55, 553, 17), // "beacon_spot_added"
QT_MOC_LITERAL(56, 571, 5), // "drift"
QT_MOC_LITERAL(57, 577, 8), // "callsign"
QT_MOC_LITERAL(58, 586, 4), // "grid"
QT_MOC_LITERAL(59, 591, 5), // "power"
QT_MOC_LITERAL(60, 597, 15) // "decodes_cleared"

    },
    "ClientWidget\0do_clear_decodes\0\0ClientKey\0"
    "key\0window\0do_close\0do_reply\0QModelIndex\0"
    "modifier\0do_halt_tx\0auto_only\0"
    "do_free_text\0text\0location\0"
    "highlight_callsign\0call\0bg\0fg\0last_only\0"
    "switch_configuration\0configuration_name\0"
    "configure\0mode\0frequency_tolerance\0"
    "submode\0fast_mode\0tr_period\0rx_df\0"
    "dx_call\0dx_grid\0generate_messages\0"
    "update_status\0Frequency\0f\0report\0"
    "tx_mode\0tx_enabled\0transmitting\0"
    "decoding\0tx_df\0de_call\0de_grid\0"
    "watchdog_timeout\0sub_mode\0special_op_mode\0"
    "tx_message\0decode_added\0is_new\0snr\0"
    "delta_time\0delta_frequency\0message\0"
    "low_confidence\0off_air\0beacon_spot_added\0"
    "drift\0callsign\0grid\0power\0decodes_cleared"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   99,    2, 0x06 /* Public */,
       1,    1,  104,    2, 0x26 /* Public | MethodCloned */,
       6,    1,  107,    2, 0x06 /* Public */,
       7,    2,  110,    2, 0x06 /* Public */,
      10,    2,  115,    2, 0x06 /* Public */,
      12,    3,  120,    2, 0x06 /* Public */,
      14,    2,  127,    2, 0x06 /* Public */,
      15,    5,  132,    2, 0x06 /* Public */,
      15,    4,  143,    2, 0x26 /* Public | MethodCloned */,
      15,    3,  152,    2, 0x26 /* Public | MethodCloned */,
      15,    2,  159,    2, 0x26 /* Public | MethodCloned */,
      20,    2,  164,    2, 0x06 /* Public */,
      22,   10,  169,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      32,   22,  190,    2, 0x0a /* Public */,
      47,   10,  235,    2, 0x0a /* Public */,
      55,   11,  256,    2, 0x0a /* Public */,
      60,    1,  279,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UChar,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 8, QMetaType::UChar,    2,    9,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,   11,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::Bool,    4,   13,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,   13,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QColor, QMetaType::QColor, QMetaType::Bool,    4,   16,   17,   18,   19,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QColor, QMetaType::QColor,    4,   16,   17,   18,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QColor,    4,   16,   17,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,   16,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,   21,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::UInt, QMetaType::QString, QMetaType::Bool, QMetaType::UInt, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    4,   23,   24,   25,   26,   27,   28,   29,   30,   31,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 33, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::UInt, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::UChar, QMetaType::UInt, QMetaType::UInt, QMetaType::QString, QMetaType::QString,    4,   34,   23,   29,   35,   36,   37,   38,   39,   28,   40,   41,   42,   30,   43,   44,   26,   45,   24,   27,   21,   46,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 3, QMetaType::QTime, QMetaType::Int, QMetaType::Float, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Bool,   48,    4,    2,   49,   50,   51,   23,   52,   53,   54,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 3, QMetaType::QTime, QMetaType::Int, QMetaType::Float, 0x80000000 | 33, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Bool,   48,    4,    2,   49,   50,   51,   56,   57,   58,   59,   54,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void ClientWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->do_clear_decodes((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 1: _t->do_clear_decodes((*reinterpret_cast< const ClientKey(*)>(_a[1]))); break;
        case 2: _t->do_close((*reinterpret_cast< const ClientKey(*)>(_a[1]))); break;
        case 3: _t->do_reply((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 4: _t->do_halt_tx((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->do_free_text((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->location((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->highlight_callsign((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QColor(*)>(_a[3])),(*reinterpret_cast< const QColor(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 8: _t->highlight_callsign((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QColor(*)>(_a[3])),(*reinterpret_cast< const QColor(*)>(_a[4]))); break;
        case 9: _t->highlight_callsign((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QColor(*)>(_a[3]))); break;
        case 10: _t->highlight_callsign((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->switch_configuration((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 12: _t->configure((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< quint32(*)>(_a[6])),(*reinterpret_cast< quint32(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< bool(*)>(_a[10]))); break;
        case 13: _t->update_status((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< Frequency(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< quint32(*)>(_a[10])),(*reinterpret_cast< quint32(*)>(_a[11])),(*reinterpret_cast< const QString(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13])),(*reinterpret_cast< const QString(*)>(_a[14])),(*reinterpret_cast< bool(*)>(_a[15])),(*reinterpret_cast< const QString(*)>(_a[16])),(*reinterpret_cast< bool(*)>(_a[17])),(*reinterpret_cast< quint8(*)>(_a[18])),(*reinterpret_cast< quint32(*)>(_a[19])),(*reinterpret_cast< quint32(*)>(_a[20])),(*reinterpret_cast< const QString(*)>(_a[21])),(*reinterpret_cast< const QString(*)>(_a[22]))); break;
        case 14: _t->decode_added((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const ClientKey(*)>(_a[2])),(*reinterpret_cast< QTime(*)>(_a[3])),(*reinterpret_cast< qint32(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< quint32(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< bool(*)>(_a[10]))); break;
        case 15: _t->beacon_spot_added((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const ClientKey(*)>(_a[2])),(*reinterpret_cast< QTime(*)>(_a[3])),(*reinterpret_cast< qint32(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< Frequency(*)>(_a[6])),(*reinterpret_cast< qint32(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< qint32(*)>(_a[10])),(*reinterpret_cast< bool(*)>(_a[11]))); break;
        case 16: _t->decodes_cleared((*reinterpret_cast< const ClientKey(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClientWidget::*)(ClientKey const & , quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientWidget::do_clear_decodes)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClientWidget::*)(ClientKey const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientWidget::do_close)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ClientWidget::*)(QModelIndex const & , quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientWidget::do_reply)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ClientWidget::*)(ClientKey const & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientWidget::do_halt_tx)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ClientWidget::*)(ClientKey const & , QString const & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientWidget::do_free_text)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ClientWidget::*)(ClientKey const & , QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientWidget::location)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ClientWidget::*)(ClientKey const & , QString const & , QColor const & , QColor const & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientWidget::highlight_callsign)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ClientWidget::*)(ClientKey const & , QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientWidget::switch_configuration)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (ClientWidget::*)(ClientKey const & , QString const & , quint32 , QString const & , bool , quint32 , quint32 , QString const & , QString const & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientWidget::configure)) {
                *result = 12;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ClientWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QDockWidget::staticMetaObject>(),
    qt_meta_stringdata_ClientWidget.data,
    qt_meta_data_ClientWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ClientWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientWidget.stringdata0))
        return static_cast<void*>(this);
    return QDockWidget::qt_metacast(_clname);
}

int ClientWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void ClientWidget::do_clear_decodes(ClientKey const & _t1, quint8 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void ClientWidget::do_close(ClientKey const & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ClientWidget::do_reply(QModelIndex const & _t1, quint8 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ClientWidget::do_halt_tx(ClientKey const & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ClientWidget::do_free_text(ClientKey const & _t1, QString const & _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ClientWidget::location(ClientKey const & _t1, QString const & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ClientWidget::highlight_callsign(ClientKey const & _t1, QString const & _t2, QColor const & _t3, QColor const & _t4, bool _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 11
void ClientWidget::switch_configuration(ClientKey const & _t1, QString const & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ClientWidget::configure(ClientKey const & _t1, QString const & _t2, quint32 _t3, QString const & _t4, bool _t5, quint32 _t6, quint32 _t7, QString const & _t8, QString const & _t9, bool _t10)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

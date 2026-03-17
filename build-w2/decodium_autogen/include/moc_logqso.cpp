/****************************************************************************
** Meta object code from reading C++ file 'logqso.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../widgets/logqso.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logqso.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogQSO_t {
    QByteArrayData data[26];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogQSO_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogQSO_t qt_meta_stringdata_LogQSO = {
    {
QT_MOC_LITERAL(0, 0, 6), // "LogQSO"
QT_MOC_LITERAL(1, 7, 9), // "acceptQSO"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 12), // "QSO_date_off"
QT_MOC_LITERAL(4, 31, 4), // "call"
QT_MOC_LITERAL(5, 36, 4), // "grid"
QT_MOC_LITERAL(6, 41, 16), // "Radio::Frequency"
QT_MOC_LITERAL(7, 58, 9), // "dial_freq"
QT_MOC_LITERAL(8, 68, 4), // "mode"
QT_MOC_LITERAL(9, 73, 8), // "rpt_sent"
QT_MOC_LITERAL(10, 82, 12), // "rpt_received"
QT_MOC_LITERAL(11, 95, 8), // "tx_power"
QT_MOC_LITERAL(12, 104, 8), // "comments"
QT_MOC_LITERAL(13, 113, 4), // "name"
QT_MOC_LITERAL(14, 118, 11), // "QSO_date_on"
QT_MOC_LITERAL(15, 130, 13), // "operator_call"
QT_MOC_LITERAL(16, 144, 7), // "my_call"
QT_MOC_LITERAL(17, 152, 7), // "my_grid"
QT_MOC_LITERAL(18, 160, 13), // "exchange_sent"
QT_MOC_LITERAL(19, 174, 13), // "exchange_rcvd"
QT_MOC_LITERAL(20, 188, 8), // "propmode"
QT_MOC_LITERAL(21, 197, 9), // "satellite"
QT_MOC_LITERAL(22, 207, 8), // "sat_mode"
QT_MOC_LITERAL(23, 216, 6), // "freqRx"
QT_MOC_LITERAL(24, 223, 4), // "ADIF"
QT_MOC_LITERAL(25, 228, 6) // "accept"

    },
    "LogQSO\0acceptQSO\0\0QSO_date_off\0call\0"
    "grid\0Radio::Frequency\0dial_freq\0mode\0"
    "rpt_sent\0rpt_received\0tx_power\0comments\0"
    "name\0QSO_date_on\0operator_call\0my_call\0"
    "my_grid\0exchange_sent\0exchange_rcvd\0"
    "propmode\0satellite\0sat_mode\0freqRx\0"
    "ADIF\0accept"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogQSO[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,   21,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      25,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, 0x80000000 | 6, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QByteArray,    3,    4,    5,    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void LogQSO::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LogQSO *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->acceptQSO((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< Radio::Frequency(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< const QString(*)>(_a[10])),(*reinterpret_cast< const QDateTime(*)>(_a[11])),(*reinterpret_cast< const QString(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13])),(*reinterpret_cast< const QString(*)>(_a[14])),(*reinterpret_cast< const QString(*)>(_a[15])),(*reinterpret_cast< const QString(*)>(_a[16])),(*reinterpret_cast< const QString(*)>(_a[17])),(*reinterpret_cast< const QString(*)>(_a[18])),(*reinterpret_cast< const QString(*)>(_a[19])),(*reinterpret_cast< const QString(*)>(_a[20])),(*reinterpret_cast< const QByteArray(*)>(_a[21]))); break;
        case 1: _t->accept(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Radio::Frequency >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LogQSO::*)(QDateTime const & , QString const & , QString const & , Radio::Frequency , QString const & , QString const & , QString const & , QString const & , QString const & , QString const & , QDateTime const & , QString const & , QString const & , QString const & , QString const & , QString const & , QString const & , QString const & , QString const & , QString const & , QByteArray const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LogQSO::acceptQSO)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LogQSO::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_LogQSO.data,
    qt_meta_data_LogQSO,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LogQSO::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogQSO::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LogQSO.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int LogQSO::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void LogQSO::acceptQSO(QDateTime const & _t1, QString const & _t2, QString const & _t3, Radio::Frequency _t4, QString const & _t5, QString const & _t6, QString const & _t7, QString const & _t8, QString const & _t9, QString const & _t10, QDateTime const & _t11, QString const & _t12, QString const & _t13, QString const & _t14, QString const & _t15, QString const & _t16, QString const & _t17, QString const & _t18, QString const & _t19, QString const & _t20, QByteArray const & _t21)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t12))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t13))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t14))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t15))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t16))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t17))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t18))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t19))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t20))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t21))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

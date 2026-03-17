/****************************************************************************
** Meta object code from reading C++ file 'NtpClient.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Network/NtpClient.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NtpClient.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NtpClient_t {
    QByteArrayData data[18];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NtpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NtpClient_t qt_meta_stringdata_NtpClient = {
    {
QT_MOC_LITERAL(0, 0, 9), // "NtpClient"
QT_MOC_LITERAL(1, 10, 13), // "offsetUpdated"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "offsetMs"
QT_MOC_LITERAL(4, 34, 17), // "syncStatusChanged"
QT_MOC_LITERAL(5, 52, 6), // "synced"
QT_MOC_LITERAL(6, 59, 10), // "statusText"
QT_MOC_LITERAL(7, 70, 13), // "errorOccurred"
QT_MOC_LITERAL(8, 84, 8), // "errorMsg"
QT_MOC_LITERAL(9, 93, 16), // "onRefreshTimeout"
QT_MOC_LITERAL(10, 110, 14), // "onQueryTimeout"
QT_MOC_LITERAL(11, 125, 11), // "onReadyRead"
QT_MOC_LITERAL(12, 137, 17), // "onDnsLookupResult"
QT_MOC_LITERAL(13, 155, 9), // "QHostInfo"
QT_MOC_LITERAL(14, 165, 8), // "hostInfo"
QT_MOC_LITERAL(15, 174, 11), // "onHttpReply"
QT_MOC_LITERAL(16, 186, 14), // "QNetworkReply*"
QT_MOC_LITERAL(17, 201, 5) // "reply"

    },
    "NtpClient\0offsetUpdated\0\0offsetMs\0"
    "syncStatusChanged\0synced\0statusText\0"
    "errorOccurred\0errorMsg\0onRefreshTimeout\0"
    "onQueryTimeout\0onReadyRead\0onDnsLookupResult\0"
    "QHostInfo\0hostInfo\0onHttpReply\0"
    "QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NtpClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    2,   57,    2, 0x06 /* Public */,
       7,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   65,    2, 0x08 /* Private */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,
      12,    1,   68,    2, 0x08 /* Private */,
      15,    1,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void NtpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NtpClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->offsetUpdated((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->syncStatusChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->errorOccurred((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onRefreshTimeout(); break;
        case 4: _t->onQueryTimeout(); break;
        case 5: _t->onReadyRead(); break;
        case 6: _t->onDnsLookupResult((*reinterpret_cast< QHostInfo(*)>(_a[1]))); break;
        case 7: _t->onHttpReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QHostInfo >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NtpClient::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NtpClient::offsetUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NtpClient::*)(bool , QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NtpClient::syncStatusChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NtpClient::*)(QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NtpClient::errorOccurred)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NtpClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NtpClient.data,
    qt_meta_data_NtpClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NtpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NtpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NtpClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NtpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void NtpClient::offsetUpdated(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NtpClient::syncStatusChanged(bool _t1, QString const & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NtpClient::errorOccurred(QString const & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

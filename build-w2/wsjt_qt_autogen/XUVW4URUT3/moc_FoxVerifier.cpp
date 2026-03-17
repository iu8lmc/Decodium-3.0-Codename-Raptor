/****************************************************************************
** Meta object code from reading C++ file 'FoxVerifier.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Network/FoxVerifier.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FoxVerifier.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FoxVerifier_t {
    QByteArrayData data[18];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FoxVerifier_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FoxVerifier_t qt_meta_stringdata_FoxVerifier = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FoxVerifier"
QT_MOC_LITERAL(1, 12, 14), // "verifyComplete"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "status"
QT_MOC_LITERAL(4, 35, 2), // "ts"
QT_MOC_LITERAL(5, 38, 8), // "callsign"
QT_MOC_LITERAL(6, 47, 4), // "code"
QT_MOC_LITERAL(7, 52, 2), // "hz"
QT_MOC_LITERAL(8, 55, 8), // "response"
QT_MOC_LITERAL(9, 64, 11), // "verifyError"
QT_MOC_LITERAL(10, 76, 12), // "httpFinished"
QT_MOC_LITERAL(11, 89, 14), // "httpRedirected"
QT_MOC_LITERAL(12, 104, 3), // "url"
QT_MOC_LITERAL(13, 108, 13), // "httpEncrypted"
QT_MOC_LITERAL(14, 122, 9), // "sslErrors"
QT_MOC_LITERAL(15, 132, 16), // "QList<QSslError>"
QT_MOC_LITERAL(16, 149, 13), // "errorOccurred"
QT_MOC_LITERAL(17, 163, 27) // "QNetworkReply::NetworkError"

    },
    "FoxVerifier\0verifyComplete\0\0status\0"
    "ts\0callsign\0code\0hz\0response\0verifyError\0"
    "httpFinished\0httpRedirected\0url\0"
    "httpEncrypted\0sslErrors\0QList<QSslError>\0"
    "errorOccurred\0QNetworkReply::NetworkError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FoxVerifier[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   49,    2, 0x06 /* Public */,
       9,    6,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   75,    2, 0x08 /* Private */,
      11,    1,   76,    2, 0x08 /* Private */,
      13,    0,   79,    2, 0x08 /* Private */,
      14,    1,   80,    2, 0x08 /* Private */,
      16,    1,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, QMetaType::UInt, QMetaType::QString,    3,    4,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, QMetaType::UInt, QMetaType::QString,    3,    4,    5,    6,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 17,    6,

       0        // eod
};

void FoxVerifier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FoxVerifier *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->verifyComplete((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6]))); break;
        case 1: _t->verifyError((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6]))); break;
        case 2: _t->httpFinished(); break;
        case 3: _t->httpRedirected((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 4: _t->httpEncrypted(); break;
        case 5: _t->sslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 6: _t->errorOccurred((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FoxVerifier::*)(int , QDateTime , QString , QString , unsigned int , QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FoxVerifier::verifyComplete)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FoxVerifier::*)(int , QDateTime , QString , QString , unsigned int , QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FoxVerifier::verifyError)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FoxVerifier::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FoxVerifier.data,
    qt_meta_data_FoxVerifier,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FoxVerifier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FoxVerifier::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FoxVerifier.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FoxVerifier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FoxVerifier::verifyComplete(int _t1, QDateTime _t2, QString _t3, QString _t4, unsigned int _t5, QString const & _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FoxVerifier::verifyError(int _t1, QDateTime _t2, QString _t3, QString _t4, unsigned int _t5, QString const & _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

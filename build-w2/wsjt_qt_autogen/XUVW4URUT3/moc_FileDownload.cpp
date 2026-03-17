/****************************************************************************
** Meta object code from reading C++ file 'FileDownload.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Network/FileDownload.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileDownload.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileDownload_t {
    QByteArrayData data[24];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileDownload_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileDownload_t qt_meta_stringdata_FileDownload = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FileDownload"
QT_MOC_LITERAL(1, 13, 8), // "complete"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "filename"
QT_MOC_LITERAL(4, 32, 8), // "progress"
QT_MOC_LITERAL(5, 41, 13), // "load_finished"
QT_MOC_LITERAL(6, 55, 14), // "download_error"
QT_MOC_LITERAL(7, 70, 6), // "reason"
QT_MOC_LITERAL(8, 77, 5), // "error"
QT_MOC_LITERAL(9, 83, 14), // "start_download"
QT_MOC_LITERAL(10, 98, 8), // "download"
QT_MOC_LITERAL(11, 107, 3), // "url"
QT_MOC_LITERAL(12, 111, 5), // "store"
QT_MOC_LITERAL(13, 117, 5), // "abort"
QT_MOC_LITERAL(14, 123, 16), // "downloadComplete"
QT_MOC_LITERAL(15, 140, 14), // "QNetworkReply*"
QT_MOC_LITERAL(16, 155, 4), // "data"
QT_MOC_LITERAL(17, 160, 16), // "downloadProgress"
QT_MOC_LITERAL(18, 177, 8), // "recieved"
QT_MOC_LITERAL(19, 186, 5), // "total"
QT_MOC_LITERAL(20, 192, 13), // "errorOccurred"
QT_MOC_LITERAL(21, 206, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(22, 234, 4), // "code"
QT_MOC_LITERAL(23, 239, 13) // "replyComplete"

    },
    "FileDownload\0complete\0\0filename\0"
    "progress\0load_finished\0download_error\0"
    "reason\0error\0start_download\0download\0"
    "url\0store\0abort\0downloadComplete\0"
    "QNetworkReply*\0data\0downloadProgress\0"
    "recieved\0total\0errorOccurred\0"
    "QNetworkReply::NetworkError\0code\0"
    "replyComplete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileDownload[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       5,    0,   85,    2, 0x06 /* Public */,
       6,    1,   86,    2, 0x06 /* Public */,
       8,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   92,    2, 0x0a /* Public */,
      10,    1,   93,    2, 0x0a /* Public */,
      12,    0,   96,    2, 0x0a /* Public */,
      13,    0,   97,    2, 0x0a /* Public */,
      14,    1,   98,    2, 0x0a /* Public */,
      17,    2,  101,    2, 0x0a /* Public */,
      20,    1,  106,    2, 0x0a /* Public */,
      23,    0,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,

       0        // eod
};

void FileDownload::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileDownload *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->complete((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->progress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->load_finished(); break;
        case 3: _t->download_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->start_download(); break;
        case 6: _t->download((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 7: _t->store(); break;
        case 8: _t->abort(); break;
        case 9: _t->downloadComplete((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 11: _t->errorOccurred((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 12: _t->replyComplete(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 11:
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
            using _t = void (FileDownload::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileDownload::complete)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FileDownload::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileDownload::progress)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FileDownload::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileDownload::load_finished)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FileDownload::*)(QString const & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileDownload::download_error)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FileDownload::*)(QString const & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileDownload::error)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileDownload::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FileDownload.data,
    qt_meta_data_FileDownload,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileDownload::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileDownload::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileDownload.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileDownload::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void FileDownload::complete(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileDownload::progress(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FileDownload::load_finished()const
{
    QMetaObject::activate(const_cast< FileDownload *>(this), &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FileDownload::download_error(QString const & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< FileDownload *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FileDownload::error(QString const & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< FileDownload *>(this), &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

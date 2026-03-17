/****************************************************************************
** Meta object code from reading C++ file 'FileDownload.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Network/FileDownload.hpp"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileDownload.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN12FileDownloadE_t {};
} // unnamed namespace

template <> constexpr inline auto FileDownload::qt_create_metaobjectdata<qt_meta_tag_ZN12FileDownloadE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "FileDownload",
        "complete",
        "",
        "filename",
        "progress",
        "load_finished",
        "download_error",
        "reason",
        "error",
        "start_download",
        "download",
        "QUrl",
        "url",
        "store",
        "abort",
        "downloadComplete",
        "QNetworkReply*",
        "data",
        "downloadProgress",
        "recieved",
        "total",
        "errorOccurred",
        "QNetworkReply::NetworkError",
        "code",
        "replyComplete"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'complete'
        QtMocHelpers::SignalData<void(QString)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'progress'
        QtMocHelpers::SignalData<void(QString)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'load_finished'
        QtMocHelpers::SignalData<void() const>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'download_error'
        QtMocHelpers::SignalData<void(QString const &) const>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Signal 'error'
        QtMocHelpers::SignalData<void(QString const &) const>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'start_download'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'download'
        QtMocHelpers::SlotData<void(QUrl)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Slot 'store'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'abort'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'downloadComplete'
        QtMocHelpers::SlotData<void(QNetworkReply *)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 16, 17 },
        }}),
        // Slot 'downloadProgress'
        QtMocHelpers::SlotData<void(qint64, qint64)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 19 }, { QMetaType::LongLong, 20 },
        }}),
        // Slot 'errorOccurred'
        QtMocHelpers::SlotData<void(QNetworkReply::NetworkError)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 22, 23 },
        }}),
        // Slot 'replyComplete'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<FileDownload, qt_meta_tag_ZN12FileDownloadE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject FileDownload::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12FileDownloadE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12FileDownloadE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12FileDownloadE_t>.metaTypes,
    nullptr
} };

void FileDownload::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<FileDownload *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->complete((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->progress((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->load_finished(); break;
        case 3: _t->download_error((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->error((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->start_download(); break;
        case 6: _t->download((*reinterpret_cast<std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 7: _t->store(); break;
        case 8: _t->abort(); break;
        case 9: _t->downloadComplete((*reinterpret_cast<std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 10: _t->downloadProgress((*reinterpret_cast<std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qint64>>(_a[2]))); break;
        case 11: _t->errorOccurred((*reinterpret_cast<std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1]))); break;
        case 12: _t->replyComplete(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (FileDownload::*)(QString )>(_a, &FileDownload::complete, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileDownload::*)(QString )>(_a, &FileDownload::progress, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileDownload::*)() const>(_a, &FileDownload::load_finished, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileDownload::*)(QString const & ) const>(_a, &FileDownload::download_error, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileDownload::*)(QString const & ) const>(_a, &FileDownload::error, 4))
            return;
    }
}

const QMetaObject *FileDownload::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileDownload::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12FileDownloadE_t>.strings))
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
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void FileDownload::complete(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void FileDownload::progress(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void FileDownload::load_finished()const
{
    QMetaObject::activate(const_cast< FileDownload *>(this), &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FileDownload::download_error(QString const & _t1)const
{
    QMetaObject::activate<void>(const_cast< FileDownload *>(this), &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void FileDownload::error(QString const & _t1)const
{
    QMetaObject::activate<void>(const_cast< FileDownload *>(this), &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP

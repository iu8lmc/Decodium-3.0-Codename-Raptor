/****************************************************************************
** Meta object code from reading C++ file 'Cloudlog.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Network/Cloudlog.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Cloudlog.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8CloudlogE_t {};
} // unnamed namespace

template <> constexpr inline auto Cloudlog::qt_create_metaobjectdata<qt_meta_tag_ZN8CloudlogE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Cloudlog",
        "apikey_ok",
        "",
        "apikey_ro",
        "apikey_invalid",
        "testApi",
        "url",
        "apiKey"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'apikey_ok'
        QtMocHelpers::SignalData<void() const>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'apikey_ro'
        QtMocHelpers::SignalData<void() const>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'apikey_invalid'
        QtMocHelpers::SignalData<void() const>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'testApi'
        QtMocHelpers::SlotData<void(QString const &, QString const &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 }, { QMetaType::QString, 7 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Cloudlog, qt_meta_tag_ZN8CloudlogE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Cloudlog::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8CloudlogE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8CloudlogE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8CloudlogE_t>.metaTypes,
    nullptr
} };

void Cloudlog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Cloudlog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->apikey_ok(); break;
        case 1: _t->apikey_ro(); break;
        case 2: _t->apikey_invalid(); break;
        case 3: _t->testApi((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Cloudlog::*)() const>(_a, &Cloudlog::apikey_ok, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Cloudlog::*)() const>(_a, &Cloudlog::apikey_ro, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Cloudlog::*)() const>(_a, &Cloudlog::apikey_invalid, 2))
            return;
    }
}

const QMetaObject *Cloudlog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cloudlog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8CloudlogE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Cloudlog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Cloudlog::apikey_ok()const
{
    QMetaObject::activate(const_cast< Cloudlog *>(this), &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Cloudlog::apikey_ro()const
{
    QMetaObject::activate(const_cast< Cloudlog *>(this), &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Cloudlog::apikey_invalid()const
{
    QMetaObject::activate(const_cast< Cloudlog *>(this), &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP

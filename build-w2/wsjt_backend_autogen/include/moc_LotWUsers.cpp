/****************************************************************************
** Meta object code from reading C++ file 'LotWUsers.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Network/LotWUsers.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LotWUsers.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9LotWUsersE_t {};
} // unnamed namespace

template <> constexpr inline auto LotWUsers::qt_create_metaobjectdata<qt_meta_tag_ZN9LotWUsersE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "LotWUsers",
        "LotW_users_error",
        "",
        "reason",
        "progress",
        "load_finished",
        "load",
        "url",
        "fetch",
        "force_download",
        "set_age_constraint",
        "uploaded_since_days"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'LotW_users_error'
        QtMocHelpers::SignalData<void(QString const &) const>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'progress'
        QtMocHelpers::SignalData<void(QString const &) const>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'load_finished'
        QtMocHelpers::SignalData<void() const>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'load'
        QtMocHelpers::SlotData<void(QString const &, bool, bool)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 }, { QMetaType::Bool, 8 }, { QMetaType::Bool, 9 },
        }}),
        // Slot 'load'
        QtMocHelpers::SlotData<void(QString const &, bool)>(6, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 7 }, { QMetaType::Bool, 8 },
        }}),
        // Slot 'load'
        QtMocHelpers::SlotData<void(QString const &)>(6, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'set_age_constraint'
        QtMocHelpers::SlotData<void(qint64)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 11 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<LotWUsers, qt_meta_tag_ZN9LotWUsersE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject LotWUsers::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9LotWUsersE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9LotWUsersE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9LotWUsersE_t>.metaTypes,
    nullptr
} };

void LotWUsers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<LotWUsers *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->LotW_users_error((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->progress((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->load_finished(); break;
        case 3: _t->load((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3]))); break;
        case 4: _t->load((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2]))); break;
        case 5: _t->load((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->set_age_constraint((*reinterpret_cast<std::add_pointer_t<qint64>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (LotWUsers::*)(QString const & ) const>(_a, &LotWUsers::LotW_users_error, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (LotWUsers::*)(QString const & ) const>(_a, &LotWUsers::progress, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (LotWUsers::*)() const>(_a, &LotWUsers::load_finished, 2))
            return;
    }
}

const QMetaObject *LotWUsers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LotWUsers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9LotWUsersE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LotWUsers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void LotWUsers::LotW_users_error(QString const & _t1)const
{
    QMetaObject::activate<void>(const_cast< LotWUsers *>(this), &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void LotWUsers::progress(QString const & _t1)const
{
    QMetaObject::activate<void>(const_cast< LotWUsers *>(this), &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void LotWUsers::load_finished()const
{
    QMetaObject::activate(const_cast< LotWUsers *>(this), &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP

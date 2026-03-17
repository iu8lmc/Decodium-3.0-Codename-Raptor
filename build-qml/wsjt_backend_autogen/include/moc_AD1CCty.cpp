/****************************************************************************
** Meta object code from reading C++ file 'AD1CCty.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../logbook/AD1CCty.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AD1CCty.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7AD1CCtyE_t {};
} // unnamed namespace

template <> constexpr inline auto AD1CCty::qt_create_metaobjectdata<qt_meta_tag_ZN7AD1CCtyE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AD1CCty",
        "cty_loaded",
        "",
        "version",
        "Continent",
        "UN",
        "AF",
        "AN",
        "AS",
        "EU",
        "NA",
        "OC",
        "SA"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'cty_loaded'
        QtMocHelpers::SignalData<void(QString const &) const>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Continent'
        QtMocHelpers::EnumData<enum Continent>(4, 4, QMC::EnumIsScoped).add({
            {    5, Continent::UN },
            {    6, Continent::AF },
            {    7, Continent::AN },
            {    8, Continent::AS },
            {    9, Continent::EU },
            {   10, Continent::NA },
            {   11, Continent::OC },
            {   12, Continent::SA },
        }),
    };
    return QtMocHelpers::metaObjectData<AD1CCty, qt_meta_tag_ZN7AD1CCtyE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AD1CCty::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7AD1CCtyE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7AD1CCtyE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7AD1CCtyE_t>.metaTypes,
    nullptr
} };

void AD1CCty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AD1CCty *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->cty_loaded((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (AD1CCty::*)(QString const & ) const>(_a, &AD1CCty::cty_loaded, 0))
            return;
    }
}

const QMetaObject *AD1CCty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AD1CCty::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7AD1CCtyE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AD1CCty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void AD1CCty::cty_loaded(QString const & _t1)const
{
    QMetaObject::activate<void>(const_cast< AD1CCty *>(this), &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP

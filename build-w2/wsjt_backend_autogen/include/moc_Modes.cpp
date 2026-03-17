/****************************************************************************
** Meta object code from reading C++ file 'Modes.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../models/Modes.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Modes.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN5ModesE_t {};
} // unnamed namespace

template <> constexpr inline auto Modes::qt_create_metaobjectdata<qt_meta_tag_ZN5ModesE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Modes",
        "Mode",
        "ALL",
        "JT65",
        "JT9",
        "JT4",
        "WSPR",
        "Echo",
        "MSK144",
        "FreqCal",
        "FT8",
        "FT4",
        "FST4",
        "FST4W",
        "Q65",
        "FT2",
        "MODES_END_SENTINAL_AND_COUNT"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Mode'
        QtMocHelpers::EnumData<enum Mode>(1, 1, QMC::EnumFlags{}).add({
            {    2, Mode::ALL },
            {    3, Mode::JT65 },
            {    4, Mode::JT9 },
            {    5, Mode::JT4 },
            {    6, Mode::WSPR },
            {    7, Mode::Echo },
            {    8, Mode::MSK144 },
            {    9, Mode::FreqCal },
            {   10, Mode::FT8 },
            {   11, Mode::FT4 },
            {   12, Mode::FST4 },
            {   13, Mode::FST4W },
            {   14, Mode::Q65 },
            {   15, Mode::FT2 },
            {   16, Mode::MODES_END_SENTINAL_AND_COUNT },
        }),
    };
    return QtMocHelpers::metaObjectData<Modes, qt_meta_tag_ZN5ModesE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Modes::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5ModesE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5ModesE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN5ModesE_t>.metaTypes,
    nullptr
} };

void Modes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Modes *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *Modes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Modes::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5ModesE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int Modes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP

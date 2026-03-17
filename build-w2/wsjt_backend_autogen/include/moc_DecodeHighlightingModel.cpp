/****************************************************************************
** Meta object code from reading C++ file 'DecodeHighlightingModel.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../models/DecodeHighlightingModel.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DecodeHighlightingModel.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN23DecodeHighlightingModelE_t {};
} // unnamed namespace

template <> constexpr inline auto DecodeHighlightingModel::qt_create_metaobjectdata<qt_meta_tag_ZN23DecodeHighlightingModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DecodeHighlightingModel",
        "Highlight",
        "CQ",
        "MyCall",
        "Tx",
        "DXCC",
        "DXCCBand",
        "Grid",
        "GridBand",
        "Call",
        "CallBand",
        "Continent",
        "ContinentBand",
        "CQZone",
        "CQZoneBand",
        "ITUZone",
        "ITUZoneBand",
        "LotW"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Highlight'
        QtMocHelpers::EnumData<enum Highlight>(1, 1, QMC::EnumIsScoped).add({
            {    2, Highlight::CQ },
            {    3, Highlight::MyCall },
            {    4, Highlight::Tx },
            {    5, Highlight::DXCC },
            {    6, Highlight::DXCCBand },
            {    7, Highlight::Grid },
            {    8, Highlight::GridBand },
            {    9, Highlight::Call },
            {   10, Highlight::CallBand },
            {   11, Highlight::Continent },
            {   12, Highlight::ContinentBand },
            {   13, Highlight::CQZone },
            {   14, Highlight::CQZoneBand },
            {   15, Highlight::ITUZone },
            {   16, Highlight::ITUZoneBand },
            {   17, Highlight::LotW },
        }),
    };
    return QtMocHelpers::metaObjectData<DecodeHighlightingModel, qt_meta_tag_ZN23DecodeHighlightingModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject DecodeHighlightingModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23DecodeHighlightingModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23DecodeHighlightingModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN23DecodeHighlightingModelE_t>.metaTypes,
    nullptr
} };

void DecodeHighlightingModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DecodeHighlightingModel *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *DecodeHighlightingModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DecodeHighlightingModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23DecodeHighlightingModelE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int DecodeHighlightingModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP

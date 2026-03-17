/****************************************************************************
** Meta object code from reading C++ file 'DecodeHighlightingModel.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../models/DecodeHighlightingModel.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DecodeHighlightingModel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DecodeHighlightingModel_t {
    QByteArrayData data[18];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DecodeHighlightingModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DecodeHighlightingModel_t qt_meta_stringdata_DecodeHighlightingModel = {
    {
QT_MOC_LITERAL(0, 0, 23), // "DecodeHighlightingModel"
QT_MOC_LITERAL(1, 24, 9), // "Highlight"
QT_MOC_LITERAL(2, 34, 2), // "CQ"
QT_MOC_LITERAL(3, 37, 6), // "MyCall"
QT_MOC_LITERAL(4, 44, 2), // "Tx"
QT_MOC_LITERAL(5, 47, 4), // "DXCC"
QT_MOC_LITERAL(6, 52, 8), // "DXCCBand"
QT_MOC_LITERAL(7, 61, 4), // "Grid"
QT_MOC_LITERAL(8, 66, 8), // "GridBand"
QT_MOC_LITERAL(9, 75, 4), // "Call"
QT_MOC_LITERAL(10, 80, 8), // "CallBand"
QT_MOC_LITERAL(11, 89, 9), // "Continent"
QT_MOC_LITERAL(12, 99, 13), // "ContinentBand"
QT_MOC_LITERAL(13, 113, 6), // "CQZone"
QT_MOC_LITERAL(14, 120, 10), // "CQZoneBand"
QT_MOC_LITERAL(15, 131, 7), // "ITUZone"
QT_MOC_LITERAL(16, 139, 11), // "ITUZoneBand"
QT_MOC_LITERAL(17, 151, 4) // "LotW"

    },
    "DecodeHighlightingModel\0Highlight\0CQ\0"
    "MyCall\0Tx\0DXCC\0DXCCBand\0Grid\0GridBand\0"
    "Call\0CallBand\0Continent\0ContinentBand\0"
    "CQZone\0CQZoneBand\0ITUZone\0ITUZoneBand\0"
    "LotW"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DecodeHighlightingModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x2,   16,   19,

 // enum data: key, value
       2, uint(DecodeHighlightingModel::Highlight::CQ),
       3, uint(DecodeHighlightingModel::Highlight::MyCall),
       4, uint(DecodeHighlightingModel::Highlight::Tx),
       5, uint(DecodeHighlightingModel::Highlight::DXCC),
       6, uint(DecodeHighlightingModel::Highlight::DXCCBand),
       7, uint(DecodeHighlightingModel::Highlight::Grid),
       8, uint(DecodeHighlightingModel::Highlight::GridBand),
       9, uint(DecodeHighlightingModel::Highlight::Call),
      10, uint(DecodeHighlightingModel::Highlight::CallBand),
      11, uint(DecodeHighlightingModel::Highlight::Continent),
      12, uint(DecodeHighlightingModel::Highlight::ContinentBand),
      13, uint(DecodeHighlightingModel::Highlight::CQZone),
      14, uint(DecodeHighlightingModel::Highlight::CQZoneBand),
      15, uint(DecodeHighlightingModel::Highlight::ITUZone),
      16, uint(DecodeHighlightingModel::Highlight::ITUZoneBand),
      17, uint(DecodeHighlightingModel::Highlight::LotW),

       0        // eod
};

void DecodeHighlightingModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject DecodeHighlightingModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_DecodeHighlightingModel.data,
    qt_meta_data_DecodeHighlightingModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DecodeHighlightingModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DecodeHighlightingModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DecodeHighlightingModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int DecodeHighlightingModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

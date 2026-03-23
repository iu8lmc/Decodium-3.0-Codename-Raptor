/****************************************************************************
** Meta object code from reading C++ file 'RFAnalyzerWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../widgets/RFAnalyzerWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RFAnalyzerWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RFAnalyzerBackend_t {
    QByteArrayData data[24];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RFAnalyzerBackend_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RFAnalyzerBackend_t qt_meta_stringdata_RFAnalyzerBackend = {
    {
QT_MOC_LITERAL(0, 0, 17), // "RFAnalyzerBackend"
QT_MOC_LITERAL(1, 18, 11), // "dataChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "settingsChanged"
QT_MOC_LITERAL(4, 47, 9), // "resetPeak"
QT_MOC_LITERAL(5, 57, 15), // "getWaterfallRow"
QT_MOC_LITERAL(6, 73, 12), // "spectrumData"
QT_MOC_LITERAL(7, 86, 12), // "spectrumSize"
QT_MOC_LITERAL(8, 99, 2), // "df"
QT_MOC_LITERAL(9, 102, 5), // "maxDB"
QT_MOC_LITERAL(10, 108, 10), // "noiseFloor"
QT_MOC_LITERAL(11, 119, 6), // "peakDB"
QT_MOC_LITERAL(12, 126, 3), // "snr"
QT_MOC_LITERAL(13, 130, 5), // "rmsDB"
QT_MOC_LITERAL(14, 136, 13), // "zeroCrossRate"
QT_MOC_LITERAL(15, 150, 8), // "peakFreq"
QT_MOC_LITERAL(16, 159, 9), // "peakLevel"
QT_MOC_LITERAL(17, 169, 12), // "waveformData"
QT_MOC_LITERAL(18, 182, 7), // "waveRms"
QT_MOC_LITERAL(19, 190, 8), // "trPeriod"
QT_MOC_LITERAL(20, 199, 7), // "elapsed"
QT_MOC_LITERAL(21, 207, 5), // "refDB"
QT_MOC_LITERAL(22, 213, 7), // "rangeDB"
QT_MOC_LITERAL(23, 221, 4) // "mode"

    },
    "RFAnalyzerBackend\0dataChanged\0\0"
    "settingsChanged\0resetPeak\0getWaterfallRow\0"
    "spectrumData\0spectrumSize\0df\0maxDB\0"
    "noiseFloor\0peakDB\0snr\0rmsDB\0zeroCrossRate\0"
    "peakFreq\0peakLevel\0waveformData\0waveRms\0"
    "trPeriod\0elapsed\0refDB\0rangeDB\0mode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RFAnalyzerBackend[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
      18,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x02 /* Public */,
       5,    0,   37,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::QVariantList,

 // properties: name, type, flags
       6, QMetaType::QVariantList, 0x00495001,
       7, QMetaType::Int, 0x00495001,
       8, QMetaType::Float, 0x00495001,
       9, QMetaType::Float, 0x00495001,
      10, QMetaType::Float, 0x00495001,
      11, QMetaType::Float, 0x00495001,
      12, QMetaType::Float, 0x00495001,
      13, QMetaType::Float, 0x00495001,
      14, QMetaType::Int, 0x00495001,
      15, QMetaType::Float, 0x00495001,
      16, QMetaType::Float, 0x00495001,
      17, QMetaType::QVariantList, 0x00495001,
      18, QMetaType::Float, 0x00495001,
      19, QMetaType::Float, 0x00495001,
      20, QMetaType::Float, 0x00495001,
      21, QMetaType::Float, 0x00495103,
      22, QMetaType::Float, 0x00495103,
      23, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       1,
       1,
       1,

       0        // eod
};

void RFAnalyzerBackend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RFAnalyzerBackend *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dataChanged(); break;
        case 1: _t->settingsChanged(); break;
        case 2: _t->resetPeak(); break;
        case 3: { QVariantList _r = _t->getWaterfallRow();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RFAnalyzerBackend::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RFAnalyzerBackend::dataChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RFAnalyzerBackend::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RFAnalyzerBackend::settingsChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<RFAnalyzerBackend *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantList*>(_v) = _t->spectrumData(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->spectrumSize(); break;
        case 2: *reinterpret_cast< float*>(_v) = _t->df(); break;
        case 3: *reinterpret_cast< float*>(_v) = _t->maxDB(); break;
        case 4: *reinterpret_cast< float*>(_v) = _t->noiseFloor(); break;
        case 5: *reinterpret_cast< float*>(_v) = _t->peakDB(); break;
        case 6: *reinterpret_cast< float*>(_v) = _t->snr(); break;
        case 7: *reinterpret_cast< float*>(_v) = _t->rmsDB(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->zeroCrossRate(); break;
        case 9: *reinterpret_cast< float*>(_v) = _t->peakFreq(); break;
        case 10: *reinterpret_cast< float*>(_v) = _t->peakLevel(); break;
        case 11: *reinterpret_cast< QVariantList*>(_v) = _t->waveformData(); break;
        case 12: *reinterpret_cast< float*>(_v) = _t->waveRms(); break;
        case 13: *reinterpret_cast< float*>(_v) = _t->trPeriod(); break;
        case 14: *reinterpret_cast< float*>(_v) = _t->elapsed(); break;
        case 15: *reinterpret_cast< float*>(_v) = _t->refDB(); break;
        case 16: *reinterpret_cast< float*>(_v) = _t->rangeDB(); break;
        case 17: *reinterpret_cast< QString*>(_v) = _t->mode(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<RFAnalyzerBackend *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 15: _t->setRefDB(*reinterpret_cast< float*>(_v)); break;
        case 16: _t->setRangeDB(*reinterpret_cast< float*>(_v)); break;
        case 17: _t->setMode(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject RFAnalyzerBackend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_RFAnalyzerBackend.data,
    qt_meta_data_RFAnalyzerBackend,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RFAnalyzerBackend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RFAnalyzerBackend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RFAnalyzerBackend.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RFAnalyzerBackend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 18;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void RFAnalyzerBackend::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RFAnalyzerBackend::settingsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_RFAnalyzerWidget_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RFAnalyzerWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RFAnalyzerWidget_t qt_meta_stringdata_RFAnalyzerWidget = {
    {
QT_MOC_LITERAL(0, 0, 16) // "RFAnalyzerWidget"

    },
    "RFAnalyzerWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RFAnalyzerWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void RFAnalyzerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject RFAnalyzerWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_RFAnalyzerWidget.data,
    qt_meta_data_RFAnalyzerWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RFAnalyzerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RFAnalyzerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RFAnalyzerWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RFAnalyzerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

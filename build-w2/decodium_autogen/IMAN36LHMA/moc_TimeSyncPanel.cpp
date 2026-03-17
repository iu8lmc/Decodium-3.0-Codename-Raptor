/****************************************************************************
** Meta object code from reading C++ file 'TimeSyncPanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../widgets/TimeSyncPanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TimeSyncPanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TimeSyncPanel_t {
    QByteArrayData data[19];
    char stringdata0[341];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimeSyncPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimeSyncPanel_t qt_meta_stringdata_TimeSyncPanel = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TimeSyncPanel"
QT_MOC_LITERAL(1, 14, 16), // "ntpEnableToggled"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7), // "enabled"
QT_MOC_LITERAL(4, 40, 19), // "customServerChanged"
QT_MOC_LITERAL(5, 60, 6), // "server"
QT_MOC_LITERAL(6, 67, 16), // "syncNowRequested"
QT_MOC_LITERAL(7, 84, 11), // "onClockTick"
QT_MOC_LITERAL(8, 96, 21), // "on_btnSyncNow_clicked"
QT_MOC_LITERAL(9, 118, 26), // "on_btnClearHistory_clicked"
QT_MOC_LITERAL(10, 145, 23), // "on_cbNtpEnabled_toggled"
QT_MOC_LITERAL(11, 169, 7), // "checked"
QT_MOC_LITERAL(12, 177, 35), // "on_editCustomServer_editingFi..."
QT_MOC_LITERAL(13, 213, 26), // "on_btnLaunchChrono_clicked"
QT_MOC_LITERAL(14, 240, 24), // "on_btnStopChrono_clicked"
QT_MOC_LITERAL(15, 265, 29), // "on_cbChronoAutoLaunch_toggled"
QT_MOC_LITERAL(16, 295, 17), // "checkChronoStatus"
QT_MOC_LITERAL(17, 313, 19), // "updateChronoButtons"
QT_MOC_LITERAL(18, 333, 7) // "running"

    },
    "TimeSyncPanel\0ntpEnableToggled\0\0enabled\0"
    "customServerChanged\0server\0syncNowRequested\0"
    "onClockTick\0on_btnSyncNow_clicked\0"
    "on_btnClearHistory_clicked\0"
    "on_cbNtpEnabled_toggled\0checked\0"
    "on_editCustomServer_editingFinished\0"
    "on_btnLaunchChrono_clicked\0"
    "on_btnStopChrono_clicked\0"
    "on_cbChronoAutoLaunch_toggled\0"
    "checkChronoStatus\0updateChronoButtons\0"
    "running"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimeSyncPanel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       6,    0,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   86,    2, 0x08 /* Private */,
       8,    0,   87,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    1,   89,    2, 0x08 /* Private */,
      12,    0,   92,    2, 0x08 /* Private */,
      13,    0,   93,    2, 0x08 /* Private */,
      14,    0,   94,    2, 0x08 /* Private */,
      15,    1,   95,    2, 0x08 /* Private */,
      16,    0,   98,    2, 0x08 /* Private */,
      17,    1,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,

       0        // eod
};

void TimeSyncPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TimeSyncPanel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ntpEnableToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->customServerChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->syncNowRequested(); break;
        case 3: _t->onClockTick(); break;
        case 4: _t->on_btnSyncNow_clicked(); break;
        case 5: _t->on_btnClearHistory_clicked(); break;
        case 6: _t->on_cbNtpEnabled_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_editCustomServer_editingFinished(); break;
        case 8: _t->on_btnLaunchChrono_clicked(); break;
        case 9: _t->on_btnStopChrono_clicked(); break;
        case 10: _t->on_cbChronoAutoLaunch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->checkChronoStatus(); break;
        case 12: _t->updateChronoButtons((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TimeSyncPanel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TimeSyncPanel::ntpEnableToggled)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TimeSyncPanel::*)(QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TimeSyncPanel::customServerChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TimeSyncPanel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TimeSyncPanel::syncNowRequested)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TimeSyncPanel::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_TimeSyncPanel.data,
    qt_meta_data_TimeSyncPanel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TimeSyncPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeSyncPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TimeSyncPanel.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TimeSyncPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void TimeSyncPanel::ntpEnableToggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TimeSyncPanel::customServerChanged(QString const & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TimeSyncPanel::syncNowRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

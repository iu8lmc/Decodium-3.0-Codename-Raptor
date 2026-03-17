/****************************************************************************
** Meta object code from reading C++ file 'displaytext.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../widgets/displaytext.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'displaytext.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11DisplayTextE_t {};
} // unnamed namespace

template <> constexpr inline auto DisplayText::qt_create_metaobjectdata<qt_meta_tag_ZN11DisplayTextE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DisplayText",
        "selectCallsign",
        "",
        "Qt::KeyboardModifiers",
        "erased",
        "insertText",
        "text",
        "QColor",
        "bg",
        "fg",
        "call1",
        "call2",
        "QTextCursor::MoveOperation",
        "location",
        "strikeout",
        "erase",
        "highlight_callsign",
        "callsign",
        "last_period_only"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'selectCallsign'
        QtMocHelpers::SignalData<void(Qt::KeyboardModifiers)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Signal 'erased'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'insertText'
        QtMocHelpers::SlotData<void(QString const &, QColor, QColor, QString const &, QString const &, QTextCursor::MoveOperation, bool)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 }, { 0x80000000 | 7, 8 }, { 0x80000000 | 7, 9 }, { QMetaType::QString, 10 },
            { QMetaType::QString, 11 }, { 0x80000000 | 12, 13 }, { QMetaType::Bool, 14 },
        }}),
        // Slot 'insertText'
        QtMocHelpers::SlotData<void(QString const &, QColor, QColor, QString const &, QString const &, QTextCursor::MoveOperation)>(5, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 6 }, { 0x80000000 | 7, 8 }, { 0x80000000 | 7, 9 }, { QMetaType::QString, 10 },
            { QMetaType::QString, 11 }, { 0x80000000 | 12, 13 },
        }}),
        // Slot 'insertText'
        QtMocHelpers::SlotData<void(QString const &, QColor, QColor, QString const &, QString const &)>(5, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 6 }, { 0x80000000 | 7, 8 }, { 0x80000000 | 7, 9 }, { QMetaType::QString, 10 },
            { QMetaType::QString, 11 },
        }}),
        // Slot 'insertText'
        QtMocHelpers::SlotData<void(QString const &, QColor, QColor, QString const &)>(5, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 6 }, { 0x80000000 | 7, 8 }, { 0x80000000 | 7, 9 }, { QMetaType::QString, 10 },
        }}),
        // Slot 'insertText'
        QtMocHelpers::SlotData<void(QString const &, QColor, QColor)>(5, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 6 }, { 0x80000000 | 7, 8 }, { 0x80000000 | 7, 9 },
        }}),
        // Slot 'insertText'
        QtMocHelpers::SlotData<void(QString const &, QColor)>(5, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 6 }, { 0x80000000 | 7, 8 },
        }}),
        // Slot 'insertText'
        QtMocHelpers::SlotData<void(QString const &)>(5, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Slot 'erase'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'highlight_callsign'
        QtMocHelpers::SlotData<void(QString const &, QColor const &, QColor const &, bool)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 17 }, { 0x80000000 | 7, 8 }, { 0x80000000 | 7, 9 }, { QMetaType::Bool, 18 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<DisplayText, qt_meta_tag_ZN11DisplayTextE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject DisplayText::staticMetaObject = { {
    QMetaObject::SuperData::link<QTextEdit::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11DisplayTextE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11DisplayTextE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11DisplayTextE_t>.metaTypes,
    nullptr
} };

void DisplayText::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DisplayText *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->selectCallsign((*reinterpret_cast<std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1]))); break;
        case 1: _t->erased(); break;
        case 2: _t->insertText((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<QTextCursor::MoveOperation>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[7]))); break;
        case 3: _t->insertText((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<QTextCursor::MoveOperation>>(_a[6]))); break;
        case 4: _t->insertText((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[5]))); break;
        case 5: _t->insertText((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4]))); break;
        case 6: _t->insertText((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[3]))); break;
        case 7: _t->insertText((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[2]))); break;
        case 8: _t->insertText((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->erase(); break;
        case 10: _t->highlight_callsign((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[4]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (DisplayText::*)(Qt::KeyboardModifiers )>(_a, &DisplayText::selectCallsign, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (DisplayText::*)()>(_a, &DisplayText::erased, 1))
            return;
    }
}

const QMetaObject *DisplayText::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DisplayText::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11DisplayTextE_t>.strings))
        return static_cast<void*>(this);
    return QTextEdit::qt_metacast(_clname);
}

int DisplayText::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void DisplayText::selectCallsign(Qt::KeyboardModifiers _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void DisplayText::erased()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP

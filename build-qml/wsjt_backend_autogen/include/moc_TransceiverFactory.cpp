/****************************************************************************
** Meta object code from reading C++ file 'TransceiverFactory.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Transceiver/TransceiverFactory.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TransceiverFactory.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18TransceiverFactoryE_t {};
} // unnamed namespace

template <> constexpr inline auto TransceiverFactory::qt_create_metaobjectdata<qt_meta_tag_ZN18TransceiverFactoryE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "TransceiverFactory",
        "DataBits",
        "seven_data_bits",
        "eight_data_bits",
        "default_data_bits",
        "StopBits",
        "one_stop_bit",
        "two_stop_bits",
        "default_stop_bits",
        "Handshake",
        "handshake_default",
        "handshake_none",
        "handshake_XonXoff",
        "handshake_hardware",
        "PTTMethod",
        "PTT_method_VOX",
        "PTT_method_CAT",
        "PTT_method_DTR",
        "PTT_method_RTS",
        "TXAudioSource",
        "TX_audio_source_front",
        "TX_audio_source_rear",
        "SplitMode",
        "split_mode_none",
        "split_mode_rig",
        "split_mode_emulate"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'DataBits'
        QtMocHelpers::EnumData<enum DataBits>(1, 1, QMC::EnumFlags{}).add({
            {    2, DataBits::seven_data_bits },
            {    3, DataBits::eight_data_bits },
            {    4, DataBits::default_data_bits },
        }),
        // enum 'StopBits'
        QtMocHelpers::EnumData<enum StopBits>(5, 5, QMC::EnumFlags{}).add({
            {    6, StopBits::one_stop_bit },
            {    7, StopBits::two_stop_bits },
            {    8, StopBits::default_stop_bits },
        }),
        // enum 'Handshake'
        QtMocHelpers::EnumData<enum Handshake>(9, 9, QMC::EnumFlags{}).add({
            {   10, Handshake::handshake_default },
            {   11, Handshake::handshake_none },
            {   12, Handshake::handshake_XonXoff },
            {   13, Handshake::handshake_hardware },
        }),
        // enum 'PTTMethod'
        QtMocHelpers::EnumData<enum PTTMethod>(14, 14, QMC::EnumFlags{}).add({
            {   15, PTTMethod::PTT_method_VOX },
            {   16, PTTMethod::PTT_method_CAT },
            {   17, PTTMethod::PTT_method_DTR },
            {   18, PTTMethod::PTT_method_RTS },
        }),
        // enum 'TXAudioSource'
        QtMocHelpers::EnumData<enum TXAudioSource>(19, 19, QMC::EnumFlags{}).add({
            {   20, TXAudioSource::TX_audio_source_front },
            {   21, TXAudioSource::TX_audio_source_rear },
        }),
        // enum 'SplitMode'
        QtMocHelpers::EnumData<enum SplitMode>(22, 22, QMC::EnumFlags{}).add({
            {   23, SplitMode::split_mode_none },
            {   24, SplitMode::split_mode_rig },
            {   25, SplitMode::split_mode_emulate },
        }),
    };
    return QtMocHelpers::metaObjectData<TransceiverFactory, qt_meta_tag_ZN18TransceiverFactoryE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject TransceiverFactory::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18TransceiverFactoryE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18TransceiverFactoryE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18TransceiverFactoryE_t>.metaTypes,
    nullptr
} };

void TransceiverFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<TransceiverFactory *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *TransceiverFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TransceiverFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18TransceiverFactoryE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TransceiverFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'esensors.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../STEMe/esensor/esensors.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'esensors.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ESensors_t {
    QByteArrayData data[13];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ESensors_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ESensors_t qt_meta_stringdata_ESensors = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ESensors"
QT_MOC_LITERAL(1, 9, 16), // "modbusRtuRequest"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 16), // "VNetworkDataUnit"
QT_MOC_LITERAL(4, 44, 4), // "unit"
QT_MOC_LITERAL(5, 49, 17), // "modbusRtuRequests"
QT_MOC_LITERAL(6, 67, 5), // "bool*"
QT_MOC_LITERAL(7, 73, 2), // "ok"
QT_MOC_LITERAL(8, 76, 14), // "on_sensorReply"
QT_MOC_LITERAL(9, 91, 20), // "on_sensorWriteReport"
QT_MOC_LITERAL(10, 112, 6), // "status"
QT_MOC_LITERAL(11, 119, 14), // "modbusRtuReply"
QT_MOC_LITERAL(12, 134, 12) // "on_timerPoll"

    },
    "ESensors\0modbusRtuRequest\0\0VNetworkDataUnit\0"
    "unit\0modbusRtuRequests\0bool*\0ok\0"
    "on_sensorReply\0on_sensorWriteReport\0"
    "status\0modbusRtuReply\0on_timerPoll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ESensors[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    2,   47,    2, 0x06 /* Public */,
       8,    1,   52,    2, 0x06 /* Public */,
       9,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   58,    2, 0x0a /* Public */,
      12,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    4,    7,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void ESensors::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ESensors *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modbusRtuRequest((*reinterpret_cast< VNetworkDataUnit(*)>(_a[1]))); break;
        case 1: _t->modbusRtuRequests((*reinterpret_cast< VNetworkDataUnit(*)>(_a[1])),(*reinterpret_cast< bool*(*)>(_a[2]))); break;
        case 2: _t->on_sensorReply((*reinterpret_cast< VNetworkDataUnit(*)>(_a[1]))); break;
        case 3: _t->on_sensorWriteReport((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->modbusRtuReply((*reinterpret_cast< VNetworkDataUnit(*)>(_a[1]))); break;
        case 5: _t->on_timerPoll(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ESensors::*)(VNetworkDataUnit );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ESensors::modbusRtuRequest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ESensors::*)(VNetworkDataUnit , bool * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ESensors::modbusRtuRequests)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ESensors::*)(VNetworkDataUnit );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ESensors::on_sensorReply)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ESensors::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ESensors::on_sensorWriteReport)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ESensors::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ESensors.data,
    qt_meta_data_ESensors,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ESensors::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ESensors::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ESensors.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ESensors::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ESensors::modbusRtuRequest(VNetworkDataUnit _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ESensors::modbusRtuRequests(VNetworkDataUnit _t1, bool * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ESensors::on_sensorReply(VNetworkDataUnit _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ESensors::on_sensorWriteReport(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

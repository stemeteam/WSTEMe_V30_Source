/****************************************************************************
** Meta object code from reading C++ file 'sensor_sen0105.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../STEMe/vsensors/sensor_sen0105.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sensor_sen0105.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Sensor_SEN0105_t {
    QByteArrayData data[18];
    char stringdata0[473];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Sensor_SEN0105_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Sensor_SEN0105_t qt_meta_stringdata_Sensor_SEN0105 = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Sensor_SEN0105"
QT_MOC_LITERAL(1, 15, 15), // "on_displayTimer"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "on_chartUpdate"
QT_MOC_LITERAL(4, 47, 27), // "on_pushButton_Calib_clicked"
QT_MOC_LITERAL(5, 75, 26), // "on_pushButton_Exit_clicked"
QT_MOC_LITERAL(6, 102, 36), // "on_comboBox_Unit_currentIndex..."
QT_MOC_LITERAL(7, 139, 5), // "index"
QT_MOC_LITERAL(8, 145, 30), // "on_pushButton_OpenData_clicked"
QT_MOC_LITERAL(9, 176, 30), // "on_pushButton_SaveData_clicked"
QT_MOC_LITERAL(10, 207, 27), // "on_pushButton_Start_clicked"
QT_MOC_LITERAL(11, 235, 44), // "on_comboBox_SelectSample_curr..."
QT_MOC_LITERAL(12, 280, 32), // "on_pushButton_ClearChart_clicked"
QT_MOC_LITERAL(13, 313, 35), // "on_radioButton_Accumulation_t..."
QT_MOC_LITERAL(14, 349, 7), // "checked"
QT_MOC_LITERAL(15, 357, 39), // "on_pushButton_TrackLine_Defau..."
QT_MOC_LITERAL(16, 397, 39), // "on_pushButton_TrackLine_Toolt..."
QT_MOC_LITERAL(17, 437, 35) // "on_pushButton_TrackLine_Yax_c..."

    },
    "Sensor_SEN0105\0on_displayTimer\0\0"
    "on_chartUpdate\0on_pushButton_Calib_clicked\0"
    "on_pushButton_Exit_clicked\0"
    "on_comboBox_Unit_currentIndexChanged\0"
    "index\0on_pushButton_OpenData_clicked\0"
    "on_pushButton_SaveData_clicked\0"
    "on_pushButton_Start_clicked\0"
    "on_comboBox_SelectSample_currentIndexChanged\0"
    "on_pushButton_ClearChart_clicked\0"
    "on_radioButton_Accumulation_toggled\0"
    "checked\0on_pushButton_TrackLine_Default_clicked\0"
    "on_pushButton_TrackLine_Tooltip_clicked\0"
    "on_pushButton_TrackLine_Yax_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sensor_SEN0105[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    1,   94,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    1,   98,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Sensor_SEN0105::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Sensor_SEN0105 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_displayTimer(); break;
        case 1: _t->on_chartUpdate(); break;
        case 2: _t->on_pushButton_Calib_clicked(); break;
        case 3: _t->on_pushButton_Exit_clicked(); break;
        case 4: _t->on_comboBox_Unit_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_OpenData_clicked(); break;
        case 6: _t->on_pushButton_SaveData_clicked(); break;
        case 7: _t->on_pushButton_Start_clicked(); break;
        case 8: _t->on_comboBox_SelectSample_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_ClearChart_clicked(); break;
        case 10: _t->on_radioButton_Accumulation_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_TrackLine_Default_clicked(); break;
        case 12: _t->on_pushButton_TrackLine_Tooltip_clicked(); break;
        case 13: _t->on_pushButton_TrackLine_Yax_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Sensor_SEN0105::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Sensor_SEN0105.data,
    qt_meta_data_Sensor_SEN0105,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Sensor_SEN0105::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sensor_SEN0105::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Sensor_SEN0105.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Sensor_SEN0105::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

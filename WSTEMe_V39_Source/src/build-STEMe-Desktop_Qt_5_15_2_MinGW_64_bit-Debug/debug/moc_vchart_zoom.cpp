/****************************************************************************
** Meta object code from reading C++ file 'vchart_zoom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../STEMe/vchart/vchart_zoom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vchart_zoom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Vchart_Zoom_t {
    QByteArrayData data[17];
    char stringdata0[440];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Vchart_Zoom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Vchart_Zoom_t qt_meta_stringdata_Vchart_Zoom = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Vchart_Zoom"
QT_MOC_LITERAL(1, 12, 17), // "setChartParameter"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "sampleTime"
QT_MOC_LITERAL(4, 42, 13), // "on_chartTimer"
QT_MOC_LITERAL(5, 56, 28), // "on_pushButton_Cancel_clicked"
QT_MOC_LITERAL(6, 85, 30), // "on_pushButton_SaveData_clicked"
QT_MOC_LITERAL(7, 116, 30), // "on_pushButton_OpenData_clicked"
QT_MOC_LITERAL(8, 147, 26), // "on_pushButton_Stop_clicked"
QT_MOC_LITERAL(9, 174, 35), // "on_pushButton_SetSampleTime_c..."
QT_MOC_LITERAL(10, 210, 36), // "on_pushButton_SetConfigChart_..."
QT_MOC_LITERAL(11, 247, 32), // "on_pushButton_ClearChart_clicked"
QT_MOC_LITERAL(12, 280, 35), // "on_radioButton_Accumulation_t..."
QT_MOC_LITERAL(13, 316, 7), // "checked"
QT_MOC_LITERAL(14, 324, 39), // "on_pushButton_TrackLine_Defau..."
QT_MOC_LITERAL(15, 364, 39), // "on_pushButton_TrackLine_Toolt..."
QT_MOC_LITERAL(16, 404, 35) // "on_pushButton_TrackLine_Yax_c..."

    },
    "Vchart_Zoom\0setChartParameter\0\0"
    "sampleTime\0on_chartTimer\0"
    "on_pushButton_Cancel_clicked\0"
    "on_pushButton_SaveData_clicked\0"
    "on_pushButton_OpenData_clicked\0"
    "on_pushButton_Stop_clicked\0"
    "on_pushButton_SetSampleTime_clicked\0"
    "on_pushButton_SetConfigChart_clicked\0"
    "on_pushButton_ClearChart_clicked\0"
    "on_radioButton_Accumulation_toggled\0"
    "checked\0on_pushButton_TrackLine_Default_clicked\0"
    "on_pushButton_TrackLine_Tooltip_clicked\0"
    "on_pushButton_TrackLine_Yax_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Vchart_Zoom[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   82,    2, 0x08 /* Private */,
       5,    0,   83,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    1,   90,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,
      15,    0,   94,    2, 0x08 /* Private */,
      16,    0,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Vchart_Zoom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Vchart_Zoom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setChartParameter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_chartTimer(); break;
        case 2: _t->on_pushButton_Cancel_clicked(); break;
        case 3: _t->on_pushButton_SaveData_clicked(); break;
        case 4: _t->on_pushButton_OpenData_clicked(); break;
        case 5: _t->on_pushButton_Stop_clicked(); break;
        case 6: _t->on_pushButton_SetSampleTime_clicked(); break;
        case 7: _t->on_pushButton_SetConfigChart_clicked(); break;
        case 8: _t->on_pushButton_ClearChart_clicked(); break;
        case 9: _t->on_radioButton_Accumulation_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_TrackLine_Default_clicked(); break;
        case 11: _t->on_pushButton_TrackLine_Tooltip_clicked(); break;
        case 12: _t->on_pushButton_TrackLine_Yax_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Vchart_Zoom::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Vchart_Zoom::setChartParameter)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Vchart_Zoom::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Vchart_Zoom.data,
    qt_meta_data_Vchart_Zoom,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Vchart_Zoom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Vchart_Zoom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Vchart_Zoom.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Vchart_Zoom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Vchart_Zoom::setChartParameter(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

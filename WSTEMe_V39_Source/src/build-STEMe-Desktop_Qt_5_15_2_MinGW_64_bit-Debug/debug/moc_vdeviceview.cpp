/****************************************************************************
** Meta object code from reading C++ file 'vdeviceview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../STEMe/vdevice/vdeviceview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vdeviceview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VDeviceView_t {
    QByteArrayData data[10];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VDeviceView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VDeviceView_t qt_meta_stringdata_VDeviceView = {
    {
QT_MOC_LITERAL(0, 0, 11), // "VDeviceView"
QT_MOC_LITERAL(1, 12, 27), // "on_tableView_Device_pressed"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 53, 5), // "index"
QT_MOC_LITERAL(5, 59, 34), // "on_pushButton_SelectDevice_cl..."
QT_MOC_LITERAL(6, 94, 34), // "on_pushButton_RemoveDevice_cl..."
QT_MOC_LITERAL(7, 129, 28), // "on_pushButton_Cancel_clicked"
QT_MOC_LITERAL(8, 158, 27), // "on_tableView_Select_pressed"
QT_MOC_LITERAL(9, 186, 27) // "on_pushButton_Apply_clicked"

    },
    "VDeviceView\0on_tableView_Device_pressed\0"
    "\0QModelIndex\0index\0"
    "on_pushButton_SelectDevice_clicked\0"
    "on_pushButton_RemoveDevice_clicked\0"
    "on_pushButton_Cancel_clicked\0"
    "on_tableView_Select_pressed\0"
    "on_pushButton_Apply_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VDeviceView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    1,   50,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void VDeviceView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VDeviceView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tableView_Device_pressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_SelectDevice_clicked(); break;
        case 2: _t->on_pushButton_RemoveDevice_clicked(); break;
        case 3: _t->on_pushButton_Cancel_clicked(); break;
        case 4: _t->on_tableView_Select_pressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_Apply_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VDeviceView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_VDeviceView.data,
    qt_meta_data_VDeviceView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VDeviceView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VDeviceView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VDeviceView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VDeviceView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

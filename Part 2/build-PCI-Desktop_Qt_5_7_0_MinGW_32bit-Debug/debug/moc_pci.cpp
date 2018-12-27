/****************************************************************************
** Meta object code from reading C++ file 'pci.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PCI/pci.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pci.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PCI_t {
    QByteArrayData data[9];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PCI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PCI_t qt_meta_stringdata_PCI = {
    {
QT_MOC_LITERAL(0, 0, 3), // "PCI"
QT_MOC_LITERAL(1, 4, 14), // "on_arb_clicked"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 15), // "on_devA_clicked"
QT_MOC_LITERAL(4, 36, 15), // "on_devB_clicked"
QT_MOC_LITERAL(5, 52, 15), // "on_devC_clicked"
QT_MOC_LITERAL(6, 68, 13), // "on_R1_clicked"
QT_MOC_LITERAL(7, 82, 13), // "on_R2_clicked"
QT_MOC_LITERAL(8, 96, 16) // "on_arb_2_clicked"

    },
    "PCI\0on_arb_clicked\0\0on_devA_clicked\0"
    "on_devB_clicked\0on_devC_clicked\0"
    "on_R1_clicked\0on_R2_clicked\0"
    "on_arb_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PCI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PCI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PCI *_t = static_cast<PCI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_arb_clicked(); break;
        case 1: _t->on_devA_clicked(); break;
        case 2: _t->on_devB_clicked(); break;
        case 3: _t->on_devC_clicked(); break;
        case 4: _t->on_R1_clicked(); break;
        case 5: _t->on_R2_clicked(); break;
        case 6: _t->on_arb_2_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PCI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PCI.data,
      qt_meta_data_PCI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PCI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PCI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PCI.stringdata0))
        return static_cast<void*>(const_cast< PCI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PCI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

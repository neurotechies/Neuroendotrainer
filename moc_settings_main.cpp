/****************************************************************************
** Meta object code from reading C++ file 'settings_main.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "settings_main.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings_main.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_settings_main_t {
    QByteArrayData data[20];
    char stringdata0[391];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_settings_main_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_settings_main_t qt_meta_stringdata_settings_main = {
    {
QT_MOC_LITERAL(0, 0, 13), // "settings_main"
QT_MOC_LITERAL(1, 14, 26), // "on_tabWidget_tabBarClicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 5), // "index"
QT_MOC_LITERAL(4, 48, 21), // "on_pbPractice_clicked"
QT_MOC_LITERAL(5, 70, 19), // "on_pbOnline_clicked"
QT_MOC_LITERAL(6, 90, 20), // "on_pbOffline_clicked"
QT_MOC_LITERAL(7, 111, 31), // "on_listWidgetEndoOnline_clicked"
QT_MOC_LITERAL(8, 143, 30), // "on_listWidgetAuxOnline_clicked"
QT_MOC_LITERAL(9, 174, 12), // "updatelblAux"
QT_MOC_LITERAL(10, 187, 13), // "updatelblEndo"
QT_MOC_LITERAL(11, 201, 17), // "on_pbQuit_clicked"
QT_MOC_LITERAL(12, 219, 31), // "on_listWidgetAuxOffline_clicked"
QT_MOC_LITERAL(13, 251, 32), // "on_listWidgetEndoOffline_clicked"
QT_MOC_LITERAL(14, 284, 29), // "on_listWidgetPractice_clicked"
QT_MOC_LITERAL(15, 314, 20), // "on_pbRefresh_clicked"
QT_MOC_LITERAL(16, 335, 18), // "openSettingsDialog"
QT_MOC_LITERAL(17, 354, 16), // "updateParameters"
QT_MOC_LITERAL(18, 371, 6), // "params"
QT_MOC_LITERAL(19, 378, 12) // "initialSetup"

    },
    "settings_main\0on_tabWidget_tabBarClicked\0"
    "\0index\0on_pbPractice_clicked\0"
    "on_pbOnline_clicked\0on_pbOffline_clicked\0"
    "on_listWidgetEndoOnline_clicked\0"
    "on_listWidgetAuxOnline_clicked\0"
    "updatelblAux\0updatelblEndo\0on_pbQuit_clicked\0"
    "on_listWidgetAuxOffline_clicked\0"
    "on_listWidgetEndoOffline_clicked\0"
    "on_listWidgetPractice_clicked\0"
    "on_pbRefresh_clicked\0openSettingsDialog\0"
    "updateParameters\0params\0initialSetup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_settings_main[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x08 /* Private */,
       4,    0,   97,    2, 0x08 /* Private */,
       5,    0,   98,    2, 0x08 /* Private */,
       6,    0,   99,    2, 0x08 /* Private */,
       7,    1,  100,    2, 0x08 /* Private */,
       8,    1,  103,    2, 0x08 /* Private */,
       9,    1,  106,    2, 0x08 /* Private */,
      10,    1,  109,    2, 0x08 /* Private */,
      11,    0,  112,    2, 0x08 /* Private */,
      12,    1,  113,    2, 0x08 /* Private */,
      13,    1,  116,    2, 0x08 /* Private */,
      14,    1,  119,    2, 0x08 /* Private */,
      15,    0,  122,    2, 0x08 /* Private */,
      16,    0,  123,    2, 0x08 /* Private */,
      17,    1,  124,    2, 0x08 /* Private */,
      19,    0,  127,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   18,
    QMetaType::Bool,

       0        // eod
};

void settings_main::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        settings_main *_t = static_cast<settings_main *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tabWidget_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pbPractice_clicked(); break;
        case 2: _t->on_pbOnline_clicked(); break;
        case 3: _t->on_pbOffline_clicked(); break;
        case 4: _t->on_listWidgetEndoOnline_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_listWidgetAuxOnline_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->updatelblAux((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 7: _t->updatelblEndo((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 8: _t->on_pbQuit_clicked(); break;
        case 9: _t->on_listWidgetAuxOffline_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_listWidgetEndoOffline_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->on_listWidgetPractice_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 12: _t->on_pbRefresh_clicked(); break;
        case 13: _t->openSettingsDialog(); break;
        case 14: _t->updateParameters((*reinterpret_cast< const params(*)>(_a[1]))); break;
        case 15: { bool _r = _t->initialSetup();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject settings_main::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_settings_main.data,
      qt_meta_data_settings_main,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *settings_main::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *settings_main::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_settings_main.stringdata0))
        return static_cast<void*>(const_cast< settings_main*>(this));
    return QDialog::qt_metacast(_clname);
}

int settings_main::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

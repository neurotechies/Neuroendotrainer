/****************************************************************************
** Meta object code from reading C++ file 'testUSB.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "testUSB.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testUSB.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_testUSB_t {
    QByteArrayData data[5];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_testUSB_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_testUSB_t qt_meta_stringdata_testUSB = {
    {
QT_MOC_LITERAL(0, 0, 7), // "testUSB"
QT_MOC_LITERAL(1, 8, 8), // "sendtoUI"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "finished"
QT_MOC_LITERAL(4, 27, 7) // "process"

    },
    "testUSB\0sendtoUI\0\0finished\0process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_testUSB[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    0,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void testUSB::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        testUSB *_t = static_cast<testUSB *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendtoUI((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->finished(); break;
        case 2: _t->process(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (testUSB::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&testUSB::sendtoUI)) {
                *result = 0;
            }
        }
        {
            typedef void (testUSB::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&testUSB::finished)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject testUSB::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_testUSB.data,
      qt_meta_data_testUSB,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *testUSB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *testUSB::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_testUSB.stringdata0))
        return static_cast<void*>(const_cast< testUSB*>(this));
    return QObject::qt_metacast(_clname);
}

int testUSB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void testUSB::sendtoUI(const QImage & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void testUSB::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

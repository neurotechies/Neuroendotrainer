/****************************************************************************
** Meta object code from reading C++ file 'auxCamRecord.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "auxCamRecord.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'auxCamRecord.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_auxCamRecord_producer_t {
    QByteArrayData data[4];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_auxCamRecord_producer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_auxCamRecord_producer_t qt_meta_stringdata_auxCamRecord_producer = {
    {
QT_MOC_LITERAL(0, 0, 21), // "auxCamRecord_producer"
QT_MOC_LITERAL(1, 22, 8), // "finished"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7) // "process"

    },
    "auxCamRecord_producer\0finished\0\0process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_auxCamRecord_producer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void auxCamRecord_producer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auxCamRecord_producer *_t = static_cast<auxCamRecord_producer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->process(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (auxCamRecord_producer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&auxCamRecord_producer::finished)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject auxCamRecord_producer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_auxCamRecord_producer.data,
      qt_meta_data_auxCamRecord_producer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *auxCamRecord_producer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *auxCamRecord_producer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_auxCamRecord_producer.stringdata0))
        return static_cast<void*>(const_cast< auxCamRecord_producer*>(this));
    return QObject::qt_metacast(_clname);
}

int auxCamRecord_producer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void auxCamRecord_producer::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_auxCamRecord_consumer_t {
    QByteArrayData data[4];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_auxCamRecord_consumer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_auxCamRecord_consumer_t qt_meta_stringdata_auxCamRecord_consumer = {
    {
QT_MOC_LITERAL(0, 0, 21), // "auxCamRecord_consumer"
QT_MOC_LITERAL(1, 22, 8), // "finished"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7) // "process"

    },
    "auxCamRecord_consumer\0finished\0\0process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_auxCamRecord_consumer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void auxCamRecord_consumer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auxCamRecord_consumer *_t = static_cast<auxCamRecord_consumer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->process(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (auxCamRecord_consumer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&auxCamRecord_consumer::finished)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject auxCamRecord_consumer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_auxCamRecord_consumer.data,
      qt_meta_data_auxCamRecord_consumer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *auxCamRecord_consumer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *auxCamRecord_consumer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_auxCamRecord_consumer.stringdata0))
        return static_cast<void*>(const_cast< auxCamRecord_consumer*>(this));
    return QObject::qt_metacast(_clname);
}

int auxCamRecord_consumer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void auxCamRecord_consumer::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'cam_idsProdCons.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cam_idsProdCons.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cam_idsProdCons.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cam_ids_producer_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cam_ids_producer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cam_ids_producer_t qt_meta_stringdata_cam_ids_producer = {
    {
QT_MOC_LITERAL(0, 0, 16), // "cam_ids_producer"
QT_MOC_LITERAL(1, 17, 8), // "finished"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7) // "process"

    },
    "cam_ids_producer\0finished\0\0process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cam_ids_producer[] = {

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

void cam_ids_producer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cam_ids_producer *_t = static_cast<cam_ids_producer *>(_o);
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
            typedef void (cam_ids_producer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cam_ids_producer::finished)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject cam_ids_producer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cam_ids_producer.data,
      qt_meta_data_cam_ids_producer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cam_ids_producer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cam_ids_producer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cam_ids_producer.stringdata0))
        return static_cast<void*>(const_cast< cam_ids_producer*>(this));
    return QObject::qt_metacast(_clname);
}

int cam_ids_producer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void cam_ids_producer::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_cam_ids_consumer_t {
    QByteArrayData data[5];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cam_ids_consumer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cam_ids_consumer_t qt_meta_stringdata_cam_ids_consumer = {
    {
QT_MOC_LITERAL(0, 0, 16), // "cam_ids_consumer"
QT_MOC_LITERAL(1, 17, 12), // "sendtoUI_aux"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "finished"
QT_MOC_LITERAL(4, 40, 7) // "process"

    },
    "cam_ids_consumer\0sendtoUI_aux\0\0finished\0"
    "process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cam_ids_consumer[] = {

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

void cam_ids_consumer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cam_ids_consumer *_t = static_cast<cam_ids_consumer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendtoUI_aux((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->finished(); break;
        case 2: _t->process(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (cam_ids_consumer::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cam_ids_consumer::sendtoUI_aux)) {
                *result = 0;
            }
        }
        {
            typedef void (cam_ids_consumer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cam_ids_consumer::finished)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject cam_ids_consumer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cam_ids_consumer.data,
      qt_meta_data_cam_ids_consumer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cam_ids_consumer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cam_ids_consumer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cam_ids_consumer.stringdata0))
        return static_cast<void*>(const_cast< cam_ids_consumer*>(this));
    return QObject::qt_metacast(_clname);
}

int cam_ids_consumer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void cam_ids_consumer::sendtoUI_aux(const QImage & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cam_ids_consumer::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

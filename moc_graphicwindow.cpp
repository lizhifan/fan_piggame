/****************************************************************************
** Meta object code from reading C++ file 'graphicwindow.h'
**
** Created: Tue May 7 20:42:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "graphicwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GraphicWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      32,   14,   14,   14, 0x0a,
      48,   14,   14,   14, 0x0a,
      65,   14,   14,   14, 0x0a,
      77,   14,   14,   14, 0x0a,
      89,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GraphicWindow[] = {
    "GraphicWindow\0\0randomgenerate()\0"
    "handlecollide()\0handlebuilding()\0"
    "pausegame()\0scorekeep()\0speedup()\0"
};

void GraphicWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GraphicWindow *_t = static_cast<GraphicWindow *>(_o);
        switch (_id) {
        case 0: _t->randomgenerate(); break;
        case 1: _t->handlecollide(); break;
        case 2: _t->handlebuilding(); break;
        case 3: _t->pausegame(); break;
        case 4: _t->scorekeep(); break;
        case 5: _t->speedup(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData GraphicWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GraphicWindow::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_GraphicWindow,
      qt_meta_data_GraphicWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GraphicWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GraphicWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GraphicWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicWindow))
        return static_cast<void*>(const_cast< GraphicWindow*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int GraphicWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

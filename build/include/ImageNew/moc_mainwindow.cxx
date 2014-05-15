/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.hpp'
**
** Created: Thu May 15 19:43:28 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/ImageNew/mainwindow.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyLabel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,    9,    8,    8, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_MyLabel[] = {
    "MyLabel\0\0ev\0on_mouseDoubleClickEvent(QMouseEvent*)\0"
};

void MyLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyLabel *_t = static_cast<MyLabel *>(_o);
        switch (_id) {
        case 0: _t->on_mouseDoubleClickEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyLabel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_MyLabel,
      qt_meta_data_MyLabel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyLabel))
        return static_cast<void*>(const_cast< MyLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int MyLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MyLabel::on_mouseDoubleClickEvent(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_MyWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      32,    9,    9,    9, 0x0a,
      55,    9,    9,    9, 0x0a,
      78,    9,    9,    9, 0x0a,
     102,    9,    9,    9, 0x0a,
     127,    9,    9,    9, 0x0a,
     152,    9,    9,    9, 0x0a,
     183,  177,    9,    9, 0x0a,
     218,  177,    9,    9, 0x0a,
     253,  177,    9,    9, 0x0a,
     288,  177,    9,    9, 0x0a,
     329,  177,    9,    9, 0x0a,
     370,  177,    9,    9, 0x0a,
     411,  177,    9,    9, 0x0a,
     452,  449,    9,    9, 0x0a,
     502,  177,    9,    9, 0x0a,
     534,  177,    9,    9, 0x0a,
     567,  177,    9,    9, 0x0a,
     600,    9,    9,    9, 0x0a,
     625,    9,    9,    9, 0x0a,
     649,    9,    9,    9, 0x0a,
     675,    9,    9,    9, 0x0a,
     698,    9,    9,    9, 0x0a,
     722,  177,    9,    9, 0x0a,
     760,    9,    9,    9, 0x0a,
     787,    9,    9,    9, 0x0a,
     815,    9,    9,    9, 0x0a,
     845,    9,    9,    9, 0x0a,
     874,    9,    9,    9, 0x0a,
     898,  177,    9,    9, 0x0a,
     934,  177,    9,    9, 0x0a,
     970,    9,    9,    9, 0x0a,
     999,    9,    9,    9, 0x0a,
    1022,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyWindow[] = {
    "MyWindow\0\0on_openFile_clicked()\0"
    "on_closeFile_clicked()\0on_writeFile_clicked()\0"
    "on_openCamera_clicked()\0"
    "on_startCamera_clicked()\0"
    "on_pauseCamera_clicked()\0"
    "on_closeCamera_clicked()\0value\0"
    "on_HValue_slider_valueChanged(int)\0"
    "on_SValue_slider_valueChanged(int)\0"
    "on_VValue_slider_valueChanged(int)\0"
    "on_HThreshValue_slider_valueChanged(int)\0"
    "on_SThreshValue_slider_valueChanged(int)\0"
    "on_VThreshValue_slider_valueChanged(int)\0"
    "on_BlobValue_slider_valueChanged(int)\0"
    "ev\0on_colorImage_mouseDoubleClickEvent(QMouseEvent*)\0"
    "on_blurSlider_valueChanged(int)\0"
    "on_mblurSlider_valueChanged(int)\0"
    "on_gblurSlider_valueChanged(int)\0"
    "on_dilateCheck_clicked()\0"
    "on_erodeCheck_clicked()\0"
    "on_morphellipse_clicked()\0"
    "on_morphrect_clicked()\0on_morphcross_clicked()\0"
    "on_kernelSizeSlider_valueChanged(int)\0"
    "on_contoursCheck_clicked()\0"
    "on_boundrectCheck_clicked()\0"
    "on_boundcircleCheck_clicked()\0"
    "on_approxpolyCheck_clicked()\0"
    "on_houghCheck_clicked()\0"
    "on_houghMinRadius_valueChanged(int)\0"
    "on_houghMaxRadius_valueChanged(int)\0"
    "on_houghLinesCheck_clicked()\0"
    "on_blobCheck_clicked()\0on_updateImages()\0"
};

void MyWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyWindow *_t = static_cast<MyWindow *>(_o);
        switch (_id) {
        case 0: _t->on_openFile_clicked(); break;
        case 1: _t->on_closeFile_clicked(); break;
        case 2: _t->on_writeFile_clicked(); break;
        case 3: _t->on_openCamera_clicked(); break;
        case 4: _t->on_startCamera_clicked(); break;
        case 5: _t->on_pauseCamera_clicked(); break;
        case 6: _t->on_closeCamera_clicked(); break;
        case 7: _t->on_HValue_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_SValue_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_VValue_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_HThreshValue_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_SThreshValue_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_VThreshValue_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_BlobValue_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_colorImage_mouseDoubleClickEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 15: _t->on_blurSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_mblurSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_gblurSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_dilateCheck_clicked(); break;
        case 19: _t->on_erodeCheck_clicked(); break;
        case 20: _t->on_morphellipse_clicked(); break;
        case 21: _t->on_morphrect_clicked(); break;
        case 22: _t->on_morphcross_clicked(); break;
        case 23: _t->on_kernelSizeSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_contoursCheck_clicked(); break;
        case 25: _t->on_boundrectCheck_clicked(); break;
        case 26: _t->on_boundcircleCheck_clicked(); break;
        case 27: _t->on_approxpolyCheck_clicked(); break;
        case 28: _t->on_houghCheck_clicked(); break;
        case 29: _t->on_houghMinRadius_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->on_houghMaxRadius_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->on_houghLinesCheck_clicked(); break;
        case 32: _t->on_blobCheck_clicked(); break;
        case 33: _t->on_updateImages(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MyWindow,
      qt_meta_data_MyWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyWindow))
        return static_cast<void*>(const_cast< MyWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MyWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

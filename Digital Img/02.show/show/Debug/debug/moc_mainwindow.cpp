/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "openButton_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "saveButton_clicked"
QT_MOC_LITERAL(4, 50, 18), // "greyButton_clicked"
QT_MOC_LITERAL(5, 69, 11), // "preimg_show"
QT_MOC_LITERAL(6, 81, 14), // "samplingChange"
QT_MOC_LITERAL(7, 96, 18), // "quantizationChange"
QT_MOC_LITERAL(8, 115, 14), // "bitPlaneChange"
QT_MOC_LITERAL(9, 130, 15), // "thresholdChange"
QT_MOC_LITERAL(10, 146, 13), // "diagramChange"
QT_MOC_LITERAL(11, 160, 5), // "image"
QT_MOC_LITERAL(12, 166, 8), // "lineFunc"
QT_MOC_LITERAL(13, 175, 10), // "unlineFunc"
QT_MOC_LITERAL(14, 186, 13), // "tradEqualPush"
QT_MOC_LITERAL(15, 200, 15), // "betterEqualPush"
QT_MOC_LITERAL(16, 216, 7), // "bmp2txt"
QT_MOC_LITERAL(17, 224, 10), // "saveChange"
QT_MOC_LITERAL(18, 235, 4), // "zoom"
QT_MOC_LITERAL(19, 240, 4), // "roll"
QT_MOC_LITERAL(20, 245, 9), // "translate"
QT_MOC_LITERAL(21, 255, 9), // "showMagic"
QT_MOC_LITERAL(22, 265, 9) // "magicBack"

    },
    "MainWindow\0openButton_clicked\0\0"
    "saveButton_clicked\0greyButton_clicked\0"
    "preimg_show\0samplingChange\0"
    "quantizationChange\0bitPlaneChange\0"
    "thresholdChange\0diagramChange\0image\0"
    "lineFunc\0unlineFunc\0tradEqualPush\0"
    "betterEqualPush\0bmp2txt\0saveChange\0"
    "zoom\0roll\0translate\0showMagic\0magicBack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x08 /* Private */,
       3,    0,  115,    2, 0x08 /* Private */,
       4,    0,  116,    2, 0x08 /* Private */,
       5,    0,  117,    2, 0x08 /* Private */,
       6,    0,  118,    2, 0x08 /* Private */,
       7,    0,  119,    2, 0x08 /* Private */,
       8,    0,  120,    2, 0x08 /* Private */,
       9,    0,  121,    2, 0x08 /* Private */,
      10,    1,  122,    2, 0x08 /* Private */,
      12,    0,  125,    2, 0x08 /* Private */,
      13,    0,  126,    2, 0x08 /* Private */,
      14,    0,  127,    2, 0x08 /* Private */,
      15,    0,  128,    2, 0x08 /* Private */,
      16,    0,  129,    2, 0x08 /* Private */,
      17,    0,  130,    2, 0x08 /* Private */,
      18,    0,  131,    2, 0x08 /* Private */,
      19,    0,  132,    2, 0x08 /* Private */,
      20,    0,  133,    2, 0x08 /* Private */,
      21,    0,  134,    2, 0x08 /* Private */,
      22,    0,  135,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openButton_clicked(); break;
        case 1: _t->saveButton_clicked(); break;
        case 2: _t->greyButton_clicked(); break;
        case 3: _t->preimg_show(); break;
        case 4: _t->samplingChange(); break;
        case 5: _t->quantizationChange(); break;
        case 6: _t->bitPlaneChange(); break;
        case 7: _t->thresholdChange(); break;
        case 8: _t->diagramChange((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 9: _t->lineFunc(); break;
        case 10: _t->unlineFunc(); break;
        case 11: _t->tradEqualPush(); break;
        case 12: _t->betterEqualPush(); break;
        case 13: _t->bmp2txt(); break;
        case 14: _t->saveChange(); break;
        case 15: _t->zoom(); break;
        case 16: _t->roll(); break;
        case 17: _t->translate(); break;
        case 18: _t->showMagic(); break;
        case 19: _t->magicBack(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

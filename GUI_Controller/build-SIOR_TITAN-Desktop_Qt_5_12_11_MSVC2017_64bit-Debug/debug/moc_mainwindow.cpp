/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SIOR_TITAN/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[419];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 5), // "About"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 4), // "Load"
QT_MOC_LITERAL(4, 23, 4), // "Save"
QT_MOC_LITERAL(5, 28, 30), // "on_serialConnectButton_clicked"
QT_MOC_LITERAL(6, 59, 23), // "on_recordButton_clicked"
QT_MOC_LITERAL(7, 83, 24), // "on_refreshButton_clicked"
QT_MOC_LITERAL(8, 108, 21), // "on_testButton_clicked"
QT_MOC_LITERAL(9, 130, 24), // "on_groupListView_clicked"
QT_MOC_LITERAL(10, 155, 11), // "QModelIndex"
QT_MOC_LITERAL(11, 167, 5), // "index"
QT_MOC_LITERAL(12, 173, 34), // "on_groupListView_objectNameCh..."
QT_MOC_LITERAL(13, 208, 10), // "objectName"
QT_MOC_LITERAL(14, 219, 25), // "on_addGroupButton_clicked"
QT_MOC_LITERAL(15, 245, 28), // "on_deleteGroupButton_clicked"
QT_MOC_LITERAL(16, 274, 27), // "on_addGestureButton_clicked"
QT_MOC_LITERAL(17, 302, 30), // "on_deleteGestureButton_clicked"
QT_MOC_LITERAL(18, 333, 30), // "on_singleExecuteButton_clicked"
QT_MOC_LITERAL(19, 364, 24), // "on_captureButton_clicked"
QT_MOC_LITERAL(20, 389, 29) // "on_batchExecuteButton_clicked"

    },
    "MainWindow\0About\0\0Load\0Save\0"
    "on_serialConnectButton_clicked\0"
    "on_recordButton_clicked\0"
    "on_refreshButton_clicked\0on_testButton_clicked\0"
    "on_groupListView_clicked\0QModelIndex\0"
    "index\0on_groupListView_objectNameChanged\0"
    "objectName\0on_addGroupButton_clicked\0"
    "on_deleteGroupButton_clicked\0"
    "on_addGestureButton_clicked\0"
    "on_deleteGestureButton_clicked\0"
    "on_singleExecuteButton_clicked\0"
    "on_captureButton_clicked\0"
    "on_batchExecuteButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    1,  101,    2, 0x08 /* Private */,
      12,    1,  104,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    0,  109,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    0,  111,    2, 0x08 /* Private */,
      19,    0,  112,    2, 0x08 /* Private */,
      20,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString,   13,
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
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->About(); break;
        case 1: _t->Load(); break;
        case 2: _t->Save(); break;
        case 3: _t->on_serialConnectButton_clicked(); break;
        case 4: _t->on_recordButton_clicked(); break;
        case 5: _t->on_refreshButton_clicked(); break;
        case 6: _t->on_testButton_clicked(); break;
        case 7: _t->on_groupListView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_groupListView_objectNameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_addGroupButton_clicked(); break;
        case 10: _t->on_deleteGroupButton_clicked(); break;
        case 11: _t->on_addGestureButton_clicked(); break;
        case 12: _t->on_deleteGestureButton_clicked(); break;
        case 13: _t->on_singleExecuteButton_clicked(); break;
        case 14: _t->on_captureButton_clicked(); break;
        case 15: _t->on_batchExecuteButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

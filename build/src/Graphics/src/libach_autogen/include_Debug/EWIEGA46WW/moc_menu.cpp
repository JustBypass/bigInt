/****************************************************************************
** Meta object code from reading C++ file 'menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/Graphics/src/menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_menu_t {
    QByteArrayData data[13];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_menu_t qt_meta_stringdata_menu = {
    {
QT_MOC_LITERAL(0, 0, 4), // "menu"
QT_MOC_LITERAL(1, 5, 5), // "addSq"
QT_MOC_LITERAL(2, 11, 0), // ""
QT_MOC_LITERAL(3, 12, 4), // "plus"
QT_MOC_LITERAL(4, 17, 5), // "minus"
QT_MOC_LITERAL(5, 23, 6), // "delten"
QT_MOC_LITERAL(6, 30, 6), // "multen"
QT_MOC_LITERAL(7, 37, 3), // "qui"
QT_MOC_LITERAL(8, 41, 4), // "link"
QT_MOC_LITERAL(9, 46, 9), // "changeBut"
QT_MOC_LITERAL(10, 56, 7), // "checked"
QT_MOC_LITERAL(11, 64, 11), // "pressedFunc"
QT_MOC_LITERAL(12, 76, 7) // "openNew"

    },
    "menu\0addSq\0\0plus\0minus\0delten\0multen\0"
    "qui\0link\0changeBut\0checked\0pressedFunc\0"
    "openNew"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_menu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    1,   71,    2, 0x0a /* Public */,
      11,    0,   74,    2, 0x0a /* Public */,
      12,    0,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addSq(); break;
        case 1: _t->plus(); break;
        case 2: _t->minus(); break;
        case 3: _t->delten(); break;
        case 4: _t->multen(); break;
        case 5: _t->qui(); break;
        case 6: _t->link(); break;
        case 7: _t->changeBut((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->pressedFunc(); break;
        case 9: _t->openNew(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject menu::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_menu.data,
    qt_meta_data_menu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_menu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

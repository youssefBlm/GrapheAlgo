/****************************************************************************
** Meta object code from reading C++ file 'MainWin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MainWin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mainwin_t {
    QByteArrayData data[17];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mainwin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mainwin_t qt_meta_stringdata_Mainwin = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Mainwin"
QT_MOC_LITERAL(1, 8, 13), // "chargerGraphe"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 17), // "sauvegarderGraphe"
QT_MOC_LITERAL(4, 41, 13), // "nouveauGraphe"
QT_MOC_LITERAL(5, 55, 11), // "setAjoutSom"
QT_MOC_LITERAL(6, 67, 11), // "setSupprSom"
QT_MOC_LITERAL(7, 79, 11), // "setAjoutArc"
QT_MOC_LITERAL(8, 91, 11), // "setSupprArc"
QT_MOC_LITERAL(9, 103, 17), // "setEnregistrement"
QT_MOC_LITERAL(10, 121, 4), // "rang"
QT_MOC_LITERAL(11, 126, 9), // "distances"
QT_MOC_LITERAL(12, 136, 16), // "dessinerDijkstra"
QT_MOC_LITERAL(13, 153, 16), // "redessinerGraphe"
QT_MOC_LITERAL(14, 170, 11), // "coderPrufer"
QT_MOC_LITERAL(15, 182, 15), // "dessinerKruskal"
QT_MOC_LITERAL(16, 198, 15) // "afficherDantzig"

    },
    "Mainwin\0chargerGraphe\0\0sauvegarderGraphe\0"
    "nouveauGraphe\0setAjoutSom\0setSupprSom\0"
    "setAjoutArc\0setSupprArc\0setEnregistrement\0"
    "rang\0distances\0dessinerDijkstra\0"
    "redessinerGraphe\0coderPrufer\0"
    "dessinerKruskal\0afficherDantzig"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mainwin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    0,   94,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    0,   97,    2, 0x0a /* Public */,
      11,    0,   98,    2, 0x0a /* Public */,
      12,    0,   99,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    0,  101,    2, 0x0a /* Public */,
      15,    0,  102,    2, 0x0a /* Public */,
      16,    0,  103,    2, 0x0a /* Public */,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Mainwin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mainwin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->chargerGraphe(); break;
        case 1: _t->sauvegarderGraphe(); break;
        case 2: _t->nouveauGraphe(); break;
        case 3: _t->setAjoutSom(); break;
        case 4: _t->setSupprSom(); break;
        case 5: _t->setAjoutArc(); break;
        case 6: _t->setSupprArc(); break;
        case 7: _t->setEnregistrement(); break;
        case 8: _t->rang(); break;
        case 9: _t->distances(); break;
        case 10: _t->dessinerDijkstra(); break;
        case 11: _t->redessinerGraphe(); break;
        case 12: _t->coderPrufer(); break;
        case 13: _t->dessinerKruskal(); break;
        case 14: _t->afficherDantzig(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Mainwin::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Mainwin.data,
    qt_meta_data_Mainwin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mainwin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mainwin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mainwin.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Mainwin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

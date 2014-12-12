/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GuessWho-GUI/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,
      58,   11,   11,   11, 0x08,
      78,   11,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     128,   11,   11,   11, 0x08,
     149,   11,   11,   11, 0x08,
     170,   11,   11,   11, 0x08,
     195,   11,   11,   11, 0x08,
     212,   11,   11,   11, 0x08,
     225,   11,   11,   11, 0x08,
     250,   11,   11,   11, 0x08,
     268,   11,   11,   11, 0x08,
     281,   11,   11,   11, 0x08,
     294,   11,   11,   11, 0x08,
     306,   11,   11,   11, 0x08,
     330,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0genderButtonClicked()\0"
    "eyeColorButtonClicked()\0hairButtonClicked()\0"
    "facialHairButtonClicked()\0"
    "headwearButtonClicked()\0aboutButtonClicked()\0"
    "startButtonClicked()\0howToPlayButtonClicked()\0"
    "backToMainMenu()\0createText()\0"
    "characterButtonClicked()\0guessWhoClicked()\0"
    "isAccepted()\0isRejected()\0isGuessed()\0"
    "characterGuessClicked()\0"
    "highScoresButtonClicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->genderButtonClicked(); break;
        case 1: _t->eyeColorButtonClicked(); break;
        case 2: _t->hairButtonClicked(); break;
        case 3: _t->facialHairButtonClicked(); break;
        case 4: _t->headwearButtonClicked(); break;
        case 5: _t->aboutButtonClicked(); break;
        case 6: _t->startButtonClicked(); break;
        case 7: _t->howToPlayButtonClicked(); break;
        case 8: _t->backToMainMenu(); break;
        case 9: _t->createText(); break;
        case 10: _t->characterButtonClicked(); break;
        case 11: _t->guessWhoClicked(); break;
        case 12: _t->isAccepted(); break;
        case 13: _t->isRejected(); break;
        case 14: _t->isGuessed(); break;
        case 15: _t->characterGuessClicked(); break;
        case 16: _t->highScoresButtonClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'gamewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Game_double20180912/gamewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_gameWindow_t {
    QByteArrayData data[18];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gameWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gameWindow_t qt_meta_stringdata_gameWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "gameWindow"
QT_MOC_LITERAL(1, 11, 8), // "sendDice"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 16), // "sendEventMessage"
QT_MOC_LITERAL(4, 38, 12), // "sendRoundEnd"
QT_MOC_LITERAL(5, 51, 14), // "sendWinMessage"
QT_MOC_LITERAL(6, 66, 15), // "sendLoseMessage"
QT_MOC_LITERAL(7, 82, 14), // "sendReturnRoom"
QT_MOC_LITERAL(8, 97, 16), // "sendHouseMessage"
QT_MOC_LITERAL(9, 114, 9), // "setMyName"
QT_MOC_LITERAL(10, 124, 10), // "roundBegin"
QT_MOC_LITERAL(11, 135, 4), // "Dice"
QT_MOC_LITERAL(12, 140, 16), // "gameBeginMessage"
QT_MOC_LITERAL(13, 157, 12), // "eventMessage"
QT_MOC_LITERAL(14, 170, 10), // "winMessage"
QT_MOC_LITERAL(15, 181, 11), // "loseMessage"
QT_MOC_LITERAL(16, 193, 12), // "houseMessage"
QT_MOC_LITERAL(17, 206, 9) // "throwDice"

    },
    "gameWindow\0sendDice\0\0sendEventMessage\0"
    "sendRoundEnd\0sendWinMessage\0sendLoseMessage\0"
    "sendReturnRoom\0sendHouseMessage\0"
    "setMyName\0roundBegin\0Dice\0gameBeginMessage\0"
    "eventMessage\0winMessage\0loseMessage\0"
    "houseMessage\0throwDice"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gameWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       3,    1,   97,    2, 0x06 /* Public */,
       4,    0,  100,    2, 0x06 /* Public */,
       5,    1,  101,    2, 0x06 /* Public */,
       6,    1,  104,    2, 0x06 /* Public */,
       7,    0,  107,    2, 0x06 /* Public */,
       8,    1,  108,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  111,    2, 0x0a /* Public */,
      10,    1,  114,    2, 0x0a /* Public */,
      11,    1,  117,    2, 0x0a /* Public */,
      12,    1,  120,    2, 0x0a /* Public */,
      13,    1,  123,    2, 0x0a /* Public */,
      14,    1,  126,    2, 0x0a /* Public */,
      15,    1,  129,    2, 0x0a /* Public */,
      16,    1,  132,    2, 0x0a /* Public */,
      17,    0,  135,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,

       0        // eod
};

void gameWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gameWindow *_t = static_cast<gameWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendEventMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendRoundEnd(); break;
        case 3: _t->sendWinMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sendLoseMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->sendReturnRoom(); break;
        case 6: _t->sendHouseMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setMyName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->roundBegin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->Dice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->gameBeginMessage((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 11: _t->eventMessage((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 12: _t->winMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->loseMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->houseMessage((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 15: _t->throwDice(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (gameWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameWindow::sendDice)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (gameWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameWindow::sendEventMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (gameWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameWindow::sendRoundEnd)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (gameWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameWindow::sendWinMessage)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (gameWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameWindow::sendLoseMessage)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (gameWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameWindow::sendReturnRoom)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (gameWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameWindow::sendHouseMessage)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject gameWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_gameWindow.data,
      qt_meta_data_gameWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *gameWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gameWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gameWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int gameWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void gameWindow::sendDice(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void gameWindow::sendEventMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void gameWindow::sendRoundEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void gameWindow::sendWinMessage(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void gameWindow::sendLoseMessage(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void gameWindow::sendReturnRoom()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void gameWindow::sendHouseMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

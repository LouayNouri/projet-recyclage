/****************************************************************************
** Meta object code from reading C++ file 'TTP.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TTP.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TTP.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSTextToSpeechWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSTextToSpeechWindowENDCLASS = QtMocHelpers::stringData(
    "TextToSpeechWindow",
    "speak",
    "",
    "stop",
    "setRate",
    "setPitch",
    "setVolume",
    "volume",
    "stateChanged",
    "QTextToSpeech::State",
    "state",
    "engineSelected",
    "index",
    "languageSelected",
    "language",
    "voiceSelected",
    "localeChanged",
    "locale",
    "updatePlainText",
    "data"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTextToSpeechWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x0a,    1 /* Public */,
       3,    0,   81,    2, 0x0a,    2 /* Public */,
       4,    1,   82,    2, 0x0a,    3 /* Public */,
       5,    1,   85,    2, 0x0a,    5 /* Public */,
       6,    1,   88,    2, 0x0a,    7 /* Public */,
       8,    1,   91,    2, 0x0a,    9 /* Public */,
      11,    1,   94,    2, 0x0a,   11 /* Public */,
      13,    1,   97,    2, 0x0a,   13 /* Public */,
      15,    1,  100,    2, 0x0a,   15 /* Public */,
      16,    1,  103,    2, 0x0a,   17 /* Public */,
      18,    1,  106,    2, 0x0a,   19 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::QLocale,   17,
    QMetaType::Void, QMetaType::QString,   19,

       0        // eod
};

Q_CONSTINIT const QMetaObject TextToSpeechWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSTextToSpeechWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTextToSpeechWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTextToSpeechWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TextToSpeechWindow, std::true_type>,
        // method 'speak'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setRate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setPitch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setVolume'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTextToSpeech::State, std::false_type>,
        // method 'engineSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'languageSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'voiceSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'localeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QLocale &, std::false_type>,
        // method 'updatePlainText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void TextToSpeechWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TextToSpeechWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->speak(); break;
        case 1: _t->stop(); break;
        case 2: _t->setRate((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->setPitch((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->setVolume((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<QTextToSpeech::State>>(_a[1]))); break;
        case 6: _t->engineSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->languageSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->voiceSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->localeChanged((*reinterpret_cast< std::add_pointer_t<QLocale>>(_a[1]))); break;
        case 10: _t->updatePlainText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *TextToSpeechWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextToSpeechWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTextToSpeechWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TextToSpeechWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP

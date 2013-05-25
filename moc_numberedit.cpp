/****************************************************************************
** Meta object code from reading C++ file 'numberedit.h'
**
** Created: Sat May 25 16:58:26 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "numberedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'numberedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NumberEdit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   32,   32,   32, 0x08,
      33,   32,   32,   32, 0x08,
      51,   32,   32,   32, 0x08,
      69,   32,   32,   32, 0x08,
      87,   32,   32,   32, 0x08,
     105,   32,   32,   32, 0x08,
     123,   32,   32,   32, 0x08,
     141,   32,   32,   32, 0x08,
     159,   32,   32,   32, 0x08,
     177,   32,   32,   32, 0x08,
     195,   32,   32,   32, 0x08,
     213,   32,   32,   32, 0x08,
     232,   32,   32,   32, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NumberEdit[] = {
    "NumberEdit\0on_Pb_Back_clicked()\0\0"
    "on_Pb_0_clicked()\0on_Pb_1_clicked()\0"
    "on_Pb_2_clicked()\0on_Pb_3_clicked()\0"
    "on_Pb_4_clicked()\0on_Pb_5_clicked()\0"
    "on_Pb_6_clicked()\0on_Pb_7_clicked()\0"
    "on_Pb_8_clicked()\0on_Pb_9_clicked()\0"
    "on_Pb_Ok_clicked()\0on_Pb__clicked()\0"
};

void NumberEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NumberEdit *_t = static_cast<NumberEdit *>(_o);
        switch (_id) {
        case 0: _t->on_Pb_Back_clicked(); break;
        case 1: _t->on_Pb_0_clicked(); break;
        case 2: _t->on_Pb_1_clicked(); break;
        case 3: _t->on_Pb_2_clicked(); break;
        case 4: _t->on_Pb_3_clicked(); break;
        case 5: _t->on_Pb_4_clicked(); break;
        case 6: _t->on_Pb_5_clicked(); break;
        case 7: _t->on_Pb_6_clicked(); break;
        case 8: _t->on_Pb_7_clicked(); break;
        case 9: _t->on_Pb_8_clicked(); break;
        case 10: _t->on_Pb_9_clicked(); break;
        case 11: _t->on_Pb_Ok_clicked(); break;
        case 12: _t->on_Pb__clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData NumberEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NumberEdit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NumberEdit,
      qt_meta_data_NumberEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NumberEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NumberEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NumberEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NumberEdit))
        return static_cast<void*>(const_cast< NumberEdit*>(this));
    return QDialog::qt_metacast(_clname);
}

int NumberEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

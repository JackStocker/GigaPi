#ifndef EDITBOX_H
#define EDITBOX_H

#include <QLineEdit>
#include <QLabel>
#include "numberedit.h"

class EditBox : public QLineEdit
{
    Q_OBJECT
public:
    explicit EditBox( QLabel &location_label, QString initValue = "", QWidget *parent = 0 ) ;

    void mousePressEvent( QMouseEvent * ) ;

    int GetIntValue() ;
    double GetDoubleValue() ;
    QString GetStringValue() ;
    
signals:
    
public slots:
    
private:
    NumberEdit *numEdit ;

private slots:
    void ReadValue() ;

};

#endif // EDITBOX_H

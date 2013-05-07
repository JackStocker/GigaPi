#include "editbox.h"

EditBox::EditBox( QLabel &location_label, QString initValue, QWidget *parent) :
    QLineEdit(parent)
{
    numEdit = 0 ;

    this->setText( initValue ) ;
    resize( location_label.size() ) ;
    move( location_label.pos() ) ;
}

void EditBox::mousePressEvent( QMouseEvent * )
{
    numEdit = new NumberEdit( this->text(), this ) ;
    connect( numEdit, SIGNAL( finished( int ) ), this, SLOT( ReadValue() ) ) ;

    /*if( this->pos() != QPoint( 0, 0 ) )
    {
        numEdit->move( this->x() , this->y() ) ;
    }
    else
    {
        numEdit->move( 0 , 0 ) ;
    }

    numEdit->show() ;
    numEdit->raise() ;*/

    numEdit->exec() ;
}

void EditBox::ReadValue()
{
    if( numEdit != 0 )
    {
        this->setText( numEdit->GetStringValue() ) ;
    }

    delete numEdit ;
    numEdit = 0 ;
}

int EditBox::GetIntValue()
{
    return ( int )( this->text().toInt() ) ;
}

double EditBox::GetDoubleValue()
{
    return ( double )( this->text().toDouble() ) ;
}

QString EditBox::GetStringValue()
{
    return ( QString )( this->text() ) ;
}

#include "numberedit.h"
#include "ui_numberedit.h"

NumberEdit::NumberEdit( int initValue, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NumberEdit)
{
    ui->setupUi(this);

    this->setWindowFlags( Qt::MSWindowsFixedSizeDialogHint | Qt::FramelessWindowHint | Qt::Dialog ) ;

    ui->Le_Value->setText( QString::number( initValue ) ) ;
}

NumberEdit::NumberEdit(double initValue, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NumberEdit)
{
    ui->setupUi(this);

    this->setWindowFlags( Qt::MSWindowsFixedSizeDialogHint | Qt::FramelessWindowHint | Qt::Dialog ) ;

    ui->Le_Value->setText( QString::number( initValue ) ) ;
}

NumberEdit::NumberEdit( QString initValue, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NumberEdit)
{
    ui->setupUi(this);

    this->setWindowFlags( Qt::MSWindowsFixedSizeDialogHint | Qt::FramelessWindowHint | Qt::Dialog ) ;

    ui->Le_Value->setText( initValue ) ;
}

NumberEdit::~NumberEdit()
{
    delete ui;
}

void NumberEdit::on_Pb_Back_clicked()
{
    ui->Le_Value->setText( ui->Le_Value->text().left( ui->Le_Value->text().length() -1 ) ) ;
}

void NumberEdit::on_Pb_Ok_clicked()
{
    //this->close() ;
    this->finished( 1 ) ;
}

int NumberEdit::GetIntValue()
{
    return ( int )( ui->Le_Value->text().toInt() ) ;
}

double NumberEdit::GetDoubleValue()
{
    return ( double )( ui->Le_Value->text().toDouble() ) ;
}

QString NumberEdit::GetStringValue()
{
    return ( QString )( ui->Le_Value->text() ) ;
}

void NumberEdit::on_Pb_0_clicked()
{
    ui->Le_Value->setText( ui->Le_Value->text() + '0' ) ;
}

void NumberEdit::on_Pb_1_clicked()
{
    ui->Le_Value->setText( ui->Le_Value->text() + '1' ) ;
}

void NumberEdit::on_Pb_2_clicked()
{
    ui->Le_Value->setText( ui->Le_Value->text() + '2' ) ;
}

void NumberEdit::on_Pb_3_clicked()
{
    ui->Le_Value->setText( ui->Le_Value->text() + '3' ) ;
}

void NumberEdit::on_Pb_4_clicked()
{
    ui->Le_Value->setText( ui->Le_Value->text() + '4' ) ;
}

void NumberEdit::on_Pb_5_clicked()
{
    ui->Le_Value->setText( ui->Le_Value->text() + '5' ) ;
}

void NumberEdit::on_Pb_6_clicked()
{
    ui->Le_Value->setText( ui->Le_Value->text() + '6' ) ;
}

void NumberEdit::on_Pb_7_clicked()
{
    ui->Le_Value->setText( ui->Le_Value->text() + '7' ) ;
}

void NumberEdit::on_Pb_8_clicked()
{
    ui->Le_Value->setText( ui->Le_Value->text() + '8' ) ;
}

void NumberEdit::on_Pb_9_clicked()
{
    ui->Le_Value->setText( ui->Le_Value->text() + '9' ) ;
}

void NumberEdit::on_Pb__clicked()
{
    if( ! ui->Le_Value->text().contains( '.' ) )
    {
        ui->Le_Value->setText( ui->Le_Value->text() + '.' ) ;
    }
}

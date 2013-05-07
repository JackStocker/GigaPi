#include "adjustments.h"
#include "ui_adjustments.h"

Adjustments::Adjustments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adjustments)
{
    ui->setupUi(this);

    this->setWindowFlags( Qt::MSWindowsFixedSizeDialogHint | Qt::FramelessWindowHint | Qt::Dialog ) ;
}

Adjustments::~Adjustments()
{
    delete ui;
}

void Adjustments::on_Pb_Ok_clicked()
{
    this->close() ;
}

QPushButton* Adjustments::GetRightPb()
{
    return ui->Pb_Right ;
}

QPushButton* Adjustments::GetLeftPb()
{
    return ui->Pb_Left ;
}

QPushButton* Adjustments::GetUpPb()
{
    return ui->Pb_Up ;
}

QPushButton* Adjustments::GetDownPb()
{
    return ui->Pb_Down ;
}

QPushButton* Adjustments::GetRotatePb()
{
    return ui->Pb_Rotate ;
}

int Adjustments::GetDelay()
{
    return ui->Sp_Delay->value() ;
}

int Adjustments::GetRotDegs()
{
    return ui->Sp_RotationDegrees->value() ;
}

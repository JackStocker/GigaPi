#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    this->setWindowFlags( Qt::MSWindowsFixedSizeDialogHint | Qt::FramelessWindowHint | Qt::Dialog ) ;

    Eb_HOverlap = new EditBox( *( ui->La_H_Overlap ), "30", this ) ;
    Eb_VOverlap = new EditBox( *( ui->La_V_Overlap ), "30", this ) ;
    Eb_HMin_Step = new EditBox( *( ui->La_H_Min_Step ), QString::number( double( 1 / double( double( 40 * 2048 ) / 360 ) ) ) , this ) ;
    Eb_VMin_Step = new EditBox( *( ui->La_V_Min_Step ), QString::number( double( 1 / double( double( 56 * 2048 ) / 360 ) ) ) , this ) ;
    Eb_Focal_Length = new EditBox( *( ui->La_Focal_Length ), "100", this ) ;
    Eb_Focus_Duration = new EditBox( *( ui->La_Focus_Dur ), "750", this ) ;
    Eb_Shutter_Duration = new EditBox( *( ui->La_Shutter_Dur ), "300", this ) ;
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_Pb_Ok_clicked()
{
    this->close() ;
}

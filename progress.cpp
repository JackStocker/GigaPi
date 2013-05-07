#include "progress.h"
#include "ui_progress.h"

Progress::Progress( const int rows, const int columns, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Progress)
{
    ui->setupUi(this);

    this->setWindowFlags( Qt::MSWindowsFixedSizeDialogHint | Qt::FramelessWindowHint | Qt::Dialog ) ;


    // Setup the initial table
    ui->Tw_Display->setFixedSize( ui->Tw_Display->size() ) ;
    ui->Tw_Display->setRowCount( rows ) ;
    ui->Tw_Display->setColumnCount( columns ) ;

    ui->Tw_Display->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff ) ;
    ui->Tw_Display->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff ) ;

    ui->Tw_Display->horizontalHeader()->hide() ;
    ui->Tw_Display->verticalHeader()->hide() ;

    // Setup the headers
    ui->Tw_VerticalHeader->setRowCount( rows ) ;
    ui->Tw_HorizontalHeader->setColumnCount( columns ) ;
    ui->Tw_VerticalHeader->setRowCount( rows ) ;
    ui->Tw_HorizontalHeader->setColumnCount( columns ) ;

    ui->Tw_VerticalHeader->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff ) ;
    ui->Tw_HorizontalHeader->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff ) ;


    for( int x=0 ; x < columns ; ++x )
    {
        ui->Tw_Display->setColumnWidth( x, ( ui->Tw_Display->width() / columns ) ) ;
        ui->Tw_HorizontalHeader->setColumnWidth( x, ui->Tw_Display->width() / columns ) ;
    }

    for( int x=0 ; x < rows ; ++x )
    {
        ui->Tw_Display->setRowHeight( x, ( ui->Tw_Display->height() / rows ) ) ;
        ui->Tw_VerticalHeader->setRowHeight( x, ui->Tw_Display->height() / rows ) ;
    }
}

Progress::~Progress()
{
    delete ui;
}

void Progress::SetCompletedCells( const int completed_rows, const int current_cell )
{
    for( int x = 0 ; x < current_cell ; ++x )
    {
        ui->Tw_Display->setItem( completed_rows, x, new QTableWidgetItem() ) ;
        ui->Tw_Display->item( completed_rows, x )->setBackgroundColor( Qt::gray ) ;
    }

    ui->Tw_Display->item( completed_rows, current_cell -1 )->setBackgroundColor( Qt::darkGreen ) ;
}

void Progress::SetCompletedRow( const int row )
{
    for( int x=0 ; x < ui->Tw_Display->columnCount() ; ++x )
    {
        ui->Tw_Display->setItem( row, x, new QTableWidgetItem() ) ;
        ui->Tw_Display->item( row, x )->setBackgroundColor( Qt::green ) ;
    }
}

void Progress::SetStatus( const QString &string )
{
    ui->La_Status->setText( string ) ;
}

void Progress::on_Pb_PauseContinue_clicked()
{
    if( ui->Pb_PauseContinue->text() == "Pause" )
    {
        current_state = PAUSE ;
        ui->Pb_PauseContinue->setText( "Continue" ) ;
    }
    else
    {
        current_state = RUNNING ;
        ui->Pb_PauseContinue->setText( "Pause" ) ;
    }
}

void Progress::on_Pb_Cancel_clicked()
{
    current_state = CANCEL ;
}

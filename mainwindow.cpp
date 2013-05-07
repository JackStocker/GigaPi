#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "time.h"
#include <QMessageBox>
#include <QProcess>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <math.h>
#include <qmath.h>
#include <wiringPi.h>


#ifndef	TRUE
#  define	TRUE	(1==1)
#  define	FALSE	(1==2)
#endif

#undef	DEBUG


#define _USE_MATH_DEFINES

static int phases [2] ;

static int half_step_sequence [] =
{
//O  Y  P  B    <-- Wire Colours
  1, 0, 0, 0,
  1, 1, 0, 0,
  0, 1, 0, 0,
  0, 1, 1, 0,
  0, 0, 1, 0,
  0, 0, 1, 1,
  0, 0, 0, 1,
  1, 0, 0, 1,
} ;

static int full_step_sequence [] =
{
//O  Y  P  B    <-- Wire Colours
  1, 1, 0, 0,
  0, 1, 1, 0,
  0, 0, 1, 1,
  1, 0, 0, 1,
  1, 1, 0, 0,
  0, 1, 1, 0,
  0, 0, 1, 1,
  1, 0, 0, 1,
} ;

ACTION_STATE Progress::current_state ;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this) ;

    delay_int = 3 ;
    reverse = false ;
    adjustments = new Adjustments() ;
    connect( adjustments->GetRightPb(),SIGNAL( released() ), this, SLOT( ButtonReleased() ) ) ;
    connect( adjustments->GetLeftPb() ,SIGNAL( released() ), this, SLOT( ButtonReleased() ) ) ;
    connect( adjustments->GetUpPb()   ,SIGNAL( released() ), this, SLOT( ButtonReleased() ) ) ;
    connect( adjustments->GetDownPb() ,SIGNAL( released() ), this, SLOT( ButtonReleased() ) ) ;

    connect( adjustments->GetRightPb(),SIGNAL( pressed()  ), this, SLOT( on_Pb_Right_pressed() ) ) ;
    connect( adjustments->GetLeftPb() ,SIGNAL( pressed()  ), this, SLOT( on_Pb_Left_pressed()  ) ) ;
    connect( adjustments->GetUpPb()   ,SIGNAL( pressed()  ), this, SLOT( on_Pb_Up_pressed() )  ) ;
    connect( adjustments->GetDownPb() ,SIGNAL( pressed()  ), this, SLOT( on_Pb_Down_pressed()  ) ) ;

    connect( adjustments->GetRotatePb() ,SIGNAL( clicked() ), this, SLOT( on_Pb_Rotate_clicked() ) ) ;


    spin_timer = new QTimer( this ) ;
    connect( spin_timer, SIGNAL( timeout() ), this, SLOT( OnTick() ) ) ;

    settings = new Settings( this ) ;

    this->setWindowFlags( Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint ) ;

    //this->showFullScreen() ;

    Eb_HAngle = new EditBox( *( ui->La_H_Angle ), "100", this ) ;
    Eb_VAngle = new EditBox( *( ui->La_V_Angle ), "15", this ) ;

    // Initialising
    H_Viewing_Angle = 0 ;
    V_Viewing_Angle = 0 ;

    H_Pic_Overlap = 0 ;
    V_Pic_Overlap = 0 ;

    Actual_V_Angle = 0 ;

    Sensor_Height = 0.0 ;
    Sensor_Width  = 0.0 ;

    Focal_Length = 0 ;

    H_FOV = 0.0 ;
    V_FOV = 0.0 ;

    H_ROT = 0.0 ;
    V_ROT = 0.0 ;

    H_Min_Step = 0.0 ;
    V_Min_Step = 0.0 ;

    H_ROT_arr = 0.0 ;
    V_ROT_arr = 0.0 ;

    GigaPi_Row_List.clear() ;

    steps_to_go = 0 ;
    //motor = HORIZONTAL ;

    Horizontal.id               = 0 ;
    Horizontal.worm_wheel_teeth = 40 ;
    Horizontal.isHorizontal     = true ;
    Horizontal.min_full_step    = 11.250 ;
    Horizontal.steps_per_rev    = 2048 ;

    Vertical.id               = 1 ;
    Vertical.worm_wheel_teeth = 56 ;
    Vertical.isHorizontal     = false ;
    Vertical.min_full_step    = 11.250 ;
    Vertical.steps_per_rev    = 2048 ;

    current_motor = Horizontal ;

    horizontal_steps_to_go = 0 ;
    vertical_steps_to_go   = 0 ;
    current_row            = 0 ;


    setup () ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setup()
{
  int i ;

  if( wiringPiSetup() == -1 )
  {
    QMessageBox::information( this , "Error" , "Unable to setup wiringPi" , QMessageBox::Ok) ;
    exit( 1 ) ;
  }


  // setup the 8 stepper pins to be output
  for( i = 0 ; i < 8 ; ++i )
  {
    pinMode( i, OUTPUT ) ;
    digitalWrite( i, 0 ) ;
  }

  // setup two pins for the relays
  pinMode( 8, OUTPUT ) ;
  pinMode( 9, OUTPUT ) ;

  // initialise the stepper motors to 1,0,0,0
  digitalWrite( 0, 1 ) ;
  digitalWrite( 4, 1 ) ;

  // initialise the phases to 0
  phases[ 0 ] = 0 ;
  phases[ 1 ] = 0 ;
}


void MainWindow::stepMotor( Motor motor, bool reverse )
{
  int i ;
  int offset = motor.id * 4 ;
  int phase  = phases[ motor.id ] * 4 ;


  if( ! reverse )
  {
    i = phases[ motor.id ] - 1 ;
    if( i < 0 )
      i = 7 ;
  }
  else
  {
    i = phases[ motor.id ] + 1 ;
    if( i == 8 )
      i = 0 ;
  }

  phases[ motor.id ] = i ;

  for ( i = 0 ; i < 4 ; ++i )
  {
    //digitalWrite( i + offset, half_step_sequence[ phase + i ] ) ;
      digitalWrite( i + offset, full_step_sequence[ phase + i ] ) ;
  }
}

void MainWindow::on_Pb_Go_clicked()
{
    GigaPi_Row_List.clear() ;

    // Start processing
    H_Viewing_Angle = Eb_HAngle->GetIntValue() ;
    V_Viewing_Angle = ( Eb_VAngle->GetDoubleValue() / ( double )2 ) ;

    H_Pic_Overlap = settings->Eb_HOverlap->GetIntValue() ;
    V_Pic_Overlap = settings->Eb_VOverlap->GetIntValue() ;

    Actual_V_Angle = V_Viewing_Angle * 2 ;

    if( ui->comboBox->currentText() == "Canon" )
    {
        Sensor_Height = 24 ;
        Sensor_Width  = 36 ;
    }
    else
    {
        Sensor_Height = 4.56 ;
        Sensor_Width  = 6.08 ;
    }

    Focal_Length = settings->Eb_Focal_Length->GetIntValue() ;

    H_FOV = 2 * atan( Sensor_Width / 2 / Focal_Length ) * ( 180 / M_PI ) ;
    V_FOV = 2 * atan( Sensor_Height / 2 / Focal_Length ) * ( 180 / M_PI ) ;

    H_ROT = H_FOV * double( 1 - double( H_Pic_Overlap / double( 100 ) ) ) ;
    V_ROT = V_FOV * double( 1 - double( V_Pic_Overlap / double( 100 ) ) ) ;

    H_Min_Step = settings->Eb_HMin_Step->GetDoubleValue() ;
    V_Min_Step = settings->Eb_VMin_Step->GetDoubleValue() ;

    H_ROT_arr = H_Min_Step * qFloor( H_ROT / H_Min_Step ) ;
    V_ROT_arr = V_Min_Step * qFloor( V_ROT / V_Min_Step ) ;

    H_Angle_Moved = 0.0 ;


    // Create the list of rows
    GigaPi_Row prev_row ;
    prev_row.V_Angle = 0 ; // double( V_Min_Step * ( double )( double( V_Viewing_Angle ) / 2 / double( Actual_V_Angle ) ) ) ;
    prev_row.V_Overlap = 0 ;
    prev_row.B_NumPics = H_Viewing_Angle * cos( prev_row.V_Angle / ( 180 / M_PI ) ) / H_ROT ;
    prev_row.B_Angle = H_Viewing_Angle / prev_row.B_NumPics ;
    prev_row.H_Angle = H_Min_Step * qFloor( prev_row.B_Angle / H_Min_Step ) ;
    prev_row.H_Overlap = ( H_FOV / cos( prev_row.V_Angle / ( 180 * M_PI ) ) - prev_row.H_Angle ) / H_FOV * cos( prev_row.V_Angle / ( 180 * M_PI ) ) ;
    prev_row.L_NumPics = qCeil( double( H_Viewing_Angle / prev_row.H_Angle ) ) ;

    GigaPi_Row_List.push_back( prev_row ) ;


    while( double( prev_row.V_Angle + ( V_FOV / 2.0 ) ) < double( V_Viewing_Angle ) )
    {
        GigaPi_Row new_row ;

        // Vertical Rotation Angle
        if( ( prev_row.V_Angle + V_FOV / 2 >= 90 ) ||
            ( prev_row.V_Angle + V_ROT_arr >= 90 ) )
        {
            new_row.V_Angle = 90 ;
        }
        else
        {
            new_row.V_Angle = prev_row.V_Angle + V_ROT_arr ;
        }

        // Vertical Overlap with previous
        new_row.V_Overlap = ( V_FOV - new_row.V_Angle + prev_row.V_Angle ) / V_FOV ;

        // Brut number of Pictures
        new_row.B_NumPics = H_Viewing_Angle * cos( ( prev_row.V_Angle + ( V_ROT / 2 ) ) / ( 180 * M_PI ) ) / H_ROT ;

        // Brut angle
        new_row.B_Angle = H_Viewing_Angle / new_row.B_NumPics ;

        // Horizontal Rotation Angle
        if( new_row.V_Angle == 90 )
        {
            new_row.H_Angle = 0 ;
        }
        else if( new_row.B_Angle > 360 )
        {
            new_row.H_Angle = 360 ;
        }
        else
        {
            new_row.H_Angle = H_Min_Step * qFloor( new_row.B_Angle / H_Min_Step ) ;
        }

        // Horizontal Overlap with previous
        new_row.H_Overlap = ( H_FOV / cos( new_row.V_Angle / ( 180 * M_PI ) ) - new_row.H_Angle ) / H_FOV * cos( new_row.V_Angle / ( 180 * M_PI ) ) ;

        // Number of Pics on Line
        if( new_row.H_Angle == 0.0 )
        {
            new_row.L_NumPics = 1 ;
        }
        else
        {
            new_row.L_NumPics = qCeil( double( H_Viewing_Angle / new_row.H_Angle ) ) ;
        }

        GigaPi_Row_List.push_back( new_row ) ;
        prev_row = new_row ;
    }


    QString rows = "" ;
    foreach( GigaPi_Row row, GigaPi_Row_List )
    {
        rows += QString::number( row.V_Angle   ) + " " + QString::number( row.V_Overlap ) + ( rows == "" ? ".000000 " : " " ) +
                QString::number( row.B_NumPics ) + " " + QString::number( row.B_Angle   ) + " " +
                QString::number( row.H_Angle   ) + " " + QString::number( row.H_Overlap ) + " " +
                QString::number( row.L_NumPics ) + "\n" ;
    }

    //QMessageBox::information( this, "Rows" , rows , QMessageBox::Default ) ;
    QMessageBox Go ;
    Go.setFixedSize( this->size() ) ;
    Go.addButton( QMessageBox::Yes ) ;
    Go.addButton( QMessageBox::No ) ;
    Go.setText( "The image will consist of:\n" +
                QString::number( GigaPi_Row_List.size() ) + " rows of\n" +
                QString::number( GigaPi_Row_List[ 0 ].L_NumPics ) + " images.\n\n" +
                "Begin?" ) ;

    int ret = Go.exec() ;
    if( ret == QMessageBox::Yes )
    {
        GigaPi_Timer = new QTimer( this ) ;
        connect( GigaPi_Timer, SIGNAL( timeout() ), this, SLOT( OnGigaPiTimerTick() ) ) ;

        GigaPi_State  = TAKE_PICTURE ;
        Progress::current_state = RUNNING ;
        horizontal_steps_to_go = GigaPi_Row_List[ 0 ].L_NumPics ;
        vertical_steps_to_go   = GigaPi_Row_List.size() ;

        progress = new Progress( vertical_steps_to_go, horizontal_steps_to_go, this ) ;
        ShowDialog( *progress ) ;
        GigaPi_Timer->start( 1000 ) ;
    }
}

void MainWindow::on_Pb_Settings_clicked()
{
    ShowDialog( *settings ) ;
}

void MainWindow::on_Pb_Adjustments_clicked()
{
    ShowDialog( *adjustments ) ;
}

void MainWindow::ShowDialog( QDialog &dialog )
{
    if( this->pos() != QPoint( 0, 0 ) )
    {
        dialog.move( this->x() , this->y() ) ;
    }
    else
    {
        dialog.move( 0 , 0 ) ;
    }

    dialog.show() ;
    dialog.raise() ;
}

void MainWindow::Rotate( Motor motor, double degrees, bool reverse )
{
    if( delay_int < 1 )
      delay_int = 1 ;

    if( degrees < 0 )
      degrees = 0 ;


    double stepper_motor_degrees = motor.worm_wheel_teeth * degrees ;

    steps_to_go = ( stepper_motor_degrees * motor.steps_per_rev ) / 360 ;


    current_motor = motor ;
    this->reverse = reverse ;

    spin_timer->start( adjustments->GetDelay() ) ;
}

void MainWindow::OnTick()
{
    if( steps_to_go <= 0 )
    {
        spin_timer->stop() ;
        return ;
    }


    if( Progress::current_state == RUNNING )
    {
        --steps_to_go ;

        stepMotor( current_motor, reverse ) ;
    }
    else if( Progress::current_state == PAUSE )
    {
        //
    }
    else if( Progress::current_state == CANCEL )
    {
        spin_timer->stop() ;

        if( GigaPi_Timer->isActive() )
        {
            GigaPi_Timer->stop() ;
        }

        if( progress->isWindow() )
        {
            progress->close() ;
        }
    }

    //delay( delay_int ) ;
}

void MainWindow::OnGigaPiTimerTick()
{
    // If the motor is still spinning, then wait here for another second
    // As we do not want to move on too early
    if( Progress::current_state == PAUSE ||
        spin_timer->isActive() )
    {
        GigaPi_Timer->setSingleShot( false ) ;
        GigaPi_Timer->start( 1000 ) ;

        digitalWrite( 8, 0 ) ;
        digitalWrite( 9, 0 ) ;

        return ;
    }
    else if( Progress::current_state == CANCEL )
    {
        spin_timer->stop() ;
        GigaPi_Timer->stop() ;

        horizontal_steps_to_go = 0 ;
        vertical_steps_to_go = 0 ;

        progress->close() ;

        digitalWrite( 8, 0 ) ;
        digitalWrite( 9, 0 ) ;

        return ;
    }
    else
    {
        GigaPi_Timer->setSingleShot( true ) ;
    }


    switch( GigaPi_State )
    {
        case TAKE_PICTURE:
        {
            progress->SetStatus( "Preparing image..." ) ;


            // if completed a row, step down
            if( horizontal_steps_to_go <= 0 )
            {
                GigaPi_State = STEP_DOWN ;
            }
            // otherwise focus
            else
            {
                GigaPi_State = FOCUS ;
            }

            // wait
            GigaPi_Timer->start( 300 ) ;
            break ;
        }
        case FOCUS:
        {
            progress->SetStatus( "Focusing..." ) ;

            // focus
            digitalWrite( 8, 1 ) ;

            GigaPi_State = SHUTTER ;

            // wait
            GigaPi_Timer->start( settings->Eb_Focus_Duration->GetIntValue() ) ; //get from settings
            break ;
        }
        case SHUTTER:
        {
            progress->SetStatus( "Taking picture..." ) ;


            // shutter
            digitalWrite( 9, 1 ) ;

            GigaPi_State = WRITE_TO_CARD ;

            // wait
            GigaPi_Timer->start( settings->Eb_Shutter_Duration->GetIntValue() ) ; //get from settings
            break ;
        }
        case WRITE_TO_CARD:
        {
            progress->SetStatus( "Writing to card..." ) ;


            // stop taking picture and wait for data to be written to card
            digitalWrite( 8, 0 ) ;
            digitalWrite( 9, 0 ) ;

            GigaPi_State = STEP_RIGHT ;

            // wait
            GigaPi_Timer->start( settings->Eb_Shutter_Duration->GetIntValue() *2 ) ; //get from settings *2
            break ;
        }
        case STEP_RIGHT:
        {
            progress->SetStatus( "Moving right..." ) ;


            // one picture complete, display this + step right once
            --horizontal_steps_to_go ;

            progress->SetCompletedCells( GigaPi_Row_List.size() - vertical_steps_to_go, GigaPi_Row_List[ GigaPi_Row_List.size() - vertical_steps_to_go ].L_NumPics - horizontal_steps_to_go ) ;

            // Step right
            Rotate( Horizontal, GigaPi_Row_List[ GigaPi_Row_List.size() - vertical_steps_to_go ].H_Angle, true ) ;

            H_Angle_Moved += GigaPi_Row_List[ GigaPi_Row_List.size() - vertical_steps_to_go ].H_Angle ;


            GigaPi_State = TAKE_PICTURE ;

            // wait
            GigaPi_Timer->start( 300 ) ;
            break ;
        }
        case STEP_DOWN:
        {
            progress->SetStatus( "Moving down..." ) ;


            // step down
            Rotate( Vertical, GigaPi_Row_List[ GigaPi_Row_List.size() - vertical_steps_to_go ].H_Angle, false ) ;

            GigaPi_State = RESET_TO_LEFT ;

            // wait
            GigaPi_Timer->start( 1000 ) ;
            break ;
        }
        case RESET_TO_LEFT:
        {
            progress->SetStatus( "Resetting to left..." ) ;


            // reset to left
            Rotate( Horizontal, H_Angle_Moved, false ) ;

            H_Angle_Moved = 0.0 ;

            GigaPi_State = TAKE_PICTURE ;
            //GigaPi_State = TAKE_UP_SLACK ;

            --vertical_steps_to_go ;

            // if picutre complete, reset to top
            if( vertical_steps_to_go <= 0 )
            {
                GigaPi_State = RESET_TO_TOP ;
            }
            // otherwise, carry on & take another picture
            else
            {
                horizontal_steps_to_go = GigaPi_Row_List[ GigaPi_Row_List.size() - vertical_steps_to_go ].L_NumPics ;
            }

            // wait
            GigaPi_Timer->start( 1000 ) ;
            break ;
        }
        case TAKE_UP_SLACK:
        {
            progress->SetStatus( "Taking up slack..." ) ;

            // Take up the slack in the horizontal worm gears
            //Rotate( Horizontal, settings->Eb_Slack_Angle->GetDoubleValue(), true ) ;

            GigaPi_State = TAKE_PICTURE ;

            // wait
            GigaPi_Timer->start( 1000 ) ;
            break ;
        }
        case RESET_TO_TOP:
        {
            progress->SetStatus( "Resetting to top..." ) ;


            // reset to top
            Rotate( Vertical, GigaPi_Row_List[ GigaPi_Row_List.size() - vertical_steps_to_go ].H_Angle, true ) ;

            GigaPi_State = FINISH ;

            // wait
            GigaPi_Timer->start( 1000 ) ;
            break ;
        }
        case FINISH:
        {
            progress->SetStatus( "Finish..." ) ;


            GigaPi_Timer->stop() ;
            horizontal_steps_to_go = 0 ;
            vertical_steps_to_go = 0 ;

            progress->close() ;
            break ;
        }
    }
}

//Button functions
void MainWindow::on_Pb_Right_pressed()
{
    reverse = true ;
    current_motor = Horizontal ;

    Progress::current_state = RUNNING ;
    steps_to_go = 10000 ;

    spin_timer->start( adjustments->GetDelay() ) ;
}

void MainWindow::on_Pb_Left_pressed()
{
    reverse = false ;
    current_motor = Horizontal ;

    Progress::current_state = RUNNING ;
    steps_to_go = 10000 ;

    spin_timer->start( adjustments->GetDelay() ) ;
}

void MainWindow::on_Pb_Up_pressed()
{
    reverse = true ;
    current_motor = Vertical ;

    Progress::current_state = RUNNING ;
    steps_to_go = 10000 ;

    spin_timer->start( adjustments->GetDelay() ) ;
}

void MainWindow::on_Pb_Down_pressed()
{
    reverse = false ;
    current_motor = Vertical ;

    Progress::current_state = RUNNING ;
    steps_to_go = 10000 ;

    spin_timer->start( adjustments->GetDelay() ) ;
}

void MainWindow::ButtonReleased()
{
    spin_timer->stop() ;
    Progress::current_state = CANCEL ;
}

void MainWindow::on_Pb_Close_clicked()
{
    this->close() ;
}

void MainWindow::on_Pb_Shutdown_clicked()
{
    QProcess *shutdown = new QProcess( this );
    QString command= "sudo shutdown" ;
    QStringList arguments ;
    arguments << "-h " << "now" ;
    shutdown->start( command, arguments );
}

void MainWindow::on_Pb_Rotate_clicked()
{
    int degs = adjustments->GetRotDegs() ;

    if( degs < 0 )
    {
        degs *= -1 ;
        reverse = true ;
    }
    else
    {
        reverse = false ;
    }


    //degs = ( 360 / ( double( 360 ) / double( settings->Eb_HGear_Ratio->GetDoubleValue() ) ) )  * degs ;
    Progress::current_state = RUNNING ;
    Rotate( Horizontal, degs, reverse ) ;
}

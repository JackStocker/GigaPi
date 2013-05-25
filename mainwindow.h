#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "settings.h"
#include "adjustments.h"
#include "progress.h"
#include "editbox.h"

struct GigaPi_Row
{
    double V_Angle ;
    double V_Overlap ;
    double B_NumPics ;
    double B_Angle ;
    double H_Angle ;
    double H_Overlap ;
    int    L_NumPics ;
};

static enum MOTOR { HORIZONTAL = 0, VERTICAL = 1 } motor ;

static enum GIGAPI_STATES { TAKE_PICTURE, FOCUS, SHUTTER, WRITE_TO_CARD, STEP_RIGHT, STEP_DOWN, RESET_TO_LEFT, TAKE_UP_SLACK, RESET_TO_TOP, FINISH } GigaPi_State ;

struct Motor
{
   int    id ;
   int    worm_wheel_teeth ;
   bool   isHorizontal ;
   double min_full_step ;
   int    steps_per_rev ;
} ;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_Pb_Go_clicked();

    void on_Pb_Settings_clicked();

    void OnTick() ;

    void OnGigaPiTimerTick() ;

    void on_Pb_Down_pressed();

    void on_Pb_Right_pressed();

    void on_Pb_Left_pressed();

    void on_Pb_Up_pressed();

    void ButtonReleased() ;

    void on_Pb_Close_clicked() ;

    void on_Pb_Shutdown_clicked() ;

    void on_Pb_Adjustments_clicked();

    void on_Pb_Rotate_clicked();

private:
    Ui::MainWindow *ui;

    int steps_to_go ;
    //int motor ;

    EditBox *Eb_HAngle ;
    EditBox *Eb_VAngle ;

    void setup() ;
    void stepMotor( Motor motor, bool reverse ) ;
    void Rotate( Motor motor, double degrees, bool reverse ) ;

    Settings *settings ;
    Adjustments *adjustments ;
    QTimer   *spin_timer ;


    QTimer *GigaPi_Timer ;
    Progress *progress ;
    int horizontal_steps_to_go ;
    int vertical_steps_to_go ;
    int current_row ;

    Motor Horizontal ;
    Motor Vertical ;
    Motor current_motor ;

    void ShowDialog( QDialog & ) ;


    int delay_int ;
    bool reverse ;


    int H_Viewing_Angle ;
    int V_Viewing_Angle ;

    int H_Pic_Overlap ;
    int V_Pic_Overlap ;

    int Actual_V_Angle ;

    double Sensor_Height ;
    double Sensor_Width ;

    int Focal_Length ;

    double H_FOV ;
    double V_FOV ;

    double H_ROT ;
    double V_ROT ;

    double H_Min_Step ;
    double V_Min_Step ;

    double H_ROT_arr ;
    double V_ROT_arr ;

    double H_Angle_Moved ;
    double V_Angle_Moved ;

    QList< GigaPi_Row > GigaPi_Row_List ;
};

#endif // MAINWINDOW_H

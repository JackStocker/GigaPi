#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "editbox.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT
    
public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

    EditBox *Eb_HOverlap ;
    EditBox *Eb_VOverlap ;
    EditBox *Eb_HMin_Step ;
    EditBox *Eb_VMin_Step ;
    EditBox *Eb_Focal_Length ;
    EditBox *Eb_Focus_Duration ;
    EditBox *Eb_Shutter_Duration ;
    
private slots:
    void on_Pb_Ok_clicked();

private:
    Ui::Settings *ui;

};

#endif // SETTINGS_H

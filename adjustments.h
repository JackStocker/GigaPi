#ifndef ADJUSTMENTS_H
#define ADJUSTMENTS_H

#include <QDialog>

namespace Ui {
class Adjustments;
}

class Adjustments : public QDialog
{
    Q_OBJECT
    
public:
    explicit Adjustments(QWidget *parent = 0);
    ~Adjustments();

    QPushButton* GetRightPb() ;
    QPushButton* GetLeftPb() ;
    QPushButton* GetUpPb() ;
    QPushButton* GetDownPb() ;

    QPushButton* GetRotatePb() ;

    int GetDelay() ;
    int GetRotDegs() ;
    
private:
    Ui::Adjustments *ui;

private slots:
    void on_Pb_Ok_clicked();
};

#endif // ADJUSTMENTS_H

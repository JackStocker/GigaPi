#ifndef NUMBEREDIT_H
#define NUMBEREDIT_H

#include <QDialog>

namespace Ui {
class NumberEdit;
}

class NumberEdit : public QDialog
{
    Q_OBJECT
    
public:
    explicit NumberEdit( int     initValue, QWidget *parent = 0 ) ;
    explicit NumberEdit( double  initValue, QWidget *parent = 0 ) ;
    explicit NumberEdit( QString initValue, QWidget *parent = 0 ) ;
    ~NumberEdit();

    int     GetIntValue() ;
    double  GetDoubleValue() ;
    QString GetStringValue() ;
    
private slots:
    void on_Pb_Back_clicked();

    void on_Pb_0_clicked();

    void on_Pb_1_clicked();

    void on_Pb_2_clicked();

    void on_Pb_3_clicked();

    void on_Pb_4_clicked();

    void on_Pb_5_clicked();

    void on_Pb_6_clicked();

    void on_Pb_7_clicked();

    void on_Pb_8_clicked();

    void on_Pb_9_clicked();

    void on_Pb_Ok_clicked();

    void on_Pb__clicked();

private:
    Ui::NumberEdit *ui;
};

#endif // NUMBEREDIT_H

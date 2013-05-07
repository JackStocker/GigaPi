#ifndef PROGRESS_H
#define PROGRESS_H

#include <QDialog>

enum ACTION_STATE { RUNNING, PAUSE, CANCEL } ;


namespace Ui {
class Progress;
}

class Progress : public QDialog
{
    Q_OBJECT

public:
    explicit Progress( const int rows, const int columns, QWidget *parent = 0);
    ~Progress();

    void SetCompletedCells( const int completed_rows, const int current_cell ) ;
    void SetCompletedRow( const int row ) ;

    void SetStatus( const QString &string ) ;

    static ACTION_STATE current_state ;

private slots:
    void on_Pb_PauseContinue_clicked();

    void on_Pb_Cancel_clicked();

private:
    Ui::Progress *ui;
};

#endif // PROGRESS_H

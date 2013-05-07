/********************************************************************************
** Form generated from reading UI file 'progress.ui'
**
** Created: Sun Apr 21 09:55:54 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESS_H
#define UI_PROGRESS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Progress
{
public:
    QPushButton *Pb_PauseContinue;
    QPushButton *Pb_Cancel;
    QTableWidget *Tw_Display;
    QTableWidget *Tw_VerticalHeader;
    QTableWidget *Tw_HorizontalHeader;
    QLabel *La_Status;

    void setupUi(QDialog *Progress)
    {
        if (Progress->objectName().isEmpty())
            Progress->setObjectName(QString::fromUtf8("Progress"));
        Progress->resize(480, 272);
        QFont font;
        font.setPointSize(16);
        Progress->setFont(font);
        Pb_PauseContinue = new QPushButton(Progress);
        Pb_PauseContinue->setObjectName(QString::fromUtf8("Pb_PauseContinue"));
        Pb_PauseContinue->setGeometry(QRect(350, 0, 131, 121));
        Pb_Cancel = new QPushButton(Progress);
        Pb_Cancel->setObjectName(QString::fromUtf8("Pb_Cancel"));
        Pb_Cancel->setGeometry(QRect(350, 150, 131, 121));
        Tw_Display = new QTableWidget(Progress);
        Tw_Display->setObjectName(QString::fromUtf8("Tw_Display"));
        Tw_Display->setGeometry(QRect(20, 20, 331, 251));
        Tw_VerticalHeader = new QTableWidget(Progress);
        Tw_VerticalHeader->setObjectName(QString::fromUtf8("Tw_VerticalHeader"));
        Tw_VerticalHeader->setGeometry(QRect(1, 19, 21, 251));
        Tw_HorizontalHeader = new QTableWidget(Progress);
        Tw_HorizontalHeader->setObjectName(QString::fromUtf8("Tw_HorizontalHeader"));
        Tw_HorizontalHeader->setGeometry(QRect(20, 0, 331, 21));
        La_Status = new QLabel(Progress);
        La_Status->setObjectName(QString::fromUtf8("La_Status"));
        La_Status->setGeometry(QRect(350, 120, 131, 31));
        QFont font1;
        font1.setPointSize(12);
        La_Status->setFont(font1);

        retranslateUi(Progress);

        QMetaObject::connectSlotsByName(Progress);
    } // setupUi

    void retranslateUi(QDialog *Progress)
    {
        Progress->setWindowTitle(QApplication::translate("Progress", "Dialog", 0, QApplication::UnicodeUTF8));
        Pb_PauseContinue->setText(QApplication::translate("Progress", "Pause", 0, QApplication::UnicodeUTF8));
        Pb_Cancel->setText(QApplication::translate("Progress", "Cancel", 0, QApplication::UnicodeUTF8));
        La_Status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Progress: public Ui_Progress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESS_H

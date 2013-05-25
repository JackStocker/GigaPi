/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat May 25 16:54:28 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Pb_Settings;
    QComboBox *comboBox;
    QPushButton *Pb_Go;
    QLabel *label;
    QLabel *label_2;
    QPushButton *Pb_Close;
    QPushButton *Pb_Adjustments;
    QLabel *La_H_Angle;
    QLabel *La_V_Angle;
    QPushButton *Pb_Shutdown;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 272);
        QFont font;
        font.setPointSize(16);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Pb_Settings = new QPushButton(centralWidget);
        Pb_Settings->setObjectName(QString::fromUtf8("Pb_Settings"));
        Pb_Settings->setGeometry(QRect(380, 170, 101, 101));
        QFont font1;
        font1.setPointSize(14);
        Pb_Settings->setFont(font1);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(0, 0, 231, 41));
        Pb_Go = new QPushButton(centralWidget);
        Pb_Go->setObjectName(QString::fromUtf8("Pb_Go"));
        Pb_Go->setGeometry(QRect(0, 180, 221, 91));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 60, 91, 41));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 120, 91, 41));
        Pb_Close = new QPushButton(centralWidget);
        Pb_Close->setObjectName(QString::fromUtf8("Pb_Close"));
        Pb_Close->setGeometry(QRect(320, 50, 161, 61));
        Pb_Adjustments = new QPushButton(centralWidget);
        Pb_Adjustments->setObjectName(QString::fromUtf8("Pb_Adjustments"));
        Pb_Adjustments->setGeometry(QRect(280, 170, 101, 101));
        Pb_Adjustments->setFont(font1);
        La_H_Angle = new QLabel(centralWidget);
        La_H_Angle->setObjectName(QString::fromUtf8("La_H_Angle"));
        La_H_Angle->setGeometry(QRect(0, 60, 221, 41));
        La_V_Angle = new QLabel(centralWidget);
        La_V_Angle->setObjectName(QString::fromUtf8("La_V_Angle"));
        La_V_Angle->setGeometry(QRect(0, 120, 221, 41));
        Pb_Shutdown = new QPushButton(centralWidget);
        Pb_Shutdown->setObjectName(QString::fromUtf8("Pb_Shutdown"));
        Pb_Shutdown->setGeometry(QRect(320, 0, 161, 51));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        Pb_Settings->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Lumix", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Canon", 0, QApplication::UnicodeUTF8)
        );
        Pb_Go->setText(QApplication::translate("MainWindow", "Go", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "H_Angle", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "V_Angle", 0, QApplication::UnicodeUTF8));
        Pb_Close->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        Pb_Adjustments->setText(QApplication::translate("MainWindow", "Adjust", 0, QApplication::UnicodeUTF8));
        La_H_Angle->setText(QString());
        La_V_Angle->setText(QString());
        Pb_Shutdown->setText(QApplication::translate("MainWindow", "Shutdown", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

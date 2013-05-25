/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Sat May 25 16:54:28 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QPushButton *Pb_Ok;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *La_H_Overlap;
    QLabel *La_V_Overlap;
    QLabel *La_H_Min_Step;
    QLabel *La_V_Min_Step;
    QLabel *La_Focal_Length;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *La_Focus_Dur;
    QLabel *label_9;
    QLabel *La_Shutter_Dur;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(480, 272);
        QFont font;
        font.setPointSize(10);
        Settings->setFont(font);
        Pb_Ok = new QPushButton(Settings);
        Pb_Ok->setObjectName(QString::fromUtf8("Pb_Ok"));
        Pb_Ok->setGeometry(QRect(280, 140, 201, 131));
        QFont font1;
        font1.setPointSize(16);
        Pb_Ok->setFont(font1);
        label = new QLabel(Settings);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 10, 81, 31));
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);
        label_2 = new QLabel(Settings);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 60, 81, 31));
        label_2->setFont(font2);
        label_5 = new QLabel(Settings);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(190, 190, 91, 31));
        QFont font3;
        font3.setPointSize(11);
        label_5->setFont(font3);
        label_6 = new QLabel(Settings);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(190, 240, 91, 31));
        label_6->setFont(font3);
        La_H_Overlap = new QLabel(Settings);
        La_H_Overlap->setObjectName(QString::fromUtf8("La_H_Overlap"));
        La_H_Overlap->setGeometry(QRect(0, 0, 191, 41));
        QFont font4;
        font4.setPointSize(14);
        La_H_Overlap->setFont(font4);
        La_V_Overlap = new QLabel(Settings);
        La_V_Overlap->setObjectName(QString::fromUtf8("La_V_Overlap"));
        La_V_Overlap->setGeometry(QRect(0, 50, 191, 41));
        La_V_Overlap->setFont(font4);
        La_H_Min_Step = new QLabel(Settings);
        La_H_Min_Step->setObjectName(QString::fromUtf8("La_H_Min_Step"));
        La_H_Min_Step->setGeometry(QRect(0, 180, 191, 41));
        La_H_Min_Step->setFont(font4);
        La_V_Min_Step = new QLabel(Settings);
        La_V_Min_Step->setObjectName(QString::fromUtf8("La_V_Min_Step"));
        La_V_Min_Step->setGeometry(QRect(0, 230, 191, 41));
        La_V_Min_Step->setFont(font4);
        La_Focal_Length = new QLabel(Settings);
        La_Focal_Length->setObjectName(QString::fromUtf8("La_Focal_Length"));
        La_Focal_Length->setGeometry(QRect(0, 110, 191, 41));
        La_Focal_Length->setFont(font4);
        label_7 = new QLabel(Settings);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(190, 120, 91, 31));
        label_7->setFont(font3);
        label_8 = new QLabel(Settings);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(320, 40, 121, 31));
        label_8->setFont(font2);
        La_Focus_Dur = new QLabel(Settings);
        La_Focus_Dur->setObjectName(QString::fromUtf8("La_Focus_Dur"));
        La_Focus_Dur->setGeometry(QRect(280, 0, 201, 41));
        La_Focus_Dur->setFont(font4);
        label_9 = new QLabel(Settings);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(310, 100, 131, 31));
        label_9->setFont(font2);
        La_Shutter_Dur = new QLabel(Settings);
        La_Shutter_Dur->setObjectName(QString::fromUtf8("La_Shutter_Dur"));
        La_Shutter_Dur->setGeometry(QRect(280, 70, 201, 31));
        La_Shutter_Dur->setFont(font4);

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Dialog", 0, QApplication::UnicodeUTF8));
        Pb_Ok->setText(QApplication::translate("Settings", "Ok", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Settings", "H_Overlap", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Settings", "V_Overlap", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Settings", "H_Min Step", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Settings", "V_Min Step", 0, QApplication::UnicodeUTF8));
        La_H_Overlap->setText(QString());
        La_V_Overlap->setText(QString());
        La_H_Min_Step->setText(QString());
        La_V_Min_Step->setText(QString());
        La_Focal_Length->setText(QString());
        label_7->setText(QApplication::translate("Settings", "Focal Length", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Settings", "Focus Duration", 0, QApplication::UnicodeUTF8));
        La_Focus_Dur->setText(QString());
        label_9->setText(QApplication::translate("Settings", "Shutter Duration", 0, QApplication::UnicodeUTF8));
        La_Shutter_Dur->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H

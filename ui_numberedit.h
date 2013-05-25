/********************************************************************************
** Form generated from reading UI file 'numberedit.ui'
**
** Created: Sat May 25 16:54:28 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMBEREDIT_H
#define UI_NUMBEREDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NumberEdit
{
public:
    QPushButton *Pb_7;
    QPushButton *Pb_8;
    QPushButton *Pb_9;
    QPushButton *Pb_5;
    QPushButton *Pb_4;
    QPushButton *Pb_6;
    QPushButton *Pb_2;
    QPushButton *Pb_1;
    QPushButton *Pb_3;
    QPushButton *Pb_0;
    QLineEdit *Le_Value;
    QPushButton *Pb_Ok;
    QPushButton *Pb_Back;
    QPushButton *Pb_;

    void setupUi(QDialog *NumberEdit)
    {
        if (NumberEdit->objectName().isEmpty())
            NumberEdit->setObjectName(QString::fromUtf8("NumberEdit"));
        NumberEdit->resize(480, 272);
        QFont font;
        font.setPointSize(16);
        NumberEdit->setFont(font);
        Pb_7 = new QPushButton(NumberEdit);
        Pb_7->setObjectName(QString::fromUtf8("Pb_7"));
        Pb_7->setGeometry(QRect(0, 0, 81, 81));
        Pb_8 = new QPushButton(NumberEdit);
        Pb_8->setObjectName(QString::fromUtf8("Pb_8"));
        Pb_8->setGeometry(QRect(90, 0, 81, 81));
        Pb_9 = new QPushButton(NumberEdit);
        Pb_9->setObjectName(QString::fromUtf8("Pb_9"));
        Pb_9->setGeometry(QRect(180, 0, 81, 81));
        Pb_5 = new QPushButton(NumberEdit);
        Pb_5->setObjectName(QString::fromUtf8("Pb_5"));
        Pb_5->setGeometry(QRect(90, 90, 81, 81));
        Pb_4 = new QPushButton(NumberEdit);
        Pb_4->setObjectName(QString::fromUtf8("Pb_4"));
        Pb_4->setGeometry(QRect(0, 90, 81, 81));
        Pb_6 = new QPushButton(NumberEdit);
        Pb_6->setObjectName(QString::fromUtf8("Pb_6"));
        Pb_6->setGeometry(QRect(180, 90, 81, 81));
        Pb_2 = new QPushButton(NumberEdit);
        Pb_2->setObjectName(QString::fromUtf8("Pb_2"));
        Pb_2->setGeometry(QRect(90, 180, 81, 81));
        Pb_1 = new QPushButton(NumberEdit);
        Pb_1->setObjectName(QString::fromUtf8("Pb_1"));
        Pb_1->setGeometry(QRect(0, 180, 81, 81));
        Pb_3 = new QPushButton(NumberEdit);
        Pb_3->setObjectName(QString::fromUtf8("Pb_3"));
        Pb_3->setGeometry(QRect(180, 180, 81, 81));
        Pb_0 = new QPushButton(NumberEdit);
        Pb_0->setObjectName(QString::fromUtf8("Pb_0"));
        Pb_0->setGeometry(QRect(270, 180, 81, 81));
        Le_Value = new QLineEdit(NumberEdit);
        Le_Value->setObjectName(QString::fromUtf8("Le_Value"));
        Le_Value->setGeometry(QRect(270, 10, 201, 61));
        Pb_Ok = new QPushButton(NumberEdit);
        Pb_Ok->setObjectName(QString::fromUtf8("Pb_Ok"));
        Pb_Ok->setGeometry(QRect(360, 180, 111, 81));
        Pb_Back = new QPushButton(NumberEdit);
        Pb_Back->setObjectName(QString::fromUtf8("Pb_Back"));
        Pb_Back->setGeometry(QRect(360, 90, 111, 81));
        Pb_ = new QPushButton(NumberEdit);
        Pb_->setObjectName(QString::fromUtf8("Pb_"));
        Pb_->setGeometry(QRect(270, 90, 81, 81));

        retranslateUi(NumberEdit);

        QMetaObject::connectSlotsByName(NumberEdit);
    } // setupUi

    void retranslateUi(QDialog *NumberEdit)
    {
        NumberEdit->setWindowTitle(QApplication::translate("NumberEdit", "Dialog", 0, QApplication::UnicodeUTF8));
        Pb_7->setText(QApplication::translate("NumberEdit", "7", 0, QApplication::UnicodeUTF8));
        Pb_8->setText(QApplication::translate("NumberEdit", "8", 0, QApplication::UnicodeUTF8));
        Pb_9->setText(QApplication::translate("NumberEdit", "9", 0, QApplication::UnicodeUTF8));
        Pb_5->setText(QApplication::translate("NumberEdit", "5", 0, QApplication::UnicodeUTF8));
        Pb_4->setText(QApplication::translate("NumberEdit", "4", 0, QApplication::UnicodeUTF8));
        Pb_6->setText(QApplication::translate("NumberEdit", "6", 0, QApplication::UnicodeUTF8));
        Pb_2->setText(QApplication::translate("NumberEdit", "2", 0, QApplication::UnicodeUTF8));
        Pb_1->setText(QApplication::translate("NumberEdit", "1", 0, QApplication::UnicodeUTF8));
        Pb_3->setText(QApplication::translate("NumberEdit", "3", 0, QApplication::UnicodeUTF8));
        Pb_0->setText(QApplication::translate("NumberEdit", "0", 0, QApplication::UnicodeUTF8));
        Pb_Ok->setText(QApplication::translate("NumberEdit", "Ok", 0, QApplication::UnicodeUTF8));
        Pb_Back->setText(QApplication::translate("NumberEdit", "<--", 0, QApplication::UnicodeUTF8));
        Pb_->setText(QApplication::translate("NumberEdit", ".", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NumberEdit: public Ui_NumberEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMBEREDIT_H

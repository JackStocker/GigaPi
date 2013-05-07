/********************************************************************************
** Form generated from reading UI file 'adjustments.ui'
**
** Created: Sun Apr 21 09:55:54 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTMENTS_H
#define UI_ADJUSTMENTS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Adjustments
{
public:
    QPushButton *Pb_Down;
    QPushButton *Pb_Right;
    QPushButton *Pb_Up;
    QPushButton *Pb_Left;
    QPushButton *Pb_Ok;
    QSpinBox *Sp_Delay;
    QLabel *label;
    QSpinBox *Sp_RotationDegrees;
    QLabel *label_2;
    QPushButton *Pb_Rotate;

    void setupUi(QDialog *Adjustments)
    {
        if (Adjustments->objectName().isEmpty())
            Adjustments->setObjectName(QString::fromUtf8("Adjustments"));
        Adjustments->resize(480, 272);
        QFont font;
        font.setPointSize(16);
        Adjustments->setFont(font);
        Pb_Down = new QPushButton(Adjustments);
        Pb_Down->setObjectName(QString::fromUtf8("Pb_Down"));
        Pb_Down->setGeometry(QRect(80, 190, 81, 81));
        Pb_Right = new QPushButton(Adjustments);
        Pb_Right->setObjectName(QString::fromUtf8("Pb_Right"));
        Pb_Right->setGeometry(QRect(160, 190, 81, 81));
        Pb_Up = new QPushButton(Adjustments);
        Pb_Up->setObjectName(QString::fromUtf8("Pb_Up"));
        Pb_Up->setGeometry(QRect(80, 110, 81, 81));
        Pb_Left = new QPushButton(Adjustments);
        Pb_Left->setObjectName(QString::fromUtf8("Pb_Left"));
        Pb_Left->setGeometry(QRect(0, 190, 81, 81));
        Pb_Ok = new QPushButton(Adjustments);
        Pb_Ok->setObjectName(QString::fromUtf8("Pb_Ok"));
        Pb_Ok->setGeometry(QRect(280, 190, 201, 81));
        Pb_Ok->setFont(font);
        Sp_Delay = new QSpinBox(Adjustments);
        Sp_Delay->setObjectName(QString::fromUtf8("Sp_Delay"));
        Sp_Delay->setGeometry(QRect(380, 0, 101, 71));
        Sp_Delay->setMinimum(1);
        Sp_Delay->setMaximum(50);
        Sp_Delay->setValue(3);
        label = new QLabel(Adjustments);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 0, 131, 71));
        label->setWordWrap(true);
        Sp_RotationDegrees = new QSpinBox(Adjustments);
        Sp_RotationDegrees->setObjectName(QString::fromUtf8("Sp_RotationDegrees"));
        Sp_RotationDegrees->setGeometry(QRect(130, 0, 101, 71));
        Sp_RotationDegrees->setMinimum(-360);
        Sp_RotationDegrees->setMaximum(360);
        Sp_RotationDegrees->setSingleStep(5);
        Sp_RotationDegrees->setValue(90);
        label_2 = new QLabel(Adjustments);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 131, 71));
        label_2->setWordWrap(true);
        Pb_Rotate = new QPushButton(Adjustments);
        Pb_Rotate->setObjectName(QString::fromUtf8("Pb_Rotate"));
        Pb_Rotate->setGeometry(QRect(280, 90, 201, 81));

        retranslateUi(Adjustments);

        QMetaObject::connectSlotsByName(Adjustments);
    } // setupUi

    void retranslateUi(QDialog *Adjustments)
    {
        Adjustments->setWindowTitle(QApplication::translate("Adjustments", "Dialog", 0, QApplication::UnicodeUTF8));
        Pb_Down->setText(QApplication::translate("Adjustments", "\\/", 0, QApplication::UnicodeUTF8));
        Pb_Right->setText(QApplication::translate("Adjustments", ">", 0, QApplication::UnicodeUTF8));
        Pb_Up->setText(QApplication::translate("Adjustments", "/\\", 0, QApplication::UnicodeUTF8));
        Pb_Left->setText(QApplication::translate("Adjustments", "<", 0, QApplication::UnicodeUTF8));
        Pb_Ok->setText(QApplication::translate("Adjustments", "Ok", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Adjustments", "Delay between steps (>=1)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Adjustments", "<html><head/><body><p>Degrees to rotate</p></body></html>", 0, QApplication::UnicodeUTF8));
        Pb_Rotate->setText(QApplication::translate("Adjustments", "Rotate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Adjustments: public Ui_Adjustments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTMENTS_H

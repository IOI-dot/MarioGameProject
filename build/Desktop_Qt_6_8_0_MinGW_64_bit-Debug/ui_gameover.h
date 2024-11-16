/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Gameover
{
public:

    void setupUi(QDialog *Gameover)
    {
        if (Gameover->objectName().isEmpty())
            Gameover->setObjectName("Gameover");
        Gameover->resize(400, 300);

        retranslateUi(Gameover);

        QMetaObject::connectSlotsByName(Gameover);
    } // setupUi

    void retranslateUi(QDialog *Gameover)
    {
        Gameover->setWindowTitle(QCoreApplication::translate("Gameover", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gameover: public Ui_Gameover {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H

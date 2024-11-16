/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_main
{
public:

    void setupUi(QDialog *main)
    {
        if (main->objectName().isEmpty())
            main->setObjectName("main");
        main->resize(400, 300);

        retranslateUi(main);

        QMetaObject::connectSlotsByName(main);
    } // setupUi

    void retranslateUi(QDialog *main)
    {
        main->setWindowTitle(QCoreApplication::translate("main", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main: public Ui_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H

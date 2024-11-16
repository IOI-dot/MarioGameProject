/********************************************************************************
** Form generated from reading UI file 'qmain.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMAIN_H
#define UI_QMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_qmain
{
public:

    void setupUi(QDialog *qmain)
    {
        if (qmain->objectName().isEmpty())
            qmain->setObjectName("qmain");
        qmain->resize(400, 300);

        retranslateUi(qmain);

        QMetaObject::connectSlotsByName(qmain);
    } // setupUi

    void retranslateUi(QDialog *qmain)
    {
        qmain->setWindowTitle(QCoreApplication::translate("qmain", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qmain: public Ui_qmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMAIN_H

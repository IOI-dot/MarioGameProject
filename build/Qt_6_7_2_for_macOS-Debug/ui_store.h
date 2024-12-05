/********************************************************************************
** Form generated from reading UI file 'store.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORE_H
#define UI_STORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Store
{
public:
    QWidget *widgetButtonImage;
    QPushButton *pushButtonBuyMushroom;
    QLabel *labelMushroomImage;
    QLabel *labelLifeImage;
    QWidget *widgetButtonImage_2;
    QPushButton *pushButtonBuyLife;

    void setupUi(QDialog *Store)
    {
        if (Store->objectName().isEmpty())
            Store->setObjectName("Store");
        Store->resize(741, 592);
        Store->setStyleSheet(QString::fromUtf8(""));
        widgetButtonImage = new QWidget(Store);
        widgetButtonImage->setObjectName("widgetButtonImage");
        widgetButtonImage->setGeometry(QRect(250, 220, 221, 81));
        widgetButtonImage->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/img/StoreButtonFinal.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: cover;\n"
"    border: none;"));
        pushButtonBuyMushroom = new QPushButton(widgetButtonImage);
        pushButtonBuyMushroom->setObjectName("pushButtonBuyMushroom");
        pushButtonBuyMushroom->setGeometry(QRect(30, 10, 171, 61));
        pushButtonBuyMushroom->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"    border: none;\n"
"color: White;"));
        labelMushroomImage = new QLabel(Store);
        labelMushroomImage->setObjectName("labelMushroomImage");
        labelMushroomImage->setGeometry(QRect(260, 100, 191, 121));
        labelMushroomImage->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/img/mushroom.png);"));
        labelMushroomImage->setPixmap(QPixmap(QString::fromUtf8(":/Resources/img/mushroom.png")));
        labelMushroomImage->setScaledContents(true);
        labelLifeImage = new QLabel(Store);
        labelLifeImage->setObjectName("labelLifeImage");
        labelLifeImage->setGeometry(QRect(260, 300, 201, 131));
        labelLifeImage->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/img/extralife.png);"));
        labelLifeImage->setPixmap(QPixmap(QString::fromUtf8(":/Resources/img/extralife.png")));
        labelLifeImage->setScaledContents(true);
        widgetButtonImage_2 = new QWidget(Store);
        widgetButtonImage_2->setObjectName("widgetButtonImage_2");
        widgetButtonImage_2->setGeometry(QRect(250, 420, 221, 81));
        widgetButtonImage_2->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/img/StoreButtonFinal.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: cover;\n"
"    border: none;"));
        pushButtonBuyLife = new QPushButton(widgetButtonImage_2);
        pushButtonBuyLife->setObjectName("pushButtonBuyLife");
        pushButtonBuyLife->setGeometry(QRect(20, 10, 171, 61));
        pushButtonBuyLife->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"    border: none;\n"
"color: White;"));

        retranslateUi(Store);

        QMetaObject::connectSlotsByName(Store);
    } // setupUi

    void retranslateUi(QDialog *Store)
    {
        Store->setWindowTitle(QCoreApplication::translate("Store", "Dialog", nullptr));
        pushButtonBuyMushroom->setText(QCoreApplication::translate("Store", "BUY MUSHROOM (500)", nullptr));
        labelMushroomImage->setText(QString());
        labelLifeImage->setText(QString());
        pushButtonBuyLife->setText(QCoreApplication::translate("Store", "BUY ExtraLife(1000)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Store: public Ui_Store {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORE_H

/********************************************************************************
** Form generated from reading UI file 'store.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
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

QT_BEGIN_NAMESPACE

class Ui_Store
{
public:
    QLabel *labelMushroomImage;
    QLabel *labelLifeImage;
    QLabel *labelBackground;
    QLabel *labelButtonImage;
    QPushButton *pushButtonBuyMushroom;
    QLabel *labelButtonImage_2;
    QPushButton *pushButtonBuyLife;
    QLabel *labelStoreSign;
    QLabel *labelButtonImage_3;
    QLabel *labelFireflowerImage;
    QPushButton *pushButtonBuyFireFlower;
    QLabel *labelButtonImage_4;
    QLabel *labelStarImage;
    QPushButton *pushButtonBuyStar;
    QLabel *labelScoreSign;
    QLabel *labelScoreText;
    QLabel *labelNextSign;
    QPushButton *pushButtonNext;

    void setupUi(QDialog *Store)
    {
        if (Store->objectName().isEmpty())
            Store->setObjectName("Store");
        Store->resize(743, 620);
        Store->setStyleSheet(QString::fromUtf8(""));
        labelMushroomImage = new QLabel(Store);
        labelMushroomImage->setObjectName("labelMushroomImage");
        labelMushroomImage->setGeometry(QRect(130, 110, 201, 131));
        labelMushroomImage->setStyleSheet(QString::fromUtf8(""));
        labelMushroomImage->setPixmap(QPixmap(QString::fromUtf8(":/Resources/img/MushroomFinal.png")));
        labelMushroomImage->setScaledContents(true);
        labelLifeImage = new QLabel(Store);
        labelLifeImage->setObjectName("labelLifeImage");
        labelLifeImage->setGeometry(QRect(380, 80, 231, 181));
        labelLifeImage->setStyleSheet(QString::fromUtf8(""));
        labelLifeImage->setPixmap(QPixmap(QString::fromUtf8(":/Resources/img/ExtraLifeFinal2.png")));
        labelLifeImage->setScaledContents(true);
        labelBackground = new QLabel(Store);
        labelBackground->setObjectName("labelBackground");
        labelBackground->setGeometry(QRect(0, 0, 741, 631));
        labelBackground->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/img/StoreBackgroundFinal.png);"));
        labelBackground->setPixmap(QPixmap(QString::fromUtf8(":/Resources/img/StoreFInal.png")));
        labelBackground->setScaledContents(true);
        labelBackground->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelButtonImage = new QLabel(Store);
        labelButtonImage->setObjectName("labelButtonImage");
        labelButtonImage->setGeometry(QRect(100, 210, 251, 151));
        labelButtonImage->setStyleSheet(QString::fromUtf8(""));
        labelButtonImage->setPixmap(QPixmap(QString::fromUtf8(":/Resources/img/StorebuttonFinal.png")));
        labelButtonImage->setScaledContents(true);
        pushButtonBuyMushroom = new QPushButton(Store);
        pushButtonBuyMushroom->setObjectName("pushButtonBuyMushroom");
        pushButtonBuyMushroom->setGeometry(QRect(150, 250, 171, 61));
        pushButtonBuyMushroom->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 700 15pt \"American Typewriter\";\n"
"    border: none;\n"
"color: White;"));
        labelButtonImage_2 = new QLabel(Store);
        labelButtonImage_2->setObjectName("labelButtonImage_2");
        labelButtonImage_2->setGeometry(QRect(370, 210, 251, 151));
        labelButtonImage_2->setStyleSheet(QString::fromUtf8(""));
        labelButtonImage_2->setPixmap(QPixmap(QString::fromUtf8(":/Resources/img/StorebuttonFinal.png")));
        labelButtonImage_2->setScaledContents(true);
        pushButtonBuyLife = new QPushButton(Store);
        pushButtonBuyLife->setObjectName("pushButtonBuyLife");
        pushButtonBuyLife->setGeometry(QRect(420, 250, 171, 61));
        pushButtonBuyLife->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 700 15pt \"American Typewriter\";\n"
"    border: none;\n"
"color: White;"));
        labelStoreSign = new QLabel(Store);
        labelStoreSign->setObjectName("labelStoreSign");
        labelStoreSign->setGeometry(QRect(210, -30, 311, 191));
        labelStoreSign->setPixmap(QPixmap(QString::fromUtf8(":/Resources/img/StoreSign.png")));
        labelStoreSign->setScaledContents(true);
        labelButtonImage_3 = new QLabel(Store);
        labelButtonImage_3->setObjectName("labelButtonImage_3");
        labelButtonImage_3->setGeometry(QRect(100, 420, 251, 151));
        labelButtonImage_3->setStyleSheet(QString::fromUtf8(""));
        labelButtonImage_3->setPixmap(QPixmap(QString::fromUtf8(":/Resources/img/StorebuttonFinal.png")));
        labelButtonImage_3->setScaledContents(true);
        labelFireflowerImage = new QLabel(Store);
        labelFireflowerImage->setObjectName("labelFireflowerImage");
        labelFireflowerImage->setGeometry(QRect(140, 320, 181, 141));
        labelFireflowerImage->setStyleSheet(QString::fromUtf8(""));
        labelFireflowerImage->setPixmap(QPixmap(QString::fromUtf8(":/Resources/img/FireflowerFinal.png")));
        labelFireflowerImage->setScaledContents(true);
        pushButtonBuyFireFlower = new QPushButton(Store);
        pushButtonBuyFireFlower->setObjectName("pushButtonBuyFireFlower");
        pushButtonBuyFireFlower->setGeometry(QRect(150, 460, 171, 61));
        pushButtonBuyFireFlower->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 700 15pt \"American Typewriter\";\n"
"    border: none;\n"
"color: White;"));
        labelButtonImage_4 = new QLabel(Store);
        labelButtonImage_4->setObjectName("labelButtonImage_4");
        labelButtonImage_4->setGeometry(QRect(370, 420, 251, 151));
        labelButtonImage_4->setStyleSheet(QString::fromUtf8(""));
        labelButtonImage_4->setPixmap(QPixmap(QString::fromUtf8(":/Resources/img/StorebuttonFinal.png")));
        labelButtonImage_4->setScaledContents(true);
        labelStarImage = new QLabel(Store);
        labelStarImage->setObjectName("labelStarImage");
        labelStarImage->setGeometry(QRect(410, 310, 181, 161));
        labelStarImage->setStyleSheet(QString::fromUtf8(""));
        labelStarImage->setPixmap(QPixmap(QString::fromUtf8(":/Resources/img/Star.png")));
        labelStarImage->setScaledContents(true);
        pushButtonBuyStar = new QPushButton(Store);
        pushButtonBuyStar->setObjectName("pushButtonBuyStar");
        pushButtonBuyStar->setGeometry(QRect(420, 460, 171, 61));
        pushButtonBuyStar->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 700 15pt \"American Typewriter\";\n"
"    border: none;\n"
"color: White;"));
        labelScoreSign = new QLabel(Store);
        labelScoreSign->setObjectName("labelScoreSign");
        labelScoreSign->setGeometry(QRect(80, 0, 191, 101));
        labelScoreSign->setStyleSheet(QString::fromUtf8(""));
        labelScoreSign->setPixmap(QPixmap(QString::fromUtf8(":/Resources/img/StorebuttonFinal.png")));
        labelScoreSign->setScaledContents(true);
        labelScoreText = new QLabel(Store);
        labelScoreText->setObjectName("labelScoreText");
        labelScoreText->setGeometry(QRect(130, 30, 101, 31));
        labelScoreText->setStyleSheet(QString::fromUtf8("font: 700 15pt \"American Typewriter\";\n"
"color: white;"));
        labelNextSign = new QLabel(Store);
        labelNextSign->setObjectName("labelNextSign");
        labelNextSign->setGeometry(QRect(420, 500, 241, 121));
        labelNextSign->setStyleSheet(QString::fromUtf8(""));
        labelNextSign->setPixmap(QPixmap(QString::fromUtf8(":/Resources/img/NextButton.png")));
        labelNextSign->setScaledContents(true);
        pushButtonNext = new QPushButton(Store);
        pushButtonNext->setObjectName("pushButtonNext");
        pushButtonNext->setGeometry(QRect(470, 540, 151, 51));
        pushButtonNext->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 700 15pt \"American Typewriter\";\n"
"    border: none;\n"
"color: White;"));
        labelBackground->raise();
        labelMushroomImage->raise();
        labelLifeImage->raise();
        labelButtonImage->raise();
        pushButtonBuyMushroom->raise();
        labelButtonImage_2->raise();
        pushButtonBuyLife->raise();
        labelStoreSign->raise();
        labelButtonImage_3->raise();
        labelFireflowerImage->raise();
        pushButtonBuyFireFlower->raise();
        labelButtonImage_4->raise();
        labelStarImage->raise();
        pushButtonBuyStar->raise();
        labelScoreSign->raise();
        labelScoreText->raise();
        labelNextSign->raise();
        pushButtonNext->raise();

        retranslateUi(Store);

        QMetaObject::connectSlotsByName(Store);
    } // setupUi

    void retranslateUi(QDialog *Store)
    {
        Store->setWindowTitle(QCoreApplication::translate("Store", "Dialog", nullptr));
        labelMushroomImage->setText(QString());
        labelLifeImage->setText(QString());
        labelBackground->setText(QString());
        labelButtonImage->setText(QString());
        pushButtonBuyMushroom->setText(QCoreApplication::translate("Store", "Buy Mushroom (500)", nullptr));
        labelButtonImage_2->setText(QString());
        pushButtonBuyLife->setText(QCoreApplication::translate("Store", "Buy Extra Life (1000)", nullptr));
        labelStoreSign->setText(QString());
        labelButtonImage_3->setText(QString());
        labelFireflowerImage->setText(QString());
        pushButtonBuyFireFlower->setText(QCoreApplication::translate("Store", "Buy Fireflower (500)", nullptr));
        labelButtonImage_4->setText(QString());
        labelStarImage->setText(QString());
        pushButtonBuyStar->setText(QCoreApplication::translate("Store", "Buy Star (500)", nullptr));
        labelScoreSign->setText(QString());
        labelScoreText->setText(QString());
        labelNextSign->setText(QString());
        pushButtonNext->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Store: public Ui_Store {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORE_H

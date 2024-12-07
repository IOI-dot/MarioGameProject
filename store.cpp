#include "store.h"
#include "ui_store.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "level3.h"

Store::Store(Level3 *level, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Store) , Level(level)
{
    ui->setupUi(this);
    ui->labelScoreText->setText("Score: " + QString::number(Level->getScore()));
}

Store::~Store()
{
    delete ui;
}



void Store::on_pushButtonBuyMushroom_clicked()
{
    if (Level->getScore() >= 500)
    {
        Level->decreaseScore(500);
        //mushrrom implementation
        ui->labelScoreText->setText("Score: " + QString::number(Level->getScore()));
        QMessageBox::warning(this, "Successful", "You have successfully purchased a mushroom!");

    }
    else
    {
        // Display a message box indicating insufficient score
        QMessageBox::warning(this, "Insufficient Score", "Transaction failed, you need at least a score of 500 to buy a mushroom!");
    }
}



void Store::on_pushButtonBuyFireFlower_clicked()
{
    if (Level->getScore() >= 500)
    {
        Level->decreaseScore(500);
        //Fire flower implementation
        ui->labelScoreText->setText("Score: " + QString::number(Level->getScore()));
        QMessageBox::warning(this, "Successful", "You have successfully purchased a FireFlower!");

    }
    else
    {
        // Display a message box indicating insufficient score
        QMessageBox::warning(this, "Insufficient Score", "Transaction failed, you need at least a score of 500 to buy a FireFlower!");
    }
}


void Store::on_pushButtonBuyLife_clicked()
{
    if (Level->getScore() >= 1000)
    {
        Level->decreaseScore(1000);
        //Extra life implementation
        ui->labelScoreText->setText("Score: " + QString::number(Level->getScore()));
        QMessageBox::warning(this, "Successful", "You have successfully purchased an extra life!");

    }
    else
    {
        // Display a message box indicating insufficient score
        QMessageBox::warning(this, "Insufficient Score", "Transaction failed, you need at least a score of 1000 to buy an extra life!");
    }
}


void Store::on_pushButtonBuyStar_clicked()
{
    if (Level->getScore() >= 500)
    {
        Level->decreaseScore(500);
        //Star implementation
        ui->labelScoreText->setText("Score: " + QString::number(Level->getScore()));
        QMessageBox::warning(this, "Successful", "You have successfully purchased a Star!");

    }
    else
    {
        // Display a message box indicating insufficient score
        QMessageBox::warning(this, "Insufficient Score", "Transaction failed, you need at least a score of 500 to buy a Star!");
    }
}


void Store::on_pushButtonNext_clicked()
{
    this->close();
}


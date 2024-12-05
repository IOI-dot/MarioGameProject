#include "store.h"
#include "ui_store.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "level1.h"

Store::Store(Level1 *level, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Store) , Level(level)
{
    ui->setupUi(this);
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
    }

}


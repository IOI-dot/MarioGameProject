#include "store.h"
#include "ui_store.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Store::Store(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Store)
{
    ui->setupUi(this);
}

Store::~Store()
{
    delete ui;
}




#include "store.h"
#include "ui_store.h"

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

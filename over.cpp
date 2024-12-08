#include "over.h"
#include "ui_over.h"

OVER::OVER(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OVER)
{
    ui->setupUi(this);
}

OVER::~OVER()
{
    delete ui;
}

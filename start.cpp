#include "start.h"
#include "ui_start.h"

START::START(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::START)
{
    ui->setupUi(this);
}

START::~START()
{
    delete ui;
}

void START::on_pushButtonLev1_clicked()
{
    LevelManager *manager = new LevelManager();
     manager->startLevel1();
    manager->show();  // Display the LevelManager window
    this->close();    // Close the current StartGame window
}

void START::on_pushButtonLev2_clicked()
{
    LevelManager *manager = new LevelManager();
    manager->startLevel2(0);
    manager->show();  // Display the LevelManager window

    this->close();
}


void START::on_pushButtonLev3_clicked()
{
    LevelManager *manager = new LevelManager();
    manager->startLevel3(0);
    manager->show();  // Display the LevelManager window

    this->close();
}


void START::on_pushButtonLev4_clicked()
{
    LevelManager *manager = new LevelManager();
    manager->startLevel4(0);
    manager->show();  // Display the LevelManager window

    this->close();
}


void START::on_pushButtonLev5_clicked()
{
    LevelManager *manager = new LevelManager();
    manager->startLevel5(0);
    manager->show();  // Display the LevelManager window

    this->close();
}

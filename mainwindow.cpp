#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include "Level1.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    Level1 *level1 = new Level1();  // Create Level1 widget
    mainWindow.setCentralWidget(level1);
    mainWindow.show();
    return app.exec();
}

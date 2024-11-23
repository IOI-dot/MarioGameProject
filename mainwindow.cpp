#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    gameLevel = new Level1(this);  // Create an instance of Level1
    setCentralWidget(gameLevel);   // Set the game window (Level1) as the central widget
}

MainWindow::~MainWindow()
{
    delete gameLevel;  // Clean up the game window
}

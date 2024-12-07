#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Super Mario Game");

    // Initialize the LevelManager
    levelManager = new LevelManager(this);

    // Set the LevelManager as the central widget
    setCentralWidget(levelManager);
}

MainWindow::~MainWindow()
{
    delete levelManager;  // Clean up LevelManager
}

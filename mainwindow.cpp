#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), levelManager(new LevelManager(this))
{
    setCentralWidget(levelManager);
    resize(800, 600);
    setWindowTitle("Mario Game");
}

MainWindow::~MainWindow()
{
    // `levelManager` will be automatically deleted as its parent is the MainWindow
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Level1.h" // Include Level1

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Level1 *gameLevel;  // Pointer to the Level1 class or game window
};

#endif // MAINWINDOW_H

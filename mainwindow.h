#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Level1.h" // Include Level1
#include "gameover.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startGame();  // Slot to start the game

private:
    StartGame *startScreen;  // Start screen widget
    Level1 *gameLevel;      // The main game widget
};

private slots:
    void onGameOver();  // Slot to show the Game Over screen
private:
    Level1 *gameLevel;  // Pointer to the Level1 class or game window
    Ui::MainWindow *ui;
    GameOver *gameOverScreen;  // Pointer to the GameOver widget
};

#endif // MAINWINDOW_H

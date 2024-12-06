#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>


namespace Ui {
class GameOver;  //  declaration of the UI class
}

class GameOver : public QWidget
{
    Q_OBJECT

public:
     GameOver(QWidget *parent = nullptr);  // Constructor
    ~GameOver();

 signals:
     void backToStartScreen(); // Signal to go back to start screen

private slots:
    void onRestartButtonClicked();  // Slot for the restart button
    void onExitButtonClicked();  // Slot for the exit button

private:
    Ui::GameOver *ui;  // Pointer to the UI object
    QLabel *gameOverImageLabel;  // Label for the game over image
    QPushButton *restartButton;  // Button to restart the game
    QPushButton *exitButton;  // Button to exit the game

};

#endif // GAMEOVER_H

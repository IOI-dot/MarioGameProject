#ifndef STARTGAME_H
#define STARTGAME_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class StartGame;
}

class StartGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartGame(QWidget *parent = nullptr);
    ~StartGame();

private slots:
    void onStartButtonClicked();  // Declare the slot for the start button click

private:
    Ui::StartGame *ui;  // Pointer to the UI object
};

#endif // STARTGAME_H

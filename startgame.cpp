#include "startgame.h"
#include "ui_startgame.h"
#include <QPixmap>
#include <QMessageBox>

StartGame::StartGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartGame)  // Initialize the UI object
{
    ui->setupUi(this);  // Set up the UI from the .ui file

    // Set the background image for the "startimage" QLabel
    QPixmap pixmap(":/resources/super_mario_5.webp");
    ui->startimage->setPixmap(pixmap);  // Set the image in the label
    ui->startimage->setScaledContents(true);  // Ensure the image scales within the label

    // Connect the start button click to the onStartButtonClicked slot
    connect(ui->startbutton, &QPushButton::clicked, this, &StartGame::onStartButtonClicked);
}

StartGame::~StartGame()
{
    delete ui;  // Clean up the UI object when the window is destroyed
}

// Slot that is called when the start button is clicked
void StartGame::onStartButtonClicked()
{
    // Show a message box indicating the game is starting
    QMessageBox::information(this, "Game Started", "Starting the game...");


}

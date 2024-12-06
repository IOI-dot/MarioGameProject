#include "gameover.h"
#include "ui_gameover.h"  // Automatically generated UI header
#include <QMessageBox>
#include <QPixmap>  // For QPixmap to load the image

// Constructor
GameOver::GameOver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOver)  // Initialize the UI
{
    ui->setupUi(this);  // Set up the UI components

    // Create QLabel to show the "Game Over" image
    gameOverImageLabel = new QLabel(this);
    QPixmap pixmap(":/images/Super_Mario_Bros._2_-_NES_-_Game_Over.png");  // Path to your game over image
    gameOverImageLabel->setPixmap(pixmap);
    gameOverImageLabel->setAlignment(Qt::AlignCenter);  // Center the image

    // Create restart and exit buttons
    restartButton = new QPushButton("Restart", this);
    exitButton = new QPushButton("Exit", this);

    // Create the layout and add widgets
    layout = new QVBoxLayout(this);
    layout->addWidget(gameOverImageLabel);  // Add the game over image
    layout->addWidget(restartButton);  // Add the restart button
    layout->addWidget(exitButton);  // Add the exit button

    // Connect buttons to respective slots
    connect(restartButton, &QPushButton::clicked, this, &GameOver::onRestartButtonClicked);
    connect(exitButton, &QPushButton::clicked, this, &GameOver::onExitButtonClicked);
}

// Destructor
GameOver::~GameOver()
{
    delete ui;
}


void GameOver::onRestartButtonClicked()
{
    emit backToStartScreen();
}

// exit the game
void GameOver::onExitButtonClicked()
{
    QApplication::quit();  // Exit the application
}

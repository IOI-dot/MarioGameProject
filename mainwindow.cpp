#include "mainwindow.h"
#include "startgame.h"
#include "gameover.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    gameLevel = new Level1(this);  // Create an instance of Level1
    setCentralWidget(gameLevel);   // Set the game window (Level1) as the central widget
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    startScreen(new StartGame(this)),  // Create the start screen
    gameLevel(nullptr)  // Initialize gameLevel to null
{
    setWindowTitle("Super Mario Game");

    // Set the start screen as the central widget initially
    setCentralWidget(startScreen);

    // Connect the start button signal to start the game
    connect(startScreen, &StartGame::startGameClicked, this, &MainWindow::startGame);
}

MainWindow::~MainWindow()
{
    delete startScreen;
    delete gameLevel;  // Clean up the game window
    delete gameOverScreen;

}

void MainWindow::startGame()
{
    gameLevel = new Level1(this);  // Create the game screen
    setCentralWidget(gameLevel);   // Set gameLevel as the central widget
    }
void MainWindow::showGameOverScreen()
{
    // Create and display the GameOver window
    GameOver *gameOverScreen = new GameOver(this);  // Create new GameOver
    gameOverScreen->show();  // Show the GameOver window
}

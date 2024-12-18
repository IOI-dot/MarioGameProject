#include "Level2.h"
#include "Player.h"
#include "Obstacle.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QPixmap>
#include <QBrush>
#include <QTimer>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>
#include "coins.h"
#include "goomba.h"
#include "turtle.h"

// Constructor
Level2::Level2(QWidget *parent)
    : QWidget(parent), scene(nullptr), view(nullptr), player(nullptr), ground(nullptr), castle(nullptr), score(0), level(2)
{
    initLevel();
}

// Destructor
Level2::~Level2()
{
    delete scene;
    delete view;
    delete player;
    delete gameTimer;
    delete ground;
    delete musicPlayer;
    delete audioOutput;
    for (auto obstacle : obstacles)
        delete obstacle;

}

int Level2::getScore()
{
    return score;
}

void Level2::decreaseScore(int amount)
{
    score -= amount;
}
void Level2::setScore(int newScore)
{
    score = newScore;
    scoreLabel->setText("Score: " + QString::number(score));  // Update the score display
}
void Level2::initLevel()
{
    this->setWindowTitle("Level 2");
    this->resize(800, 600);

    // Set up the scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 3000, 600); // Extended level width

    // Set the background image for the scene
    QPixmap backgroundPixmap(":/Resources/img/Background2.png");
    QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem();
    backgroundItem->setPixmap(backgroundPixmap.scaled(3000, 600));
    backgroundItem->setPos(0, 0);
    backgroundItem->setZValue(-10); // Ensure background is behind other objects
    scene->addItem(backgroundItem);

    // Set up the view
    view = new QGraphicsView(scene, this);
    view->setFixedSize(800, 600);

    // Add player to the scene
    player = new Player();
    player->setPos(100, 360); // Place player on the ground
    player->setFocus();
    player->setZValue(4);
    scene->addItem(player);
    // Set up the game timer
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &Level2::updateGame);
    gameTimer->start(16); // ~60 FPS (16 ms per frame)

    // Add obstacles to the scene
    for (int i = 0; i < 7; ++i)
    {
        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 375);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene
    for (int i = 0; i < 7; ++i)
    {
        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 420);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene
    for (int i = 0; i < 7; ++i)
    {
        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 465);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene
    for (int i = 0; i < 7; ++i)
    {
        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 510);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene
    for (int i = 0; i < 80; ++i)
    {
        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 555);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene
    for (int i = 0; i < 80; ++i)
    {
        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 50);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene
    for (int i = 0; i < 9; ++i)
    {
        float xPos = 550+i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 375);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene
    for (int i = 0; i < 9; ++i)
    {
        float xPos = 1200+i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 375);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene
    for (int i = 0; i < 9; ++i)
    {
        float xPos = 1850+i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 375);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    for (int i = 0; i < 9; ++i)
    {
        float xPos = 2500+i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 375);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    for (int i = 0; i < 9; ++i)
    {
        float xPos = 550 + i*50; // Spread coins horizontally
        float yPos = 315;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }
    for (int i = 0; i < 9; ++i)
    {
        float xPos = 1200 + i*50; // Spread coins horizontally
        float yPos = 315;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }
    for (int i = 0; i < 9; ++i)
    {
        float xPos = 1850 + i*50; // Spread coins horizontally
        float yPos = 315;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }
    for (int i = 0; i < 9; ++i)
    {
        float xPos = 2500 + i*50; // Spread coins horizontally
        float yPos = 315;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }
    // Add the castle at the end of the level
    castle = new QGraphicsPixmapItem();
    QPixmap castleImage(":/Resources/img/castle2.png");
    castleImage = castleImage.scaled(150, 150);
    castle->setPixmap(castleImage);
    castle->setPos(2800, 228); // Position the castle at the far right
    castle->setZValue(0); // Ensure the castle is rendered in front of the background
    scene->addItem(castle);
    // Add Turtles to the scene
    for (int i = 0; i < 3; ++i)
    {
        float xPos = 600 + i * 500;  // Spread Turtles horizontally
        float yPos = 515;  // Place them on the ground
        Turtle *turtle = new Turtle(":/Resources/img/turtle-walk-0.png",
                                    ":/Resources/img/turtle-walk-1.png",
                                    ":/Resources/img/turtle-turtleback-0.png",
                                    xPos, yPos, 530);  // Maximum 300px movement in either direction
        scene->addItem(turtle);

        // Connect the game timer to update the Turtle
        connect(gameTimer, &QTimer::timeout, [turtle, player = this->player]() {
            turtle->update(player);
        });
    }
    // Add Turtles to the scene
    for (int i = 0; i < 6; ++i)
    {
        float xPos = 1500 + i * 500;  // Spread Turtles horizontally
        float yPos = 515;  // Place them on the ground
        Turtle *turtle = new Turtle(":/Resources/img/turtle-walk-0.png",
                                    ":/Resources/img/turtle-walk-1.png",
                                    ":/Resources/img/turtle-turtleback-0.png",
                                    xPos, yPos, 530);  // Maximum 300px movement in either direction
        scene->addItem(turtle);

        // Connect the game timer to update the Turtle
        connect(gameTimer, &QTimer::timeout, [turtle, player = this->player]() {
            turtle->update(player);
        });
    }
    lives = 3;  // Start with 3 lives

    // Initialize the lives label
    livesLabel = new QLabel("Lives: " + QString::number(lives), this);
    livesLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
    // Set up the score and level labels
    scoreLabel = new QLabel("Score: " + QString::number(score), this);
    qDebug()<<score;
    levelLabel = new QLabel("Level: 2", this);

    levelLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
    scoreLabel->setStyleSheet("font-size: 16px; font-weight: bold;");

    QHBoxLayout *labelLayout = new QHBoxLayout();
    labelLayout->addWidget(levelLabel);
    labelLayout->addWidget(scoreLabel);
    labelLayout->addWidget(livesLabel);  // Add lives label here
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(labelLayout);
    mainLayout->addWidget(view);

    this->setLayout(mainLayout);
    //Initialize the Game Over image
            gameOverImage = new QGraphicsPixmapItem();
    QPixmap gameOverPixmap(":/Resources/img/Super_Mario_Bros._2_-_NES_-_Game_Over.png");
    gameOverImage->setPixmap(gameOverPixmap.scaled(this->size(), Qt::KeepAspectRatio));
    gameOverImage->setPos(0, 0);
    gameOverImage->setZValue(100);  // Make sure it's on top
    gameOverImage->setVisible(false);  // Initially hidden
    scene->addItem(gameOverImage);

    // Initialize the media player for background music
    musicPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);

    // Set up the audio output
    musicPlayer->setAudioOutput(audioOutput);
    musicPlayer->setSource(QUrl("qrc:/sounds/02. Underground Theme.mp3"));
    audioOutput->setVolume(50);

    // Start playing the music when the game starts
    musicPlayer->play();
}

void Level2::startGame()
{
    scoreLabel->setText("Score: " + QString::number(score));
    gameTimer->start(16); // ~60 FPS (16 ms per frame)
    musicPlayer->play();
}

void Level2::keyPressEvent(QKeyEvent *event)
{
    if (player)
    {
        player->keyPressEvent(event);
    }
}

void Level2::keyReleaseEvent(QKeyEvent *event)
{
    if (player)
    {
        player->keyReleaseEvent(event);
    }
}

void Level2::updateGame()
{
    player->updatePosition(); // Apply gravity and jump mechanics

    // Center the view on the player as they move
    view->centerOn(player);

    // Collision detection with obstacles
    for (auto obstacle : obstacles)
    {
        if (player->collidesWithItem(obstacle))
        {
            player->stopMovement(); // Stop movement if player hits an obstacle
            break;
        }
    }
    // Collision detection with coins
    for (int i = 0; i < coins.size(); ++i)
    {
        if (player->collidesWithItem(coins[i]))
        {
            // Increase the score and remove the coin
            score += 100;
            scoreLabel->setText("Score: " + QString::number(score));

            // Remove the coin from the scene and list
            scene->removeItem(coins[i]);
            delete coins[i];
            coins.removeAt(i);
            --i; // Adjust index due to removal
        }
    }
    if (player->x() + player->boundingRect().width() / 2 >= castle->x() + castle->boundingRect().width() / 2)
    {
        // Stop the game
        musicPlayer->stop();
        gameTimer->stop();
        player->hide();

        // Show a victory message
        QMessageBox::information(this, "You Won!", "Congratulations Mario, you have completed the level!");
        emit level2Completed(score);
    }
}
void Level2::endGame()
{
    // Stop the game timer and music
    musicPlayer->stop();
    musicPlayer->setSource(QUrl("qrc:/sounds/08. Lost a Life.mp3"));
    musicPlayer->play();
    gameTimer->stop();
    // Hide the player
    player->hide();
    for (auto obstacle : obstacles) obstacle->setVisible(false);  // Hide obstacles
    for (auto coin : coins) coin->setVisible(false);  // Hide coins
    for (auto enemy : scene->items())  // Hide all enemies (Turtles, Goombas, etc.)
    {
        if (dynamic_cast<Turtle*>(enemy) || dynamic_cast<Goomba*>(enemy)) {
            enemy->setVisible(false);
        }
    }
    // Hide the background image
    QGraphicsPixmapItem* backgroundItem = nullptr;
    for (auto item : scene->items()) {
        backgroundItem = dynamic_cast<QGraphicsPixmapItem*>(item);
        if (backgroundItem) {
            backgroundItem->setVisible(false);
            break;
        }
    }
    // Show the Game Over image
    gameOverImage->setZValue(600);
    gameOverImage->setVisible(true);
    view->centerOn(100, 360);

}

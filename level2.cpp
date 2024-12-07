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
    // Set up the score and level labels
    scoreLabel = new QLabel("Score: 0", this);
    levelLabel = new QLabel("Level: 2", this);

    scoreLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
    levelLabel->setStyleSheet("font-size: 16px; font-weight: bold;");

    QHBoxLayout *labelLayout = new QHBoxLayout();
    labelLayout->addWidget(levelLabel);
    labelLayout->addWidget(scoreLabel);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(labelLayout);
    mainLayout->addWidget(view);

    this->setLayout(mainLayout);


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
    score = 0;
    scoreLabel->setText("Score: 0");
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
        emit level2Completed();
    }
}

#include "Level1.h"
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

// Constructor
Level1::Level1(QWidget *parent)
    : QWidget(parent), scene(nullptr), view(nullptr), player(nullptr), ground(nullptr), castle(nullptr), score(0), level(1)
{
    initLevel();
}

// Destructor
Level1::~Level1()
{
    delete scene;
    delete view;
    delete player;
    delete gameTimer;
    delete ground;
    delete musicPlayer;  // Clean up the music player
    delete audioOutput;  // Clean up the audio output
    for (auto obstacle : obstacles)
        delete obstacle;
}

void Level1::initLevel()
{
    this->setWindowTitle("Level 1");
    this->resize(800, 600);

    // Set up the scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);

    // Set the background image for the scene
    QPixmap backgroundPixmap("C:/Users/Merna/Downloads/sky.png");
    QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem();
    backgroundItem->setPixmap(backgroundPixmap.scaled(800, 600));
    backgroundItem->setPos(0, 0); // Position the background
    scene->addItem(backgroundItem);

    // Set up the ground (floor)
    ground = new QGraphicsRectItem(0, 550, 800, 50); // Ground rectangle (position and size)
    ground->setBrush(Qt::darkGreen);                 // Ground color (can be textured later)
    ground->setZValue(1);                            // Ensure ground is above background
    scene->addItem(ground);

    // Set up the view
    view = new QGraphicsView(scene, this);
    view->setFixedSize(800, 600);

    // Add player to the scene
    player = new Player();
    player->setPos(100, 420); // Place player on the ground
    player->setFocus();
    scene->addItem(player);

    // Add obstacles to the scene
    for (int i = 0; i < 20; ++i)
    {
        float xPos = i * 50; // Spread out obstacles
        Obstacle *obstacle = new Obstacle("C:/Users/Merna/Downloads/blocks.jpg", xPos, 480);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene
    for (int i = 0; i < 20; ++i)
    {
        float xPos = i * 50; // Spread out obstacles
        Obstacle *obstacle = new Obstacle("C:/Users/Merna/Downloads/blocks.jpg", xPos, 530);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene
    for (int i = 0; i < 5; ++i)
    {
        float xPos = 150+ i * 50; // Spread out obstacles
        Obstacle *obstacle = new Obstacle("C:/Users/Merna/Downloads/blocks.jpg", xPos, 300);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add the castle at the end of the level
    castle = new QGraphicsPixmapItem();
    QPixmap castleImage("C:/Users/Merna/Downloads/CASLE.png");
    castleImage = castleImage.scaled(150, 150); // Resize castle image to appropriate size
    castle->setPixmap(castleImage);
    castle->setPos(650, 330);  // Position the castle at the end of the level
    scene->addItem(castle);

    // Set up the score and level labels
    scoreLabel = new QLabel("Score: 0", this);
    levelLabel = new QLabel("Level: 1", this);

    scoreLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
    levelLabel->setStyleSheet("font-size: 16px; font-weight: bold;");

    QHBoxLayout *labelLayout = new QHBoxLayout();
    labelLayout->addWidget(levelLabel);
    labelLayout->addWidget(scoreLabel);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(labelLayout);
    mainLayout->addWidget(view);

    this->setLayout(mainLayout);

    // Set up the game timer
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &Level1::updateGame);
    gameTimer->start(16);  // ~60 FPS (16 ms per frame)

    // Initialize the media player for background music
    musicPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);

    // Set up the audio output
    musicPlayer->setAudioOutput(audioOutput);
    musicPlayer->setSource(QUrl::fromLocalFile("C:/Users/Merna/Downloads/01. Ground Theme.mp3"));  // Replace with the correct path
    audioOutput->setVolume(50);  // Set volume to 50%

    // Start playing the music when the game starts
    musicPlayer->play();
}

// Starts the game
void Level1::startGame()
{
    score = 0;
    scoreLabel->setText("Score: 0");
    gameTimer->start(16); // ~60 FPS (16 ms per frame)

    // Start playing the music when the game starts
    musicPlayer->play();
}

// Handles key press events
void Level1::keyPressEvent(QKeyEvent *event)
{
    if (player)
    {
        player->keyPressEvent(event);
    }
}

// Handles key release events
void Level1::keyReleaseEvent(QKeyEvent *event)
{
    if (player)
    {
        player->keyReleaseEvent(event);
    }
}

void Level1::updateGame()
{
    player->updatePosition(); // Apply gravity and jump mechanics

    // Ensure the player doesn’t fall below the ground
    if (player->collidesWithItem(ground))
    {
        // Correct Mario's position if he collides with the ground
        player->landOn(ground->y() - player->boundingRect().height());
    }

    // Collision detection with obstacles
    for (auto obstacle : obstacles)
    {
        if (player->collidesWithItem(obstacle))
        {
            player->stopMovement(); // Stop movement if player hits an obstacle
            break;
        }
    }

    // Check if Mario reaches the center of the castle (end of level)
    if (player->x() + player->boundingRect().width() / 2 >= castle->x() + castle->boundingRect().width() / 2)
    {
        // Show the message box when Mario reaches the castle
        QMessageBox::information(this, "You Won!", "Congratulations Mario, you have completed the level!");


        musicPlayer->stop();

        gameTimer->stop();
    }

    // Update score dynamically
    score += 1;
    scoreLabel->setText("Score: " + QString::number(score));
}

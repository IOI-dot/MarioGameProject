#include "Level1.h"
#include "player.h"
#include "obstacle.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QBrush>
#include <QGraphicsRectItem>

// Constructor
Level1::Level1(QWidget *parent)
    : QWidget(parent), scene(nullptr), view(nullptr), player(nullptr), score(0), level(1)
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
    for (auto obstacle : obstacles)
        delete obstacle;
}

// Initializes the level
void Level1::initLevel()
{
    this->setWindowTitle("Level 1");
    this->resize(800, 600);

    // Set up the scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);

    // Set the background image for the scene
    QPixmap backgroundPixmap("C:/Users/Merna/Downloads/sky.png"); // Adjust the path to image
    QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem();
    backgroundItem->setPixmap(backgroundPixmap);
    backgroundItem->setPos(0, 0); // Position the background
    scene->addItem(backgroundItem);

    // Set up the view
    view = new QGraphicsView(scene, this);
    view->setFixedSize(800, 600);

    // Add player to the scene
    player = new Player();
    player->setPos(100, 500); // Set initial position
    scene->addItem(player);

    // Add obstacles to the scene
    for (int i = 0; i < 5; ++i)
    {
        Obstacle *obstacle = new Obstacle();
        obstacle->setPos(200 + i * 120, 500); // Spread obstacles across the scene
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }

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
}

// Starts the game
void Level1::startGame()
{
    score = 0;
    scoreLabel->setText("Score: 0");
    gameTimer->start(16); // ~60 FPS (16 ms per frame)
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

// Updates the game state
void Level1::updateGame()
{
    // Update player position and check collisions
    player->updatePosition();

    for (auto obstacle : obstacles)
    {
        if (player->collidesWithItem(obstacle))
        {
            //FADY
        }
    }


    // Increase score as the game progresses
    score += 1;
    scoreLabel->setText("Score: " + QString::number(score));

}

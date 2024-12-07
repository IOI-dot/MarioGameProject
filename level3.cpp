#include "Level3.h"
#include "Player.h"
#include "Obstacle.h"
#include "Coins.h"
#include "Turtle.h"
#include "goomba.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPixmap>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include <QUrl>
#include "piranha.h"
#include <QRandomGenerator>
#include "store.h"

// Constructor
Level3::Level3(QWidget *parent)
    : QWidget(parent), scene(nullptr), view(nullptr), player(nullptr), score(0), level(3)
{
    initLevel();
}

// Destructor
Level3::~Level3()
{
    delete scene;
    delete view;
    delete player;
    delete gameTimer;
    delete musicPlayer;
    delete audioOutput;
    for (auto obstacle : obstacles)
        delete obstacle;
}

int Level3::getScore()
{
    return score;
}

void Level3::decreaseScore(int amount)
{
    score -= amount;
}

void Level3::initLevel()
{
    this->setWindowTitle("Level 3");
    this->resize(800, 600);

    // Set up the scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 3000, 600); // Extended level width

    // Set the background image for the scene
    QPixmap backgroundPixmap(":/Resources/img/sky.png");
    QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem();
    backgroundItem->setPixmap(backgroundPixmap.scaled(3000, 600));
    backgroundItem->setPos(0, 0);
    backgroundItem->setZValue(-10);
    scene->addItem(backgroundItem);

    // Set up the view
    view = new QGraphicsView(scene, this);
    view->setFixedSize(800, 600);

    // Add player to the scene
    player = new Player();
    player->setPos(100, 420);
    player->setFocus();
    player->setZValue(4);
    scene->addItem(player);
    oldcastle=new QGraphicsPixmapItem();
    QPixmap oldcastleImage(":/Resources/img/castle.png");
    oldcastleImage = oldcastleImage.scaled(150, 150);
    oldcastle->setPixmap(oldcastleImage);
    oldcastle->setPos(100, 420); // Position the castle at the far right
    oldcastle->setZValue(0); // Ensure the castle is rendered in front of the background
    scene->addItem(oldcastle);
    // Add the castle at the end of the level
    castle = new QGraphicsPixmapItem();
    QPixmap castleImage(":/Resources/img/castle.png");
    castleImage = castleImage.scaled(150, 150);
    castle->setPixmap(castleImage);
    castle->setPos(2800, 420); // Position the castle at the far right
    castle->setZValue(0); // Ensure the castle is rendered in front of the background

    // Set up the game timer
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &Level3::updateGame);
    gameTimer->start(16); // ~60 FPS (16 ms per frame)

    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 80; ++i)
    {
        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick2.bmp", xPos, 555);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 4; ++i)
    {
        float xPos = 2550+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 410);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 4; ++i)
    {
        float xPos = 2650+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 310);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 4; ++i)
    {
        float xPos = 2750+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 240);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 4; ++i)
    {
        float xPos = 2850+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 150);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 4; ++i)
    {
        float xPos = 3000+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 115);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add Turtles to the scene
    for (int i = 0; i < 6; ++i)
    {
        float xPos = 1200 + i * 500;  // Spread Turtles horizontally
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

    // Add Goombas to the scene (Group 2)
    for (int i = 0; i < 4; ++i)
    {
        float xPos = 400 + i * 400;
        float yPos = 515;  // Place them on the ground
        Goomba *goomba = new Goomba(":/Resources/img/goomba-0.png",
                                    ":/Resources/img/goomba-dead.png",
                                    xPos, yPos, 300);  // Maximum 300px movement in either direction
        scene->addItem(goomba);

        // Connect gameTimer to update the Goomba
        connect(gameTimer, &QTimer::timeout, [goomba, player = this->player]() {
            goomba->update(player);
        });
    }

    // Add Piranhas to the scene with their pipes
    for (int i = 0; i < 6; ++i)
    {
        float piranhaXPos = 400 + i * 400;  // Spread them horizontally
        float piranhaYPos = 490;  // Adjust to the desired y position of the piranha
        Piranha *piranha = new Piranha(":/Resources/img/piranha-0.png",
                                       ":/Resources/img/piranha-1.png",
                                       ":/Resources/img/pipe-med.png", // Add the pipe image
                                       piranhaXPos, piranhaYPos, 435); // Adjust the Y-axis max movement
        scene->addItem(piranha);
        // Connect gameTimer to update the Piranha
        connect(gameTimer, &QTimer::timeout, [piranha, player = this->player]() {
            piranha->update(player);
        });

        // Add a Pipe for the Piranha, ensuring it acts as an obstacle
        QGraphicsPixmapItem *pipe = new QGraphicsPixmapItem();
        pipe->setPixmap(QPixmap(":/Resources/img/pipe-med.png").scaled(80, 80));  // Resize the pipe
        pipe->setPos(piranhaXPos-20, piranhaYPos-15);  // Position the pipe below the piranha
        pipe->setZValue(40);
        scene->addItem(pipe);

        // Make the pipe an obstacle by adding collision handling for the player
        connect(gameTimer, &QTimer::timeout, [pipe, player = this->player]() {
            if (player->collidesWithItem(pipe)) {
                // Block player movement if colliding with pipe (optional)
                player->stopMovement();
            }
        });
        // Add obstacles to the scene (bricks, turtles, etc.)
            Obstacle *obstacle = new Obstacle(":/Resources/img/brick2.bmp",piranhaXPos-5, piranhaYPos-15);
            obstacles.append(obstacle);
            scene->addItem(obstacle);
                float xPos =piranhaXPos; // Spread coins horizontally
                float yPos =piranhaYPos-150;          // Fixed vertical position
                Coins *coin = new Coins();
                coin->setPos(xPos, yPos);
                coins.append(coin);
                scene->addItem(coin);
    }


    // Set up the score and level labels
    scoreLabel = new QLabel("Score: 0", this);
    levelLabel = new QLabel("Level: 3", this);

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

    musicPlayer->setAudioOutput(audioOutput);
    musicPlayer->setSource(QUrl("qrc:/sounds/12. Ground Theme (Hurry!).mp3"));
    audioOutput->setVolume(50);
    // Connect media status signal to handle replay logic
    connect(musicPlayer, &QMediaPlayer::mediaStatusChanged, this, &Level3::onMediaStatusChanged);


    musicPlayer->play();
}


void Level3::startGame()
{

    score = 0;
    scoreLabel->setText("Score: 0");
    gameTimer->start(16); // ~60 FPS (16 ms per frame)
    musicPlayer->play();
}
void Level3::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    // Check if the music has finished
    if (status == QMediaPlayer::EndOfMedia) {
        // Replay the music from the start
        musicPlayer->play();
    }
}
void Level3::keyPressEvent(QKeyEvent *event)
{
    if (player)
    {
        player->keyPressEvent(event);
    }
}

void Level3::keyReleaseEvent(QKeyEvent *event)
{
    if (player)
    {
        player->keyReleaseEvent(event);
    }
}

void Level3::updateGame()
{
    player->updatePosition(); // Apply gravity and jump mechanics

    // Center the view on the player
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
            score += 100;
            scoreLabel->setText("Score: " + QString::number(score));
            scene->removeItem(coins[i]);
            delete coins[i];
            coins.removeAt(i);
            --i; // Adjust index after removal
        }
    }

    // Check if the player has reached the top castle
    if (player->y() <= 0) // Player reaches the top
    {
        musicPlayer->stop();
        gameTimer->stop();
        player->hide();

        // Show a victory message
        QMessageBox::information(this, "You Won!", "Congratulations Mario, you have completed Level 3!");
        this->close();
        Store* store =new Store(this);
        store->exec();
        emit level3Completed();
    }
}

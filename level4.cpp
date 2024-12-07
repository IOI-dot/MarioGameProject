#include "Level4.h"
#include "Player.h"
#include "Obstacle.h"
#include "Coins.h"
#include "turtlefly.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPixmap>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QKeyEvent>
#include <QUrl>

Level4::Level4(QWidget *parent)
    : QWidget(parent), scene(nullptr), view(nullptr), player(nullptr), score(0), level(4)
{
    initLevel();
}

Level4::~Level4()
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

int Level4::getScore()
{
    return score;
}

void Level4::decreaseScore(int amount)
{
    score -= amount;
}

void Level4::initLevel()
{
    this->setWindowTitle("Level 4");
    this->resize(800, 600);

    // Set up the scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 3000, 600);  // Extended level width

    // Set the background image for the scene (can be underwater theme background here)
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
    player->setPos(100, 470);
    player->setFocus();
    player->setZValue(4);
    scene->addItem(player);

    // Add the castle at the end of the level
    castle = new QGraphicsPixmapItem();
    QPixmap castleImage(":/Resources/img/castle.png");
    castleImage = castleImage.scaled(150, 150);
    castle->setPixmap(castleImage);
    castle->setPos(2750, 340);  // Position the castle at the far right
    castle->setZValue(0);  // Ensure the castle is rendered in front of the background
    scene->addItem(castle);

    // Set up the game timer
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &Level4::updateGame);
    gameTimer->start(16);  // ~60 FPS (16 ms per frame)
    // Add TurtleFly enemies
    for (int i = 0; i < 11; ++i)
    {
        float xPos = 3000 + (i * 200);// Start slightly offscreen
        float yPos = 200 + i * 30; // Vary heights for a dynamic level
        TurtleFly *turtleFly = new TurtleFly(":/Resources/img/turtle-fly-0.png",
                                             ":/Resources/img/turtle-fly-1.png",
                                             ":/Resources/img/turtle-turtleback-0.png",
                                             xPos, yPos, 2.0); // Adjust speed as needed
        scene->addItem(turtleFly);

        // Connect update signal
        connect(gameTimer, &QTimer::timeout,  [turtleFly, player = this->player]() {
            turtleFly->update(player);
        });
    }


    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 5; ++i)
    {
        float xPos = i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 500);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }

    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 5; ++i)
    {
        float xPos = 500+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 370);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
        float yPos =330;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);

    }

    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 5; ++i)
    {
        float xPos = 250+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 410);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
        float yPos =370;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 5; ++i)
    {
        float xPos = 750+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 420);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
        float yPos =380;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 5; ++i)
    {
        float xPos = 1000+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 405);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
        float yPos =365;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 5; ++i)
    {
        float xPos = 1250+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 385);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
        float yPos =345;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 5; ++i)
    {
        float xPos = 1500+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 350);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
        float yPos =310;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 5; ++i)
    {
        float xPos = 1750+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 300);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
        float yPos =260;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 5; ++i)
    {
        float xPos = 2000+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 340);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
        float yPos =300;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 5; ++i)
    {
        float xPos = 2250+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 360);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
        float yPos =320;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 5; ++i)
    {
        float xPos = 2500+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 310);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
        float yPos =270;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 5; ++i)
    {
        float xPos = 2750+i * 25;
        Obstacle *obstacle = new Obstacle(":/Resources/img/cloud-small.png", xPos, 460);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Set up the score and level labels
    scoreLabel = new QLabel("Score: 0", this);
    levelLabel = new QLabel("Level: 4", this);
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
    musicPlayer->setSource(QUrl("qrc:/sounds/03. Underwater Theme.mp3"));
    audioOutput->setVolume(50);
    connect(musicPlayer, &QMediaPlayer::mediaStatusChanged, this, &Level4::onMediaStatusChanged);
    musicPlayer->play();
}

void Level4::startGame()
{
    score = 0;
    scoreLabel->setText("Score: 0");
    gameTimer->start(16);  // ~60 FPS (16 ms per frame)
    musicPlayer->play();
}

void Level4::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        musicPlayer->play();
    }
}

void Level4::keyPressEvent(QKeyEvent *event)
{
    if (player)
    {
        player->keyPressEvent(event);
    }
}

void Level4::keyReleaseEvent(QKeyEvent *event)
{
    if (player)
    {
        player->keyReleaseEvent(event);
    }
}

void Level4::updateGame()
{
    player->updatePosition();

    // Center the view on the player
    view->centerOn(player);

    // Collision detection with obstacles
    for (auto obstacle : obstacles)
    {
        if (player->collidesWithItem(obstacle))
        {
            player->stopMovement();
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
            --i;
        }
    }

    // Check if the player has reached the castle
    if (player->x() + player->boundingRect().width() / 2 >= castle->x() + castle->boundingRect().width() / 2)
    {
        musicPlayer->stop();
        gameTimer->stop();
        player->hide();
        QMessageBox::information(this, "You Won!", "Congratulations Mario, you have completed Level 4!");
        emit level4Completed();
    }
}

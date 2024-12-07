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
#include "coins.h"
#include "goomba.h"
#include "store.h"
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
    delete musicPlayer;
    delete audioOutput;
    for (auto obstacle : obstacles)
        delete obstacle;
}

int Level1::getScore()
{
    return score;
}

void Level1::decreaseScore(int amount)
{
    score -= amount;
}

/*void Level1::ShowStore(bool show)
{
    if (show)
    {
        store->show();
        this->hide(); // Hide the game UI while the store is visible
    }
    else
    {
        store->hide();
        this->show(); // Show the game UI when the store is hidden
    }
}
*/
void Level1::initLevel()
{
    this->setWindowTitle("Level 1");
    this->resize(800, 600);

    // Set up the scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 3000, 600); // Extended level width

    // Set the background image for the scene
    QPixmap backgroundPixmap(":/Resources/img/sky.png");
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
    player->setPos(100, 420); // Place player on the ground
    player->setFocus();
    player->setZValue(4);
    scene->addItem(player);

    // Add obstacles to the scene
    for (int i = 0; i < 80; ++i)
    {   if (i >= 30 && i <= 33) {
            continue;
        }

        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/block.png", xPos, 480);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene
    for (int i = 0; i < 80; ++i)
    {
       if (i >= 30 && i <= 33) {
            continue;
        }
        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/block.png", xPos, 570);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }

    for (int i = 0; i < 80; ++i)
    {
        if (i >= 30 && i <= 33) {
            continue;
        }
        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/block.png", xPos, 525);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene
    for (int i = 0; i < 10; ++i)
    {
        float xPos = 500+i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/block.png", xPos, 300);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene
    for (int i = 0; i < 7; ++i)
    {
        float xPos = 1600+i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/block.png", xPos, 300);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add the castle at the end of the level
    castle = new QGraphicsPixmapItem();
    QPixmap castleImage(":/Resources/img/castle.png");
    castleImage = castleImage.scaled(150, 150);
    castle->setPixmap(castleImage);
    castle->setPos(2800, 330); // Position the castle at the far right
   castle->setZValue(0); // Ensure the castle is rendered in front of the background
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
    gameTimer->start(16); // ~60 FPS (16 ms per frame)

    // Initialize the media player for background music
    musicPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);

    // Set up the audio output
    musicPlayer->setAudioOutput(audioOutput);
    musicPlayer->setSource(QUrl("qrc:/sounds/01. Ground Theme.mp3"));
    audioOutput->setVolume(50);

    // Start playing the music when the game starts
    musicPlayer->play();
    // Add coins
    for (int i = 0; i < 15; ++i)
    {
        float xPos = 150 + i * 200; // Spread coins horizontally
        float yPos = 350;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }
    for (int i = 0; i < 15; ++i)
    {
        float xPos = 500 + i * 200; // Spread coins horizontally
        float yPos = 200;          // Fixed vertical position
        Coins *coin = new Coins();
        coin->setPos(xPos, yPos);
        coins.append(coin);
        scene->addItem(coin);
    }
    // Add Goombas to the scene (Group 1)
    for (int i = 0; i < 3; ++i)
    {
        float xPos = 300 + i * 400;
        float yPos = 440;  // Place them on the ground
        Goomba *goomba = new Goomba(":/Resources/img/goomba-0.png",
                                    ":/Resources/img/goomba-dead.png",
                                    xPos, yPos,300);
        scene->addItem(goomba);

        // Connect gameTimer to update the Goomba
        connect(gameTimer, &QTimer::timeout, [goomba, player = this->player]() {
            goomba->update(player);
        });
    }

    // Add Goombas to the scene (Group 2)
    for (int i = 0; i < 4; ++i)
    {
        float xPos = 2100 + i * 400;
        float yPos = 440;  // Place them on the ground
        Goomba *goomba = new Goomba(":/Resources/img/goomba-0.png",
                                    ":/Resources/img/goomba-dead.png",
                                    xPos, yPos,300);  // Maximum 300px movement in either direction
        scene->addItem(goomba);

        // Connect gameTimer to update the Goomba
        connect(gameTimer, &QTimer::timeout, [goomba, player = this->player]() {
            goomba->update(player);
        });
    }

}

void Level1::startGame()
{
    score = 0;
    scoreLabel->setText("Score: 0");
    gameTimer->start(16); // ~60 FPS (16 ms per frame)
    musicPlayer->play();
}

void Level1::keyPressEvent(QKeyEvent *event)
{
    if (player)
    {
        player->keyPressEvent(event);
    }
}

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

    // Center the view on the player as they move
    view->centerOn(player);

    // Ensure the player doesn’t fall below the ground
    if (player->collidesWithItem(ground))
    {
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

        // Close Level1 and open the store dialog
        emit level1Completed();
    }

}



#include "Level5.h"
#include "Player.h"
#include "Obstacle.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPixmap>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QKeyEvent>
#include <QUrl>
#include "fireball.h"
#include <QRandomGenerator>
Level5::Level5(QWidget *parent)
    : QWidget(parent), scene(nullptr), view(nullptr), player(nullptr), score(0), level(5)
{
    initLevel();
}

Level5::~Level5()
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

int Level5::getScore()
{
    return score;
}

void Level5::decreaseScore(int amount)
{
    score -= amount;
}
void Level5::setScore(int newScore)
{
    score = newScore;
    scoreLabel->setText("Score: " + QString::number(score));  // Update the score display
}
void Level5::initLevel()
{
    this->setWindowTitle("Level 5");
    this->resize(800, 600);

    // Set up the scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 3000, 600);  // Extended level width

    // Set the background image for the scene (castle theme background)
    QPixmap backgroundPixmap(":/Resources/img/Background3.png");
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
    player->setPos(100, 350);
    player->setFocus();
    player->setZValue(4);
    scene->addItem(player);
    oldcastle=new QGraphicsPixmapItem();
    QPixmap oldcastleImage(":/Resources/img/castle2.png");
    oldcastleImage = oldcastleImage.scaled(150, 150);
    oldcastle->setPixmap(oldcastleImage);
    oldcastle->setPos(100, 270); // Position the castle at the far right
    oldcastle->setZValue(0); // Ensure the castle is rendered in front of the background
    scene->addItem(oldcastle);

    // Add the castle at the end of the level
    castle = new QGraphicsPixmapItem();
    QPixmap castleImage(":/Resources/img/Princess peach.JPG");
    castleImage = castleImage.scaled(80, 80);
    castle->setPixmap(castleImage);
    castle->setPos(2800, 330);  // Position the castle at the far right
    castle->setZValue(0);  // Ensure the castle is rendered in front of the background
    scene->addItem(castle);

    // Set up the game timer
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &Level5::updateGame);
    gameTimer->start(16);  // ~60 FPS (16 ms per frame)
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 80; ++i)
    {
        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 390);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 80; ++i)
    {
        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 100);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 80; ++i)
    {
        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 55);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 80; ++i)
    {
        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 10);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 80; ++i)
    {
        float xPos = i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 435);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 80; ++i)
    {
        float xPos = 2250+i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 435);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 80; ++i)
    {
        float xPos = 2250+i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 480);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 80; ++i)
    {
        float xPos = 2250+i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 525);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }
    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 80; ++i)
    {
        float xPos = 2250+i * 50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, 570);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }

    // Add obstacles to the scene (bricks, turtles, etc.)
    for (int i = 0; i < 80; ++i)
    {
        float xPos = 2250;
        float yPos= 260 -i*50;
        Obstacle *obstacle = new Obstacle(":/Resources/img/brick.bmp", xPos, yPos);
        obstacles.append(obstacle);
        scene->addItem(obstacle);
    }

    // Add fireballs to the scene
    for (int i = 0; i < 17; ++i) { // Example: 3 fireballs
        int rand = 1 + (QRandomGenerator::global()->generateDouble() * 150); // Randomize in each timeout
        float startX = 500 + i * 100;
        float startY = 800 + rand;
        float maxY = 300;
        Fireball *fireball = new Fireball(startX, startY, maxY);
        scene->addItem(fireball);
        connect(gameTimer, &QTimer::timeout, [=]() {
            fireball->update(player);
        });
    }
    // Set up the score and level labels
    scoreLabel = new QLabel("Score: " + QString::number(score), this);
    levelLabel = new QLabel("Level: 5", this);
    // Initialize the lives label
    scoreLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
    levelLabel->setStyleSheet("font-size: 16px; font-weight: bold;");

    QHBoxLayout *labelLayout = new QHBoxLayout();
    labelLayout->addWidget(levelLabel);
    labelLayout->addWidget(scoreLabel);

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
    musicPlayer->setAudioOutput(audioOutput);
    musicPlayer->setSource(QUrl("qrc:/sounds/04. Castle Theme.mp3"));
    audioOutput->setVolume(50);
    connect(musicPlayer, &QMediaPlayer::mediaStatusChanged, this, &Level5::onMediaStatusChanged);
    musicPlayer->play();
}

void Level5::startGame()
{
    scoreLabel->setText("Score: " + QString::number(score));
    gameTimer->start(16);  // ~60 FPS (16 ms per frame)
    musicPlayer->play();
}

void Level5::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        musicPlayer->play();
    }
}

void Level5::keyPressEvent(QKeyEvent *event)
{
    if (player)
    {
        player->keyPressEvent(event);
    }
}

void Level5::keyReleaseEvent(QKeyEvent *event)
{
    if (player)
    {
        player->keyReleaseEvent(event);
    }
}

void Level5::updateGame()
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

    // Check if the player has reached the princess
    if (player->x() + player->boundingRect().width() / 2 >= castle->x() + castle->boundingRect().width() / 2)
    {
        // Stop the current music
        musicPlayer->stop();

        // Start the new music for completing the castle
        musicPlayer->setSource(QUrl("qrc:/sounds/07. Castle Complete.mp3"));
        musicPlayer->play();

        // Stop the game timer and hide the player
        gameTimer->stop();
        QMessageBox::information(this, "You Won!", "Congratulations Mario, you have rescued the Princess!");
    }
}
void Level5::endGame()
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

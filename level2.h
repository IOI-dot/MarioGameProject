#ifndef LEVEL2_H
#define LEVEL2_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QList>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QKeyEvent>
#include "coins.h"
#include "collectables.h"
class Player;
class Obstacle;

class Level2 : public QWidget
{
    Q_OBJECT

public:
    explicit Level2(QWidget *parent = nullptr);
    ~Level2();

    void startGame();
    int getScore();
    void decreaseScore(int amount);

signals:
    void level2Completed();  // Signal emitted when level is completed

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    void initLevel();
    void updateGame();

    QGraphicsScene *scene;
    QGraphicsView *view;
    Player *player;
    QGraphicsRectItem *ground;
    QGraphicsPixmapItem *castle;
    QLabel *scoreLabel;
    QLabel *levelLabel;
    QList<Obstacle *> obstacles;
    QTimer *gameTimer;
    QMediaPlayer *musicPlayer;  // Media player for background music
    QAudioOutput *audioOutput;  // Audio output to manage volume and playback
    int score;
    int level;
    QList<Coins *> coins;     // List to store coins
    QList<Collectable*> mushrooms;
};

#endif // LEVEL2_H

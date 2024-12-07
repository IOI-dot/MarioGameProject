#ifndef LEVEL4_H
#define LEVEL4_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QKeyEvent>
#include "Player.h"
#include "Obstacle.h"
#include "Coins.h"
#include "Turtle.h"
#include "Goomba.h"
#include "Piranha.h"

class Level4 : public QWidget
{
    Q_OBJECT

public:
    explicit Level4(QWidget *parent = nullptr);
    ~Level4();

    void startGame();

    int getScore();
    void decreaseScore(int amount);
signals:
    void level4Completed();  // Signal emitted when level is completed

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void updateGame();
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);  // Slot to handle media status changes

private:
    void initLevel();

    QGraphicsScene *scene;
    QGraphicsView *view;
    Player *player;
    QTimer *gameTimer;
    QLabel *scoreLabel;
    QLabel *levelLabel;
    QGraphicsPixmapItem *castle;
    QVector<Obstacle*> obstacles;
    QVector<Coins*> coins;
    QVector<Turtle*> turtles;
    int score;
    int level;
    QMediaPlayer *musicPlayer;
    QAudioOutput *audioOutput;
};

#endif // LEVEL4_H

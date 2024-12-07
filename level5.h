#ifndef LEVEL5_H
#define LEVEL5_H

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

class Level5 : public QWidget
{
    Q_OBJECT

public:
    explicit Level5(QWidget *parent = nullptr);
    ~Level5();

    void startGame();

    int getScore();
    void decreaseScore(int amount);
signals:
    void level5Completed();  // Signal emitted when level is completed

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
    QGraphicsPixmapItem *oldcastle;
    QVector<Coins*> coins;
    QVector<Turtle*> turtles;
    int score;
    int level;
    QMediaPlayer *musicPlayer;
    QAudioOutput *audioOutput;
};

#endif // LEVEL5_H

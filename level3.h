#ifndef LEVEL3_H
#define LEVEL3_H

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

class Level3 : public QWidget
{
    Q_OBJECT

public:
    explicit Level3(QWidget *parent = nullptr);
    ~Level3();

    void startGame();
     void setScore(int score);
    int getScore();
    void decreaseScore(int amount);
      void endGame();
signals:
    void level3Completed(int);  // Signal emitted when level is completed

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
    QLabel *livesLabel;
    QGraphicsPixmapItem *gameOverImage;
    QGraphicsPixmapItem *castle;
    QGraphicsPixmapItem *oldcastle;
    QVector<Obstacle*> obstacles;
    QVector<Coins*> coins;
    QVector<Turtle*> turtles;
    int score;
    int lives;
    int level;
    QMediaPlayer *musicPlayer;
    QAudioOutput *audioOutput;
};

#endif // LEVEL3_H

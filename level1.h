#ifndef LEVEL1_H
#define LEVEL1_H

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
//#include "store.h"

class Player;
class Obstacle;

class Level1 : public QWidget
{
    Q_OBJECT

public:
    explicit Level1(QWidget *parent = nullptr);
    ~Level1();

    void startGame();
    int getScore();
    void decreaseScore(int amount);
  //  void ShowStore(bool show);
signals:
    void level1Completed();  // Signal emitted when level is completed

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

   //  Store *store; //pointer to a store
};

#endif // LEVEL1_H

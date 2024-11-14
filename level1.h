#ifndef LEVEL1_H
#define LEVEL1_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QLabel>
#include <QPixmap>
#include "player.h"  // Assuming a player class is implemented separately
#include "obstacle.h"  // Assuming an obstacle class is implemented separately

class Level1 : public QWidget
{
    Q_OBJECT

public:
    // Constructor and Destructor
    explicit Level1(QWidget *parent = nullptr);
    ~Level1();

    // Initializes the level
    void initLevel();

    // Starts the game
    void startGame();

    // Handles key events for player movement
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    // Update the game state (like player movement, score, etc.)
    void updateGame();

private:
    QGraphicsScene *scene;          // Scene for graphical elements
    QGraphicsView *view;            // View to display the scene
    Player *player;                 // Player object
    QList<Obstacle *> obstacles;    // List of obstacles
    QLabel *scoreLabel;             // Label for score display
    QLabel *levelLabel;             // Label for level display
    int score;                      // Current score
    int level;                      // Current level number

    QTimer *gameTimer;              // Timer to control game loop
};

#endif // LEVEL1_H

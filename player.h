#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>

class Player : public QObject, public QGraphicsRectItem
{
public:
    int jumpSpeed; // Adjust this for higher jumps
    int gravity;   // Controls fall speed
    int verticalVelocity;
    bool isJumping;
    Player();
    void updatePosition();

public:
    void jump();
public slots:
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H

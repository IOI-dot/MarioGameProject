#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
class Obstacle; // Forward declaratio
class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Player(QObject *parent = nullptr);

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void jump();
    void landOn(float groundY);
    void updatePosition();
    void stopMovement();

private:
    float horizontalSpeed;
    float jumpSpeed;
    float gravity;
    float groundLevel;
    float verticalVelocity;
    bool isJumping;
};

#endif // PLAYER_H

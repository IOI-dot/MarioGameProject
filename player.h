#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int horizontalSpeed;
    int jumpSpeed;
    int gravity;
    int groundLevel;
    int verticalVelocity;
    bool isJumping;

    // Image paths for different states
    QString normalImagePath;
    QString jumpImagePath;
    QString standImagePath;

public:
    Player(QObject *parent = nullptr);

    // Key events
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    // Movement and actions
    void jump();
    void bounce();
    void handleCollision();
    void landOn(float groundY);
    void updatePosition();

    // Update image
    void updateImage();
    void stopMovement();
};

#endif // PLAYER_H

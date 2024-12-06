#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

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
    bool m_imageToggle;  // For toggling between walking images

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

    // Update image and handle movement
    void updateImage();
    void toggleImage();  // Function to toggle walking images

    // Stop movement (when collision happens or when Mario stops moving)
    void stopMovement();
};

#endif // PLAYER_H

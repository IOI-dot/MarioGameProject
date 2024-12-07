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
    bool facingLeft;  // Tracks whether Mario is facing left

    // Image paths for different states
    QString normalImagePath;
    QString jumpImagePath;
    QString standImagePath;
    QString bigJumpImagePath;
    QString bigStandImagePath;
    QString bigWalkImagePaths[3];
    bool isBig;


public:
    Player(QObject *parent = nullptr);
    void consumeMushroom();

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

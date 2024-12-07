#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsItem>
#include <QDebug>
#include "obstacle.h"
#include <QTimer>
#include "collectables.h"
Player::Player(QObject *parent)
    : QObject(parent), horizontalSpeed(0), jumpSpeed(20), gravity(1), groundLevel(500), verticalVelocity(0), isJumping(false), m_imageToggle(true), facingLeft(false)
{
    // Image paths for different states
    normalImagePath = ":/Resources/img/mario-small-walk-0.png";
    jumpImagePath = ":/Resources/img/mario-small-jump.png";
    standImagePath = ":/Resources/img/mario-small-stand.png";

    // Set the initial image to the standing image
    QPixmap playerImage(standImagePath);
    playerImage = playerImage.scaled(40, 50); // Reduced size
    this->setPixmap(playerImage);

    // Start at an initial position
    this->setPos(100, groundLevel);

    // Enable focus for handling key events
    this->setFlags(QGraphicsItem::ItemIsFocusable);
    this->setFocus();

    // Set a timer to handle flickering the walking images
    QTimer *imageToggleTimer = new QTimer(this);
    connect(imageToggleTimer, &QTimer::timeout, this, &Player::toggleImage);
    imageToggleTimer->start(150);  // 150 ms for flickering animation
    isBig = false;

    bigJumpImagePath = ":/Resources/img/mario-big-jump.png";
    bigStandImagePath = ":/Resources/img/mario-big-stand.png";
    bigWalkImagePaths[0] = ":/Resources/img/mario-big-walk-0.png";
    bigWalkImagePaths[1] = ":/Resources/img/mario-big-walk-1.png";
    bigWalkImagePaths[2] = ":/Resources/img/mario-small-walk-2.png";
}
void Player::consumeMushroom()
{
    isBig = true;
    setScale(1.2); // Adjust size
    setPos(x(), y() - 20); // Compensate for size change
    updateImage(); // Update to big Mario's image
}
void Player::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_A:  // Move left
        horizontalSpeed = -5;
        facingLeft = true;  // Mario is facing left
        updateImage();
        break;
    case Qt::Key_D:  // Move right
        horizontalSpeed = 5;
        facingLeft = false;  // Mario is facing right
        updateImage();
        break;
    case Qt::Key_W:  // Jump
        jump();
        break;
    default:
        break;
    }
}


void Player::keyReleaseEvent(QKeyEvent *event)
{
    // Stop horizontal movement when the A or D key is released
    if (event->key() == Qt::Key_A || event->key() == Qt::Key_D)
    {
        horizontalSpeed = 0; // Stop horizontal movement
        updateImage();  // Update image when standing still
    }
}

void Player::jump()
{
    if (!isJumping)
    {
        verticalVelocity = -jumpSpeed; // Apply upward velocity
        isJumping = true;              // Prevent mid-air jumps
        updateImage(); // Update image when jumping
    }
}

void Player::bounce()
{
    verticalVelocity = -15; // Adjust based on desired bounce strength
}

void Player::handleCollision()
{
    setPos(100, 420); // Reset position
}

void Player::landOn(float groundY)
{
    setPos(x(), groundY);   // Snap to the ground/platform
    verticalVelocity = 0;   // Stop any vertical movement
    isJumping = false;      // Reset jump state to allow jumping again
    updateImage();  // Update image when landing on the ground
}

void Player::updatePosition()
{
    // Apply horizontal movement
    setPos(x() + horizontalSpeed, y());

    // Apply gravity to vertical velocity
    verticalVelocity += gravity;
    setPos(x(), y() + verticalVelocity);

    // Track whether Mario is standing on an object
    bool isOnGround = false;

    // Check collisions with other items
    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);

    for (QGraphicsItem *item : collidingItems)
    {

        Obstacle *obstacle = dynamic_cast<Obstacle *>(item);
        if (obstacle)
        {
            QRectF marioRect = this->boundingRect().translated(this->pos());
            QRectF obstacleRect = obstacle->boundingRect().translated(obstacle->pos());

            float overlapX = 0;
            float overlapY = 0;

            if (marioRect.right() > obstacleRect.left() && marioRect.left() < obstacleRect.right())
            {
                overlapX = std::min(marioRect.right() - obstacleRect.left(), obstacleRect.right() - marioRect.left());
            }

            if (marioRect.bottom() > obstacleRect.top() && marioRect.top() < obstacleRect.bottom())
            {
                overlapY = std::min(marioRect.bottom() - obstacleRect.top(), obstacleRect.bottom() - marioRect.top());
            }

            if (overlapX > 0 && overlapY > 0)
            {
                if (overlapX < overlapY)
                {
                    // Push horizontally
                    if (marioRect.center().x() < obstacleRect.center().x())
                    {
                        setPos(obstacleRect.left() - marioRect.width(), y()); // Push left
                    }
                    else
                    {
                        setPos(obstacleRect.right(), y()); // Push right
                    }
                    horizontalSpeed = 0; // Stop horizontal movement
                }
                else
                {
                    // Push vertically
                    if (marioRect.center().y() < obstacleRect.center().y())
                    {
                        setPos(x(), obstacleRect.top() - marioRect.height()); // Push up
                        landOn(obstacleRect.top() - marioRect.height());      // Mario lands on the obstacle
                        isOnGround = true;
                    }
                    else
                    {
                        setPos(x(), obstacleRect.bottom()); // Push down
                        verticalVelocity = 0; // Stop upward movement
                    }
                }
            }
        }
    }

    // If Mario is not on the ground, allow gravity to pull him down
    if (!isOnGround && y() < groundLevel)
    {
        isJumping = true;
    }

    // Ensure Mario stays within scene bounds
    if (x() < 0)
    {
        setPos(0, y()); // Prevent moving off the left edge
    }
    else if (y() > 600)
    {
        setPos(100, 420); // Reset position
    }
    else if (x() + pixmap().width() > scene()->width())
    {
        setPos(scene()->width() - pixmap().width(), y()); // Prevent moving off the right edge
    }
}

void Player::updateImage()
{
    if (isBig) {
        if (isJumping) {
            QPixmap jumpPixmap(bigJumpImagePath);
            if (facingLeft) {
                QTransform transform;
                transform.scale(-1, 1);
                jumpPixmap = jumpPixmap.transformed(transform);
            }
            setPixmap(jumpPixmap.scaled(50, 75)); // Adjust for big Mario
        } else if (horizontalSpeed == 0) {  // Standing still
            QPixmap standPixmap(bigStandImagePath);
            if (facingLeft) {
                QTransform transform;
                transform.scale(-1, 1);
                standPixmap = standPixmap.transformed(transform);
            }
            setPixmap(standPixmap.scaled(50, 75)); // Adjust for big Mario
        }
    } else {
        if (isJumping) { // Small Mario Jumping
            QPixmap jumpPixmap(jumpImagePath);
            if (facingLeft) {
                QTransform transform;
                transform.scale(-1, 1);
                jumpPixmap = jumpPixmap.transformed(transform);
            }
            setPixmap(jumpPixmap.scaled(40, 50));
        } else if (horizontalSpeed == 0) {  // Small Mario standing still
            QPixmap standPixmap(standImagePath);
            if (facingLeft) {
                QTransform transform;
                transform.scale(-1, 1);
                standPixmap = standPixmap.transformed(transform);
            }
            setPixmap(standPixmap.scaled(40, 50));
        }
    }
    if (isJumping)  // If Mario is jumping
    {
        QPixmap jumpPixmap(jumpImagePath);
        if (facingLeft)  // Invert image if facing left
        {
            QTransform transform;
            transform.scale(-1, 1);
            jumpPixmap = jumpPixmap.transformed(transform);
        }
        setPixmap(jumpPixmap.scaled(40, 50)); // Reduced size
    }
    else if (horizontalSpeed == 0)  // Standing still
    {
        QPixmap standPixmap(standImagePath);
        if (facingLeft)  // Invert image if facing left
        {
            QTransform transform;
            transform.scale(-1, 1);
            standPixmap = standPixmap.transformed(transform);
        }
        setPixmap(standPixmap.scaled(40, 50)); // Reduced size
    }
}



void Player::toggleImage()
{
    if (!isJumping && horizontalSpeed != 0)  // Only toggle walking images if not jumping
    {
        QString walkingImage;

        // Select walking images based on the toggle state
        if (m_imageToggle)
        {
            walkingImage = ":/Resources/img/mario-small-walk-0.png";
        }
        else
        {
            walkingImage = m_imageToggle ? ":/Resources/img/mario-small-walk-1.png" : ":/Resources/img/mario-small-walk-2.png";
        }

        QPixmap playerImage(walkingImage);

        // Adjust image orientation based on the last direction
        if (facingLeft)  // If Mario is facing left, invert the image
        {
            QTransform transform;
            transform.scale(-1, 1);
            playerImage = playerImage.transformed(transform);
        }

        // Update Mario's pixmap with the scaled and oriented image
        setPixmap(playerImage.scaled(40, 50)); // Reduced size

        // Toggle the flag for the next image update
        m_imageToggle = !m_imageToggle;
    }
    else if (!isJumping && horizontalSpeed == 0)  // When idle
    {
        // Ensure the idle state respects the direction Mario is facing
        QPixmap idlePixmap(standImagePath);
        if (facingLeft)  // Invert if facing left
        {
            QTransform transform;
            transform.scale(-1, 1);
            idlePixmap = idlePixmap.transformed(transform);
        }

        setPixmap(idlePixmap.scaled(40, 50)); // Reduced size
    }
}


void Player::stopMovement()
{
    horizontalSpeed = 0;
    verticalVelocity = 0;
    isJumping = false;
}

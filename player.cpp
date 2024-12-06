#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsItem>
#include <QDebug>
#include "obstacle.h"
#include <QTimer>

Player::Player(QObject *parent)
    : QObject(parent), horizontalSpeed(0), jumpSpeed(20), gravity(1), groundLevel(500), verticalVelocity(0), isJumping(false), m_imageToggle(true)
{
    // Image paths for different states
    normalImagePath = ":/Resources/img/mario-small-walk-0.png";
    jumpImagePath = ":/Resources/img/mario-small-jump.png";
    standImagePath = ":/Resources/img/mario-small-stand.png";

    // Set the initial image to the standing image
    QPixmap playerImage(standImagePath);
    playerImage = playerImage.scaled(40, 60); // Adjust size as needed
    this->setPixmap(playerImage);

    // Start at an initial position
    this->setPos(100, groundLevel);

    // Enable focus for handling key events
    this->setFlags(QGraphicsItem::ItemIsFocusable);
    this->setFocus();

    // Set a timer to handle flickering the walking images
    QTimer *imageToggleTimer = new QTimer(this);
    connect(imageToggleTimer, &QTimer::timeout, this, &Player::toggleImage);
    imageToggleTimer->start(150);  // 150 ms = 0.15 seconds for flickering animation
}

void Player::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_A:  // Left movement
        horizontalSpeed = -5;
        updateImage();  // Update image when moving left
        break;
    case Qt::Key_D:  // Right movement
        horizontalSpeed = 5;
        updateImage();  // Update image when moving right
        break;
    case Qt::Key_W:  // Jumping
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
    // If Mario is standing still
    if (horizontalSpeed == 0 && !isJumping)
    {
        setPixmap(QPixmap(standImagePath).scaled(40, 60));  // Standing still image
    }
    else if (isJumping)  // If Mario is jumping
    {
        setPixmap(QPixmap(jumpImagePath).scaled(40, 60));  // Jump image
    }
}

void Player::toggleImage()
{
    // Only toggle images if Mario is moving (left or right)
    if (horizontalSpeed != 0 && !isJumping)
    {
        QString walkingImage;
        if (horizontalSpeed > 0)  // Moving right
        {
            // Toggle between walk images for right movement
            walkingImage = (m_imageToggle) ? ":/Resources/img/mario-small-walk-0.png" : ":/Resources/img/mario-small-walk-1.png";
        }
        else  // Moving left
        {
            // Toggle between walk images for left movement (mirrored)
            walkingImage = (m_imageToggle) ? ":/Resources/img/mario-small-walk-0.png" : ":/Resources/img/mario-small-walk-2.png";
        }

        // Set the current walking image for Mario
        QPixmap playerImage(walkingImage);
        if (horizontalSpeed > 0)  // If moving right, apply no mirror effect
        {
            playerImage = playerImage.scaled(40, 60);
        }
        else  // If moving left, apply mirror effect
        {
            QTransform transform;
            transform.scale(-1, 1);  // Flip the image horizontally
            playerImage = playerImage.transformed(transform).scaled(40, 60);
        }

        this->setPixmap(playerImage);  // Set the updated image for Mario

        m_imageToggle = !m_imageToggle;  // Toggle the flag for the next update
    }
}

void Player::stopMovement()
{
    horizontalSpeed = 0;
    verticalVelocity = 0;
    isJumping = false;
}


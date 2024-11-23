#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPixmap>
#include <QDebug>

Player::Player(QObject *parent)
    : QObject(parent), horizontalSpeed(0), jumpSpeed(20), gravity(1), groundLevel(500), verticalVelocity(0), isJumping(false)
{
    // Load and set up the player's image
    QPixmap playerImage("C:/Users/Merna/Downloads/mariolesgo.jpeg");
    playerImage = playerImage.scaled(40, 60); // Adjust size as needed
    this->setPixmap(playerImage);

    // Start at an initial position
    this->setPos(100, groundLevel);

    // Enable focus for handling key events
    this->setFlags(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}

void Player::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_A:  // Left movement
        horizontalSpeed = -10;
        break;
    case Qt::Key_D:  // Right movement
        horizontalSpeed = 10;
        break;
    case Qt::Key_W:  // Jumping
        jump();
        break;
    case Qt::Key_S:  // Stop movement (optional)
        stopMovement();
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
    }
}

void Player::jump()
{
    if (!isJumping)
    {
        verticalVelocity = -jumpSpeed; // Apply upward velocity
        isJumping = true;              // Prevent mid-air jumps
    }
}

void Player::landOn(float groundY)
{
    setPos(x(), groundY);   // Snap to the ground/platform
    verticalVelocity = 0;    // Stop any vertical movement
    isJumping = false;       // Reset jump state
}

void Player::updatePosition()
{
    // Apply horizontal movement
    setPos(x() + horizontalSpeed, y());

    // Apply vertical movement (gravity and jumping mechanics)
    if (isJumping)
    {
        verticalVelocity += gravity;         // Gravity pulls the player down
        setPos(x(), y() + verticalVelocity); // Update vertical position

        // Check for collision with the ground
        if (y() >= groundLevel)
        {
            landOn(groundLevel); // Snap to the ground
        }
    }

    // Ensure the player stays within scene bounds
    if (x() < 0)
    {
        setPos(0, y()); // Prevent moving off the left edge
    }
    else if (x() + pixmap().width() > scene()->width())
    {
        setPos(scene()->width() - pixmap().width(), y()); // Prevent moving off the right edge
    }
}

void Player::stopMovement()
{
    horizontalSpeed = 0;  // Stop horizontal movement
    verticalVelocity = 0; // Stop vertical movement
    isJumping = false;    // Stop jumpinp
}

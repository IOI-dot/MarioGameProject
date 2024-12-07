#include "turtlefly.h"
#include "player.h"
#include <QGraphicsScene>
#include <QTimer>

TurtleFly::TurtleFly(const QString &walkPath1, const QString &walkPath2, const QString &deadPath,
                     float x, float y, float speed)
    : Enemy(walkPath1, x, y, 40, 40), m_walkImagePath1(walkPath1), m_walkImagePath2(walkPath2),
    m_deadImagePath(deadPath), m_imageToggle(true)
{
    setSpeed(speed); // Set the speed of the turtle fly

    // Set initial walking image
    setPixmap(QPixmap(walkPath1).scaled(40, 40));

    // Start the image toggle timer to switch images every 500 ms
    m_imageToggleTimer = new QTimer(this);
    connect(m_imageToggleTimer, &QTimer::timeout, this, &TurtleFly::toggleImage);
    m_imageToggleTimer->start(500); // 500 ms = 0.5 seconds

    // Start moving to the left
    setDirection(-1);
}

void TurtleFly::update(Player *player)
{
    if (!isAlive())
        return;

    // Move the TurtleFly to the left
    setPos(x() + direction() * speed(), y());

    // Reset position if it goes off-screen
    if (x() < -50) {
        setPos(3000, y()); // Reset to the right side of the screen
    }

    // Check for collision with the player
    if (collidesWithItem(player)) {
        QRectF turtleFlyRect = boundingRect().translated(pos());
        QRectF playerRect = player->boundingRect().translated(player->pos());

        bool topCollision = playerRect.bottom() > turtleFlyRect.top() &&
                            playerRect.bottom() < turtleFlyRect.center().y() &&
                            playerRect.left() < turtleFlyRect.right() &&
                            playerRect.right() > turtleFlyRect.left();

        if (topCollision) {
            // Mario stomps the TurtleFly
            setAlive(false);
            setPixmap(QPixmap(m_deadImagePath).scaled(40, 20)); // Dead TurtleFly image
            startFlickering(); // Start flickering effect
            player->bounce();   // Mario bounces after stomping
        } else {
            // Mario gets hit by the TurtleFly
            player->handleCollision();
        }
    }
}

void TurtleFly::startFlickering()
{
    QTimer *flickerTimer = new QTimer(this);
    connect(flickerTimer, &QTimer::timeout, this, &TurtleFly::toggleVisibility);
    flickerTimer->start(100);  // Flicker every 100 milliseconds

    QTimer::singleShot(1000, this, &TurtleFly::remove);  // TurtleFly disappears after 1 second
}

void TurtleFly::toggleVisibility()
{
    // Toggle visibility (fade in/out effect)
    setVisible(!isVisible());
}

void TurtleFly::remove()
{
    scene()->removeItem(this);
}

void TurtleFly::toggleImage()
{
    if (!isAlive())
        return;

    // Toggle between two images to simulate flying every 0.5 seconds
    if (m_imageToggle) {
        setPixmap(QPixmap(m_walkImagePath1).scaled(40, 40));  // First flying image
    } else {
        setPixmap(QPixmap(m_walkImagePath2).scaled(40, 40));  // Second flying image
    }

    m_imageToggle = !m_imageToggle; // Toggle the flag for the next update
}

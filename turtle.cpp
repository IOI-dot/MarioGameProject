#include "turtle.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsOpacityEffect>
#include <QGraphicsScene>
#include <QDebug>

Turtle::Turtle(const QString &walkPath1, const QString &walkPath2, const QString &deadPath,
               float startX, float startY, float maxDistance)
    : Enemy(walkPath1, startX, startY), m_deadImagePath(deadPath), m_walkImagePath1(walkPath1),
    m_walkImagePath2(walkPath2), m_startX(startX), m_maxDistance(maxDistance), m_imageToggle(true)
{
    setSpeed(1.0);  // Slightly slower movement for the Turtle
    setDirection(1); // Initial direction: right

    // Set initial walking image
    setPixmap(QPixmap(walkPath1).scaled(40, 40));

    // Start the image toggle timer to switch images every 0.5 seconds
    QTimer *imageToggleTimer = new QTimer(this);
    connect(imageToggleTimer, &QTimer::timeout, this, &Turtle::toggleImage);
    imageToggleTimer->start(500);  // 500 ms = 0.5 seconds
}

void Turtle::update(Player *player)
{
    if (!isAlive())
        return;

    // Movement logic: reverse direction if out of bounds
    // Move the turtle based on its current speed and direction
    setPos(x() + direction() * speed(), y());

    // Check for boundary conditions and reverse direction when needed
    if (x() > m_startX + m_maxDistance) {
        setPos(m_startX + m_maxDistance, y());
        setDirection(-direction());  // Reverse direction
    } else if (x() < m_startX - m_maxDistance) {
        setPos(m_startX - m_maxDistance, y());
        setDirection(-direction());  // Reverse direction
    }

    // Collision detection with player
    if (player && collidesWithItem(player))
    {
        QRectF turtleRect = this->boundingRect().translated(this->pos());
        QRectF playerRect = player->boundingRect().translated(player->pos());

        bool topCollision = playerRect.bottom() > turtleRect.top() &&
                            playerRect.bottom() < turtleRect.center().y() &&
                            playerRect.left() < turtleRect.right() &&
                            playerRect.right() > turtleRect.left();

        bool fallingCollision = playerRect.bottom() - 21 <= turtleRect.top();  // Adjust for falling collision

        if (topCollision || fallingCollision)
        {
            // Mario stomps the Turtle
            setAlive(false);
            setPixmap(QPixmap(m_deadImagePath).scaled(40, 20)); // Squished Turtle image

            // Adjust position to keep the Turtle on the ground
            setPos(x(), 533);  // Keep turtle on the ground
            startFlickering();  // Start flickering effect
            player->bounce();   // Mario bounces after stomping the Turtle
        }
        else
        {
            // Mario gets hit by the Turtle
            player->handleCollision();
        }
    }
}

void Turtle::startFlickering()
{
    // Create a QTimer to handle the flickering effect
    QTimer *flickerTimer = new QTimer(this);
    connect(flickerTimer, &QTimer::timeout, this, &Turtle::toggleVisibility);
    flickerTimer->start(100);  // Flicker every 100 milliseconds

    // Set a timer to remove the Turtle after a short period
    QTimer::singleShot(1000, this, &Turtle::remove);  // Turtle disappears after 1 second
}

void Turtle::toggleVisibility()
{
    // Toggle visibility (fade in/out effect)
    if (opacity() == 1.0)
        setOpacity(0.0);  // Make Turtle invisible
    else
        setOpacity(1.0);  // Make Turtle visible again
}

void Turtle::remove()
{
    // Remove the Turtle from the scene after flickering
    scene()->removeItem(this);
}

void Turtle::toggleImage()
{
    if (!isAlive())
        return;

    // Toggle between two images to simulate walking every 0.5 seconds
    if (m_imageToggle)
    {
        setPixmap(QPixmap(m_walkImagePath1).scaled(40, 40));  // First walking image
    }
    else
    {
        setPixmap(QPixmap(m_walkImagePath2).scaled(40, 40));  // Second walking image
    }

    // Toggle the flag for the next update
    m_imageToggle = !m_imageToggle;

    // Invert the image horizontally based on direction
    if (direction() > 0)  // Facing right
    {
        setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
    }
}



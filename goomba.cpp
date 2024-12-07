#include "goomba.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsOpacityEffect>
#include <QGraphicsScene>
#include <QDebug>

Goomba::Goomba(const QString &alivePath, const QString &deadPath, float startX, float startY, float maxDistance)
    : Enemy(alivePath, startX, startY), m_deadImagePath(deadPath), m_startX(startX), m_maxDistance(maxDistance), m_imageToggle(true)
{
    setSpeed(1.5);  // Slower movement for Goombas
    setDirection(1); // Initial direction: right

    // Set initial walking image
    setPixmap(QPixmap(alivePath).scaled(40, 40)); // Assuming alive image size is 40x40
    m_walkImagePath1 = alivePath;
    m_walkImagePath2 = ":/Resources/img/goomba-1.png"; // The second walking image

    // Start the image toggle timer to switch images every 0.5 seconds
    QTimer *imageToggleTimer = new QTimer(this);
    connect(imageToggleTimer, &QTimer::timeout, this, &Goomba::toggleImage);
    imageToggleTimer->start(500);  // 500 ms = 0.5 seconds
}

void Goomba::update(Player *player)
{
    if (!isAlive())
        return;

    // Movement logic: reverse direction if out of bounds
    setPos(x() + direction() * speed(), y());
    if (x() > m_startX + m_maxDistance || x() < m_startX - m_maxDistance)
    {
        setDirection(-direction());
    }

    // Collision detection with player
    if (player && collidesWithItem(player))
    {
        QRectF goombaRect = this->boundingRect().translated(this->pos());
        QRectF playerRect = player->boundingRect().translated(player->pos());

        bool topCollision = playerRect.bottom() > goombaRect.top() &&
                            playerRect.bottom() < goombaRect.center().y() &&
                            playerRect.left() < goombaRect.right() &&
                            playerRect.right() > goombaRect.left();

        bool fallingCollision = playerRect.bottom() - 21 <= goombaRect.top();  // Adjust for falling collision

        if (topCollision || fallingCollision)
        {
            // Mario stomps Goomba
            setAlive(false);
            setPixmap(QPixmap(m_deadImagePath).scaled(40, 20)); // Squished Goomba image

            // Adjust position to keep Goomba on the ground

                setPos(x(), y()+20);


                 setPos(x(), y()+20);

            // Start flickering effect
            startFlickering();
            player->bounce(); // Mario bounces after stomping the Goomba
        }
        else
        {
            // Mario gets hit by the Goomba
            player->handleCollision();
        }
    }
}

void Goomba::startFlickering()
{
    // Create a QTimer to handle the flickering effect
    QTimer *flickerTimer = new QTimer(this);
    connect(flickerTimer, &QTimer::timeout, this, &Goomba::toggleVisibility);
    flickerTimer->start(100);  // Flicker every 100 milliseconds

    // Set a timer to remove the Goomba after a short period
    QTimer::singleShot(1000, this, &Goomba::remove);  // Goomba disappears after 1 second
}

void Goomba::toggleVisibility()
{
    // Toggle visibility (fade in/out effect)
    if (opacity() == 1.0)
        setOpacity(0.0);  // Make Goomba invisible
    else
        setOpacity(1.0);  // Make Goomba visible again
}

void Goomba::remove()
{
    // Remove the Goomba from the scene after flickering
    scene()->removeItem(this);
}

void Goomba::toggleImage()
{
    if(!isAlive()){
        return;
    }
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
}

// piranha.cpp
#include "piranha.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsOpacityEffect>

Piranha::Piranha(const QString &imagePath1, const QString &imagePath2, const QString &pipePath, float startX, float startY, float maxY)
    : Enemy(imagePath1, startX, startY), m_piranhaImagePath1(imagePath1), m_piranhaImagePath2(imagePath2), m_pipeImagePath(pipePath),
    m_startY(startY), m_maxY(maxY), m_isMovingUp(true), m_imageToggle(true), m_pipeHeight(40)
{
    setPixmap(QPixmap(m_piranhaImagePath1).scaled(40, 40)); // Set initial piranha image
    setPos(startX, startY);

    // Timer for toggling images (walking animation)
    QTimer *imageToggleTimer = new QTimer(this);
    connect(imageToggleTimer, &QTimer::timeout, this, &Piranha::toggleImage);
    imageToggleTimer->start(1000);  // Change image every 500 ms
}

void Piranha::toggleImage()
{
    if (!isAlive()) {
        return;
    }
    // Toggle between two images to simulate walking (appearance of the plant)
    if (m_imageToggle) {
        setPixmap(QPixmap(m_piranhaImagePath1).scaled(40, 40));
    } else {
        setPixmap(QPixmap(m_piranhaImagePath2).scaled(40, 40));
    }

    // Toggle the flag for the next image
    m_imageToggle = !m_imageToggle;
}

void Piranha::update(Player *player)
{
    if (!isAlive()) {
        return;
    }

    // Move the piranha plant vertically (up and down)
    if (m_isMovingUp) {
        setPos(x(), y() - 0.5);
        if (y() <= m_maxY) {
            m_isMovingUp = false;
        }
    } else {
        setPos(x(), y() + 0.5);
        if (y() >= m_startY) {
            m_isMovingUp = true;
        }
    }

    // Check for collision with the player
    handlePlayerCollision(player);
}

void Piranha::handlePlayerCollision(Player *player)
{
    // Check if the player collides with the Piranha Plant
    if (player && collidesWithItem(player)) {
        QRectF piranhaRect = this->boundingRect().translated(this->pos());
        QRectF playerRect = player->boundingRect().translated(player->pos());

        bool topCollision = playerRect.bottom() > piranhaRect.top() &&
                            playerRect.bottom() < piranhaRect.center().y() &&
                            playerRect.left() < piranhaRect.right() &&
                            playerRect.right() > piranhaRect.left();

        if (topCollision) {
            // Mario collides with the Piranha Plant
            player->handleCollision();  // Reset Mario's position
        }
    }
}

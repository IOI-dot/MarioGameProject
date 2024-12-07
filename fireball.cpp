#include "Fireball.h"
#include <QPixmap>
#include <QDebug>
#include <QRandomGenerator> // Include for random number generation
Fireball::Fireball(float startX, float startY, float maxY, QObject *parent)
    : QObject(parent), m_startY(startY), m_maxY(maxY), m_isMovingUp(true), currentImageIndex(0) {
    // Load fireball images
    fireballImages = {
     ":/Resources/img/fireball-0-Photoroom.png",
     ":/Resources/img/fireball-1-Photoroom.png"
    };

    // Set initial image
    setPixmap(QPixmap(fireballImages[currentImageIndex]).scaled(40, 40));
    setPos(startX, startY);

    // Timer for image animation
    imageTimer = new QTimer(this);
    connect(imageTimer, &QTimer::timeout, this, &Fireball::toggleImage);
    imageTimer->start(200); // Change image every 200 ms

    // Timer for movement
    movementTimer = new QTimer(this);
    connect(movementTimer, &QTimer::timeout, [this]() {
        int rand = 1 + (QRandomGenerator::global()->generateDouble() * 6); // Randomize in each timeout

        if (m_isMovingUp) {
            setPos(x(), y() - rand); // Move up
            if (y() <= m_maxY) {
                m_isMovingUp = false;
            }
        } else {
            setPos(x(), y() + rand); // Move down
            if (y() >= m_startY) {
                m_isMovingUp = true;
            }
        }
    });

    movementTimer->start(16); // ~60 FPS
}

void Fireball::toggleImage() {
    // Cycle through fireball images
    currentImageIndex = (currentImageIndex + 1) % fireballImages.size();

    // Load the current image
    QPixmap pixmap(fireballImages[currentImageIndex]);

    // Check if the pixmap is valid
    if (pixmap.isNull()) {
        qDebug() << "Failed to load image:" << fireballImages[currentImageIndex];
        return;  // Exit if image loading fails
    }

    // If image is loaded correctly, set the pixmap
    setPixmap(pixmap.scaled(40, 40));
}
void Fireball::update(Player *player) {
    handlePlayerCollision(player);
}

void Fireball::handlePlayerCollision(Player *player) {
    // Check if the player collides with the Piranha Plant
    if (player && collidesWithItem(player)) {
        QRectF fireballRect = this->boundingRect().translated(this->pos());
        QRectF playerRect = player->boundingRect().translated(player->pos());

        bool topCollision = playerRect.bottom() > fireballRect.top() &&
                            playerRect.bottom() < fireballRect.center().y() &&
                            playerRect.left() < fireballRect.right() &&
                            playerRect.right() > fireballRect.left();

        if (topCollision) {
            // Mario collides with the Piranha Plant
            player->handleCollision();  // Reset Mario's position
        }
    }
}

#include "obstacle.h"

// Constructor to set the image and position of the obstacle
Obstacle::Obstacle(const QString &imagePath, float x, float y)
{
    setImage(imagePath);   // Set the image for the obstacle
    setPosition(x, y);     // Set the position of the obstacle
}

// Set the position of the obstacle
void Obstacle::setPosition(float x, float y)
{
    setPos(x, y); // Position this obstacle on the scene
}

// Set the image of the obstacle
void Obstacle::setImage(const QString &imagePath)
{
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull())  // makes sure the image loaded correctly
    {
        setPixmap(pixmap); // Set the pixmap for the obstacle
    }
}

// Get the position of the obstacle
QPointF Obstacle::position() const
{
    return pos(); // Return the current position of the obstacle
}

// Custom collision detection function (player or enemy)
bool Obstacle::checkCollision(QGraphicsItem *item)
{
    // Perform a basic collision check
    return this->collidesWithItem(item);
}

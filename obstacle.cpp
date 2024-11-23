#include "obstacle.h"
#include <QPixmap>

Obstacle::Obstacle(const QString &imagePath, float x, float y)
{
    setImage(imagePath);
    setPosition(x, y);
}

void Obstacle::setPosition(float x, float y)
{
    setPos(x, y);
}

void Obstacle::setImage(const QString &imagePath)
{
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull())
    {
        setPixmap(pixmap.scaled(50, 50)); // Set the size of obstacles
    }
}

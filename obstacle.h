#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Obstacle : public QGraphicsPixmapItem
{

public:
public:
    // Constructor
    Obstacle(const QString &imagePath, float x = 0, float y = 0);

    // Setters
    void setPosition(float x, float y);
    void setImage(const QString &imagePath);

    // Getters
    QPointF position() const;

    //collision detection function
    bool checkCollision(QGraphicsItem *item);
};

#endif // OBSTACLE_H

#ifndef ENEMY_H
#define ENEMY_H

#include "obstacle.h"
#include <QObject>
#include <QGraphicsPixmapItem>

class Player; // Forward declaration

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

protected:
    float m_direction;   // Movement direction (-1 for left, 1 for right)
    float m_speed;       // Speed of movement
    bool m_isAlive;      // Status of the enemy

public:
    Enemy(const QString &imagePath, float x, float y, float width = 40, float height = 40);

    // Setters and Getters
    void setDirection(float direction);
    float direction() const;

    void setSpeed(float speed);
    float speed() const;

    void setAlive(bool alive);
    bool isAlive() const;

    // Collision logic
    virtual bool isTopCollision(const Player *player) const;

    // Update behavior
    virtual void update(Player *player);
};

#endif // ENEMY_H

#ifndef ENEMY_H
#define ENEMY_H

#include "obstacle.h"
#include <QTimer>

class Enemy : public Obstacle
{
    Q_OBJECT

private:
    float m_direction;
    float m_speed;
    bool m_isAlive;
    QTimer *m_timer;


public:
    // Constructor
    Enemy(const QString &imagePath, float x = 0, float y = 0, float width = 100, float height = 100);

    // Setters
    void setDirection(float direction);
    void setSpeed(float speed);
    void setAlive(bool alive);

    // Getters
    float direction() const;
    float speed() const;
    bool isAlive() const;

    // Check if the collision is from the top
    bool isTopCollision(const Player *player) const;

    // Update the enemy's behavior
    void update(Player *player);


};

#endif // ENEMY_H

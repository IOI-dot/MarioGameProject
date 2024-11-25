#ifndef GOOMBA_H
#define GOOMBA_H

#include "enemy.h"

class Goomba : public Enemy
{
    Q_OBJECT

private:
    QString m_deadImagePath; // Path to the dead sprite
    float m_startX;          // Starting position
    float m_maxDistance;     // Maximum distance from starting position

public:
    Goomba(const QString &alivePath, const QString &deadPath, float startX, float startY, float maxDistance);

    void update(Player *player) override; // Override the update method
};

#endif // GOOMBA_H

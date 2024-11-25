#include "goomba.h"
#include "player.h"

Goomba::Goomba(const QString &alivePath, const QString &deadPath, float startX, float startY, float maxDistance)
    : Enemy(alivePath, startX, startY), m_deadImagePath(deadPath), m_startX(startX), m_maxDistance(maxDistance)
{
    setSpeed(1.5);  // Slower movement for Goombas
    setDirection(1); // Initial direction: right
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
        if (isTopCollision(player))
        {
            // Mario stomps Goomba
            setAlive(false);
            setPixmap(QPixmap(m_deadImagePath).scaled(40, 40)); // Squished Goomba image
            player->bounce(); // Mario bounces after defeating Goomba
        }
        else
        {
            // Mario gets hit
            player->handleCollision();
        }
    }
}

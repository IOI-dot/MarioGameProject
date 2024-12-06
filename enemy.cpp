#include "enemy.h"
#include "player.h"

Enemy::Enemy(const QString &imagePath, float x, float y, float width, float height)
    : m_direction(1), m_speed(2.0f), m_isAlive(true)
{
    setPixmap(QPixmap(imagePath).scaled(width, height)); // Set the enemy's image
    setPos(x, y); // Set initial position
}

void Enemy::setDirection(float direction)
{
    m_direction = direction;
}

float Enemy::direction() const
{
    return m_direction;
}

void Enemy::setSpeed(float speed)
{
    m_speed = speed;
}

float Enemy::speed() const
{
    return m_speed;
}

void Enemy::setAlive(bool alive)
{
    m_isAlive = alive;
}

bool Enemy::isAlive() const
{
    return m_isAlive;
}

bool Enemy::isTopCollision(const Player *player) const
{
    if (!player)
        return false;

    QRectF enemyBounds = boundingRect().translated(pos());
    QRectF playerBounds = player->boundingRect().translated(player->pos());

    return playerBounds.bottom() >= enemyBounds.top() &&
           playerBounds.bottom() <= enemyBounds.top() + 30 &&
           playerBounds.center().x() >= enemyBounds.left() &&
           playerBounds.center().x() <= enemyBounds.right();
}

void Enemy::update(Player *player)
{
    // Default enemy behavior
    if (m_isAlive)
    {
        setPos(x() + m_direction * m_speed, y()); // Update position
    }
}

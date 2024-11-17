#include "enemy.h"
#include "player.h"

Enemy::Enemy(const QString &imagePath, float x, float y, float width, float height)
    : Obstacle(imagePath, x, y, width, height), m_direction(1), m_speed(2.0f), m_isAlive(true)
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, [this]() {
        update(nullptr); // Player needs to be passed
    });
    m_timer->start(100); // Update every 100ms
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
    if (!alive)
    {
        m_timer->stop();
        setScale(0.5); // Shrinks the enemy to half its original size
    }
}

bool Enemy::isAlive() const
{
    return m_isAlive;
}

// Check if the collision is from the top
bool Enemy::isTopCollision(const Player *player) const
{
    if (!player)
        return false;

    // Get bounding rectangles
    QRectF enemyBounds = boundingRect().translated(pos());
    QRectF playerBounds = player->boundingRect().translated(player->pos());

    // Check if player's bottom intersects enemy's top and if their center aligns horizontally
    return playerBounds.bottom() >= enemyBounds.top() &&
           playerBounds.bottom() <= enemyBounds.top() + 10 && // Allow a margin for top collision
           playerBounds.center().x() >= enemyBounds.left() &&
           playerBounds.center().x() <= enemyBounds.right();
}

void Enemy::update(Player *player)
{
    if (!m_isAlive)
        return;

    // Move the enemy
    setPos(x() + m_direction * m_speed, y());

    // Reverse direction on screen bounds
    if (x() <= 0 || x() >= 800) // Adjust screen width as necessary
    {
        m_direction = -m_direction;
    }

    // Check for collision with player
    if (player && collidesWithItem(player))
    {
        if (isTopCollision(player))
        {
            setAlive(false);    // Enemy is defeated
            player->bounce();   // Make the player "bounce" after landing on top
        }
        else
        {
            player->handleCollision(); // Player takes damage or is knocked out
        }
    }
}

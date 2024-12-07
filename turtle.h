#ifndef TURTLE_H
#define TURTLE_H

#include "enemy.h"

class Turtle : public Enemy
{
    Q_OBJECT

private:
    QString m_deadImagePath;  // Path to the dead sprite
    QString m_walkImagePath1; // Path to the first walking sprite
    QString m_walkImagePath2; // Path to the second walking sprite
    bool m_imageToggle;       // Flag to toggle between images for walking effect
     float m_startX;           // Starting position (X-coordinate)
     float m_maxDistance;      // Maximum distance the Goomba can travel left/right

public:
    // Constructor to initialize the Turtle with its alive and dead images, starting position, and maximum distance
    Turtle(const QString &walkPath1, const QString &walkPath2, const QString &deadPath,
           float startX, float startY, float maxDistance);

    // Override the update method from the Enemy class
    void update(Player *player) override;
    // Methods for the flickering effect after the Goomba dies
    void startFlickering();
    void toggleVisibility();
    void remove();

    // Toggle the walking animation
    void toggleImage();
};

#endif // TURTLE_H

#ifndef GOOMBA_H
#define GOOMBA_H

#include "enemy.h"

class Goomba : public Enemy
{
    Q_OBJECT

private:
    QString m_deadImagePath;  // Path to the dead sprite
    QString m_walkImagePath1; // Path to the first walking sprite
    QString m_walkImagePath2; // Path to the second walking sprite
    float m_startX;           // Starting position (X-coordinate)
    float m_maxDistance;      // Maximum distance the Goomba can travel left/right
    bool m_imageToggle;       // Flag to toggle between images for walking effect
    int leveltype;

public:
    // Constructor to initialize the Goomba with its alive and dead images, starting position, and maximum distance
    Goomba(const QString &alivePath, const QString &deadPath, float startX, float startY, float maxDistance);

    // Override the update method from the Enemy class
    void update(Player *player) override;

    // Methods for the flickering effect after the Goomba dies
    void startFlickering();
    void toggleVisibility();
    void remove();

    // Helper method to switch the Goomba's images to create the walking effect
    void toggleImage();
};

#endif // GOOMBA_H

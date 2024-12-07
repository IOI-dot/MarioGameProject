#ifndef TURTLEFLY_H
#define TURTLEFLY_H

#include "enemy.h"
#include <QTimer>

class TurtleFly : public Enemy
{
    Q_OBJECT

private:
    QString m_walkImagePath1; // Path to the first flying sprite
    QString m_walkImagePath2; // Path to the second flying sprite
    QString m_deadImagePath;   // Path to the dead sprite
    bool m_imageToggle;        // Flag to toggle between images
    QTimer *m_imageToggleTimer; // Timer for toggling images

public:
    TurtleFly(const QString &walkPath1, const QString &walkPath2, const QString &deadPath,
              float x, float y, float speed);
    void update(Player *player) override;
    void startFlickering();
    void toggleVisibility();
    void remove();

    // Toggle the walking animation
    void toggleImage();
};

#endif // TURTLEFLY_H

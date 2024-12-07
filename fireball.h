#ifndef FIREBALL_H
#define FIREBALL_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Player.h"
#include <QRandomGenerator>

class Fireball : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Fireball(float startX, float startY, float maxY, QObject *parent = nullptr);

    void update(Player *player);

private slots:
    void toggleImage();

private:
    void handlePlayerCollision(Player *player);

    float m_startY;
    float m_maxY;
    bool m_isMovingUp;
    int currentImageIndex;
    QStringList fireballImages;
    QTimer *imageTimer;
    QTimer *movementTimer;

};

#endif // FIREBALL_H

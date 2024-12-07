#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "player.h"

class Collectable : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Collectable(QString imagePath, QObject *parent = nullptr);
    void checkForCollisionWithPlayer(Player *player);
};

#endif // COLLECTABLE_H

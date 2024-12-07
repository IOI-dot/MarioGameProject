#include "collectables.h"
#include <QGraphicsScene>
Collectable::Collectable(QString imagePath, QObject *parent)
    : QObject(parent), QGraphicsPixmapItem(QPixmap(imagePath).scaled(50, 50))
{
}
void Collectable::checkForCollisionWithPlayer(Player *player)
{
    if (this->collidesWithItem(player)) {
        player->consumeMushroom();
        scene()->removeItem(this); // Remove mushroom after collection
        delete this; // Delete the mushroom object
    }
}

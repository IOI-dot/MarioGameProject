// piranha.h
#ifndef PIRANHA_H
#define PIRANHA_H

#include "enemy.h"
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Piranha : public Enemy
{
    Q_OBJECT

private:
    QString m_piranhaImagePath1;
    QString m_piranhaImagePath2;
    QString m_pipeImagePath;
    float m_startY;
    float m_maxY;
    bool m_isMovingUp;
    bool m_imageToggle;
    int m_pipeHeight;

public:
    Piranha(const QString &imagePath1, const QString &imagePath2, const QString &pipePath, float startX, float startY, float maxY);

    void update(Player *player) override;
    void toggleImage();

protected:
    void handlePlayerCollision(Player *player);
};

#endif // PIRANHA_H

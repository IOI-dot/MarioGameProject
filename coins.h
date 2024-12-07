#ifndef COINS_H
#define COINS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Coins : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Coins(); // Constructor

private slots:
    void updateImage(); // Slot to update the coin image

private:
    QTimer *timer;      // Timer for animation
    int currentImage;   // Index to track the current image
};

#endif // COINS_H

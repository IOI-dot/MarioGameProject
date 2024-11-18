#ifndef COLLECTABLE_H
#define COLLECTABLE_H
#include <QString>
#include <QPointF>

class Collectable
{
public:
    // Constructor to initialize the collectable
    Collectable(QString type, int gainValue, QPointF position)
        : type(type), gainValue(gainValue), position(position) {}

    // Method to collect the collectable
    void collect() {
        // we'd interact with the player's score here
        qDebug() << "Collected" << type << "and gained" << gainValue << "points!";
    }

    // Method to display the collectable (for now, we'll just print info)
    void displayCollectable() {
        qDebug() << "Displaying collectable of type" << type << "at position" << position;
    }

    // Getters for the collectable attributes
    QString getType() const { return type; }
    int getGainValue() const { return gainValue; }
    QPointF getPosition() const { return position; }

private:
    QString type;        // Type of collectable (coin, gem )
    int gainValue;       // Points gained when collected
    QPointF position;    // Position of collectable in the game world
};

#endif // COLLECTABLE_H

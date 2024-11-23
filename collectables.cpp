/*#include <QCoreApplication>
#include <QDebug>
#include <QPointF>
#include "Collectable.h"
#include "Score.h"

// Simulate the player object (for demonstration purposes)
class Player : public QObject
{
    Q_OBJECT

public:
    Player(QObject *parent = nullptr) : QObject(parent), score() {}

    // Update the player's score
    void updateScore(int points) {
        score.updateScore(points);  // Update the score with the collected points
    }

    // Show the player's score
    void showScore() {
        score.showScore();
    }

private:
    Score score;  // The player's score
};

// Main function
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create a player
    Player player;

    // Create some collectables
    Collectable coin("Coin", 10, QPointF(100, 200));
    Collectable gem("Gem", 50, QPointF(150, 250));

    // Display the collectables
    coin.displayCollectable();
    gem.displayCollectable();

    // Simulate the player collecting the items
    player.updateScore(coin.getGainValue());  // Collect the coin
    player.updateScore(gem.getGainValue());   // Collect the gem

    // Show the updated score
    player.showScore();

    return a.exec();
}
*/

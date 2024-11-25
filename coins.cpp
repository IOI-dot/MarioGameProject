#include "coins.h"
#include <QPixmap>

// Constructor implementation
Coins::Coins()
{
    // Set the coin image
    QPixmap coinPixmap("C:/Users/Merna/Downloads/coin-1.png");
    setPixmap(coinPixmap.scaled(50, 50));
}

#include "coins.h"
#include <QPixmap>

// Constructor implementation
Coins::Coins()
    : currentImage(0) // Initialize the image index to 0
{
    // Set the initial coin image
    QPixmap coinPixmap(":/Resources/img/coin-0.png");
    setPixmap(coinPixmap.scaled(50, 50));

    // Create and configure a timer for updating the coin image
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Coins::updateImage);
    timer->start(500); // 0.5-second interval
}

// Slot to update the coin image
void Coins::updateImage()
{
    // Define the image paths in the animation sequence
    QStringList coinImages = {
        ":/Resources/img/coin-0.png",
        ":/Resources/img/coin-1.png",
        ":/Resources/img/coin-1.png",
        ":/Resources/img/coin-2.png",
    };

    // Set the current image
    QPixmap coinPixmap(coinImages[currentImage]);
    setPixmap(coinPixmap.scaled(50, 50));

    // Update the index for the next image
    currentImage = (currentImage + 1) % coinImages.size();
}

/*#include "Score.h"
#include <QDebug>

// Constructor: Initialize score to 0 and highestScore to 0
Score::Score(QObject *parent) : QObject(parent), score(0), highestScore(0) {}

// Getter for the current score: returns the value of the `score`
int Score::getScore() const {
    return score;  // Return the current score
}

// Getter for the highest score: returns the value of the `highestScore`
int Score::getHighScore() const {
    return highestScore;  // Return the highest score
}

// Method to update the score by adding a given number of points
void Score::updateScore(int points) {
    score += points;  // Add the points to the current score

    // Check if the current score exceeds the highest score and update it if necessary
    if (score > highestScore) {
        highestScore = score;  // Update the highest score
    }

    showScore();  // Call showScore to display the updated scores
}

// Method to reset the score to 0
void Score::resetScore() {
    score = 0;  // Reset current score to 0
    showScore();  // Call showScore to display the reset score
}

// Method to display the current score and highest score in the console
void Score::showScore() const {
    // Qt's qDebug function prints messages to the debug output (console)
    qDebug() << "Current Score: " << score;  // Display the current score
    qDebug() << "Highest Score: " << highestScore;  // Display the highest score
}
*/

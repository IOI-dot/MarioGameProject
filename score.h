/*#ifndef SCORE_H
#define SCORE_H

#include <QString>
#include <QList>
#include <QDebug>
#include "Collectable.h"

class Score
{
public:
    Score() : score(0), highestScore(0) {}

    // Update the score and add collectable points
    void updateScore(int points) {
        score += points;
        if (score > highestScore) {
            highestScore = score;  // Update the highest score if needed
        }
    }
    //ya
    // Display the current score and the highest score
    void showScore() {
        qDebug() << "Current Score:" << score;
        qDebug() << "Highest Score:" << highestScore;
    }

    // Collect a collectable and add its value to the score
    void collectCollectable(Collectable* collectable) {
        qDebug() << "Collecting collectable of type" << collectable->getType();
        int gainValue = collectable->getGainValue();
        updateScore(gainValue);  // Add the collectable's value to the score
        collectable->collect();  // Handle the collectable (mark it as collected)
    }

    // Add a collectable to the list (for tracking all collectables in the game)
    void addCollectable(Collectable* collectable) {
        collectables.append(collectable);
    }

    // Display all collectables in the game (for debug purposes)
    void displayCollectables() {
        for (Collectable* collectable : collectables) {
            collectable->displayCollectable();
        }
    }

private:
    int score;                // Current score
    int highestScore;         // Highest score achieved
    QList<Collectable*> collectables;  // List of collectables in the game
};

#endif // SCORE_H*/

#include "Powerup.h"
#include <QDebug>

Powerup::Powerup(const QString &type, const QString &usage, const QString &effect, int duration, QObject *parent)
    : QObject(parent), type(type), usage(usage), effect(effect), duration(duration), active(false)
{
    // Initialize the QTimer for duration management
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Powerup::deactivate);  // Deactivate the powerup when the timer expires
}

QString Powerup::getType() const {
    return type;  // Return the type of the powerup
}

QString Powerup::getUsage() const {
    return usage;  // Return how the powerup can be used (once, unlimited)
}

QString Powerup::getEffect() const {
    return effect;  // Return the effect of the powerup (increase speed, invincibility)
}

int Powerup::getDuration() const {
    return duration;  // Return the duration of the powerup in seconds
}

bool Powerup::isActive() const {
    return active;  // Return whether the powerup is active or not
}

void Powerup::activate() {
    if (active) {
        qDebug() << "Powerup is already active!";
        return;  // If the powerup is already active, do nothing
    }

    // Set the powerup as active
    active = true;
    qDebug() << "Powerup activated: " << effect;

    // Start the timer to automatically deactivate the powerup after the duration
    if (duration > 0) {
        timer->start(duration * 1000);  // Start the timer (convert duration from seconds to milliseconds)
    }

    // Apply the effect (increase speed, make invincible)

}

void Powerup::deactivate() {
    if (!active) {
        return;  // If the powerup is already inactive, do nothing
    }

    // Set the powerup as inactive
    active = false;
    qDebug() << "Powerup deactivated: " << effect;

    // Stop the timer (just in case)
    timer->stop();

    // Revert the effect ( remove speed boost, remove invincibility)

}

void Powerup::reset() {
    // Reset the powerup state (useful for some powerups that are used multiple times or reset manually)
    active = false;
    timer->stop();
    qDebug() << "Powerup reset: " << effect;
}


#ifndef POWERUPS_H
#define POWERUPS_H

#include <QObject>
#include <QString>
#include <QTimer>

class Powerup : public QObject
{
    Q_OBJECT

public:
    explicit Powerup(const QString &type, const QString &usage, const QString &effect, int duration, QObject *parent = nullptr);

    // Getters
    QString getType() const;
    QString getUsage() const;
    QString getEffect() const;
    int getDuration() const;
    bool isActive() const;

    // Methods to activate, deactivate, and check powerup state
    void activate();   // Activates the powerup
    void deactivate(); // Deactivates the powerup
    void reset();      // Resets the powerup state ( after use or expiration mslan)

private:
    QString type;       // The type of the powerup ( "Speed Boost")
    QString usage;      // How the powerup can be used ( "once", "unlimited")
    QString effect;     // The effect of the powerup ( "Increase speed")
    int duration;       // How long the powerup lasts in seconds
    bool active;        // Whether the powerup is currently active

    QTimer *timer;      // Timer to track the duration of the powerup
};

#endif // POWERUP_H

#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <QWidget>
#include <QStackedWidget>
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Level5.h"  // Include the header for Level 5

class LevelManager : public QWidget
{
    Q_OBJECT

public:
    explicit LevelManager(QWidget *parent = nullptr);
    ~LevelManager();

    void startLevel1();
    void startLevel2();
    void startLevel3();
    void startLevel4();
    void startLevel5();  // New method for Level 5

private:
    QStackedWidget *stackedWidget;
    Level1 *level1;
    Level2 *level2;
    Level3 *level3;
    Level4 *level4;
    Level5 *level5;  // Pointer for Level 5
};

#endif // LEVELMANAGER_H

#include "LevelManager.h"
#include <QVBoxLayout>

LevelManager::LevelManager(QWidget *parent)
    : QWidget(parent),
    stackedWidget(new QStackedWidget(this)),
    level1(nullptr),
    level2(nullptr),
    level3(nullptr),
    level4(nullptr),
    level5(nullptr)  // Initialize Level 5 pointer
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(stackedWidget);
    this->setLayout(layout);

    startLevel1();  // Start with Level 1
}

LevelManager::~LevelManager()
{
}

void LevelManager::startLevel1()
{
    if (!level1)
    {
        level1 = new Level1(this);
        connect(level1, &Level1::levelCompleted, this, &LevelManager::startLevel2);
        stackedWidget->addWidget(level1);
    }
    stackedWidget->setCurrentWidget(level1);
    level1->startGame();
}

void LevelManager::startLevel2()
{
    if (!level2)
    {
        level2 = new Level2(this);
        connect(level2, &Level2::level2Completed, this, &LevelManager::startLevel3);
        stackedWidget->addWidget(level2);
    }
    stackedWidget->setCurrentWidget(level2);
    level2->startGame();
}

void LevelManager::startLevel3()
{
    if (!level3)
    {
        level3 = new Level3(this);
        connect(level3, &Level3::level3Completed, this, &LevelManager::startLevel4);
        stackedWidget->addWidget(level3);
    }
    stackedWidget->setCurrentWidget(level3);
    level3->startGame();
}

void LevelManager::startLevel4()
{
    if (!level4)
    {
        level4 = new Level4(this);
        connect(level4, &Level4::level4Completed, this, &LevelManager::startLevel5);  // Connect to Level 5
        stackedWidget->addWidget(level4);
    }
    stackedWidget->setCurrentWidget(level4);
    level4->startGame();
}

void LevelManager::startLevel5()
{
    if (!level5)
    {
        level5 = new Level5(this);  // Create Level 5
        connect(level5, &Level5::level5Completed, this, &LevelManager::startLevel1);  // Loop back to Level 1
        stackedWidget->addWidget(level5);
    }
    stackedWidget->setCurrentWidget(level5);
    level5->startGame();
}

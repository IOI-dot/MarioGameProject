QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    coins.cpp \
    collectables.cpp \
    enemy.cpp \
    fireball.cpp \
    goomba.cpp \
    level1.cpp \
    level2.cpp \
    level3.cpp \
    level4.cpp \
    level5.cpp \
    levelmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    obstacle.cpp \
    over.cpp \
    piranha.cpp \
    player.cpp \
    powerups.cpp \
    score.cpp \
    start.cpp \
    store.cpp \
    turtle.cpp \
    turtlefly.cpp

HEADERS += \
    coins.h \
    collectables.h \
    enemy.h \
    fireball.h \
    goomba.h \
    level1.h \
    level2.h \
    level3.h \
    level4.h \
    level5.h \
    levelmanager.h \
    mainwindow.h \
    obstacle.h \
    over.h \
    piranha.h \
    player.h \
    powerups.h \
    score.h \
    start.h \
    store.h \
    turtle.h \
    turtlefly.h

FORMS += \
    mainwindow.ui \
    over.ui \
    start.ui \
    store.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../Downloads/01. Ground Theme.mp3 \
    ../../../Downloads/01. Ground Theme.mp3 \
    Lucidchart super mario.docx \
    MARIO_PROJECT_GAME.pro.user \
    MARIO_PROJECT_GAME.pro.user.1a33b8a \
    MARIO_PROJECT_GAME.pro.user.40841d7 \
    MARIO_PROJECT_GAME.pro.user.4a76226 \
    MARIO_PROJECT_GAME.pro.user.9ddf80c

RESOURCES += \
    resources.qrc \
    resources.qrc

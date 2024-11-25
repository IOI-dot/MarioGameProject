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
    gameover.cpp \
    goomba.cpp \
    level1.cpp \
    main.cpp \
    mainwindow.cpp \
    obstacle.cpp \
    player.cpp \
    powerups.cpp \
    score.cpp \
    store.cpp

HEADERS += \
    coins.h \
    collectables.h \
    enemy.h \
    gameover.h \
    goomba.h \
    level1.h \
    mainwindow.h \
    obstacle.h \
    player.h \
    powerups.h \
    score.h \
    store.h

FORMS += \
    gameover.ui \
    mainwindow.ui \
    store.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../Downloads/01. Ground Theme.mp3 \
    ../../../Downloads/01. Ground Theme.mp3 \
    ../../../Downloads/block.png \
    ../../../Downloads/castle.png \
    ../../../Downloads/coin-1.png \
    ../../../Downloads/goomba-0.png \
    ../../../Downloads/goomba-dead.png \
    ../../../Downloads/mario-big-jump.png \
    ../../../Downloads/mario-big-stand.png \
    ../../../Downloads/mario-big-walk-0.png \
    ../../../Downloads/marioew.png

RESOURCES += \
    resources.qrc

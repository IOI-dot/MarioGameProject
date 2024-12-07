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
    gameover.cpp \
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
    piranha.cpp \
    player.cpp \
    powerups.cpp \
    score.cpp \
    store.cpp \
    turtle.cpp \
    turtlefly.cpp

HEADERS += \
    coins.h \
    collectables.h \
    enemy.h \
    fireball.h \
    gameover.h \
    goomba.h \
    level1.h \
    level2.h \
    level3.h \
    level4.h \
    level5.h \
    levelmanager.h \
    mainwindow.h \
    obstacle.h \
    piranha.h \
    player.h \
    powerups.h \
    score.h \
    store.h \
    turtle.h \
    turtlefly.h

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
    ../../../Downloads/01. Ground Theme.mp3

RESOURCES += \
    resources.qrc

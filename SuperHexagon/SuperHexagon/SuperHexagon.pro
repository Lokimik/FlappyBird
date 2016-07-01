#-------------------------------------------------
#
# Project created by QtCreator 2015-01-21T14:59:54
#
#-------------------------------------------------

QT       += core gui opengl multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SuperHexagon
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameinfo.cpp \
    GameElement/ebackgroundback.cpp \
    GameElement/ebackgroundfore.cpp \
    GameElement/ecentralhexagon.cpp \
    GameElement/ecursor.cpp \
    GameElement/emenubutton.cpp \
    GameElement/emodebutton.cpp \
    GameElement/emodeinfo.cpp \
    GameElement/eoptionsbutton.cpp \
    GameElement/gameelement.cpp \
    GameWidget/creaditswidget.cpp \
    GameWidget/gameplaywidget.cpp \
    GameWidget/mainmenuwidget.cpp \
    GameWidget/modeselectwidget.cpp \
    GameWidget/optionswidget.cpp \
    GameElement/etimekeeper.cpp \
    GameWidget/gameoverwidget.cpp \
    GameElement/eoverboard.cpp

HEADERS  += mainwindow.h \
    gameinfo.h \
    GameElement/ebackgroundback.h \
    GameElement/ebackgroundfore.h \
    GameElement/ecentralhexagon.h \
    GameElement/ecursor.h \
    GameElement/emenubutton.h \
    GameElement/emodebutton.h \
    GameElement/emodeinfo.h \
    GameElement/eoptionsbutton.h \
    GameElement/gameelement.h \
    GameWidget/creditswidget.h \
    GameWidget/gameplaywidget.h \
    GameWidget/mainmenuwidget.h \
    GameWidget/modeselectwidget.h \
    GameWidget/optionswidget.h \
    GameElement/etimekeeper.h \
    GameWidget/gameoverwidget.h \
    GameElement/eoverboard.h

RESOURCES += \
    resourse.qrc

OTHER_FILES +=

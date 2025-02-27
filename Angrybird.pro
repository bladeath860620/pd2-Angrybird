#-------------------------------------------------
#
# Project created by QtCreator 2016-06-14T20:55:33
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Angrybird
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    item.cpp \
    pointtransfer.cpp \
    bird.cpp \
    land.cpp \
    obstacle.cpp \
    ball_obstacle.cpp \
    bumpchecker.cpp \
    pig.cpp \
    results.cpp

HEADERS  += mainwindow.h \
    item.h \
    pointtransfer.h \
    bird.h \
    land.h \
    obstacle.h \
    ball_obstacle.h \
    bumpchecker.h \
    pig.h \
    results.h

FORMS    += mainwindow.ui \
    results.ui

LIBS += -L . -lBox2D

RESOURCES += \
    rsc.qrc

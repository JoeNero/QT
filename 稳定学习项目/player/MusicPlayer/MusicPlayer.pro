#-------------------------------------------------
#
# Project created by QtCreator 2019-10-09T14:40:10
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MusicPlayer
TEMPLATE = app


SOURCES += main.cpp\
        musicwindow.cpp \
    http.cpp \
    analysisjson.cpp \
    networkmusic.cpp \
    musicinformation.cpp \
    musicplayer.cpp \
    musicitem.cpp

HEADERS  += musicwindow.h \
    http.h \
    analysisjson.h \
    networkmusic.h \
    musicinformation.h \
    musicplayer.h \
    musicitem.h

FORMS    += musicwindow.ui

RESOURCES += \
    resources.qrc

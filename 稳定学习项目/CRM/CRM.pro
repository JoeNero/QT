#-------------------------------------------------
#
# Project created by QtCreator 2017-06-18T13:36:28
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CRM
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp\
        mainwindow.cpp \
    dlgitem.cpp

HEADERS  += mainwindow.h \
    dlgitem.h

FORMS    += mainwindow.ui \
    dlgitem.ui

RC_FILE += myapp.rc

RESOURCES += \
    rc.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2016-04-02T18:46:16
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sf
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mybutton.cpp \
    ship.cpp \
    coord.cpp

HEADERS  += mainwindow.h \
    mybutton.h \
    ship.h \
    coord.h

FORMS    += mainwindow.ui

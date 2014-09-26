#-------------------------------------------------
#
# Project created by QtCreator 2014-09-25T22:18:33
#
#-------------------------------------------------

QT       += core gui
QT       += network
CONFIG += thread
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    thread.cpp

HEADERS  += mainwindow.h \
    thread.h

FORMS    += mainwindow.ui

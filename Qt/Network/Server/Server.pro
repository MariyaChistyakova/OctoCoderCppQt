#-------------------------------------------------
#
# Project created by QtCreator 2014-08-18T21:16:42
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp \
    MyServer.cpp

HEADERS  += \
    MyServer.h

FORMS    += mainwindow.ui

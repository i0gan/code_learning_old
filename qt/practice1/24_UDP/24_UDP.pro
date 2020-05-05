#-------------------------------------------------
#
# Project created by QtCreator 2020-01-31T14:39:20
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 24_UDP
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
CONFIG += c++11

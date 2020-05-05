#-------------------------------------------------
#
# Project created by QtCreator 2020-01-29T12:27:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 13_QtEvent
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mylabel.cpp \
    mybutton.cpp

HEADERS  += widget.h \
    mylabel.h \
    mybutton.h

FORMS    += widget.ui
CONFIG += c++11

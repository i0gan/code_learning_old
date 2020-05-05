#-------------------------------------------------
#
# Project created by QtCreator 2020-02-06T00:02:02
#
#-------------------------------------------------

QT       += core gui sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CarManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    doxml.cpp

HEADERS  += mainwindow.h \
    doxml.h

FORMS    += mainwindow.ui

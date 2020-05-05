#-------------------------------------------------
#
# Project created by QtCreator 2020-02-08T16:40:08
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyQQ
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    dialoglist.cpp

HEADERS  += widget.h \
    dialoglist.h

FORMS    += widget.ui \
    dialoglist.ui

RESOURCES += \
    res.qrc
CONFIG += C++11

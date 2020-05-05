#-------------------------------------------------
#
# Project created by QtCreator 2020-01-31T11:06:22
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 23_QTcp_Server
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    clientwidget.cpp

HEADERS  += widget.h \
    clientwidget.h

FORMS    += widget.ui \
    clientwidget.ui
CONFIG += C++11

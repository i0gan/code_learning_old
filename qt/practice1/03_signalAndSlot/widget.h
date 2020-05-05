#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QDebug>
#include "subwindow.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    //explicit Widget(QWidget *parent = 0);
    Widget(QWidget *parent = 0);
    ~Widget();
signals:

public slots:
    void encrase();
    void changeWindow();
    void dealSub();
private:
    subWindow sbw;
};

#endif // WIDGET_H

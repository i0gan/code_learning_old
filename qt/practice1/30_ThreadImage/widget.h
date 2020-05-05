#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QThread>
#include "mythread.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    //paint event
    void paintEvent(QPaintEvent *);
    void getImage(QImage);
    void dealClose();

private:
    Ui::Widget *ui;
    QImage image;
    MyThread *myT; //my thread
    QThread *thread; //child thread
};

#endif // WIDGET_H

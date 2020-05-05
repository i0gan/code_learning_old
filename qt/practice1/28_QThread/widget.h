#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QThread> //sleep
#include <QDebug>
#include "qt4_tread.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void dealTimeout();
    void dealDone();
    void stopThread();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTimer *timer; //define a timer
    Qt4_Tread *thread; //thread object

};

#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <QDebug>
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
    void dealSignal();
    void dealClose();

private slots:
    void on_pushButtonStart_clicked();
    void on_pushButtonStop_clicked();

signals:
    void startThread(); //Signal to start a child thread
private:
    Ui::Widget *ui;
    MyThread *myT;
    QThread  *thread;
};

#endif // WIDGET_H

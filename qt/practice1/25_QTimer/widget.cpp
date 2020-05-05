#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout,
            [=](){
        static int i = 0;
        i++;
        ui->lcdNumber->display(i);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonStart_clicked()
{
    //Time interval is 100 ms
    //The timeout function is triggered every 100 milliseconds
    if(!timer->isActive()) {
    timer->start(10); //start timer
    }
}

void Widget::on_pushButtonStop_clicked()
{
    if(true == timer->isActive()) {
    timer->stop();
    }
}

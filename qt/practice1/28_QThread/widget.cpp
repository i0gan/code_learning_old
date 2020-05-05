#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    //a sginal timeout
    connect(timer, &QTimer::timeout, this, &Widget::dealTimeout);
    //malloc loacl thread
    thread = new Qt4_Tread(this);
    connect(thread, &Qt4_Tread::isDone, this, &Widget::dealDone);
    connect(this, &Widget::destroyed, this, &Widget::stopThread);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::dealTimeout() {
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

void Widget::on_pushButton_clicked()
{
    if(false == timer->isActive()) {
        timer->start();
    }
    //start thread ot deal with data
    thread->start();
}
void Widget::dealDone() {
    qDebug() << "OKOK";
    timer->stop(); //switch off timer
}
void Widget::stopThread() {
    qDebug() << "switch off window";
    thread->quit(); //quit thread
    thread->wait(); //wait quit
}

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //mytread malloc space, but can't to set father object
    myT = new MyThread;
    //create child thread
    thread = new QThread(this);

    //add mythread to child thread
    myT->moveToThread(thread);
    //Start child thread, but not start function
    thread->start();
    connect(ui->pushButton, &QPushButton::pressed, myT, &MyThread::drawImage);
    connect(myT, &MyThread::updateImage, this, &Widget::getImage);
    connect(this, &Widget::destroyed, this, &Widget::dealClose);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *) {
    QPainter p(this); //create a painter and father object as this
    p.drawImage(50, 50, image);
}
void Widget::getImage(QImage temp) {
    image = temp;
    update();
}
void Widget::dealClose() {
    thread->quit();
    thread->wait();
    delete myT;
    this->close();

}

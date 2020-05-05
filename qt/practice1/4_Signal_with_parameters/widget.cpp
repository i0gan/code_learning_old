#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->t_1 = new QTextEdit(this);
    t_1->setText("Hello");
    t_1->move(50,50);
    w2.show();
    this->resize(400, 200);
    this->setWindowTitle("MainWindow");

    void (win2::*S_1)() = &win2::MySingal;
    void (Widget::*D_1)() = &Widget::dealWith;
    connect(&w2, S_1, this, D_1);

    void (win2::*S_2)(QString, int) = &win2::MySingal;
    void (Widget::*D_2)(QString, int) = &Widget::dealWith;
    connect(&w2, S_2, this, D_2);
}

Widget::~Widget(){
}
void Widget::dealWith() {
    qDebug() << "Send a msg";
}

void Widget::dealWith(QString a, int b) {
    this->t_1->setText(a);
    qDebug() << a.toUtf8().data(); //From QString to C String

}

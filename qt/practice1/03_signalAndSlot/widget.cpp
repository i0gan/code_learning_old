#include "widget.h"

int xx = 400;
int yy = 200;



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *q = new QPushButton("encrase");
    q->show();
    q->setParent(this);
    this->resize(xx, yy);
    this->setWindowTitle(QString("Main"));


    QPushButton *bt_2 = new QPushButton("change window");
    bt_2->move(50, 50);
    bt_2->setParent(this);


    connect(q, SIGNAL(clicked()), this, SLOT(encrase()));
    connect(bt_2, SIGNAL(clicked()), this, SLOT(changeWindow()));

    connect(&sbw, SIGNAL(S_changeWindow()), this, SLOT(dealSub()));

}

Widget::~Widget()
{


}
void Widget::encrase() {
    qDebug() << "|";
    xx = xx + 100;
    yy = yy + 50;

    this->resize(xx, yy);
    //b->setText(QString("OK"));

}
void Widget::changeWindow() {
    this->sbw.show();
    this->hide();
}
void Widget::dealSub() {
    this->show();
    this->sbw.hide();

}

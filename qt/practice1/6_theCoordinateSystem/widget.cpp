#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //For the parent window, the coordinate system
    //is relative to the screen

    // x increases to the right
    // y goes down

    QPushButton *a = new QPushButton(this);
    resize(400, 200);
    a->setText("^_^");
    a-> move(100, 50);
    a->resize(150, 100);
    QPushButton *b = new QPushButton(a);
    b->move(30, 10);
    b->setText("@_@");

}

Widget::~Widget()
{

}

#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //Lambda formular
    //c++11 new feature,it is very convenient to use
    //Add 'CONFIG += C++11' to the project file

    QPushButton *b = new QPushButton(this);
    this->resize(400,200);
    b->setText("Lambda");
    b->move(50,50);
    //'[]' : Square brackets indicate passing in external variables
    // You can use it:
    //[a, b, c....] Passes the specified variable  (read only)
    //mutable  : Allows incoming variables to be modified

    //[=]  Pass all variables
    //[&]  Pass in all local variables that are external, but it's easy to make mistakes
    //[this] Pass the this pointer from the class

    //() To take the parameters of the signal function
    int a = 4;
    connect(b, &QPushButton::clicked,
            [a](bool isCheck) mutable {
            a = 5;
            qDebug() << "HELLO " << a << isCheck;

            }

            );

}

Widget::~Widget()
{

}

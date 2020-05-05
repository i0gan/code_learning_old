#include "mybutton.h"
#include <QMouseEvent>
#include <QDebug>
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}

void MyButton::mousePressEvent(QMouseEvent *e) {
    e->ignore();

    if(e->button() == Qt::LeftButton) {

        qDebug() << "Mose Left Button!";

    }else {


    }

    QPushButton::mousePressEvent(e);
}

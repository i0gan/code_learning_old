#include "mylabel.h"
#include <QMouseEvent>
myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);
}

void myLabel::mousePressEvent(QMouseEvent *ev) {
    int x = ev->x();
    int y = ev->y();
    /*
     * QString str = QString("abc %1 ^_^ %2").arg(123).arg("mike");
     * str = abc 123 ^_^ mike
    */

    if(ev->button() == Qt::RightButton) {
        qDebug() << "Mouse click right button";
    }else if(ev->button() == Qt::LeftButton) {
        qDebug() << "Mouse click left button";
    }
    else if(ev->button() == Qt::MidButton) {
        qDebug() << "Mouse click mid button";
    }

    QString text = QString("<center><h1> Mouse Press: (%1, %2)</h1></center>").arg(x).arg(y);
    this->setText(text);


}
void myLabel::mouseReleaseEvent(QMouseEvent *ev) {
    int x = ev->x();
    int y = ev->y();
    QString text = QString("<center><h1> Mouse Relase: (%1, %2)</h1></center>").arg(x).arg(y);
    this->setText(text);
}
void myLabel::mouseMoveEvent(QMouseEvent *ev) {
    int x = ev->x();
    int y = ev->y();
    QString text = QString("<center><h1> Mouse move: (%1, %2)</h1></center>").arg(x).arg(y);
    this->setText(text);

}
void myLabel::enterEvent(QEvent *ev) {
    QString text = QString("<center><h1> enter </h1></center>");
    qDebug() << text;
}
void myLabel::leaveEvent(QEvent *ev) {

    QString text = QString("<center><h1> leave </h1></center>");
    this->setText(text);
}


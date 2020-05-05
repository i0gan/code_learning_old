#include "mythread.h"

MyThread::MyThread(QObject *parent) : QObject(parent)
{

}

void MyThread::drawImage() {
    //Define QImatge device
    QImage image(500, 500, QImage::Format_ARGB32);
    //Define painter and device
    QPainter p(&image);
    //define 5 pointer
    QPoint a[] = {
        QPoint(qrand() % 500, qrand() % 500),
        QPoint(qrand() % 500, qrand() % 500),
        QPoint(qrand() % 500, qrand() % 500),
        QPoint(qrand() % 500, qrand() % 500),
        QPoint(qrand() % 500, qrand() % 500)
    };
    //define pen
    QPen pen;
    pen.setWidth(5); //set width
    //set pen to painter
    p.setPen(pen);
    //define brush
    QBrush brush;
    brush.setStyle(Qt::Dense1Pattern);
    brush.setColor(Qt::red);
    //set brush to painter
    p.setBrush(brush);
    //draw 5 points
    p.drawPolygon(a, 5);
    //send image
    emit updateImage(image);

}

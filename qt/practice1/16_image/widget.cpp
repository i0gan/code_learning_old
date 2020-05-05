#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //set backtroun as transparent
    QImage image(400, 300, QImage::Format_ARGB32);
    QPainter p;
    p.begin(&image);

    p.drawImage(0, 0, QImage("://butterfly.png"));

    for(int i = 100; i <250; i++) {
        for(int j = 100; j< 250; j++) {
            image.setPixel(QPoint(i, j), qRgb(0, 10, 100)); //set pixel pointer
            // image.pixel(QPoint(3, 4)) get pixel
        }
    }
    p.end();
    image.save("../out.png");
}

Widget::~Widget()
{
    delete ui;
}

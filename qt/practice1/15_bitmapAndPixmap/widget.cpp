#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Draw device
    QPixmap pixmap(400, 400);
    QPainter p(&pixmap);
    //fill in white to background
    p.fillRect(0, 0, 400, 400, QBrush(Qt::white));
    //pixmap.fill(Qt::white);
    p.drawPixmap(0, 0, 100, 100, QPixmap(":/butterfly.png"));
    pixmap.save("../out.png"); //save pixmap to file
    qDebug() << "OK";

}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    //QPixmap -> the picture is transparent
    p.drawPixmap(0, 0, QPixmap("://butterfly.png"));
    //QBitmap -> the picture is transparent
    p.drawPixmap(200, 0, QBitmap("://butterfly.png"));

    QPixmap pixmap; //Backgroun is white
    pixmap.load(":/butterfly1.png");
    p.drawPixmap(0, 200, pixmap);

    QBitmap bitmap; //Backgroun is white
    bitmap.load(":/butterfly1.png");
    p.drawPixmap(200, 200, bitmap);

}

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPicture picture;
    QPainter p;
    p.begin(&picture);

    p.drawPixmap(0, 0, 100, 100, QPixmap(":/new/prefix1/butterfly.png"));
    p.drawLine(50, 50, 100, 100);
    p.end();
    picture.save("../picture.out"); //save as binary file

}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *) {
#if 0
    QPicture pic;
    pic.load("../picture.out"); //load binary file

    QPainter p(this);
    p.drawPicture(0, 0, pic);

#endif
    QPainter p(this);
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/butterfly.png");
    QImage tmpImage = pixmap.toImage();
    p.drawImage(40, 40, tmpImage);

    QImage image;
    image.load(":/new/prefix1/butterfly.png");

    //QImage -> QPixmap
    QPixmap tmpPixmap = QPixmap::fromImage(image);
    p.drawPixmap(240, 40, tmpPixmap);

}

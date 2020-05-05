#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *) {
    //QPainter p(this);
    /*
     * QPainter p;
     * p.begin(this); //set paint device as widget
     * // Paint..
     * p.end();
    */

    QPainter p;
    p.begin(this);
    qDebug() << "aa";
    //Set background with image
    p.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/q.jpg"));
    //p.drawPixmap(rect(), QPixmap(":/q.jpg"));

    //painting
    p.drawLine(10, 10, 100, 100); //start postion and end postion

    //defin a pen
    QPen pen;
    pen.setWidth(5); //set wigth of pen
    //pen.setColor(Qt::green);
    pen.setColor(QColor(14, 9, 234));
    pen.setStyle(Qt::DashLine);
    p.setPen(pen); // set the pen to p
    p.drawLine(10, 100, 100, 10);

    // Draw rectangel
    p.drawRect(100, 100, 40, 60); // postion and wigth & hight
    // Circle drawing or Drawing ellipse
    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::CrossPattern);
    p.setBrush(brush);
    p.drawEllipse(QPoint(x, 150), 100, 60);


    p.end();


}

void Widget::on_pushButton_clicked()
{
    this->x += 20;
    if(x > this->width()) {
        x = 0;
    }
    this->update(); // update the paint window
}

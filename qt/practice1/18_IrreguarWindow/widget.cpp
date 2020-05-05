#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Remove borders
    setWindowFlags(Qt::FramelessWindowHint); // | windowFlags());

    //set Window as transparent
    setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawPixmap(0, 0, QPixmap("://Luffy.png"));

}
void Widget::mouseMoveEvent(QMouseEvent *e) {
    if(e->buttons() & Qt::LeftButton) {
        this->move(e->globalPos() - pos);
    }
}
void Widget::mousePressEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton) {
        //calclate the difference of coordinates
        //SubStract the coordinates of the upper left corner of the
        //window from the current coordinates
        pos = e->globalPos() - this->frameGeometry().topLeft();
    }else if(e->button() == Qt::RightButton) {
        this->close();
    }
}

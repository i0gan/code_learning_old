#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QByteArray a;
    QDataStream b(&a, QIODevice::WriteOnly);
    b << "dddd";
    qDebug() << a;
}

Widget::~Widget()
{
    delete ui;
}

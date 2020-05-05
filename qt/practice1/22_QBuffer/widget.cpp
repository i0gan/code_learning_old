#include "widget.h"
#include "ui_widget.h"
#define qd qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QByteArray array;
    QBuffer buf(&array); //create a file buffer and let data write to array
    buf.open(QIODevice::ReadWrite);

    buf.write("1323409523asdf\n");
    buf.write("jaksdf asjdfj");
    buf.close();
    qd << buf.buffer();
    qd << "array" << array;

    QBuffer buf2;
    buf2.open(QIODevice::WriteOnly);
    QDataStream stream(&buf2);
    stream << QString("Just a test!") << 250;
    buf2.close();

    buf2.open(QIODevice::ReadOnly);
    QDataStream streamIn;
    streamIn.setDevice(&buf2);
    QString str;
    int num;
    streamIn >> str >> num;
    qd << str << num;
}

Widget::~Widget()
{
    delete ui;
}

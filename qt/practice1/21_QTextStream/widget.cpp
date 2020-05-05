#include "widget.h"
#include "ui_widget.h"

#define qout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    writeData();
    readData();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::writeData() {
    QFile file;
    file.setFileName("../test.txt");

    bool isOpen = file.open(QIODevice::WriteOnly);
    if(true == isOpen) {
        QTextStream stream(&file);
        //set code
        stream.setCodec("UTF-8");
        stream << QString("Hello You guys") << 250;
    }
    file.close();
}

void Widget::readData() {
    QFile file;
    file.setFileName("../test.txt");

    bool isOpen = file.open(QIODevice::ReadOnly);
    if(true == isOpen) {
        QTextStream stream(&file);
        //set code
        stream.setCodec("UTF-8");
        QString str;
        str = stream.readAll();
        qout << str.toUtf8().data();

    }
    file.close();
}

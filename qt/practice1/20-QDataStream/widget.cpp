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
    QFile file("../test.txt");
    bool isOpen = file.open(QIODevice::WriteOnly);
    if(true == isOpen) {
        //Create a data stream, and associate files with data stream

        QDataStream stream(&file);
        stream << QString("FucKKKKing! ") << 250;
    }
    file.close();


}
void Widget::readData() {
    QFile file("../test.txt");
   bool isOpen = file.open(QIODevice::ReadOnly);
   if(isOpen == true) {
        QDataStream stream(&file);
        QString str;
        int a;
        stream >> str >> a;
        qout << str << a;
   }
}

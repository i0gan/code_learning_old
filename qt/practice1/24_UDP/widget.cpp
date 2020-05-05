#include "widget.h"
#include "ui_widget.h"
#define PORT 7890
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //malloc mem
    udpSoket = new QUdpSocket(this);
    //bind socket
    udpSoket->bind(QHostAddress::Any, 8888);
    //setWindowTitle("UDP group");
    //jone group
    //udpSoket->joinMulticastGroup(QHostAddress("224.0.0.2"));
    //udpSoket->leaveMulticastGroup() //leave group

    //It will invoke this if recv data from host
    connect(udpSoket, &QUdpSocket::readyRead, this, &Widget::dealMsg);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::dealMsg() {
    //read msg from host
    char buf[1024] = {0};
    QHostAddress hAddr; // host ip
    quint16 port; //host por
    qint64 len = udpSoket->readDatagram(buf, sizeof(buf), &hAddr, &port);
    //if(len > 0) {
        QString str = QString("[%1:%2]%3").arg(hAddr.toString()).arg(port).arg(buf);
        ui->textEdit->append(str);

    //}
}

void Widget::on_pushButtonSend_clicked()
{
    QString ip = ui->lineEditIp->text();
    qint16 port = ui->lineEditPort->text().toInt();
    QString text = ui->textEdit->toPlainText();
    //send data
    udpSoket->writeDatagram(text.toUtf8().data(), QHostAddress(ip), port);

}

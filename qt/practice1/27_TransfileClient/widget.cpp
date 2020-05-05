#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    isStart = true;
    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, &QTcpSocket::readyRead,
            [=]() {

        QByteArray buf = tcpSocket->readAll();
        //Recv content of head
        if(true == isStart) {//file info
             isStart = false;
            //Parsing header information
            // "filename##size";
            fileName = QString(buf).section("##", 0, 0); // in 0 section to 0 secion
            fileSize = QString(buf).section("##",1, 1).toInt(); // in 1 section to 1 section
            recvSize = 0;
           file.setFileName(fileName);
           bool isOpen = file.open(QIODevice::WriteOnly);
           if(false == isOpen) {
               qDebug() << "Write error!";
           }

        }else {
            qint64 len = file.write(buf);
            recvSize += len;
            if(recvSize == fileSize) {
                file.close();
                QMessageBox::information(this, "finish", "the file recved!");
                tcpSocket->disconnectFromHost();
                tcpSocket->close();
            }
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //Get sever ip and port
    QString ip = ui->lineEditServerIp->text();
    quint16 port = ui->lineEditServerPort->text().toInt();
    tcpSocket->connectToHost(QHostAddress(ip), port);

}

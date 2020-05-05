#include "widget.h"
#include "ui_widget.h"

#define SERVERPORT 8888
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{  
    ui->setupUi(this);
    ui->textEditread->setText(QString("Discnnected"));
    isConnect = false;
    setWindowTitle(QString("Server"));
    //set father object as this
    tcpServer = new QTcpServer(this);
    qint16 lport = 8888;
    tcpServer->listen(QHostAddress::Any, lport);

    qDebug() << "OK!";

    connect(tcpServer, &QTcpServer::newConnection,//Connect
            [=](){
        qDebug() << "OK!";
        isConnect = true;
            //Take out the newly established socket
        tcpSocket = tcpServer->nextPendingConnection();

        //Get the ip and port of the other party
        QString ip = tcpSocket->peerAddress().toString();
        qint16 port = tcpSocket->peerPort();
        QString Text = QString("[%1:%2]: connected").arg(ip).arg(port);
        ui->textEditread->setText(Text);

        //if connected recvdata
        connect(tcpSocket, &QTcpSocket::readyRead,
                [=](){
                QByteArray array = tcpSocket->readAll(); //recv data
                ui->textEditread->append(array);
        });
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonSend_clicked()
{
    if(isConnect) {

     //Get the content of area of edit
    QString text = ui->textEditWrite->toPlainText();
    //Send data to client
    tcpSocket->write(text.toUtf8().data());
}else {
        ui->textEditread->setText(QString("No client!"));
    }

}

void Widget::on_pushButtonDiscnnect_clicked()
{
    if(isConnect) {
    //disconnect
    ui->textEditread->setText(QString("Discnnected"));
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    isConnect = false;
    }
}

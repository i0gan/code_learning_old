#include "widget.h"
#include "ui_widget.h"
#define PORT 8888
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    sPort = PORT;
    //set two buttons can't use
    ui->pushButtonSelect->setEnabled(false);
    ui->pushButtonSend->setEnabled(false);

    tcpSever = new QTcpServer(this);
    setWindowTitle("Server");

    //listen
    tcpSever->listen(QHostAddress::Any, sPort);
    connect(tcpSever, &QTcpServer::newConnection,
            [=](){
        //get soket
        tcpSocket = tcpSever->nextPendingConnection();
        //get ip from client
        QString ip = tcpSocket->peerAddress().toString();
        quint16 cPort = tcpSocket->peerPort();

        QString text = QString("[%1:%2]").arg(ip).arg(cPort);
        ui->textEdit->setText(text);

        ui->pushButtonSelect->setEnabled(true);
    });
    connect(&timer, &QTimer::timeout,
            [=](){
        timer.stop();
        //Start to send file
        sendData();
    });
}

Widget::~Widget()
{
    delete ui;
}
//Select file
void Widget::on_pushButtonSelect_clicked()
{
    QString filePath  = QFileDialog::getOpenFileName(this, "Open", "../");
    if(false == filePath.isEmpty()) { //if select file is valid
        //Get infomation of target file
        fileName.clear();
        fileSize = 0;
        sendSize = 0;
        QFileInfo info(filePath);
        fileName = info.fileName(); //Get file name
        fileSize = info.size();     //Get file size
        //Open file
        file.setFileName(filePath);
        bool isOpen = file.open(QIODevice::ReadOnly);
        if(false == isOpen){
            qDebug() << "Open file fali!";
            return;
        }
        ui->textEdit->append(filePath);
        ui->pushButtonSelect->setEnabled(false);
        ui->pushButtonSend->setEnabled(true);

    }else {
        qDebug() << "Select file is invalid";

    }
}
//Send file
void Widget::on_pushButtonSend_clicked()
{
    /*First send the file header information,
     * then send the file content
    */
    //file name ## file size
    QString head = QString("%1##%2").arg(fileName).arg(fileSize);
    qint64 len = tcpSocket->write(head.toUtf8());
    if(len > 0) {
        /*Send real file informatiom
         * In order to prevent TCP packet sticking
         * timer is needed to prevent it
        */
        timer.start(20);

    }else {
        file.close();;
        ui->pushButtonSelect->setEnabled(true);
        ui->pushButtonSend->setEnabled(false);
        qDebug() << "Send head information fail!";
    }



}
void Widget::sendData() {
    qint64 len = 0;
    do {
        //Send 4k every time
        char buf[4 * 1024] = {0};
        len = 0;
        len = file.read(buf, sizeof(buf));
        //Send data
        tcpSocket->write(buf,len);
        sendSize += len;
    }while(len > 0);

    //judge file if finish to send
    if(sendSize >= fileSize) {
        ui->textEdit->append("Send finish");
        //close
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
    }
}

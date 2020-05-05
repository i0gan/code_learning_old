#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, &QTcpSocket::connected,
            [=]() {
       ui->textEditRead->setText("server connected");
    });

    connect(tcpSocket, &QTcpSocket::readyRead,
            [=]() {
        //Get conntent from host
        QByteArray array = tcpSocket->readAll();
        //show
        ui->textEditRead->append(array);
    });
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_pushButtonConnect_clicked()
{
    //get server ip and port
    QString ip = ui->lineEditIp->text();
    qint16 port = ui->lineEditPort->text().toInt();

    //Connect host
    tcpSocket->connectToHost(QHostAddress(ip), port);
}

void ClientWidget::on_pushButtonSend_clicked()
{
    QString Text = ui->textEditWrite->toPlainText();
    tcpSocket->write(Text.toUtf8().data());
    qDebug() << "send " << Text.toUtf8().data();
}

void ClientWidget::on_pushButtonDisconnect_clicked()
{
      tcpSocket->disconnectFromHost();
      tcpSocket->close();
}

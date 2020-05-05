#include "dialoglist.h"
#include "ui_dialoglist.h"

DialogList::DialogList(QWidget *parent, QString title) :
    QWidget(parent),
    ui(new Ui::DialogList)
{
    ui->setupUi(this);
    //init
    udpSocket = new QUdpSocket(this);
    //get name;
    uName = title;
    this->port = 9999;   //             share ip adrr            if as not online will reconnect
    udpSocket->bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    //send new user enter
    sendMsg(UserEneter);

    connect(ui->pushButtonSend, &QPushButton::clicked, [=](){
        sendMsg(Msg);
    });
    //listen data from others
    connect(udpSocket, &QUdpSocket::readyRead, this, &DialogList::ReceiveMessage);
    //quit btn
    connect(ui->pushButtonQuit, &QPushButton::clicked, [=](){
        this->close();
    });
    //font
    connect(ui->fontComboBox, &QFontComboBox::currentFontChanged, [=](const QFont &font){
       ui->textEdit->setCurrentFont(font);
       ui->textEdit->setFocus();
    });
}

DialogList::~DialogList()
{

    delete ui;
}
void DialogList::closeEvent(QCloseEvent *e) {
     emit this->WindowClose();
    sendMsg(UserLeft);
    //disconnect socket
    udpSocket->close();
    udpSocket->destroyed();
   // DialogList::closeEvent(e);
}
void DialogList::sendMsg(MsgType type){ //send msg
 //Send mes as 3 types
    QByteArray array;
    //type + username + content
    QDataStream stream(&array, QIODevice::WriteOnly);
    stream << type << getUser(); //Add first content to stream
    switch (type) {
    case Msg:
        if(ui->textEdit->toPlainText() == "") {
            QMessageBox::warning(this, "warning", "send message can't be null");
            return;
        }
        stream << getMsg(); //send content
        //send
        //Broadcast transmission
        udpSocket->writeDatagram(array, QHostAddress::Broadcast, port);
        break;
    case UserEneter:
        udpSocket->writeDatagram(array, QHostAddress::Broadcast, port);
        break;
    case UserLeft:
        udpSocket->writeDatagram(array, QHostAddress::Broadcast, port);
        break;
    default:
        break;
    }
}
QString DialogList::getMsg() {
    QString str = ui->textEdit->toHtml();
    //clear
    ui->textEdit->clear();
    ui->textEdit->setFocus();
    return str;
}
void DialogList::ReceiveMessage() {
    //retave data
    QByteArray array = QByteArray(4096, 0);
    qint64 size = udpSocket->pendingDatagramSize();
    udpSocket->readDatagram(array.data(), size);

    //jiexi  type + content

    QDataStream stream (&array, QIODevice::ReadOnly);
    int msgType;
    QString userName;
    QString msg;
    QString Time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm");
    stream >> msgType;
    switch(msgType) {
    case Msg: {
        //append text
        //set color
        stream >> userName >> msg;
        ui->textBrowser->setTextColor(Qt::blue);
        ui->textBrowser->append(Time + "[" + userName + "]" );
        ui->textBrowser->append(msg);
    }
        break;
    case UserEneter:
        qDebug() << "enter";
          stream >> userName;
          userEnter(userName);
        break;
    case UserLeft:
        qDebug() << "left";
        stream >> userName;
        userLeft(userName, Time);
        break;
    default:
        break;
    }
}
QString DialogList::getUser() {
    return this->uName;
}
void DialogList::userEnter(QString userName) {
    //update interface

    bool isEmpty = ui->tableWidget->findItems(userName, Qt::MatchExactly).isEmpty();
    if(isEmpty) {
        QTableWidgetItem * user = new QTableWidgetItem(userName);
        //insert line
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0, 0, user);
        //add record
        ui->textBrowser->setTextColor(Qt::gray);
        ui->textBrowser->append(QString("%1 user enter").arg(userName));
        //update the number of people
        ui->label->setText(QString("online: %1").arg(ui->tableWidget->rowCount()));
        //send msg
        sendMsg(UserEneter);
    }
}
void DialogList::userLeft(QString userName, QString time) {
    //update tableWidget
    if(! ui->tableWidget->findItems(userName, Qt::MatchExactly).isEmpty()) {
        int row = ui->tableWidget->findItems(userName, Qt::MatchExactly).first()->row();
        ui->tableWidget->removeRow(row);
        //append communication record
        ui->textBrowser->setTextColor(Qt::gray);
        ui->textBrowser->append(QString("%1   %2 user left").arg(time).arg(userName));
        ui->label->setText(QString("online: %1").arg(ui->tableWidget->rowCount()));
    }
}

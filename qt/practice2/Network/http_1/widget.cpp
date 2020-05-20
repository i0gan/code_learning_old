#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();

}
void Widget::init() {
    qNetworkAccessManager = new QNetworkAccessManager();
    connect(qNetworkAccessManager, &QNetworkAccessManager::finished, this, &Widget::dealWithRequestReply);

}
Widget::~Widget()
{
    delete ui;
}

void Widget::dealWithRequestReply(QNetworkReply *reply) {
    QByteArray data = reply->readAll();
    ui->textBrowser->setText(data);
    qDebug() << data;
}

void Widget::on_pushButtonSearch_clicked()
{
    QNetworkRequest request;
    request.setUrl(QUrl(ui->lineEdit->text()));
    request.setRawHeader("User-Agent", "QT5.User");
    qNetworkAccessManager->get(request);
    qDebug() << "dasd";
}

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void sendData();

private slots:
    void on_pushButtonSelect_clicked();

    void on_pushButtonSend_clicked();

private:
    Ui::Widget *ui;
    QTcpServer *tcpSever; //tcp server
    QTcpSocket *tcpSocket; //soket of server
    qint16 sPort;
    QFile file; // file object
    QString fileName;
    qint64 fileSize;
    qint64 sendSize;
    QTimer timer;
};

#endif // WIDGET_H

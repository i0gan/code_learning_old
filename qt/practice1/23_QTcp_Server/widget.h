#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer> // Listen socket
#include <QTcpSocket> //communicate socket
#include <QByteArray>
#include <QDebug>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButtonSend_clicked();

    void on_pushButtonDiscnnect_clicked();

private:
    Ui::Widget *ui;
    QTcpServer *tcpServer; //listen sock
    QTcpSocket *tcpSocket; //communicate socket
    bool isConnect;
};

#endif // WIDGET_H

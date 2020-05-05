#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket> //UDP socket
#include <QHostAddress>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void dealMsg(); //slot function to deal with msg

private slots:
    void on_pushButtonSend_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket *udpSoket;

};

#endif // WIDGET_H

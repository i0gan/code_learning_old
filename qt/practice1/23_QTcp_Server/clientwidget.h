#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>

namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = 0);
    ~ClientWidget();

private slots:
    void on_pushButtonConnect_clicked();

    void on_pushButtonSend_clicked();

    void on_pushButtonDisconnect_clicked();

private:
    Ui::ClientWidget *ui;
    QTcpSocket *tcpSocket;
    bool isConnect;
};

#endif // CLIENTWIDGET_H

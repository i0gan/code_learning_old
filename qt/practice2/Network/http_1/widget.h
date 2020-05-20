#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QNetworkRequest>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void init();

private slots:
    void on_pushButtonSearch_clicked();
    void dealWithRequestReply(QNetworkReply *);

private:
    Ui::Widget *ui;
    QNetworkAccessManager *qNetworkAccessManager;
};
#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QMovie>
#include <QDebug>
#include <QTime>
#include <QMessageBox>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void dealNum();
private slots:
    void on_ptbStart_clicked();

    void on_ptbExit_clicked();

    void on_pbtDel_clicked();

    void on_pbtHint_clicked();

private:
    Ui::Widget *ui;
    int gameTime;
    QString randStr;
    int gameTimerId;
    int overTimerId;
    int winTimerId;
    QString resultStr;

    QMovie startMovie;
    QMovie overMovie; //lose animation
    QMovie winMovie; //win animation


protected:
    void timerEvent(QTimerEvent *);


};

#endif // WIDGET_H

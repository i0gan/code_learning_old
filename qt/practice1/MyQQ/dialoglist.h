#ifndef DIALOGLIST_H
#define DIALOGLIST_H

#include <QWidget>
#include <QDebug>
#include <QUdpSocket>
#include <QDataStream>
#include <QMessageBox>
#include <QDateTime>
namespace Ui {
class DialogList;
}

class DialogList : public QWidget
{
    Q_OBJECT
    enum MsgType {Msg, UserEneter, UserLeft};
public:
    explicit DialogList(QWidget *parent, QString title);
    ~DialogList();
    void sendMsg(MsgType type); //send msg
    void userEnter(QString username);
    void userLeft(QString username, QString time);
    QString getUser(); //get user name
    QString getMsg(); //get information of communication
    void ReceiveMessage(); // recv udb imformation
private:
    Ui::DialogList *ui;
    QUdpSocket * udpSocket;
    qint16 port; /// port
    QString uName; //user name

signals:
    void WindowClose();// close signal
protected:
    void closeEvent(QCloseEvent *);
};

#endif // DIALOGLIST_H

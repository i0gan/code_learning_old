#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QObject>
#include <QThread>
#include <QDebug>
class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    //thread processing function
    void myTimeout();
    void setFlag(bool flag = true); //to stop thread flag

signals:
    void mySingal();

public slots:
private:
    bool isStop;
};

#endif // MYTHREAD_H

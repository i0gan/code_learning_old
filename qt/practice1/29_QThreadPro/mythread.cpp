#include "mythread.h"

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    isStop = false;

}
void MyThread::myTimeout() {
    while(false == isStop) {
        QThread::sleep(1);
        emit mySingal();
        qDebug() << "Sec thread id: " << QThread::currentThreadId();
    }
}
void MyThread::setFlag(bool flag) {
    isStop = flag;
}

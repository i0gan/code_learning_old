#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //It can't set father object
    myT = new MyThread(); //it must be no father object
    //Create a sun thread
    thread = new QThread(this);
    //let out thread join in sun thread
    myT->moveToThread(thread);
    connect(myT, &MyThread::mySingal, this, &Widget::dealSignal);
    qDebug() << "Main thread id: " << QThread::currentThreadId();
    connect(this, &Widget::startThread, myT, &MyThread::myTimeout, Qt::QueuedConnection);

    connect(this, &Widget::destroyed, this, &Widget::dealClose);//deal with close thread when close the window
    /*Graphical interface operation is not allowed inside a thread fuction
     *Function of the fifith parameter of connect function: connection mode:
     * default, queue, direct.
     * Multithreading makes sense
     * In case of multithreading,the queue is used by default
     * If it is single thread, direct mode is used by default
     * Queues: slot functions are on the same thread as the receiver;
     * Direct: slot function is in the same thread as the sender
     */

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonStart_clicked()
{
    if(thread->isRunning() == false) {
    myT->setFlag(false);
    //start thread, but do not start  deal with function
    thread->start();
    /*A direct call will cause the handler to be on the same thread
     *as the main thread
    */
    //myT->myTimeout();
    //Can only be called by signals and slots
    emit startThread();
    }
}
void Widget::dealSignal() {
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

void Widget::on_pushButtonStop_clicked()
{
    if(thread->isRunning() == true) {
    myT->setFlag(true);
    thread->quit();
    thread->wait();
    }
}
void Widget::dealClose() {
    delete myT;
    on_pushButtonStop_clicked();
}

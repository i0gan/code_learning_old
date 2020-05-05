#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QObject>
#include <QImage>
#include <QPainter>
#include <QPen>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    //thread deal with funciton
    void drawImage();

signals:
    void updateImage(QImage temp);

public slots:
};

#endif // MYTHREAD_H

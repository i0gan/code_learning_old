#ifndef QT4_TREAD_H
#define QT4_TREAD_H
#include <QThread>

class Qt4_Tread : public QThread
{
    Q_OBJECT
public:
    explicit Qt4_Tread(QObject *parent = 0);

signals:
    void isDone();
public slots:
protected:
    /*Thread processing function
     * It can't be used directly. You need to start it with the start function
    */
    void run();

};

#endif // QT4_TREAD_H

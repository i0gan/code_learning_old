#ifndef WIN_2_H
#define WIN_2_H
#include <QString>

class win_2 : public QWidget
{
    Q_OBJECT
public:
    //explicit Sginal(QWidget *parent = 0);
    win_2();
signals:

    void Signal(int q, QString d);
public slots:
    void emitSginal();
};

#endif // WIN_2_H

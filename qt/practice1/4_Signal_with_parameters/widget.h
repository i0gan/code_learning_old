#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QTextEdit>
#include "win2.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
signals:

public slots:
    void dealWith();
    void dealWith(QString a, int b);

private:
    win2 w2;
    QTextEdit *t_1;
};

#endif // WIDGET_H

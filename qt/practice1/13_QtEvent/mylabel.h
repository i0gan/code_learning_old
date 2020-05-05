#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QDebug>
class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = 0);

protected:
    // Mouse Events
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void enterEvent(QEvent *ev);
    void leaveEvent(QEvent *ev);

signals:

public slots:
};

#endif // MYLABEL_H

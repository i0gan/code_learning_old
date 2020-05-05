#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QDebug>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    quint32 chess_w;
    quint32 chess_h;

private:
    Ui::Widget *ui;
    QPoint chessPos; //The position of array chess
    bool isFirst;
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
};

#endif // WIDGET_H

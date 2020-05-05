#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QPen>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    int x;
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_pushButton_clicked();
};

#endif // WIDGET_H

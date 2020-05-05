#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsOpacityEffect>
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    void paintEvent(QPaintEvent *);

private:
    Ui::login *ui;
    QGraphicsOpacityEffect *effect;
};

#endif // LOGIN_H

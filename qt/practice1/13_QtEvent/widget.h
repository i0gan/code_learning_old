#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
    int time_id;
    int time_id_2;
protected:
    //keyboard events:
    void keyPressEvent(QKeyEvent *);
    //Timer events
    void timerEvent(QTimerEvent *);
    void mousePressEvent(QMouseEvent *);
    //Close events
    void closeEvent(QCloseEvent *);
    //Qevents
    bool event(QEvent *);
};

#endif // WIDGET_H

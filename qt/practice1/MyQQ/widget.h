#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QMessageBox>
#include "dialoglist.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void initData();

private:
    Ui::Widget *ui;
    QVector<bool> isShow;
};

#endif // WIDGET_H

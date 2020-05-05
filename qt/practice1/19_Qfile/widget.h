#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QDateTime>
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

private slots:
    void on_pbtOpen_clicked();

    void on_pbtSave_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

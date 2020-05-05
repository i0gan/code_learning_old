#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void showDatabase();

private slots:
    void on_pushButtonDelete_clicked();

    void on_pushButtonDeleteForce_clicked();

    void on_pushButtonCancle_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

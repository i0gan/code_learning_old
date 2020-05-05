#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QVariantList>
#include <QSqlTableModel>
#include <QSqlRecord> //record history
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
    void on_pushButtonAdd_clicked();

    void on_pushButtonComite_clicked();

    void on_pushButtonCancel_clicked();

    void on_pushButtonDelelt_clicked();

    void on_pushButtonSearch_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel *model;
};

#endif // WIDGET_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>
#include "doxml.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connectDB();
    void initData();

private slots:
    void on_actionVehicle_management_triggered();

    void on_actionSales_statistics_triggered();

    void on_comboBoxVender_currentIndexChanged(const QString &arg1);

    void on_comboBoxTraderMark_currentIndexChanged(const QString &arg1);

    void on_spinBoxQuantity_valueChanged(int arg1);

    void on_pushButtonCancel_clicked();

    void on_pushButtonBuy_clicked();

private:
    Ui::MainWindow *ui;
    bool isOpenDb;
    int remainingNumber; //remaining numner;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCompleter>
#include <QStringList>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << ui->lineEdit->text(); //Get text form line edit
    ui->lineEdit->setText("ABCD");
    ui->lineEdit->setTextMargins(10, 0, 0, 0);
    ui->lineEdit->setEchoMode(QLineEdit::Password);

    QStringList list;
    list << "418894119" << "345234535" << "345345345";
    QCompleter *com = new QCompleter(list, this);
    ui->lineEdit_2->setCompleter(com);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_myButton_clicked()
{
    static int i = 0;
    ui->stackedWidget->setCurrentIndex(++i % 2);

}

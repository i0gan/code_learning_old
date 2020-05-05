#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->labelText->setText("TEXT");
    //QLabel of image
    ui->labelImage->setPixmap(QPixmap("://Res/u=2035486075,2219293768&fm=26&gp=0.jpg")); //
    ui->labelImage->setScaledContents(true);

    //QLabel of movie
    QMovie *myMovie = new QMovie("://Res/fit-in__850x850.gif");
    ui->labelMovie->setMovie(myMovie);
   // ui->labelMovie->setScaledContents(true);
    myMovie->start(); //start the movie

    //QLable of url
    ui->labelUrl->setText("<h1><a href=\"http://www.baidu.com\">Baidu</a></h1>");
    ui->labelUrl->setOpenExternalLinks(true);

    //lcd
    ui->lcdNumber->display(520);

    //progressBar
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(1000);
    ui->progressBar->setValue(520);


}

MainWindow::~MainWindow()
{
    delete ui;
}

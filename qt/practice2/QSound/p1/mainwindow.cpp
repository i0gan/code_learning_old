#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "asdfads";
    QSound sound(":/msg.wav");
    sound.play();
    sound.loops();
    QSound::play("./msg.wav");
    QSound::play("./msg.wav");
QSound::play("./msg.wav");
QSound::play("./msg.wav");
QSound::play("./msg.wav");
QSound::play("./msg.wav");
QSound::play("./msg.wav");
QSound::play("./msg.wav");
QSound::play("./msg.wav");
QSound::play("./msg.wav");
QSound::play("./msg.wav");

qDebug() << "end";
}

MainWindow::~MainWindow()
{
    delete ui;
}

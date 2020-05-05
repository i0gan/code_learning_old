#include "widget.h"
#include "ui_widget.h"
#include <QWidget>
#include <QMovie>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //init
    ui->stackedWidget->setCurrentWidget(ui->startMenu);

    startMovie.setFileName(":/fit-in.gif");
    ui->labelStartGIF->setMovie(&startMovie);
   // ui->labelStartGIF->setScaledContents(true);
    startMovie.start();

    overMovie.setFileName(":/over.gif");
    ui->labelLoseGIF->setMovie(&overMovie);
    ui->labelLoseGIF->setScaledContents(true);

    winMovie.setFileName(":/win.gif");
    ui->labelWinGIF->setMovie(&winMovie);
    ui->labelWinGIF->setScaledContents(true);

    //Connect:::

    connect(ui->pbt0, &QPushButton::clicked, this, &Widget::dealNum);
    connect(ui->pbt1, &QPushButton::clicked, this, &Widget::dealNum);
    connect(ui->pbt2, &QPushButton::clicked, this, &Widget::dealNum);
    connect(ui->pbt3, &QPushButton::clicked, this, &Widget::dealNum);
    connect(ui->pbt4, &QPushButton::clicked, this, &Widget::dealNum);
    connect(ui->pbt5, &QPushButton::clicked, this, &Widget::dealNum);
    connect(ui->pbt6, &QPushButton::clicked, this, &Widget::dealNum);
    connect(ui->pbt7, &QPushButton::clicked, this, &Widget::dealNum);
    connect(ui->pbt8, &QPushButton::clicked, this, &Widget::dealNum);
    connect(ui->pbt9, &QPushButton::clicked, this, &Widget::dealNum);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ptbStart_clicked()
{
    QString time = ui->comboBox->currentText();
    time.chop(1);
    gameTime = time.toInt();
    qDebug() << gameTime << "s";
    //change ui
    ui->stackedWidget->setCurrentWidget(ui->GameMenu);

    int num;
    qsrand(QTime(0, 0, 0).secsTo( QTime::currentTime()));
    //create a rand num in 100 ~ 999
    while((num = qrand() % 1000) < 99);
    randStr = QString::number(num);

    qDebug() << "randnum= " << randStr;

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(gameTime);
    ui->progressBar->setValue(gameTime);

    gameTimerId = 0;
    gameTimerId = startTimer(1000);
    resultStr.clear();
    ui->textEdit->clear();

}

void Widget::on_ptbExit_clicked()
{
    this->close(); //exit game
}


void Widget::timerEvent(QTimerEvent *e) {
    if(e->timerId() == gameTimerId) {
        gameTime --;
        ui->progressBar->setValue(gameTime);
        if(gameTime <= 0) {
            killTimer(gameTimerId);
            QMessageBox::information(this, "failing!!", "The time out!");
            overMovie.start();
            ui->stackedWidget->setCurrentWidget(ui->loseOver);
            qDebug() << "Start";
            this->overTimerId = this->startTimer(5000); //auto start timer to end the overed animation

        }
    }else if(e->timerId() == overTimerId) {
        overMovie.stop();
        killTimer(overTimerId);
        ui->stackedWidget->setCurrentWidget(ui->startMenu);

    }else if(e->timerId() == winTimerId) {
        winMovie.stop();
        killTimer(winTimerId);
        ui->stackedWidget->setCurrentWidget(ui->startMenu);

    }

}
void Widget::dealNum() {
    QObject *mySender = sender();

    QPushButton *p = static_cast<QPushButton *>(mySender);

    if(p != NULL) {
        QString numStr = p->text();
        resultStr += numStr;

        if(resultStr.size() == 1 && resultStr == "0") {
            resultStr.clear();
        }

        if(resultStr.size() <= 3) {
            ui->textEdit->setText(resultStr);
            if(resultStr.size() == 3) {
                if(resultStr > randStr) {
                    ui->textEdit->append("The number is bigger a litil bit");
                }else if(resultStr < randStr) {
                    ui->textEdit->append("The number is smaller a litil bit");
                }else {
                    ui->textEdit->append("Yeah Yeah! Your are right!!!");

                    killTimer(gameTimerId);
                    QMessageBox::information(this, "You are wining", "Congratulations!!");
                    winMovie.start();
                    ui->stackedWidget->setCurrentWidget(ui->winOver);
                    winTimerId = startTimer(5000);
                }

                resultStr.clear();
            }
        }
    }

}

void Widget::on_pbtDel_clicked()
{
    if(resultStr.size() ==1) {
        resultStr.clear();
        ui->textEdit->clear();
    }else {
        resultStr.chop(1);
        ui->textEdit->setText(resultStr);
    }
}

void Widget::on_pbtHint_clicked()
{
    QMessageBox::information(this, "Warning", "Are you foolish ?");
}

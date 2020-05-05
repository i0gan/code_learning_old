#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    //remove borders
    //setWindowFlags(Qt::FramelessWindowHint);
    //set window as transparent
    setAttribute(Qt::WA_TranslucentBackground);

    /*
    double opacity = 0.5;
    effect = new QGraphicsOpacityEffect();
    effect->setOpacity(opacity);
    ui->pushButton_Login->setGraphicsEffect(effect); */

    ui->pushButton_Login->setStyleSheet("QPushButton{"


                                         "border-image: url(:/images/res/button_1-1.png);"
                                         "}"
                                         "QPushButton:hover {"
                                         "border-image: url(:/images/res/button_1-2.png);"

                                        "}"
                                         "QPushButton:pressed {"
                                        "border-image: url(:/images/res/button_1-3.png);"
                                        "}");

    ui->pushButton_Signup->setStyleSheet("QPushButton{"
                                         "border-image: url(:/images/res/button_2-1.png);"
                                         "}"
                                         "QPushButton:hover {"
                                         "border-image: url(:/images/res/button_2-2.png);"
                                         "}"
                                         "QPushButton:pressed {"
                                        "border-image: url(:/images/res/button_2-3.png);"
                                        "}");
}

login::~login()
{
    delete ui;
}
void login::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(-120, 0, 640, 640, QPixmap(":/images/res/bg_1.png"));
}

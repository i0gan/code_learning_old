#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel{color:rgb(1,240,100,);"
                             "background-color:blue;"
                             "}");
    ui->pushButton->setStyleSheet("QPushButton{"
                                  "border-width: 4px;"
                                  "border-image: url(:/new/prefix1/res/aa.jpg);"
                                  "}"
                                  "QPushButton:hover {"
                                  "border-image: url(:/new/prefix1/res/fit-in__850x850.gif);"
                                  "}");
}

Widget::~Widget()
{
    delete ui;
}

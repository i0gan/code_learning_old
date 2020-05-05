#include "win2.h"

win2::win2(QWidget *parent) : QWidget(parent)
{
    this->te = new QTextEdit(this);
    te->move(20,20);
    QPushButton *bt_1 = new QPushButton(this);
    this->resize(400, 200);
    this->setWindowTitle("win2");
    bt_1->setText("Send");
    connect(bt_1, &QPushButton::clicked, this, &win2::SendSingal);
}
void win2::SendSingal() {
    emit MySingal("txt", 3);
    emit MySingal();
}

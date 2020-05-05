#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QTimerEvent>
#include <QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->time_id = this->startTimer(1000);
    this->time_id_2 = this->startTimer(100);

    connect(ui->pushButton, &QPushButton::clicked,
            [=](){
            qDebug() << "OK?";

    });


}

Widget::~Widget()
{
    delete ui;
}
void Widget::keyPressEvent(QKeyEvent *ev) {
    switch (ev->key()) {
    case Qt::Key_A:
        qDebug() << "A";
        break;
    case Qt::Key_B:
        qDebug() << "B";
        break;
    case Qt::Key_C:
        qDebug() << "C";
        break;
    case Qt::Key_D:
        qDebug() << "D";
        break;
    default:
        break;
    }

}
void Widget::timerEvent(QTimerEvent *ev) {

    if(ev->timerId() == this->time_id) {
        static int sec = 0;
    ui->label->setText(
                QString("<center><h1> Timer:  %1</h1></center>").arg( sec++)
                );
    if(sec == 10) killTimer(time_id);
    }else if(ev->timerId() == this->time_id_2) {
        static int sec = 0;
        ui->label_2->setText(
                    QString("<center><h1> Timer:  %1</h1></center>").arg( sec++)
                    );
        }
}
void Widget::mousePressEvent(QMouseEvent *) {
    qDebug() << "Widget accpet the signal!";
}
void Widget::closeEvent(QCloseEvent *e) {
    int ret = QMessageBox::question(this, "Warning", "Are you sure to close the window?");
    if(ret == QMessageBox::No) {
        //Event to father control (widget)
        e->ignore();
    }else if(ret == QMessageBox::Yes) {
        e->accept();
    }
}

bool Widget::event(QEvent *e) {
    switch (e->type()) {
    case QEvent::MouseMove:
        qDebug() << "MouseMove";
        break;
    case QEvent::KeyPress: {
        QKeyEvent *env = static_cast<QKeyEvent *>(e);
        if(env->key() == Qt::Key_1) {
            qDebug() << "You preass key 1";
        }
    } break;
    default:
        break;
    }

    QWidget::event(e);

}

#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pbtOpen_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                "open",
                                                "../",
                                                "TXT(*.txt *.cpp *.c)");
    if(!path.isEmpty()) {

        //File Qbject
        QFile file(path);
        //open file
        bool isOpen = file.open(QIODevice::ReadOnly);
        if(isOpen == true) {
#if 0
            QByteArray buf = file.readAll();
            ui->textEdit->setText(QString(buf));
#endif
            QByteArray array;
            while(file.atEnd() == false) {
                array += file.readLine();
            }
            ui->textEdit->setText(QString(array));
            file.close();

        }
        //get file information
        QFileInfo info(path);
        qDebug() << "FileName: " << info.fileName().toUtf8().data();
        qDebug() << "External name: " << info.suffix();
        qDebug() << "Size fo file" << info.size();
        qDebug() << "Date: " << info.created().toString("yyyy-MM-dd hh:mm:ss"); //2015-01-01-

    }
}

void Widget::on_pbtSave_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "save", "../", "TXT(*.txt *.cpp *.c)");
    if(!path.isEmpty()) {
        QFile file;
        file.setFileName(path);

        //open file
        bool isOpen = file.open(QIODevice::WriteOnly);
        if(isOpen == true) {
            //get content from textEdit
            QString str = ui->textEdit->toPlainText();
            //Write file
            //file.write(str.toUtf8());
            //file.write(str.toStdString().data());
            file.write(str.toLocal8Bit()); //loacl code
        }
    }
}

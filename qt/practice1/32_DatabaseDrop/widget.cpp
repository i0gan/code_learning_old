#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //add database
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //connect database
    db.setHostName("127.0.0.1"); //database ip
    db.setUserName("root");
    db.setPassword("l%Lyxf06&/"); //passwd
    db.setDatabaseName("qt");
    if(false == db.open()) {
        QMessageBox::information(this, "error", db.lastError().text());
        return ;
    }
    showDatabase();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonDelete_clicked()
{
    qDebug() << "delete";
    //get text
    QString name = ui->lineEdit->text();

    QString sql = QString("delete from student where name = '%1'").arg(name);
    //open a things
    QSqlDatabase::database().transaction();
    QSqlQuery query;
    query.exec(sql);
    showDatabase();
}

void Widget::on_pushButtonDeleteForce_clicked()
{
    //force delete
    QSqlDatabase::database().commit();
    showDatabase();
}


void Widget::on_pushButtonCancle_clicked()
{
    QSqlDatabase::database().rollback();
    showDatabase();
}
void Widget::showDatabase() {
    ui->textEdit->clear();
    QSqlQuery query;
    query.exec("select * from student");
    while(query.next()) {
        //get content
        QString value;
        value.clear();
        value += QString("  ID: ") + QString::number(query.value("id").toInt());
        value += QString("  Name: ") + query.value("name").toString();
        value += QString("  Age: ") + QString::number(query.value("age").toInt());
        value += QString("  Score: ") + QString::number(query.value("score").toInt());
        ui->textEdit->append(value);
        //qDebug() << query.value("ID: ").toInt();
    }
}

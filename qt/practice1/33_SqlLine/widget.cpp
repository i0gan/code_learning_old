#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //add sqlite
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //set database
    db.setDatabaseName("../database.db");

    //open database
    if(false == db.open()) {
        QMessageBox::warning(this, "error", db.lastError().text());
        return ;
    }
    qDebug() << "open database secusessfully!";
    QSqlQuery query;
    query.exec("create table student(id int primary key, name varchar(255), age int, score int);");
    query.prepare("insert into student(name, age, score) values(?, ?, ?)");
    QVariantList nameList;
    nameList << "Xiao" << "Xu" << "Li";
    QVariantList ageList;
    ageList << 23 << 24 << 25;
    QVariantList scoreList;
    scoreList << 58 << 59 << 60;
    query.addBindValue(nameList);
    query.addBindValue(ageList);
    query.addBindValue(scoreList);
    query.execBatch();

    query.exec("select * from student");
    while(query.next()) {
        qDebug() << query.value(0).toInt()
               << query.value(1).toString()
               << query.value(2).toInt()
               << query.value("score").toInt();
    }
}

Widget::~Widget()
{
    delete ui;
}

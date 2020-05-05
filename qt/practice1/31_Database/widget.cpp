#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //print drive of database qt surport
    qDebug() << QSqlDatabase::drivers();
    //add mysql
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "qt");
    //connect database
    db.setHostName("127.0.0.1"); //database ip
    db.setUserName("root"); //database username
    db.setPassword("l%Lyxf06&/"); //database passwd
    db.setDatabaseName("qt"); //set database in mysql

    //open database
    if(false == db.open()) {
        QMessageBox::information(this, "wrong", db.lastError().text());
        return; //database fail
    }
    QSqlQuery query(db);
    //query.exec("create table student(id int primary key auto_increment, name varchar(255), age int, score int);");
    //query.exec("drop table student");
    //query.exec("insert into student(id, name, age, score) values(1, 'mike', 18, 58);");

/* ****************************************
    //Windows version bulk insert
    //prepare sentence
    //? is equivalent to placeholder
    //Set content for fields and bind list to field
    query.prepare("insert into student(name, age, score) values( ?, ?, ?);");
    QVariantList nameList;
    nameList << "XA" << "XB" << "XC";
    QVariantList ageList;
    ageList << 12 << 13 << 13;
    QVariantList scoreList;
    scoreList << 59 << 69 << 79;
    //Must be bound in order
    query.addBindValue(nameList);
    query.addBindValue(ageList);
    query.addBindValue(scoreList);
    //Execute preprocessing command
    query.execBatch();
*/

    /***************************************
    //oracle version bulk insert
    //placeholder = ':' + 'custom name'
    query.prepare("insert into student(name, age, score) values( :name, :age, :score);");
    QVariantList nameList;
    nameList << "AA" << "BB" << "CC";
    QVariantList ageList;
    ageList << 22 << 23 << 24;
    QVariantList scoreList;
    scoreList << 99 << 89 << 79;
    //bind
    query.bindValue(":name", nameList);
    query.bindValue(":score", scoreList);
    query.bindValue(":age", ageList);
    query.execBatch();
    */




}

Widget::~Widget()
{
    delete ui;
}



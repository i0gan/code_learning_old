#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectDB();
    initData();
    on_actionVehicle_management_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionVehicle_management_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->main);
    ui->label->setText("Car management");
}

void MainWindow::on_actionSales_statistics_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->ratio);
    ui->label->setText("Sales statistics");
}
//connect database
void MainWindow::connectDB() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("l%Lyxf06&/");
    db.setDatabaseName("car");
    //open database
    if(!(isOpenDb = db.open())) {
        QMessageBox::warning(this, "Open database fail", db.lastError().text());
        return;
    }
}
//init
void MainWindow::initData() {
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    queryModel->setQuery("select name from factory"); //execv sql sentence
    //show data in comboBox
    ui->comboBoxVender->setModel(queryModel);

    ui->labeRQuantity->setText(tr("0"));
    ui->labeRQuantity->setEnabled(false);
    Doxml::createXML("../list.xml");
    QStringList fList;
    QStringList bList;
    QStringList pList;
    QStringList aList;
    QStringList tList;
    Doxml::readXML("../list.xml", fList, bList, pList, aList, tList);
    QString textTitel = "Sales today";
    ui->textEdit->setText(textTitel);
    for(int i = 0; i < fList.size(); i++) {
        QString str = QString("%1 --> At today's time,%2:%3: was sold at a price of %4,"
                              "%5 cars were sold and %6 cars were left in total..\n")
                .arg(i).arg(fList.at(i)).arg(bList.at(i)).arg(pList.at(i)).arg(aList.at(i)).arg(tList.at(i));
        ui->textEdit->append(str);
    }
}

void MainWindow::on_comboBoxVender_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "Slect factory") {
        //clean
        ui->comboBoxTraderMark->clear();
        ui->lineEditAmount->setText(tr("0"));
        ui->labeRQuantity->clear();
        ui->lineEditOffer->clear();
        ui->spinBoxQuantity->setValue(0);
        ui->spinBoxQuantity->setEnabled(false);
        ui->pushButtonBuy->setEnabled(false);
    } else {

        ui->spinBoxQuantity->setEnabled(true);
        ui->comboBoxTraderMark->clear();
        QSqlQuery query;
        QString sql = QString("select name from brand where factory = '%1';").arg(arg1);
        query.exec(sql); //execuv  sql
        //get content
        while(query.next()) {
            QString name = query.value(0).toString();
            ui->comboBoxTraderMark->addItem(name);
        }

    }
}

void MainWindow::on_comboBoxTraderMark_currentIndexChanged(const QString &arg1)
{
    ui->spinBoxQuantity->setValue(0);
    ui->labeRQuantity->setEnabled(true);
    QSqlQuery query;
    QString sql = QString("select price, last from brand where factory = '%1' and name = '%2';")
            .arg(ui->comboBoxVender->currentText()).arg(arg1); //select brand
    query.exec(sql); //execuv  sql
    //get content
    while(query.next()) {
        int price = query.value("price").toInt();
        //remain
        remainingNumber = query.value("last").toInt();
        ui->lineEditOffer->setText(QString::number(price));
        ui->labeRQuantity->setText(QString::number(remainingNumber));//remaining quantity

    }

}

void MainWindow::on_spinBoxQuantity_valueChanged(int arg1)
{

    if(remainingNumber < arg1) {
        ui->spinBoxQuantity->setValue(remainingNumber);
        return;
    }



    if(arg1 < 1) {
        ui->pushButtonBuy->setEnabled(false);
        return;
    }else {
        ui->pushButtonBuy->setEnabled(true);
    }

    int temNum = remainingNumber - arg1;
    //update remaining quantity
    ui->labeRQuantity->setText(QString::number(temNum));
    int price = ui->lineEditOffer->text().toInt() * arg1;
    ui->lineEditAmount->setText(QString::number(price));

}

void MainWindow::on_pushButtonCancel_clicked()
{/*
    initData();
    this->on_comboBoxVender_currentIndexChanged("select name from factory"); */
    ui->comboBoxVender->setCurrentIndex(0);
}

void MainWindow::on_pushButtonBuy_clicked()
{
    //Get infomation
    //data of sales volume
    int num = ui->spinBoxQuantity->value();
    //remaining
    int remaining = ui->labeRQuantity->text().toInt();
    QSqlQuery query;
    QString sql = QString("select sell from brand where factory = '%1' and name = '%2';")
            .arg(ui->comboBoxVender->currentText()).arg(ui->comboBoxTraderMark->currentText());
    query.exec(sql); //execuv  sql
    int sell;
    while(query.next()) {
        sell = query.value("sell").toInt();
    }
    //update database, reaming number , sells, sum
    sell += num;
    sql = QString("update brand set sell = %1, last = %2 where factory = '%3' and name = '%4'")
            .arg(sell).arg(remaining)
            .arg(ui->comboBoxVender->currentText())
            .arg(ui->comboBoxTraderMark->currentText());
    query.exec(sql);

    //record data to xml
    QStringList list;
    list << ui->comboBoxVender->currentText()
         << ui->comboBoxTraderMark->currentText()
         << ui->lineEditOffer->text()
         << QString::number(num)
         << QString::number(remaining);
    qDebug() << ui->comboBoxVender->currentText() << "  " << ui->comboBoxTraderMark->currentText();
    Doxml::appendXML("../list.xml", list);
    initData();
    QMessageBox::information(this, "Congratulations!", "Purchase succeeded!");
    ui->comboBoxVender->setCurrentIndex(0);
}

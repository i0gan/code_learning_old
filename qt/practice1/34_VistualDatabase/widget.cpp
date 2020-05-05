#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Visal database");
    //add mysql
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //connect mysql
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("l%Lyxf06&/");
    db.setDatabaseName("qt");
    if(false == db.open()) {
        QMessageBox::warning(this, "error", db.lastError().text());
        return ;
    }
    //set modle  #include <QSqlTableModel>
    model = new QSqlTableModel(this); //auto relevant to database
    model->setTable("student"); //set table
    //set model to view
    ui->tableView->setModel(model);

    //show data in model
    model->select();
    model->setHeaderData(1, Qt::Horizontal, "Name"); //modify the text
    //Set the editing mode of the model and submit the modification manually
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //set tableView as readonly
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonAdd_clicked()
{
    //add empty record
    QSqlRecord record = model->record(); //get empty record
    //Get line number
    int row = model->rowCount();
    model->insertRecord(row, record);

}

void Widget::on_pushButtonComite_clicked()
{
    model->submitAll(); //commit all action
}

void Widget::on_pushButtonCancel_clicked()
{
    model->revertAll(); //undo all action
    model->submitAll(); //submit
}

void Widget::on_pushButtonDelelt_clicked()
{
    //get row when select model
    QItemSelectionModel *sModel = ui->tableView->selectionModel();
    //get index in model
    QModelIndexList list = sModel->selectedRows();
    //delete all selection
    for(int i = 0; i < list.size(); i++) {
        model->removeRow(list.at(i).row()); //delete
    }
}

void Widget::on_pushButtonSearch_clicked()
{
    //select * from student where name = 'mike'
    // name = 'mike'
    QString name = ui->lineEdit->text();
    QString str = QString("name = '%1'").arg(name);
    model->setFilter(str);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./autoDB.db");

    if(db.open())
    {
        qDebug("Open");
    }
    else
    {
        qDebug("No open");
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Auto_details(name varchar(50) not null, car_brand varchar(30) not null, car_model varchar(50) not null, car_year integer not null, in_stock integer not null, price float not null, category varchar(50) not null);");

    model = new QSqlTableModel(this,db);
    model->setTable("Auto_details");
    model->select();

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_infoButton_clicked()
{
    model->insertRow(model->rowCount());
}


void MainWindow::on_deleteButton_clicked()
{
    model->removeRow(row);
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

void MainWindow::on_infoOfProgram_clicked()
{

}


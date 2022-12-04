#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./autoDB.db");

    if(db.open())
    {
        qDebug("Open window cpp");
    }
    else
    {
        qDebug("No open window cpp");
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Auto_details("
                "detail_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                " datail_name varchar(50) not null,"
                " car_brand varchar(30) not null,"
                " car_model varchar(50) not null,"
                " car_year integer not null,"
                " in_stock integer not null,"
                " price float not null, "
                "category varchar(50) not null);");

    model = new QSqlTableModel(this,db);
    model->setTable("Auto_details");
    model->select();

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete addWindow;
}

void MainWindow::on_addButton_clicked()
{
    addWindow = new ClassAdd;
    addWindow->open();
    addWindow->exec();
   // model->setTable("Auto_details");
    model->select();

    ui->tableView->setModel(model);

}

void MainWindow::insertInfo(QString &name, QString &brand, QString &model, int &year, int &in_Stock, float &price, QString &category)
{
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




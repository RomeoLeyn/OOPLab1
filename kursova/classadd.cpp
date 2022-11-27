#include "classadd.h"
#include "ui_classadd.h"


ClassAdd::ClassAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassAdd)
{
    ui->setupUi(this);
    connect(ClassAdd::hide,&QPushButton::clicked,this,&MainWindow::insertInfo);

}

ClassAdd::~ClassAdd()
{
    delete ui;
}

void ClassAdd::on_buttonOk_clicked()
{
    this->name = ui->nameEdit->text();
    this->brand = ui->carBrandEdit->text();
    this->model = ui->carModelEdit->text();
    this->year = ui->carYearEdit->text().toInt();
    this->in_Stock = ui->inStockEdit->text().toInt();
    this->price = ui->priceEdit->text().toDouble();
    this->catgory = ui->categoryEdit->text();

}

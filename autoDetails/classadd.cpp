#include "classadd.h"
#include "ui_classadd.h"



ClassAdd::ClassAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassAdd)
{
    ui->setupUi(this);
    //connect(ClassAdd::hide,&QPushButton::clicked,this,&MainWindow::insertInfo);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./autoDB.db");

    query = new QSqlQuery(db);


    if(db.open())
    {
        qDebug("Open class add");
    }
    else
    {
        qDebug("No open class ad");
    }


    ui->categoryBox->addItem("Двигун",QVariant(1));
    ui->categoryBox->addItem("Підвіска",QVariant(2));
    ui->categoryBox->addItem("Кузов",QVariant(3));
    ui->categoryBox->addItem("Трансмісія",QVariant(4));
    ui->categoryBox->addItem("Електрика",QVariant(5));

    connect(ui->categoryBox,&QComboBox::currentIndexChanged,this,&ClassAdd::setComboBox);



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
    this->price = ui->priceEdit->text().toFloat();
    //this->catgory = ui->categoryEdit->text();
    //this->catgory=ui->categoryBox->itemData(ComboBoxIndex).toString();
    this->catgory=ui->categoryBox->itemText(ComboBoxIndex);
    qDebug() << catgory;

    QString insertQuery = "INSERT INTO Auto_details("
                          " detail_name,"
                          " car_brand,"
                          " car_model,"
                          " car_year,"
                          " in_stock,"
                          " price, "
                          "category)"
                          "VALUES(?,?,?,?,?,?,?);";
        query->prepare(insertQuery);
        query->addBindValue(name);
        query->addBindValue(brand);
        query->addBindValue(model);
        query->addBindValue(year);
        query->addBindValue(in_Stock);
        query->addBindValue(price);
        query->addBindValue(catgory);

    if(!query->exec()){
        qDebug()<<"Error entering data";
    }

    else
    {
        qDebug()<<"Succses";
        this->close();
    }




}

void ClassAdd::setComboBox(int index)
{
    this->ComboBoxIndex = index;

    qDebug() << ui->categoryBox->itemText(index);

}

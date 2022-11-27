#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlTableModel>

#include"classadd.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void insertInfo(QString &name,QString &brand,QString &model,int &year,int &in_Stock,float &price,QString &category);

private slots:
    void on_infoButton_clicked();

    void on_deleteButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_infoOfProgram_clicked();

    void on_addButton_clicked();


private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    ClassAdd *addWindow;



    int row;

};
#endif // MAINWINDOW_H

#ifndef CLASSADD_H
#define CLASSADD_H

#include <QDialog>
#include<qstring.h>
#include<mainwindow.h>

namespace Ui {
class ClassAdd;
}

class ClassAdd : public QDialog
{
    Q_OBJECT

public:
    explicit ClassAdd(QWidget *parent = nullptr);
    ~ClassAdd();

private slots:
    void on_buttonOk_clicked();

private:
    Ui::ClassAdd *ui;

    QString name;
    QString brand;
    QString model;
    int year;
    int in_Stock;
    float price;
    QString catgory;



};

#endif // CLASSADD_H

#include <iostream>


using namespace std;

class Kasa
{

private:
    int countAuto;
    int countNoPayCar;
    int countAllCar;
    double allSum;


public:

    Kasa();
    ~Kasa();

    void payingCar()
    {
        countAuto++;
        countAllCar++;
        allSum += 0.5;
    }

    void noPayCar()
    {
        countNoPayCar++;
        countAllCar++;
    }

    void display()
    {
        cout << "Кiлькiсть авто якi проїхали - " << countAllCar << endl;
        cout << "Авто якi не заплатили - " << countNoPayCar << endl;
        cout << "Кiлькiсть авто якi заплатили - " << countAuto << endl;
        cout << "Сума - " << allSum << endl;

    }
};

Kasa::Kasa()
{
    countAuto = 0;
    countNoPayCar = 0;
    countAllCar = 0;
    allSum = 0.0;
}

Kasa::~Kasa()
{
}


int menu()
{
    int item;
    cout << "1 - Платний проїзд - 0,50$" << endl;
    cout << "2 - Безплатний проїзд" << endl;
    cout << "3 - Iнформацiя про автомобiлi" << endl;
    cout << "4 - Вихiд" << endl;
    cin >> item;
    return item;
}


int main()
{
    int menuChoice;

    Kasa test;

    setlocale(LC_ALL, "ukr");

    while ((menuChoice = menu()) != 4)
    {
        switch (menuChoice)
        {
        case 1:
            test.payingCar();
            //test.display();
            cout << "Оплачено..." << endl;
            break;
        case 2:
            test.noPayCar();
            //test.display();
            break;
        case 3:
            test.display();
            break;
        }
        system("pause");
        system("cls");
    }
}
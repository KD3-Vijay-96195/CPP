#include<iostream>
using namespace std;

class Tollbooth
{
    private:
    int cars;
    double cash;
    int noPayCars;

    public:
    Tollbooth(void)
    {
        this->cars = 0;
        this->cash = 0.0;

        this->noPayCars = 0;
    }

    void payingCars(void)
    {
        this->cars = cars+1;
        this->cash = cash+0.5;
    }

    void nonPayCars(void)
    {
        this->noPayCars = ++noPayCars;
    }

    void printOnConsole(void)
    {
        cout<<"Total Cars : "<<this->cars+this->noPayCars<<endl;
        cout<<"Total cash : "<<this->cash<<endl;

        cout<<"Paying cars : "<<this->cars<<endl;
        cout<<"No paying cars : "<<this->noPayCars<<endl;

    }

};

int menuList(void)
{
    int choice;

    cout<<" \n 0. Exit \n 1. paying car \n 2. No Pay Car \n";
    cin>>choice;
    return choice;
}

int main()
{
    int choice;
    Tollbooth T1;

    while((choice = menuList()) != 0)
    {
        switch(choice)
        {
            case 1:
            {
                T1.payingCars();
                T1.printOnConsole();
                break;

            }
            case 2:
            {

                T1.nonPayCars();
                T1.printOnConsole();
                break;
            }
        }
    }
    return 0;
}
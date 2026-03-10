#include<iostream>
using namespace std;

class date
{
    private:

    int day;
    int month;
    int year;

    public:

    void initDate()
    {
        day = 25;
        month = 8;
        year = 1976;
    }

    void acceptDate()
    {
        cout<<"day : "<<endl;
        cin>>day;

        cout<<"month : "<<endl;
        cin>>month;

        cout<<"year : "<<endl;
        cin>>year;
    }

    void printDate()
    {
        cout<<day<<"-"<<month<<"-"<<year<<endl;
    }
};

int menuList(void)
{
    int choice;
    cout<<"0.exit\n 1.initDate\n 2.acceptDate\n 3.printDate\n"<<endl;
    cin>>choice;
    return choice;
}

int main()
{
    int choice;
    date d1;

    while((choice = menuList()) != 0)
    {
        switch(choice)
        {
            case 1:
                d1.initDate();
                break;
            
            case 2:
                d1.acceptDate();
                break;
            
            case 3:
                d1.printDate();
                break;
        }
    }

    return 0;
}


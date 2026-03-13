#include<iostream>
using namespace std;

class Time
{
    private:
    int h;
    int m;
    int s;

    public:

    Time(void) : h(0), m(0), s(0)
    {   }
    Time(int h, int m, int s) : h(h), m(m), s(s)
    {   }

    void setHour(int h)
    {
        this->h = h; 
    }

    void setMinute(int m)
    {
        this->m = m;   
    }

    void setSeconds(int s)
    {
        this->s = s;
    }

    int getHour(void)
    {
        return this->h;
    }

    int getMinute(void)
    {
        return this->m;
    }

    int getSeconds(void)
    {
        return this->s;
        
    }

    void printTime(void)
    {
        cout<<this->h<<":"<<this->m<<":"<<this->s<<endl;
    }
};

int menuList(void)
    {
        int choice;
        cout<<" 0. exit \n 1. add time \n 2. display all time \n 3. display only hrs of all time objects"<<endl;
        cin>>choice;
    
        return choice;
    }

int main()
{
    int choice;
    int count;
    Time *arr;

    cout<<"Select no of dates to enter : ";
    cin>>count;

    for(int i=0; i<count; i++)
    {
        arr = new Time[i];
    }


    while((choice = menuList()) != 0)
    {
        switch(choice)
        {
            case 1:
                for(int i=0; i<count; i++)
                {
                    int h,m,s;
                    cout<<"hour : ";
                    cin>>h;
                    arr[i].setHour(h);
                    cout<<endl;

                    cout<<"minutes : ";
                    cin>>m;
                    arr[i].setMinute(m);
                    cout<<endl;

                    cout<<"seconds : ";
                    cin>>s;
                    arr[i].setSeconds(s);
                    cout<<endl;
                    
                }
                break;
            
            case 2:
                for(int i=0; i<count; i++)
                {
                    arr[i].printTime();
                    cout<<endl;
                    cout<<endl;
                      
                }
                break;

            case 3:
                for(int i=0; i<count; i++)
                {
                    cout<<arr[i].getHour();
                    cout<<endl;
                }
                break;


        }
    }
    return 0;

}
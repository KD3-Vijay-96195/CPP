#include<iostream>
using namespace std;

class Distance
{
    private:
    double feet;
    double inch;

    public:
    Distance(void) : feet(0.0), inch(0.0)
    {   }

    Distance(double feet, double inch) : feet(feet), inch(inch)
    {   }

    void accept(void)
    {
        cout<<"enter feet : ";
        cin>>this->feet;
        cout<<"enter inch : ";
        cin>>this->inch;
    }

    void display(void)
    {
        cout<<"feet : "<<this->feet<<endl;
        cout<<"inch : "<<this->inch<<endl;
    }

    // c1++ ---- operator++(c1,0)


    Distance& operator++(int)
    {
        this->feet++;
        this->inch++;
        return *this;
    }

    //c = a+b .....a.sum+(b)
    Distance operator+(Distance &other)
    {
        Distance temp;
        temp.feet = this->feet + other.feet;
        temp.inch = this->inch + other.inch;
        return temp;
    } 

    friend Distance operator--(Distance &other, int value);
    friend void operator<<(ostream &cout, Distance &other);
    friend void operator>>(istream &cin, Distance &other);

};

//c1-- = operator(c1,0)
Distance operator--(Distance &other, int value)
{
    Distance temp;
    temp.feet = other.feet--;
    temp.inch = other.inch --;
    return temp;
}

void operator<<(ostream &cout, Distance &other)
{
    cout<<other.feet<<endl;
    cout<<other.inch<<endl;
}

void operator>>(istream &cin, Distance &other)
{
    cout<<"feet : ";
    cin>>other.feet;
    cout<<"inch : ";
    cin>>other.inch;
}
int main()
{
    Distance d1(10,20);
    d1.display();
    Distance d2(30,40);
    d2.display();

    Distance d3 = d1 + d2;
    d3.display();

    Distance d5 = d2++;
    d5.display();

    Distance d4 = d1--;
    d4.display();
    d1.display();

    cin>>d1;
    cout<<d1;

    return 0;
}
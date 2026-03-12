#include<iostream>

using namespace std;

class Cylinder
{
    private:
    double height;
    double radius;
    static double pi;

    public:

    Cylinder()
    {
        this->height = 0;
        this->radius = 0;
    }

    Cylinder(int radius, int height) : radius(radius), height(height)
    {

    }

    void getRadius(void)
    {
        cout<<"Radius : ";
        cin>>this->radius;
    }

    void getHeight(void)
    {
        cout<<"height : ";
        cin>>this->height;
    }

    double volume(void)
    {
        double volume = Cylinder::pi * this->radius * this->radius * this->height;
        return volume;
    }

    void printData(void)
    {
        cout<<"Radius = "<<this->radius<<endl;
        cout<<"Height = "<<this->height<<endl;
        cout<<"pi = "<<Cylinder::pi<<endl;
    }


};

double Cylinder :: pi = 3.14;

int main()
{
    Cylinder c1;
    c1.getHeight();
    c1.getRadius();
    c1.printData();
    cout<<"Volume = "<<c1.volume()<<endl;

    return 0;
}
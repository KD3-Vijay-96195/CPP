#include<iostream>
using namespace std;

class Box
{
    private:
    int length;
    int width;
    int height;

    public:
    Box(void)   //parameterless
    {
        this->length = 1;
        this->width = 1;
        this->height = 1;
    }

    Box(int value)
    {
        this->length = value;
        this->width = value;
        this->height = value;
    }


    Box(int l, int w, int h)
    {
        this->length = l;
        this->width = w;
        this->height = h;
    }


    int Volume(void)
    {
        int volume = this->length*this->width*this->height;

        return volume;
    }
};

int menuList(void)
    {
        int choice;

        cout<<"\n 0.exit\n 1.Volume with Default Values \n 2.Volume with same value\n 3.Volume with different Values \n";

        cin>>choice;

        return choice;
    }

int main()
{
    int choice;

    while((choice = menuList()) != 0)
    {
        switch(choice)
        {
            case 0:
                break;
            case 1:
            {
                Box B1;
                cout<<"Volume = "<<B1.Volume();
                break;
            }

            case 2:
            { 
                int value;
                cout<<"value : ";
                cin>>value;

                Box B2(value);

                cout<<"Volume = "<<B2.Volume();
                break;
            }

            case 3:
            {
                int l, w, h;
                cout<<"Lenght : ";
                cin>>l;

                cout<<"Width : ";
                cin>>w;

                cout<<"height : ";
                cin>>h;

                Box B3(l, w, h);

                cout<<"Volume = "<<B3.Volume();
                break;
            }
        
        }
    }
    return 0;

}
#include<iostream>
using namespace std;

class Product
{
    protected:
    int id;
    string title;
    double price;

    public:
    Product(void) : id(0), title(""), price(0.0)
    {   }

    virtual void acceptRecord(void)
    {
        cout<<"id : ";
        cin>>this->id;
        cout<<"title : ";
        cin>>this->title;
        cout<<"price : ";
        cin>>this->price;
    }

    double getPrice(void)
    {
        return this->price;
    }

    void setPrice(double percent)
    {
        this->price = this->price*percent;
    }

    virtual void printRecord (void)
    {
        cout<<"id : "<<this->id<<endl;
        cout<<"title : "<<this->title<<endl;
        cout<<"price : "<<this->price<<endl;
    }

    virtual ~Product()
    {
        cout<<"destructor call"<<endl;
    }
};

class Book : public Product
{
    private:
    string author;

    public:
    Book(void) : author("")
    {   }

    void acceptRecord(void)
    {
        Product::acceptRecord();
        cout<<"author : ";
        cin>>this->author;
    }

    void printRecord()
    {
        Product::printRecord();
        cout<<"author : "<<this->author<<endl;
    }
};

class Tape : public Product
{
    private:
    string artist;

    public:
    Tape(void) : artist("")
    {   }

    void acceptRecord(void)
    {
        Product::acceptRecord();
        cout<<"artist : ";
        cin>>this->artist;
    }

    void printRecord(void)
    {
        Product::printRecord();
        cout<<"artist : "<<this->artist<<endl;
    }
};


int menuList(void)
{
    int choice;
    cout<<"enter the product : "<<endl;
    cout<<"0. Exit \n 1. book(10'%' discount) \n 2. tape(5'%' discount) \n 3. Total Bill \n";
    cin>>choice;
    return choice;
}

int main()
{
    Product *p[3];
    int choice;
    int i = 0;


    while((choice = menuList()) != 0)
    {
        if (i>3)
        {
            break;
        }
        
        
            if(choice == 1)
            {
                p[i] = new Book();
                p[i]->acceptRecord();
                p[i]->setPrice(0.9);
                p[i]->printRecord(); //10% discount
                i++;   
            }

            else if(choice == 2)
            {
                p[i] = new Tape();
                p[i]->acceptRecord();
                p[i]->setPrice(0.95);
                p[i]->printRecord();  //5% discount
                i++;
            }

            else if(choice == 3)
            {
                double bill = 0.0;
                for(int j = 0; j<i; j++)
                {
                    bill = bill + p[j]->getPrice();
                }
                cout<<"total bill = "<<bill<<endl;
            }
        
        
        

    }
    for(int i=0; i<3; i++)
    {
        delete p[i];
        p[i] = NULL;
    }
    return 0;

}


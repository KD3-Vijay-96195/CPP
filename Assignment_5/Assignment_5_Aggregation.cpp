#include<iostream>
using namespace std;

class Date
{
    private:
    int day;
    string month;
    int year;

    public:
    Date(void) : day(0), month(""), year(0)
    {   }
    Date(int day, string month, int year) : day(day), month(month), year(year)
    {   }
    
    void acceptDate(void)
    {
        cout<<"day : ";
        cin>>this->day;
        cout<<"month : ";
        cin>>this->month;
        cout<<"year : ";
        cin>>this->year;
    }

    void displayDate(void)
    {
        cout<<this->day<<"-"<<this->month<<"-"<<this->year<<endl;
    }
};

class Person
{
    private:
    string name;
    string address;
    Date *birthDate;

    public:
    Person(void) : name(""), address(""), birthDate(new Date())
    {   }
    Person(string name, string address) : name(name), address(address)
    {
        birthDate = NULL;  
    }
    Person(string name, string address, Date birthDate) : Person(name, address)
    {
        this->birthDate = new Date();
    }

    void acceptRecord(void)
    {
        cout<<"name : ";
        cin>>this->name;
        cout<<"address : ";
        cin>>this->address;
        cout<<"Birth Date: ";
        this->birthDate->acceptDate();
        cout<<endl;
    }

    void displayRecord(void)
    {
        cout<<"name : "<<this->name<<endl;
        cout<<"Address : "<<this->address<<endl;
        this->birthDate->displayDate();
        cout<<endl;
    }

    ~Person()
    {
        if(birthDate != NULL)
        {
            delete birthDate;
            birthDate = NULL;
        }
    }
};

class Student
{
    private:
    int id;
    double marks;
    string course;
    Date *joinDate;
    Date *endDate;

    public:
    Student(void) : id(0), marks(0.0), course(""), joinDate(new Date()), endDate(new Date())
    {   }
    Student(int id, double marks, string course) : id(id), marks(marks), course(course)
    {
        this->joinDate = NULL;
        this->endDate = NULL;
    }
    Student(int id, double marks, string course, Date joinDate, Date endDate) : Student(id, marks, course)
    {
        this->joinDate = new Date();
        this->endDate = new Date();
    } 

    void acceptRecord(void)
    {
        cout<<"id : ";
        cin>>this->id;
        cout<<"marks : ";
        cin>>this->marks;
        cout<<"Join Date : ";
        this->joinDate->acceptDate();
        cout<<"End Date : ";
        this->endDate->acceptDate();
        cout<<endl;
    }

    void displayRecord(void)
    {
        cout<<endl;
        cout<<"id : "<<this->id<<endl;
        cout<<"marks : "<<this->marks<<endl;
        cout<<"join date :";
        this->joinDate->displayDate();
        cout<<"end Date : ";
        this->endDate->displayDate();
        cout<<endl;
    }

    ~Student()
    {
        if(joinDate != NULL || endDate != NULL)
        {
            delete joinDate;
            joinDate = NULL;

            delete endDate;
            endDate = NULL;
        }
    }
};

int menuList(void)
{
    int choice;
    cout<<"\n 0. Exit \n 1. Person Data \n 2. Student Data \n";
    cin>>choice;
    return choice;
}

int main()
{
    int choice;
    int count;
    cout<<"Enter the no. of entries to be made: "<<endl;
    cin>>count;

    while((choice = menuList()) != 0)
    {
        switch(choice)
        {
            case  1:
            {
                Person *p = new Person[count];

                for(int i = 0; i<count; i++)
                {
                    p[i].acceptRecord();
                    p[i].displayRecord();
                }
                break;
            }
            case 2:
            {
                Student *s = new Student[count];

                for(int i = 0; i<count; i++)
                {
                    s[i].acceptRecord();
                    s[i].displayRecord();
                }
                break;
            }
        }
    }
    return 0;
}
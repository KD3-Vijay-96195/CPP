#include<iostream>
using namespace std;

class Date
{
    private:
    int day;
    int month;
    int year;

    public:

    Date(void) : day(0), month(0), year(0)
    {   }
    Date(int day, int month, int year) : day(day), month(month), year(year)
    {   }

    void acceptDate(void)
    {
        cout<<"Day : ";
        cin>>this->day;
        cout<<"Month : ";
        cin>>this->month;
        cout<<"year : ";
        cin>>this->year;
    }

    void displayDate()
    {
        cout<<this->day<<"/"<<this->month<<"/"<<this->year<<"/"<<endl;
    }
};

class Person
{
    private:
    string name;
    string address;
    Date birthDate;

    public:

    Person(void) : name(""), address("")
    {    }
    Person(string name, string address, Date birthDate)
    {
        this->name = name;
        this->address = address;
        this->birthDate = birthDate;
    }
    void acceptRecord(void)
    {
        cout<<"name : ";
        cin>>this->name;
        cout<<"address : ";
        cin>>this->address;
        cout<<"birthDate: ";
        this->birthDate.acceptDate();
    }

    void displayRecord()
    {
        cout<<"name : "<<this->name<<endl;
        cout<<"address : "<<this->address<<endl;
        cout<<"birthDate: ";
        this->birthDate.displayDate();
        cout<<endl;
    }
};

class Student
{
    int id;
    double marks;
    string course;
    Date joinDate;
    Date endDate;

    public:
    Student(void) : id(0), marks(0.0), course("")
    {   }
    Student(int id, double marks, string course, Date joinDate, Date endDate) : id(id), marks(marks), course(course), joinDate(joinDate), endDate(endDate)
    {   }

    void acceptRecord(void)
    {
        cout<<"id : ";
        cin>>this->id;
        cout<<"marks : ";
        cin>>this->marks;
        cout<<"course : ";
        cin>>this->course;
        cout<<endl;
        cout<<"JoinDate: ";
        this->joinDate.acceptDate();
        cout<<endl;
        cout<<"EndDate: ";
        this->endDate.acceptDate();
        cout<<endl;
    }

    void displayRecord(void)
    {
        cout<<"id : "<<this->id<<endl;
        cout<<"marks : "<<this->marks<<endl;
        cout<<"course : "<<this->course<<endl;
        cout<<"Joindate : ";
        this->joinDate.displayDate();
        cout<<endl;
        cout<<"endDate : ";
        this->endDate.displayDate();
        cout<<endl;
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
    cout<<"Enter the no of entries: ";
    cin>>count;

    while((choice = menuList()) != 0)
    {
        switch(choice)
        {
            case 1:
            {
                Person *p = new Person[count];

                for(int i=0; i<count; i++)
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

    // Person p1;
    // p1.acceptRecord();
    // p1.displayRecord();

    // Student s1;
    // s1.acceptRecord();
    // s1.displayRecord();

    // return 0;

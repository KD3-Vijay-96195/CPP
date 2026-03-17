#include<iostream>
using namespace std;

class Employee
{
    private:
    int id;
    double salary;

    public:
    Employee(void) : id(0), salary(0.0)
    {   }
    Employee(int id,  double salary) : id(id), salary(salary)
    {   }

    void setId(int id)
    {
        this->id = id;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }


    int getId(void)
    {
        return this->id;
    }

    double getSalary(void)
    {
        return this->salary;
    }

    virtual void accept(void)
    {
        cout<<"id : ";
        cin>>this->id;
        cout<<"salary : ";
        cin>>this->salary;
    }

    virtual void display(void)
    {
        cout<<"id : "<<this->id<<endl;
        cout<<"salary : "<<this->salary<<endl;
    }

};

class Manager : virtual public Employee
{
    private:
    double bonus;

    public:
    Manager(void) : Employee(), bonus(0.0)
    {   }
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus)
    {   }

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus(void)
    {
        return this->bonus;
    }

    void accept(void)
    {
        Employee :: accept();
    }
    void display(void)
    {
        Employee :: display();
    }

    protected:
    void acceptManager(void)
    {
        cout<<"enter bonus : ";
        cin>>this->bonus;
    }

    void displayManager(void)
    {
        cout<<"bonus : "<<this->bonus<<endl;
    }

    
};

class Salesman : virtual public Employee
{
    private:
    double comm;

    public:
    Salesman(void) : Employee(), comm(0.0)
    {   }
    Salesman(int id, double salary, double comm) : Employee(id, salary), comm(comm)
    {   }

    void setComm(double comm)
    {
        this->comm = comm;
    }

    double getComm(void)
    {
        return this->comm;
    }

    void accept(void)
    {
        Employee :: accept();
    }

    void display(void)
    {
        Employee :: display();
    }

    protected:
    void acceptSalesman(void)
    {
        cout<<"enter commission : ";
        cin>>this->comm;
    }

    void displaySalesman(void)
    {
        cout<<"comm : "<<this->comm<<endl;
    }

};

class SalesManager : public Manager, public Salesman
{
    public:
    SalesManager(void) : Manager(), Salesman()
    {   }
    SalesManager(int id, double salary, double bonus, double comm) : Employee(id, salary), Manager(id, salary, bonus), Salesman(id, salary, comm)
    {   }

    void accept()
    {
        Employee::accept();
        Manager :: acceptManager();
        Salesman :: acceptSalesman();
    }

    void display()
    {
        Employee :: display();
        Manager :: displayManager();
        Salesman :: displaySalesman();
    }

};

int main()
{
    SalesManager s1;
    s1.accept();
    s1.display();
    return 0;
}
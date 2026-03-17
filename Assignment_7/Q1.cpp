#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee(void) : id(0), salary(0.0)
    {
    }
    Employee(int id, double salary)
    {
    }

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

    int getSalary(void)
    {
        return this->salary;
    }

    virtual void accept(void)
    {
        cout << "enter id : ";
        cin >> this->id;
        cout << "enter salary : ";
        cin >> this->salary;
    }

    virtual void display(void)
    {
        cout << "id : " << this->id << endl;
        cout << "salary : " << this->salary << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

public:
    Manager(void) : Employee(), bonus(bonus)
    {
    }
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus)
    {
    }

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
        Employee ::accept();
        acceptManager();
    }

    void display(void)
    {
        Employee ::display();
        displayManager();
    }

protected:
    void acceptManager(void)
    {
        cout << "enter bonus : ";
        cin >> this->bonus;
    }

    void displayManager(void)
    {
        cout << "bonus : " << this->bonus << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    double comm;

public:
    Salesman(void) : Employee(), comm(0.0)
    {
    }
    Salesman(int id, double salary, double comm) : Employee(id, salary), comm(comm)
    {
    }

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
        Employee ::accept();
        acceptSalesman();
    }

    void display(void)
    {
        Employee ::display();
        displaySalesman();
    }

protected:
    void acceptSalesman(void)
    {
        cout << "enter commission : ";
        cin >> this->comm;
    }

    void displaySalesman(void)
    {
        cout << "comm : " << this->comm << endl;
    }
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager(void) : Manager(), Salesman()
    {
    }
    SalesManager(int id, double salary, double bonus, double comm) : Employee(id, salary), Manager(id, salary, bonus), Salesman(id, salary, comm)
    {
    }

    void accept()
    {
        Employee::accept();
        Manager ::acceptManager();
        Salesman ::acceptSalesman();
    }

    void display()
    {
        Employee ::display();
        Manager ::displayManager();
        Salesman ::displaySalesman();
    }
};

int menuList(void)
{
    int choice;
    cout << "\n 0. Exit \n 1. Add Manager \n 2. Add Salesman \n 3. Add SalesManager \n 4. Display count of employees by designation \n 5. Display All Managers \n 6. Display All Salesman \n 7. Display All Sales Manager \n ";
    cin >> choice;
    return choice;
}

int main()
{
    int empCount;
    int choice;
    int i = 0;
    cout << "enter no. of employees : ";
    cin >> empCount;
    Employee *emp[empCount-1];

    while ((choice = menuList()) != 0)
    {

        {

            switch (choice)
            {
            case 1:
            {
                if (i > (empCount-1))
                {
                    cout << "Employee List is Full" << endl;
                    break;
                }

                emp[i] = new Manager();
                emp[i]->accept();
                i++;
                break;
            }

            case 2:
            {
                if (i > (empCount-1))
                {
                    cout << "Employee List is Full" << endl;
                    break;
                }

                emp[i] = new Salesman();
                emp[i]->accept();
                i++;
                break;
            }

            case 3:
            {
                if (i > (empCount-1))
                {
                    cout << "Employee List is Full" << endl;
                    break;
                }
                emp[i] = new SalesManager();
                emp[i]->accept();
                i++;
                break;
            }

            case 4:
            {
                int magCount = 0;
                int salesCount = 0;
                int salesMagCount = 0;

                for (int j = 0; j < i; j++)
                {
                    if (typeid(*emp[j]) == typeid(Manager))
                    {
                        magCount++;
                    }
                    else if (typeid(*emp[j]) == typeid(Salesman))
                    {
                        salesCount++;
                    }
                    else if (typeid(*emp[j]) == typeid(SalesManager))
                    {
                        salesMagCount++;
                    }
                }
                cout << "Manager Count : " << magCount << endl;
                cout << "Salesman count: " << salesCount << endl;
                cout << "SalesManager Cout : " << salesMagCount << endl;
                break;
            }

            case 5:
            {
                cout << "~Manager Record~" << endl;
                for (int j = 0; j < i; j++)
                {
                    if (typeid(*emp[j]) == typeid(Manager))
                    {
                        emp[j]->display();
                        cout << endl;
                    }
                }

                break;
            }

            case 6:
            {
                cout << "~Salesman Record~" << endl;
                for (int j = 0; j < i; j++)
                {
                    if (typeid(*emp[j]) == typeid(Salesman))
                    {
                        emp[j]->display();
                        cout << endl;
                    }
                }
                break;
            }

            case 7:
            {
                cout << "~SalesManager Record~" << endl;
                for (int j = 0; j < i; j++)
                {
                    if (typeid(*emp[j]) == typeid(SalesManager))
                    {
                        emp[j]->display();
                        cout << endl;
                    }
                }
                break;
            }
            }
        }
    }
    return 0;
}

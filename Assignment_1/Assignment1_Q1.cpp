#include<stdio.h>

struct date
{
    private:

    int day;
    int month;
    int year;

    public:

    void initDate()
    {
        day = 15;
        month = 7;
        year = 2025;

    }

    void acceptDate()
    {
        printf("day: ");
        scanf("%d", &day);

        printf("month: ");
        scanf("%d", &month);

        printf("year : ");
        scanf("%d", &year);
    }

    void printDate()
    {
        printf("%d-%d-%d\n",day, month, year);
    }

};

int menuList(void)
{
    int choice;
    printf("0. exit \n 1.initDate\n 2.acceptDate\n 3.printDate\n");
    scanf("%d", &choice);
    return choice;
}

int main()
{

    int choice;
    struct date d1;

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
#include <iostream>
#include <conio.h>
using namespace std;

class calender
{
private:
    int daycode = 0;

public:
    void menu();
    void display(int);
    int numOfday(int, int, int);
    int month_finder(int, int);
    int dayfinder(int, int, int);
};
int calender::numOfday(int month, int year, int day)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int temp;

    year -= month < 3;
    temp = (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day % 7);
    return temp;
}

void calender::menu()
{
    int ch;
    do
    {
        system("cls");
        cout << endl
             << "\t\t <-------------------------------------------------------->";
        cout << endl
             << "\t\t <---  Welcome to the Calender  ---> ";
        cout << endl
             << "\t\t <---------- 1  . Calender of the year --------> ";
        cout << endl
             << "\t\t <---------- 2  . Search a Particular Year Calender --------> ";
        cout << endl
             << "\t\t <---------- 99 . Exit --------> ";

        cout << endl
             << "\t\t <-------------------------------------------------------->";
        cin >> ch;

        switch (ch)
        {
        case 1:
            display(2022);
            getch();
            break;

        case 2: // Showing a particular date of the year
            //	Search();
            int joker;
            cout << endl
                 << "\t\t Enter the date ---> ";
            fflush(stdin);
            cin >> joker;
            display(joker);
            getch();

            break;

        case 99:
            cout << endl
                 << "\t\t<------ Thanks for using our program ------> ";
            getch();
            break;

        default:
            cout << endl
                 << "\t\t<------  Invalid options -----> ";
            break;
        }
    } while (ch != 99);
}

void calender::display(int date)
{
    system("cls");
    string weeks[] = {" Sun    ", "        Mon     ", "      Tue ", "           Wed ", "          Thu ", "            Fri ", "            Sat "};
    int weeks_in_days[] = {1, 2, 3, 4, 5, 6, 7};
    int total_days[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
    // string month[] = {"Januray", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int days;      // number of days store
    int last_days; // store last day for next month
    int temp = 0;  // dividing days in weeks system

    last_days = numOfday(1, 1, date);
    last_days+=1;
    for (int month = 0; month < 12; month++)
    {
        days = month_finder(month, date);
        // weeks

        cout << endl;
        for (int week = 0; week <= 6; week++)
        {
            cout << weeks[week] << " ";
        }

        cout << endl
             << "  ";

        temp = 0;
        if (last_days == 7)
            last_days = 0;

        for (int i = 1; i <= last_days; i++)
        {
            temp++;
            cout << "                ";
        }
        for (int day = 0; day < days; day++)
        {

            if (temp == 7)
            {
                cout << endl
                     << "  ";

                temp = 0;
            }
            cout << total_days[day] << "\t\t ";

            temp++;
            last_days = temp;
        }
        cout << endl
             << "  <----------------------------------------------------------------------------------------------------->";
    }
}

int calender::month_finder(int num, int date)
{
    string month[] = {"Januray", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // days = for total number of day in a month
    int days = 0;

    cout << endl
         << endl
         << endl
         << "  <-------------------------------------------   " << date << "  " << month[num] << "   --------------------------------------->";

    num = num + 1;

    if (num == 1)
        days = 31;
    else if (num == 2)
    {
        if (date % 400 == 0 || (date % 4 == 0 && date % 100 != 0))
            days = 29;
        else
            days = 28;
    }
    else if (num == 3)
    {
        days = 31;
    }
    else if (num == 4)
    {
        days = 30;
    }
    else if (num == 5)
    {
        days = 31;
    }
    else if (num == 6)
    {
        days = 30;
    }
    else if (num == 7)
    {
        days = 31;
    }
    else if (num == 8)
    {
        days = 31;
    }
    else if (num == 9)
    {
        days = 30;
    }
    else if (num == 10)
    {
        days = 31;
    }
    else if (num == 11)
    {
        days = 30;
    }
    else if (num == 12)
    {
        days = 31;
    }

    return days;
}

int main()
{
    calender cal;
    cal.menu();
}

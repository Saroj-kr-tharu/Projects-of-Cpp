#include <iostream>
#include <conio.h>
using namespace std;
class convertor
{
private:
    int years, month, day;
    int new_years, new_month, new_day;
    //    string Nepali[11];
    //    string English[11];
public:
    void menu();
    void input();
    void Bs_To_Ad();
    void Ad_TO_BS();
};

void convertor::input()
{

    cout << endl
         << "\t\t Enter the day in years/month/day --------------------->";
    fflush(stdin);
    cin >> years;
    cin.ignore(1, '/');
    cin >> month;
    cin.ignore(1, '/');
    cin >> day;
    if(month>12 || day>31){
        system("cls");
        input();
    }
    new_years = years;
    new_month = month;
    new_day = day;
}

void convertor::Bs_To_Ad()
{
    string Nepali[] = {"Baishak", "Jetha", "Ashar", "Shrawan", "Bhadra", "Ashoj", "Kartik", "Mangir", "Poush", "Magh", "Falgun", "Chaitra"};
    string English[] = {"Januray", "Feburary", "March", "April", "May", "June", "July", "Auguest", "September", "Octber", "November", "December"};

    cout << endl
         << "\t\t <------------------------ BS TO AD --------------------------> ";
    cout << endl
         << "\t\t <---------- Enter Date in BS ---------> ";
    input();
    if (day > 17)
    {
        day -= 17;
    }
    else
    {
        day += 30;
        --month;
        day -= 17;
    }

    if (month > 8)
    {
        month -= 8;
    }
    else
    {
        month += 12;
        --years;
        month -= 8;
    }
    years -= 56;

    cout << endl
         << "\t\t In Bs -----> " << new_years << "/" << new_month << "/" << new_day;
    cout << endl
         << "\t\t In BS -----> " << new_years << "/" << Nepali[new_month-1] << "/" << new_day;
         
    cout << endl
         << endl
         << "\t\t In Ad -----> " << years << "/" << month << "/" << day;
    cout << endl
         << "\t\t In AD -----> " << years << "/" << English[month-1] << "/" << day;
}

void convertor::Ad_TO_BS()
{
    string Nepali[] = {"Baishak", "Jetha", "Ashar", "Shrawan", "Bhadra", "Ashoj", "Kartik", "Mangir", "Poush", "Magh", "Falgun", "Chaitra"};
    string English[] = {"Januray", "Feburary", "March", "April", "May", "June", "July", "Auguest", "September", "Octber", "November", "December"};

    cout << endl
         << "\t\t <--------------------------- AD TO BS --------------------------> ";
    cout << endl
         << "\t\t <--------------------------- Enter Date in AD --------------------------> ";
    input();
    if (day < 17)
    {
        if (month == 1)
            day += 16;

        if (month == 2)
            day += 17;

        if (month == 3)
            day += 16;

        if (month == 4)
            day += 16;

        if (month == 5)
            day += 17;

        if (month == 6)
            day += 17;

        if (month == 7)
            day += 17;

        if (month == 8)
            day += 15;

        if (month == 9)
            day += 15;

        if (month == 10)
            day += 14;

        if (month == 11)
            day += 14;

        if (month == 12)
            day += 14;

        --month;
    }
    else
    {
        day -= 30;

        if (month == 1)
            day += 16;

        if (month == 2)
            day += 18;

        if (month == 3)
            day += 16;

        if (month == 4)
            day += 17;

        if (month == 5)
            day += 16;

        if (month == 6)
            day += 16;

        if (month == 7)
            day += 14;

        if (month == 8)
            day += 14;

        if (month == 9)
            day += 14;

        if (month == 10)
            day += 13;

        if (month == 11)
            day += 14;

        if (month == 12)
            day += 15;

        // ++month;
        // day += 6;
    }

    if (month < 4)
    {
        month += 9;
    }
    else
    {
        month += 12;
        ++years;
        month -= 15;
    }
    years += 56;
    
    
    cout << endl
         << "\t\t In AD -----> " << new_years << "/" << new_month << "/" << new_day;
    cout << endl
         << "\t\t In Bs -----> " << new_years << "/" << English[new_month-1] << "/" << new_day;

    cout << endl
         << endl
         << endl
         << "\t\t In BS -----> " << years << "/" << month << "/" << day;
    cout << endl
         << "\t\t In Bs -----> " << years << "/" << Nepali[month-1] << "/" << day;
}

void convertor::menu()
{
    int choice, num;

    do
    {
        system("cls");
        cout << endl
             << endl
             << "\t ________________________________________________";
        cout << endl
             << "\t\t Please select appropriate key";
        cout << endl
             << "\t\t<--------- 1  ) BS TO AD ---------->";
        cout << endl
             << "\t\t<--------- 2  ) AD TO BS ---------->";
        cout << endl
             << "\t\t<--------- 99 ) Exit ---------->" << endl;
        cout << "\t ________________________________________________";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            Bs_To_Ad();
            getch();
            break;
        case 2:
            system("cls");
            Ad_TO_BS();
            getch();
            break;

        case 99:
            cout << endl
                 << endl
                 << endl
                 << "\t ________________________________________________";
            cout << endl
                 << "\t\t Thanks for using our program ";
            cout << endl
                 << "\t ________________________________________________";
            break;
        default:
            cout << endl
                 << "\t\t Invalid key";
            break;
        }

    } while (choice != 99);
}

int main()
{
    convertor con;
    con.menu();

    return 0;
}

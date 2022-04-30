#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <conio.h>
//#include<math.h>
using namespace std;
class CQotd
{
private:
    vector<string> qoutes;
    int joker;

public:
    void readfile();
    // void readfile();
    void GetRandomQuote(int);
    void menu();
};

void CQotd::readfile()
{
    ifstream file;
    file.open("wisdom.txt");
    if (file.is_open())

    { // cout<<endl<<"\t\t Found";
        string line;
        string running = "";

        while (getline(file, line))
        {
            if (line != "%")
            {
                running = running + line + "\n";
            }
            else
            {
                qoutes.push_back(running);
                running = "";
            }
        }
    }
    else
    {
        cout << endl
             << "\t\t File not founded ";
    }
}

void CQotd::menu()
{
    int ch;
    int no;

    do
    {
        system("cls");
        cout << endl
             << "\t\t<---------------------------------------------------->";
        cout << endl
             << "\t\t <---------- MENU SECTION -------->" << endl
             << endl;
        cout << endl
             << "\t\t <---------- 1 . Enter lucky number  -------->";
        cout << endl
             << "\t\t <---------- 2 . Random  -------->";
        cout << endl
             << "\t\t <---------- 99. Exit -------->";
        cout << endl
             << "\t\t<----------------------------------------------------> ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << endl
                 << "\t\t Enter your lucky number ----> ";
            cin >> no;
            GetRandomQuote(no);
            getch();
            break;

        case 2:
            no = 99;
            GetRandomQuote(no);
            getch();
            break;

        case 99:
            cout << endl
                 << "\t\t <------ Thanks for using our program ------>";
            system("exit");
            break;
        default:
            cout << endl
                 << "\t\t <------ INVALID OPTIONS --------> ";
            break;
        }

    } while (ch != 99);
}

void CQotd::GetRandomQuote(int num)
{  string temp;
    readfile();
    system("cls");
    if (num != 99)
    {
         temp = qoutes[num];
    }
    else
    {
        int r = rand() % qoutes.size();

         temp = qoutes[r];
    }

    //  int r = rand() % qoutes.size();

    //     string temp = qoutes[r];
    cout << endl
         << "\t\t <--- Quotes of the day ------>" << endl
         << temp << endl
         << endl;
}

int main()
{
    CQotd cq;
    cq.menu();
}

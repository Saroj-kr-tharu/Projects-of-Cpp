#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <conio.h>
#include <windows.h>
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
    void art(int, int, string); // type,Speed,file
    void menu();
    void developer();

    string Thankyou = "art/thankyou.txt";
    string banner = "art/banner.txt";
    string Developer = "art/Developer.txt";
};

void CQotd::art(int type, int speed, string name)
{

    string filename(name);

    FILE *input_file = fopen(filename.c_str(), "r");
    unsigned char character;
    while (!feof(input_file))
    {
        character = getc(input_file);

        if (type == 99)
            Sleep(speed);
        else
            Sleep(0);

        cout << character << "";
    }
    cout << endl;
    fclose(input_file);
}

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
                running = running+"\t\t" + line + "\n";
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
void CQotd::developer()
{
    system("cls");
    art(99, 1, Developer);
    getch();
}
void CQotd::menu()
{
    int ch;
    int no;
    // Quotes of the day
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
             << "\t\t <---------- 10. About -------->";
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
        case 10
        :
            developer();
            break;
        case 99:
            system("cls");
            art(1, 0, Thankyou);
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
{
    string temp;
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
    system("cls");
    art(9, 0, banner);
    cout << endl
         << "\t <------------------------ Quotes of the day --------------------------->" << endl
         << temp << endl
         
         <<"\t   <--------------------------------------------------------------------->";
}

void intial()
{
    string Developer = "art/Developer.txt";
    string welcome = "art/Art.txt";

    CQotd ct;
    system("color 71");

    system("cls");
    ct.art(99, 2, welcome);
    Sleep(1000);

    system("cls");
    ct.art(1, 0, Developer);
    Sleep(4000);
}

int main()
{
    intial();
    CQotd cq;
    cq.menu();
}

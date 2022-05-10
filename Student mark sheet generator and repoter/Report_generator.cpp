/* This program is desinged by Saroj kumar Tharu to generated Marksheet and report it */
#include <iostream>
#include <fstream>
#include <cmath>
#include <conio.h>
#include <windows.h>
#include <string.h>

using namespace std;
string str;
class student
{
private:
    int rollno, clas;
    double chem, math, phy, com, nep, percent;

    char name[30], grade[3], phone[13];
    // string str;

public:
    void input();
    void display();

    void calculate();
    int retClass();
    int retRollno();
    void art(int, int, string);
    void animation(int, string);
};

void student ::art(int type, int speed, string name)
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

int student::retClass()
{
    return clas;
}
int student::retRollno()
{
    return rollno;
}

void student::calculate()
{
    string jok;
    //	double temp;
    percent = (chem + math + phy + com + nep) / 5;
    percent = round(percent);

    if (percent >= 90 && percent <= 100)
    {
        jok = "A+";
    }

    else if (percent >= 80 && percent <= 90)
    {
        jok = "A";
    }

    else if (percent >= 70 && percent <= 80)
    {
        jok = "B+";
    }

    else if (percent >= 60 && percent <= 70)
    {
        jok = "B";
    }

    else if (percent >= 50 && percent <= 60)
    {
        jok = "C+";
    }

    else if (percent >= 40 && percent <= 50)
    {
        jok = "C";
    }

    else
    {
        jok = "F";
    }

    strcpy(grade, jok.c_str());

    cout << endl
         << "\t\t Grade =" << grade;
    getch();
}

void student::input()
{

    cout << endl
         << "\t\t <--------------------------------------->";
    fflush(stdin);
    str = "\n\t\t Enter Name -----> ";
    animation(2, str);
    // cin >> name;
    cin.getline(name, 30);
    str = "\t\t Enter Class -----> ";
    animation(2, str);
    cin >> clas;
    str = "\t\t Enter Roll no -----> ";
    animation(2, str);
    cin >> rollno;

    str = "\n\t\t<--------- Entrying Marks --------> ";
    animation(2, str);

    str = "\n\t\t Enter Marks Of Chemistry ---> ";
    animation(2, str);
    cin >> chem;

    str = "\t\t Enter Marks Of Math ---> ";
    animation(2, str);
    cin >> math;
    str = "\t\t Enter Marks Of Physics ---> ";
    animation(2, str);
    cin >> phy;

    str = "\t\t Enter Marks Of Computer ---> ";
    animation(2, str);
    cin >> com;
    str = "\t\t Enter Marks Of Nepali ---> ";
    animation(2, str);
    cin >> nep;
    calculate();
    cout << endl
         << "\t\t <--------------------------------------->";
}

void student::display()
{

    cout << endl
         << "\t\t_______________________________________________";

    str = "\n\t\t Name Of Student ----> ";
    animation(2, str);
    cout << name;

    str = "\n\t\t Class ----> ";
    animation(2, str);
    cout << clas;

    str = "\n\t\t Roll No ----> ";
    animation(2, str);
    cout << rollno;

    cout << endl
         << "\t\t_________________________________________________";
    cout << endl
         << endl
         << "\t\t Marks of Math -------> " << math;
    cout << endl
         << "\t\t Marks of Physic -------> " << phy;
    cout << endl
         << "\t\t Marks of Math -------> " << math;
    cout << endl
         << "\t\t Marks of Nepali ------->  " << nep;
    cout << endl
         << "\t\t Marks of Chemisty ------> " << chem;
    str = "\n\t\t Precentage ----> ";
    animation(2, str);
    cout << percent;

    cout << endl
         << "\t\t Grade :-" << grade;
    cout << endl
         << "\t\t________________________________________";
}

void red();
void wrte();
void modify();
void search();
void del();
void destory();
void menu();
void intial();
void about();

int main()
{
    intial();
    menu();
}

void student::animation(int speed, string temp)
{
    int i = 0;
    while (temp[i] != NULL)
    {
        cout << temp[i];
        i++;
        Sleep(speed);
    }
}
void about()
{
    string Developer = "art/Developer.txt";
    student stu;
    system("cls");
    stu.art(99, 1, Developer);
    getch();
}
void menu()
{

    int choice = 0;
    string Thankyou = "art/thankyou.txt";
    string banner = "art/banner.txt";
    string Developer = "art/Developer.txt";
    student stu;

    do
    {

        system("cls");
        stu.art(2, 1, banner);
        str = "\n\t\t <------  WELCOME TO MAIN MENU  -------> ";
        stu.animation(2, str);
        cout << endl
             << "\t\t <---------------------------------------> ";
        cout << endl
             << "\t\t <------ 1 .  Input            ------->";
        cout << endl
             << "\t\t <------ 2 .  Display          ------->";
        cout << endl
             << "\t\t <------ 3 .  Modify           ------->";
        cout << endl
             << "\t\t <------ 4 .  Delete           ------->";
        cout << endl
             << "\t\t <------ 5 .  Destory database ------->";
        cout << endl
             << "\t\t <------ 6 .  Search           ------->";
        cout << endl
             << "\t\t <------ 10.  About            ------->";
        cout << endl
             << "\t\t <------ 99.  Exit             ------->";
        cout << endl
             << "\t\t <---------------------------------------> ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            stu.art(2, 1, banner);
            wrte();
            getch(); // inputing and writing
            break;
        case 2:
            system("cls");
            stu.art(2, 1, banner);
            red();
            getch(); // reading and displaying
            break;
        case 3:
            system("cls");
            stu.art(2, 1, banner);
            modify();
            break;
        case 4:
            system("cls");
            stu.art(2, 1, banner);
            del();
            break;
        case 5:
            system("cls");
            stu.art(2, 1, banner);
            destory();
            //	getch();
            break;
        case 6:
            system("cls");
            stu.art(2, 1, banner);
            search();
            //	getch();
            break;
        case 10:
            system("cls");
            stu.art(2, 1, banner);
            about();
            break;
        case 99:
            system("cls");
            stu.art(99, 1, Thankyou);
            system("exit");
            break;
        default:
            break;
        }

    } while (choice != 99);
}
void del()
{
    bool found = false;
    char choice;
    fstream file, outfile;
    student stu;
    int clas, roll;

    file.open("database.txt", ios::in);
    outfile.open("temp.txt", ios::out);

    str = "\n\t\t <------  WELCOME TO DELETE SECTION  ------->";
    stu.animation(2, str);
    cout << endl
         << "\t\t <--------------------------------------------------->";

    str = "\n\t\t Enter Class -----> ";
    stu.animation(2, str);
    cin >> clas;

    str = "\t\t Enter Roll no -----> ";
    stu.animation(2, str);
    cin >> roll;

    if (file.is_open())
    {
        if (!file.eof())
        {
            while (file.read(reinterpret_cast<char *>(&stu), sizeof(student)))
            {
                if (stu.retClass() != clas && stu.retRollno() != roll)
                {
                    outfile.write(reinterpret_cast<char *>(&stu), sizeof(student));
                }
                if (stu.retClass() == clas && stu.retRollno() == roll)
                    found = true;
            }
        }
        else
        {
            str = "\n\t\t  <-------- Unable to opened file  ----------> ";
            stu.animation(2, str);
            getch();
        }
    }

    file.close();
    outfile.close();

    if (found == false)
    {

        str = "\n\t\t  <-------- Not Founded  ----------> ";
        stu.animation(2, str);
    }
    else
    {
        str = "\n\t\t  <-------- Sucessfully Delete  ----------> ";
        stu.animation(2, str);

        remove("database.txt");
        rename("temp.txt", "database.txt");
    }

    cout << endl
         << "\t\t <-------------------------------------------------->";
    getch();
}
void intial()
{
    string Developer = "art/Developer.txt";
    string welcome = "art/Art.txt";

    student ct;
    // system("color 71");
    system("color 87");

    system("cls");
    ct.art(99, 2, welcome);
    Sleep(1000);

    system("cls");
    ct.art(1, 0, Developer);
    Sleep(4000);
}

void modify()
{
    bool found = false;
    char ch;
    fstream file;
    student stu;
    int clas, roll;

    file.open("database.txt", ios::in | ios::out);

    str = "\n\t\t <------  WELCOME TO MODIFY SECTION  ------->";
    stu.animation(2, str);
    cout << endl
         << "\t\t <--------------------------------------------------->";

    str = "\n\t\t Enter Class -----> ";
    stu.animation(2, str);
    cin >> clas;

    str = "\t\t Enter Roll no -----> ";
    stu.animation(2, str);
    cin >> roll;

    if (file.is_open())
    {
        if (!file.eof())
        {
            while (file.read(reinterpret_cast<char *>(&stu), sizeof(student)))
            {
                if (((stu.retClass() == clas) && (stu.retRollno() == roll)))
                {
                    system("cls");

                    str = "\n\t\t  <-------- Sucessfully Founded  ----------> ";
                    stu.animation(2, str);

                    found = true;
                    stu.display();

                    str = "\n\t\t  <-------- Press Y For To Edit  ----------> ";
                    stu.animation(2, str);
                    fflush(stdin);
                    ch = getch();
                    if (ch == 'y' || ch == 'Y')
                    {
                        stu.input();

                        int pos = (-1) * static_cast<int>(sizeof(student)); // file pointer
                        file.seekp(pos, ios::cur);
                        file.write(reinterpret_cast<char *>(&stu), sizeof(student));

                        str = "\n\t\t  <-------- Sucessfully Modified  ----------> ";
                        stu.animation(2, str);
                    }
                    else
                    {
                        str = "\n\t\t  <-------- Not Modified  ----------> ";
                        stu.animation(2, str);
                    }
                }
            }
        }
    }
    else
    {

        str = "\n\t\t  <-------- Unable to opened file  ----------> ";
        stu.animation(2, str);
    }

    if (found == false)
    {
        str = "\n\t\t  <-------- Not Founded  ----------> ";
        stu.animation(2, str);
    }

    file.close();
    cout << endl
         << "\t\t <--------------------------------------------------->";

    getch();
}

void destory()
{
    student stu;
    remove("database.txt");
    cout << endl
         << "\t\t<----  Welcome to Database Destory Section  ---->";
    str = "\n\t\t  <-------- Sucessfully Destory  ----------> ";
    stu.animation(2, str);
    getch();
}

void red()
{
    fstream file;
    student stu;
    file.open("database.txt", ios::in);

    if (file.is_open())
    {
        if (!file.eof())
        {
            str = "\n\t\t <------  WELCOME TO DISPLAY SECTION  -------> ";
            stu.animation(2, str);
            while (file.read(reinterpret_cast<char *>(&stu), sizeof(student)))
            {

                stu.display();
            }
        }
    }
    else
    {
        str = "\n\t\t  <-------- Unable to opened file  ----------> ";
        stu.animation(2, str);
    }
    getch();
    file.close();
}

void wrte()
{
    fstream file;
    student stu;

    str = "\n\t\t <------  WELCOME TO INPUT SECTION  ------->";
    stu.animation(2, str);
    file.open("database.txt", ios::app);
    // stu.input();

    if (file.is_open())
    {
        stu.input();
        str = "\n\t\t  <-------- Rechecking The Data  ----------> ";
        stu.animation(2, str);
        stu.display();
        file.write(reinterpret_cast<char *>(&stu), sizeof(student));
        str = "\n\t\t  <-------- Sucessfully Written to File  ----------> ";
        stu.animation(2, str);
    }
    else
    {
        str = "\n\t\t <----- File is not Opened ----->";
        stu.animation(2, str);
    }
    file.close();
}

void search()
{
    bool found = false;
    char ch;
    fstream file;
    student stu;
    int clas, roll;

    file.open("database.txt", ios::in);

    str = "\n\t\t <------  WELCOME TO SEARCH SECTION  ------->";
    stu.animation(2, str);
    cout << endl
         << "\t\t <--------------------------------------------------->";

    str = "\n\t\t Enter Class -----> ";
    stu.animation(2, str);
    cin >> clas;

    str = "\t\t Enter Roll no -----> ";
    stu.animation(2, str);
    cin >> roll;

    if (file.is_open())
    {
        if (!file.eof())
        {
            system("cls");
            while (file.read(reinterpret_cast<char *>(&stu), sizeof(student)))
            {
                if ((stu.retClass() == clas) && (stu.retRollno() == roll))
                {
                    str = "\n\t\t  <-------- Sucessfully Founded  ----------> ";
                    stu.animation(2, str);
                    found = true;
                    stu.display();
                }
            }
        }
    }
    else
    {

        str = "\n\t\t  <-------- Unable to opened file  ----------> ";
        stu.animation(2, str);
    }

    if (found == false)
    {
        str = "\n\t\t  <-------- Not Founded  ----------> ";
        stu.animation(2, str);
    }

    cout << endl
         << "\t\t <--------------------------------------------------->";
    file.close();
    getch();
}

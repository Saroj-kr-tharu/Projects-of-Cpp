/* This program is designed by Saroj kumar tharu to manage student management system */
#include <iostream>
#include <fstream>
#include <conio.h>
#include <algorithm>
#include <windows.h>
using namespace std;
string str;
class student
{
private:
    char name[30], Auther[50], publication[100];
    int id, stock;

public:
    void input();
    void display();
    int retid();
    void art(int, int, string); // type , speed, Filename
    void about();
    void animation(int, string); // string for to store data  // speed,string
};
void student::about()
{
    string Developer = "art/Developer.txt";
    system("cls");
    art(99, 1, Developer);
}

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

int student::retid()
{
    return id;
}

void student::input()
{
    // system("cls");
    str = "\n\t\t\t\t   Enter  Book Id ----->";
    animation(2, str);
    cin >> id;

    str = "\t\t\t\t   Enter Book Name ----->";
    animation(2, str);
    fflush(stdin);
    cin.getline(name, 30);
    // cin.ignore();
    str = "\t\t\t\t   Enter  Book Auther ----->";
    animation(2, str);
    fflush(stdin);
    cin.getline(Auther, 50);

    str = "\t\t\t\t   Enter Publication Of The Book ----->";
    animation(2, str);
    fflush(stdin);
    cin.getline(publication, 100);
    str = "\t\t\t\t   Enter  Stock of Book ----->";
    animation(2, str);
    cin >> stock;
    cout << endl
         << "\t\t\t <---------------------------------------------------->";
}

void student::display()
{
    // system("cls");
    str = "\n\t\t\t\t   Book Id ----->";
    animation(2, str);
    cout << id;

    str = "\n\t\t\t\t   Name of the Book ---->";
    animation(2, str);
    cout << name;

    str = "\n\t\t\t\t   Auther of the Book ----->";
    animation(2, str);
    cout << Auther;

    str = "\n\t\t\t\t   Publication Of The Book  ----->";
    animation(2, str);
    cout << publication;

    str = "\n\t\t\t\t   Book Stock ----->";
    animation(2, str);
    cout << stock;
    cout << endl
         << "\t\t\t  <------------------------------------------------------------>";
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
void intial();
void input();
void display();
void search();
void modify();
void delet();
void destory();
void menu();

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

void menu()
{
    int num;
    string name, add;
    int type;
    int roll, clas;
    long long int fone;
    student stu;
    string Thankyou = "art/thankyou.txt";
    string banner = "art/banner.txt";
    string Developer = "art/Developer.txt";

    int choice;
    do
    {
        system("cls");
        stu.art(2, 1, banner);
        str = "\n\t\t\t  <-----------  WELCOME TO MAIN MENU  ------------>";
        stu.animation(2, str);
        cout << endl
             << "\t\t\t <---------------------------------------------------->";

        str = "\n\t\t\t <------ Please select appropriate key ------>";
        stu.animation(2, str);

        cout << endl
             << "\t\t\t\t 1  . Input";
        cout << endl
             << "\t\t\t\t 2  . Display";
        cout << endl
             << "\t\t\t\t 3  . Destory data base";
        cout << endl
             << "\t\t\t\t 4  . Modify";
        cout << endl
             << "\t\t\t\t 5  . Search";
        cout << endl
             << "\t\t\t\t 6  . Delete";
        cout << endl
             << "\t\t\t\t 10 . About";
        cout << endl
             << "\t\t\t\t 99 . Exit" << endl;
        cout << "\t\t\t <---------------------------------------------------->";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            stu.art(1, 0, banner);

            str = "\n\t\t\t  <-----------  WELCOME TO INPUT SECTION ------------>";
            stu.animation(2, str);
            input();
            break;
        case 2:
            system("cls");
            stu.art(1, 0, banner);

            str = "\n\t\t\t  <-----------  WELCOME TO DISPLAY SECTION ------------>";
            stu.animation(2, str);
            display();
            break;
        case 3:
            system("cls");
            stu.art(1, 0, banner);
            destory();
            break;
        case 4: // modify
            system("cls");
            stu.art(1, 0, banner);
            modify();
            break;

        case 5: // search
            system("cls");
            stu.art(1, 0, banner);
            search();
            break;

        case 6: // delete
            system("cls");
            stu.art(1, 0, banner);
            delet();
            break;
        case 10:
            stu.about();
            break;
        case 99:
            system("cls");
            stu.art(99, 1, Thankyou);
            break;
        default:
            str = "\n\t\t\t <------ Invalid Options ----->";
            stu.animation(2, str);
            break;
        }

    } while (choice != 99);
}

int main()
{
    intial();
    menu();
}

void delet()
{
    int flag = 99;
    student hack, stu;
    fstream file, outfile;
    char ch;
    int id;
    str = "\n\t\t\t  <-----------  WELCOME TO DELETE SECTION  ------------>";
    stu.animation(2, str);

    file.open("database.txt", ios::in | ios::binary);
    outfile.open("temp.txt", ios::out | ios::binary);
    str = "\n\t\t\t\t Enter Id Of The Bok  ----->";
    stu.animation(2, str);
    cin >> id;

    if (file.is_open())
    {
        while (file.read(reinterpret_cast<char *>(&hack), sizeof(student)))
        {
            if (hack.retid() != id)
            {
                outfile.write(reinterpret_cast<char *>(&hack), sizeof(student));
            }
            if (hack.retid() == id)
                flag = 100;
        }
        file.close();
        outfile.close();
    }
    else
    {
        str = "\n\t\t\t\t <------ File Is Not Found ----->";
        stu.animation(2, str);
    }

    outfile.close();


    if (flag == 99)
    {
        str = "\n\t\t\t\t <------ Not Found ----->";
        stu.animation(2, str);
    }
    else if (flag == 100)
    {
        str = "\n\t\t\t\t <------ Sucessfull Delete ------>";
        stu.animation(2, str);
        remove("database.txt");
        rename("temp.txt", "database.txt");
    }

    else
    {
        str = "\n\t\t\t\t <------ Founded But Not Delete ----->";
        stu.animation(2, str);
    }
    cout << endl
         << "\t\t\t <---------------------------------------------------->";
    getch();
}

void search()
{
    int num, n, ch;
    fstream file;
    student stu;
    str = "\n\t\t\t  <-----------  WELCOME TO SEARCH SECTION  ------------>";
    stu.animation(2, str);
    str = "\n\t\t\t\t Enter Id Of The BOOK ----->";
    stu.animation(2, str);
    cin >> ch;
    file.open("database.txt", ios::in | ios::binary);
    if (file.is_open())
    {
        if (!file.eof())
        {
            while (file.read(reinterpret_cast<char *>(&stu), sizeof(student)))
            {
                if (stu.retid() == ch)
                {
                    str = "\n\t\t\t\t <------ Sucessfully Founded ----->";
                    stu.animation(2, str);
                    stu.display();
                    n++;
                }
            }
            // getch();
        }
    }
    else
    {
        str = "\n\t\t\t\t <------ File Is Not Found ----->";
        stu.animation(2, str);
    }

    if (n == 0)
    {
        str = "\n\t\t\t\t <------ Data Is Not Found ----->";
        stu.animation(2, str);
        // getch();
    }
    file.close();
    cout << endl
         << "\t\t\t  <------------------------------------------------------------>";
    getch();
}

void modify()
{
    int num, n, cha;
    fstream file;
    student stu;
    char ch;
    str = "\n\t\t\t  <-----------  WELCOME TO MODIFY SECTION ----------->";
    stu.animation(2, str);
    file.open("database.txt", ios::in | ios::out | ios::binary);
    cout << endl
         << "\t\t\t\t Enter the id of the book -----> ";
    cin >> cha;
    if (file.is_open())
    {
        if (!file.eof())
        {
            while (file.read(reinterpret_cast<char *>(&stu), sizeof(student)))
            {
                if (stu.retid() == cha)
                {
                    str = "\n\t\t\t\t <------ Sucessfully Founed  ----->";
                    stu.animation(2, str);
                    cout << endl
                         << "\t\t\t   <----- Displaying current information ----->";
                    stu.display();
                    str = "\n\t\t\t\t <-- Press y For To Modify -->";
                    stu.animation(2, str);
                    fflush(stdin);
                    ch = getch();
                    if (ch == 'y' || ch == 'y')
                    {
                        stu.input();
                        int pos = (-1) * static_cast<int>(sizeof(student)); // file pointer
                        file.seekp(pos, ios::cur);
                        file.write(reinterpret_cast<char *>(&stu), sizeof(student));
                        str = "\n\t\t\t\t <------ Sucessfully Modified ----->";
                        stu.animation(2, str);
                    }
                    n++;
                }
            }
        }
    }
    else
    {
        str = "\n\t\t\t\t <------ File Is Not Found ----->";
        stu.animation(2, str);
    }

    if (n == 0)
    {
        str = "\n\t\t\t\t <------ Data Is Not Found ----->";
        stu.animation(2, str);
    }

    file.close();
    cout << endl
         << "\t\t\t  <------------------------------------------------------------>";
    getch();
}

void input()
{
    fstream file;
    student stu;
    file.open("database.txt", ios::app);

    if (file.is_open())
    {
        stu.input();
        file.write(reinterpret_cast<char *>(&stu), sizeof(student));
        str = "\n\t\t\t\t <------ File Is Written Sucessfully  ----->";
        stu.animation(2, str);
    }
    else
    {
        str = "\n\t\t\t\t <------ File Is Not Found ----->";
        stu.animation(2, str);
    }
    file.close();
    cout << endl
         << "\t\t\t  <------------------------------------------------------------>";
    getch();
}

void display()
{
    fstream file;
    student stu;
    file.open("database.txt", ios::in);
    if (file.is_open())
    {
        if (!file.eof())
        {
            while (file.read(reinterpret_cast<char *>(&stu), sizeof(student)))
            {
                stu.display();
            }
        }
    }
    else
    {
        str = "\n\t\t\t\t <------ File Is Not Found ----->";
        stu.animation(2, str);
    }
    file.close();
    cout << endl
         << "\t\t\t  <------------------------------------------------------------>";
    getch();
}

void destory()
{
    student stu;
    remove("database.txt");

    str = "\n\t\t   <---------  Destorying Database Sucessfully --------->";
    stu.animation(2, str);
    cout << endl
         << "\t\t\t <---------------------------------------------------->";
    getch();
}

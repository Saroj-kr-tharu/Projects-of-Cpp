/* This program is designed by Saroj kumar tharu to manage student management system */
#include <iostream>
#include <fstream>
#include <conio.h>
#include <algorithm>
#include <windows.h>
using namespace std;
class student
{
private:
    char name[30], address[50];
    int rollno, clas;
    long long int phone;

public:
    void input();
    void display();
    string retName();
    string retAdd();
    int retClas();
    int retRoll();
    void art(int, int, string); // type , speed, Filename
    void about();
};
void student::about(){
        string Developer = "art/Developer.txt";
    system("cls");
    art(99,1,Developer);
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
string student::retName()
{
    string ch;
    ch = name;
    transform(ch.begin(), ch.end(), ch.begin(), ::tolower);
    return ch;
}
string student::retAdd()
{
    string ch;
    ch = address;
    transform(ch.begin(), ch.end(), ch.begin(), ::tolower);
    return ch;
}

int student::retClas()
{
    return clas;
}
int student::retRoll()
{
    return rollno;
}

void student::input()
{
    // system("cls");
    cout << endl
         << "\t\t Enter the name of the student :-\t";
    fflush(stdin);
    cin.getline(name, 30);
    // cin.ignore();
    cout << "\t\t Enter the Address of the student :-\t";
    fflush(stdin);
    cin.getline(address, 50);
    cout << "\t\t Enter the rollno of the student :-\t";
    cin >> rollno;
    cout << "\t\t Enter the class of the student :-\t";
    cin >> clas;
    cout << "\t\t Enter the phone of the student  :-\t";
    cin >> phone;
    cout << endl
         << "\t __________________________________________________________________________________";
}

void student::display()
{
    // system("cls");
    cout << endl
         << endl
         << "\t\t Name :-\t" << name;
    cout << endl
         << "\t\t Address :-\t" << address;
    cout << endl
         << "\t\t Roll no :-\t" << rollno;
    cout << endl
         << "\t\t Phone   :-\t" << phone;
    cout << endl
         << "\t\t Class   :-\t" << clas;
    cout << endl
         << "\t __________________________________________________________________________________";
}

void intial();
void input();
void display();
void search(string, string, int, long long int, int, int);
void modify(string, string, int, long long int, int, int);
void delet(string);
void destory();
void menu();

void intial()
{
    string Developer = "art/Developer.txt";
    string welcome = "art/Art.txt";

    student ct;
    //system("color 71");
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
        cout << endl
             << endl
             << "\t __________________________________________________________________________________";
        cout << endl
             << "\t\t Please select appropriate key";
        cout << endl
             << "\t\t 1  ) Input";
        cout << endl
             << "\t\t 2  ) Display";
        cout << endl
             << "\t\t 3  ) Destory data base";
        cout << endl
             << "\t\t 4  ) Modify";
        cout << endl
             << "\t\t 5  ) Search";
        cout << endl
             << "\t\t 6  ) Delete";
        cout << endl
             << "\t\t 10  ) About";
        cout << endl
             << "\t\t 99 ) Exit" << endl;
        cout << "\t __________________________________________________________________________________";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            stu.art(1, 0, banner);
            cout << endl
                 << "\t __________________________________________________________________________________";
            input();
            break;
        case 2:
            system("cls");
            stu.art(1, 0, banner);
            cout << "\t __________________________________________________________________________________";
            display();
            break;
        case 3:
            system("cls");
            stu.art(1, 0, banner);
            cout << endl
                 << "\t __________________________________________________________________________________";
            destory();
            break;
        case 4: // modify
            system("cls");
            stu.art(1, 0, banner);
            cout << "\t __________________________________________________________________________________";
            cout << endl
                 << endl
                 << "\t\t Please select appropriate key to be modified";
            cout << endl
                 << "\t\t 1) BY Name";
            cout << endl
                 << "\t\t 2) BY Address";
            cout << endl
                 << "\t\t 3) By Class";
            cout << endl
                 << "\t\t 4) BY Rollno" << endl;
            cin >> num;
            fflush(stdin);
            switch (num)
            {
            case 1: // name add roll fone
                system("cls");
                stu.art(1, 0, banner);
                cout << endl
                     << "\t\t Enter name :) ";
                fflush(stdin);
                // cin.getline(name,30);
                getline(cin, name);
                transform(name.begin(), name.end(), name.begin(), ::tolower);
                type = 100;
                modify(name, add, type, fone, clas, roll);
                break;

            case 2: // add=110 phone=120 clas=130 roll=140 // address
                system("cls");
                stu.art(1, 0, banner);
                cout << endl
                     << "\t\t Enter Address :) ";
                fflush(stdin);
                getline(cin, add);
                transform(add.begin(), add.end(), add.begin(), ::tolower);
                type = 130;
                modify(name, add, type, fone, clas, roll);
                break;

            case 3: // class
                system("cls");
                cout << endl
                     << "\t\t Enter Class:) ";
                fflush(stdin);
                cin >> clas;
                type = 130;
                modify(name, add, type, fone, clas, roll);
                break;
            case 4:
                    system("cls");
                    stu.art(1, 0, banner);
                cout << endl
                     << "\t\t Enter Rollno :) ";
                fflush(stdin);
                cin >> roll;
                type = 140;
                modify(name, add, type, fone, clas, roll);
                break;
            default:
                cout << endl
                     << "\t\t Invalid key";
                break;
            }
            break;

        case 5: // search
            system("cls");
            stu.art(1, 0, banner);
            cout << "\t __________________________________________________________________________________";
            cout << endl
                 << endl
                 << "\t\t Please select appropriate key to be search";
            cout << endl
                 << "\t\t 1) BY Name";
            cout << endl
                 << "\t\t 2) BY Address";
            cout << endl
                 << "\t\t 3) By Class";
            cout << endl
                 << "\t\t 4) BY Rollno" << endl;
            cin >> num;
            fflush(stdin);
            switch (num)
            {
            case 1: // name add roll fone
                system("cls");
                stu.art(1, 0, banner);
                cout << endl
                     << "\t\t Enter name :) ";
                fflush(stdin);
                // cin.getline(name,30);
                getline(cin, name);
                transform(name.begin(), name.end(), name.begin(), ::tolower);
                type = 100;
                search(name, add, type, fone, clas, roll);
                break;

            case 2: // add=110 phone=120 clas=130 roll=140 // address
                     system("cls");
                     stu.art(1, 0, banner);
                cout << endl
                     << "\t\t Enter Address :) ";
                fflush(stdin);
                getline(cin, add);
                transform(add.begin(), add.end(), add.begin(), ::tolower);
                type = 130;
                search(name, add, type, fone, clas, roll);
                break;

            case 3: // class
                    system("cls");
                    stu.art(1, 0, banner);
                cout << endl
                     << "\t\t Enter Class:) ";
                fflush(stdin);
                cin >> clas;
                type = 130;
                search(name, add, type, fone, clas, roll);
                break;
            case 4:
                system("cls");
                stu.art(1, 0, banner);
                cout << endl
                     << "\t\t Enter Rollno :) ";
                fflush(stdin);
                cin >> roll;
                type = 140;
                search(name, add, type, fone, clas, roll);
                break;
            default:
                cout << endl
                     << "\t\t Invalid key";
                break;
            }
            break;

        case 6: // delete
                system("cls");
                stu.art(1, 0, banner);
            cout << "\t __________________________________________________________________________________";
            cout << endl
                 << "\t\t Enter name :) ";
            fflush(stdin);
            // cin.getline(name,30);
            getline(cin, name);
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            // cout<<endl<<"\t\t "<<name;
            delet(name);
            break;
        case 10:
            stu.about();
        break;
        case 99:
            system("cls");
            stu.art(99, 1, Thankyou);
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
    intial();
    menu();
}

void delet(string name)
{

    bool flag = false;
    student hack;
    fstream file, outfile;
    file.open("details.txt", ios::in | ios::binary);
    outfile.open("temp.txt", ios::out | ios::binary);

    if (file.is_open())
    {
        while (file.read(reinterpret_cast<char *>(&hack), sizeof(student)))
        {
            if (hack.retName() != name)
            {
                outfile.write(reinterpret_cast<char *>(&hack), sizeof(student));
            }
            if (hack.retName() == name)
                flag = true;
        }
        file.close();
        outfile.close();
    }
    else
    {
        cout << endl
             << "\t\t File not opened";
    }
    if (flag == false)
    {
        cout << endl
             << "\t\t Name not found";
    }

    else
    {
        cout << endl
             << "\t\t Sucessfully deleted ";
        remove("details.txt");
        rename("temp.txt", "details.txt");
    }
    cout << endl
         << "\t __________________________________________________________________________________";
    getch();
}

void search(string name, string address, int type, long long int phone, int clas, int rollno)
{
    int num, n;
    fstream file;
    student stu;
    file.open("details.txt", ios::in | ios::binary);
    if (file.is_open())
    {
        if (!file.eof())
        {
            while (file.read(reinterpret_cast<char *>(&stu), sizeof(student)))
            {

                switch (type)
                {
                case 100: // name
                    if (stu.retName() == name)
                    {
                        cout << endl
                             << "\t\t Found";
                        stu.display();
                        n++;
                    }
                    break;
                case 110: // add
                    if (stu.retAdd() == address)
                    {
                        cout << endl
                             << "\t\t Found";
                        stu.display();
                        n++;
                    }
                    break;

                case 130: // clas
                    if (stu.retClas() == clas)
                    {
                        cout << endl
                             << "\t\t Found";
                        stu.display();
                        n++;
                    }
                    break;
                case 140: // rollno
                    if (stu.retRoll() == rollno)
                    {
                        cout << endl
                             << "\t\t Found";
                        stu.display();
                        n++;
                    }
                    break;
                default:
                    cout << endl
                         << "\t\t Invalid type:";
                    break;
                }
            }
            // getch();
        }
    }
    else
    {
        cout << endl
             << "\t\t File is not opened";
    }

    if (n == 0)
    {
        cout << endl
             << "\t\t Name is not found";
        // getch();
    }
    file.close();
    cout << endl
         << "\t __________________________________________________________________________________";
    getch();
}

void modify(string name, string address, int type, long long int phone, int clas, int rollno)
{
    int num, n;
    fstream file;
    student stu;
    char ch;
    file.open("details.txt", ios::in | ios::out | ios::binary);
    if (file.is_open())
    {
        if (!file.eof())
        {
            while (file.read(reinterpret_cast<char *>(&stu), sizeof(student)))
            {

                switch (type)
                {
                case 100: // name
                    if (stu.retName() == name)
                    {
                        cout << endl
                             << "\t\t Found";
                        cout << endl
                             << "\t\t Displaying current informatoin";
                        stu.display();
                        cout << endl
                             << "\t\t Press y for to modify";
                        cin >> ch;
                        if (ch == 'y' || ch == 'y')
                        {
                            stu.input();

                            int pos = (-1) * static_cast<int>(sizeof(student)); // file pointer
                            file.seekp(pos, ios::cur);
                            file.write(reinterpret_cast<char *>(&stu), sizeof(student));
                            cout << "\t\t Sucessfully modified";
                        }
                        n++;
                    }
                    break;
                case 110: // add
                    if (stu.retAdd() == address)
                    {
                        cout << endl
                             << "\t\t Found";
                        cout << endl
                             << "\t\t Displaying current informatoin";
                        stu.display();
                        cout << endl
                             << "\t\t Press y for to modify";
                        cin >> ch;
                        if (ch == 'y' || ch == 'y')
                        {
                            stu.input();

                            int pos = (-1) * static_cast<int>(sizeof(student)); // file pointer
                            file.seekp(pos, ios::cur);
                            file.write(reinterpret_cast<char *>(&stu), sizeof(student));
                            cout << "\t\t Sucessfully modified";
                        }
                        n++;
                    }
                    break;

                case 130: // clas
                    if (stu.retClas() == clas)
                    {
                        cout << endl
                             << "\t\t Found";
                        cout << endl
                             << "\t\t Displaying current informatoin";
                        stu.display();
                        cout << endl
                             << "\t\t Press y for to modify";
                        cin >> ch;
                        if (ch == 'y' || ch == 'y')
                        {
                            stu.input();

                            int pos = (-1) * static_cast<int>(sizeof(student)); // file pointer
                            file.seekp(pos, ios::cur);
                            file.write(reinterpret_cast<char *>(&stu), sizeof(student));
                            cout << "\t\t Sucessfully modified";
                        }
                        n++;
                    }
                    break;
                case 140: // rollno
                    if (stu.retRoll() == rollno)
                    {
                        cout << endl
                             << "\t\t Found";
                        cout << endl
                             << "\t\t Displaying current informatoin";
                        stu.display();
                        cout << endl
                             << "\t\t Press y for to modify";
                        cin >> ch;
                        if (ch == 'y' || ch == 'y')
                        {
                            stu.input();

                            int pos = (-1) * static_cast<int>(sizeof(student)); // file pointer
                            file.seekp(pos, ios::cur);
                            file.write(reinterpret_cast<char *>(&stu), sizeof(student));
                            cout << "\t\t Sucessfully modified";
                        }
                        n++;
                    }
                    break;
                default:
                    cout << endl
                         << "\t\t Invalid type:";
                    break;
                }
            }
        }
    }
    else
    {
        cout << endl
             << "\t\t File is not opened";
    }

    if (n == 0)
    {
        cout << endl
             << "\t\t Name is not found";
    }

    file.close();
    cout << endl
         << "\t __________________________________________________________________________________";
    getch();
}

void input()
{
    fstream file;
    student stu;
    file.open("details.txt", ios::app);
    if (file.is_open())
    {
        stu.input();
        file.write(reinterpret_cast<char *>(&stu), sizeof(student));
        cout << endl
             << "\t\t File is sucessfully written ";
    }
    else
    {
        cout << "\t\t File is not opened sucessfully";
    }
    file.close();
    cout << endl
         << "\t __________________________________________________________________________________";
    getch();
}

void display()
{
    fstream file;
    student stu;
    file.open("details.txt", ios::in);
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
        cout << endl
             << "\t\t File is not opened";
    }
    file.close();
    cout << endl
         << "\t __________________________________________________________________________________";
    getch();
}

void destory()
{
    remove("details.txt");
    cout << endl
         << "\t\t Destorying database sucessfull";
    cout << endl
         << "\t __________________________________________________________________________________";
    getch();
}

/* This program is desinged by Saroj kumar Tharu to generated Marksheet and report it */
#include <iostream>
#include <fstream>
#include <cmath>
#include <conio.h>
using namespace std;

class student
{
private:
    int rollno, clas;
    double chem, math, phy, com, nep, percent;
    string name;
    string grade;

public:
    void input();
    void display();
    void calculate();
    int retClass();
    int retRollno();
};

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
    //	double temp;
    percent = (chem + math + phy + com + nep) / 5;
    percent = round(percent);

    if (percent >= 90 && percent <= 100)
    {
        grade = "A+";
    }

    else if (percent >= 80 && percent <= 90)
    {
        grade = "A";
    }

    else if (percent >= 70 && percent <= 80)
    {
        grade = "B+";
    }

    else if (percent >= 60 && percent <= 70)
    {
        grade = "B";
    }

    else if (percent >= 50 && percent <= 60)
    {
        grade = "C+";
    }

    else if (percent >= 40 && percent <= 50)
    {
        grade = "C";
    }

    else
    {
        grade = "F";
    }

    cout << endl
         << "\t\t Grade =" << grade;
    getch();
}

void student::input()
{
    fflush(stdin);
    cout << endl
         << "\t\t <--------- Enter the name ---------> ";
    // cin >> name;
    getline(cin, name);
    cout << "\t\t <--------- Enter the Class ---------> ";
    cin >> clas;
    cout
        << "\t\t <--------- Enter the rollno ---------> ";
    cin >> rollno;

    cout
        << "\t\t <--------- Enter the marks of chemistry ---------> ";
    cin >> chem;
    cout
        << "\t\t <--------- Enter the marks of Math ---------> ";
    cin >> math;
    cout
        << "\t\t <--------- Enter the marks of Physic ---------> ";
    cin >> phy;
    cout
        << "\t\t <--------- Enter the marks of Computer ---------> ";
    cin >> com;
    cout << "\t\t <--------- Enter the marks of Nepali ---------> ";
    cin >> nep;
    calculate();
}

void student::display()
{

    cout << endl
         << "\t\t________________________________________";
    cout << endl
         << "\t\t Name of student -----> " << name;
    cout << endl
         << "\t\t Name of class -----> " << clas;
    cout << endl
         << "\t\t Name of Roll no -----> " << rollno;
    cout << endl
         << "\t\t________________________________________";
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
    cout << endl
         << "\t\t Percentage --------------> " << percent;
    cout << endl
         << "\t\t Grade :-" << grade;
    cout << endl
         << "\t\t________________________________________";
    getch();
}

void red();
void wrte();
void modify();
void del();
void destory();

int main()
{
    int choice;
    do
    {
        system("cls");
        cout << endl
             << "\t\t <------ 1 .  Input ------->";
        cout << endl
             << "\t\t <------ 2 .  Display ------->";
        cout << endl
             << "\t\t <------ 3 .  Modify ------->";
        cout << endl
             << "\t\t <------ 4 .  Delete ------->";
        cout << endl
             << "\t\t <------ 5 .  Destory database -------> ";
        cout << endl
             << "\t\t <------ 99.  Exit -------> \t";
        cin >> choice;

        switch (choice)
        {
        case 1:
            wrte(); // inputing and writing
            break;
        case 2:
            red(); // reading and displaying
            break;
        case 3:
            modify();
            break;
        case 4:
            del();
            break;
        case 5:
            destory();
        //	getch();
        default:
            break;
        }

    } while (choice != 99);
}

void del()
{
    bool found = false;
    char choice;
    fstream file, newfile;
    student stu;
    int clas, roll;

    file.open("Database.txt", ios::in);
    newfile.open("temp.txt", ios::out);
    cout << endl
         << "\t\t <------ Enter class of the student ------->  ";
    cin >> clas;
    cout << "\t\t <------ Enter Rollno of the student ------->  ";
    cin >> roll;

    if (file.is_open())
    {
        if (!file.eof())
        {
            while (file.read(reinterpret_cast<char *>(&stu), sizeof(student)))
            {
                if ((stu.retClass() != clas) && (stu.retRollno() != roll))
                {

                    newfile.write(reinterpret_cast<char *>(&stu), sizeof(student));
                }
                else
                {
                    found = true;
                }
            }
        }
    }
    else
    {
        cout << endl
             << "\t\t <-------- Unable to opened file -------> ";
        getch();
    }

    if (found == false)
    {
        cout << endl
             << "\t\t <------------- Not founded ------------> ";
    }
    else
    {
        cout << endl
             << "\t\t <------------- Sucessfully delete ------------>";
        remove("Database.txt");
        rename("temp.txt", "Database.txt");
    }
    getch();
    file.close();
    newfile.close();
}
void modify()
{
    bool found = false;
    char choice;
    fstream file;
    student stu;
    int clas, roll;

    file.open("Database.txt", ios::in | ios::app);
    cout << endl
         << "\t\t <------------- Enter class of the student ------------>  ";
    cin >> clas;
    cout << "\t\t <------------- Enter Rollno of the student ------------>  ";
    cin >> roll;

    if (file.is_open())
    {
        if (!file.eof())
        {
            while (file.read(reinterpret_cast<char *>(&stu), sizeof(student)))
            {
                if ((stu.retClass() == clas) && (stu.retRollno() == roll))
                {
                    system("cls");
                    cout << endl
                         << "\t\t <------------- After return ---->" << stu.retClass();
                    cout << endl
                         << "\t\t <------------- Sucessfully found ------------>";
                    found = true;
                    stu.display();
                    cout << endl
                         << "\t\t <------------- Press y for to edit ------------> ";
                    cin >> choice;
                    if (choice == 'y' || choice == 'Y')
                    {
                        stu.input();
                        int pos = (-1) * static_cast<int>(sizeof(student)); // file pointer
                        file.seekp(pos, ios::cur);
                        cout << endl
                             << "\t\t IN file";
                        file.write(reinterpret_cast<char *>(&stu), sizeof(student));
                        cout << endl
                             << "\t\t <------------- Sucessfully Modified ------------>";
                        getch();
                    }
                    else
                    {
                        cout << endl
                             << "\t\t <------------- NOt modified ------------>";
                    }
                }
            }
        }
    }
    else
    {
        cout << endl
             << "\t\t <------------- Unable to opened file ------------>";
        getch();
    }

    if (found == false)
    {
        cout << endl
             << "\t\t <------------- Not founded ------------> ";
    }

    file.close();
}

void red()
{
    fstream file;
    student stu;
    file.open("Database.txt", ios::in);

    if (file.is_open())
    {
        if (!file.eof())
        {
            while (file.read(reinterpret_cast<char *>(&stu), sizeof(student)))
            {
                stu.display();
            }
        }
        getch();
    }
    else
    {
        cout << endl
             << "\t\t <------------- Unable to opened file ------------>";
    }
    file.close();
}

void destory()
{
    remove("Database.txt");
    cout << endl
         << "\t\t <------------- Sucessfully Delete ------------>";
    getch();
}

void wrte()
{
    fstream file;
    student stu;

    file.open("Database.txt", ios::app);
    stu.input();
    cout << endl
         << "\t\t <------------- Rechecking the data ------------> ";
    stu.display();
    if (file.is_open())
    {
        file.write(reinterpret_cast<char *>(&stu), sizeof(student));
        // file.write(reinterpret_cast<char *>(&stu), sizeof(student) );
        cout << endl
             << "\t\t <------------- File is sucessfull written to the database ------------>";
    }
    else
    {
        cout << endl
             << "\t\t <------------- Unable to opened file ------------>";
    }
    file.close();
}
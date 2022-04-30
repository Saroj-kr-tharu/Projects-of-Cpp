#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

class book
{
private:
    string book_name, auther, publisher;
    float price;
    int stock, book_id;

public:
    void input();
    void display();
    string retname();
    string retauther();
    string retpublisher();
    float retprice();
    int retid();
};

string book::retauther()
{
    return auther;
}
string book::retpublisher()
{
    return publisher;
}
string book::retname()
{
    return book_name;
}
float book::retprice()
{
    return price;
}
int book::retid()
{
    return book_id;
}

void book::input()
{
    stock = 0;
    cout << endl
         << "\t\t<------------ Entey Section --------->";
    cout << endl
         << "\t\t Enter Id of book -----------> ";
    cin >> book_id;
    cout << "\t\t Enter Name of book -----------> ";
    // cin>>book_name;
    fflush(stdin);
    getline(cin, book_name);
    cout << "\t\t Enter Auther of book -----------> ";
    fflush(stdin);
    getline(cin, auther);
    // cin>>auther;
    cout << "\t\t Enter Publicsher of book -----------> ";
    fflush(stdin);
    getline(cin, publisher);

    cout << "\t\t Enter Stock of book -----------> ";
    cin >> stock;
    cout << "\n";
    // cin>>publisher;
}

void book::display()
{
    cout << endl
         << "\t\t<------------ Display Section --------->";
    cout << endl
         << "\t\t Id of the book -------> " << book_id;
    cout << endl
         << "\t\t Name of the book -------> " << book_name;
    cout << endl
         << "\t\t Auther of the book -------> " << auther;
    cout << endl
         << "\t\t Publisher of the book -------> " << publisher;
    cout << endl
         << "\t\t Stock of the book -------> " << stock;
}

class function
{
public:
    void wrt();
    void red();
    void menu();
    void update();
    void search();
    void destory();
};

void function::wrt()
{
    fstream file;
    book stu;
    file.open("database.txt", ios::app);
    if (file.is_open())
    {
        stu.input();
        file.write(reinterpret_cast<char *>(&stu), sizeof(book));
        cout << endl
             << "\t\t File is sucessfully written ";
    }
    else
    {
        cout << "\t\t File is not opened sucessfully";
    }
    file.close();
    getch();
}

void function::red()
{
    fstream file;
    book stu;
    file.open("database.txt", ios::in);
    if (file.is_open())
    {
        if (!file.eof())
        {

            while (file.read(reinterpret_cast<char *>(&stu), sizeof(book)))
            {
                stu.display();
                cout << endl;
            }
        }
    }
    else
    {
        cout << endl
             << "\t\t File is not opened";
    }

    file.close();
}

void function::destory()
{
    remove("database.txt");
    cout << endl
         << "\t\t<----------- Destorying database sucessfull ------->";
}

void function::search()
{

    fstream file;
    book stu;
    string bookname, auther, publish;
    int id, ch, temp = 0;
    float price;
    file.open("database.txt", ios::in);

    system("cls");
    cout << endl
         << "\t\t<---------------------------------------------------->";
    cout << endl
         << "\t\t <---------- Search Section -------->";
    cout << endl
         << "\t\t <---------- 1 . Book Id -------->";
    cout << endl
         << "\t\t <---------- 2 . Book Name -------->";
    cout << endl
         << "\t\t <---------- 3 . Book Auther -------->";
    cout << endl
         << "\t\t <---------- 4 . Book Publisher -------->";
    cout << endl
         << "\t\t <---------- 5 . Book Price  -------->";
    cout << endl
         << "\t\t<----------------------------------------------------> ";
    cin >> ch;
    temp = 0;

    switch (ch)
    {
    case 1:
        cout << endl
             << "\t\t <-------- Enter Id ------>";
        cin >> id;
        getch();
        break;
    case 2:
        cout << endl
             << "\t\t <-------- Enter Name ------>";
        fflush(stdin);
        getline(cin, bookname);

        break;
    case 3:
        cout << endl
             << "\t\t <-------- Enter Auther ------>";
        fflush(stdin);
        getline(cin, auther);

        break;
    case 4:
        cout << endl
             << "\t\t <-------- Enter Publisher ------>";
        fflush(stdin);
        getline(cin, publish);

        break;

    case 5:
        cout << endl
             << "\t\t <-------- Enter Price ------>";
        cin >> price;

        break;
    default:
        cout << endl
             << "\t\t <------ Invalid options ------>";
        break;
    }

    if (file.is_open())
    {
        if (!file.eof())
        {
            while (file.read(reinterpret_cast<char *>(&stu), sizeof(book)))
            {

                switch (ch)
                {
                case 1: // id
                    if (stu.retid() == id)
                    {
                        stu.display();
                        temp++;
                    }
                    break;
                case 2: // name
                    if (stu.retname() == bookname)
                    {

                        stu.display();
                        temp++;
                    }
                    break;

                case 3: // auther
                    if (stu.retauther() == auther)
                    {

                        stu.display();
                        temp++;
                    }
                    break;
                case 4: // publisher
                    if (stu.retpublisher() == publish)
                    {

                        stu.display();
                        temp++;
                    }
                    break;
                case 5: // price
                    if (stu.retprice() == price)
                    {
                        stu.display();
                        temp++;
                    }
                    break;
                default:
                    cout << endl
                         << "\t\t Invalid type:";
                    break;
                }
            }
            getch();
        }
    }
    else
    {
        cout << endl
             << "\t\t <---------- File is not opened -------->";
    }

    if (temp == 0)
        cout << endl
             << "\t\t <----- Record not found ------->";

    file.close();
}

void function::update()
{
    fstream file;
    book stu;
    int id,n=0;
    char ch;
    file.open("database.txt", ios::in | ios::out);
    if (file.is_open())
    {
        if (!file.eof())
        {
            while (file.read(reinterpret_cast<char *>(&stu), sizeof(book)))
            {
                cout << endl
                     << "\t\t<------- Enter the id ----->";
                cin >> id;
                if (stu.retid() == id)
                {
                    stu.display();
                    cout << endl
                         << "\t\t Press y for to modify";
                    cin >> ch;
                    if (ch == 'y' || ch == 'y')
                    {
                        stu.input();

                        int pos = (-1) * static_cast<int>(sizeof(book)); // file pointer
                        file.seekp(pos, ios::cur);
                        file.write(reinterpret_cast<char *>(&stu), sizeof(book));
                        cout << "\t\t Sucessfully modified";
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
        getch();
    }
}
    void function ::menu()
    {
        int ch;

        do
        {
            system("cls");
            cout << endl
                 << "\t\t<---------------------------------------------------->";
            cout << endl
                 << "\t\t <---------- 1 . Input -------->";
//            cout << endl
//                 << "\t\t <---------- 2 . Update -------->";
//            cout << endl
//                 << "\t\t <---------- 3 . Search -------->";
            cout << endl
                 << "\t\t <---------- 4 . Display -------->";
           cout << endl
                << "\t\t <---------- 5 . Destory -------->";
            cout << endl
                 << "\t\t <---------- 99. Exit -------->";
            cout << endl
                 << "\t\t<----------------------------------------------------> ";
            cin >> ch;

            switch (ch)
            {
            case 1:
                wrt();
                break;

            case 2:
                //    update();
                break;

            case 3:
                search();
                break;
            case 4:
                red();
                getch();
                break;
            case 5:
                destory();
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

    int main()
    {

        function fun;
        fun.menu();
        return 0;
    }

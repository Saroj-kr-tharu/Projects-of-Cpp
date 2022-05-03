#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
// template <class T1, class T2>
class jok
{
private:
    string input, output;
    int length;

public:
    // void input();
    // void display();
    void encrypt();
    void decrpt();
    void menu();
};
void Initial();
void art(int, int, string);

void Initial()
{
    string Developer = "art/Developer.txt";
    string welcome = "art/Art.txt";

    system("cls");
    system("color 2f");
    art(99, 2, welcome);
    Sleep(1000);

    system("cls");
    art(99, 0, Developer);
    Sleep(1000);
}

void art(int type, int speed, string name)
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

void jok ::menu()
{
    string banner = "art/banner.txt";
    string Developer = "art/Developer.txt";
    string welcome = "art/Art.txt";
    string thankyou = "art/thankyou.txt";
    int ch;

    do
    {
        system("cls");
        cout << endl
             << "\t\t\t\t <---------------------------------->";
        cout << endl
             << "\t\t\t\t <---------- 1 . Encryption -------->";
        cout << endl
             << "\t\t\t\t <---------- 2 . Decrption  -------->";
        cout << endl
             << "\t\t\t\t <---------- 10 . About     -------->";
        cout << endl
             << "\t\t\t\t <---------- 99. Exit       -------->";
        cout << endl
             << "\t\t\t\t <---------------------------------->";
        cin >> ch;

        switch (ch)
        {
        case 1:
            system("cls");
            art(1, 0, banner);
            encrypt();
            getch();
            break;

        case 2:
            system("cls");
            art(1, 0, banner);
            decrpt();
            getch();
            break;

        case 99:
            art(99, 1, thankyou);
            system("exit");
            break;
        case 10:
            system("cls");
            art(99, 1, Developer);
            getch();
            break;
        default:
            cout << endl
                 << "\t\t <------ INVALID OPTIONS --------> ";
            break;
        }

    } while (ch != 99);
}

void jok::encrypt()
{
    cout << endl
         << "\t\t\t\t<-------------- Input Section ----------->";
    cout << endl
         << "\t\t\t    Input String ------>";
    cin >> input;

    int length = input.length();
    char temp[length + 1], output[length + 1];

    strcpy(temp, input.c_str());
    for (int i = 0; i < length; i++)
    {

        output[i] = (temp[i] + 4);
    }
    cout << endl
         << "\t\t\t   Encrypted string ---> " << output;
}

void jok::decrpt()
{
    // cout<<endl<<"\t\t<-------------- Display Section ----------->;
    cout << endl
         << "\t\t    Decrypt String ------>";
    cin >> input;

    int length = input.length();
    char temp[length + 1], output[length + 1];

    strcpy(temp, input.c_str());

    // for(int i=0; i<=length; i++){
    //     output[i]=temp[i]-4;
    // }
    cout << endl;
    for (int i = 0; i < length; i++)
    {
        output[i] = (temp[i] - 4);
        // cout<<output[i];
    }
    cout << "\t\t       Decrypted string --------> ";
    cout << output;
}
int main()
{
    jok jo;
    Initial();
    jo.menu();
}

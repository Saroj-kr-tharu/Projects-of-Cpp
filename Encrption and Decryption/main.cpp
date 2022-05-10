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
    int len;
    string str; // string for animation

public:
    // void input();
    // void display();
    void encrypt();
    void decrpt();
    void menu();
    void animation(int, string);
};
void Initial();
void art(int, int, string);
void jok::animation(int speed, string temp)
{
    int i = 0;
    while (temp[i] != NULL)
    {
        cout << temp[i];
        i++;
        Sleep(speed);
    }
}
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
        art(2, 1, banner);
        str = "\n\t\t\t\t <------  WELCOME TO MAIN MENU  -------> ";
        animation(2, str);
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

    str = "\n\t\t\t\t <------  WELCOME TO INPUT SECTION  -------> ";
    animation(2, str);

    str = "\n\t\t\t\t  Input String -------> ";
    animation(2, str);
    fflush(stdin);
    cin >> input;

    int len = input.length();
    char temp[len + 1], output[len + 1];

    strcpy(temp, input.c_str());
    for (int i = 0; i < len; i++)
    {
        output[i] = (temp[i] + 4);
    }
    str = "\t\t\t\t  Encrypted String -------> ";
    animation(2, str);
    cout << output;
}

void jok::decrpt()
{
    // cout<<endl<<"\t\t<-------------- Display Section ----------->;
    str = "\n\t\t\t <------  WELCOME TO   DECRYPTED  SECTION  -------> ";
    animation(2, str);

    str = "\n\t\t\t\t  Encrypted String -------> ";
    animation(2, str);
    cin >> input;

    int len = input.length();
    char temp[len], output[len];

    strcpy(temp, input.c_str());

    // for(int i=0; i<=len; i++){
    //     output[i]=temp[i]-4;
    // }
    cout << endl;
    fflush(stdin);
    for (int i = 0; i < len - 2; i++)
    {
        output[i] = (temp[i] - 4);
        // cout<<output[i];
    }

    str = "\t\t\t\t       Decrypted String -------> ";
    animation(2, str);
    cout << output;
}
int main()
{
    jok jo;
    // Initial();
    jo.menu();
}

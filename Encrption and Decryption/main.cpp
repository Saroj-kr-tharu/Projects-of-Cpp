#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
//template <class T1, class T2>
class jok{
private:
    //char input[500],output[500];
    string input,output;
    int length;
public:
    //void input();
   // void display();
    void encrypt();
    void decrpt();
    void menu();
};

void jok ::menu()
{
    int ch;

    do
    {
        system("cls");
        cout << endl
             << "\t\t <---------- 1 . Encryption -------->";
        cout << endl
             << "\t\t <---------- 2 . Decrption -------->";
        cout << endl
             << "\t\t <---------- 99. Exit -------->";
        cin >> ch;

        switch (ch)
        {
        case 1:
            encrypt();
            getch();
            break;

        case 2:
          decrpt();
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

void jok::encrypt(){
    cout<<endl<<"\t\t<-------------- Input Section ----------->";
    cout<<endl<<"\t\t Input String ------>";
    cin>>input;

    int length=input.length();
    char temp[length+1],output[length+1];

    strcpy(temp,input.c_str() );
    for(int i=0; i<length; i++){
       
        output[i]= (temp[i]+4);
        
    }
    cout<<endl<<"\t\t Encrypted string ---> "<<output;
}


void jok::decrpt(){
    //cout<<endl<<"\t\t<-------------- Display Section ----------->;
    cout<<endl<<"\t\t Decrypt String ------>";
    cin>>input;

    int length=input.length();
    char temp[length+1],output[length+1];

    strcpy(temp,input.c_str() );

    // for(int i=0; i<=length; i++){
    //     output[i]=temp[i]-4;
    // }
    cout<<endl;
     for(int i=0; i<length; i++){
        output[i]= (temp[i]-4);
        //cout<<output[i];
    }
    cout<<"\t\t Decrypted string --------> ";
    cout<<output;
}
int main(){
    jok jo;
    jo.menu();
    
}

/* This program is designed by Saroj kumar tharu to developed poker game */
#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
using namespace std;
bool check=false;
class poker{
private:
    string name;
    long long int amount,betting_amount;
    int guess,generated;
public:
    void menu();
    void rules();
   // string retName;
    void annocer(int);

};

void poker::menu(){
    hell:
    if(check == false){
    cout<<endl<<"\t\t Enter name the of the Player ------> ";
    //getline(cin,name;
    cin>>name;
    fflush(stdin);
    cout<<"\t\t Enter the main  amount ------> \t";
    cin>>amount;
    cout<<"\t\t Enter the betting amount ------> \t";
    cin>>betting_amount;
    if(betting_amount>amount){
        cout<<endl<<"\t\t betting amount is more than the actual amount ------>";
        goto hell;
    }
    }
    else{
        cout<<endl<<"\t\t Enter the betting amount ------> \t";
    cin>>betting_amount;

    if(betting_amount > amount){
        cout<<endl<<"\t\t betting amount is more than the actual amount ------>";
        goto hell;
    }

    }


}
void poker::rules(){
    system("cls");
    cout<<endl<<"\t\t<----- This program is designed by Saroj kumar tharu ------>";
    cout<<endl<<"\t\t<------ Guess the number from 1 to 10 ------>";
    cout<<endl<<"\t\t<------ If you guess sucessfully you wil get 10 times of betting amount ------>";


}

void poker::annocer(int num){
        long long int choice;
    switch(num){
case 1: /// winner
    cout<<endl<<"\t\t"<<"<------ "<<name<<"  Congratulation you won ------>";
    choice=betting_amount*10;
    cout<<endl<<"\t\t You win\t\t"<<choice;
    cout<<endl<<"\t\t Total amount ------> "<<amount+choice;
    break;
case 2: // losser
    cout<<endl<<"\t\t"<<name<<"<------ Sorry you loose at this time ------>";
    choice=betting_amount;
    cout<<endl<<"\t\t<------ You loss ------>"<<choice;
    cout<<endl<<"\t\t<------ Total amount ------>"<<amount-choice;
    break;
default:
    cout<<endl<<"\t\t<------ Invalid options ------>";
    break;

    }
}

void drawline(int,char);
int main(){
    poker pok;
    int guess,generated;
    char choice,sym='_';
    string name;

    do{ system("cls");
    drawline(40,sym);
        pok.menu();
        check=true;
    cout<<endl<<"\t\t<------ Enter the guess number  :- Select number between 1 to 10 ------>";
    cin>>guess;
    generated=( rand() % 10 ) +1;

    if(guess == generated)
           pok.annocer(1);
    else
           pok.annocer(2);
           

           cout<<endl<<"\t\t <--------- Guess nbr --------> "<<guess;
           cout<<endl<<"\t\t <--------- Generated nbr --------> "<<generated;
           drawline(40,sym);

    cout<<endl<<"\t\t <--------- Press y for to play again -------->";
    cout<<endl<<"\t\t <--------- Press R for to see rules -------->";
    drawline(40,sym);
    fflush(stdin);
    choice=getch();
    if(choice == 'R' || choice == 'r'){
        pok.rules(); }


    }while(choice=='y' || choice=='Y');
    check=false;
    drawline(40,sym);
    return 0;
}


void drawline(int num,char sym){
    cout<<endl<<"\t\t";
    for(int i=0; i<=num; i++){
        cout<<sym;
    }
}

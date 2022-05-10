#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <fstream>
using namespace std;
class linked
{
private:
     struct node
     {
          int id;
          int age;
          char phone[11];
          char name[30];
          char address[50];

          struct node *next;
     };
     struct node *head;
     struct node *second;
     struct node *last;

     string str; // store information for extra animation

public:
     linked();
     ~linked();

     void display();
     void edit();

     void insert();
     void insert_at_begin();
     void insert_at_end();
     void insert_at_any_position();
     void insert_after_node(struct node *);

     void del();
     void deleteAtBegin();
     void deleteAtEnd();
     void deleteAtPosition();

     void sorting();
     void sorting_to_increase();
     void sorting_to_decrease();

     void search();
     void search_by_id();
     void search_by_age();
     void search_by_name();
     void search_by_address();
     void search_by_phone();

     void menu();
     void intial();
     void art(int, int, string);
     string c_to_str(char *);
     void wrt(int, string); // write to the file for animation
                            // int = speed , string = string
};
//
string linked::c_to_str(char *a)
{
     string s(a);
     return s;
}

// Searching Section
void linked::search_by_address()
{
     int choice = 0, size = 0;
     string temp, temp1;
     struct node *ptr;
     ptr = head;

     str = "\n\t\t <--------- WELCOME TO SEARCH BY ADDRESS SECTION ----------> ";
     wrt(2, str);

     str = "\n\t\t Enter Address ---> ";
     wrt(2, str);
     cin >> temp;

     cout << endl;
     for (int i = 1; ptr != NULL; i++)
     {
          temp1 = c_to_str(ptr->address);

          if (temp1 == temp)
          {
               str = "\n\t\t  <--- Elements  ";
               wrt(2, str);
               cout << i;
               str = " ---> ";
               wrt(2, str);

               str = "\n\t\t  ID ---> ";
               wrt(2, str);
               cout << ptr->id;

               str = "\n\t\t  Name ---> ";
               wrt(2, str);
               cout << ptr->name;

               str = "\n\t\t  Address ---> ";
               wrt(2, str);
               cout << ptr->address;

               str = "\n\t\t  Phone ---> ";
               wrt(2, str);
               cout << ptr->phone;

               str = "\n\t\t  Age ---> ";
               wrt(2, str);
               cout << ptr->age;

               cout << endl
                    << endl;
               choice = 99;
          }

          ptr = ptr->next;
     }
     if (choice != 99 && choice == 0)
     {
          str = "\n\t\t  <----- NOT FOUNDED -----> ";
          wrt(2, str);
     }
}

void linked::search_by_name()
{
     int choice = 0, size = 0;
     string temp, temp1;
     struct node *ptr;
     ptr = head;

     str = "\n\t\t <--------- WELCOME TO SEARCH BY NAME SECTION ----------> ";
     wrt(2, str);

     str = "\n\t\t Enter Name ---> ";
     wrt(2, str);
     cin >> temp;

     cout << endl;
     for (int i = 1; ptr != NULL; i++)
     {
          temp1 = c_to_str(ptr->name);

          if (temp1 == temp)
          {
               str = "\n\t\t  <--- Elements  ";
               wrt(2, str);
               cout << i;
               str = " ---> ";
               wrt(2, str);

               str = "\n\t\t  ID ---> ";
               wrt(2, str);
               cout << ptr->id;

               str = "\n\t\t  Name ---> ";
               wrt(2, str);
               cout << ptr->name;

               str = "\n\t\t  Address ---> ";
               wrt(2, str);
               cout << ptr->address;

               str = "\n\t\t  Phone ---> ";
               wrt(2, str);
               cout << ptr->phone;

               str = "\n\t\t  Age ---> ";
               wrt(2, str);
               cout << ptr->age;

               cout << endl
                    << endl;
               choice = 99;
          }

          ptr = ptr->next;
     }

     if (choice != 99 && choice == 0)
     {
          str = "\n\t\t  <----- NOT FOUNDED -----> ";
          wrt(2, str);
     }
}

void linked::search_by_phone()
{
     int choice = 0, size = 0;
     string temp, temp1;
     struct node *ptr;
     ptr = head;

     str = "\n\t\t <--------- WELCOME TO SEARCH BY PHONE SECTION ----------> ";
     wrt(2, str);
     str = "\n\t\t Enter Phone ---> ";
     wrt(2, str);
     cin >> temp;

     cout << endl;
     for (int i = 1; ptr != NULL; i++)
     {
          temp1 = c_to_str(ptr->phone);

          if (temp1 == temp)
          {
               str = "\n\t\t  <--- Elements  ";
               wrt(2, str);
               cout << i;
               str = " ---> ";
               wrt(2, str);

               str = "\n\t\t  ID ---> ";
               wrt(2, str);
               cout << ptr->id;

               str = "\n\t\t  Name ---> ";
               wrt(2, str);
               cout << ptr->name;

               str = "\n\t\t  Address ---> ";
               wrt(2, str);
               cout << ptr->address;

               str = "\n\t\t  Phone ---> ";
               wrt(2, str);
               cout << ptr->phone;

               str = "\n\t\t  Age ---> ";
               wrt(2, str);
               cout << ptr->age;

               cout << endl
                    << endl;
               choice = 99;
          }

          ptr = ptr->next;
     }
     if (choice != 99 && choice == 0)
     {
          str = "\n\t\t  <----- NOT FOUNDED -----> ";
          wrt(2, str);
     }
}
void linked::search_by_id()
{
     int temp_age, choice = 0;
     struct node *ptr;
     ptr = head;

     str = "\n\t\t <--------- WELCOME TO SEARCH BY ID SECTION ----------> ";
     wrt(2, str);

     str = "\n\t\t Enter id ---> ";
     wrt(2, str);
     cin >> temp_age;

     cout << endl;
     for (int i = 1; ptr != NULL; i++)
     {
          if (ptr->id == temp_age)
          {
               str = "\n\t\t  <--- Elements  ";
               wrt(2, str);
               cout << i;
               str = " ---> ";
               wrt(2, str);

               str = "\n\t\t  ID ---> ";
               wrt(2, str);
               cout << ptr->id;

               str = "\n\t\t  Name ---> ";
               wrt(2, str);
               cout << ptr->name;

               str = "\n\t\t  Address ---> ";
               wrt(2, str);
               cout << ptr->address;

               str = "\n\t\t  Phone ---> ";
               wrt(2, str);
               cout << ptr->phone;

               str = "\n\t\t  Age ---> ";
               wrt(2, str);
               cout << ptr->age;

               cout << endl
                    << endl;
               choice = 99;
          }

          ptr = ptr->next;
     }
     if (choice != 99)
     {
          str = "\n\t\t  <----- NOT FOUNDED -----> ";
          wrt(2, str);
     }
}

void linked::search_by_age()
{
     int temp_age, choice = 0;
     struct node *ptr;
     ptr = head;
     str = "\n\t\t  <-------- WELCOME TO SEARCHING BY AGE SECTION  ----------> ";
     wrt(2, str);

     str = "\n\t\t Enter id ---> ";
     wrt(2, str);

     cin >> temp_age;
     cout << endl;
     for (int i = 1; ptr != NULL; i++)
     {
          if (ptr->age == temp_age)
          {

               str = "\n\t\t  <--- Elements  ";
               wrt(2, str);
               cout << i;
               str = " ---> ";
               wrt(2, str);

               str = "\n\t\t  ID ---> ";
               wrt(2, str);
               cout << ptr->id;

               str = "\n\t\t  Name ---> ";
               wrt(2, str);
               cout << ptr->name;

               str = "\n\t\t  Address ---> ";
               wrt(2, str);
               cout << ptr->address;

               str = "\n\t\t  Phone ---> ";
               wrt(2, str);
               cout << ptr->phone;

               str = "\n\t\t  Age ---> ";
               wrt(2, str);
               cout << ptr->age;

               choice = 99;
          }

          ptr = ptr->next;
     }
     if (choice != 99)
     {
          str = "\n\t\t  <----- NOT FOUNDED -----> ";
          wrt(2, str);
     }
}
void linked::search()
{
     int ch;
     string banner = "art/banner.txt";
     string Developer = "art/Developer.txt";
     string welcome = "art/Art.txt";
     string thankyou = "art/thankyou.txt";
     do
     {
          system("cls");
          str = "\n\t\t\t\t <----------  MAIN MENU OF SEARCH   ------------->";
          wrt(2, str);

          cout << endl
               << "\t\t\t\t <----------------------------------------------->";
          cout << endl
               << "\t\t\t\t <---------- 1 .  Search by id           -------->";
          cout << endl
               << "\t\t\t\t <---------- 2 .  Search by Name         -------->";
          cout << endl
               << "\t\t\t\t <---------- 3 .  Search by Address      -------->";
          cout << endl
               << "\t\t\t\t <---------- 4 .  Search by Age          -------->";
          cout << endl
               << "\t\t\t\t <---------- 5 .  Search BY Phone        -------->";
          cout << endl
               << "\t\t\t\t <---------- 6 .   Display               -------->";
          cout << endl
               << "\t\t\t\t <---------- 99 .  Return Main Menu      -------->";

          cout << endl
               << "\t\t\t\t <----------------------------------------------->";
          cin >> ch;

          switch (ch)
          {
          case 1: // id
               system("cls");
               art(1, 0, banner);
               search_by_id();
               getch();
               break;
          case 2: // name
               system("cls");
               art(1, 0, banner);
               search_by_name();
               getch();
               break;

          case 3: // address
               system("cls");
               art(1, 0, banner);
               search_by_address();
               getch();
               break;
          case 4: // age
               system("cls");
               art(1, 0, banner);
               search_by_age();
               getch();
               break;
          case 5: // phone
               system("cls");
               art(1, 0, banner);
               search_by_phone();
               getch();
               break;
          case 6: // display
               system("cls");
               art(1, 0, banner);
               display();
               getch();
               break;

          case 99: // age

               cout << endl
                    << "\t\t Returning To Menu Main";
               return;
               break;
          case 10:
               system("cls");
               art(99, 1, Developer);
               getch();
               break;
          default:
               str = "\n\t\t  <-------- INVALID OPTIONS  ----------> ";
               wrt(2, str);
               break;
          }
     } while (ch != 99);
}

// Sorting Section
void linked::sorting()
{

     string banner = "art/banner.txt";
     string Developer = "art/Developer.txt";
     string welcome = "art/Art.txt";
     string thankyou = "art/thankyou.txt";

     int ch;
     do
     {
          system("cls");
          str = "\n\t\t\t\t <---------  MAIN MENU OF SORTING    ------------>";
          wrt(2, str);

          cout << endl
               << "\t\t\t\t <----------------------------------------------->";
          cout << endl
               << "\t\t\t\t <---------- 1 .  Sort to Asscending     -------->";
          cout << endl
               << "\t\t\t\t <---------- 2 .  Sort to Desscending    -------->";
          cout << endl
               << "\t\t\t\t <---------- 5 .  Display                -------->";
          cout << endl
               << "\t\t\t\t <---------- 10 . About                  -------->";
          cout << endl
               << "\t\t\t\t <---------- 99.  Return to Main Menu    -------->";
          cout << endl
               << "\t\t\t\t <----------------------------------------------->";
          cin >> ch;

          switch (ch)
          {
          case 1:
               system("cls");
               art(1, 0, banner);
               sorting_to_increase();
               getch();
               break;
          case 2:
               system("cls");
               art(1, 0, banner);
               sorting_to_decrease();
               getch();
               break;

          case 5:
               system("cls");
               art(1, 0, banner);
               display();
               getch();
               break;

          case 99:

               cout << endl
                    << "\t\t Returning To Menu Main";
               return;
               break;
          case 10:
               system("cls");
               art(99, 1, Developer);
               getch();
               break;
          default:

               str = "\n\t\t  <----  Invalid options -----> ";
               wrt(2, str);

               break;
          }

     } while (ch != 99);
}
void linked::sorting_to_decrease()
{
     struct node *current = head, *index = NULL;
     // struct node *back = (struct node *)malloc(sizeof(struct node));
     // one step further than current
     int temp;

     str = "\n\t\t  <-------- WELCOME TO SORTING DECENDING ORDER   ----------> ";
     wrt(2, str);
     if (head == NULL)
     {
          str = "\n\t\t  <-------- List is empty  ----------> ";
          wrt(2, str);

          return;
     }
     else
     {
          // for (int j = 1; current->next != NULL; j++)
          while (current != NULL)
          { // current->next;
               index = current->next;
               // for (int i = 1; index != NULL; i++) //  current==null or index==null // index->next
               while (index != NULL)
               {

                    if (current->id < index->id)
                    {
                         temp = current->id;
                         current->id = index->id;
                         index->id = temp;
                    }
                    //  current = index;
                    index = index->next;
               }
               current = current->next;
          }
     }

     str = "\n\t\t  <-------- SUCESSFULLY Sorted In Decending Order ----------> ";
     wrt(2, str);
}

void linked::sorting_to_increase()
{
     struct node *current = head, *index = NULL;
     // struct node *back = (struct node *)malloc(sizeof(struct node));
     // one step further than current
     int temp;
     str = "\n\t\t  <-------- WELCOME TO SORTING ACESSENDING ORDER   ----------> ";
     wrt(2, str);

     if (head == NULL)
     {
          str = "\n\t\t  <-------- List is empty  ----------> ";
          wrt(2, str);
          return;
     }
     else
     {
          // for (int j = 1; current->next != NULL; j++)
          while (current != NULL)
          { // current->next;
               index = current->next;
               // for (int i = 1; index != NULL; i++) //  current==null or index==null // index->next
               while (index != NULL)
               {

                    if (current->id > index->id)
                    {
                         temp = current->id;
                         current->id = index->id;
                         index->id = temp;
                    }
                    //  current = index;
                    index = index->next;
               }
               current = current->next;
          }
     }
     str = "\n\t\t <-------- SUCESSFULLY Sorted In Acessending Order ----------> ";
     wrt(2, str);
}

// Deleting section
void linked::del()
{

     string banner = "art/banner.txt";
     string Developer = "art/Developer.txt";
     string welcome = "art/Art.txt";
     string thankyou = "art/thankyou.txt";

     int ch;
     do
     {
          system("cls");
          str = "\n\t\t\t\t <---- WELCOME TO MAIN MENU  DELETE  SECTION  ----->";
          wrt(2, str);
          cout << endl
               << "\t\t\t\t <----------------------------------------------->";
          cout << endl
               << "\t\t\t\t <---------- 1 .  Delete at First        -------->";
          cout << endl
               << "\t\t\t\t <---------- 2 .  Delete at End          -------->";
          cout << endl
               << "\t\t\t\t <---------- 3 .  Delete at any position -------->";
          cout << endl
               << "\t\t\t\t <---------- 5 .  Display                -------->";
          cout << endl
               << "\t\t\t\t <---------- 10 . About                  -------->";
          cout << endl
               << "\t\t\t\t <---------- 99.  Return to Main Menu    -------->";
          cout << endl
               << "\t\t\t\t <----------------------------------------------->";
          cin >> ch;

          switch (ch)
          {
          case 1:
               system("cls");
               art(1, 0, banner);
               deleteAtBegin();
               getch();
               break;
          case 2:
               system("cls");
               art(1, 0, banner);
               deleteAtEnd();
               getch();
               break;

          case 3:
               system("cls");
               art(1, 0, banner);
               deleteAtPosition();
               getch();
               break;

          case 5:
               system("cls");
               art(1, 0, banner);
               display();
               getch();
               break;

          case 99:

               str = "\n\t\t  <-------- Returning To Main Menu  ----------> ";
               wrt(2, str);

               break;
          case 10:
               system("cls");
               art(99, 1, Developer);
               getch();
               break;
          default:
               str = "\n\t\t  <-------- Invalid Options  ----------> ";
               wrt(2, str);
               break;
          }

     } while (ch != 99);
}
void linked::deleteAtPosition()
{
     int pos;
     struct node *ptr = (struct node *)malloc(sizeof(struct node));
     struct node *back = head;
     str = "\n\t\t  <-------- WELCOME TO DELETE AT ANY POSITION SECTION  ----------> ";
     wrt(2, str);

     str = "\n\t\t Enter Positi ----> ";
     wrt(2, str);

     cin >> pos;

     for (int i = 1; i < pos - 1; i++)
     {
          if (back->next = NULL)
          {
               str = "\n\t\t  <-------- LIST IS EMPTY  ----------> ";
               wrt(2, str);
          }
          back = back->next;
     }
     ptr = back->next;
     back->next = ptr->next;
     free(ptr);

     str = "\n\t\t  <-------- Sucessfully Delete At Position  ";
     wrt(2, str);
     cout << pos;
     str = " ----------> ";
     wrt(2, str);
}

void linked::deleteAtEnd()
{
     str = "\n\t\t  <-------- WELCOME TO DELETE AT End SECTION  ----------> ";
     wrt(2, str);
     struct node *ptr = (struct node *)malloc(sizeof(struct node));
     ptr = second;
     ptr->next = NULL;
     // free(ptr);
     str = "\n\t\t  <-------- Sucessfully Delete At End   ----------> ";
     wrt(2, str);
}

void linked::deleteAtBegin()
{
     str = "\n\t\t  <-------- WELCOME TO DELETE AT BEGIN SECTION  ----------> ";
     wrt(2, str);
     head = head->next;
     str = "\n\t\t  <-------- Sucessfully Delete At First Node  ----------> ";
     wrt(2, str);
}

// Inserting section
void linked::insert_at_any_position()
{
     struct node *ptr = (struct node *)malloc(sizeof(struct node));
     struct node *back = head;
     int i = 1;
     int pos;

     str = "\n\t\t  <-------- Welcome To Insert At Any Position ----------> ";
     wrt(2, str);

     char temp[50];
     str = "\n\t\t  Enter Age --> ";
     wrt(2, str);
     cin >> ptr->age;

     str = "\t\t  Enter ID --> ";
     wrt(2, str);
     cin >> ptr->id;

     str = "\t\t  Enter Name --> ";
     wrt(2, str);
     fflush(stdin);
     cin.getline(temp, 30);
     strcpy(ptr->name, temp);

     str = "\t\t  Enter Address --> ";
     wrt(2, str);
     fflush(stdin);
     cin.getline(temp, 50);
     strcpy(ptr->address, temp);

     str = "\t\t  Enter Phone --> ";
     wrt(2, str);
     fflush(stdin);
     cin.getline(temp, 50);
     strcpy(ptr->phone, temp);

     str = "\n\t Enter position -----> ";
     wrt(2, str);
     cin >> pos;

     for (int i = 1; i < pos - 1; i++)
     {
          if (back->next == NULL)
          {
               cout << endl
                    << "\t\t List is empty";
          }
          back = back->next;
     }
     ptr->next = back->next;
     back->next = ptr;

     str = "\n\t\t  <-------- Sucessfull Inserted After Position";
     wrt(2, str);
     cout << pos;
     str = "\t ------->";
}

void linked::insert_at_end()
{
     struct node *ptr = (struct node *)malloc(sizeof(struct node));
     str = "\n\t\t  <-------- Welcome To Insert At End  ----------> ";
     wrt(2, str);

     char temp[50];
     str = "\n\t\t  Enter Age --> ";
     wrt(2, str);
     cin >> ptr->age;

     str = "\t\t  Enter ID --> ";
     wrt(2, str);
     cin >> ptr->id;

     str = "\t\t  Enter Name --> ";
     wrt(2, str);
     fflush(stdin);
     cin.getline(temp, 30);
     strcpy(ptr->name, temp);

     str = "\t\t  Enter Address --> ";
     wrt(2, str);
     fflush(stdin);
     cin.getline(temp, 50);
     strcpy(ptr->address, temp);

     str = "\t\t  Enter Phone --> ";
     wrt(2, str);
     fflush(stdin);
     cin.getline(temp, 50);
     strcpy(ptr->phone, temp);

     last->next = ptr;
     ptr->next = NULL;

     str = "\n\t\t <--------- Sucessfully Insert after at end ----------> ";
     wrt(2, str);
}

void linked::insert_after_node(struct node *back)
{
     str = "\n\t\t  <-------- Welcome to Insert after node ----------> ";
     wrt(2, str);
     back = second;
     struct node *ptr = (struct node *)malloc(sizeof(struct node));

     char temp[50];
     str = "\n\t\t  Enter Age --> ";
     wrt(2, str);
     cin >> ptr->age;

     str = "\t\t  Enter ID --> ";
     wrt(2, str);
     cin >> ptr->id;

     str = "\t\t  Enter Name --> ";
     wrt(2, str);
     fflush(stdin);
     cin.getline(temp, 30);
     strcpy(ptr->name, temp);

     str = "\t\t  Enter Address --> ";
     wrt(2, str);
     fflush(stdin);
     cin.getline(temp, 50);
     strcpy(ptr->address, temp);

     str = "\t\t  Enter Phone --> ";
     wrt(2, str);
     fflush(stdin);
     cin.getline(temp, 50);
     strcpy(ptr->phone, temp);

     ptr->next = back->next;
     back->next = ptr;

     str = "\n\t\t <--------- Sucessfully Instread after second node  ----------> ";
     wrt(2, str);
}

void linked::insert_at_begin()
{
     str = "\n\t\t  <-------- Welcome to Insert at begin  ----------> ";
     wrt(2, str);

     struct node *ptr = (struct node *)malloc(sizeof(struct node));

     char temp[50];
     str = "\n\t\t  Enter Age --> ";
     wrt(2, str);
     cin >> ptr->age;

     str = "\t\t  Enter ID --> ";
     wrt(2, str);
     cin >> ptr->id;

     str = "\t\t  Enter Name --> ";
     wrt(2, str);
     fflush(stdin);
     cin.getline(temp, 30);
     strcpy(ptr->name, temp);

     str = "\t\t  Enter Address --> ";
     wrt(2, str);
     fflush(stdin);
     cin.getline(temp, 50);
     strcpy(ptr->address, temp);

     str = "\t\t  Enter Phone --> ";
     wrt(2, str);
     fflush(stdin);
     cin.getline(temp, 50);
     strcpy(ptr->phone, temp);

     ptr->next = head;
     head = ptr;

     str = "\n\t\t  <-------- Sucessfully Inserted At Begin  ----------> ";
     wrt(2, str);
}

void linked::insert()
{
     string banner = "art/banner.txt";
     string Developer = "art/Developer.txt";
     string welcome = "art/Art.txt";
     string thankyou = "art/thankyou.txt";

     int ch;
     do
     {
          system("cls");

          str = "\n\t\t\t\t <-------  WELCOME TO INSERT MAIN MENU  --------->";
          wrt(2, str);

          cout << endl
               << "\t\t\t\t <----------------------------------------------->";
          cout << endl
               << "\t\t\t\t <---------- 1 .  Insert at First        -------->";
          cout << endl
               << "\t\t\t\t <---------- 2 .  Insert at End          -------->";
          cout << endl
               << "\t\t\t\t <---------- 3 .  Insert at any position -------->";
          cout << endl
               << "\t\t\t\t <---------- 4 .  Insert After a Node    -------->";
          cout << endl
               << "\t\t\t\t <---------- 5 .  Display                -------->";
          cout << endl
               << "\t\t\t\t <---------- 10 . About                  -------->";
          cout << endl
               << "\t\t\t\t <---------- 99.  Return to Main Menu    -------->";
          cout << endl
               << "\t\t\t\t <----------------------------------------------->";
          cin >> ch;

          switch (ch)
          {
          case 1:
               system("cls");
               art(1, 0, banner);
               insert_at_begin();
               getch();
               break;
          case 2:
               system("cls");
               art(1, 0, banner);
               insert_at_end();
               getch();
               break;

          case 3:
               system("cls");
               art(1, 0, banner);
               insert_at_any_position();
               getch();
               break;

          case 4:
               system("cls");
               art(1, 0, banner);
               insert_after_node(second);
               getch();
               break;
          case 5:
               system("cls");
               art(1, 0, banner);
               display();
               getch();
               break;

          case 99:

               str = "\n\t\t <--------- Returning To Main Menu ----------> ";
               wrt(2, str);

               break;
          case 10:
               system("cls");
               art(99, 1, Developer);
               getch();
               break;
          default:

               str = "\n\t\t <--------- Invalid options ----------> ";
               wrt(2, str);
               break;
          }

     } while (ch != 99);
}

// Editing section
void linked::edit()
{
     struct node *ptr = head;
     int elements;
     char temp[50];

     str = "\n\t\t <--------- Editing Section ----------> ";
     wrt(2, str);
     display();

     str = "\n\t Press No Of Elements ----------> ";
     wrt(2, str);
     fflush(stdin);
     cin >> elements;

     if (ptr == NULL)
     {
          str = "\n\t\t <--------- List is empty ----------> ";
          wrt(2, str);
          return;
     }

     for (int i = 1; ptr != NULL; i++)
     {
          if (elements == i)
          {
               system("cls");

               str = "\n\t\t <--------- Current Information ----------> ";
               wrt(2, str);

               str = "\n\t   Current id ---> ";
               wrt(2, str);
               cout << ptr->id;

               str = "\n\t   Current Name ---> ";
               wrt(2, str);
               cout << ptr->name;

               str = "\n\t   Current address ---> ";
               wrt(2, str);
               cout << ptr->address;

               str = "\n\t   Current Age ---> ";
               wrt(2, str);
               cout << ptr->age;

               str = "\n\t   Current Phone ---> ";
               wrt(2, str);
               cout << ptr->phone;

               ;

               str = "\n\n\t\t <--------- New Information Filling  ----------> ";
               wrt(2, str);

               str = "\n\t   Enter New id ---> ";
               wrt(2, str);
               cin >> ptr->id;

               str = "\t   Enter New Name ---> ";
               wrt(2, str);

               fflush(stdin);
               cin.getline(temp, 30);
               strcpy(ptr->name, temp);

               str = "\t   Enter New address ---> ";
               wrt(2, str);
               fflush(stdin);
               cin.getline(temp, 50);
               strcpy(ptr->address, temp);

               str = "\t   Enter New Age ---> ";
               wrt(2, str);
               cin >> ptr->age;

               str = "\t   Enter New Phone ---> ";
               wrt(2, str);
               fflush(stdin);
               cin.getline(temp, 50);
               strcpy(ptr->phone, temp);

               str = "\n\t <-------- Sucessfully Edited ----------> ";
               wrt(2, str);
          }
          ptr = ptr->next;
     }
}

// Displaying section
void linked::display()
{
     str = "\n\t\t <--------- WELCOME TO DISPLAY SECTION ----------> ";
     wrt(2, str);

     struct node *ptr = head;
     int i = 1;

     cout << endl;
     while (ptr != NULL)
     {

          str = "\n\t\t  <--- Elements  ";
          wrt(2, str);
          cout << i;
          str = " ---> ";
          wrt(2, str);

          cout << endl
               << "\t\t ID --->";
          cout << ptr->id;

          cout << endl
               << "\t\t NAME --->";
          cout << ptr->name;

          cout << endl
               << "\t\t ADDRESS --->";
          cout << ptr->address;

          cout << endl
               << "\t\t PHONE --->";
          cout << ptr->phone;

          cout << endl
               << "\t\t AGE --->";
          cout << ptr->age;

          cout << endl
               << endl;
          ptr = ptr->next;
          i++;
     }
}

// Main menu
void linked::menu()
{

     string banner = "art/banner.txt";
     string Developer = "art/Developer.txt";
     string welcome = "art/Art.txt";
     string thankyou = "art/thankyou.txt";
     intial();
     int ch;
     do
     {
          system("cls");
          str = "\n\t\t\t\t <----- WELCOME TO MAIN MENU  ------> ";
          wrt(2, str);
          cout << endl
               << "\t\t\t\t <---------------------------------->";
          cout << endl
               << "\t\t\t\t <---------- 1 . Insertion -------->";
          cout << endl
               << "\t\t\t\t <---------- 2 . Editing   -------->";
          cout << endl
               << "\t\t\t\t <---------- 3 . Delete    -------->";
          cout << endl
               << "\t\t\t\t <---------- 4 . Sorting   -------->";
          cout << endl
               << "\t\t\t\t <---------- 5 . Display   -------->";
          cout << endl
               << "\t\t\t\t <---------- 6 . Search    -------->";
          cout << endl
               << "\t\t\t\t <---------- 10 .About     -------->";
          cout << endl
               << "\t\t\t\t <---------- 99. Exit      -------->";
          cout << endl
               << "\t\t\t\t <---------------------------------->";
          cin >> ch;

          switch (ch)
          {
          case 1:
               system("cls");
               art(1, 0, banner);
               insert();
               getch();
               break;
          case 2:
               system("cls");
               art(1, 0, banner);
               edit();
               getch();
          case 3:
               system("cls");
               art(1, 0, banner);
               del();
               getch();
               break;

          case 4:
               system("cls");
               art(1, 0, banner);
               sorting();
               getch();
               break;
          case 5:
               system("cls");
               art(1, 0, banner);
               display();
               getch();
               break;

          case 6:
               system("cls");
               art(1, 0, banner);
               search();
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
               str = "\n\t\t <--------- Invalid options ----------> ";
               wrt(2, str);
               break;
          }

     } while (ch != 99);
}

// Contructor
linked::linked()
{
     // int temp_id, temp_age;
     char name_temp[30] = "Saroj";
     char address_temp[50] = "Maithawa";
     char temp_phone[11] = "9800585856";

     head = (struct node *)malloc(sizeof(struct node));
     second = (struct node *)malloc(sizeof(struct node));
     last = (struct node *)malloc(sizeof(struct node));

     head->age = 1;
     head->id = 1;
     strcpy(head->name, name_temp);
     strcpy(head->address, address_temp);
     strcpy(head->phone, temp_phone);
     head->next = second;

     second->age = 2;
     second->id = 2;
     strcpy(second->name, name_temp);
     strcpy(second->address, address_temp);
     strcpy(second->phone, temp_phone);
     second->next = last;

     last->age = 99;
     last->id = 99;
     strcpy(last->name, name_temp);
     strcpy(last->address, address_temp);
     strcpy(last->phone, temp_phone);
     last->next = NULL;
}
// destructor
linked::~linked()
{
     free(head);
     free(second);
     free(last);
}

// program start from here
int main()
{
     linked link;
     link.menu();
     return 0;
}

// Intialzation of art and color setting
void linked::intial()
{
     string Developer = "art/Developer.txt";
     string welcome = "art/Art.txt";

     linked ct;
     // system("color 71");
     system("color 87");

     system("cls");
     ct.art(99, 2, welcome);
     Sleep(1000);

     system("cls");
     ct.art(1, 0, Developer);
     Sleep(1000);
}

// Function to design a art
void linked ::art(int type, int speed, string name)
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

// Function to write in the file for extra animation

void linked::wrt(int speed, string str)
{

     int i = 0;
     while (str[i] != NULL)
     {
          cout << str[i];
          i++;
          Sleep(speed);
     }
}

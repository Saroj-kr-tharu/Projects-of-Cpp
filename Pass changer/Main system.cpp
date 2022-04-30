/* This program is designed by Saroj kumar tharu to change the password of the computer */
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <conio.h>
using namespace std;
class sys
{
private:
	int ch, num;
	int i;
	string str, str1, str3;
	string username, password;
	char strfinal[30];

public:
	void menu();
	void user_list();
	void new_user();
	void del_user();
	void pass_change();
	void add_in_admin();
	void remove_from_admin();
};
void menu();
int main()
{
	sys sy;
	sy.menu();
}
void sys::user_list()
{
	system("cls");
	system("net user");
}
void sys::new_user()
{
	system("cls");
	system("net user");
	cout << endl
		 << "\t\t Enter the username to add ";
	fflush(stdin);
	cout << endl;
	getline(cin, username);

	cout << endl
		 << "\t\t Enter the password to add ";
	fflush(stdin);
	cout << endl;
	getline(cin, password);
	str1 = "net user";
	str = str1 + " " + username + " " + password + " /add ";
	cout << endl
		 << str;
	getch();
	num = str.length();

	for (i = 0; i <= num; i++)
	{
		strfinal[i] = str[i];
	}
	cout << endl
		 << "\t\t " << strfinal;
	system(strfinal);
}
void sys::del_user()
{
	system("cls");
	system("net user");
	cout << endl
		 << "\t\t Enter the user name to delete ";
	fflush(stdin);
	cout << endl;
	getline(cin, username);

	str1 = "net user";
	str = str1 + " /delete " + username;

	num = str.length();

	for (i = 0; i <= num; i++)
	{
		strfinal[i] = str[i];
	}

	system(strfinal);
}

void sys::pass_change()
{
	system("cls");
	system("net user");
	cout << endl
		 << "\t\t Enter username to change the password";
	//	getline(username,cin);
	fflush(stdin);
	cout << endl;
	getline(cin, username);

	str1 = "net user";
	str = str1 + " " + username + " *";

	num = str.length();

	for (i = 0; i <= num; i++)
	{
		strfinal[i] = str[i];
	}

	system(strfinal);
}

void sys::add_in_admin()
{
	system("cls");
	system("net user");
	cout << endl
		 << "\t\t Enter the user name to add in admin group ";
	fflush(stdin);
	cout << endl;
	getline(cin, username);

	str1 = "net localgroup administrators";
	str = str1 + " " + username + " /add ";

	num = str.length();
	for (i = 0; i <= num; i++)
	{
		strfinal[i] = str[i];
	}
	//	cout<<endl<<"\t\t "<<strfinal;
	system(strfinal);
}

void sys::remove_from_admin()
{
	system("cls");
	system("net user");
	cout << endl
		 << "\t\t Enter the user name to delete in admin group ";
	fflush(stdin);
	cout << endl;
	getline(cin, username);

	str1 = "net localgroup administrators";
	str = str1 + " " + username + " /delete ";

	num = str.length();
	for (i = 0; i <= num; i++)
	{
		strfinal[i] = str[i];
	}
	//	cout<<endl<<"\t\t "<<strfinal;
	system(strfinal);
}
void sys::menu()
{

	do
	{
		system("cls");
		cout << endl
			 << "\t\t <-------------------------------------------------------->";
		cout << endl
			 << "\t\t <---  Welcome to the main security of the computer ---> ";
		cout << endl
			 << "\t\t <---------- 1  . User List --------> ";
		cout << endl
			 << "\t\t <---------- 2  . Password Change --------> ";
		cout << endl
			 << "\t\t <---------- 3  . Delete User --------> ";
		cout << endl
			 << "\t\t <---------- 4  . Add New User --------> ";
		cout << endl
			 << "\t\t <---------- 5  . Add user in Administration --------> ";
		cout << endl
			 << "\t\t <---------- 6  . Remove user from Administration --------> ";
		cout << endl
			 << "\t\t <---------- 99 . Exit --------> ";
		cout << endl
			 << "\t\t <---------- 100. NOTE --------> ";
		cout << endl
			 << "\t\t <-------------------------------------------------------->";
		cin >> ch;

		switch (ch)
		{
		case 1: // user list
			user_list();
			getch();
			break;

		case 2: // user change
			pass_change();
			getch();

			break;
		case 3:
			del_user();
			getch();
			break;

		case 4: // add user
			new_user();
			getch();
			break;
		case 5:
			add_in_admin();
			getch();
			break;
		case 6:
			remove_from_admin();
			getch();
			break;
		case 99:
			cout << endl
				 << "\t\t<------ Thanks for using our program ------> ";
			getch();
			break;
		case 100:
			cout << endl
				 << "\t\t<----- Please run this program in administrator mode for to do work sucessfully ------>";
			cout << endl
				 << endl;
			getch();
			break;

		default:
			cout << endl
				 << "\t\t<------  Invalid options -----> ";
			break;
		}
	} while (ch != 99);
}
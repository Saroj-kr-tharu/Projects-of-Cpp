#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <sstream>
#include <Windows.h>
using namespace std;
class sys
{
private:
	char ch;
	// string str1="C:\\Windows\\System32\\shutdown /s /t",str2,str;
	int sec, i;
	string strOne, strTwo;
	char str_One[50], str_Two[10];
	ostringstream intToStr;
	int choice, num;

public:
	void menu();
	void restart();
	void shutdown();
	void cancell();
	void art(int, int, string);
};

void sys ::art(int type, int speed, string name)
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

void sys::restart()
{
	system("C:\\Windows\\System32\\shutdown /r");
	cout << endl
		 << "\t\t <------- The computer will be restarted in 1 min -----------> ";
}
void sys::shutdown()
{
	cout << "\t\t <------- Press y for to set timer or nothing for default -----------> ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		cout << endl
			 << "\t\t <------- Enter second for timer -----------> ";
		cin >> sec;

		intToStr << sec;
		strOne = "C:\\Windows\\System32\\shutdown /s /t ";
		strTwo = intToStr.str();
		i = 0;
		while (strOne[i])
		{
			str_One[i] = strOne[i];
			i++;
		}
		str_One[i] = '\0';
		i = 0;
		while (strTwo[i])
		{
			str_Two[i] = strTwo[i];
			i++;
		}
		str_Two[i] = '\0';
		strcat(str_One, str_Two);
		system(str_One);
		cout << endl
			 << "\t\t <------- The computer will be shutdown within ----------->  " << sec;
	}
	else
	{
		system("C:\\Windows\\System32\\shutdown /s");
		cout << endl
			 << "\t\t <------- The computer will be shutdown within 1 min -----------> ";
	}
}
void sys::cancell()
{
	system("C:\\Windows\\System32\\shutdown /a");
	cout << endl
		 << "\t\t <------- All the log computer will be cancell -----------> ";
}

void sys::menu()
{
	int choice;
	string Thankyou = "art/thankyou.txt";
	string banner = "art/banner.txt";
	string Developer = "art/Developer.txt";
	do
	{
		system("cls");
		art(1, 1, banner);
		cout << endl
			 << "\t\t <------- Welcome to Main Security System ----------->  ";
		cout << endl
			 << "\t\t  <------- 1 . Restart   Computer -----------> ";
		cout << endl
			 << "\t\t  <------- 2 .  Shutdown Computer -----------> ";
		cout << endl
			 << "\t\t  <-------  9 .  To  Cancell           ------>  ";
		cout << endl
			 << "\t\t  <------- 10.        About       ----------->  ";
		cout << endl
			 << "\t\t  <------- 99.        Exit        -----------> ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		system("cls");
		art(1,1,banner);
			restart();
			getch();
			break;
		case 2: // shutdown
		system("cls");
		art(1,1,banner);
			shutdown();
			getch();
			break;
		case 9:
		system("cls");
		art(1,1,banner);
			cancell();
			getch();

			break;
		case 10:
			system("cls");
			art(99, 1, Developer);
			break;
		case 99:
			system("cls");
			art(99, 1, Thankyou);
			break;
		default:
			cout << endl
				 << "\t\t <------ Invalid options ------> ";
			break;
		}

	} while (choice != 99);
}

void about()
{
	string Developer = "art/Developer.txt";
	sys stu;
	system("cls");
	stu.art(99, 1, Developer);
	getch();
}

void intial()
{
	string Developer = "art/Developer.txt";
	string welcome = "art/Art.txt";

	sys ct;
	// system("color 71");
	system("color 87");

	system("cls");
	ct.art(99, 2, welcome);
	Sleep(1000);

	system("cls");
	ct.art(1, 0, Developer);
	Sleep(4000);
}

int main()
{
	sys s;
	intial();
	s.menu();
	return 0;
}

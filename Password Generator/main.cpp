#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;
void intial();
class joker
{
private:
	string smal = "abcdefghifklmnopqrstuvwxyz";
	string big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string number = "0123456789";
	string special = "_+[]|{};:,./<>?";
	string data = smal + big + number + special;

public:
	void process();
	void percent(string);		// Password is passed to pass as a string
	void art(int, int, string); // type,speed,filename
	string banner = "art/banner.txt";
	string admin = "art/admin.txt";
	string hack = "art/hack.txt";
};
void joker::art(int type, int speed, string name)
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
void joker::percent(string temp)
{
	int size;
	size = strlen(temp.c_str());

	art(99, 1, admin);
	if (size > 6 && size < 8)
	{
		cout << "\t\t\t ----> 80% ";
	}
	else if (size > 8 && size < 10)
	{
		cout << "\t\t\t ----> 60% ";
	}
	else if (size > 10 && size < 15)
	{
		cout << "\t\t\t ----> 10% ";
	}
	else if (size > 15)
	{
		cout << "\t\t\t ----> 1%";
	}
	else
	{
		cout << "\t\t\t\t Hackable ";
	}
	art(99, 1, hack);
}
void joker::process()
{
	srand(time(0));

	string pass;
	int size;

	cout << endl
		 << "\t\t Enter the length of password ---------> ";
	cin >> size;

	for (int i = 0; i <= size; i++)
	{
		pass = pass + data[rand() % 77];
	}

	cout << "\t\t     Your password -------> " << pass;
	percent(pass);
	getch();
}

void intial()
{
	string Developer = "art/Developer.txt";
	string welcome = "art/Art.txt";

	string thankyou = "art/thankyou.txt";
	joker jok;
	system("color 71");

	system("cls");
	jok.art(99, 2, welcome);
	Sleep(1000);

	system("cls");
	jok.art(1, 0, Developer);
	getch();
}

int main()
{
	joker jok;
	string banner = "art/banner.txt";

	intial();

	system("cls");
	jok.art(1, 0, banner);
	jok.process();
	return 0;
}
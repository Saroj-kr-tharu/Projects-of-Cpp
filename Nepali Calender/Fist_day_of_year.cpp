#include <iostream>
#include <conio.h>
using namespace std;
void fun(int, int, int);
void Bs_To_Ad(int, int, int);

int new_years;
int new_month;
int new_day;

int main()
{
	char ch1;
	// int date;
	int years, month, day;

	do
	{
		cout << endl
			 << "\t\t Enter the day in years/month/day --------------------->";
		fflush(stdin);
		cin >> years;
		cin.ignore(1, '/');
		cin >> month;
		cin.ignore(1, '/');
		cin >> day;
		// date -= 57;
		new_years = years;
		new_month = month;
		new_day = day;
		Bs_To_Ad(years, month, day);
		cout << endl
			 << "\t\t<---- Press y to run again ----> ";
		fflush(stdin);
		ch1 = getch();
	} while (ch1 == 'y' || ch1 == 'Y');

	return 0;
}

void Bs_To_Ad(int years, int month, int day)
{
	string Nepali[] = {"Baishak", "Jetha", "Ashar", "Shrawan", "Bhadra", "Ashoj", "Kartik", "Mangir", "Poush", "Magh", "Falgun", "Chaitra"};
	string English[] = {"Januray", "Feburary", "March", "April", "May", "June", "July", "Auguest", "September", "Octber", "November", "December"};

	cout << endl
		 << "\t\t <------------------------ BS TO AD --------------------------> ";

	if (day > 17)
	{
		day -= 17;
	}
	else
	{
		day += 30;
		--month;
		day -= 17;
	}

	if (month > 8)
	{
		month -= 8;
	}
	else
	{
		month += 12;
		--years;
		month -= 8;
	}
	years -= 56;

	cout << endl
		 << "\t\t In Bs -----> " << new_years << "/" << new_month << "/" << new_day;
	cout << endl
		 << "\t\t In BS -----> " << new_years << "/" << Nepali[new_month - 1] << "/" << new_day;

	cout << endl
		 << endl
		 << "\t\t In Ad -----> " << years << "/" << month << "/" << day;
	cout << endl
		 << "\t\t In AD -----> " << years << "/" << English[month - 1] << "/" << day;

	getch();

	fun(new_years, new_month, new_day);
}

void fun(int year, int month, int day)
{
	string weeks[] = {" Sun", " Mon", " Tue ", "Wed", " Thu ", "  Fri ", "  Sat "};
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1,
					  4, 6, 2, 4};

	int temp_day;
	temp_day;

	year -= month < 3;
	temp_day = (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;

	cout << endl
		 << "\t\t Date ---> " << temp_day + 5;

	cout << endl
		 << "\t\t Day ----> " << weeks[temp_day - 2];
}

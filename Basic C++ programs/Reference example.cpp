#include<iostream>
using namespace std;

int main()
{
	int a=10;
	int &r=a;
	cout<<a<<endl<<r<<endl;
	
	int b=5;   //Here the value of 'b' is given to 'r' and 'r' is a nickname of 'a' so by changing 'r' you also change 'a'
	r=b;
	cout<<a<<endl<<r<<endl<<b<<endl;
	return 0;
}

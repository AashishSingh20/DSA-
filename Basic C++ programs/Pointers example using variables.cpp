#include<iostream>
using namespace std;

int main()
{
	int a=3;
	int *p;
	p=&a;
	
	cout<<"Without using pointer:"<<a<<endl;
	cout<<"Using pointer:"<<*p<<endl;
	return 0;
}

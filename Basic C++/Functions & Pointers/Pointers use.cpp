#include<iostream>
using namespace std;

int main(){
	int x = 56;
	int* p = &x;  //Pointer p stores the address of x;
	cout<<x<<endl;
	cout<<&x<<endl;  //Display's the address of x
	cout<<*p<<endl;  //Display's the value at the stored adress in p;
	cout<<&p<<endl;  // Display address of variable p
	
	*p = 45; // Changes the value of x
	cout<<x<<endl;
}

#include<iostream>
using namespace std;

int swap(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
	cout<<"a:"<<a<<endl<<"b:"<<b<<endl;
}

int main(){
	int x=10,y=50;
	swap(x,y);
	
	cout<<"First number:"<<x<<endl;  //Here actual parameters gets changed by changing formal parameters.
	cout<<"Second number:"<<y<<endl;
	
	return 0;
}

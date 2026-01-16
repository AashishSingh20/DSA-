#include<iostream>
using namespace std;

int pow(int x,int y){
	if(y==0){
		return 1;
	}
	return x * pow(x,y-1); 	
}

int main(){
	int a,b;
	cout<<"Enter a number: ";
	cin>>a;
	cout<<"Enter it's power: ";
	cin>>b;
	
	cout<<"The factorial of the given number is: "<<pow(a,b)<<endl;
}

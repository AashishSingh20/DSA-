#include<iostream>
using namespace std;

int x = 0;  //Here we are declaring x as a global variable
int fun(int n){
	if(n>0){
		x++;
		return fun(n-1) + x;
	}
	return 0;
}

int main(){
	int a;
	cout<<"Enter a number:";
	cin>>a;
	cout<<fun(a); 
	
	return 0;
}

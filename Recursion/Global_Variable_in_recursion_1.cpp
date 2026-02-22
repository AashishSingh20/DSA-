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
	int r;
	r = fun(3);
	cout<<r<<endl;
	
	r = fun(3); // Here it is printing 2x of first call because value is x is already initialized to 3 then this call again increases the value by 3 then so value of x becomes "6" 
	cout<<r; 
	
	return 0;
}

#include<iostream>
using namespace std;

int fibo(int n){
	if(n == 1 ){
		return 0;	
	}
	else if(n == 2){
		return 1;
	}
	return fibo(n-1)+fibo(n-2);
}

int main(){
	int a;
	cout<<"Enter the index: ";
	cin>>a;
	
	cout<<"The fibonacci of the given index is: "<<fibo(a)<<endl;
}

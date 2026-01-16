#include<iostream>
using namespace std;

void fun(int n){
	if(n>0){
		cout<<n;
		fun(n-1);
		fun(n-1);
	}
}

int main(){
	int a;
	cout<<"Enter the number:";
	cin>>a;
	fun(a);
	
	return 0;
}

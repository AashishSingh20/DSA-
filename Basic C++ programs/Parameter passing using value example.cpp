#include<iostream>
using namespace std;

int add(int a, int b){
	a++;
	cout<<a<<endl;
	return 0;
}

int main(){
	int x=10,y=5;
	add(x,y);
	cout<<x;
	
	return 0;
}

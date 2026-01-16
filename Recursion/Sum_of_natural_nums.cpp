#include<iostream>
using namespace std;

int sum(int n){
	if(n>0){
		return n+sum(n-1);
	}
	else{
		return 0;
	}
}

int main(){
	int r;
	cout<<"Enter number:";
	cin>>r;
	cout<<"Sum of all natural numbers till "<< r <<" is "<<sum(r);
	
	return 0;
}

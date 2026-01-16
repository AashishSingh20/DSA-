#include<iostream>
using namespace std;

int power(int m, int n){
	if(n==0){
		return 1;
	}
	else{
		return m*power(m,n-1);
		}
}

int main(){
	int a,b;
	cout<<"Enter a number:";
	cin>>a;
	cout<<"Enter it's power:";
	cin>>b;
	
	int ans = power(a,b);
	cout<<a<<"^"<<b<<": "<<ans; 
}

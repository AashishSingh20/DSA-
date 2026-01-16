#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter n: ";
	cin>>n;
	
	int sum = 0;
	while(n!=0){
	   int lastDigit = n%10;
	   sum = sum+lastDigit;
	   n = n/10;
	}
	cout<<"Sum of all numbers is:"<<sum<<endl;
}

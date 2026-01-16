#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter n: ";
	cin>>n;
	
	int product = 1;
	while(n!=0){
	   int lastDigit = n%10;
	   product = product*lastDigit;
	   n = n/10;
	}
	cout<<"Sum of all numbers is:"<<product<<endl;
}

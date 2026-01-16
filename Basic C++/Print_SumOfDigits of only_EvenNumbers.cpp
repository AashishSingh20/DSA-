#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter n: ";
	cin>>n;
	
	int sum = 0;
	while(n!=0){
	   int lastDigit = n%10;
	   
	   if(lastDigit%2==0){
	      sum = sum+lastDigit;
	   }
	      n = n/10;
	}
	cout<<"Sum of all even numbers is:"<<sum<<endl;
}

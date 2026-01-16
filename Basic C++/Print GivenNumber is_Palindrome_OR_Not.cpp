#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter n: ";
	cin>>n;
	
	int original = n;
	int reverse= 0;
	while(n!=0){
		int lastDigit = n%10;
		reverse = reverse*10+lastDigit;
		n=n/10;
	}
	cout<<"Reverse of the given number is:"<<reverse<<endl;
	
		if(original==reverse){
	        cout<<"It is a Palindrome Number"<<endl;
		}
	    else{
	        cout<<"It is not a Palindrome Number"<<endl;
     	}
}

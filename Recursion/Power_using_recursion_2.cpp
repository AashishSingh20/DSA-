#include<iostream>
using namespace std;

int power(int m, int n){
	if(n==0){    // Base case
		return 1;
	}

	if(n==1){
		return m;
	}

	int ans = power(m,n/2);
	if(n%2==0){    // If power is even 
		return ans*ans;  // Eg:-(m=2,n=4 so it gives (2^2)^2 )	
	}
	else{     // If power is odd
		return m*ans*ans;  // Eg:-(m=2,n=5 so it gives 2*(2^2)^2)
	}
} 

int main(){
	int a,b;
	cout<<"Enter a number:";
	cin>>a;
	cout<<"Enter it's power:";
	cin>>b;
	
	cout<<"Answer:"<<power(a,b); 
}

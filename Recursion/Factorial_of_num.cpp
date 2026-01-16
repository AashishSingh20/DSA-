#include<iostream>
using namespace std;

int factorial(int n){
	if(n==0){
		return 1;  // this is the base case
	}
	else{
	    return n*factorial(n-1);  // Here value of n is decreased and multiplied with each call (Eg:- n = 3  so 3*2*1*0  then return)
	}
}

int main(){
	int a;
	cout<<"Enter a number:";
	cin>>a;
	cout<<"Factorial of "<< a <<" is "<<factorial(a);
	return 0;
}


// T.C:- O(n)
// S.C:- O(n)
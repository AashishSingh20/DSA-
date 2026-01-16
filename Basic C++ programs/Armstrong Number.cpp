#include<iostream>
using namespace std;

int numdigit(int n){
	int count = 0;
	while(n!=0){
		n = n/10;
	    count++;
	}
	return count;
}

int pow(int x,int y){
	int power = 1;
	for(int i=0;i<y;i++){
		power = power*x;
	}
	return power;
}

int main(){
	int n;
	cout<<"Enter a number: ";
	cin>>n;
	int num = n;
	int a = numdigit(num);
	cout<<"Number of digits are: "<<a<<endl;
	int sum = 0;
	while(n!=0){
		int digit = n%10;
	    sum += pow(digit,a);
	    n = n/10;
	}
	if(sum == num){
		cout<<"It is an Armstrong Number."<<endl;
	}
	else{
		cout<<"It is not an Armstrong Number.";
	}	
}

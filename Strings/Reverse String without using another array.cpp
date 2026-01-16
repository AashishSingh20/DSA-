#include<iostream>
#include<string>
using namespace std;

int main(){
	string A = "hello";
	char temp;
	int j = A.length()-1;  // String ke length tak jaega aur -1 karega taki last character mil jaye kyuki last mein \0 rehta hai
	
	int i = 0;
	while(i<j){
		temp = A[i];
		A[i] = A[j];
		A[j] = temp;
		i++;
		j--;
	}
	cout<<"Reverse of the string is: "<<A;
}

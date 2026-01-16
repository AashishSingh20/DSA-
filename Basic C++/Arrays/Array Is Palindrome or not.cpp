#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of elements in the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter array elements: ";
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	bool isPalindrome = true;
	for(int i=0;i<n/2;i++){
		if(arr[i]!= arr[n-i-1]){
			isPalindrome = false;
			break;
		}
	}
	
	if(isPalindrome){
		cout<<"Array is a Palindrome";
	}
	else{
		cout<<"Array is not a Palindrome";
	}
}

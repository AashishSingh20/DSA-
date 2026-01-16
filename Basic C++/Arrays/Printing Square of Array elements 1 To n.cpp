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
	cout<<"Elements of the array after squaring are: ";
	
	for(int i=0;i<n;i++){
		cout<<arr[i]*(i+1)<<" ";
	}
}

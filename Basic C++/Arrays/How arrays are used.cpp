#include<iostream>
using namespace std;

int main(){
	int arr[5]; // Declaration
//	arr[0] = 5; // Set
//	arr[1] = 6;
//	arr[2] = 2;
//	arr[3] = 0;
//	arr[4] = 7;
//	cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4];

    int arr[5] = {4,5,2,7,9};  // Declaration and Initialization	
	cout<<"Enter array elements: ";
	
	for(int i=0;i<=4;i++){
		cin>>arr[i];
	}
	
	for(int i=0;i<=4;i++){
		cout<<arr[i]<<" ";
	}
}


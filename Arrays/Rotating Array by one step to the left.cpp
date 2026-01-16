#include<iostream>
using namespace std;

void RotateArray(int A[],int n){
	int temp =A[0];
	for(int i=0;i<n-1;i++){
		A[i] = A[i+1];
	}
	A[n-1] = temp;
}

int main(){
	int arr[] = {12,44,23,2,4,5,2,45,53};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"Original Array: ";
	for(int i=0;i<=n-1;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    RotateArray(arr,n);
    
    cout<<"After Rotating the Array: ";
	for(int i=0;i<=n-1;i++){
		cout<<arr[i]<<" ";
    }
}

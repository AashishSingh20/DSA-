#include<iostream>
using namespace std;

void ShiftArray(int A[],int n){
	for(int i=0;i<n;i++){
		A[i] = A[i+1];
	}
}

int main(){
	int arr[] = {12,44,23,2,4,5,2,45,53};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"Original Array: ";
	for(int i=0;i<=n-1;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    ShiftArray(arr,n);
    
    cout<<"After Shifting the Array: ";
	for(int i=0;i<=n-1;i++){
		cout<<arr[i]<<" ";
    }
}

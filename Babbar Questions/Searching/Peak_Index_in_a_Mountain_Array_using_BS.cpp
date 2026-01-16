#include<iostream>
using namespace std;

int PeakIndex(int arr[], int n){
	int low = 0;
	int high = n-1;
	while(low<high){
		int mid = (low+(high-low)/2);
		if(arr[mid] < arr[mid+1]){
			low = mid+1;
		}
		else{    // mid[i] > mid[i+1]
			high = mid;
		}
	}
	return low;   // You can return high as well as at this point both will be same
}

int main(){
	int n;
	cout<<"Enter array size: ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter Array Elements: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int peak = PeakIndex(arr,n);
	cout<<"Peak index in the Mountain array is: "<<peak<<endl;
	cout<<"Peak Element in the Mountain array is: "<<arr[peak]<<endl;
}

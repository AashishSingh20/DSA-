#include<iostream>
using namespace std;

int getPivot(int arr[], int n){   // Gives minimum element
	int low = 0;
	int high = n-1;
	
	while(low<high){
		int mid = low+(high-low)/2;
		if(arr[mid] >= arr[high]){   // Agar mid element 1st element se chota hai to low ko mid+1 kardo
			low = mid+1;
		}
		else{           // Agar mid element 1st element se bada hai to high ko mid par lado.
			high = mid;
		}	 
	}
	return low;
}

int BinarySearch(int arr[], int low, int high, int target){
	int mid = low+(high-low)/2;
	
	while(low <= high){
		if(arr[mid] == target){
			return mid;
		}
		else if(arr[mid] < target){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
		mid = low+(high-low)/2;
	}
	return -1;
}

int findPosition(int arr[], int n, int target){
	
	int pivot = getPivot(arr, n);	
	if(target >= arr[pivot] && target <= arr[n-1]){
		return BinarySearch(arr, pivot, n-1, target);
	}
	else{
		return BinarySearch(arr, 0, pivot-1, target);
	}
}

int main(){
	int size;
	int target;
	cout<<"Enter array size: ";
	cin>>size;
	int arr[size];
	cout<<"\nEnter Array Elements: ";
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	cout<<"\nEnter Element you want to find: ";
	cin>>target;
	
	int Find = findPosition(arr,size,target);
	cout<<"The index of the Target element is: "<<Find<<endl;
}

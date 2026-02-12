#include<iostream>
using namespace std;

int PivotElement(int arr[], int n){    // It returns the Minimum element in the Array
	int low = 0;
	int high = n-1;
	
	while(low<high){
		int mid = low+(high-low)/2;
		if(arr[mid] >= arr[high]){    // Yeh check karega ki mid element 1st element se chhota hai ki nahi agar mid 1st element se bada ya barabar hai toh low ko mid+1 par lado
			low = mid+1;
		}
		else{
			high = mid;
		}
	}
	return low;
}

int main(){
	int A[] = {5,8,10,1,2,3};
	int n = (sizeof(A)/sizeof(A[0]));
	int pivot = PivotElement(A,n);
	
	cout<<"The Pivot Index in the Array is: "<<pivot<<endl;
	cout<<"The Pivot Element in the Array is: "<<A[pivot]<<endl;
}

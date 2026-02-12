#include<iostream>
using namespace std;

int LastOcc(int arr[], int n, int key){
	int low = 0;
	int high = n-1;
	int ans = 0;
	int mid = (low+(high-low)/2);
	
	while(low<=high){
		if(arr[mid]== key){
			ans = mid;
			low = mid+1;
		}
		else if(arr[mid] < key){  // Right mein jao
			low = mid+1; 
		}
		else{               // mid > key    // Left mein jao
			high = mid-1;
		}
		mid = (low+(high-low)/2);
	}
	return ans;
}

int main(){
	int A[] = {1,2,3,4,4,4,5};
	
	int First = LastOcc(A,7,4);
	cout<<"Last Occurence of 4 is: "<<First<<endl;
}

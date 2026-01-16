#include<iostream>
using namespace std;

int FirstOcc(int arr[], int n, int key){
	int low = 0;
	int high = n-1;
	int ans = -1;
	int mid = (low+(high-low)/2);
	
	while(low<=high){
		if(arr[mid]	== key){
			ans = mid;
			high = mid-1;
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
	
	int First = FirstOcc(A,7,4);
	int Last = LastOcc(A,7,4);
	pair<int, int> p(First,Last);  // use pair<int,int> p = {First,Last} in newer compiler. 
	cout<<"First and Last Occurrence of 4 is: "<<p.first<<" "<<p.second<<endl;
}

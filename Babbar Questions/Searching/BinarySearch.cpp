#include<iostream>
using namespace std;

struct Array{
	int A[10];
	int size;
	int length;
};

void display(struct Array arr){
	cout<<"Elements in the array are: ";
	for(int i=0;i<arr.length;i++){
		cout<<arr.A[i]<<" ";
	}
}

int BinarySearch(struct Array arr,int key){   //Using loops
	int l = 0;
	int h = arr.length-1;
	
	while(l<=h){
	int mid = (l+(h-l)/2);  // This will prevent array out of bounds condition.
		if(key==arr.A[mid]){
			return mid;
		}
		else if(key<arr.A[mid]){
			h = mid-1;
		}
		else{
			l = mid+1;
		}
	}	
		return -1;
}

//int RBinSearch(int a[],int l,int h,int key){     // Using Recursion
//	int mid;
//	if(l<=h){
//		mid = (l+h)/2;
//		if(key == a[mid]){
//		return mid;
//		}
//		else if(key<a[mid]){
//			return RBinSearch(a,l,mid-1,key);
//		}
//		else{
//			return RBinSearch(a,mid+1,h,key);
//		}
//	}
//	return -1;
//}

int main(){
	struct Array arr = {{2,4,5,6,7,9,11,12},10,8};
	cout<<endl;
	display(arr);
	cout<<endl;
    cout<<"Element is found at index: "<<BinarySearch(arr,6)<<endl;
//    cout<<"Element is found at index: "<<RBinSearch(arr.A,0,arr.length,11)<<endl;
}

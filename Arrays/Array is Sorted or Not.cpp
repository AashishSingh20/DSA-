#include<iostream>
using namespace std;

struct Array{
	int A[10];
	int size;
	int length;
};

void display(struct Array arr){
	cout<<"Array: ";
	for(int i=0;i<arr.length;i++){
		cout<<arr.A[i]<<" ";
	}
}

int isSorted(struct Array arr){
	bool flag = true;
	for(int i=0;i<arr.length-1;i++){
		if(arr.A[i]>arr.A[i+1]){
			return 0;
		}
	}return 1;
}

int main(){
	int x;
	struct Array arr = {{2,4,6,8,10,12},10,6};
	display(arr);
	cout<<endl;
	bool flag = isSorted(arr);
	
	if(flag){
		cout<<"Array is Sorted.";
	}
	else{
		cout<<"Array is not Sorted.";
	}
}

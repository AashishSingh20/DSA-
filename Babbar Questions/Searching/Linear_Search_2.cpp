#include<iostream>
using namespace std;

struct Array{
	int A[10];
	int size;
	int length;
};

void display(struct Array arr){
	cout<<"Elements are: ";
	for(int i=0;i<arr.length;i++){
		cout<<arr.A[i]<<" ";
	}
}

//int LinearSearch(struct Array arr, int key){      // Normal Method
//	for(int i=0;i<arr.length;i++){
//		if(arr.A[i] == key)
//		  return i;
//	}
//	return -1;
//}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

//int LinearSearch(struct Array *arr,int key){     // Transposition Method 
//	for(int i=0;i<arr->length;i++){
//		if(arr->A[i] == key){
//			swap(&arr->A[i],&arr->A[i-1]);
//			return i-1;
//		}
//	}
//		return 1;
//}

int LinearSearch(struct Array *arr,int key){     // Move to Front/Head
	for(int i=0;i<arr->length;i++){
		if(arr->A[i] == key){
			swap(&arr->A[i],&arr->A[0]);
			return i-1;
		}
	}
		return 1;
}

int main(){
	struct Array arr = {{2,4,5,6,7},10,5};
	cout<<endl;
//	cout<<"Element is found at index: "<<LinearSearch(arr,4)<<endl;   // 1st method
    cout<<"Element is found at index: "<<LinearSearch(&arr,5)<<endl;  // 2nd method  //3rd Method
	display(arr);
}

#include<iostream>
using namespace std;

struct Array{
	int A[10];
	int size;
	int length;
};

void display(struct Array arr){
	for(int i=0;i<arr.length;i++){
		cout<<arr.A[i]<<" ";
	}
}

//void Reverse(struct Array *arr){               // Method 1(Using Extra/Auxillary Array)
//	
//	int* B = new int[arr->length];     // Allocates Dynamic Array
//	
//	for(int i=arr->length-1,j=0;i>=0;i--,j++){
//		B[j] = arr->A[i];             // Copies Array A in B in reverse Order
//	}
//	for(int i=0;i<arr->length;i++){
//		arr->A[i] = B[i];             // Copies Reverse Elements of B in A
//	}
//	delete[] B;                       // Free Allocated memory in B
//}

void Reverse2(struct Array *arr){              // Method 2(using Swap)
	for(int i=0,j=arr->length-1;i<j;i++,j--){
		int temp = arr->A[i];
		arr->A[i] = arr->A[j];
		arr->A[j] = temp;
	}
}

int main(){
	struct Array arr = {{2,3,4,5,6,7},10,6};
	cout<<"Elements in the array are: "; 
	display(arr);
	cout<<endl;
//	Reverse(&arr);
	Reverse2(&arr);
	
	cout<<"Reversed Array: ";
	display(arr);
	
	return 0;
	
}

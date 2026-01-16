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

int Get(struct Array arr, int index){
	if(index >= 0 && index<arr.length){
		return arr.A[index];
	}
	return -1;
}

void Set(struct Array *arr, int index, int x){
	if(index >= 0 && index < arr->length){
		arr->A[index] = x;
	}
}

int Max(struct Array arr){
	int max = arr.A[0];
	for(int i=1;i<arr.length;i++){
		if(arr.A[i]>max){
			max = arr.A[i];
		}
	} return max;
}

int Min(struct Array arr){
	int min = arr.A[0];
	for(int i=1;i<arr.length;i++){
		if(arr.A[i]<min){
			min = arr.A[i];
		}
	} return min;
}

int Sum(struct Array arr){
	int sum = 0;
	for(int i=0;i<arr.length;i++){
		sum += arr.A[i];
	}
	return sum;
}

float Avg(struct Array arr){
	return (float)Sum(arr)/arr.length;
}


int main(){
	struct Array arr = {{2,3,4,5,6,7},10,6};
	display(arr);
	cout<<endl;
	
	cout<<"Element at index 2 is: "<<Get(arr,2)<<endl;
	Set(&arr,0,1);
	cout<<"Element at index 0 is changed to: "<<Get(arr,0)<<endl;
	display(arr);
	cout<<endl;
	
	cout<<"Maximum Element in the Array is: "<<Max(arr)<<endl;
	cout<<"Minimum Element in the Array is: "<<Min(arr)<<endl;
	
	cout<<"Sum of all elements in the array is: "<<Sum(arr)<<endl;
	cout<<"Average of all element in the array is: "<<Avg(arr);
}

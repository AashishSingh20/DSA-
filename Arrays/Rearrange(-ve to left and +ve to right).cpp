#include<iostream>
using namespace std;

struct Array{
	int A[10];
	int size;
	int length;
};

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void display(struct Array arr){
	cout<<"Array: ";
	for(int i=0;i<arr.length;i++){
		cout<<arr.A[i]<<" ";
	}
}

void Rearrange(struct Array *arr){
	int i = 0;
	int j = arr->length-1;
	
	while(i<j){
		while(arr->A[i]<0){
			i++;
		}
		while(arr->A[j]>=0){
			j--;
		}
		if(i<j){
			swap(&arr->A[i],&arr->A[j]);
		}
	}
}

int main(){
	int x;
	struct Array arr = {{9,-5,-4,8,-8,12},10,6};
	display(arr);
	cout<<endl;
	Rearrange(&arr);
	cout<<"Rearranged ";
	display(arr);
}

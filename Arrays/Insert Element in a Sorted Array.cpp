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
void InsertElement(struct Array *arr, int x){
	int i = arr->length-1;
	if(arr->length == arr->size){
		return;
	}
	
	else{
	while(i>=0 && arr->A[i]>x){
		arr->A[i+1] = arr->A[i];
		i--;
	}
	arr->A[i+1] = x;
	arr->length++;
	}
}

int main(){
	int x;
	struct Array arr = {{2,4,6,8,10,12},10,6};
	display(arr);
	cout<<endl;
	InsertElement(&arr,7);
	cout<<"After inserting element: "<<endl;
	display(arr);
}
	

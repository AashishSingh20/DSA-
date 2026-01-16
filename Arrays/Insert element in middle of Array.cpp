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

void Insert(struct Array *arr, int index, int x){
	if(index>=0 && index<=arr->length){	
		for(int i=arr->length;i>index;i--){
			arr->A[i]=arr->A[i-1];
		}
			arr->A[index]=x;
			arr->length++;
	}
}	
	
int main(){
	struct Array arr = {{2,4,5,6,7},10,5};
	Insert(&arr,3,10);
	display(arr);
}

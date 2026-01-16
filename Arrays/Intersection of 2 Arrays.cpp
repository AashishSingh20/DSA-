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

struct Array* IntersectionArray(struct Array *arr1, struct Array *arr2){
	int i,j,k;
	i=j=k = 0;
	Array* arr3 = new Array;
	
	while(i<arr1->length && j<arr2->length){
		if(arr1->A[i]<arr2->A[j]){
			i++;
		}
		else if(arr1->A[i] == arr2->A[j]){
			arr3->A[k] = arr1->A[i];
			i++;
			j++;
			k++;
	    }
	    else{
			j++;
		}
	}
	arr3->length = k;
	
	return arr3;
}

int main(){
	struct Array arr1 ={{2,4,6,10,14},10,5};
	struct Array arr2 = {{1,2,5,14,15},10,5};
	struct Array *arr3;
	
	display(arr1);
	cout<<endl;
	display(arr2);
	cout<<endl;
	
	arr3 = IntersectionArray(&arr1,&arr2);
	cout<<"Intersection of ";
	display(*arr3);
	
	delete arr3;
	return 0;
}

#include<iostream>
using namespace std;

class Array{
	private:
		int *A;
		int size;
		int length;
	
	public:
		Array(int sz){
			size = sz;
			length = 0;
			A = new int[size];
		}
		
		~Array(){
			delete []A;
		}
		
		void Fill(int data[],int n){
			n = length;
			for(int i=0;i<n;i++){
				A[i] = data[i];
			}
		}
		
		void Display();
		void PivotIndex(int arr[]);
};

void Array::Display(){
	cout<<"Array: ";
	for(int i=0;i<arr.length;i++){
		cout<<arr.A[i]<<" ";
	}
	cout<<endl;
}

void Array::PivotIndex(int arr[]){
	int mid = 0;
	for(int i=0;i<length;i++){
		sumRight += A[n-i];
		if(sumLeft[] == sumRight[]){
			return A[i];
		}
		else if()
	}
}

int main(){
	Array arr(10);
	int data[] = {1,7,3,6,5,6};
	n = sizeof(data)/sizeof(data[0]);
	
	arr.Fill(data,n);
	arr.Display();
	cout<<"Pivot Element is: ";
}

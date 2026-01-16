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
			length = n;
			for(int i=0;i<n;i++){
				A[i] = data[i];
			}
		}
		
		void Display();
		void Duplicate_in_Sorted();
};

void Array::Display(){
	cout<<"Array: ";
	for(int i=0;i<length;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

void Array::Duplicate_in_Sorted(){
	int lastDuplicate = -1;     // Array mein iske hone ke chances kam hai
	cout<<"Duplicate Elements: ";
	int count = 0;
	for(int i=0;i<length-1;i++){
		if(A[i] == A[i+1] && A[i] != lastDuplicate){
			cout<<A[i]<<" ";
		lastDuplicate = A[i];
		count++;
		}
	}
	cout<<endl;
	cout<<"Number of Duplicate Elements: "<<count;
}

int main(){
	Array arr(10);
	int data[] = {3,4,4,5,6,6,7,8,8};
	int n = sizeof(data)/sizeof(data[0]);
	arr.Fill(data,n);
	arr.Display();
	arr.Duplicate_in_Sorted();
	
}

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
		
		Array(int data[], int n){   // Constructor used to initialize 
			size = n;
			length = n;
			A = new int[size];
			for(int i = 0;i<n;i++){
				A[i] = data[i];
			}
		}
		
		~Array(){
			delete []A;
		}	
		
		void Fill(int data[], int n){
			length = n;
			if(n > size){
				n = size;
			}
			for(int i=0;i<n;i++){
				A[i] = data[i];
			}
		}
		
		void Display();
		Array* MergeSort(Array &other);  // other creates a copy of the array as reference
};

void Array::Display(){
	cout<<"Array: "<<endl;
	for(int i=0;i<length;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

Array* Array::MergeSort(Array &other){
			int i = 0, j = 0,k = 0;
			Array* result = new Array(size + other.size);
			
			while(i<length && j<other.length){
				if(A[i]<other.A[j]){
					result->A[k] = A[i];
					i++;
					k++;
				}
				else{
					result->A[k] = other.A[j];
					k++;
					j++;
				}
			}
			
			for(;i<length;i++){
				result->A[k] = A[i];
				k++;
			}
			for(;j<other.length;j++){
				result->A[k] = other.A[j];
				k++;
				}
			result->length = length+other.length;
			
			return result;
}

int main() {
	int data1[5], data2[5];
	
	cout<<"Enter 5 elements into Array 1: ";
	for(int i=0;i<5;i++){
		cin>>data1[i];
	}
	
	cout<<"Enter 5 elements into Array 2: ";
	for(int i=0;i<5;i++){
		cin>>data2[i];
	}

    Array arr1(data1, 5);
    Array arr2(data2, 5);

    arr1.Display();
    arr2.Display();
    
    Array* arr3 = arr1.MergeSort(arr2);

    cout << "Merged ";
    arr3->Display();
    delete arr3;
}

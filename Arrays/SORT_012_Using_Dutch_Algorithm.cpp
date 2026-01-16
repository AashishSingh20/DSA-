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
		void Sort012(int arr[]);
};

void Array::Display(){
	cout<<"Array: ";
	for(int i=0;i<length;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

void Array::Sort012(int arr[]){
	int low=0;
	int mid=0;
	int high=length-1;
	
	while(mid<=high){
		if(A[mid]==0){
			swap(A[mid],A[low]);
			low++;
			mid++;
		}
		else if(A[mid]==1){
			mid++;
		}
		else{
			swap(A[mid],A[high]);
			high--;
		}
	}
}

int main(){
	Array arr(10);
	int data[] = {1,2,0,1,0,2,1,2,0};
	int n = sizeof(data)/sizeof(data[0]);
	arr.Fill(data,n);
	arr.Display();
	
	arr.Sort012(data);
	arr.Display();
}

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
		
		void Fill(int data[], int n){
			length = n;
			for(int i=0;i<n;i++){
				A[i] = data[i];
			}
		}
		
		void Display();
		void FindMultipleMissing();
};

void Array::Display(){
	cout<<"Array: ";
	for(int i=0;i<length;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

void Array::FindMultipleMissing(){
	int diff = A[0]-0;
	cout<<"Missing Elements are: ";
	for(int i=0;i<length;i++){
		if(A[i]-i!=diff){
			while(diff<A[i]-i){
				cout<<+i+diff<<" ";
			diff++;
			}
		}
	}
	cout<<endl;
}

int main(){
	Array arr(10);
	int data[] = {3,4,6,7,9,10,12,13};
	int n = sizeof(data)/sizeof(data[0]);
	arr.Fill(data,n);
	arr.Display();
	arr.FindMultipleMissing();
	
}

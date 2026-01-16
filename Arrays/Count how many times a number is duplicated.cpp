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
		void Count_ocurrence_of_Duplicates();
};

void Array::Display(){
	cout<<"Array: ";
	for(int i=0;i<length;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

void Array::Count_ocurrence_of_Duplicates(){
	int j = 0;
	for(int i=0;i<length-1;i++){
		if(A[i] == A[i+1]){
			j = i+1;
		while(j<length && A[j]==A[i]){
			j++;
		}
		cout<<A[i]<<" is appearing "<<j-i<<" times"<<endl;
		i = j-1;
	  }
	}
}

int main(){
	Array arr(20);
	int data[] = {3,4,4,4,4,5,6,6,6,7,7,7,7,7,8};
	int n = sizeof(data)/sizeof(data[0]);
	arr.Fill(data,n);
	arr.Display();
	arr.Count_ocurrence_of_Duplicates();
	
}

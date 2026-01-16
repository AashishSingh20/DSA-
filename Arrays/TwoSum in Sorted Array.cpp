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
		int  TwoSumSorted(int arr[],int target);
};

void Array::Display(){
	cout<<"Array: ";
	for(int i=0;i<length;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

int Array::TwoSumSorted(int arr[], int target){
	int i = 0;
	int j = length-1;
	
	while(i<j){
		if(A[i]+A[j]==target){
			cout<<"Index at which it equals to target: "<<i<<" "<<j<<endl;
			i++;
			j--;
		}
		else if(A[i]+A[j]<target){
			i++;
		}
		else{
			j--;
		}
	}
	return -1;
}

int main(){
	Array arr(10);
	int data[] = {2,7,11,15};
	int target = 9;
	int n = sizeof(data)/sizeof(data[0]);
	
	arr.Fill(data,n);
	arr.Display();
	arr.TwoSumSorted(data,target);
}

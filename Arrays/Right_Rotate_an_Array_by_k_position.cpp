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
		void LeftrotateArray(int arr[],int i,int j);
};

void Array::Display(){
	cout<<"Array: ";
	for(int i=0;i<length;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

void Array::LeftrotateArray(int arr[],int i,int j){
	while(i<j){
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
		i++;
		j--;
	}
}

int main(){
	Array arr(10);
	int data[] = {1,2,3,4,5,6};
	int n = sizeof(data)/sizeof(data[0]);
	
	arr.Fill(data,n);
	arr.Display();
	int k;
	cout<<"Enter value of k: ";
	cin>>k;
	k = k%n;
	arr.LeftrotateArray(data,0,n-1);
	arr.Display();
	arr.LeftrotateArray(data,0,k-1);
	arr.Display();
	arr.LeftrotateArray(data,k,n-1);	
	arr.Display();
}



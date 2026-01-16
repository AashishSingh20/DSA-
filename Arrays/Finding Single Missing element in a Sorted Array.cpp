#include<iostream>
using namespace std;

class Array{
	private:
		int *A;
		int size;
		int length;
	
	public:
//		Array(){               // Iska kaam nahi hai yaha kyuki mein parametirized contructor use kiya hai
//			size = 10;
//			A = new int[10];
//			length = 0;
//		}
		
		Array(int sz){
			size = sz;
			length = 0;
			A = new int[size];
		}
		
		~Array(){
			delete []A;
		}
		
		void Fill(int data[], int n) {
        length = n;
        for (int i = 0; i < n; i++) {
            A[i] = data[i];
        }
    }
		
		void Display();
		void FindMissingElement();
		void FindMissingElement2();
};

void Array::Display(){
	cout<<"Array: ";
	for(int i=0;i<length;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

//void Array::FindMissingElement(){   // This method works on if the number start from 1
//	int n = length+1;
//	int sum = 0;
//	for(int i=0;i<length;i++){
//		sum += A[i];
//	}
//	int s = n*(n+1)/2;
//	cout<<"Missing Element is:"<<s-sum<<endl;
//}

void Array::FindMissingElement2(){
	
	for(int i=0;i<length;i++){
	int diff = A[0]-0;
		if(A[i]-i!=diff){
			cout<<"Here the missing Element is: "<<i+diff<<endl;
			break;
		}
	}
}

int main(){
	Array arr(10);
//	int data[] = {1,2,3,5,6,7};
	int data1[] = {10,12,13,15,16,17};
	int n = sizeof(data1)/sizeof(data1[0]);
//	arr.Fill(data,n);
	arr.Fill(data1,n);
	arr.Display();
//	arr.FindMissingElement();
	arr.FindMissingElement2();
}

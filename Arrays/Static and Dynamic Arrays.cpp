#include<iostream>
using namespace std;

int main(){
	int A[5] = {3,5,1,8,2};
	int *p;   // Pointer is used to create an array in Heap
	
	p = new int[5];   // Creates array in heap
	p[0] = 5;
    p[1] = 7;
    p[2] = 6;
    p[3] = 1;
    p[4] = 0;
	
	for(int i=0;i<5;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	
	for(int i=0;i<5;i++){
		cout<<p[i]<<" ";
	}
	delete []p; 
}

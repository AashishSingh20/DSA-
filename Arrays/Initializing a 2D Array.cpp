#include<iostream>
using namespace std;

int main(){
	//Initialize a 2D Array(Matrix)
	int A[3][4] = {{1,2,3,4},{2,4,6,8},{1,3,5,7}};  // Method 1 (No element in Heap
	int *B[3];   // Method 2  // Elements are partially in heap
	
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	B[0] = new int[4];
	B[1] = new int[4];
	B[2] = new int[4];
	
	int **C = new int*[3];  // Method 3  (All elements in Heap)
	C[0] = new int[4];
	C[1] = new int[4];
	C[2] = new int[4];
	
}

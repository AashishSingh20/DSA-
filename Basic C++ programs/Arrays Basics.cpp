#include<iostream>
using namespace std;

int main(){
	int A[5];
	A[0]=14;
	A[1]=24;
	A[2]=87;
	// You can use int[A]={14,24,87,1,56] as well where A[0]=14, A[1]=24, etc.
	//If you write A[] without declaring the size then the size will be equal to the number of elements present in the array.	
	cout<<sizeof(A)<<endl;// To get size of the array= size of array x 4(4 bit for each element)
	cout<<A[1];
	
	return 0;
}




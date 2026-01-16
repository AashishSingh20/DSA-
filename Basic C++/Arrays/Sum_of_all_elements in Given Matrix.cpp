#include<iostream>
using namespace std;

int main(){
	int m,n;
	int sum = 0;
	cout<<"Enter number of rows in Matrix: ";
	cin>>m;
	cout<<"Enter number of columns in Matrix: ";
	cin>>n;
	int arr[m][n];
	cout<<"Enter Elements of Matrix: ";
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		cin>>arr[i][j];
		}	 
	}
	cout<<endl;
	
	for(int i=0;i<m;i++){
	    for(int j=0;j<n;j++){
	        sum+= arr[i][j];
		}	 
	}
	cout<<"Sum of all elements in the matrix is: "<<sum;
}

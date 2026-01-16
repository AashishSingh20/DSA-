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
	cout<<"Enter Elements of Matrix: "<<endl;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		cin>>arr[i][j];
		}	 
	}
	cout<<endl;
	
	int a1,a2,b1,b2;
	cout<<"Enter first co-ordinates: ";
	cin>>a1>>a2;
	cout<<"Enter second co-ordinates: ";
	cin>>b1>>b2;		
	
	for(int i=a1;i<=b1;i++){
	    for(int j=a2;j<=b2;j++){
	        sum+= arr[i][j];
		}	 
	}
	cout<<"Sum of selected elements in the matrix in rectangle form is: "<<sum;
}	

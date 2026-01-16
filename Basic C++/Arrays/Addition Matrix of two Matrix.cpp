#include<iostream>
using namespace std;

int main(){
	int m,n;
	cout<<"Enter number of rows in Matrix: ";
	cin>>m;
	cout<<"Enter number of columns in Matrix: ";
	cin>>n;
	int a[m][n];
	int b[m][n];
	int c[m][n];
	cout<<"Enter Elements of Matrix A: ";
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		cin>>a[i][j];
		}	 
	}
	cout<<endl;
	
	cout<<"Enter Elements of Matrix B: ";
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		cin>>b[i][j];
		}
	}
	cout<<endl;	
	
	cout<<"Addition Matrix of both Matrices: "<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			c[i][j] = a[i][j] + b[i][j];
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
}

#include<iostream>
using namespace std;

/* Eg.  3 
        3 2
        3 2 1      */
    
int main(){
	int m,n;
	cout<<"Number of Rows: ";
	cin>>m;

// METHOD 1
//
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=i;j++){ 
//			cout<<(m+1)-j<<" ";
//		}
//	cout<<endl;
//	}

// METHOD 2

	for(int i=1;i<=m;i++){
		for(int j=m;j>=m-i+1;j--){ 
			cout<<j<<" ";
		}
	cout<<endl;
	}	
}

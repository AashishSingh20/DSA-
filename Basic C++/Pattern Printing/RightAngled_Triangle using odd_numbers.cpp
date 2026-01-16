#include<iostream>
using namespace std;

/* Eg.  1 
        1 3
        1 3 5      */
    
int main(){
	int m,n;
	cout<<"Number of Rows: ";
	cin>>m;
	
// METHOD 1
//
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=i;j++){
//			cout<<2*j-1<<" ";
//		}
//	cout<<endl;
//	}

// METHOD 2

//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=2*i-1;j+=2){
//			cout<<j<<" ";
//		}
//	cout<<endl;
//	}

//METHOD 3
	for(int i=1;i<=m;i++){
		int a = 1;
		for(int j=1;j<=i;j++){
			cout<<a<<" ";
			a+=2;
		}
	cout<<endl;
	}
}

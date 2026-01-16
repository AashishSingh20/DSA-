#include<iostream>
using namespace std;

/* Eg.  1 
        2 3
        4 5 6      */  // Floyd's Triangle
    
int main(){
	int m,n;
	cout<<"Number of Rows: ";
	cin>>m;
	
	int a = 1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){ 
			cout<<a<<" ";
			a+=1;
		}
	cout<<endl;
	}	
}	

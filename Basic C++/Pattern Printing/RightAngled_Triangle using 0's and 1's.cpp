#include<iostream>
using namespace std;

/* Eg.  1 
        0 1
        1 0 1
		0 1 0 1      */  
    
int main(){
	int m,n;
	cout<<"Number of Rows: ";
	cin>>m;

	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){ 
		if((i+j)%2==0){
			cout<<"1"<<" ";
		  }
		else{
			cout<<"0"<<" ";
		  }	
		}
	cout<<endl;
	}	
}	

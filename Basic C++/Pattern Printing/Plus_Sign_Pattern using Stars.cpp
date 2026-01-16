#include<iostream>
using namespace std;
    
/* Eg.    *
          *
      * * * * * 
		  *     
		  *    */
		    
int main(){
	int m,n;
	cout<<"Number of Rows: ";
	cin>>m;
    int mid = (m/2)+1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){ 
		if(i==mid || j==mid){
			cout<<"*"<<" ";
		  }
		else{
			cout<<"  ";
		  }	
		}
	cout<<endl;
	}	
}	

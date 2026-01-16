#include<iostream>
using namespace std;
    
/* Eg.   * * * * * *
         *         *
         *         *
         * * * * * *
                       */
		    
int main(){
	int m,n;
	cout<<"Number of Rows: ";
	cin>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m+2;j++){ 
		if((i==1 || i==m) || (j==1 || j==m+2)){
			cout<<"*"<<" ";
		  }
		else{
			cout<<"  ";
		  }	
		}
	cout<<endl;
	}	
}	

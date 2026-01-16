#include<iostream>
using namespace std;

/*  A B C D
    A B C D
    A B C D  */
    
int main(){
	int m,n;
	cout<<"Number of Rows: ";
	cin>>m;
	cout<<"Number of Columns: ";
	cin>>n;
	
	for(int i=1;i<=m;i++){ // loop for rows 
		for(int j=1;j<=n;j++){  // loop for columns
			cout<<(char)(j+64)<<" ";
		}
	cout<<endl;
	}
}

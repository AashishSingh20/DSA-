#include<iostream>
using namespace std;

/* Eg.  1 2 3 4
        1 2 3 4
        1 2 3 4 */
    
int main(){
	int m,n;
	cout<<"Number of Rows: ";
	cin>>m;
	cout<<"Number of Columns: ";
	cin>>n;
	
	for(int i=1;i<=m;i++){ // loop for rows 
		for(int j=1;j<=n;j++){  // loop for columns
			cout<<j<<" ";
		}
	cout<<endl;
	}
}

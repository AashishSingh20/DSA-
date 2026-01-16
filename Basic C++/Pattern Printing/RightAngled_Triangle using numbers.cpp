#include<iostream>
using namespace std;

/*  1
    1 2
    1 2 3  */
    
int main(){
	int m,n;
	cout<<"Number of Rows: ";
	cin>>m;

	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){ 
			cout<<j<<" ";
		}
	cout<<endl;
	}
}

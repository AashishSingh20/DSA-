#include<iostream>
using namespace std;

/*  A
    A B
    A B C  */
    
int main(){
	int m,n;
	cout<<"Number of Rows: ";
	cin>>m;

	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){ 
			cout<<(char)(j+64)<<" ";
		}
	cout<<endl;
	}
}

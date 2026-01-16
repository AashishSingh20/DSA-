#include<iostream>
using namespace std;

/*     1
     1 2 3
   1 2 3 4 5   */
    
int main(){
	int m;
	cout<<"Number of Rows: ";
	cin>>m;

	for(int i=1;i<=m;i++){
		for(int j=1;j<=m-i;j++){ 
		cout<<"  ";
		}
		
		for(int j=1;j<=2*i-1;j++){ 
			cout<<j<<" ";
		}
	cout<<endl;
	}
}

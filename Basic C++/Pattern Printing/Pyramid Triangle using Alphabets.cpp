#include<iostream>
using namespace std;

/*     A
     A B C
   A B C D E   */
    
int main(){
	int m;
	cout<<"Number of Rows: ";
	cin>>m;

	for(int i=1;i<=m;i++){
		for(int j=1;j<=m-i;j++){ 
		cout<<"  ";
		}
		
		for(int j=1;j<=2*i-1;j++){ 
			cout<<(char)(j+64)<<" ";
		}
	cout<<endl;
	}
}

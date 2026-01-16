#include<iostream>
using namespace std;

int main(){
	int arr[2][3] = {{2,8,6},{7,9,2}};
	
	int mx = INT_MIN;
	cout<<"Matrix: "<<endl;
	
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			mx = max(mx,arr[i][j]);
		}
	}
	cout<<"Maximum element in the Matrix is: "<<mx;
}

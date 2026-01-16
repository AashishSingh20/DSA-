#include<iostream>
using namespace std;

int main(){
	int arr[2][3];
	cout<<"Enter array elements: ";
	
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
		cin>>arr[i][j];
		}
	}
	cout<<endl;
	
	cout<<"Transpose 2D Array: "<<endl;
	for(int j=0;j<3;j++){
		for(int i=0;i<2;i++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

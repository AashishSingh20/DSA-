#include<iostream>
using namespace std;

int main(){
	int arr[4][2];
	cout<<"Enter Roll No & Marks: ";
	
	for(int i=0;i<4;i++){
		for(int j=0;j<2;j++){
		cin>>arr[i][j];
		}
	}
	cout<<endl;	
	cout<<"Roll No: "<<" Marks: "<<endl;
	for(int i=0;i<4;i++){
		cout<<"  ";
		for(int j=0;j<2;j++){
			cout<<arr[i][j]<<"        ";
		}
		cout<<endl;
	}
}

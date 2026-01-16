#include<iostream>
using namespace std;

void change(int arr[]){  // Arrays always pass by reference
	arr[0]  = 3;   
}
int main(){
	int arr[] = {4,6,9};
	for(int i=0;i<=2;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	change(arr);
	for(int i=0;i<=2;i++){
		cout<<arr[i]<<" ";
	}
}

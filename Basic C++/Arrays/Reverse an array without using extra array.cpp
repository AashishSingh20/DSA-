#include<iostream>
using namespace std;

int main(){
	int arr[] = {12,44,23,2,4,5,2,45,53};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	int j = n-1;
	
	cout<<"Original Array: ";
	for(int i=0;i<=n-1;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;

	while(i<j){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
	
	cout<<"Reverse of the Array: ";
	for(int i=0;i<=n-1;i++){
		cout<<arr[i]<<" ";
    }
}

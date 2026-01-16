#include<iostream>
using namespace std;

int main(){
	int arr[] = {3,5,6,2,1};
	int product = 1;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Array: ";
	for(int i=0;i<=n-1;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;
    
	for(int i=0;i<=4;i++){
		product *= arr[i];
	}
	cout<<"Product of all elements in the array is: "<<product;
}

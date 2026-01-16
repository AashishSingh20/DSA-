#include<iostream>
using namespace std;

int main(){
	int arr[] = {3,5,6,2,1};
	int sum = 0;
	int n = sizeof(arr)/4; // Used to find the length of the array
	cout<<"Array: ";
	for(int i=0;i<=n;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;
    
	for(int i=0;i<=4;i++){
		sum += arr[i];
	}
	cout<<"Sum of all elements in the array is: "<<sum;
}

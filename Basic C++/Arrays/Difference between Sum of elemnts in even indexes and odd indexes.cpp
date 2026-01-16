#include<iostream>
using namespace std;

int main(){
	int arr[] = {3,8,6,2,1,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sumeven = 0;
	int sumodd = 0;
	cout<<"Array: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;
    
	for(int i=0;i<n;i+=2){
		sumeven += arr[i];
	}
	cout<<"Sum of all elements in even Index is: "<<sumeven<<endl;
	
	for(int i=1;i<n;i+=2){
		sumodd += arr[i];
	}
	cout<<"Sum of all elements in odd Index is: "<<sumodd<<endl;
	
	cout<<"Difference between the sum of Elements at even and odd index is: "<<sumeven-sumodd;
}
	

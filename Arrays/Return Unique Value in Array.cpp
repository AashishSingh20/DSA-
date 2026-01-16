#include<iostream>
using namespace std;

void originalArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int UniqueElement(int arr[],int n){   //Only works when there is only one unique element and other elements occur 2 times
	int num = 0;
	for(int i=0;i<n;i++){
		num = num^arr[i];  // XOR is used as it gives true if either one of the conditions is true
	}
	return num;
}

int main(){
	int n;
	cout<<"Enter the number of elements:";
	cin>>n;
	int arr[n];
	
	cout<<"Enter Array Elements:";
	for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
    
    int unique = UniqueElement(arr,n);
    cout<<"Unique Element in the Array is:"<<unique<<endl;
}

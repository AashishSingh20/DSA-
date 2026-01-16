#include<iostream>
using namespace std;

void originalArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swapAlternate(int arr[],int n){
	for(int i=0;i<n;i+=2){
		if(i+1<n){
			swap(arr[i],arr[i+1]);
		}
	}
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int odd[] = {2,4,6,7,1};
    int even[] = {3,5,1,8,5,6};
    int m = sizeof(odd)/sizeof(odd[0]);
    int n = sizeof(even)/sizeof(even[0]);
    
    cout<<"Array 1: ";
    originalArray(odd,m);
    cout<<"Array 2: ";
    originalArray(even,n);
    
    swapAlternate(odd,m);
    swapAlternate(even,n);
    
    cout<<"Reverse of array 1: ";
    printArray(odd,m);
    cout<<"Reverse of array 2: ";
    printArray(even,n);
}

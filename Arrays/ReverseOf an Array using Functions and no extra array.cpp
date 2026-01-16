#include<iostream>
using namespace std;

void originalArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverseArray(int arr[],int n){
    int start = 0;
    int end = n-1;
    
    while(start<=end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {2,4,6,7,1};
    int brr[] = {3,5,1,8,5,6};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = sizeof(brr)/sizeof(brr[0]);
    
    cout<<"Array 1: ";
    originalArray(arr,m);
    cout<<"Array 2: ";
    originalArray(brr,n);
    
    reverseArray(arr,m);
    reverseArray(brr,n);
    
    cout<<"Reverse of array 1: ";
    printArray(arr,m);
    cout<<"Reverse of array 2: ";
    printArray(brr,n);
}

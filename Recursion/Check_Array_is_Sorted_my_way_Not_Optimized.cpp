#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){
    if(n<=1){
        return 1;
    }

    if(arr[n-1]<arr[n-2]){
            return 0;
    }
    return isSorted(arr,n-1);
}

int main(){
    int n;
    cout<<"Enter Array size: ";
    cin>>n;
    int *arr = new int[n];

    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(isSorted(arr, n)){
        cout<<"Array is Sorted";
    }
    else{
        cout<<"Array is Unsorted";
    }

    delete[]arr;
}
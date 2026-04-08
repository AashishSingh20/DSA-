#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){
    if(n<=1){
        return 1;   // If Array is of 0 size or if there is only one element in the array then naturally it is sorted
    }

    if(arr[0] > arr[1]){  // If First Element is Smaller than second the return false
        return false;
    }
    else{
        bool remaningPart =  isSorted(arr+1,n-1);  // Now check for remaining part (now it will check arr[1] and arr[2]  and size of array is reduced)
        return remaningPart;
    }
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
#include<iostream>
using namespace std;

int sortArray(int *arr, int n){

    if(n==0 || n==1){
        return *arr;
    }
    
    for(int i=0;i<n-1;i++){   // Solves 1 case  - Largest element ko last mein pohacha dega 
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    return sortArray(arr,n-1);

}

int main(){
    int n;
    cout<<"Enter Array size: ";
    cin>>n;
    int *arr = new int[n];  // Creating Array Dynamically

    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sortArray(arr, n);
    
    cout<<"Sorted Elements: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
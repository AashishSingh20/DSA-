#include<iostream>
using namespace std;

bool linearSearch(int *arr, int n, int key){

    if(n==0){
        return false;  // This checks ki array complete traverse ho gaya hai ki nahi 
    }

    if(arr[0] == key){  // If element in Array is equal to key then return true
        return true;
    }
    else{
        return linearSearch(arr+1,n-1,key);  // If both conditions are false then increase arr pointer(arr[0] -> arr[1] decrease size of array then check)
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

    int key;
    cout<<"Enter Key: ";
    cin>>key;

    if(linearSearch(arr,n,key)){
        cout<<"Key is in the Array";
    }
    else{
        cout<<"Element is not in the Array";
    }
}
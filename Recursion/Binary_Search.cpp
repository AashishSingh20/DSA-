#include<iostream>
using namespace std;

bool binarySearch(int *arr, int s, int e, int key){
    if(s>e){
        return 0;   // If start becomes greater than e and key is not found then return false
    }

    int mid = s+(e-s)/2;  // Calculate mid

    if(arr[mid]==key){   // If element is found
        return 1;
    }
    else{
        if(arr[mid]<key){
            return binarySearch(arr,mid+1,e,key);  // increment of start by mid+1
        }
        else{
            return binarySearch(arr,s,mid-1,key); // decrement of end by mid-1
        }
    }
}

int main(){
    int n;
    cout<<"Enter Array size: ";
    cin>>n;
    int *arr = new int[n];

    cout<<"Enter Sorted Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter Element you want to find: ";
    cin>>key;

    int start = 0;
    int end = n-1;

    if(binarySearch(arr,start,end,key)){
        cout<<"Element is Present";
    }
    else{
        cout<<"Element is Absent";
    }
}
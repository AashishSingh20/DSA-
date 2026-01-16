#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){

// Diving and copying of main array into further arrays START!! 
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;   // This is the length of 1st array out of 2
    int len2 = e-mid;    // This the the length of 2nd array out of 2

    int *first = new int[len1];   // Here 1st array is created
    int *second = new int[len2];  // Here 2nd array is created

    int k=s;    // Keeps track ki kitne elements konse array mein copy karna hai(k = main Array Index)
    for(int i=0;i<len1;i++){
        first[i] = arr[k++];   // Elements from arr are being copied into first array till mid
    }

    k=mid+1;   // Now k becomes mid+1 as elements till mid are copied into first
    for(int i=0;i<len2;i++){
        second[i] = arr[k++];   // Elements from arr are being copied into second array from mid+1 till last
    }
// Dividing and copying DONE!


// Creating 2 sorted Arrays by Merging  START!
    int index1 = 0;
    int index2 = 0;
    k = s;

    while(index1 < len1 && index2 < len2){   // Loop First Array until len1 and Second Array until len2
        if(first[index1] < second[index2]){  // If element of 1st Array is smaller than element of 2nd Array then put first array's element in the merged sorted Array
            arr[k++] = first[index1++];  
        }
        else{    // If element of 2nd Array is smaller than element of 1st Array then put second array's element in the merged sorted Array
            arr[k++] = second[index2++];
        }
    }

    while(index1 < len1){   // Put left out elements of 1st array in arr
        arr[k++] = first[index1++];
    }
    while(index2 < len2){  // Put left out elements of 2nd array in arr
        arr[k++] = second[index2++];
    }

    delete[]first;   // Free Memory
    delete[]second;  
}

void mergeSort(int *arr, int s, int e){
    if(s>=e){
        return;
    }

    int mid = s+(e-s)/2;

    mergeSort(arr,s,mid);  // Left part sort karega
    mergeSort(arr,mid+1,e);  // Right part sort karega

    merge(arr,s,e);   // Yeh Array ko divide karke naya sorted Array banaega
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
    
    mergeSort(arr,0,n-1);
    
    cout<<"Sorted Elements: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    delete[]arr;
}
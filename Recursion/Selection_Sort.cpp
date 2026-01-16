#include<iostream>
using namespace std;

void sortArray(int *arr, int n){
    
    if(n==0 || n==1){   
        return;
    }

    int maxIndex = 0;   // This is used to find the maximum element
    
    for(int j=1;j<n;j++){     // This is used to find maximum element in first n elements
        if(arr[j]>arr[maxIndex]){  // (Eg:- 6 5 4 3 2 1   here arr[j]= arr[1] = 5, arr[maxIndex] = 6,   5 is not greater than 6 so maxInde remains same then swap is carried out)
            maxIndex = j;   // If there comes a number which is greater than maxIndex element then 
        }
    }
    
    swap(arr[maxIndex],arr[n-1]);    // Swaps Maximum element with the last element 
    sortArray(arr,n-1);   // Recursive Call // Since the last element is sorted check the second max element and then place it in it's correct position
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
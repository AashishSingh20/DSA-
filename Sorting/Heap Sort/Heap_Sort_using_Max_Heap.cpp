#include<iostream>
#include<vector>
using namespace std;

void maxHeapify(vector<int>& arr, int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n,largest);
    }
}

void heapSort(vector<int>& arr, int n){
    int size = n;

    while(size > 1){
        // Step 1:- Swap last Element with 1st Element
        swap(arr[size],arr[1]);
        // Step 2:- Decrement Size
        size--;
        // Step 3:- call Heapify
        maxHeapify(arr,size,1);
    }
}

int main(){
    int n;
    cout<<"Enter Size of Vector: ";
    cin>>n;

    cout<<"Enter Array Elements: ";
    vector<int> arr;
    arr.push_back(-1); // Dummy Element for 1 based Indexing
    for(int i=1;i<=n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }

    // Building Max Heap    
    for(int i=n/2;i>0;i--){
        maxHeapify(arr,n,i);
    }

    heapSort(arr,n);
    cout<<"Printing Sorted Array: ";
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
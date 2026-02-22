#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    // Agar left n se chhota hai and
    // Largest element in the current heap is smaller than it's left child
    // Update Largest
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    // If largest Update ho gaya then
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

int main(){
    int size;
    cout<<"Enter size of Array: ";
    cin>>size;
    int arr[size + 1];

    cout<<"Enter Array Elements: ";
    for(int i=1;i<=size;i++){
        cin>>arr[i];
    }

    for(int i=size/2;i>0;i--){
        heapify(arr,size,i);
    }

    cout<<"Max Heapified Array: ";
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
}
#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int smallest = i;
    int left = 2*i;
    int right = 2*i+1;

    // Agar left n se bada hai and
    // Smallest element in the current heap is larger than it's left child
    // Update smallest
    if(left <= n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right <= n && arr[smallest] > arr[right]){
        smallest = right;
    }

    // If smallest Update ho gaya then
    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr,n,smallest);
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

    cout<<"Min Heapified Array: ";
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
}
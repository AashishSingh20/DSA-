#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size;

    Heap(){
        // Initially Array mein -1 ki value daldo
        arr[0] = -1;
        size = 0;
    }
    
// Insertion
    void insert(int val){
        // Size ko increase kardo kyuki naya element aaya hai
        size = size + 1;
        // index ko last mein set kardo
        int index = size;
        // last mein element ko put kardo
        arr[index] = val;

        while(index > 1){
            // Parent is always at i/2 from the node to be inserted
            int parent = index/2;
            // If parent ka element is smaller than new element 
            // Swap
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

// Deletion
// Not Valid For all Condition
    void deleteFromHeap(){
        if (size == 0){
            cout<<"Heap is Empty!";
            return;
        }
        
        //Step 1:- Last element ki value ko root element mein copy karlo
        arr[1] = arr[size];
        // Step 2:- Remove Last Element
        size--;

        //Step 3:- Take root Node to it's correct Position
        int i = 1;
        while(i <= size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex <= size && arr[i] < arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex <= size && arr[i] < arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }
};

int main(){
    Heap h;
    int n;
    cout<<"How many elements in the Heap: ";
    cin>>n;

    cout<<"Enter Elements into the Heap: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        h.insert(val);
    }
    h.print();

    cout<<"After Deletion: ";
    // This deletes the root element from the heap
    h.deleteFromHeap();
    h.print();
}
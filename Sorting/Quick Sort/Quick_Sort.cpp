#include<iostream>
using namespace std;

int partition(int *arr, int s, int e){
    int pivot = arr[s];  // 1st element ko ham pivot man lete hai

    int count = 0;  // Counts how many numbers are smaller than pivot
    for(int i=s+1;i<=e;i++){  // Loop from s+1 to e
        if(arr[i] < pivot){  // If element is smaller than pivot then increment the count
            count++; 
        }
    }

    int pivotIndex = s + count;    // New Index of pivot after placing it at correct position
    swap(arr[s],arr[pivotIndex]);   // Placing pivot at its correct position by swapping

    int i = s;   // Starting index to traverse left side of the pivot
    int j = e;   // Starting index to traverse right side of the pivot

    while(i < pivotIndex && j > pivotIndex){   // Loop until i reaches pivotIndex and j reaches pivotIndex
        while(arr[i] < pivot){   // increment i until element at i is smaller than pivot
            i++;
        }
        while(arr[j] > pivot){  // decrement j until element at j is greater than pivot
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){  // If i and j have not crossed pivotIndex than swap the elements at i and j if they are out of place
            swap(arr[i++],arr[j--]);    // Agar elements apni jagah pe nahi hai to swap kar do
        }
    }

    return pivotIndex;
}

void quickSort(int *arr, int s, int e){
    
    if(s >= e){
        return;
    }

    int p = partition(arr,s,e);  // Partition Karenge

    quickSort(arr,s,p-1);  // Left wala part sort karo  
    quickSort(arr,p+1,e);  // Right wala part sort karo
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
    
    quickSort(arr,0,n-1);
    
    cout<<"Sorted Elements: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    delete[]arr;
}
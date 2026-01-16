#include<iostream>
using namespace std;

void sortArray(int *arr, int n){
    if(n==0 || n==1){  // Array ka size har call mei kam ho raha hai kyuki har call mein array ka start/end sort hote jata hai
        return;   // If Array is reached then return 
    }

    sortArray(arr,n-1);   // Recursive Call
    int temp = arr[n-1];   // Temp mein last element ko daldo(Eg: 6 5 4 3 2 1 ,  1st put 1 in temp)
    int j = n-2;   // j mein (Eg: 6 5 4 3 2 1,  put 4 in j)

    while(j>=0){  // In 1st call j is 4 
        arr[j+1] = arr[j];  // Check if arr[4+1] > arr[4] or not (Here 2>1 so )
        j--;
    }
    
    arr[j+1] = temp;
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
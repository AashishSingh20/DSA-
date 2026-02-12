#include<iostream>
#include<vector>
using namespace std;

int main(){
    int length,ele;     // Here we declare length of array and the elements we are going to put in it.
    cout<<"Enter the length of array: "; 
    cin>>length;
    vector <int> arr;
    cout<<"Enter elements of the array: ";
    for(int i=0;i<length;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    for(int i=0;i<length-1;i++){
        int minIndex = i;       // Initially we consider the minimum element to be the 1st element

        for(int j=i+1;j<length;j++){   
            if(arr[j] < arr[minIndex]){     // If element at minIndex is greater than element at j then update minIndex
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);   // Swap minIndex with 1st element
    }

    cout<<"Sorted Array array is: ";
    for(int k = 0;k<length;k++){    // We cannot print vector directly so we use for loop
        cout<<arr[k]<<" ";
    }
    cout<<endl;
}
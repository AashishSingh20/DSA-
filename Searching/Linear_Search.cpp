#include <iostream>
using namespace std;

int search(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(key == arr[i]){
            return true;
        }
        return false;
    }
}

int main() {
    int arr[] = {4,6,2,9,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    
    cout<<"Enter the element you want to search: ";
    cin>>key;
    
    bool flag = search(arr,n,key);
    
    if(flag == true){
        cout<<"Element is in the array";
    }
    else{
        cout<<"Element is not in the array";
    }
}

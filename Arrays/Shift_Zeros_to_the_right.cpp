// Don't change the pre-defined order of other elements in the array only shift all 0's to the right

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,ele;
    cout<<"Enter number of Elements in Array: ";
    cin>>n;

    vector<int> arr;
    cout<<"Enter Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    int nonZero=0;   // It keeps track of nonZero elements
    for(int j=0;j<n;j++){
        if(arr[j]!=0){   // If j is non Zero then swap nonzero element with element at j
            swap(arr[nonZero], arr[j]);
            nonZero++;   // If nonZero element is found then increase variable count
        }
    }
        
    for(int k=0;k<n;k++){   // Print elements in array
        cout<<arr[k]<<" ";
    }
    cout<<endl;      
}
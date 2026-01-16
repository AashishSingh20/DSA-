// This checks if the Array is sorted and rotated
// Eg :- 3 4 5 1 2 is sorted and rotated,  1 1 1 is sorted and rotated
// 2 1 3 4  is not even sorted and not rotated as well 

#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int>& arr,int n){
    int count = 0;

    for(int i=1;i<n;i++){
        if(arr[i-1] > arr[i]){  // if previous element is greater than the current one then it is rotated pair
            count++;            // There is only one or 0 rotated pairs in a rotated sorted array 
        }
    }
    if(arr[n-1] > arr[0]){   // if last element is greater than first then it increases the count
        count++;
    }
    return count<=1;   // array is sorted and rotated if and only if the count is <= 1
}

int main(){
    int n,ele;

    cout<<"Enter number of Elements in Array: ";
    cin>>n;

    cout<<"Enter Array Elements: ";
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    if(check(arr,n)){
        cout<<"Array is Sorted and rotated";
    }else{
        cout<<"Array is not sorted and rotated";
    }
}
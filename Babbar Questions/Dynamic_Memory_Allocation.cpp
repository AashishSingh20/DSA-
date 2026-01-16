#include<iostream>
using namespace std;

int getSum(int *arr, int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    // char ch = 'a';
    // cout<<sizeof(ch)<<endl;  // Will be 1 as there is only one character

    // char*c = &ch;
    // cout<<sizeof(c)<<endl;  // Will be 4 as pointer size is 4 in 32-bit system

    // // Total size of charcter including it's pointer here is 5 and in 64-bit system it is 9

    // new int[5];
    // int *arr = new int[5];
    // // Here pointer arr is stored in stack and new int[5] is stored in heap 

    int n;
    cout<<"Enter Array Size: ";
    cin>>n;

    int *arr = new int[n];

    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];    // arr[i] == *(arr + i)  so no need to write in this pointer form
    }

    int ans = getSum(arr, n);
    cout<<"Sum of Array: "<<ans<<endl;

    delete[]arr;
}
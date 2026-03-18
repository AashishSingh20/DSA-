#include<bits/stdc++.h>
using namespace std;

// recursion
int solve(vector<int> &arr, int n){
    // Base Case
    if(n < 0){
        return 0;
    }
    
    if(n==0){  // Ek hi element hai toh sum mein sirf wohi hoga
        return arr[0];
    }

    int include = solve(arr,n-2) + arr[n];  // Agar curr element ko include kiya toh 2 pehle jaane padega
    int exclude = solve(arr,n-1) + 0;  // Agar exclude kiya hai toh uske pehle wale par jao 

    return max(include,exclude);
}

int main(){
    int n;
    cout<<"Enter number of Elements: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int maxSum = solve(arr,n);
    cout<<"Maximum Sum of Non Adjacent Elements is: "<<maxSum<<endl;
}
#include<bits/stdc++.h>
using namespace std;

// Recursion + Memoization
int solveMem(vector<int> &arr, int n, vector<int> &dp){
    // Base Case
    if(n < 0){
        return 0;
    }
    
    if(n==0){  // Ek hi element hai toh sum mein sirf wohi hoga
        return arr[0];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int include = solveMem(arr,n-2,dp) + arr[n];
    int exclude = solveMem(arr,n-1,dp) + 0;

    dp[n] = max(include,exclude);
    return dp[n];
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

    vector<int> dp(n,-1);
    int maxSum = solveMem(arr,n-1,dp);
    cout<<"Maximum Sum of Non Adjacent Elements is: "<<maxSum<<endl;
}
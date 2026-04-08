#include<bits/stdc++.h>
using namespace std;

bool solveMem(vector<int> &arr, int i, int target){
    
    vector<vector<int>> dp(n,vector<int>(target+1,INT_MAX));
    // Base Case
    dp[0][target] = true;
    
    if(i == 0){  // Agar last element hai then check ki woh target ke barabar hai agar nahi then this condition will return false
        return arr[0] == target;
    }
    
    if(dp[i][target] != -1){  
        return dp[i][target];
    }
    
    
    bool include = false;
    if(arr[i] <= target){   // Agar curr element target se chhota yaa barabar hai then include
        include = solveMem(arr, i-1, target - arr[i], dp);   // target mein se curr element ki value subtract kardo and index ko change kardo
    }
    
    bool exclude = solveMem(arr, i-1, target, dp);  // Agar excluding current element then sirf index ko aage badhado
    
    dp[i][target] = include || exclude;  // (F || F = F)
    return dp[i][target];
}

int main(){
    
    int n;
    cout<<"Enter Array Size: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int sum;
    cout<<"Enter Target Sum Value";

    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    return solveMem(arr,n-1,sum,dp);
}
#include<bits/stdc++.h>
using namespace std;

int solveMem(vector<int> &arr, int key, vector<int> &dp){
    // Base Case
    if(key < 0){  // Agar key 0 se kam ho jaye matlab combination ka sum key se bada ho gaya hai 
        return 0;
    }

    if(key == 0){  // Agar key == 0 means combination is correct so return 1 as count
        return 1;
    }

    if(dp[key] != -1){
        return dp[key];
    }

    int ans = 0;
    for(int i=0;i<arr.size();i++){
        ans += solveMem(arr, key - arr[i], dp);
    }

    dp[key] = 0;
    return dp[key];
    
}   

int main(){
    int n;
    cout<<"Enter Size of Array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter Key: ";
    cin>>key;

    vector<int> dp(key+1,-1);
    int count = solveMem(arr,key,dp);
    cout<<"Number of Ways to get Target Value is: "<<count<<endl;
}
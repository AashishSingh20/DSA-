#include<bits/stdc++.h>
using namespace std;

// Using Recursion + Memoization
int solve(vector<int> &coins, int target, vector<int> &dp){
    if(target == 0){
        return 0;
    }

    if(target < 0){
        return INT_MAX;
    }

    if(dp[target] != -1){
        return dp[target];
    }

    int mini = INT_MAX;
    for(int i=0;i<coins.size();i++){
        int ans = solve(coins,target-coins[i],dp);
        if(ans != INT_MAX){
            mini = min(mini,1+ans);
        }
    }

    dp[target] = mini;
    return dp[target];
}

int solveTab(vector<int> &coins, int target, vector<int> &dp){
}

int main(){ 
    vector<int> coins = {1,2}; 

    int target;
    cout<<"Enter Target Value: ";
    cin>>target;

    vector<int> dp(target+1,-1);
    int ans = solve(coins,target,dp);
    if(ans == INT_MAX){
        cout<<"There exists no denomination whose sum is equal to target."<<endl;
        return -1;
    }
    else{
        cout<<"Minimum Number of coins required to reach Target: "<<ans<<endl;
        return 0;
    }
}
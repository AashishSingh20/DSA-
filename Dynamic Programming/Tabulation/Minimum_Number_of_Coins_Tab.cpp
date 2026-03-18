#include<bits/stdc++.h>
using namespace std;

// Using Tabulation
// Finding min/max coins required
int solveTab(vector<int> &coins, int target){
    // step 1: Create DP vector,Initialize it and set 0th index of DP to 0
    vector<int> dp(target+1,INT_MAX);
    dp[0] = 0;

    // Step 2
    for(int i=1;i<=target;i++){  // Computes the minimum no of coins to reach target
        // I am trying to solve for every amount figure from 1 to target
        for(int j=0;j<coins.size();j++){  // Try every coin to see it can contribute to reach target
            if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){  // Check ki dp[i] valid index hai and kahi woh unreachable toh nahi
                dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
            }
        }
    }

    return dp[target];
}

// Finding Total possible Ways to reach target
int solveTab2(vector<int> &coins, int target){
    // step 1
    vector<int> dp(target+1,0);
    dp[0] = 1;

    for(auto &coin : coins){
        for(int i=1;i<=target;i++){
            dp[i] += dp[i - coin];
        }
    }
    return dp[target];
}

int main(){ 
    vector<int> coins = {1,2,3}; 

    int target;
    cout<<"Enter Target Value: ";
    cin>>target;

    int ans = solveTab(coins,target);
    if(ans == INT_MAX){
        cout<<"There exists no denomination whose sum is equal to target."<<endl;
        return -1;
    }
    else{
        cout<<"Minimum Number of coins required to reach Target: "<<ans<<endl;
        return 0;
    }
}
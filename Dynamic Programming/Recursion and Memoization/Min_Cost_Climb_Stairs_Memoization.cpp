#include<iostream>
#include<vector>
using namespace std;

int minCost(vector<int> &cost, int n, vector<int> &dp){
    // Base Case's
    if(n==0){  // I coming from 1st Stair
        return cost[0];
    }
    if(n == 1){  // If coming from 2nd Stair
        return cost[1];
    }

    // Step 3: Base case
    if(dp[n] != -1){  // Agar nth index par pehle se ans stored hai toh return stored ans(Phir calculate nahi karna padega)
        return dp[n];
    }

    // Step 2: Fill dp array
    dp[n] = cost[n] + min(minCost(cost,n-1,dp),minCost(cost,n-2,dp));  // min cost at every step ko dp mein store karte raho
    return dp[n];   // final node of dp mein most minimum cost store hoga

}

int main(){

    int n;
    cout<<"Enter number of Stairs: ";
    cin>>n;

    vector<int> cost(n);
    cout<<"Enter cost of each Stair: ";
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    cout<<endl;
    
    // Step 1:
    vector<int> dp(n+1,-1);
    int ans = min(minCost(cost,n-1,dp),minCost(cost,n-2,dp));
    cout<<"Minimum cost to climb all chairs is: "<<ans<<endl;
}
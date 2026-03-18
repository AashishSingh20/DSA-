#include<iostream>
#include<vector>
using namespace std;

int minCost(vector<int> &cost, int n){
    // Step 1: Creation of dp 1D Array
    vector<int> dp(n,-1);
    // Both these are base cases coonverted into this
    dp[0] = cost[0];  // dp at index 0 mein cost of 0 store karlo
    dp[1] = cost[1];  // dp at index 1 mein cost of 1 store karlo 

    // Step 2:
    for(int i=2;i<n;i++){
        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }

    // Step 3:
    return min(dp[n-1],dp[n-2]);  
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
    
    // 1 100 1 1 1 100 1 1 100 1
    int ans = minCost(cost,n);
    cout<<"Minimum cost to climb all chairs is: "<<ans<<endl;
}
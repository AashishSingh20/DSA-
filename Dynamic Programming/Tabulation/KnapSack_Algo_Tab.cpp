#include<bits/stdc++.h>
using namespace std;

int solveTab(vector<int> &wt, vector<int> &val, int n, int capacity){

    // Step 1:
    vector<vector<int>> dp(n,vector<int>(capacity+1,-1));

    // Analyse Base Case
    for(int w = wt[0];w<=capacity;w++){  // Start loop from weight at 0th index till capacity
        if(wt[0] <= capacity){  // Agar weight of 0th index is <= capacity update index dp[0][w] in dp
            dp[0][w] = val[0];
        }
        else{
            dp[0][w] = 0;  // Else  dp[0][w] mein 0 daldo
        }
    }

    // Step 2: Handle Other Cases
    for(int idx=1; idx<n; idx++){
        for(int w=0;w<=capacity;w++){
            int include = 0;

            if(wt[idx] <= w){
                include = val[idx] + dp[idx-1][w - wt[idx]];
            }

            int exclude = 0 + dp[idx-1][w];

            dp[idx][w] = max(exclude,include);
        }
    }
    
    return dp[n-1][capacity];
}

int main(){
    int n;
    cout<<"Enter Number of Items: ";
    cin>>n;

    int w;
    cout<<"Enter the weight which can be filled in knapsack: ";
    cin>>w;

    vector<int> wt(n);
    cout<<"Enter Weight of all Items: ";
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }

    vector<int> val(n);
    cout<<"Enter Value of all Items: ";
    for(int i=0;i<n;i++){
        cin>>val[i];
    }

    int ans = solveTab(wt,val,n,w);
    cout<<"Maximum Value of Items the thief can put in Knapsack is: "<<ans<<endl;
}
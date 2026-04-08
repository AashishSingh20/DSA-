#include<bits/stdc++.h>
using namespace std;

int solveMem(int n, vector<int> &dp){
    // Base Case
    if(n == 0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int ans = n;    // Answer maximum n hi ho sakta hai agar hamne 1^2 se banaya toh
    for(int i=1;i*i<=n;i++){  // i ko 1 se start karo and i^2 hamesha n se chhota hona chahiye
        ans = min(ans, 1+solveMem(n-i*i,dp));  
    }

    dp[n] = ans;
    return dp[n];
}   

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    vector<int> dp(n+1,-1);
    int minSquares = solveMem(n,dp);
    cout<<"Minimum Number of Perfect squares required to sum til n is: "<<minSquares<<endl;
}
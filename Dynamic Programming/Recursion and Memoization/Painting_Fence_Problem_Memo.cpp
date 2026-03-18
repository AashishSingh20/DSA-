#include<bits/stdc++.h>
using namespace std;

int solveMem(int n, int k,vector<int> &dp){
    // Base Case
    if(n==1){  // Agar ek hi poll hai toh use jitna paint hai utne tarikese paint kar sakte hai
        return k;
    }

    if(n==2){
        return k+k*(k-1);
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = (solveMem(n-2,k,dp)*(k-1)) + (solveMem(n-1,k,dp)*(k-1));
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter Number of Posts: ";
    cin>>n;

    int k;
    cout<<"Enter Number of colours: ";
    cin>>k;

    vector<int> dp(n+1,0);
    int ways = solveMem(n,k,dp);
    cout<<"Number of Ways to Paint the Fence is: "<<ways<<endl;
}
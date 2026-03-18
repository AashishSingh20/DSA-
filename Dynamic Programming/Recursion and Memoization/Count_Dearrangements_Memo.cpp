#include<bits/stdc++.h>
using namespace std;

int solveMem(int n,vector<int> &dp){
    // Base Case
    if(n==1){  // Ek hi Elements hai, woh dearranged nahi hota
        return 0;
    }

    if(n==2){  // 2 elements ki sirf 1 dearrangement possibility hai
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = (n-1)*(solveMem(n-1,dp) + solveMem(n-2,dp));
    
    return dp[n];
}

int main(){
    int n;
    cout<<"Number of Balls: ";
    cin>>n;

    vector<int> dp(n+1,-1);
    int Dearrangements = solveMem(n,dp);
    cout<<"Total number of ways balls can be DeArraged is: "<<Dearrangements<<endl;

    
}
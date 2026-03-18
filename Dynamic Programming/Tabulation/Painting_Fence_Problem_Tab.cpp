#include<bits/stdc++.h>
using namespace std;

int solveTab(int n, int k){

    vector<int> dp(n+1,0);
    dp[1] = k;
    dp[2] = k+k*(k-1);

    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-2]*(k-1)) + (dp[i-1]*(k-1));
    }

    return dp[n];
}

int main(){
    int n;
    cout<<"Enter Number of Posts: ";
    cin>>n;

    int k;
    cout<<"Enter Number of colours: ";
    cin>>k;

    int ways = solveTab(n,k);
    cout<<"Number of Ways to Paint the Fence is: "<<ways<<endl;
}
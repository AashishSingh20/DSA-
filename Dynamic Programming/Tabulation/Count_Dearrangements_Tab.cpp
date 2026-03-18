#include<bits/stdc++.h>
using namespace std;

int solveTab(int n){

    vector<int> dp(n+1,-1);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3;i<=n;i++){
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]); 
    }

    return dp[n];
}

int main(){
    int n;
    cout<<"Number of Balls: ";
    cin>>n;

    int Dearrangements = solveTab(n);
    cout<<"Total number of ways balls can be DeArraged is: "<<Dearrangements<<endl;

}
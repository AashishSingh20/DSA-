#include<iostream>
#include<vector>
using namespace std;

// Using Recursion + Memoization
int fib(int n, vector<int> &dp){
    // Base Case
    if(n <= 1){
        return n;
    }

    // Step 3
    if(dp[n] != -1){
        return dp[n];
    }

    // Step 2
    dp[n] = fib(n-1,dp) + fib(n-2,dp);
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter the index of Fibonacci Number: ";
    cin>>n;

    // Step 1
    vector<int> dp(n+1); 
    for(int i=0;i<=n;i++){
        dp[i] = -1;
    }

    cout<<"Fibonacci Element at nth index is: "<<fib(n,dp)<<endl;
}
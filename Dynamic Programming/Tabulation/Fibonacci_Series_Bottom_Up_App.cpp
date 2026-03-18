#include<iostream>
#include<vector>
using namespace std;


// Using Tabulation
int main(){
    int n;
    cout<<"Enter the index of Fibonacci Number: ";
    cin>>n;

    // Step 1
    vector<int> dp(n+1); 

    // Step 2
    dp[0] = 0;
    dp[1] = 1;

    // Step 3
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout<<"Fibonacci Element at nth index is: "<<dp[n]<<endl;
}
#include<bits/stdc++.h>
using namespace std;

int solveTab(int n){

    vector<int> dp(n+1,INT_MAX);

    // Base Case
    dp[0] = 0;  

    int ans = n;    // Answer maximum n hi ho sakta hai agar hamne 1^2 se banaya toh
    for(int i=1;i<=n;i++){  // i ko 1 se start karo and i^2 hamesha n se chhota hona chahiye
        for(int j=1;j*j<=n;j++){
            int temp = j*j;
            if(i - temp >= 0){
                dp[i] = min(dp[i], 1 + dp[i-temp]); 
            }
        }
    }

    return dp[n];
}   

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int minSquares = solveTab(n);
    cout<<"Minimum Number of Perfect squares required to sum til n is: "<<minSquares<<endl;
}
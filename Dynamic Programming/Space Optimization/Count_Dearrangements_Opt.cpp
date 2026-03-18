#include<bits/stdc++.h>
using namespace std;

int solve(int n){

    int prev1 = 0; // dp[n-1] or dp[0]
    int prev2 = 1; // dp[n-2] or dp[1] 

    for(int i=3;i<=n;i++){
        int curr = (i-1) * (prev1 + prev2);
        
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

int main(){
    int n;
    cout<<"Number of Balls: ";
    cin>>n;

    int Dearrangements = solve(n);
    cout<<"Total number of ways balls can be DeArraged is: "<<Dearrangements<<endl;

}
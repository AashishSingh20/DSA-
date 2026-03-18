#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k){

    if(n==1){   // Only one post
        return k;
    }

    int prev1 = k;          // dp[1]
    int prev2 = k+k*(k-1);  // dp[2]

    for(int i=3;i<=n;i++){
        int curr = (prev1*(k-1)) + (prev2*(k-1));

        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

int main(){
    int n;
    cout<<"Enter Number of Posts: ";
    cin>>n;

    int k;
    cout<<"Enter Number of colours: ";
    cin>>k;

    int ways = solve(n,k);
    cout<<"Number of Ways to Paint the Post is: "<<ways<<endl;
}
#include<bits/stdc++.h>
using namespace std;

int solveMem(int n, int x, int y, int z,vector<int> &dp){
    // Base Case
    if(n==0){  // Rod ki length hi 0 hai toh 0 segments lagenge
        return 0;
    }

    if(n < 0){
        return INT_MIN;  // Rod ki length se bada hai segment toh return INT_MIN(matlab invalid)
    }

    if(dp[n] != -1){  // dp mein answer stored hai return it
        return dp[n];
    }

    int a = solveMem(n-x,x,y,z,dp) + 1;
    int b = solveMem(n-y,x,y,z,dp) + 1;
    int c = solveMem(n-z,x,y,z,dp) + 1;

    dp[n] = max(a,max(b,c));
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter Length of Rod: ";
    cin>>n;

    int x,y,z;
    cout<<"Enter segment x,y,z: ";
    cin>>x>>y>>z;

    vector<int> dp(n+1,-1);
    int maximizeCuts = solveMem(n,x,y,z,dp);
    if(maximizeCuts >= 0){
        cout<<"Maximum no of cuts we can do in the Rod is: "<<maximizeCuts<<endl;
        return 0;
    }
    else{
        cout<<"Not Possible to cut rod in given segments.";
        return -1;
    }
}
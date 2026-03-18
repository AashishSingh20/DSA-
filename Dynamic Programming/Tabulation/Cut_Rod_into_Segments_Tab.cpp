#include<bits/stdc++.h>
using namespace std;

int solveMem(int n, int x, int y, int z){
    vector<int> dp(n+1,INT_MIN);

    // Step 1:
    dp[0] = 0;

    // Step 2:
    for(int i=1;i<=n;i++){
        if(i-x >= 0){
            dp[i] = max(dp[i],dp[i-x] + 1);  // dp ke index mein pehle joh stored tha aur ab joh stored hai unka max dp[i] mein daldo
        }

        if(i-y >= 0){
            dp[i] = max(dp[i],dp[i-y] + 1);  // dp ke index mein pehle joh stored tha aur ab joh stored hai unka max dp[i] mein daldo
        }

        if(i-z >= 0){
            dp[i] = max(dp[i],dp[i-z] + 1);  // dp ke index mein pehle joh stored tha aur ab joh stored hai unka max dp[i] mein daldo
        }
    }

    // Step 3: 
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter Length of Rod: ";
    cin>>n;

    int x,y,z;
    cout<<"Enter segment x,y,z: ";
    cin>>x>>y>>z;

    int maximizeCuts = solveMem(n,x,y,z);
    if(maximizeCuts >= 0){
        cout<<"Maximum no of cuts we can do in the Rod is: "<<maximizeCuts<<endl;
        return 0;
    }
    else{
        cout<<"Not Possible to cut rod in given segments.";
        return -1;
    }
}
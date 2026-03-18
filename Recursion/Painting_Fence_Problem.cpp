#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k){
    // Base Case
    if(n==1){  // Agar ek hi poll hai toh use jitna paint hai utne tarikese paint kar sakte hai
        return k;
    }

    if(n==2){
        return k+k*(k-1);
    }

    int ans = (solve(n-2,k)*(k-1)) + (solve(n-1,k)*(k-1));
    return ans;
}

int main(){
    int n;
    cout<<"Enter Number of Posts: ";
    cin>>n;

    int k;
    cout<<"Enter Number of colours: ";
    cin>>k;

    int ways = solve(n,k);
    cout<<"Number of Ways to Paint the Fence is: "<<ways<<endl;
}
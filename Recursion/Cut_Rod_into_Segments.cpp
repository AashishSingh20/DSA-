#include<bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z){
    // Base Case
    if(n==0){  // Rod ki length hi 0 hai toh 0 segments lagenge
        return 0;
    }

    if(n < 0){
        return INT_MIN;  // Rod ki length se bada hai segment toh return INT_MIN(matlab invalid)
    }

    int a = solve(n-x,x,y,z) + 1;
    int b = solve(n-y,x,y,z) + 1;
    int c = solve(n-z,x,y,z) + 1;

    int ans = max(a,max(b,c));
    return ans;
}

int main(){
    int n;
    cout<<"Enter Length of Rod: ";
    cin>>n;

    int x,y,z;
    cout<<"Enter segment x,y,z: ";
    cin>>x>>y>>z;

    int maximizeCuts = solve(n,x,y,z);
    if(maximizeCuts >= 0){
        cout<<"Maximum no of cuts we can do in the Rod is: "<<maximizeCuts<<endl;
        return 0;
    }
    else{
        cout<<"Not Possible to cut rod in given segments.";
        return -1;
    }
}
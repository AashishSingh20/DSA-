#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    // Base Case
    if(n==1){  // Ek hi Elements hai, woh dearranged nahi hota
        return 0;
    }

    if(n==2){  // 2 elements ki sirf 1 dearrangement possibility hai
        return 1;
    }

    int ans = (n-1)*(solve(n-1) + solve(n-2));
    
    return ans;
}

int main(){
    int n;
    cout<<"Number of Balls: ";
    cin>>n;

    int Dearrangements = solve(n);
    cout<<"Total number of ways balls can be DeArraged is: "<<Dearrangements<<endl;
}
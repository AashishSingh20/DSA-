// Here you can either climb 1 or 2 steps
// This is not the most optimized way it causes TLE so it will be solved again using DP

#include<iostream>
using namespace std;

int climbStairs(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }

    return climbStairs(n-1)+climbStairs(n-2);
}

int main(){
    int n;  // Enter number of stairs
    cout<<"Enter no of stairs: ";
    cin>>n;

    int ans = climbStairs(n);
    cout<<"Number of ways to climb "<<n<<" stairs: "<<ans;

    return 0;
}
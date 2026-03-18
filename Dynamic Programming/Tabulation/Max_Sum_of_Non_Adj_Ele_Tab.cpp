#include<bits/stdc++.h>
using namespace std;

// Tabulation
int solveTab(vector<int> &arr, int n){

    vector<int> dp(n+1,0);
    dp[0] = arr[0];  

    for(int i=1;i<n;i++){
        int include = arr[i];
        if(i > 1){
            include += dp[i-2];
        }

        int exclude = dp[i-1] + 0;

        dp[i] = max(include,exclude);
    }

    return dp[n-1];
}

int main(){
    int n;
    cout<<"Enter number of Elements: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int maxSum = solveTab(arr,n);
    cout<<"Maximum Sum of Non Adjacent Elements is: "<<maxSum<<endl;
}
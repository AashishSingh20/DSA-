#include<bits/stdc++.h>
using namespace std;

// Space Optimization
int solveTab(vector<int> &arr, int n){

    int prev1 = 0;  // dp[i-2]
    int prev2 = arr[0];  // dp[i-1]

    for(int i=1;i<n;i++){
        int include = arr[i] + prev1;
        int exclude = prev2 + 0;

        int ans = max(include,exclude);
        prev1 = prev2;
        prev2 = ans;
    }

    return prev2;
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
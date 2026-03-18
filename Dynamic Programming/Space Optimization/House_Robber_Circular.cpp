#include<bits/stdc++.h>
using namespace std;

// Space Optimization
int solveTab(vector<int> &arr, int start, int end){

    int prev1 = 0;  // dp[i-2]
    int prev2 = arr[start];  // dp[i-1]

    for(int i=start+1;i<=end;i++){
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
    cout<<"Enter number of Houses: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter money in each House: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(n==1){  // If only 1 house is there it is the only possible amount
        return arr[0];
    }

    int maxSum1 = solveTab(arr,0,n-2);  // Exclude last
    int maxSum2 = solveTab(arr,1,n-1); // Exclude First;
    int finalAns = max(maxSum1,maxSum2);

    cout<<"Maximum Amount thief can get from robbing houses is: "<<finalAns<<endl;
}
#include<bits/stdc++.h>
using namespace std;

int solveTab(vector<int> &arr, int key){

    vector<int> dp(key+1,0);

    // Base Case
    dp[0] = 1;  

    // Traversing from target 1 to key 
    for(int i=1;i<=key;i++){
        // Traversing on arr array
        for(int j=0;j<arr.size();j++){
            if(i - arr[j] >= 0){
                dp[i] += dp[i - arr[j]]; 
            }
        }
    }

    return dp[key];
}   

int main(){
    int n;
    cout<<"Enter Size of Array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter Key: ";
    cin>>key;

    int count = solveTab(arr,key);
    cout<<"Number of Ways to get Target Value is: "<<count<<endl;
}
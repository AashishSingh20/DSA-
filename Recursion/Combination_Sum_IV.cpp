#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int key){
    // Base Case
    if(key < 0){  // Agar key 0 se kam ho jaye matlab combination ka sum key se bada ho gaya hai 
        return 0;
    }

    if(key == 0){  // Agar key == 0 means combination is correct so return 1 as count
        return 1;
    }

    int ans = 0;
    for(int i=0;i<arr.size();i++){
        ans += solve(arr, key - arr[i]);
    }
    
    return ans;
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

    int count = solve(arr,key);
    cout<<"Number of Ways to get Target Value is: "<<count<<endl;
}
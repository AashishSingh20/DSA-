#include<bits/stdc++.h>
using namespace std;

int mostFreqEle(vector<int> &arr){

    unordered_map<int,int> mp;

    int maxFreq = 0;
    int maxAns = 0;

    // Create entry for all elements in the Array
    // And calculate max Frequency 
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
        maxFreq = max(maxFreq,mp[arr[i]]);
    }

    // If maxFreq equal to frequency of any element in the map then
    // Put element with max Frequency into maxAns
    for(int i=0;i<arr.size();i++){
        if(maxFreq == mp[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main(){
    int n;
    cout<<"Enter Size of Array: ";
    cin>>n;

    vector<int> arr;
    cout<<"Enter Elements in the Array: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }

    int ans = mostFreqEle(arr);
    cout<<"Number with the most frequency in the Array is: "<<ans<<endl;
}
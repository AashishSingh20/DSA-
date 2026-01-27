#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> firstNeg(const vector<int> arr, int k){
    int n = arr.size();
    vector<int> ans;
    deque<int> dq;

    // Step 1:- Process Window of k size
    for(int i=0;i<k;i++){
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }

    // Step 2:- store ans of first k size window
    if(!dq.empty()){
        ans.push_back(arr[dq.front()]);
    }
    else{
        ans.push_back(0);
    }

    // Step 3:- Process for other k window
    for(int i=k;i<n;i++){
        // Step 1:- Empty 1st element from the previous window
        if(!dq.empty() && i - dq.front() >= k){
            dq.pop_front();
        }

        // Step 2:- Add New Element into the window
        if(arr[i] < 0){
            dq.push_back(i);
        }

        // Step 3:- Store ans from this window
        if(dq.size() > 0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter no of Elements in the Array: ";
    cin>>n;

    vector<int> arr;
    cout<<"Enter Elements in the Array: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }

    int k;
    cout<<"Enter window Size: ";
    cin>>k;

    vector<int> ans = firstNeg(arr,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
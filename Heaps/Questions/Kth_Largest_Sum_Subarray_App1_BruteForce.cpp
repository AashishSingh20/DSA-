#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kthLargest(vector<int> &arr, int k, int n){
    // This vector stores Sum of All Subarrays
    vector<int> sumStore;

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    priority_queue<int> pq;
    for(int i=0;i<sumStore.size();i++){
        pq.push(sumStore[i]);
    }

    int ans = 0;
    for(int i=0;i<k;i++){
        ans = pq.top();
        pq.pop();
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter Array Size: ";
    cin>>n;

    vector<int> arr;
    cout<<"Enter Array Elements: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }

    int k;
    cout<<"Enter k: ";
    cin>>k;

    int kLargest = kthLargest(arr,k,n);
    cout<<"Sum of Kth Largest SubArray is: "<<kLargest<<endl;
}
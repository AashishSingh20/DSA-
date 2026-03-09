#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kthLargest(vector<int> &arr, int k, int n){
    // This vector stores Sum of All Subarrays
    priority_queue<int,vector<int>,greater<int>> minheap;

    // Loop to generate all subarrays and calculate their sum
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            // Calculates sum of subarrays
            sum += arr[j];
            if(minheap.size() < k){
                minheap.push(sum);
            }
            else{
                if(sum > minheap.top()){
                    minheap.pop();
                    minheap.push(sum);
                }
            }
        }
    }

    return minheap.top();
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
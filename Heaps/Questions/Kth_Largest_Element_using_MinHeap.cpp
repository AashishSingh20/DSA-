#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of Array: ";
    cin>>n;

    cout<<"Array Elements: ";
    vector<int> arr;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }

    int k;
    cout<<"Enter k: ";
    cin>>k;

    // Step 1:  Push 1st kth elements in the queue
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    // Step 2:- Process Remaining Elements in the Array
    for(int i=k;i<n;i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // Step 3:- Return the top Element it is the kth La rgest
    cout<<"Kth Smallest Element in the Array is: "<<pq.top()<<endl;
}
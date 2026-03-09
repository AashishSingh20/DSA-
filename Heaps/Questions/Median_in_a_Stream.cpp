#include<bits/stdc++.h>
using namespace std;

int signum(int a, int b){
    if(a == b) return 0;
    else if(a > b) return 1;
    else return -1;
}

void callMedian(int element, priority_queue<double> &maxheap, priority_queue<double,vector<double>,greater<double>> &minheap, double &median){

    // Using Switch Statements
    switch (signum(maxheap.size(),minheap.size()))
    {
    case 0:
            // If maxheap is empty or if element is <= top element of maxheap
            // Push element in maxheap
            if(maxheap.empty() || element <= maxheap.top()){
                maxheap.push(element);
                median = maxheap.top();
            }
            // Else push element in minheap
            else{
                minheap.push(element);
                median = minheap.top();
            }   
        break;
    
    case 1:
            // Maxheap is smaller than minheap
            // If element is <= top element of maxheap
            // push top element of maxheap into minheap to balance them
            // then pop element from maxheap and push new element into it
            if(element <= maxheap.top()){
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(element);
            }
            else{
                // Else push into minheap(no need to shift element btw both heaps as already balanced)
                minheap.push(element);
            }
            // calculate median
            median = (maxheap.top() + minheap.top()) / 2.0;

        break;

    case -1:
            // Maxheap is smaller than minheap
            // if element is > element at top of minheap
            // push top element of minheap into maxheap to balance them
            // then pop element from minheap and push new element into it
            if(element > minheap.top()){
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(element);
            }
            else{
                // Else push in maxheap
                maxheap.push(element);
            }
            // Calculate median
            median = (maxheap.top() + minheap.top()) / 2.0;
        
        break;

    default:
        break;
    }
}

vector<double> getMedian(vector<int> &arr, int n){
    vector<double> ans;

    priority_queue<double> maxheap;
    priority_queue<double,vector<double>,greater<double>> minheap;
    double median = 0;

    for(int i=0;i<n;i++){
        callMedian(arr[i],maxheap,minheap,median);
        ans.push_back(median);
    }

    return ans;
} 

int main(){
    int n;
    cout<<"Enter Size of Stream: ";
    cin>>n;

    vector<int> arr;
    cout<<"Enter Elements in the Stream: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }

    vector<double> ans = getMedian(arr,n);
    cout<<"The median of stream is: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
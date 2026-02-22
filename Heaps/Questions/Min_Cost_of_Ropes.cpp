#include<bits/stdc++.h>
using namespace std;
int minCost(vector<int>& arr) {
        int n = arr.size();
        int size = n;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);    
        }
        
        int minCost = 0;
        while(size > 1){
            int min1 = pq.top();
            pq.pop();
            
            int min2 = pq.top();
            pq.pop();
            
            minCost += min1+min2;
            pq.push(min1+min2);
            size--;
        }
        
        return minCost;
    }

int main(){
    int n;
    cout<<"Enter Vector Size: ";
    cin>>n;

    cout<<"Enter Vector Elements: ";
    vector<int> arr;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }

    int ans = minCost(arr);
    cout<<"Minimum Cost to connect all Ropes is: "<<ans<<endl;
}
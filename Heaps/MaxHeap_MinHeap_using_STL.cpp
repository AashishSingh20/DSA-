#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){

    cout<<"Using Pririty Queue: "<<endl;
    // This is a Maxheap
    priority_queue<int> pq;

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);

    for(int i=0;i<5;i++){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;

    // This is Mean Heap
    priority_queue<int,vector<int>,greater<int>> minheap;

    minheap.push(1);
    minheap.push(2);
    minheap.push(3);
    minheap.push(4);
    minheap.push(5);

    for(int i=0;i<5;i++){
        cout<<minheap.top()<<" ";
        minheap.pop();
    }
    cout<<endl;

}
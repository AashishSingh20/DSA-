#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q){
    if(q.empty()){
        return;
    }

    int num = q.front();
    q.pop();

    reverseQueue(q);
    q.push(num);
}

int main(){
    int n;
    cout<<"Enter Size of Queue: ";
    cin>>n;

    queue<int> q;
    cout<<"Enter Elements in the Queue: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        q.push(data);
    }

    reverseQueue(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
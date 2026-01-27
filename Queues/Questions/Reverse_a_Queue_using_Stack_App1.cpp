#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q){
    int n = q.size();
    stack<int> st;

    // Step 1:- Push into the Stack
    while(!q.empty()){
        int data = q.front();
        st.push(data);
        q.pop();
    }

    // Step 2:- Push into the Queue Again in the Reverse Order
    while(!st.empty()){
        int data = st.top();
        q.push(data);
        st.pop();
    }
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
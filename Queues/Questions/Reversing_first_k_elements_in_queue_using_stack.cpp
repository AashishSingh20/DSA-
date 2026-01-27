#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> reversefirstK(queue<int> q, int k){
    int n = q.size();
    stack<int> st;

    // Base Case
    if(k > n || k == 0){
        return q;
    }

    // Step 1:- Fetch elements from queue and put into stack
    for(int i=0;i<k;i++){
        int data = q.front();
        st.push(data);
        q.pop();
    }

    // Step 2:- Fetch Elements from the Stack and again put it into the queue
    while(!st.empty()){
        int data = st.top();
        q.push(data);
        st.pop();
    }

    // Step 3:- Fetch first (n-k) elements from queue and push back
    int t = q.size() - k;
    while(t != 0){
        int val = q.front();
        q.push(val);
        q.pop();
        t--;
    }
    return q;
}

int main(){
    int n;
    cout<<"Enter Number of Elements the Array: ";
    cin>>n;

    cout<<"Enter Array Elements: ";
    queue<int> q;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        q.push(data);
    }

    int k;
    cout<<"Enter Window Size: ";
    cin>>k;

    queue<int> ans = reversefirstK(q,k);
    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }
}
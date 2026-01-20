#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st, int count, int size){
    // Base Case
    if(count == size/2){
        st.pop();
        return;
    }

    int num = st.top();  // num mein top wale element ki value store karlo
    st.pop();  // aab pop ka top element

    // Recursive Call
    solve(st,count+1,size);  // Since Recursive call hai toh count ko increase kardo until(count == size/2)

    st.push(num);
}

int main(){
    stack<int> st;
    int n;
    cout<<"Give Size of Stack: ";
    cin>>n;

    cout<<"Enter data to put in Stack: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        st.push(data);
    }
    
    int count = 0;
    solve(st,count,n);

    cout<<"After deleting the Middle data: ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
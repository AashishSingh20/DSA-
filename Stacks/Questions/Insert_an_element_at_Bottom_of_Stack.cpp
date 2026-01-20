#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void solve(stack<int> &st, int x){
    // Base Case
    if(st.empty()){
        st.push(x);
        return;
    }

    int num = st.top();  // top element ki value ko num mein store karalo
    st.pop();   // ab top ke element ko pop kardo

    // Recursive call
    solve(st,x);
    st.push(num);
}

int main(){

    int n;
    cout<<"Enter how many elements to put in stack: ";
    cin>>n;

    cout<<"Enter Elements to put in Stack: ";
    stack<int> st;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        st.push(data);
    }
    
    int x;
    cout<<"Enter Element you want to enter: ";
    cin>>x;

    solve(st,x);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
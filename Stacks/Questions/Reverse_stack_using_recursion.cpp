#include<iostream>
#include<stack>
using namespace std;

void reverseStack(stack<int> &st){
    // Base Case
    if(st.empty()){
        return;
    }

    int top = st.top();
    st.pop();

    reverseStack(st);
    st.push(top);
    cout<<top<<" ";
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

    reverseStack(st);
}
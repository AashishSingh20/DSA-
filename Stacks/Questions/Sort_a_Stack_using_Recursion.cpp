#include<iostream>
#include<stack>
using namespace std;

void sortInsert(stack<int> &st, int num){
    if(st.empty() || st.top() < num){
        st.push(num);
        return;
    }

    int n = st.top();
    st.pop();

    // Recursive Call
    sortInsert(st, num);
    st.push(n);
}

void sortStack(stack<int> &st){
    // Base Case
    if(st.empty()){
        return;
    }

    int num = st.top();
    st.pop();

    sortStack(st);
    sortInsert(st,num);
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
    
    sortStack(st);  // Calls the Sort Function

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
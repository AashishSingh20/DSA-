#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void solve(stack<int> &st, int x, int place){
    // Base Case
    if(place == 0){
        st.push(x);
        return;
    }

    int num = st.top();  // top element ki value ko num mein store karalo
    st.pop();   // ab top ke element ko pop kardo

    // Recursive call
    solve(st,x,place-1);
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
    cout<<"Enter new Element you want to enter into the stack: ";
    cin>>x;

    int place;
    cout<<"Enter place where you want to enter new element: ";
    cin>>place;

    if(place < 1 || place > st.size()+1){
        cout<<"Enter a Valid Place !";
        return 0;
    }

    place  = st.size() - place + 1;

    solve(st,x,place);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
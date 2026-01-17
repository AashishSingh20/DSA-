#include<iostream>
#include<stack>
using namespace std;

int main(){

    // Creation of Stack
    stack<int> s;

    // Push Operation
    s.push(2);
    s.push(4);

    // Pop Operation
    s.pop();

    cout<<"Top Element in the Stack: "<<s.top()<<endl;
    if(s.empty()) cout<<"Stack is Empty: ";
    else  cout<<"Stack is Not Empty ";

    cout<<"Size of Stack is: "<<s.size()<<endl;
}
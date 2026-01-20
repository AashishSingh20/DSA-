#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;

    stack<char> st;

    cout<<"Reverse of the string: ";
    for(int i = 0;i<s.length();i++){
        char ch = s[i];  // char ch banao aur usmein string ke saare characters lao one by one
        st.push(ch);   // in characters ko stack mein ek ek karke push karte jao
        i++;  // i ka  increment karo
    }

    string ans = "";  // ans karke ek empty string banao
    while(!st.empty()){  // Jabtak stack 'st' is not empty till then continue looping
        char ch = st.top();  // char ch mein stack ka top character daldo
        ans.push_back(ch);  // joh ans string banayi hai usmein ye ch mein joh characters aaye hai unhe daldo
        st.pop();   // stack mein se top element ko pop kardo 
    }
}
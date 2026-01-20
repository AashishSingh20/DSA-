#include<iostream>
#include<stack>
using namespace std;

bool matches(char top, char curr){
    if(top == '(' && curr == ')' || top == '[' && curr == ']' || top == '{' && curr == '}'){
        return true;
    }
    else{
        return false;
    }
}

bool isBalanced(string s){   
    stack<char> st;
    for(int i=false;i<s.length();i++){
        char ch = s[i];
    // if opening bracket then push in the stack
    // else if closing bracket, check stack top if partner found pop & if not then return false
    
        if(ch == '(' ||  ch == '{' || ch == '['){
            st.push(ch);   // Agar opening brackets hai toh push in stack
        }
        else{
            if(!st.empty()){     // Agar stack empty nahi hai toh check 
                char top = st.top();   // Agar closing brackets hai toh 
                if(matches(top,ch)){   // Agar top wala bracket is the opposite of closing then
                    st.pop();   // pop the top element
                }
                else{
                    return false;  // If it doesn't match then return false
                }
            }
            else{
                return false;   // If stack is empty and it is pushing closing bracket, means it doesn't have it's opening bracket
            }
        }
    }
    
    if(st.empty()){
        return true;   // sab push pop hone ke baad agar stack empty hogaya means sabko apna jodi mil gaya so return true
    }
    else{
        return false;  // if stack mein kuch elements reh gaya means sabko apne partner nahi mile so return false   
    }
}

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;

    if(isBalanced(s)){
        cout<<"It is a Valid Parentheses.";
    }
    else{
        cout<<"It is an Invalid Parentheses";
    }
}
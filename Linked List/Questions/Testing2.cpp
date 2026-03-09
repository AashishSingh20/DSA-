#include<iostream>
#include<stack>
using namespace std;

bool isRedundant(string s){
    stack<char> st;
    int n = s.length();

    for(int i = 0; i < n; i++){
        char ch = s[i];

        if(ch == '('  || ch == '+'  || ch == '-'  || ch == '*'  || ch == '/'){
            st.push(ch);
        }
        else{
            if(ch == ')' ){
                bool isRedundant = true;
                while(st.top() != '('  && !st.empty()){
                    char top = st.top();
                    if(top == '+'  || top == '-'  || top == '*'  || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }

                if(isRedundant){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main(){
    string s;
    cout<<"Enter an Expression: ";
    cin>>s;

    if(isRedundant(s)){
        cout<<"Yes!, Expression is Redundant.";
    }
    else{
        cout<<"No!, Expression is not Redundant.";
    }
}
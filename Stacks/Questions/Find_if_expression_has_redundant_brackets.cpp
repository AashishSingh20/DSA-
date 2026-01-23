#include<iostream>
#include<stack>
using namespace std;

bool isRedundant(string &s){
    stack<char> st;
    int n = s.length();

    for(int i=0;i<n;i++){
        char ch = s[i];   // char ch banao joh string elements ka hisab rakhega
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){  // Agar inmein se kuch bhi hai then 
            st.push(ch);    // push into the stack
        }
        else{    // If ch == ')' || ch == lower case alphabets

            if(ch == ')' ){   // Agar hame closing bracket mila then 
                bool isRedundant = true;  // Initially consider karo ki epression is redundant

                while (st.top() != '('  && !st.empty()){   // jabtak hame uska opening brackets nahi milta yah jabtak stack empty nahi hojata tabtak loop chalao (O(1))
                    char top = st.top();  // ek character banao aur top par assign kardo

                    if(top == '+' || top == '-' || top == '*' || top == '/'){   // agar top mein koi bhi operator mila means ki woh reduntant nahi hai
                        isRedundant = false;  // Agar yeh operators mil gaya matlab redundant nahi hai so mark false
                    }
                    st.pop();   // har check ke baad elements ko pop karte jao, baki chize check karne ke liye
                }

                if(isRedundant){   // Agar loop se isRedundant true nikla means it is redundant
                    return true;  // return true kardo
                }
                st.pop();   // Ab opening bracket mil gaya toh usse pop kardo taki baki bacche hue part ka redundancy test ho paye
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
        cout<<"Yes! it has Redundant Brackets.";
    }
    else{
        cout<<"No! it does not have redundant brackets";
    }
}
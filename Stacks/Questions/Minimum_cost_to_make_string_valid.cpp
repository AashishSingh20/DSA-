#include<iostream>
#include<stack>
using namespace std;

int minCost(string s){
    // Odd length of string
    int n = s.length();
    if(n%2 != 0){
        return -1;
    }

    // Step 1: Remove Valid Part
    stack<char> st;
    for(int i=0;i<n;i++){
        char ch = s[i];
        if(ch == '{'){
            st.push(ch);
        }
        else{    // ch is '}'
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(ch);   // Agar '}' mila aur iska open nahi mila toh '}' ko stack mein push kardo
            }
        }
    }
    
    // Now stack contains invalid expression
    int a = 0;   // Counts the number of closed braces
    int b = 0;    // Counts the number of open braces
    while (!st.empty()){   // Agar list khali nahi hua hai toh loop chalate raho
        if(st.top() == '{' ){   // agar top par '{' bracket mile toh b++ kr dena
           b++;   
        }
        else{    // Agar top par '}' mile toh a++ kar dena
            a++;
        }
        st.pop();  // kisi ko bhi badhane ke baad usko pop kardena
    }
    
    int ans = (a+1)/2 +(b+1)/2;   // Yeh formula hai 
    return ans;
}

int main(){
    string s;

    cout<<"Enter a String of braces: ";
    cin>>s;

    int ans = minCost(s);
    cout<<"Minimum Cost to make a string valid is: "<<ans<<endl;
}
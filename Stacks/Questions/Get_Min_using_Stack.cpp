#include<iostream>
#include<climits>
#include<stack>
using namespace std;

class Stack{
    public:
        stack<int> st;  // Create a stack which keeps record of all elements
        int mini;   // This variable stores the minimum value in the stack

    void push(int data) {
        // For 1st Element
        if(st.empty()){  // If stack is empty then
            st.push(data);   // Normal push  into the stack
            mini = data;   // Mini mein top vale element ki value ko store karlo
        }
        else{
            if(data < mini){   // Agar stack empty nahi hai toh check karo ki kya curr data mini se chhota hai
                int value = (2*data - mini);  // If chhota hai then value variable banao aur usmein ye formula use karo
                st.push(value);   // Joh bhi value hai usko stack mein push kardo
                mini = data;   // Aur mini ko update kardo(since curr data is smaller then mini, new mini will be curr data)
            }
            else{
                st.push(data);  // Agar curr data is greater then mini then normal push curr data into the stack
            }
        }
    }

    int pop() {
        if(st.empty()){   // Agar stack empty hai aur ham pop kar rahe hai then
            return -1;    // return -1
        }

        int curr = st.top();  // Ek Curr naam ka variable banao joh ki stack ke top ki value store karega 
        st.pop();   // Ab top element ko pop kardo
        if(curr >= mini){   // Agar curr mein joh data hai woh mini se bada yaa barabar hai then
            return curr;   // curr ke data ko hi return kardo
        }
        else{    // Agar curr mini se chhota hai then
            int prevMin = mini;   // prevMin karke ek variable banao jo previous mini ko store rakhega 
            int val = (2*mini - curr);   // val nikalo
            mini = val;    // mini ki value update kardo
            return prevMin;   // prevMin ko return kardo
        }
    }

    int top() {
       if(st.empty()){   // agar stack is empty then there is no element at the top so return 
           return -1;  // -1
       }

       int curr = st.top();  // If stack is not empty curr naam ka ek variable banao joh top par point kar raha ho
       if(curr < mini){   // Agar curr mini se chhota hai then 
           return mini;   // mini is the top element return mini
       }
       else{
           return curr;  // Agar curr is greater than mini then return curr as it is the top element
       }
    }

    bool isEmpty(){
        return st.empty();   // Return isEmpty if stack is Empty
    }

    int getMin(){
        if(st.empty()){   // Agar stack is empty then there is no min so return 
            return -1;   // -1
        }
        return mini;   // Else return mini as the min element in the stack
    }
};
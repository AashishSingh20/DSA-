#include<iostream>
using namespace std;

class Stack{
    // Properties
    public:
        int *arr;
        int top;
        int size;
    
    // Behaviour
    public:
        Stack(int size){
            this->size = size;  //  size to point karwado
            arr = new int[size];  // arr create of size
            top = -1;   // top ko initialize karo with -1 initially
        }

        void push(int element){
            if(size - top > 1){
                top++;
                arr[top] = element;
            }
            else{
                cout<<"Stack OverFlow!"<<endl;
            }
        }

        void pop(){
            if(top >=0){
                top--;
            }
            else{
                cout<<"Stack UnderFlow!"<<endl;
            }
        }

        int peek(){
            if(top >= 0){
                return arr[top];
            }
            else{
                cout<<"Stack is empty!";
                return -1;
            }
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }
};

int main(){

    Stack st(5);   // Created a Stack of Size 5

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;

    if(st.isEmpty())   cout<<"Stack is Empty!";
    else  cout<<"Stack is not Empty!"; 
}
// Stack OverFlow doesn't happen in LL in normal Conditions as Memory is dynamically Allocated in Heap
// 

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    public: 
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Stack{
    private:
        Node* top;

    public:
        Stack(){
            top = NULL;
        }

    void push(int data){
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
    }

    void pop(){
        if(top == NULL){
            cout<<"Stack UnderFlow!";
            return;
        }
        else{
           Node* temp = top;
           top = top->next;
           delete temp;
        }
    }

    int peek(){
        if(top == NULL){
            cout<<"Stack UnderFlow!";
            return -1;
        }
        return top->data;
    }
};

int main(){
    int n;
    cout<<"Enter how many elements to put in stack: ";
    cin>>n;

    cout<<"Enter Elements to put in Stack: ";
    Stack st;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        st.push(data);
    }

    int j = 0;
    while(j<n){
        cout<<st.peek()<<" ";
        st.pop();
        j++;
    }
}
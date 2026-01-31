#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    public:
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree(Node* root){
    int data;
    cout<<"Enter Data: "<<endl;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data to insert in left of "<<data<<":"<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data to insert in right of "<<data<<":"<<endl;
    root->right = buildTree(root->right);
}

void revBFS(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    stack<int> st;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            // Level is finished
            st.push(-1);   // Here -1 acts as a marker for new line

            if(!q.empty()){
                q.push(NULL);  // Here NULL is the seperator for new level
            }
        }
        else{
            st.push(temp->data);

            if(temp->left != NULL){
                q.push(temp->left);
            }

            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }

    // Print in Reverse Level Order
    while(!st.empty()){   // pop until Stack is not empty
        if(st.top() == -1){  // If stack top par -1 mil gaye matlab level is completed
            cout<<endl;
            st.pop();
        }
        else{
            cout<<st.top()<<" ";
            st.pop();
        }
    }
}

int main(){
    Node* root = NULL;

    root = buildTree(root);
    
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"Printing the Level Order Traversal output: "<<endl;
    revBFS(root);
}
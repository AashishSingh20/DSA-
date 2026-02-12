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


void solve(Node* root, stack<int> &st){
    if(root == NULL) return;
    
    // This put's values in reverse in stack as this gets us descending inorder
    solve(root->right,st);
    st.push(root->data);
    solve(root->left,st);
}

vector<int> merge(Node *root1, Node *root2) {
    stack<int> st1;
    stack<int> st2;
    
    // stack1 mein BST 1 ka solution daalo
    // And stack 2 mein BST 2 ka solution daalo
    solve(root1,st1);
    solve(root2,st2);
    
    vector<int> ans;
    // loop and compare elements in stack and accordingly put in ans vector 
    while(!st1.empty() && !st2.empty()){
        if(st1.top() < st2.top()){
            ans.push_back(st1.top());
            st1.pop();
        }
        else{
            ans.push_back(st2.top());
            st2.pop();
        }
    }
    
    // Agar stack 1 bach gaya then push it's remaining elements
    while(!st1.empty()){
        ans.push_back(st1.top());
        st1.pop();
    }
    // Agar stack 2 bach gaya then push it's remaing elements
    while(!st2.empty()){
        ans.push_back(st2.top());
        st2.pop();
    }
    // Return ans 
    // It will have inorder of both BST merged
    return ans;
}

int main(){
    // Creating BST 1  
    Node* root1 = new Node(3);
    Node* b = new Node(1);
    Node* c = new Node(5);

    root1->left = b;
    root1->right = c;

    // Creating BST 2
    Node* root2 = new Node(4);
    Node* d = new Node(2);
    Node* e = new Node(6);

    root2->left = d;
    root2->right = e;

    vector<int> ans = merge(root1,root2);
    cout<<"Inorder of Merged BST: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
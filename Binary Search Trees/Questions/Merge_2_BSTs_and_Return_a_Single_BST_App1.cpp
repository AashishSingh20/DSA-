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

void levelOrderTraversal(Node* root){   // Also known as BFS
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);   // Acts as a separater (Tells us when that specific level has been completed)

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){   // Purana Level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){   // If queue has some child nodes 
                q.push(NULL);  // Yeh ek aur separater hai joh queue ke last mein rahega mein ham push kardenga
            }
        }
        else{
            cout<<temp->data<<" ";   // Print data when temp is not NULL    
            if(temp->left != NULL){
                q.push(temp->left);
            }

            if(temp->right != NULL){    
                q.push(temp->right);
            }
        }
    }
    cout<<endl;
}

void solve(Node* root, stack<int> &st){
    if(root == NULL) return;
    
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

Node* inorderToBST(int start, int end,vector<int> arr){
    if(start > end) return NULL;

    int mid = start+(end-start)/2;
    Node* root = new Node(arr[mid]);

    root->left = inorderToBST(start,mid-1,arr);
    root->right = inorderToBST(mid+1,end,arr);

    return root;
}

Node* balancingBST(Node* r1,Node* r2){
    vector<int> ans = merge(r1,r2);
    int n = ans.size();

    int index = 0;
    Node* root = inorderToBST(0,n-1,ans);

    return root;
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

    // Tree 1
    levelOrderTraversal(root1);
    // Tree 2
    levelOrderTraversal(root2);

    // Merged Tree
    Node* root = balancingBST(root1,root2);
    levelOrderTraversal(root);
}
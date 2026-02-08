#include<iostream>
#include<queue>
#include<climits>
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

void levelOrderTraversal(Node* &root){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout<<"Enter Left Node for "<<temp->data<<endl;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout<<"Enter Right Node for "<<temp->data<<endl;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);            
        }
    }
}

Node* solve(Node* root, int &k, int node){
    // Base Case
    if(root == NULL || root->data == node){
        return root;
    }

    Node* leftAns = solve(root->left,k,node);
    Node* rightAns = solve(root->right,k,node);

    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k <= 0){
            // Ans ko lock kar diya(Is loop ke hisab se k mil gaya hai toh)
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k <= 0){
            // Ans ko lock kar diya(Is loop ke hisab se k mil gaya hai toh)
            k = INT_MAX;
            return root;
        }
        return rightAns;    
    }

    return NULL;
}

int kthAncestor(Node* root, int k, int node){
    Node* ans = solve(root,k,node);
    if(ans == NULL || ans->data == node){
        return -1;
    }
    else{
        return ans->data;
    }
}

int main(){
    Node* root = NULL;

    // 1 2 3 4 5 -1 -1 -1 -1 -1 -1 
    levelOrderTraversal(root);

    int k,node;
    cout<<"Enter k and node: ";
    cin>>k>>node;

    cout<<"Kth ancestor of node is: "<< kthAncestor(root,k,node)<<endl;
}   
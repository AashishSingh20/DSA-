#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

Node* lca(Node* root, int n1, int n2){
    // Base Case
    if(root == NULL){
        return NULL;
    }

    // Agar n1 yaa n2 kuch bhi mil jaye toh return oneself
    if(root->data == n1 || root->data == n2){
        return root;
    }

    // Find answe from left and right of the subtree
    Node* leftAns = lca(root->left,n1,n2);
    Node* rightAns = lca(root->right,n1,n2);

    // Dono ka ans non NULL hai toh return mardo root ko
    if(leftAns != NULL && rightAns != NULL){
        return root;
    }

    // Whoever is not NULL return their value
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }

    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }

    // If both are NULL return NULL
    else{
        return NULL;
    }
}

int main(){
    Node* root = NULL;

    // 5 4 3 7 8 22 27 -1 -1 12 9 -1 -1 29 -1 -1 -1 -1 -1 -1 -1 
    levelOrderTraversal(root);

    int n1,n2;
    cout<<"Enter n1, n2: ";
    cin>>n1>>n2;

    cout<<"The lca of n1 and n2 is: "<< lca(root,n1,n2)<<endl;
}   
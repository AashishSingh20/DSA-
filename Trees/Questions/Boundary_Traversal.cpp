#include<iostream>
#include<queue>
#include<vector>
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

void traverseLeft(Node* root, vector<int> &ans){
    // Base Case
    if(root == NULL  || root->left == NULL && root->right == NULL){
        return;
    }

    ans.push_back(root->data);
    if(root->left != NULL){   // Agar root ki left node NULL nahi hai toh left mein jate jao
        traverseLeft(root->left,ans);
    }
    else{    // Else root ke right mein check karo
        traverseLeft(root->right,ans);
    }
}

void traverseLeaf(Node* root, vector<int> &ans){
    // Base Case
    if(root == NULL){
        return;
    }
    
    // This means that the current root is a leaf node
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);   // Agar Leaf Node hai toh uska data store karlo in ans
        return;     // return the output
    }

    // Inorder Traversal to Get all Leaf Nodes
    traverseLeaf(root->left,ans);   // Left ke leaf ko traverse karo
    traverseLeaf(root->right,ans);   // Right ke leaf ko traverse karo
}

void traverseRight(Node* root, vector<int> &ans){
    // Base Case
    if(root == NULL  || root->left == NULL && root->right == NULL){
        return;
    }

    if(root->right != NULL){    // Agar right is not NULL then aur right mein jao
        traverseRight(root->right,ans);
    }
    else{    // Agar right is NULL then left mein check karo
        traverseRight(root->left,ans);
    }

    // Wapas aagye toh data at root ko ans mein push kardo
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;
    // Base Case
    if(root == NULL){
        return ans;
    }

    ans.push_back(root->data);

    // Step 1:- Left part print/store
    traverseLeft(root->left,ans);

    // Step 2:- Traverse Leaf nodes
    // Left Subtree
    traverseLeaf(root->left,ans);
    // Right Subtree
    traverseLeaf(root->right,ans);

    // Step 3:- Traverse Right Part
    traverseRight(root->right,ans);

    return ans;
}

int main(){
    Node* root = NULL;

    // 1 2 4 3 5 -1 7 -1 -1 6 8 -1 9 -1 -1 -1 -1 10 11 -1 -1 -1 -1
    levelOrderTraversal(root);

    vector<int> boundary = boundaryTraversal(root);
    cout<<"The boundary traversal of the tree is: ";
    for(int i=0;i<boundary.size();i++){
        cout<<boundary[i]<<" ";
    }
    cout<<endl;
}   
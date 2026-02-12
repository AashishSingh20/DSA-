#include<iostream>
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

class Info{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};

Info solve(Node* root, int &ans){
    // Base Case
    if(root == NULL)  return {INT_MIN,INT_MAX,true,0};

    Info left = solve(root->left,ans);
    Info right = solve(root->right,ans);

    Info currNode;
    currNode.size = left.size + right.size + 1;

    currNode.maxi = max(root->data,right.maxi);
    currNode.mini = min(root->data,left.mini);

    if(left.isBST && right.isBST && root->data > left.maxi && root->data < right.mini){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    // Update answer
    if(currNode.isBST){
        ans = max(ans,currNode.size);
    }

    return currNode;
}

int largestBST(Node* root){
    int maxSize = 0;

    // Info in temp stores root and maxSize
    Info temp = solve(root,maxSize);
    return maxSize;
}

int main(){
    // Creating BST 1  
    Node* root = new Node(5);
    Node* b = new Node(2);
    Node* c = new Node(4);
    Node* d = new Node(1);
    Node* e = new Node(3);

    root->left = b;
    root->right = c;
    b->left = d;
    b->right = e;

    int largestBSTSize = largestBST(root);
    cout<<"The size of the Largest BST in Binary Tree is: "<<largestBSTSize<<endl;
}
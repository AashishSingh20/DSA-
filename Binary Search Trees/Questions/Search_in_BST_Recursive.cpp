#include<iostream>
#include<queue>
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

Node* insertIntoBST(Node* &root, int data){
    // Base Case
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    // If curr data is greater than root data insert in it's right
    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }
    // If curr data is smaller than root data insert in it's left
    else{
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

bool search(Node* root, int key){
    // Base Case
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(root->data > key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}

int main(){
    Node* root = NULL;

    // 21 10 50 5 15 40 60 55 70 -1
    cout<<"Enter Data to Create BST: ";
    takeInput(root);

    int key;
    cout<<"Enter Key to find in BST: ";
    cin>>key;

    if(search(root,key)){
        cout<<"Key is present in the BST";
    }
    else{
        cout<<"Key is not present in BST";
    }
}
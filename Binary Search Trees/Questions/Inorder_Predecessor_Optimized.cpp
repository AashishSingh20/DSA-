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


Node* inOrderPredecessor(Node* root, int key){
    Node* pred = NULL;
    while(root != NULL){
        if(root->data < key){
            pred = root;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }      
    return pred;
}

int main(){
    Node* root = NULL;

    // 50 20 70 10 30 90 110 -1
    cout<<"Enter Data to Create BST: ";
    takeInput(root);

    int ele;
    cout<<"Enter Element you want Predecessor of: ";
    cin>>ele;

    Node* predecessor = inOrderPredecessor(root,ele);
    cout<<"Inorder Predecessor of "<<ele<<" is "<<predecessor->data<<endl;
}
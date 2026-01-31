#include<iostream>
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
    cout<<"Enter Data: ";
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<":"<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for inserting in right of "<<data<<":"<<endl;
    root->right = buildTree(root->right);
}

int main(){
    Node* root = NULL;

    // Creating a Tree
    root = buildTree(root);
}
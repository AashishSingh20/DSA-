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

void buildFromLevelOrder(Node* &root){

    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;
    root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftdata;
        cout<<"Enter left node of: "<<temp->data<<endl;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        int rightdata;
        cout<<"Enter right node of: "<<temp->data<<endl;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}

void inorder(Node* root, int &count){
    // Base Case
    if(root == NULL){
        return;
    }

    inorder(root->left, count);

    // Leaf Node
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    
    inorder(root->right, count);
}

int noOfLeafNodes(Node* root){
    int count = 0;

    inorder(root,count);
    return count;
}

int main(){
    Node* root = NULL;

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    buildFromLevelOrder(root);

    int cnt = noOfLeafNodes(root);
    cout<<"Number of Leaf Nodes in the Tree are: "<<cnt<<endl;
}
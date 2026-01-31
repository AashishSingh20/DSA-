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
    cout<<"Enter data for root: ";
    cin>>data;
    root = new Node(data);
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftdata;
        cout<<"Enter Left Node for: "<<temp->data<<endl;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        int rightdata;
        cout<<"Enter Right Node for: "<<temp->data<<endl;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }     
    
    }
}

int heightOfBt(Node* root){

    // Base Case
    if(root == NULL){
        return 0;
    }

    int leftHeight = heightOfBt(root->left);
    int rightHeight = heightOfBt(root->right);

    int ans = max(leftHeight,rightHeight) + 1;  // Calculates the max height from left and right subtree and adds 1 which is the root node
    return ans;
}

int main(){
    Node* root = NULL;

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);

    int height = heightOfBt(root);
    cout<<endl<<"Height of Binary Tree is: "<<height<<endl;
}
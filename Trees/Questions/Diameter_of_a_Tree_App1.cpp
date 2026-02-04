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

int height(Node* root){

    // Base Case
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int ans = max(leftHeight,rightHeight) + 1;  // Calculates the max height from left and right subtree and adds 1 which is the root node
    return ans;
}

int diameterOfBt(Node* root){

    // Base Case
    if(root == NULL){
        return 0;
    }

    int op1 = diameterOfBt(root->left);
    int op2 = diameterOfBt(root->right);
    int op3 = height(root->left) + height(root->right) + 1;

    int ans = max(op1,max(op2,op3));
    return ans;
}

int main(){
    Node* root = NULL;

    // 5 8 6 3 7 9 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);

    int diameter = diameterOfBt(root);
    cout<<endl<<"Diameter of Binary Tree is: "<<diameter<<endl;
}
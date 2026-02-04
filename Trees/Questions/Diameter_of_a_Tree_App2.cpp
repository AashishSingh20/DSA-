// Here we are calculating Diamater based on the number of Nodes 

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

int maxDiameter = 0;

int diameterRec(Node* root){
    // Base Case
    if(root == NULL){
        return 0;
    }

    int leftHeight = diameterRec(root->left);
    int rightHeight = diameterRec(root->right);

    if(leftHeight + rightHeight > maxDiameter){
        maxDiameter = leftHeight + rightHeight + 1;
    }

    int height = max(leftHeight,rightHeight) + 1;
    return height;
}

int diameterOfBt(Node* root){
    maxDiameter = 0;
    diameterRec(root);

    return maxDiameter;
}

int main(){
    Node* root = NULL;

    // 5 8 6 3 7 9 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);

    int diameter = diameterOfBt(root);
    cout<<endl<<"Diameter of Binary Tree is: "<<diameter<<endl;
}
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

pair<int,int> diameterRec(Node* root){
    // Base Case
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);  // 1st int represents diamater and 2nd int represents height
        return p;
    }

    pair<int,int> left = diameterRec(root->left);
    pair<int,int> right = diameterRec(root->right);

    int op1 = left.first;   // Gives us the Diamater of the Left Subtree
    int op2 = right.first;  // Gives us the diamater of the Right Subtree

    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1,(max(op2,op3)));   // Gets max diamater and stores in ans.first
    ans.second = max(left.second,right.second) + 1;  // Gets max height and stores in ans.second
    return ans;
}

int diameterOfBt(Node* root){

    return diameterRec(root).first;  // First mein diameter store hai isliye return first
}

int main(){
    Node* root = NULL;

    // 5 8 6 3 7 9 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);

    int diameter = diameterOfBt(root);
    cout<<endl<<"Diameter of Binary Tree is: "<<diameter<<endl;
}
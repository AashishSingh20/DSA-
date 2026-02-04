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

pair<bool,int> isSumTreeFast(Node* root){
    // Base Case
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    // Check for leaf node
    if(root->left == NULL && root->right == NULL){  // Agar Leaf hai toh
        pair<bool,int> p = make_pair(true,root->data);   // Same return true and us leaf node ka data
        return p;       
    }

    pair<bool,int> left = isSumTreeFast(root->left);    // Left subtree mein jao aur bool ke sath us node ki value bhi return kardo
    pair<bool,int> right = isSumTreeFast(root->right);  // Right subtree mein jao aur bool ke sath us node ki value bhi return kardo

    bool leftAns = left.first;    // leftAns mein left ke 1st block ki bool value dedo
    bool rightAns = right.first;  // rightAns mein right ke 1st block ki bool value dedo

    bool condition = root->data == left.second + right.second;    // Agar root node sum of it's left suntree and right subtree hai toh condition true ho jayegi

    pair<bool,int> ans;

    if(leftAns && rightAns && condition){   // Agar left, right and condition is true then
        ans.first = true;  // ans ke 1st block mein true daldo
        ans.second = root->data + left.second + right.second;  // ans ke 2nd block mein sum of all value of all subtree daldo
    }
    else{
        ans.first = false;
    }

    return ans;
}

bool isSumTree(Node* root){
    return isSumTreeFast(root).first;  // ans mein bool value bhi hai aur int value bhi hai but hame bool ka kaam hai isliye we are calling .first
} 

int main(){
    Node* root = NULL;

    // 5 8 6 3 7 9 -1 -1 -1 -1 -1 -1 -1
    // buildFromLevelOrder(root);

    // 3 1 2 -1 -1 -1 -1
    buildFromLevelOrder(root);

    if(isSumTree(root)){
        cout<<"Yes, it is a Sum Tree.";
    }
    else{
        cout<<"No, it is not a Sum Tree.";
    }
}   
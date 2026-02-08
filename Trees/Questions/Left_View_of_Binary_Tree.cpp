#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

void levelOrderTraversal(Node* &root){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout<<"Enter Left Node for "<<temp->data<<endl;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout<<"Enter Right Node for "<<temp->data<<endl;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);            
        }
    }
}

void solve(Node* root, vector<int> &ans, int level){
    // Base Case
    if(root == NULL){
        return;
    }

    // Agar level is equal to size of ans it means we have entered new level
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}

vector<int> leftView(Node* &root){
    int level = 0;
    vector<int> ans;
    solve(root,ans,level);
    return ans;
}

int main(){
    Node* root = NULL;

    // 1 2 5 3 4 -1 6 -1 -1 -1 -1 -1 8 -1 9 -1 -1
    levelOrderTraversal(root);

    vector<int> left_view = leftView(root);
    cout<<"The vertical Order traversal of the tree is: ";
    for(int i=0;i<left_view.size();i++){
        cout<<left_view[i]<<" ";
    }
    cout<<endl;
}   
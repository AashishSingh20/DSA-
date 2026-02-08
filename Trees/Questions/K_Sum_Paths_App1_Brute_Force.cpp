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

void solve(Node* root, int k, int &count, vector<int> path){
    // Base Case
    if(root == NULL){
        return;
    }

    // Initially path mein root ka data daldo
    path.push_back(root->data);

    // Left Call
    solve(root->left,k,count,path);
    solve(root->right,k,count,path);

    // Check for k Sum
    int size = path.size();
    int sum = 0;
    // array ke piche se sum karo and check karo ki, is sum equal to k?
    for(int i=size-1;i >= 0;i--){
        sum += path[i];
        if(sum == k){
            count++;
        }
    }
}

int countAllPaths(Node* root, int k){    
    vector<int> path;
    int count = 0;
    solve(root,k,count,path);
    return count;
}

int main(){
    Node* root = NULL;

    // 1 3 1 2 1 4 5 -1 -1 1 -1 1 2 -1 6 -1 -1 -1 -1 -1 -1 -1 -1 
    levelOrderTraversal(root);

    int k;
    cout<<"Enter k: ";
    cin>>k;

    cout<<"The total number of paths whose sum is equal to k is: "<< countAllPaths(root,k)<<endl;
}   
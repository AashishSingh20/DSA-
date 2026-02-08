#include<iostream>
#include<queue>
#include<climits>
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

pair<int,int> solve(Node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> leftAns = solve(root->left);
    pair<int,int> rightAns = solve(root->right);

    pair<int,int> res;
    // For including the current node
    res.first = root->data + leftAns.second + rightAns.second;
    // For excluding the current data
    res.second = max(leftAns.first,leftAns.second) + max(rightAns.first,rightAns.second);

    return res;
}

int getMaxSum(Node* root){
    pair<int,int> ans;   // 1st node is for maxSum including current level and 2nd int is for maximum sum exclusing current level

    solve(root);
    return max(ans.first,ans.second);
}

int main(){
    Node* root = NULL;

    // 1 2 3 4 5 -1 -1 -1 -1 -1 -1 
    levelOrderTraversal(root);

    int k,node;
    cout<<"Enter k and node: ";
    cin>>k>>node;

    cout<<"Maximum Sum of Non Adjacent Nodes is: "<< getMaxSum(root)<<endl;
}   
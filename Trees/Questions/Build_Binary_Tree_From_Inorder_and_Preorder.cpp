#include<iostream>
#include<vector>
#include<queue>
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

void print(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<temp->data<<" ";
        
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

void createMapping(vector<int> &inorder, map<int,int> &nodeToIndex, int n){
    for(int i=0;i<n;i++){
        nodeToIndex[inorder[i]] = i;   // Mapping inorder with it's index(This keeps tab of which element is where in order array)
    }
}

Node* solve(vector<int> &inorder, vector<int> &preorder, int &preOrderIndex, int inorderStart, int inorderEnd, map<int,int> &nodeToIndex, int n){
    // cout<<"PreOrderIndex: "<<preOrderIndex<<" ";
    // cout<<"InorderStart: "<<inorderStart<<" ";
    // cout<<"InorderEnd: "<<inorderEnd<<" ";

    // Base case
    if(preOrderIndex >= n || inorderStart > inorderEnd){  // Agar preOrder ka index greater than it's own size or inorderStart becomes greater than it's end return NULL
        return NULL;
    }

    // Create a root node for element
    int element = preorder[preOrderIndex++];  // Element mein preorder ke current index par joh element hai woh daldo
    Node* root = new Node(element);  // Ab ek root naam ka node banao jismein element ki value daldo
    
    // Find Element's  index in inorder
    int position = nodeToIndex[element]; 

    // cout<<"Element: "<<element<<" ";
    // cout<<"Position "<<position<<" ";
    // Recursive Calls
    root->left = solve(inorder,preorder,preOrderIndex,inorderStart,position-1,nodeToIndex,n);
    root->right = solve(inorder,preorder,preOrderIndex,position+1,inorderEnd,nodeToIndex,n);

    return root;
}

Node* buildTree(vector<int> &inorder, vector<int> &preorder){
    int n = inorder.size();
    int preOrderIndex = 0;
    map<int,int> nodeToIndex;
    // Create Mapping 
    createMapping(inorder,nodeToIndex,n);

    Node* ans = solve(inorder, preorder, preOrderIndex, 0, n-1, nodeToIndex,n);
    return ans;
}

int main(){
    vector<int> inorder;
    vector<int> preorder;

    int n;
    cout<<"Enter no of Nodes in the Tree: ";
    cin>>n;

    cout<<"Enter Inorder Values: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        inorder.push_back(val);
    }

    cout<<"Enter Preorder Values: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        preorder.push_back(val);
    }

    Node* root = buildTree(inorder,preorder);
    cout<<"Tree: ";
    print(root);
}
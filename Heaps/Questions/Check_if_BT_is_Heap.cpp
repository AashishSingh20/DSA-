#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

void buildLevelOrder(Node* &root){
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

int countNodes(Node* root){
    if(root == NULL) return 0;

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node* root, int i, int count){
    if(root == NULL) return true;

    // Agar i number of nodes se jada ho gaya matlab 
    // Kahi par gap hai yaa current node ka index out of range hai
    if(i >= count){
        return false;
    }

    // Check for it's left and right nodes as well
    else{
        bool left = isCBT(root->left,2*i+1,count);
        bool right = isCBT(root->right,2*i+2,count);
        return(left && right);
    }
}

bool isMaxOrder(Node* root){
    // Base Case
    if(root == NULL) return true;

    // Since this condition will Run after checking Tree is CBT or Not we will consider Tree to be CBT
    // If current node is a leaf node
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    // If only one child exists(Since it is a CBT the only child will be in left)
    // Return after checking MaxHeap Condition
    if(root->right == NULL && root->left != NULL){
        return (root->data >= root->left->data );
    }
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        // If Both Child Exists
        // Check for maxHeap Property
        if(left && right && root->data >= root->left->data && root->data >= root->right->data){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    Node* root = NULL;

    // 97 46 37 12 3 7 31 6 9 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
    // 97 46 37 12 3 7 31 -1 -1 2 4 -1 -1 -1 -1 -1 -1 -1 -1 
    buildLevelOrder(root);

    int index = 0;
    int totalCount = countNodes(root);
    if(isCBT(root,index,totalCount) && isMaxOrder(root)){
        cout<<"Yes, the given Tree is a Max Heap";
    }
    else{
        cout<<"No, the given Tree is not a Max Heap or a Heap";
    }
} 
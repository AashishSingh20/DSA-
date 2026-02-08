#include<iostream>
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

Node* createParentmapping(Node* root, map<Node*,Node*> &nodeToParent,int target){
    // This function creates a mapping of every node to their parent node
    // Return target Node

    Node* res = NULL;

    queue<Node*> q;
    q.push(root);
    nodeToParent[root] = NULL;  // Root ka koi parent hi nahi hai toh mark it as give it NULL Key in map

    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();

        if(frontNode->data == target){
            res = frontNode;
        }
        // If frontNode ka left child exists then mapping mein frontNode ko uska key(parent) bana do
        if(frontNode->left){
            nodeToParent[frontNode->left] = frontNode;
            q.push(frontNode->left);
        }
        // If frontNode ka right child exists then mapping mein frontNode ko uska key(parent) bana do
        if(frontNode->right){
            nodeToParent[frontNode->right] = frontNode;
            q.push(frontNode->right);
        }
    }
    return res;
}

void burnTree(Node* root, map<Node*,Node*> &nodeToParent, int &time){
    map<Node*,bool> visited;
    queue<Node*> q;

    q.push(root);
    // Visited mein jaake ko true mark kardo means it has been visited  
    visited[root] = true;

    // Loop until q is not empty
    while(!q.empty()){
        bool flag = false;
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* frontNode = q.front();
            q.pop();

            // Agar frontNode ka left exist karta hai and woh visited nahi hai then run this condition
            if(frontNode->left && !visited[frontNode->left]){
                q.push(frontNode->left);
                visited[frontNode->left] = true;
                flag = true;
            }
            // Agar frontNode ka right exist karta hai and woh visited nahi hai then run this condition
            if(frontNode->right && !visited[frontNode->right]){
                q.push(frontNode->right);
                visited[frontNode->right] = true;
                flag = true;
            }
            // Agar frontNode ka parent exist karta hai and woh agar visited nahi hai then run this
            if(nodeToParent[frontNode] && !visited[nodeToParent[frontNode]]){
                q.push(nodeToParent[frontNode]);
                visited[nodeToParent[frontNode]] = true;
                flag = true;
            }
        }
        if(flag){
            time++;
        }
    }
}

int minTime(Node* root, int target){
    // Algo:
    // Step 1: Create nodeToParent mapping
    // Step 2: Find Target Node
    // Step 3: Burn the tree in minTime

    int time = 0;
    map<Node*,Node*> nodeToParent;
    // This Function create a mapping of child and parent node and return target node
    Node* targetNode = createParentmapping(root,nodeToParent,target);

    // This Functions burns the tree
    burnTree(targetNode,nodeToParent,time);

    return time;
}

int main(){
    Node* root = NULL;

    // 1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1 10 -1 -1
    levelOrderTraversal(root);

    int target;
    cout<<"Enter Target Node to start burning: ";
    cin>>target;

    int ans = minTime(root,target);
    cout<<"Minimum Time to Burn the tree is: "<<ans<<"sec"<<endl;
}   


// TC: O(n)
// SC: O(n)
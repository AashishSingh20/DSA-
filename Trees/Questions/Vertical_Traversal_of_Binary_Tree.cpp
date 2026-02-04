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

vector<int> verticalOrder(Node* &root){

    map<int,map<int,vector<int>>> nodes;
    queue<pair<Node*,pair<int,int>>> q;  // Node represents rooot, 1st int is hd and 2nd int is level

    vector<int> ans;
    //Base Case
    if(root == NULL){
        return ans;
    }

    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        pair<Node*,pair<int,int>> temp = q.front();
        q.pop();

        // Define frontNode , horizontal distance and level
        Node* frontNode = temp.first;   
        int hd = temp.second.first;
        int level = temp.second.second;

        // insert data at frontNode in the map
        nodes[hd][level].push_back(frontNode->data);

        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left,make_pair(hd-1,level+1)));
        }

        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right,make_pair(hd+1,level+1)));
        }
    }

    for(auto i: nodes){
        for(auto j: i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main(){
    Node* root = NULL;

    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
    levelOrderTraversal(root);

    vector<int> vertical = verticalOrder(root);
    cout<<"The vertical Order traversal of the tree is: ";
    for(int i=0;i<vertical.size();i++){
        cout<<vertical[i]<<" ";
    }
    cout<<endl;
}   
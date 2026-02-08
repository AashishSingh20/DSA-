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

vector<int> diagonalOrder(Node* &root){
    vector<int> ans;
    // Base Case
    if(root == NULL){
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        while(temp != NULL){
            ans.push_back(temp->data);

            if(temp->left){
                q.push(temp->left);
            }

            temp = temp->right;
        }
    }
    return ans;
}

int main(){
    Node* root = NULL;

    // 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1 
    levelOrderTraversal(root);

    vector<int> diagonal = diagonalOrder(root);
    cout<<"The diagonal Order traversal of the tree is: ";
    for(int i=0;i<diagonal.size();i++){
        cout<<diagonal[i]<<" ";
    }
    cout<<endl;
}   
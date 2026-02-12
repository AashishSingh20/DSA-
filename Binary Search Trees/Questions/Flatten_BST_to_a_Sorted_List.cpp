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

void print(Node* head){
    if(head == NULL){
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

void solve(Node* root, vector<Node*> &arr){
    if(root == NULL) return;

    solve(root->left,arr);
    arr.push_back(root);
    solve(root->right,arr);
}

Node* flattenBST(Node* root){
    vector<Node*> arr;
    solve(root,arr);

    int n = arr.size();
    // If n == 0 means root is NULL so return NULL
    if(n == 0) return NULL;

    // Handling nodes in between
    for(int i=0;i<n-1;i++){
        arr[i]->left = NULL;
        arr[i]->right = arr[i+1];
    }

    // Handling Last Node
    arr[n-1]->left = NULL;
    arr[n-1]->right = NULL;

    // Now arr[0] is the new Head
    return arr[0];
}

int main(){
    Node* root = new Node(5);
    Node* b = new Node(3);
    Node* c = new Node(7);
    Node* d = new Node(2);
    Node* e = new Node(4);
    Node* f = new Node(6);
    Node* g = new Node(8);

    root->left = b;
    root->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    root = flattenBST(root);
    print(root);
}
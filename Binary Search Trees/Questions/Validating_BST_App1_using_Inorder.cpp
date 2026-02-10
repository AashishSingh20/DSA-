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

void levelOrderTraversal(Node* root){   // Also known as BFS
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);   // Acts as a separater (Tells us when that specific level has been completed)

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){   // Purana Level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){   // If queue has some child nodes 
                q.push(NULL);  // Yeh ek aur separater hai joh queue ke last mein rahega mein ham push kardenga
            }
        }
        else{
            cout<<temp->data<<" ";   // Print data when temp is not NULL    
            if(temp->left != NULL){
                q.push(temp->left);
            }

            if(temp->right != NULL){    
                q.push(temp->right);
            }
        }
    }
    cout<<endl;
}

bool isBST(Node* root, int prev){
    // Base Case
    if(root == NULL){
        return false;
    }

    if(!isBST(root->left,prev)){
        
    }    
}

int main(){

    Node* root = new Node(4);
    Node* b = new Node(2);
    Node* c = new Node(5);
    Node* d = new Node(1);
    Node* e = new Node(3);

    root->left = b;
    root->right = c;
    b->left = d;
    b->right = e;
    
    cout<<"Tree: "<<endl;
    levelOrderTraversal(root);

    int prev = INT_MIN;
    if(isBST(root,prev)){
        cout<<"Tree is a BST.";
    }
    else{
        cout<<"Tree is not a BST.";
    }
}
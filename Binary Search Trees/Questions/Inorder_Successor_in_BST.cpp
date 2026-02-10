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

Node* insertIntoBST(Node* &root, int data){
    // Base Case
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    // If curr data is greater than root data insert in it's right
    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }
    // If curr data is smaller than root data insert in it's left
    else{
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

// Function to Find the RightMost in the Subtree
Node* leftMost(Node* root){
    // Base Case
    if(root == NULL){
        return NULL;
    }

    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* inOrderSuccessor(Node* root, int key){
    // Base Case (No Inorder successor)
    if(root == NULL) return NULL;


    Node* curr = root;
    Node* succ = NULL;

    // Loop until curr is not NULL
    while(curr != NULL){
        bool flag = false;
        
        // If curr node's data is less than key's data the move curr to the right
        // And set succ at curr before moving curr as succ element at succ can be possile successor
        if(curr->data < key){
            curr = curr->right;
        }
        // If curr node's data is greater than key's data move succ toh curr node as it can be a possible successor
        else if(curr->data > key){
            flag = true;
            succ = curr;
            curr = curr->left;
        }

        else{
            // If the right Subtree of the Target Nodes Exists
            // Then successor will left most Node of the right Subtree
            if(curr->right != NULL){
                flag = true;
                return leftMost(curr->right);
            }
            // Otherwise, the predessor has already been stored in the succ variable
            break;
        }
        if(flag){
            return succ;
        }
    }
    cout<<"No Successor!";
    return NULL;
}

int main(){
    Node* root = NULL;

    // 50 20 70 10 30 90 110 -1
    cout<<"Enter Data to Create BST: ";
    takeInput(root);

    int ele;
    cout<<"Enter Element you want Successor of: ";
    cin>>ele;

    Node* successor = inOrderSuccessor(root,ele);
    cout<<"Inorder Successor of "<<ele<<" is "<<successor->data<<endl;
}
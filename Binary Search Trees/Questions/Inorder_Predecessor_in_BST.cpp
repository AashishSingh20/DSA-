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
Node* rightMost(Node* root){
    // Base Case
    if(root == NULL){
        return NULL;
    }

    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* inOrderPredecessor(Node* root, int key){
    // Base Case (No Inorder Predecessor)
    if(root == NULL) return NULL;


    Node* curr = root;
    Node* pred = NULL;

    // Loop until curr is not NULL
    while(curr != NULL){
        bool flag = false;
        
        // If curr node's data is less than key's data the move curr
        // And set pred at curr before moving curr as pred element at pred can be possile predecessor
        if(curr->data < key){
            flag = true;
            pred = curr;
            curr = curr->right;
        }
        // If curr node's data is greater than key's data then don't touch the pred as elements in left of root are smaller so root cannot be it's predecessor
        else if(curr->data > key){
            curr = curr->left;
        }

        else{
            // If the left Subtree of the Target Nodes Exists
            // Then Predecessor will right most Node of the left Subtree
            if(curr->left != NULL){
                flag = true;
                return rightMost(curr->left);
            }
            // Otherwise, the predessor has already been stored in the pred variable
            break;
        }
        if(flag){
            return pred;
        }
    }
    cout<<"No Predecessor!";
    return NULL;
}

int main(){
    Node* root = NULL;

    // 50 20 70 10 30 90 110 -1
    cout<<"Enter Data to Create BST: ";
    takeInput(root);

    int ele;
    cout<<"Enter Element you want Predecessor of: ";
    cin>>ele;

    Node* predecessor = inOrderPredecessor(root,ele);
    cout<<"Inorder Predecessor of "<<ele<<" is "<<predecessor->data<<endl;
}
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

void preOrder(Node* root){
    // Base Case
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);

}

void inorder(Node* root){
    // Base Case
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}

void postOrder(Node* root){
    // Base Case
    if(root == NULL){
        return;
    }

    postOrder(root->left);  // left part mein jao
    postOrder(root->right);  // right part mein jao
    cout << root->data << " ";  // root mein joh data hai woh print kardo   

}

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

int main(){
    Node* root = NULL;

    // 10 8 21 7 27 5 4 3 -1
    cout<<"Enter Data to Create BST: ";
    takeInput(root);

    cout<<"Printing the BST in LevelOrder: "<<endl;
    levelOrderTraversal(root);

    cout<<"Printing the BST in PreOrder: ";
    preOrder(root);
    cout<<endl;

    cout<<"Printing the BST in InOrder: ";
    inorder(root);
    cout<<endl;

    cout<<"Printing the BST in PostOrder: ";
    postOrder(root);
}
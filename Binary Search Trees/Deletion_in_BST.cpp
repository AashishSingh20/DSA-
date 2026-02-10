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

int minVal(Node* root){
    if(root == NULL) return -1;

    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

Node* delNode(Node* &root, int key){
    // Base Case
    if(root == NULL){
        return NULL;
    }

    if(root->data == key){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child
        // Left Child
        else if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Right Child
        else if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        else{
            // Option 1 take minimum value node from right subtree and copy it's value in root
            // Then delete the minimum value node from which we copied
            int mini = minVal(root->right);  // Min value nikalo from right of root
            root->data = mini;

            root->right = delNode(root->right,mini); // Delete from root ka right(mini ki value jahah par hai waha jake delete the node)
            return root;

            // option 2 take maximum value node from left subtree and copy it's value in root
            // Then delete the maximum value node from which we copied
        }
    }

    if(root->data > key){
        // Left part mein jao
        root->left = delNode(root->left,key);
        return root;
    }
    else{
        // Right part mein jao
        root->right = delNode(root->right,key);
        return root;
    }

    return root;
}

int main(){
    Node* root = NULL;

    // 100 50 110 25 70 120 60 115 -1
    cout<<"Enter Data to Create BST: ";
    takeInput(root);
    
    cout<<"BST Before Deletion: "<<endl;
    levelOrderTraversal(root);

    int ele;
    cout<<"Enter Element you want to Delete: ";
    cin>>ele;

    root = delNode(root,ele);

    cout<<"BST After Deletion of "<<ele<<": "<<endl;
    levelOrderTraversal(root);
}